/* Copyright (c) 2010-2011 Xiph.Org Foundation, Skype Limited
   Written by Jean-Marc Valin and Koen Vos */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



#include "../celt/entenc.h"
#include "../silk/API.h"
#include "../celt/stack_alloc.h"
#include "../opus_include/opus.h"
//#include "../opus_include/opus_private.h"
#include "../celt/os_support.h"
#include "../celt/mathops.h"
#include "../silk/tuning_parameters.h"

#include "opus_private.h"

#include "../silk/fixed/structs_FIX.h"

#define MAX_ENCODER_BUFFER 120


struct OpusEncoder {
    int          silk_enc_offset;
    silk_EncControlStruct silk_mode;
    int          application;
    int          channels;
    int          delay_compensation;
    int          signal_type;
    int          user_bandwidth;
    int          max_bandwidth;
    int          voice_ratio;
    opus_int32   Fs;
    int          variable_duration;
    opus_int32   bitrate_bps;
    opus_int32   user_bitrate_bps;
    int          encoder_buffer;
    int          lfe;
    int          arch;

    int          stream_channels;
    opus_int32   variable_HP_smth2_Q15;
    opus_val32   hp_mem[4];

    int          bandwidth;
    /* Bandwidth determined automatically from the rate (before any other adjustment) */
    int          auto_bandwidth;
    int          silk_bw_switch;
    /* Sampling rate (at the API level) */
    int          first;

    opus_val16   delay_buffer[MAX_ENCODER_BUFFER*2];
    int          nonfinal_frame; /* current frame is not the final in a packet */
};

/* Transition tables for the voice and music. First column is the
   middle (memoriless) threshold. The second column is the hysteresis
   (difference with the middle) */
static const opus_int32 mono_voice_bandwidth_thresholds[8] = {
        10000, 1000, /* NB<->MB */
        11000, 1000, /* MB<->WB */
        13500, 1000, /* WB<->SWB */
        14000, 2000, /* SWB<->FB */
};



int opus_encoder_get_size(int channels)
{
    int silkEncSizeBytes;
    int ret;
    if (channels<1 || channels > 2)
        return 0;
    ret = silk_Get_Encoder_Size( &silkEncSizeBytes );
    if (ret)
        return 0;
    silkEncSizeBytes = align(silkEncSizeBytes);

    return align(sizeof(OpusEncoder))+silkEncSizeBytes;
}

int opus_encoder_init(OpusEncoder* st, opus_int32 Fs, int channels, int application)
{
    void *silk_enc;
    int ret, silkEncSizeBytes;

   if((Fs!=16000)||(channels!=1)/*|| application != OPUS_APPLICATION_AUDIO*/)
        return OPUS_BAD_ARG;

    OPUS_CLEAR((char*)st, opus_encoder_get_size(channels));
    /* Create SILK encoder */
    ret = silk_Get_Encoder_Size( &silkEncSizeBytes );
    if (ret)
        return OPUS_BAD_ARG;
    silkEncSizeBytes = align(silkEncSizeBytes);
    st->silk_enc_offset = align(sizeof(OpusEncoder));
    silk_enc = (char*)st+st->silk_enc_offset;

    st->stream_channels = st->channels = channels;

    st->Fs = Fs;

    st->arch = 0;//opus_select_arch();

    ret = silk_InitEncoder( silk_enc, st->arch, &st->silk_mode );
    if(ret)return OPUS_INTERNAL_ERROR;

    /* default SILK parameters */
    st->silk_mode.nChannelsAPI              = channels;
    st->silk_mode.nChannelsInternal         = channels;
    st->silk_mode.API_sampleRate            = st->Fs;
    st->silk_mode.maxInternalSampleRate     = 16000;
    st->silk_mode.minInternalSampleRate     = 8000;
    st->silk_mode.desiredInternalSampleRate = 16000;
    st->silk_mode.payloadSize_ms            = 20;
    st->silk_mode.bitRate                   = 32000;
    st->silk_mode.packetLossPercentage      = 0;
    st->silk_mode.complexity                = 4;
    st->silk_mode.useInBandFEC              = 0;
    st->silk_mode.useDTX                    = 0;
    st->silk_mode.useCBR                    = 0;
    st->silk_mode.reducedDependency         = 0;



    /* Makes constrained VBR the default (safer for real-time use) */
    st->user_bitrate_bps = OPUS_AUTO;
    st->bitrate_bps = 3000+Fs*channels;
    st->application = application;
    st->signal_type = OPUS_AUTO;
    st->user_bandwidth = OPUS_AUTO;
    st->max_bandwidth = OPUS_BANDWIDTH_WIDEBAND ;
//    st->user_forced_mode = OPUS_AUTO;
    st->voice_ratio = -1;
    st->encoder_buffer = st->Fs/100;
    st->variable_duration = OPUS_FRAMESIZE_ARG;

    /* Delay compensation of 4 ms (2.5 ms for SILK's extra look-ahead
       + 1.5 ms for SILK resamplers and stereo prediction) */
    st->delay_compensation = st->Fs/250;

    st->variable_HP_smth2_Q15 = silk_LSHIFT( silk_lin2log( VARIABLE_HP_MIN_CUTOFF_HZ ), 8 );
    st->first = 1;
    st->bandwidth = OPUS_BANDWIDTH_WIDEBAND;

    return OPUS_OK;
}

