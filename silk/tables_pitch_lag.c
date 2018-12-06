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


#include "tables.h"


opus_uint8 *s_silk_pitch_lag_iCDF = 0;
const opus_uint8 * get_silk_pitch_lag_iCDF(void){
    if(s_silk_pitch_lag_iCDF==0){
        s_silk_pitch_lag_iCDF = opus_alloc(32);

        s_silk_pitch_lag_iCDF[0] = 253; s_silk_pitch_lag_iCDF[1] = 250;
        s_silk_pitch_lag_iCDF[2] = 244; s_silk_pitch_lag_iCDF[3] = 233;
        s_silk_pitch_lag_iCDF[4] = 212; s_silk_pitch_lag_iCDF[5] = 182;
        s_silk_pitch_lag_iCDF[6] = 150; s_silk_pitch_lag_iCDF[7] = 131;
        s_silk_pitch_lag_iCDF[8] = 120; s_silk_pitch_lag_iCDF[9] = 110;
        s_silk_pitch_lag_iCDF[10] = 98; s_silk_pitch_lag_iCDF[11] = 85;
        s_silk_pitch_lag_iCDF[12] = 72; s_silk_pitch_lag_iCDF[13] = 60;
        s_silk_pitch_lag_iCDF[14] = 49; s_silk_pitch_lag_iCDF[15] = 40;
        s_silk_pitch_lag_iCDF[16] = 32; s_silk_pitch_lag_iCDF[17] = 25;
        s_silk_pitch_lag_iCDF[18] = 19; s_silk_pitch_lag_iCDF[19] = 15;
        s_silk_pitch_lag_iCDF[20] = 13; s_silk_pitch_lag_iCDF[21] = 11;
        s_silk_pitch_lag_iCDF[22] = 9; s_silk_pitch_lag_iCDF[23] = 8;
        s_silk_pitch_lag_iCDF[24] = 7; s_silk_pitch_lag_iCDF[25] = 6;
        s_silk_pitch_lag_iCDF[26] = 5; s_silk_pitch_lag_iCDF[27] = 4;
        s_silk_pitch_lag_iCDF[28] = 3; s_silk_pitch_lag_iCDF[29] = 2;
        s_silk_pitch_lag_iCDF[30] = 1; s_silk_pitch_lag_iCDF[31] = 0;
    }
    return s_silk_pitch_lag_iCDF;
}


opus_uint8 *s_silk_pitch_contour_iCDF = 0;
const opus_uint8 * get_silk_pitch_contour_iCDF(void) {
    if (s_silk_pitch_contour_iCDF == 0) {
        s_silk_pitch_contour_iCDF = opus_alloc(34);

        s_silk_pitch_contour_iCDF[0] = 223; s_silk_pitch_contour_iCDF[1] = 201;
        s_silk_pitch_contour_iCDF[2] = 183; s_silk_pitch_contour_iCDF[3] = 167;
        s_silk_pitch_contour_iCDF[4] = 152; s_silk_pitch_contour_iCDF[5] = 138;
        s_silk_pitch_contour_iCDF[6] = 124; s_silk_pitch_contour_iCDF[7] = 111;
        s_silk_pitch_contour_iCDF[8] = 98; s_silk_pitch_contour_iCDF[9] = 88;
        s_silk_pitch_contour_iCDF[10] = 79; s_silk_pitch_contour_iCDF[11] = 70;
        s_silk_pitch_contour_iCDF[12] = 62; s_silk_pitch_contour_iCDF[13] = 56;
        s_silk_pitch_contour_iCDF[14] = 50; s_silk_pitch_contour_iCDF[15] = 44;
        s_silk_pitch_contour_iCDF[16] = 39; s_silk_pitch_contour_iCDF[17] = 35;
        s_silk_pitch_contour_iCDF[18] = 31; s_silk_pitch_contour_iCDF[19] = 27;
        s_silk_pitch_contour_iCDF[20] = 24; s_silk_pitch_contour_iCDF[21] = 21;
        s_silk_pitch_contour_iCDF[22] = 18; s_silk_pitch_contour_iCDF[23] = 16;
        s_silk_pitch_contour_iCDF[24] = 14; s_silk_pitch_contour_iCDF[25] = 12;
        s_silk_pitch_contour_iCDF[26] = 10; s_silk_pitch_contour_iCDF[27] = 8;
        s_silk_pitch_contour_iCDF[28] = 6; s_silk_pitch_contour_iCDF[29] = 4;
        s_silk_pitch_contour_iCDF[30] = 3; s_silk_pitch_contour_iCDF[31] = 2;
        s_silk_pitch_contour_iCDF[32] = 1; s_silk_pitch_contour_iCDF[33] = 0;
    }

    return s_silk_pitch_contour_iCDF;
}



