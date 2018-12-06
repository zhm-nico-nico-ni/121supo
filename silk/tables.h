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
const opus_uint8 **get_silk_gain_iCDF(void);                                 /* 24 */
const opus_uint8 *get_silk_delta_gain_iCDF(void);  /* 41 */


const opus_uint8 * get_silk_pitch_lag_iCDF(void);/* 32 */
const opus_uint8 * get_silk_pitch_contour_iCDF(void);/*  34 */

const opus_uint8 **get_silk_pulses_per_block_iCDF(void);        /* 180 */
const opus_uint8 **get_silk_pulses_per_block_BITS_Q5(void);/* 162 */

const opus_uint8 **get_silk_rate_levels_iCDF(void);                          /*  18 */
const opus_uint8 **get_silk_rate_levels_BITS_Q5(void);                       /*  18 */

typedef struct _silk_shell_code_table_struct silk_shell_code_table_struct;
struct _silk_shell_code_table_struct{
    opus_uint8  silk_shell_code_table0[ 152 ];
    opus_uint8  silk_shell_code_table1[ 152 ];
    opus_uint8  silk_shell_code_table2[ 152 ];
    opus_uint8  silk_shell_code_table3[ 152 ];
};


const opus_uint8 * get_silk_shell_code_table_offsets(void);                     /*  17 */

extern const opus_uint8  silk_lsb_iCDF[ 2 ];                                                        /*   2 */

const opus_uint8 * get_silk_sign_iCDF(void);                                                      /*  42 */

extern const opus_uint8  silk_uniform4_iCDF[ 4 ];                                                   /*   4 */
extern const opus_uint8  silk_uniform6_iCDF[ 6 ];                                                   /*   6 */
extern const opus_uint8  silk_uniform8_iCDF[ 8 ];                                                   /*   8 */

extern const opus_uint8  silk_NLSF_EXT_iCDF[ 7 ];                                                   /*   7 */

const opus_uint8 ** get_silk_LTP_gain_iCDF_ptrs(void);

const opus_uint8 **get_silk_LTP_gain_BITS_Q5_ptrs(void);
const opus_int8 **get_silk_LTP_vq_ptrs_Q7(void);
const opus_uint8 **get_silk_LTP_vq_gain_ptrs_Q7(void);

extern const opus_uint8  silk_LTPscale_iCDF[ 3 ];                                                   /*   4 */

extern const opus_uint8  silk_type_offset_VAD_iCDF[ 4 ];                                            /*   4 */
extern const opus_uint8  silk_type_offset_no_VAD_iCDF[ 2 ];                                         /*   2 */


extern const opus_uint8  silk_NLSF_interpolation_factor_iCDF[ 5 ];                                  /*   5 */


silk_NLSF_CB_struct* getSilk_NLSF_CB_WB(void);

/* Piece-wise linear mapping from bitrate in kbps to coding quality in dB SNR */
const opus_int32 *get_silk_TargetRate_table_WB(void);                          /*  32 */
const opus_int16 *get_silk_SNR_table_Q1(void);                          /*  32 */

/* Quantization offsets */
extern const opus_int16  silk_Quantization_Offsets_Q10[ 2 ][ 2 ];                                   /*   8 */


/* Rom table with cosine values */
const opus_int16 *get_silk_LSFCosTab_FIX_Q12(void);                         /* 258 */


#ifdef __cplusplus
}
#endif

#endif