static unsigned char gen_toc(int framerate, int bandwidth, int channels)
{
   int period;
   unsigned char toc;
   period = 0;
   while (framerate < 400)
   {
       framerate <<= 1;
       period++;
   }

   toc = (bandwidth-OPUS_BANDWIDTH_NARROWBAND)<<5;
   toc |= (period-2)<<3;

   toc |= (channels==2)<<2;
   return toc;
}


static void dc_reject(const opus_val16 *in, opus_int32 cutoff_Hz, opus_val16 *out, opus_val32 *hp_mem, int len, int channels, opus_int32 Fs)
{
   int c, i;
   int shift;

   /* Approximates -round(log2(4.*cutoff_Hz/Fs)) */
   shift=celt_ilog2(Fs/(cutoff_Hz*3));
   for (c=0;c<channels;c++)
   {
      for (i=0;i<len;i++)
      {
         opus_val32 x, tmp, y;
         x = SHL32(EXTEND32(in[channels*i+c]), 14);
         /* First stage */
         tmp = x-hp_mem[2*c];
         hp_mem[2*c] = hp_mem[2*c] + PSHR32(x - hp_mem[2*c], shift);
         /* Second stage */
         y = tmp - hp_mem[2*c+1];
         hp_mem[2*c+1] = hp_mem[2*c+1] + PSHR32(tmp - hp_mem[2*c+1], shift);
         out[channels*i+c] = EXTRACT16(SATURATE(PSHR32(y, 14), 32767));
      }
   }
}


OpusEncoder *opus_encoder_create(opus_int32 Fs, int channels, int application, int *error)
{
   int ret;
   OpusEncoder *st;
   if((Fs!=48000&&Fs!=24000&&Fs!=16000&&Fs!=12000&&Fs!=8000)||(channels!=1&&channels!=2)/*|| (application != OPUS_APPLICATION_AUDIO)*/)
   {
      if (error)
         *error = OPUS_BAD_ARG;
      return NULL;
   }
   st = (OpusEncoder *)opus_alloc(opus_encoder_get_size(channels));
   if (st == NULL)
   {
      if (error)
         *error = OPUS_ALLOC_FAIL;
      return NULL;
   }
   ret = opus_encoder_init(st, Fs, channels, application);
   if (error)
      *error = ret;
   if (ret != OPUS_OK)
   {
      opus_free(st);
      st = NULL;
   }
   return st;
}

static opus_int32 user_bitrate_to_bitrate(OpusEncoder *st, int frame_size, int max_data_bytes)
{
  if(!frame_size)frame_size=st->Fs/400;
  if (st->user_bitrate_bps==OPUS_AUTO)
    return 60*st->Fs/frame_size + st->Fs*st->channels;
  else if (st->user_bitrate_bps==OPUS_BITRATE_MAX)
    return max_data_bytes*8*st->Fs/frame_size;
  else
    return st->user_bitrate_bps;
}



