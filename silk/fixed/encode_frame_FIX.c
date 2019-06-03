/***********************************************************************
Copyright (c) 2006-2011, Skype Limited. All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
- Neither the name of Internet Society, IETF or IETF Trust, nor the
names of specific contributors, may be used to endorse or promote
products derived from this software without specific prior written
permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
***********************************************************************/


#include <stdlib.h>
#include "main_FIX.h"
#include "../../celt/stack_alloc.h"
#include "../tuning_parameters.h"

/****************/
/* Encode frame */
/****************/
opus_int silk_encode_frame_FIX(
    silk_encoder_state_FIX          *psEnc,                                 /* I/O  Pointer to Silk FIX encoder state                                           */
    opus_int32                      *pnBytesOut,                            /* O    Pointer to number of payload bytes;                                         */
    ec_enc                          *psRangeEnc,                            /* I/O  compressor data structure                                                   */
    opus_int                        condCoding,                             /* I    The type of conditional coding to use                                       */
    opus_int                        maxBits,                                /* I    If > 0: maximum number of output bits                                       */
    opus_int                        useCBR                                  /* I    Flag to force constant-bitrate operation                                    */
)
{
    silk_encoder_control_FIX sEncCtrl;
    opus_int     i, iter, maxIter, found_upper, found_lower, ret = 0;
    opus_int16   *x_frame;
    ec_enc       sRangeEnc_copy, sRangeEnc_copy2;
    silk_nsq_state sNSQ_copy, sNSQ_copy2;
    opus_int32   seed_copy, nBits, nBits_lower, nBits_upper, gainMult_lower, gainMult_upper;
    opus_int32   gainsID, gainsID_lower, gainsID_upper;
    opus_int16   gainMult_Q8;
    opus_int16   ec_prevLagIndex_copy;
    opus_int     ec_prevSignalType_copy;
    opus_int8    LastGainIndex_copy2;
    opus_int     gain_lock[ MAX_NB_SUBFR ] = {0};
    opus_int16   best_gain_mult[ MAX_NB_SUBFR ];
    opus_int     best_sum[ MAX_NB_SUBFR ];

    /* This is totally unnecessary but many compilers (including gcc) are too dumb to realise it */
    LastGainIndex_copy2 = nBits_lower = nBits_upper = gainMult_lower = gainMult_upper = 0;

    psEnc->sCmn.indices.Seed = psEnc->sCmn.frameCounter++ & 3;

    /**************************************************************/
    /* Set up Input Pointers, and insert frame in input buffer   */
    /*************************************************************/
    /* start of frame to encode */
    x_frame = psEnc->x_buf + psEnc->sCmn.ltp_mem_length;

    /***************************************/
    /* Ensure smooth bandwidth transitions */
    /***************************************/
    //silk_LP_variable_cutoff( &psEnc->sCmn.sLP, psEnc->sCmn.inputBuf + 1, psEnc->sCmn.frame_length );

    /*******************************************/
    /* Copy new frame to front of input buffer */
    /*******************************************/
    silk_memcpy( x_frame + LA_SHAPE_MS * psEnc->sCmn.fs_kHz, psEnc->sCmn.inputBuf + 1, psEnc->sCmn.frame_length * sizeof( opus_int16 ) );

    if( !psEnc->sCmn.prefillFlag ) {
        VARDECL( opus_int16, res_pitch );
        VARDECL( opus_uint8, ec_buf_copy );
        opus_int16 *res_pitch_frame;

        ALLOC( res_pitch,
               psEnc->sCmn.la_pitch + psEnc->sCmn.frame_length
                   + psEnc->sCmn.ltp_mem_length, opus_int16 );
        /* start of pitch LPC residual frame */
        res_pitch_frame = res_pitch + psEnc->sCmn.ltp_mem_length;

        /*****************************************/
        /* Find pitch lags, initial LPC analysis */
        /*****************************************/
        silk_find_pitch_lags_FIX( psEnc, &sEncCtrl, res_pitch, x_frame - psEnc->sCmn.ltp_mem_length, psEnc->sCmn.arch );

        /************************/
        /* Noise shape analysis */
        /************************/
        silk_noise_shape_analysis_FIX( psEnc, &sEncCtrl, res_pitch_frame, x_frame, psEnc->sCmn.arch );

        /***************************************************/
        /* Find linear prediction coefficients (LPC + LTP) */
        /***************************************************/
        silk_find_pred_coefs_FIX( psEnc, &sEncCtrl, res_pitch_frame, x_frame, condCoding );

        /****************************************/
        /* Process gains                        */
        /****************************************/
        silk_process_gains_FIX( psEnc, &sEncCtrl, condCoding );

        /****************************************/
        /* Low Bitrate Redundant Encoding       */
        /****************************************/
        //silk_LBRR_encode_FIX( psEnc, &sEncCtrl, x_frame, condCoding );

        /* Loop over quantizer and entropy coding to control bitrate */
        maxIter = 6;
        gainMult_Q8 = SILK_FIX_CONST( 1, 8 );
        found_lower = 0;
        found_upper = 0;
        gainsID = silk_gains_ID( psEnc->sCmn.indices.GainsIndices, psEnc->sCmn.nb_subfr );
        gainsID_lower = -1;
        gainsID_upper = -1;
        /* Copy part of the input state */
        silk_memcpy( &sRangeEnc_copy, psRangeEnc, sizeof( ec_enc ) );
        silk_memcpy( &sNSQ_copy, &psEnc->sCmn.sNSQ, sizeof( silk_nsq_state ) );
        seed_copy = psEnc->sCmn.indices.Seed;
        ec_prevLagIndex_copy = psEnc->sCmn.ec_prevLagIndex;
        ec_prevSignalType_copy = psEnc->sCmn.ec_prevSignalType;
        ALLOC( ec_buf_copy, 1275, opus_uint8 );
        for( iter = 0; ; iter++ ) {
            if( gainsID == gainsID_lower ) {
                nBits = nBits_lower;
            } else if( gainsID == gainsID_upper ) {
                nBits = nBits_upper;
            } else {
                /* Restore part of the input state */
                if( iter > 0 ) {
                    silk_memcpy( psRangeEnc, &sRangeEnc_copy, sizeof( ec_enc ) );
                    silk_memcpy( &psEnc->sCmn.sNSQ, &sNSQ_copy, sizeof( silk_nsq_state ) );
                    psEnc->sCmn.indices.Seed = seed_copy;
                    psEnc->sCmn.ec_prevLagIndex = ec_prevLagIndex_copy;
                    psEnc->sCmn.ec_prevSignalType = ec_prevSignalType_copy;
                }

                /*****************************************/
                /* Noise shaping quantization            */
                /*****************************************/
                if( psEnc->sCmn.nStatesDelayedDecision > 1 || psEnc->sCmn.warping_Q16 > 0 ) {
                    silk_NSQ_del_dec( &psEnc->sCmn, &psEnc->sCmn.sNSQ, &psEnc->sCmn.indices, x_frame, psEnc->sCmn.pulses,
                           sEncCtrl.PredCoef_Q12[ 0 ], sEncCtrl.LTPCoef_Q14, sEncCtrl.AR_Q13, sEncCtrl.HarmShapeGain_Q14,
                           sEncCtrl.Tilt_Q14, sEncCtrl.LF_shp_Q14, sEncCtrl.Gains_Q16, sEncCtrl.pitchL, sEncCtrl.Lambda_Q10, sEncCtrl.LTP_scale_Q14,
                           psEnc->sCmn.arch );
//                } else {
//                    silk_NSQ( &psEnc->sCmn, &psEnc->sCmn.sNSQ, &psEnc->sCmn.indices, x_frame, psEnc->sCmn.pulses,
//                            sEncCtrl.PredCoef_Q12[ 0 ], sEncCtrl.LTPCoef_Q14, sEncCtrl.AR_Q13, sEncCtrl.HarmShapeGain_Q14,
//                            sEncCtrl.Tilt_Q14, sEncCtrl.LF_shp_Q14, sEncCtrl.Gains_Q16, sEncCtrl.pitchL, sEncCtrl.Lambda_Q10, sEncCtrl.LTP_scale_Q14,
//                            psEnc->sCmn.arch);
                }

                if ( iter == maxIter && !found_lower ) {
                    silk_memcpy( &sRangeEnc_copy2, psRangeEnc, sizeof( ec_enc ) );
                }

                /****************************************/
                /* Encode Parameters                    */
                /****************************************/
                silk_encode_indices( &psEnc->sCmn, psRangeEnc, psEnc->sCmn.nFramesEncoded, 0, condCoding );

                /****************************************/
                /* Encode Excitation Signal             */
                /****************************************/
                silk_encode_pulses( psRangeEnc, psEnc->sCmn.indices.signalType, psEnc->sCmn.indices.quantOffsetType,
                    psEnc->sCmn.pulses, psEnc->sCmn.frame_length );

                nBits = ec_tell( psRangeEnc );

                /* If we still bust after the last iteration, do some damage control. */
                if ( iter == maxIter && !found_lower && nBits > maxBits ) {
                    silk_memcpy( psRangeEnc, &sRangeEnc_copy2, sizeof( ec_enc ) );

                    /* Keep gains the same as the last frame. */
                    psEnc->sShape.LastGainIndex = sEncCtrl.lastGainIndexPrev;
                    for ( i = 0; i < psEnc->sCmn.nb_subfr; i++ ) {
                        psEnc->sCmn.indices.GainsIndices[ i ] = 4;
                    }
                    if (condCoding != CODE_CONDITIONALLY) {
                       psEnc->sCmn.indices.GainsIndices[ 0 ] = sEncCtrl.lastGainIndexPrev;
                    }
                    psEnc->sCmn.ec_prevLagIndex = ec_prevLagIndex_copy;
                    psEnc->sCmn.ec_prevSignalType = ec_prevSignalType_copy;
                    /* Clear all pulses. */
                    for ( i = 0; i < psEnc->sCmn.frame_length; i++ ) {
                        psEnc->sCmn.pulses[ i ] = 0;
                    }

                    silk_encode_indices( &psEnc->sCmn, psRangeEnc, psEnc->sCmn.nFramesEncoded, 0, condCoding );

                    silk_encode_pulses( psRangeEnc, psEnc->sCmn.indices.signalType, psEnc->sCmn.indices.quantOffsetType,
                        psEnc->sCmn.pulses, psEnc->sCmn.frame_length );

                    nBits = ec_tell( psRangeEnc );
                }

                if( useCBR == 0 && iter == 0 && nBits <= maxBits ) {
                    break;
                }
            }

            if( iter == maxIter ) {
                if( found_lower && ( gainsID == gainsID_lower || nBits > maxBits ) ) {
                    /* Restore output state from earlier iteration that did meet the bitrate budget */
                    silk_memcpy( psRangeEnc, &sRangeEnc_copy2, sizeof( ec_enc ) );
                    silk_memcpy( psRangeEnc->buf, ec_buf_copy, sRangeEnc_copy2.offs );
                    silk_memcpy( &psEnc->sCmn.sNSQ, &sNSQ_copy2, sizeof( silk_nsq_state ) );
                    psEnc->sShape.LastGainIndex = LastGainIndex_copy2;
                }
                break;
            }

            if( nBits > maxBits ) {
                if( found_lower == 0 && iter >= 2 ) {
                    /* Adjust the quantizer's rate/distortion tradeoff and discard previous "upper" results */
                    sEncCtrl.Lambda_Q10 = silk_ADD_RSHIFT32( sEncCtrl.Lambda_Q10, sEncCtrl.Lambda_Q10, 1 );
                    found_upper = 0;
                    gainsID_upper = -1;
                } else {
                    found_upper = 1;
                    nBits_upper = nBits;
                    gainMult_upper = gainMult_Q8;
                    gainsID_upper = gainsID;
                }
            } else if( nBits < maxBits - 5 ) {
                found_lower = 1;
                nBits_lower = nBits;
                gainMult_lower = gainMult_Q8;
                if( gainsID != gainsID_lower ) {
                    gainsID_lower = gainsID;
                    /* Copy part of the output state */
                    silk_memcpy( &sRangeEnc_copy2, psRangeEnc, sizeof( ec_enc ) );
                    silk_memcpy( ec_buf_copy, psRangeEnc->buf, psRangeEnc->offs );
                    silk_memcpy( &sNSQ_copy2, &psEnc->sCmn.sNSQ, sizeof( silk_nsq_state ) );
                    LastGainIndex_copy2 = psEnc->sShape.LastGainIndex;
                }
            } else {
                /* Within 5 bits of budget: close enough */
                break;
            }

            if ( !found_lower && nBits > maxBits ) {
                int j;
                for ( i = 0; i < psEnc->sCmn.nb_subfr; i++ ) {
                    int sum=0;
                    for ( j = i*psEnc->sCmn.subfr_length; j < (i+1)*psEnc->sCmn.subfr_length; j++ ) {
                        sum += abs( psEnc->sCmn.pulses[j] );
                    }
                    if ( iter == 0 || (sum < best_sum[i] && !gain_lock[i]) ) {
                        best_sum[i] = sum;
                        best_gain_mult[i] = gainMult_Q8;
                    } else {
                        gain_lock[i] = 1;
                    }
                }
            }
            if( ( found_lower & found_upper ) == 0 ) {
                /* Adjust gain according to high-rate rate/distortion curve */
                if( nBits > maxBits ) {
                    if (gainMult_Q8 < 16384) {
                        gainMult_Q8 *= 2;
                    } else {
                        gainMult_Q8 = 32767;
                    }
                } else {
                    opus_int32 gain_factor_Q16;
                    gain_factor_Q16 = silk_log2lin( silk_LSHIFT( nBits - maxBits, 7 ) / psEnc->sCmn.frame_length + SILK_FIX_CONST( 16, 7 ) );
                    gainMult_Q8 = silk_SMULWB( gain_factor_Q16, gainMult_Q8 );
                }

            } else {
                /* Adjust gain by interpolating */
                gainMult_Q8 = gainMult_lower + silk_DIV32_16( silk_MUL( gainMult_upper - gainMult_lower, maxBits - nBits_lower ), nBits_upper - nBits_lower );
                /* New gain multplier must be between 25% and 75% of old range (note that gainMult_upper < gainMult_lower) */
                if( gainMult_Q8 > silk_ADD_RSHIFT32( gainMult_lower, gainMult_upper - gainMult_lower, 2 ) ) {
                    gainMult_Q8 = silk_ADD_RSHIFT32( gainMult_lower, gainMult_upper - gainMult_lower, 2 );
                } else
                if( gainMult_Q8 < silk_SUB_RSHIFT32( gainMult_upper, gainMult_upper - gainMult_lower, 2 ) ) {
                    gainMult_Q8 = silk_SUB_RSHIFT32( gainMult_upper, gainMult_upper - gainMult_lower, 2 );
                }
            }

            for( i = 0; i < psEnc->sCmn.nb_subfr; i++ ) {
                opus_int16 tmp;
                if ( gain_lock[i] ) {
                    tmp = best_gain_mult[i];
                } else {
                    tmp = gainMult_Q8;
                }
                sEncCtrl.Gains_Q16[ i ] = silk_LSHIFT_SAT32( silk_SMULWB( sEncCtrl.GainsUnq_Q16[ i ], tmp ), 8 );
            }

            /* Quantize gains */
            psEnc->sShape.LastGainIndex = sEncCtrl.lastGainIndexPrev;
            silk_gains_quant( psEnc->sCmn.indices.GainsIndices, sEncCtrl.Gains_Q16,
                  &psEnc->sShape.LastGainIndex, condCoding == CODE_CONDITIONALLY, psEnc->sCmn.nb_subfr );

            /* Unique identifier of gains vector */
            gainsID = silk_gains_ID( psEnc->sCmn.indices.GainsIndices, psEnc->sCmn.nb_subfr );
        }
    }

    /* Update input buffer */
    silk_memmove( psEnc->x_buf, &psEnc->x_buf[ psEnc->sCmn.frame_length ],
        ( psEnc->sCmn.ltp_mem_length + LA_SHAPE_MS * psEnc->sCmn.fs_kHz ) * sizeof( opus_int16 ) );

    /* Exit without entropy coding */
    if( psEnc->sCmn.prefillFlag ) {
        /* No payload */
        *pnBytesOut = 0;
        return ret;
    }

    /* Parameters needed for next frame */
    psEnc->sCmn.prevLag        = sEncCtrl.pitchL[ psEnc->sCmn.nb_subfr - 1 ];
    psEnc->sCmn.prevSignalType = psEnc->sCmn.indices.signalType;

    /****************************************/
    /* Finalize payload                     */
    /****************************************/
    psEnc->sCmn.first_frame_after_reset = 0;
    /* Payload size */
    *pnBytesOut = silk_RSHIFT( ec_tell( psRangeEnc ) + 7, 3 );

    return ret;
}

