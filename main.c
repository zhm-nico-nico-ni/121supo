#include <stdio.h>
#include <define.h>
#include <stdlib.h>
#include <opus.h>
#include <math.h>



#define MAX_PACKET 40
int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    int err;
    char *inFile, *outFile;
    FILE *fin, *fout;
    OpusEncoder *enc=NULL;

    int frame_size, channels = 1;
    int use_vbr = 0;//cbr
    int cvbr = 0;
    int bandwidth=OPUS_BANDWIDTH_WIDEBAND;
    int application=OPUS_APPLICATION_AUDIO;
    opus_int32 sampling_rate = 16000;
    opus_int32 bitrate_bps = 32000;
    int complexity = 4;
    int use_inbandfec = 0;
    int forcechannels = 1;//OPUS_AUTO;
    int use_dtx = 0;
    int packet_loss_perc = 0;
    opus_int32 skip=0;
    int variable_duration=OPUS_FRAMESIZE_20_MS;

    frame_size = sampling_rate/50;
    int stop=0;


    inFile = argv[1];
    fin = fopen(inFile, "rb");
    if (!fin)
    {
        fprintf (stderr, "Could not open input file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    outFile = argv[2];
    fout = fopen(outFile, "wb+");
    if (!fout)
    {
        fprintf (stderr, "Could not open output file %s\n", argv[2]);
        fclose(fin);
        return EXIT_FAILURE;
    }

    {
        enc = opus_encoder_create(sampling_rate, channels, application, &err);
        if (err != OPUS_OK)
        {
            fprintf(stderr, "Cannot create encoder: %d\n", err);
            fclose(fin);
            fclose(fout);
            return EXIT_FAILURE;
        }
        opus_encoder_ctl(enc, OPUS_SET_BITRATE(bitrate_bps));
        opus_encoder_ctl(enc, OPUS_SET_BANDWIDTH(bandwidth));
        opus_encoder_ctl(enc, OPUS_SET_VBR(use_vbr));
        opus_encoder_ctl(enc, OPUS_SET_VBR_CONSTRAINT(cvbr));
        opus_encoder_ctl(enc, OPUS_SET_COMPLEXITY(complexity));
        opus_encoder_ctl(enc, OPUS_SET_INBAND_FEC(use_inbandfec));
        opus_encoder_ctl(enc, OPUS_SET_FORCE_CHANNELS(forcechannels));
        opus_encoder_ctl(enc, OPUS_SET_DTX(use_dtx));
        opus_encoder_ctl(enc, OPUS_SET_PACKET_LOSS_PERC(packet_loss_perc));

        opus_encoder_ctl(enc, OPUS_GET_LOOKAHEAD(&skip));
        opus_encoder_ctl(enc, OPUS_SET_LSB_DEPTH(16));
        opus_encoder_ctl(enc, OPUS_SET_EXPERT_FRAME_DURATION(variable_duration));
    }

    fprintf(stderr, "Encoding %ld Hz input at %.3f kb/s "
                    "in %s with %d-sample frames.\n",
            (long)sampling_rate, bitrate_bps*0.001,
            "", frame_size);



    size_t num_read;
    unsigned char *fbytes;
    int remaining=0, curr_read=0, nb_encoded=0, toggle = 0
    , curr_mode_count=0, mode_switch_time = 48000, curr_mode=0,nb_modes_in_list=0;
    opus_uint64 tot_in;
    opus_int32 count=0, count_act=0;
    short *in, *out;
    int len[2];
    unsigned char *data[2];
    opus_uint32 enc_final_range[2];
    double tot_samples=0, bits=0.0, bits_max=0.0, bits_act=0.0, bits2=0.0, nrg;
    int k;

    int max_frame_size = 48000*2;
    in = (short*)malloc(max_frame_size*channels*sizeof(short));
    out = (short*)malloc(max_frame_size*channels*sizeof(short));
    /* We need to allocate for 16-bit PCM data, but we store it as unsigned char. */
    fbytes = (unsigned char*)malloc(max_frame_size*channels*sizeof(short));
    data[0] = (unsigned char*)calloc(MAX_PACKET,sizeof(unsigned char));

    while (!stop)
    {

        {
            int i;
            num_read = fread(fbytes, sizeof(short)*channels, frame_size-remaining, fin);
            curr_read = (int)num_read;
            tot_in += curr_read;
            for(i=0;i<curr_read*channels;i++)
            {
                opus_int32 s;
                s=fbytes[2*i+1]<<8|fbytes[2*i];
                s=((s&0xFFFF)^0x8000)-0x8000;
                in[i+remaining*channels]=s;
            }
            if (curr_read+remaining < frame_size)
            {
                for (i=(curr_read+remaining)*channels;i<frame_size*channels;i++)
                    in[i] = 0;
                stop = 1;
            }
            len[toggle] = opus_encode(enc, in, frame_size, data[toggle], MAX_PACKET);
            nb_encoded = opus_packet_get_samples_per_frame(data[toggle], sampling_rate)*opus_packet_get_nb_frames(data[toggle], len[toggle]);
            remaining = frame_size-nb_encoded;
            for(i=0;i<remaining*channels;i++)
                in[i] = in[nb_encoded*channels+i];


            opus_encoder_ctl(enc, OPUS_GET_FINAL_RANGE(&enc_final_range[toggle]));
            if (len[toggle] < 0)
            {
                fprintf (stderr, "opus_encode() returned %d\n", len[toggle]);
                fclose(fin);
                fclose(fout);
                return EXIT_FAILURE;
            }
            curr_mode_count += frame_size;
            if (curr_mode_count > mode_switch_time && curr_mode < nb_modes_in_list-1)
            {
                curr_mode++;
                curr_mode_count = 0;
            }
        }


        {

            if (fwrite(data[toggle], 1, len[toggle], fout) != (unsigned)len[toggle]) {
                fprintf(stderr, "Error writing.\n");
                return EXIT_FAILURE;
            }
            tot_samples += nb_encoded;
        }


        if( count >= use_inbandfec ) {
            /* count bits */
            bits += len[toggle]*8;
            bits_max = ( len[toggle]*8 > bits_max ) ? len[toggle]*8 : bits_max;
            bits2 += len[toggle]*len[toggle]*64;

            {
                nrg = 0.0;
                for ( k = 0; k < frame_size * channels; k++ ) {
                    nrg += in[ k ] * (double)in[ k ];
                }
                nrg /= frame_size * channels;
                if( nrg > 1e5 ) {
                    bits_act += len[toggle]*8;
                    count_act++;
                }
            }
        }
        count++;
        toggle = (toggle + use_inbandfec) & 1;
    }


    count -= use_inbandfec;
    fprintf (stderr, "average bitrate:             %7.3f kb/s\n",
             1e-3*bits*sampling_rate/tot_samples);
    fprintf (stderr, "maximum bitrate:             %7.3f kb/s\n",
             1e-3*bits_max*sampling_rate/frame_size);

    fprintf (stderr, "active bitrate:              %7.3f kb/s\n",
             1e-3*bits_act*sampling_rate/(1e-15+frame_size*(double)count_act));
//    fprintf (stderr, "bitrate standard deviation:  %7.3f kb/s\n",
//             1e-3*sqrt(bits2/count - bits*bits/(count*(double)count))*sampling_rate/frame_size);
//    silk_TimerSave("opus_timing.txt");
    opus_encoder_destroy(enc);
    free(data[0]);

    fclose(fin);
    fclose(fout);
    free(in);
    free(out);
    free(fbytes);
    return 0;
}