void downmix_int(const void *_x, opus_val32 *y, int subframe, int offset, int c1, int c2, int C)
{
   const opus_int16 *x;
   int j;

   x = (const opus_int16 *)_x;
   for (j=0;j<subframe;j++)
      y[j] = x[(j+offset)*C+c1];
   if (c2>-1)
   {
      for (j=0;j<subframe;j++)
         y[j] += x[(j+offset)*C+c2];
   } else if (c2==-2)
   {
      int c;
      for (c=1;c<C;c++)
      {
         for (j=0;j<subframe;j++)
            y[j] += x[(j+offset)*C+c];
      }
   }
}

opus_int32 frame_size_select(opus_int32 frame_size, int variable_duration, opus_int32 Fs)
{
   int new_size;
   if (frame_size<Fs/400)
      return -1;
   if (variable_duration == OPUS_FRAMESIZE_ARG)
      new_size = frame_size;
   else if (variable_duration >= OPUS_FRAMESIZE_2_5_MS && variable_duration <= OPUS_FRAMESIZE_120_MS)
   {
      if (variable_duration <= OPUS_FRAMESIZE_40_MS)
         new_size = (Fs/400)<<(variable_duration-OPUS_FRAMESIZE_2_5_MS);
      else
         new_size = (variable_duration-OPUS_FRAMESIZE_2_5_MS-2)*Fs/50;
   }
   else
      return -1;
   if (new_size>frame_size)
      return -1;
   if (400*new_size!=Fs   && 200*new_size!=Fs   && 100*new_size!=Fs   &&
        50*new_size!=Fs   &&  25*new_size!=Fs   &&  50*new_size!=3*Fs &&
        50*new_size!=4*Fs &&  50*new_size!=5*Fs &&  50*new_size!=6*Fs)
      return -1;
   return new_size;
}

/* Returns the equivalent bitrate corresponding to 20 ms frames,
   complexity 10 VBR operation. */
static opus_int32 compute_equiv_rate(opus_int32 bitrate, int channels,
      int frame_rate, int vbr, int mode, int complexity, int loss)
{
   opus_int32 equiv;
   equiv = bitrate;
   /* Take into account overhead from smaller frames. */
   equiv -= (40*channels+20)*(frame_rate - 50);
   /* CBR is about a 8% penalty for both SILK and CELT. */
   if (!vbr)
      equiv -= equiv/12;
   /* Complexity makes about 10% difference (from 0 to 10) in general. */
   equiv = equiv * (90+complexity)/100;
   if (mode == MODE_SILK_ONLY)
   {
      /* SILK complexity 0-1 uses the non-delayed-decision NSQ, which
         costs about 20%. */
      if (complexity<2)
         equiv = equiv*4/5;
      equiv -= equiv*loss/(6*loss + 10);
   } else {
      /* Mode not known yet */
      /* Half the SILK loss*/
      equiv -= equiv*loss/(12*loss + 20);
   }
   return equiv;
}



