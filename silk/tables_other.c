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



#include <malloc.h>
#include "structs.h"

#include "tables.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Piece-wise linear mapping from bitrate in kbps to coding quality in dB SNR */
//const opus_int32 silk_TargetRate_table_NB[ TARGET_RATE_TAB_SZ ] = {
//    0,      8000,   9400,   11500,  13500,  17500,  25000,  MAX_TARGET_RATE_BPS
//};
//const opus_int32 silk_TargetRate_table_MB[ TARGET_RATE_TAB_SZ ] = {
//    0,      9000,   12000,  14500,  18500,  24500,  35500,  MAX_TARGET_RATE_BPS
//};
//const opus_int32 silk_TargetRate_table_WB[ TARGET_RATE_TAB_SZ ] = {
//    0,      10500,  14000,  17000,  21500,  28500,  42000,  MAX_TARGET_RATE_BPS
//};

opus_int32 *s_silk_TargetRate_table_WB = 0;
const opus_int32 *get_silk_TargetRate_table_WB(void){
    if(s_silk_TargetRate_table_WB == 0){
        s_silk_TargetRate_table_WB = malloc(sizeof(opus_int32) * TARGET_RATE_TAB_SZ);
        s_silk_TargetRate_table_WB[0] = 0;
        s_silk_TargetRate_table_WB[1] = 10500;
        s_silk_TargetRate_table_WB[2] = 14000;
        s_silk_TargetRate_table_WB[3] = 17000;
        s_silk_TargetRate_table_WB[4] = 21500;
        s_silk_TargetRate_table_WB[5] = 28500;
        s_silk_TargetRate_table_WB[6] = 42000;
        s_silk_TargetRate_table_WB[7] = MAX_TARGET_RATE_BPS;
    }

    return s_silk_TargetRate_table_WB;
}

//const opus_int16 silk_SNR_table_Q1[ TARGET_RATE_TAB_SZ ] = {
//    18,     29,     38,     40,     46,     52,     62,     84
//};

opus_int16 *s_silk_SNR_table_Q1=0;
const opus_int16 *get_silk_SNR_table_Q1(void){
    if(s_silk_SNR_table_Q1 == 0){
        s_silk_SNR_table_Q1 = malloc(sizeof(opus_int16)*TARGET_RATE_TAB_SZ);

        s_silk_SNR_table_Q1[0] = 18;
        s_silk_SNR_table_Q1[1] = 29;
        s_silk_SNR_table_Q1[2] = 38;
        s_silk_SNR_table_Q1[3] = 40;
        s_silk_SNR_table_Q1[4] = 46;
        s_silk_SNR_table_Q1[5] = 52;
        s_silk_SNR_table_Q1[6] = 62;
        s_silk_SNR_table_Q1[7] = 84;
    }

    return s_silk_SNR_table_Q1;
}


/* Tables for LBRR flags */
//static const opus_uint8 silk_LBRR_flags_2_iCDF[ 3 ] = { 203, 150, 0 };
//static const opus_uint8 silk_LBRR_flags_3_iCDF[ 7 ] = { 215, 195, 166, 125, 110, 82, 0 };
//const opus_uint8 * const silk_LBRR_flags_iCDF_ptr[ 2 ] = {
//    silk_LBRR_flags_2_iCDF,
//    silk_LBRR_flags_3_iCDF
//};

/* Table for LSB coding */
const opus_uint8 silk_lsb_iCDF[ 2 ] = { 120, 0 };

/* Tables for LTPScale */
const opus_uint8 silk_LTPscale_iCDF[ 3 ] = { 128, 64, 0 };

/* Tables for signal type and offset coding */
const opus_uint8 silk_type_offset_VAD_iCDF[ 4 ] = {
       232,    158,    10,      0
};
const opus_uint8 silk_type_offset_no_VAD_iCDF[ 2 ] = {
       230,      0
};

/* Tables for NLSF interpolation factor */
const opus_uint8 silk_NLSF_interpolation_factor_iCDF[ 5 ] = { 243, 221, 192, 181, 0 };

/* Quantization offsets */
const opus_int16  silk_Quantization_Offsets_Q10[ 2 ][ 2 ] = {
    { OFFSET_UVL_Q10, OFFSET_UVH_Q10 }, { OFFSET_VL_Q10, OFFSET_VH_Q10 }
};


/* Uniform entropy tables */
const opus_uint8 silk_uniform4_iCDF[ 4 ] = { 192, 128, 64, 0 };
const opus_uint8 silk_uniform6_iCDF[ 6 ] = { 213, 171, 128, 85, 43, 0 };
const opus_uint8 silk_uniform8_iCDF[ 8 ] = { 224, 192, 160, 128, 96, 64, 32, 0 };

const opus_uint8 silk_NLSF_EXT_iCDF[ 7 ] = { 100, 40, 16, 7, 3, 1, 0 };


#ifdef __cplusplus
}
#endif

