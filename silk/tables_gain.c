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
#include "tables.h"



opus_uint8 ** s_silk_gain_iCDF = 0;
const opus_uint8 **get_silk_gain_iCDF(void){
    if(s_silk_gain_iCDF == 0){
        s_silk_gain_iCDF = malloc(sizeof(opus_uint8 *)*3);

        s_silk_gain_iCDF[0] = malloc(sizeof(opus_int8) * 8);
        s_silk_gain_iCDF[0][0] = 224; s_silk_gain_iCDF[0][1] = 112;
        s_silk_gain_iCDF[0][2] = 44; s_silk_gain_iCDF[0][3] = 15;
        s_silk_gain_iCDF[0][4] = 3; s_silk_gain_iCDF[0][5] = 2;
        s_silk_gain_iCDF[0][6] = 1; s_silk_gain_iCDF[0][7] = 0;
        s_silk_gain_iCDF[1] = malloc(sizeof(opus_int8) * 8);
        s_silk_gain_iCDF[1][0] = 254; s_silk_gain_iCDF[1][1] = 237;
        s_silk_gain_iCDF[1][2] = 192; s_silk_gain_iCDF[1][3] = 132;
        s_silk_gain_iCDF[1][4] = 70; s_silk_gain_iCDF[1][5] = 23;
        s_silk_gain_iCDF[1][6] = 4; s_silk_gain_iCDF[1][7] = 0;
        s_silk_gain_iCDF[2] = malloc(sizeof(opus_int8) * 8);
        s_silk_gain_iCDF[2][0] = 255; s_silk_gain_iCDF[2][1] = 252;
        s_silk_gain_iCDF[2][2] = 226; s_silk_gain_iCDF[2][3] = 155;
        s_silk_gain_iCDF[2][4] = 61; s_silk_gain_iCDF[2][5] = 11;
        s_silk_gain_iCDF[2][6] = 2; s_silk_gain_iCDF[2][7] = 0;
    }

    return (const unsigned char **) s_silk_gain_iCDF;
}

opus_uint8 * s_silk_delta_gain_iCDF = 0;
const opus_uint8 *get_silk_delta_gain_iCDF(void){
    if(s_silk_delta_gain_iCDF == 0){
        s_silk_delta_gain_iCDF = malloc(sizeof(opus_uint8) * (MAX_DELTA_GAIN_QUANT - MIN_DELTA_GAIN_QUANT + 1));

        s_silk_delta_gain_iCDF[0] = 250; s_silk_delta_gain_iCDF[1] = 245; s_silk_delta_gain_iCDF[2] = 234;
        s_silk_delta_gain_iCDF[3] = 203; s_silk_delta_gain_iCDF[4] = 71; s_silk_delta_gain_iCDF[5] = 50;
        s_silk_delta_gain_iCDF[6] = 42; s_silk_delta_gain_iCDF[7] = 38; s_silk_delta_gain_iCDF[8] = 35;
        s_silk_delta_gain_iCDF[9] = 33; s_silk_delta_gain_iCDF[10] = 31; s_silk_delta_gain_iCDF[11] = 29;
        s_silk_delta_gain_iCDF[12] = 28; s_silk_delta_gain_iCDF[13] = 27; s_silk_delta_gain_iCDF[14] = 26;
        s_silk_delta_gain_iCDF[15] = 25; s_silk_delta_gain_iCDF[16] = 24; s_silk_delta_gain_iCDF[17] = 23;
        s_silk_delta_gain_iCDF[18] = 22; s_silk_delta_gain_iCDF[19] = 21; s_silk_delta_gain_iCDF[20] = 20;
        s_silk_delta_gain_iCDF[21] = 19; s_silk_delta_gain_iCDF[22] = 18; s_silk_delta_gain_iCDF[23] = 17;
        s_silk_delta_gain_iCDF[24] = 16; s_silk_delta_gain_iCDF[25] = 15; s_silk_delta_gain_iCDF[26] = 14;
        s_silk_delta_gain_iCDF[27] = 13; s_silk_delta_gain_iCDF[28] = 12; s_silk_delta_gain_iCDF[29] = 11;
        s_silk_delta_gain_iCDF[30] = 10; s_silk_delta_gain_iCDF[31] = 9; s_silk_delta_gain_iCDF[32] = 8;
        s_silk_delta_gain_iCDF[33] = 7; s_silk_delta_gain_iCDF[34] = 6; s_silk_delta_gain_iCDF[35] = 5;
        s_silk_delta_gain_iCDF[36] = 4; s_silk_delta_gain_iCDF[37] = 3; s_silk_delta_gain_iCDF[38] = 2;
        s_silk_delta_gain_iCDF[39] = 1; s_silk_delta_gain_iCDF[40] = 0;
    }

    return (const unsigned char *) s_silk_delta_gain_iCDF;
}