opus_int32 opus_encode_native(OpusEncoder *st, const opus_val16 *pcm, int frame_size,
                unsigned char *data, opus_int32 out_data_bytes,
                const void *analysis_pcm, opus_int32 analysis_size, int c1, int c2,
                int analysis_channels, downmix_func downmix)
{
    void *silk_enc;
    int i;
    int ret=0;
    opus_int32 nBytes;
    ec_enc enc;
    int bytes_target;

    int redundancy = 0;
    int redundancy_bytes = 0; /* Number of bytes to use for redundancy frame */

    VARDECL(opus_val16, pcm_buf);



    int hp_freq_smth1;
    int voice_est; /* Probability of voice in Q7 */
    opus_int32 equiv_rate;
    int delay_compensation;
    int frame_rate;
    opus_int32 max_rate; /* Max bitrate we're allowed to use */
    int curr_bandwidth;

    opus_int32 max_data_bytes; /* Max number of bytes we're allowed to use */
    int total_buffer;

    //VARDECL(opus_val16, tmp_prefill);

    ALLOC_STACK;

    max_data_bytes = IMIN(1276, out_data_bytes);

    if (frame_size <= 0 || max_data_bytes <= 0)
    {
       RESTORE_STACK;
       return OPUS_BAD_ARG;
    }

    /* Cannot encode 100 ms in 1 byte */
    if (max_data_bytes==1 && st->Fs==(frame_size*10))
    {
      RESTORE_STACK;
      return OPUS_BUFFER_TOO_SMALL;
    }

    silk_enc = (char*)st+st->silk_enc_offset;

    if (st->application == OPUS_APPLICATION_RESTRICTED_LOWDELAY)
       delay_compensation = 0;
    else
       delay_compensation = st->delay_compensation;

    (void)analysis_pcm;
    (void)analysis_size;
    (void)c1;
    (void)c2;
    (void)analysis_channels;
    (void)downmix;

    st->voice_ratio = -1;

    total_buffer = delay_compensation;
    st->bitrate_bps = user_bitrate_to_bitrate(st, frame_size, max_data_bytes);

    frame_rate = st->Fs/frame_size;

    {
       int cbrBytes;
       /* Multiply by 12 to make sure the division is exact. */
       int frame_rate12 = 12*st->Fs/frame_size;
       /* We need to make sure that "int" values always fit in 16 bits. */
       cbrBytes = IMIN( (12*st->bitrate_bps/8 + frame_rate12/2)/frame_rate12, max_data_bytes);
       st->bitrate_bps = cbrBytes*(opus_int32)frame_rate12*8/12;
       /* Make sure we provide at least one byte to avoid failing. */
       max_data_bytes = IMAX(1, cbrBytes);
    }
    if (max_data_bytes<3 || st->bitrate_bps < 3*frame_rate*8
       || (frame_rate<50 && (max_data_bytes*frame_rate<300 || st->bitrate_bps < 2400)))
    {
       /*If the space is too low to do something useful, emit 'PLC' frames.*/
       int bw = st->bandwidth == 0 ? OPUS_BANDWIDTH_NARROWBAND : st->bandwidth;
       int packet_code = 0;
       int num_multiframes = 0;


       /* >= 60 ms frames */
       if (frame_rate<=16)
       {
          /* 1 x 60 ms, 2 x 40 ms, 2 x 60 ms */
          if (out_data_bytes==1 || (frame_rate!=10))
          {
             packet_code = frame_rate <= 12;
             frame_rate = frame_rate == 12 ? 25 : 16;
          }
          else
          {
             num_multiframes = 50/frame_rate;
             frame_rate = 50;
             packet_code = 3;
          }
       }

       if(bw>OPUS_BANDWIDTH_WIDEBAND)
          bw=OPUS_BANDWIDTH_WIDEBAND;

       data[0] = gen_toc(frame_rate, bw, st->stream_channels);
       data[0] |= packet_code;

       ret = packet_code <= 1 ? 1 : 2;

       max_data_bytes = IMAX(max_data_bytes, ret);

       if (packet_code==3)
          data[1] = num_multiframes;


       {
          ret = opus_packet_pad(data, ret, max_data_bytes);
          if (ret == OPUS_OK)
             ret = max_data_bytes;
          else
             ret = OPUS_INTERNAL_ERROR;
       }
       RESTORE_STACK;
       return ret;
    }
    max_rate = frame_rate*max_data_bytes*8;

    /* Equivalent 20-ms rate for mode/channel/bandwidth decisions */
//    equiv_rate = compute_equiv_rate(st->bitrate_bps, st->channels, st->Fs/frame_size,
//          st->use_vbr, 0, st->silk_mode.complexity, st->silk_mode.packetLossPercentage);

    if (st->signal_type == OPUS_SIGNAL_VOICE)
       voice_est = 127;
    else if (st->signal_type == OPUS_SIGNAL_MUSIC)
       voice_est = 0;
    else if (st->voice_ratio >= 0)
    {
       voice_est = st->voice_ratio*327>>8;
       /* For AUDIO, never be more than 90% confident of having speech */
       if (st->application == OPUS_APPLICATION_AUDIO)
          voice_est = IMIN(voice_est, 115);
    } else {
        voice_est = 48;
    }


    st->stream_channels = st->channels;


    /* Update equivalent rate with mode decision. */
    equiv_rate = compute_equiv_rate(st->bitrate_bps, st->stream_channels, st->Fs/frame_size,
          0, MODE_SILK_ONLY, st->silk_mode.complexity, st->silk_mode.packetLossPercentage);

    /* Automatic (rate-dependent) bandwidth selection */
    if (st->first || st->silk_mode.allowBandwidthSwitch)
    {
        const opus_int32 *voice_bandwidth_thresholds, *music_bandwidth_thresholds;
        opus_int32 bandwidth_thresholds[8];
        int bandwidth = OPUS_BANDWIDTH_FULLBAND;

        voice_bandwidth_thresholds = mono_voice_bandwidth_thresholds;
        music_bandwidth_thresholds = mono_voice_bandwidth_thresholds;//mono_music_bandwidth_thresholds;
        /* Interpolate bandwidth thresholds depending on voice estimation */
        for (i=0;i<8;i++)
        {
           bandwidth_thresholds[i] = music_bandwidth_thresholds[i]
                    + ((voice_est*voice_est*(voice_bandwidth_thresholds[i]-music_bandwidth_thresholds[i]))>>14);
        }
        do {
            int threshold, hysteresis;
            threshold = bandwidth_thresholds[2*(bandwidth-OPUS_BANDWIDTH_MEDIUMBAND)];
            hysteresis = bandwidth_thresholds[2*(bandwidth-OPUS_BANDWIDTH_MEDIUMBAND)+1];
            if (!st->first)
            {
                if (st->auto_bandwidth >= bandwidth)
                    threshold -= hysteresis;
                else
                    threshold += hysteresis;
            }
            if (equiv_rate >= threshold)
                break;
        } while (--bandwidth>OPUS_BANDWIDTH_NARROWBAND);
        st->bandwidth = st->auto_bandwidth = bandwidth;
        /* Prevents any transition to SWB/FB until the SILK layer has fully
           switched to WB mode and turned the variable LP filter off */
        if (!st->first && !st->silk_mode.inWBmodeWithoutVariableLP && st->bandwidth > OPUS_BANDWIDTH_WIDEBAND)
            st->bandwidth = OPUS_BANDWIDTH_WIDEBAND;
    }

    if (st->bandwidth>st->max_bandwidth)
       st->bandwidth = st->max_bandwidth;

    if (st->user_bandwidth != OPUS_AUTO)
        st->bandwidth = st->user_bandwidth;

    /* This prevents us from using hybrid at unsafe CBR/max rates */
    if (max_rate < 15000)
    {
       st->bandwidth = IMIN(st->bandwidth, OPUS_BANDWIDTH_WIDEBAND);
    }

    /* Prevents Opus from wasting bits on frequencies that are above
       the Nyquist rate of the input signal */
    if (st->Fs <= 24000 && st->bandwidth > OPUS_BANDWIDTH_SUPERWIDEBAND)
        st->bandwidth = OPUS_BANDWIDTH_SUPERWIDEBAND;
    if (st->Fs <= 16000 && st->bandwidth > OPUS_BANDWIDTH_WIDEBAND)
        st->bandwidth = OPUS_BANDWIDTH_WIDEBAND;
    if (st->Fs <= 12000 && st->bandwidth > OPUS_BANDWIDTH_MEDIUMBAND)
        st->bandwidth = OPUS_BANDWIDTH_MEDIUMBAND;
    if (st->Fs <= 8000 && st->bandwidth > OPUS_BANDWIDTH_NARROWBAND)
        st->bandwidth = OPUS_BANDWIDTH_NARROWBAND;

    if (st->lfe)
       st->bandwidth = OPUS_BANDWIDTH_NARROWBAND;

    curr_bandwidth = st->bandwidth;


    /* For the first frame at a new SILK bandwidth */
    if (st->silk_bw_switch)
    {
       redundancy = 1;
       st->silk_bw_switch = 0;
    }


//    if (redundancy)
//    {
//       redundancy_bytes = compute_redundancy_bytes(max_data_bytes, st->bitrate_bps, frame_rate, st->stream_channels);
//       if (redundancy_bytes == 0)
//          redundancy = 0;
//    }

    /* printf("%d %d %d %d\n", st->bitrate_bps, st->stream_channels, st->mode, curr_bandwidth); */
    bytes_target = IMIN(max_data_bytes-redundancy_bytes, st->bitrate_bps * frame_size / (st->Fs * 8)) - 1;

    data += 1;

    ec_enc_init(&enc, data, max_data_bytes-1);

    ALLOC(pcm_buf, (total_buffer+frame_size)*st->channels, opus_val16);
    OPUS_COPY(pcm_buf, &st->delay_buffer[(st->encoder_buffer-total_buffer)*st->channels], total_buffer*st->channels);

    hp_freq_smth1 = ((silk_encoder*)silk_enc)->state_Fxx[0].sCmn.variable_HP_smth1_Q15;

    st->variable_HP_smth2_Q15 = silk_SMLAWB( st->variable_HP_smth2_Q15,
          hp_freq_smth1 - st->variable_HP_smth2_Q15, SILK_FIX_CONST( VARIABLE_HP_SMTH_COEF2, 16 ) );

    dc_reject(pcm, 3, &pcm_buf[total_buffer*st->channels], st->hp_mem, frame_size, st->channels, st->Fs);

    {
        opus_int32 total_bitRate;

       const opus_int16 *pcm_silk;


        /* Distribute bits between SILK and CELT */
        total_bitRate = 8 * bytes_target * frame_rate;

        /* SILK gets all bits */
        st->silk_mode.bitRate = total_bitRate;


        st->silk_mode.payloadSize_ms = 1000 * frame_size / st->Fs;
        st->silk_mode.nChannelsAPI = st->channels;
        st->silk_mode.nChannelsInternal = st->stream_channels;
        if (curr_bandwidth == OPUS_BANDWIDTH_NARROWBAND) {
            st->silk_mode.desiredInternalSampleRate = 8000;
        } else if (curr_bandwidth == OPUS_BANDWIDTH_MEDIUMBAND) {
            st->silk_mode.desiredInternalSampleRate = 12000;
        } else {
            st->silk_mode.desiredInternalSampleRate = 16000;
        }
        st->silk_mode.minInternalSampleRate = 8000;

        st->silk_mode.maxInternalSampleRate = 16000;

        {
           opus_int32 effective_max_rate = max_rate;
           if (frame_rate > 50)
              effective_max_rate = effective_max_rate*2/3;
           if (effective_max_rate < 8000)
           {
              st->silk_mode.maxInternalSampleRate = 12000;
              st->silk_mode.desiredInternalSampleRate = IMIN(12000, st->silk_mode.desiredInternalSampleRate);
           }
           if (effective_max_rate < 7000)
           {
              st->silk_mode.maxInternalSampleRate = 8000;
              st->silk_mode.desiredInternalSampleRate = IMIN(8000, st->silk_mode.desiredInternalSampleRate);
           }
        }

        st->silk_mode.useCBR = 1;

        /* Call SILK encoder for the low band */

        /* Max bits for SILK, counting ToC, redundancy bytes, and optionally redundancy. */
        st->silk_mode.maxBits = (max_data_bytes-1)*8;
        if (redundancy && redundancy_bytes >= 2)
        {
           /* Counting 1 bit for redundancy position and 20 bits for flag+size (only for hybrid). */
           st->silk_mode.maxBits -= redundancy_bytes*8 + 1;
        }

        pcm_silk = pcm_buf+total_buffer*st->channels;

        ret = silk_Encode( silk_enc, &st->silk_mode, pcm_silk, frame_size, &enc, &nBytes, 0 );
        if( ret ) {
            /*fprintf (stderr, "SILK encode error: %d\n", ret);*/
            /* Handle error */
           RESTORE_STACK;
           return OPUS_INTERNAL_ERROR;
        }

        /* Extract SILK internal bandwidth for signaling in first byte */
        {
            if( st->silk_mode.internalSampleRate == 8000 ) {
               curr_bandwidth = OPUS_BANDWIDTH_NARROWBAND;
            } else if( st->silk_mode.internalSampleRate == 12000 ) {
               curr_bandwidth = OPUS_BANDWIDTH_MEDIUMBAND;
            } else if( st->silk_mode.internalSampleRate == 16000 ) {
               curr_bandwidth = OPUS_BANDWIDTH_WIDEBAND;
            }
        }

        st->silk_mode.opusCanSwitch = st->silk_mode.switchReady && !st->nonfinal_frame;

        if (nBytes==0)
        {
           data[-1] = gen_toc(st->Fs/frame_size, curr_bandwidth, st->stream_channels);
           RESTORE_STACK;
           return 1;
        }

    }


    if (st->channels*(st->encoder_buffer-(frame_size+total_buffer)) > 0)
    {
       OPUS_MOVE(st->delay_buffer, &st->delay_buffer[st->channels*frame_size], st->channels*(st->encoder_buffer-frame_size-total_buffer));
       OPUS_COPY(&st->delay_buffer[st->channels*(st->encoder_buffer-frame_size-total_buffer)],
             &pcm_buf[0],
             (frame_size+total_buffer)*st->channels);
    } else {
       OPUS_COPY(st->delay_buffer, &pcm_buf[(frame_size+total_buffer-st->encoder_buffer)*st->channels], st->encoder_buffer*st->channels);
    }
    /* gain_fade() and stereo_fade() need to be after the buffer copying
       because we don't want any of this to affect the SILK part */
    if (st->stream_channels==1)
       st->silk_mode.stereoWidth_Q14 = IMIN((1<<14),2*IMAX(0,equiv_rate-24000));


    redundancy = 0;
    redundancy_bytes = 0;

    {
        ret = (ec_tell(&enc)+7)>>3;
        ec_enc_done(&enc);
    }



    /* Signalling the mode in the first byte */
    data--;
    data[0] = gen_toc(st->Fs/frame_size, curr_bandwidth, st->stream_channels);


    st->first = 0;


    /* In the unlikely case that the SILK encoder busted its target, tell
       the decoder to call the PLC */
    if (ec_tell(&enc) > (max_data_bytes-1)*8)
    {
       if (max_data_bytes < 2)
       {
          RESTORE_STACK;
          return OPUS_BUFFER_TOO_SMALL;
       }
       data[1] = 0;
       ret = 1;
    } else if (!redundancy)
    {
       /*When in LPC only mode it's perfectly
         reasonable to strip off trailing zero bytes as
         the required range decoder behavior is to
         fill these in. This can't be done when the MDCT
         modes are used because the decoder needs to know
         the actual length for allocation purposes.*/
       while(ret>2&&data[ret]==0)ret--;
    }
    /* Count ToC and redundancy */
    ret += 1+redundancy_bytes;

    {
       if (opus_packet_pad(data, ret, max_data_bytes) != OPUS_OK)
       {
          RESTORE_STACK;
          return OPUS_INTERNAL_ERROR;
       }
       ret = max_data_bytes;
    }
    RESTORE_STACK;
    return ret;
}


opus_int32 opus_encode(OpusEncoder *st, const opus_int16 *pcm, int analysis_frame_size,
                unsigned char *data, opus_int32 out_data_bytes)
{
   int frame_size;
   frame_size = frame_size_select(analysis_frame_size, st->variable_duration, st->Fs);
   return opus_encode_native(st, pcm, frame_size, data, out_data_bytes,
                             pcm, analysis_frame_size, 0, -2, st->channels, downmix_int);
}

void opus_encoder_destroy(OpusEncoder *st)
{
    opus_free(st);
}

int opus_packet_get_nb_frames(const unsigned char packet[], opus_int32 len)
{
    int count;
    if (len<1)
        return OPUS_BAD_ARG;
    count = packet[0]&0x3;
    if (count==0)
        return 1;
    else if (count!=3)
        return 2;
    else if (len<2)
        return OPUS_INVALID_PACKET;
    else
        return packet[1]&0x3F;
}
