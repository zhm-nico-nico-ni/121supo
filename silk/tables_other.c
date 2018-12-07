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



#include "structs.h"

#include "tables.h"



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
        s_silk_TargetRate_table_WB = opus_alloc(sizeof(opus_int32) * TARGET_RATE_TAB_SZ);
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
        s_silk_SNR_table_Q1 = opus_alloc(sizeof(opus_int16)*TARGET_RATE_TAB_SZ);

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
opus_uint8 *s_silk_lsb_iCDF = 0;
opus_uint8 * get_silk_lsb_iCDF(void){
    if(s_silk_lsb_iCDF == 0){
        s_silk_lsb_iCDF = opus_alloc(2);
        s_silk_lsb_iCDF[0] = 120;
        s_silk_lsb_iCDF[1] = 0;
    }

    return s_silk_lsb_iCDF;
}

/* Tables for LTPScale */
opus_uint8 *s_silk_LTPscale_iCDF = 0;
opus_uint8 * get_silk_LTPscale_iCDF(void){
    if(s_silk_LTPscale_iCDF == 0){
        s_silk_LTPscale_iCDF = opus_alloc(3);
        s_silk_LTPscale_iCDF[0] = 128;
        s_silk_LTPscale_iCDF[1] = 64;
        s_silk_LTPscale_iCDF[2] = 0;
    }

    return s_silk_LTPscale_iCDF;
}

/* Tables for signal type and offset coding */
opus_uint8 *s_silk_type_offset_VAD_iCDF = 0;
opus_uint8 * get_silk_type_offset_VAD_iCDF(void){
    if(s_silk_type_offset_VAD_iCDF == 0){
        s_silk_type_offset_VAD_iCDF = opus_alloc(4);
        s_silk_type_offset_VAD_iCDF[0] = 232;
        s_silk_type_offset_VAD_iCDF[1] = 158;
        s_silk_type_offset_VAD_iCDF[2] = 10;
        s_silk_type_offset_VAD_iCDF[3] = 0;
    }

    return s_silk_type_offset_VAD_iCDF;
}

opus_uint8 *s_silk_type_offset_no_VAD_iCDF = 0;
opus_uint8 * get_silk_type_offset_no_VAD_iCDF(void){
    if(s_silk_type_offset_no_VAD_iCDF == 0){
        s_silk_type_offset_no_VAD_iCDF = opus_alloc(2);
        s_silk_type_offset_no_VAD_iCDF[0] = 230;
        s_silk_type_offset_no_VAD_iCDF[1] = 0;
    }

    return s_silk_type_offset_no_VAD_iCDF;
}

/* Tables for NLSF interpolation factor */
opus_uint8 *s_silk_NLSF_interpolation_factor_iCDF = 0;
opus_uint8 * get_silk_NLSF_interpolation_factor_iCDF(void){
    if(s_silk_NLSF_interpolation_factor_iCDF == 0){
        s_silk_NLSF_interpolation_factor_iCDF = opus_alloc(5);
        s_silk_NLSF_interpolation_factor_iCDF[0] = 243;
        s_silk_NLSF_interpolation_factor_iCDF[1] = 221;
        s_silk_NLSF_interpolation_factor_iCDF[2] = 192;
        s_silk_NLSF_interpolation_factor_iCDF[3] = 181;
        s_silk_NLSF_interpolation_factor_iCDF[4] = 0;
    }

    return s_silk_NLSF_interpolation_factor_iCDF;
}

/* Quantization offsets */
opus_int16 ** s_silk_Quantization_Offsets_Q10 = 0;
opus_int16 ** get_silk_Quantization_Offsets_Q10(void){
    if(s_silk_Quantization_Offsets_Q10 == 0){
        s_silk_Quantization_Offsets_Q10 = opus_alloc(sizeof(opus_int16*) * 2);

        s_silk_Quantization_Offsets_Q10[0] = opus_alloc(2);
        s_silk_Quantization_Offsets_Q10[0][0]=OFFSET_UVL_Q10;
        s_silk_Quantization_Offsets_Q10[0][1]=OFFSET_UVH_Q10;

        s_silk_Quantization_Offsets_Q10[1] = opus_alloc(2);
        s_silk_Quantization_Offsets_Q10[1][0]=OFFSET_VL_Q10;
        s_silk_Quantization_Offsets_Q10[1][1]=OFFSET_VH_Q10;
    }

    return s_silk_Quantization_Offsets_Q10;
}

/* Uniform entropy tables */
opus_uint8 *s_silk_uniform4_iCDF = 0;
opus_uint8 * get_silk_uniform4_iCDF(void){
    if(s_silk_uniform4_iCDF == 0){
        s_silk_uniform4_iCDF = opus_alloc(4);
        s_silk_uniform4_iCDF[0] = 192;
        s_silk_uniform4_iCDF[1] = 128;
        s_silk_uniform4_iCDF[2] = 64;
        s_silk_uniform4_iCDF[3] = 0;
    }

    return s_silk_uniform4_iCDF;
}

//opus_uint8 * s_silk_uniform6_iCDF = 0;
//opus_uint8 * get_silk_uniform6_iCDF(void){
//    if(s_silk_uniform6_iCDF == 0){
//        s_silk_uniform6_iCDF = opus_alloc(6);
//        s_silk_uniform6_iCDF[0] = 213;
//        s_silk_uniform6_iCDF[1] = 171;
//        s_silk_uniform6_iCDF[2] = 128;
//        s_silk_uniform6_iCDF[3] = 85;
//        s_silk_uniform6_iCDF[4] = 43;
//        s_silk_uniform6_iCDF[5] = 0;
//    }
//
//    return s_silk_uniform6_iCDF;
//}

opus_uint8 *s_silk_uniform8_iCDF = 0;
opus_uint8 * get_silk_uniform8_iCDF(void){
    if(s_silk_uniform8_iCDF == 0){
        s_silk_uniform8_iCDF = opus_alloc(8);
        s_silk_uniform8_iCDF[0] = 224;
        s_silk_uniform8_iCDF[1] = 192;
        s_silk_uniform8_iCDF[2] = 160;
        s_silk_uniform8_iCDF[3] = 128;
        s_silk_uniform8_iCDF[4] = 96;
        s_silk_uniform8_iCDF[5] = 64;
        s_silk_uniform8_iCDF[6] = 32;
        s_silk_uniform8_iCDF[7] = 0;
    }

    return s_silk_uniform8_iCDF;
}

opus_uint8 *s_silk_NLSF_EXT_iCDF = 0;
opus_uint8 * get_silk_NLSF_EXT_iCDF(void){
    if(s_silk_NLSF_EXT_iCDF == 0){
        s_silk_NLSF_EXT_iCDF = opus_alloc(7);
        s_silk_NLSF_EXT_iCDF[0] = 100;
        s_silk_NLSF_EXT_iCDF[1] = 40;
        s_silk_NLSF_EXT_iCDF[2] = 16;
        s_silk_NLSF_EXT_iCDF[3] = 7;
        s_silk_NLSF_EXT_iCDF[4] = 3;
        s_silk_NLSF_EXT_iCDF[5] = 1;
        s_silk_NLSF_EXT_iCDF[6] = 0;
    }

    return s_silk_NLSF_EXT_iCDF;
}




