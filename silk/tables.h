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

#ifndef SILK_TABLES_H
#define SILK_TABLES_H

#include "define.h"
#include "structs.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Entropy coding tables (with size in bytes indicated) */
extern const opus_uint8  silk_gain_iCDF[ 3 ][ N_LEVELS_QGAIN / 8 ];                                 /* 24 */
extern const opus_uint8  silk_delta_gain_iCDF[ MAX_DELTA_GAIN_QUANT - MIN_DELTA_GAIN_QUANT + 1 ];   /* 41 */

extern const opus_uint8  silk_pitch_lag_iCDF[ 2 * ( PITCH_EST_MAX_LAG_MS - PITCH_EST_MIN_LAG_MS ) ];/* 32 */
//extern const opus_uint8  silk_pitch_delta_iCDF[ 21 ];                                               /*  21 */
extern const opus_uint8  silk_pitch_contour_iCDF[ 34 ];                                             /*  34 */

extern const opus_uint8  silk_pulses_per_block_iCDF[ N_RATE_LEVELS ][ SILK_MAX_PULSES + 2 ];        /* 180 */
extern const opus_uint8  silk_pulses_per_block_BITS_Q5[ N_RATE_LEVELS - 1 ][ SILK_MAX_PULSES + 2 ]; /* 162 */

extern const opus_uint8  silk_rate_levels_iCDF[ 2 ][ N_RATE_LEVELS - 1 ];                           /*  18 */
extern const opus_uint8  silk_rate_levels_BITS_Q5[ 2 ][ N_RATE_LEVELS - 1 ];                        /*  18 */

extern const opus_uint8  silk_max_pulses_table[ 4 ];                                                /*   4 */

typedef struct _silk_shell_code_table_struct silk_shell_code_table_struct;
struct _silk_shell_code_table_struct{
    opus_uint8  silk_shell_code_table0[ 152 ];
    opus_uint8  silk_shell_code_table1[ 152 ];
    opus_uint8  silk_shell_code_table2[ 152 ];
    opus_uint8  silk_shell_code_table3[ 152 ];
};


extern const opus_uint8  silk_shell_code_table_offsets[ SILK_MAX_PULSES + 1 ];                      /*  17 */

extern const opus_uint8  silk_lsb_iCDF[ 2 ];                                                        /*   2 */

extern const opus_uint8  silk_sign_iCDF[ 42 ];                                                      /*  42 */

extern const opus_uint8  silk_uniform4_iCDF[ 4 ];                                                   /*   4 */
extern const opus_uint8  silk_uniform6_iCDF[ 6 ];                                                   /*   6 */
extern const opus_uint8  silk_uniform8_iCDF[ 8 ];                                                   /*   8 */

extern const opus_uint8  silk_NLSF_EXT_iCDF[ 7 ];                                                   /*   7 */

extern const opus_uint8  silk_LTP_per_index_iCDF[ 3 ];                                              /*   3 */
extern const opus_uint8  * const silk_LTP_gain_iCDF_ptrs[ NB_LTP_CBKS ];                            /*   3 */
extern const opus_uint8  * const silk_LTP_gain_BITS_Q5_ptrs[ NB_LTP_CBKS ];                         /*   3 */
extern const opus_int8   * const silk_LTP_vq_ptrs_Q7[ NB_LTP_CBKS ];                                /* 168 */
extern const opus_uint8  * const silk_LTP_vq_gain_ptrs_Q7[NB_LTP_CBKS];
extern const opus_int8   silk_LTP_vq_sizes[ NB_LTP_CBKS ];                                          /*   3 */

extern const opus_uint8  silk_LTPscale_iCDF[ 3 ];                                                   /*   4 */
extern const opus_int16  silk_LTPScales_table_Q14[ 3 ];                                             /*   6 */

extern const opus_uint8  silk_type_offset_VAD_iCDF[ 4 ];                                            /*   4 */
extern const opus_uint8  silk_type_offset_no_VAD_iCDF[ 2 ];                                         /*   2 */


//extern const opus_uint8  * const silk_LBRR_flags_iCDF_ptr[ 2 ];                                     /*  10 */

extern const opus_uint8  silk_NLSF_interpolation_factor_iCDF[ 5 ];                                  /*   5 */

//typedef struct _my_silk_table_struct my_silk_table_struct;
//struct _my_silk_table_struct{
//    opus_uint8  silk_shell_code_table0[ 152 ];
//    opus_uint8  silk_shell_code_table1[ 152 ];
//    opus_uint8  silk_shell_code_table2[ 152 ];
//    opus_uint8  silk_shell_code_table3[ 152 ];
//};

silk_NLSF_CB_struct* getSilk_NLSF_CB_WB(void);

/* Piece-wise linear mapping from bitrate in kbps to coding quality in dB SNR */
//extern const opus_int32  silk_TargetRate_table_NB[  TARGET_RATE_TAB_SZ ];                           /*  32 */
//extern const opus_int32  silk_TargetRate_table_MB[  TARGET_RATE_TAB_SZ ];                           /*  32 */
extern const opus_int32  silk_TargetRate_table_WB[  TARGET_RATE_TAB_SZ ];                           /*  32 */
extern const opus_int16  silk_SNR_table_Q1[         TARGET_RATE_TAB_SZ ];                           /*  32 */

/* Quantization offsets */
extern const opus_int16  silk_Quantization_Offsets_Q10[ 2 ][ 2 ];                                   /*   8 */


/* Rom table with cosine values */
extern const opus_int16  silk_LSFCosTab_FIX_Q12[ LSF_COS_TAB_SZ_FIX + 1 ];                          /* 258 */

#ifdef __cplusplus
}
#endif

#endif
