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
#include "tables.h"



opus_uint8 ** s_silk_LTP_gain_iCDF_ptrs = 0;
/* Structure containing NLSF codebook */
const opus_uint8 ** get_silk_LTP_gain_iCDF_ptrs(void){
    if(s_silk_LTP_gain_iCDF_ptrs == NULL){
        s_silk_LTP_gain_iCDF_ptrs = malloc(sizeof(opus_uint8 *) * 3);

        s_silk_LTP_gain_iCDF_ptrs[0] = malloc(sizeof(opus_uint8) * 8);
        s_silk_LTP_gain_iCDF_ptrs[0][0] = 71;
        s_silk_LTP_gain_iCDF_ptrs[0][1] = 56;
        s_silk_LTP_gain_iCDF_ptrs[0][2] = 43;
        s_silk_LTP_gain_iCDF_ptrs[0][3] = 30;
        s_silk_LTP_gain_iCDF_ptrs[0][4] = 21;
        s_silk_LTP_gain_iCDF_ptrs[0][5] = 12;
        s_silk_LTP_gain_iCDF_ptrs[0][6] = 6;
        s_silk_LTP_gain_iCDF_ptrs[0][7] = 0;

        s_silk_LTP_gain_iCDF_ptrs[1] = malloc(sizeof(opus_uint8) * 16);
        s_silk_LTP_gain_iCDF_ptrs[1][0] = 199;
        s_silk_LTP_gain_iCDF_ptrs[1][1] = 165;
        s_silk_LTP_gain_iCDF_ptrs[1][2] = 144;
        s_silk_LTP_gain_iCDF_ptrs[1][3] = 124;
        s_silk_LTP_gain_iCDF_ptrs[1][4] = 109;
        s_silk_LTP_gain_iCDF_ptrs[1][5] = 96;
        s_silk_LTP_gain_iCDF_ptrs[1][6] = 84;
        s_silk_LTP_gain_iCDF_ptrs[1][7] = 71;
        s_silk_LTP_gain_iCDF_ptrs[1][8] = 61;
        s_silk_LTP_gain_iCDF_ptrs[1][9] = 51;
        s_silk_LTP_gain_iCDF_ptrs[1][10] = 42;
        s_silk_LTP_gain_iCDF_ptrs[1][11] = 32;
        s_silk_LTP_gain_iCDF_ptrs[1][12] = 23;
        s_silk_LTP_gain_iCDF_ptrs[1][13] = 15;
        s_silk_LTP_gain_iCDF_ptrs[1][14] = 8;
        s_silk_LTP_gain_iCDF_ptrs[1][15] = 0;

        s_silk_LTP_gain_iCDF_ptrs[2] = malloc(sizeof(opus_uint8) * 32);
        s_silk_LTP_gain_iCDF_ptrs[2][0] = 241; s_silk_LTP_gain_iCDF_ptrs[2][16] = 72;
        s_silk_LTP_gain_iCDF_ptrs[2][1] = 225; s_silk_LTP_gain_iCDF_ptrs[2][17] = 64;
        s_silk_LTP_gain_iCDF_ptrs[2][2] = 211; s_silk_LTP_gain_iCDF_ptrs[2][18] = 57;
        s_silk_LTP_gain_iCDF_ptrs[2][3] = 199; s_silk_LTP_gain_iCDF_ptrs[2][19] = 50;
        s_silk_LTP_gain_iCDF_ptrs[2][4] = 187; s_silk_LTP_gain_iCDF_ptrs[2][20] = 44;
        s_silk_LTP_gain_iCDF_ptrs[2][5] = 175; s_silk_LTP_gain_iCDF_ptrs[2][21] = 38;
        s_silk_LTP_gain_iCDF_ptrs[2][6] = 164; s_silk_LTP_gain_iCDF_ptrs[2][22] = 33;
        s_silk_LTP_gain_iCDF_ptrs[2][7] = 153; s_silk_LTP_gain_iCDF_ptrs[2][23] = 29;
        s_silk_LTP_gain_iCDF_ptrs[2][8] = 142; s_silk_LTP_gain_iCDF_ptrs[2][24] = 24;
        s_silk_LTP_gain_iCDF_ptrs[2][9] = 132; s_silk_LTP_gain_iCDF_ptrs[2][25] = 20;
        s_silk_LTP_gain_iCDF_ptrs[2][10] =123; s_silk_LTP_gain_iCDF_ptrs[2][26] = 16;
        s_silk_LTP_gain_iCDF_ptrs[2][11] =114; s_silk_LTP_gain_iCDF_ptrs[2][27] = 12;
        s_silk_LTP_gain_iCDF_ptrs[2][12] =105; s_silk_LTP_gain_iCDF_ptrs[2][28] = 9;
        s_silk_LTP_gain_iCDF_ptrs[2][13] = 96; s_silk_LTP_gain_iCDF_ptrs[2][29] = 5;
        s_silk_LTP_gain_iCDF_ptrs[2][14] = 88; s_silk_LTP_gain_iCDF_ptrs[2][30] = 2;
        s_silk_LTP_gain_iCDF_ptrs[2][15] = 80; s_silk_LTP_gain_iCDF_ptrs[2][31] = 0;
    }

    return (const unsigned char **) s_silk_LTP_gain_iCDF_ptrs;
}



opus_uint8 ** s_silk_LTP_gain_BITS_Q5_ptrs = 0;
const opus_uint8 **get_silk_LTP_gain_BITS_Q5_ptrs(void){
    if(s_silk_LTP_gain_BITS_Q5_ptrs == NULL) {
        s_silk_LTP_gain_BITS_Q5_ptrs = malloc(sizeof(opus_uint8 *) * 3);

        s_silk_LTP_gain_BITS_Q5_ptrs[0] = malloc(sizeof(opus_uint8) * 8);
        s_silk_LTP_gain_BITS_Q5_ptrs[0][0] = 15;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][1] = 131;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][2] = 138;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][3] = 138;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][4] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][5] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][6] = 173;
        s_silk_LTP_gain_BITS_Q5_ptrs[0][7] = 173;

        s_silk_LTP_gain_BITS_Q5_ptrs[1] = malloc(sizeof(opus_uint8) * 16);
        s_silk_LTP_gain_BITS_Q5_ptrs[1][0] = 69;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][1] = 93;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][2] = 115;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][3] = 118;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][4] = 131;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][5] = 138;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][6] = 141;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][7] = 138;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][8] = 150;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][9] = 150;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][10] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][11] = 150;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][12] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][13] = 160;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][14] = 166;
        s_silk_LTP_gain_BITS_Q5_ptrs[1][15] = 160;


        s_silk_LTP_gain_BITS_Q5_ptrs[2] = malloc(sizeof(opus_uint8) * 32);
        s_silk_LTP_gain_BITS_Q5_ptrs[2][0] = 131; s_silk_LTP_gain_BITS_Q5_ptrs[2][1] = 128;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][2] = 134; s_silk_LTP_gain_BITS_Q5_ptrs[2][3] = 141;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][4] = 141; s_silk_LTP_gain_BITS_Q5_ptrs[2][5] = 141;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][6] = 145; s_silk_LTP_gain_BITS_Q5_ptrs[2][7] = 145;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][8] = 145; s_silk_LTP_gain_BITS_Q5_ptrs[2][9] = 150;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][10] = 155; s_silk_LTP_gain_BITS_Q5_ptrs[2][11] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][12] = 155; s_silk_LTP_gain_BITS_Q5_ptrs[2][13] = 155;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][14] = 160; s_silk_LTP_gain_BITS_Q5_ptrs[2][15] = 160;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][16] = 160; s_silk_LTP_gain_BITS_Q5_ptrs[2][17] = 160;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][18] = 166; s_silk_LTP_gain_BITS_Q5_ptrs[2][19] = 166;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][20] = 173; s_silk_LTP_gain_BITS_Q5_ptrs[2][21] = 173;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][22] = 182; s_silk_LTP_gain_BITS_Q5_ptrs[2][23] = 192;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][24] = 182; s_silk_LTP_gain_BITS_Q5_ptrs[2][25] = 192;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][26] = 192; s_silk_LTP_gain_BITS_Q5_ptrs[2][27] = 192;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][28] = 205; s_silk_LTP_gain_BITS_Q5_ptrs[2][29] = 192;
        s_silk_LTP_gain_BITS_Q5_ptrs[2][30] = 205; s_silk_LTP_gain_BITS_Q5_ptrs[2][31] = 224;
    }

    return (const unsigned char **) s_silk_LTP_gain_BITS_Q5_ptrs;
}


opus_int8 ** s_silk_LTP_vq_ptrs_Q7 = 0;
const opus_int8 **get_silk_LTP_vq_ptrs_Q7(void){
    if(s_silk_LTP_vq_ptrs_Q7 == NULL) {
        s_silk_LTP_vq_ptrs_Q7 = malloc(sizeof(opus_uint8 *) * 3);

        s_silk_LTP_vq_ptrs_Q7[0] = malloc(sizeof(opus_int8) * 40);
        s_silk_LTP_vq_ptrs_Q7[0][0] = 4; s_silk_LTP_vq_ptrs_Q7[0][1] = 6; s_silk_LTP_vq_ptrs_Q7[0][2] = 24; s_silk_LTP_vq_ptrs_Q7[0][3] = 7; s_silk_LTP_vq_ptrs_Q7[0][4] = 5;
        s_silk_LTP_vq_ptrs_Q7[0][5] = 0; s_silk_LTP_vq_ptrs_Q7[0][6] = 0; s_silk_LTP_vq_ptrs_Q7[0][7] = 2; s_silk_LTP_vq_ptrs_Q7[0][8] = 0; s_silk_LTP_vq_ptrs_Q7[0][9] = 0;
        s_silk_LTP_vq_ptrs_Q7[0][10] = 12; s_silk_LTP_vq_ptrs_Q7[0][11] = 28; s_silk_LTP_vq_ptrs_Q7[0][12] = 41; s_silk_LTP_vq_ptrs_Q7[0][13] = 13; s_silk_LTP_vq_ptrs_Q7[0][14] = -4;
        s_silk_LTP_vq_ptrs_Q7[0][15] = -9; s_silk_LTP_vq_ptrs_Q7[0][16] = 15; s_silk_LTP_vq_ptrs_Q7[0][17] = 42; s_silk_LTP_vq_ptrs_Q7[0][18] = 25; s_silk_LTP_vq_ptrs_Q7[0][19] = 14;
        s_silk_LTP_vq_ptrs_Q7[0][20] = 1; s_silk_LTP_vq_ptrs_Q7[0][21] = -2; s_silk_LTP_vq_ptrs_Q7[0][22] = 62; s_silk_LTP_vq_ptrs_Q7[0][23] = 41; s_silk_LTP_vq_ptrs_Q7[0][24] = -9;
        s_silk_LTP_vq_ptrs_Q7[0][25] = -10; s_silk_LTP_vq_ptrs_Q7[0][26] = 37; s_silk_LTP_vq_ptrs_Q7[0][27] = 65; s_silk_LTP_vq_ptrs_Q7[0][28] = -4; s_silk_LTP_vq_ptrs_Q7[0][29] = 3;
        s_silk_LTP_vq_ptrs_Q7[0][30] = -6; s_silk_LTP_vq_ptrs_Q7[0][31] = 4; s_silk_LTP_vq_ptrs_Q7[0][32] = 66; s_silk_LTP_vq_ptrs_Q7[0][33] = 7; s_silk_LTP_vq_ptrs_Q7[0][34] = -8;
        s_silk_LTP_vq_ptrs_Q7[0][35] = 16; s_silk_LTP_vq_ptrs_Q7[0][36] = 14; s_silk_LTP_vq_ptrs_Q7[0][37] = 38; s_silk_LTP_vq_ptrs_Q7[0][38] = -3; s_silk_LTP_vq_ptrs_Q7[0][39] = 33;

        s_silk_LTP_vq_ptrs_Q7[1] = malloc(sizeof(opus_int8) * 80);
        s_silk_LTP_vq_ptrs_Q7[1][0] = 13; s_silk_LTP_vq_ptrs_Q7[1][1] = 22; s_silk_LTP_vq_ptrs_Q7[1][2] = 39; s_silk_LTP_vq_ptrs_Q7[1][3] = 23; s_silk_LTP_vq_ptrs_Q7[1][4] = 12;
        s_silk_LTP_vq_ptrs_Q7[1][5] = -1; s_silk_LTP_vq_ptrs_Q7[1][6] = 36; s_silk_LTP_vq_ptrs_Q7[1][7] = 64; s_silk_LTP_vq_ptrs_Q7[1][8] = 27; s_silk_LTP_vq_ptrs_Q7[1][9] = -6;
        s_silk_LTP_vq_ptrs_Q7[1][10] = -7; s_silk_LTP_vq_ptrs_Q7[1][11] = 10; s_silk_LTP_vq_ptrs_Q7[1][12] = 55; s_silk_LTP_vq_ptrs_Q7[1][13] = 43; s_silk_LTP_vq_ptrs_Q7[1][14] = 17;
        s_silk_LTP_vq_ptrs_Q7[1][15] = 1; s_silk_LTP_vq_ptrs_Q7[1][16] = 1; s_silk_LTP_vq_ptrs_Q7[1][17] = 8; s_silk_LTP_vq_ptrs_Q7[1][18] = 1; s_silk_LTP_vq_ptrs_Q7[1][19] = 1;
        s_silk_LTP_vq_ptrs_Q7[1][20] = 6; s_silk_LTP_vq_ptrs_Q7[1][21] = -11; s_silk_LTP_vq_ptrs_Q7[1][22] = 74; s_silk_LTP_vq_ptrs_Q7[1][23] = 53; s_silk_LTP_vq_ptrs_Q7[1][24] = -9;
        s_silk_LTP_vq_ptrs_Q7[1][25] = -12; s_silk_LTP_vq_ptrs_Q7[1][26] = 55; s_silk_LTP_vq_ptrs_Q7[1][27] = 76; s_silk_LTP_vq_ptrs_Q7[1][28] = -12; s_silk_LTP_vq_ptrs_Q7[1][29] = 8;
        s_silk_LTP_vq_ptrs_Q7[1][30] = -3; s_silk_LTP_vq_ptrs_Q7[1][31] = 3; s_silk_LTP_vq_ptrs_Q7[1][32] = 93; s_silk_LTP_vq_ptrs_Q7[1][33] = 27; s_silk_LTP_vq_ptrs_Q7[1][34] = -4;
        s_silk_LTP_vq_ptrs_Q7[1][35] = 26; s_silk_LTP_vq_ptrs_Q7[1][36] = 39; s_silk_LTP_vq_ptrs_Q7[1][37] = 59; s_silk_LTP_vq_ptrs_Q7[1][38] = 3; s_silk_LTP_vq_ptrs_Q7[1][39] = -8;
        s_silk_LTP_vq_ptrs_Q7[1][40] = 2; s_silk_LTP_vq_ptrs_Q7[1][41] = 0; s_silk_LTP_vq_ptrs_Q7[1][42] = 77; s_silk_LTP_vq_ptrs_Q7[1][43] = 11; s_silk_LTP_vq_ptrs_Q7[1][44] = 9;
        s_silk_LTP_vq_ptrs_Q7[1][45] = -8; s_silk_LTP_vq_ptrs_Q7[1][46] = 22; s_silk_LTP_vq_ptrs_Q7[1][47] = 44; s_silk_LTP_vq_ptrs_Q7[1][48] = -6; s_silk_LTP_vq_ptrs_Q7[1][49] = 7;
        s_silk_LTP_vq_ptrs_Q7[1][50] = 40; s_silk_LTP_vq_ptrs_Q7[1][51] = 9; s_silk_LTP_vq_ptrs_Q7[1][52] = 26; s_silk_LTP_vq_ptrs_Q7[1][53] = 3; s_silk_LTP_vq_ptrs_Q7[1][54] = 9;
        s_silk_LTP_vq_ptrs_Q7[1][55] = -7; s_silk_LTP_vq_ptrs_Q7[1][56] = 20; s_silk_LTP_vq_ptrs_Q7[1][57] = 101; s_silk_LTP_vq_ptrs_Q7[1][58] = -7; s_silk_LTP_vq_ptrs_Q7[1][59] = 4;
        s_silk_LTP_vq_ptrs_Q7[1][60] = 3; s_silk_LTP_vq_ptrs_Q7[1][61] = -8; s_silk_LTP_vq_ptrs_Q7[1][62] = 42; s_silk_LTP_vq_ptrs_Q7[1][63] = 26; s_silk_LTP_vq_ptrs_Q7[1][64] = 0;
        s_silk_LTP_vq_ptrs_Q7[1][65] = -15; s_silk_LTP_vq_ptrs_Q7[1][66] = 33; s_silk_LTP_vq_ptrs_Q7[1][67] = 68; s_silk_LTP_vq_ptrs_Q7[1][68] = 2; s_silk_LTP_vq_ptrs_Q7[1][69] = 23;
        s_silk_LTP_vq_ptrs_Q7[1][70] = -2; s_silk_LTP_vq_ptrs_Q7[1][71] = 55; s_silk_LTP_vq_ptrs_Q7[1][72] = 46; s_silk_LTP_vq_ptrs_Q7[1][73] = -2; s_silk_LTP_vq_ptrs_Q7[1][74] = 15;
        s_silk_LTP_vq_ptrs_Q7[1][75] = 3; s_silk_LTP_vq_ptrs_Q7[1][76] = -1; s_silk_LTP_vq_ptrs_Q7[1][77] = 21; s_silk_LTP_vq_ptrs_Q7[1][78] = 16; s_silk_LTP_vq_ptrs_Q7[1][79] = 41;

        s_silk_LTP_vq_ptrs_Q7[2] = malloc(sizeof(opus_int8) * 160);
        s_silk_LTP_vq_ptrs_Q7[2][0] = -6; s_silk_LTP_vq_ptrs_Q7[2][1] = 27; s_silk_LTP_vq_ptrs_Q7[2][2] = 61; s_silk_LTP_vq_ptrs_Q7[2][3] = 39; s_silk_LTP_vq_ptrs_Q7[2][4] = 5;
        s_silk_LTP_vq_ptrs_Q7[2][5] = -11; s_silk_LTP_vq_ptrs_Q7[2][6] = 42; s_silk_LTP_vq_ptrs_Q7[2][7] = 88; s_silk_LTP_vq_ptrs_Q7[2][8] = 4; s_silk_LTP_vq_ptrs_Q7[2][9] = 1;
        s_silk_LTP_vq_ptrs_Q7[2][10] = -2; s_silk_LTP_vq_ptrs_Q7[2][11] = 60; s_silk_LTP_vq_ptrs_Q7[2][12] = 65; s_silk_LTP_vq_ptrs_Q7[2][13] = 6; s_silk_LTP_vq_ptrs_Q7[2][14] = -4;
        s_silk_LTP_vq_ptrs_Q7[2][15] = -1; s_silk_LTP_vq_ptrs_Q7[2][16] = -5; s_silk_LTP_vq_ptrs_Q7[2][17] = 73; s_silk_LTP_vq_ptrs_Q7[2][18] = 56; s_silk_LTP_vq_ptrs_Q7[2][19] = 1;
        s_silk_LTP_vq_ptrs_Q7[2][20] = -9; s_silk_LTP_vq_ptrs_Q7[2][21] = 19; s_silk_LTP_vq_ptrs_Q7[2][22] = 94; s_silk_LTP_vq_ptrs_Q7[2][23] = 29; s_silk_LTP_vq_ptrs_Q7[2][24] = -9;
        s_silk_LTP_vq_ptrs_Q7[2][25] = 0; s_silk_LTP_vq_ptrs_Q7[2][26] = 12; s_silk_LTP_vq_ptrs_Q7[2][27] = 99; s_silk_LTP_vq_ptrs_Q7[2][28] = 6; s_silk_LTP_vq_ptrs_Q7[2][29] = 4;
        s_silk_LTP_vq_ptrs_Q7[2][30] = 8; s_silk_LTP_vq_ptrs_Q7[2][31] = -19; s_silk_LTP_vq_ptrs_Q7[2][32] = 102; s_silk_LTP_vq_ptrs_Q7[2][33] = 46; s_silk_LTP_vq_ptrs_Q7[2][34] = -13;
        s_silk_LTP_vq_ptrs_Q7[2][35] = 3; s_silk_LTP_vq_ptrs_Q7[2][36] = 2; s_silk_LTP_vq_ptrs_Q7[2][37] = 13; s_silk_LTP_vq_ptrs_Q7[2][38] = 3; s_silk_LTP_vq_ptrs_Q7[2][39] = 2;
        s_silk_LTP_vq_ptrs_Q7[2][40] = 9; s_silk_LTP_vq_ptrs_Q7[2][41] = -21; s_silk_LTP_vq_ptrs_Q7[2][42] = 84; s_silk_LTP_vq_ptrs_Q7[2][43] = 72; s_silk_LTP_vq_ptrs_Q7[2][44] = -18;
        s_silk_LTP_vq_ptrs_Q7[2][45] = -11; s_silk_LTP_vq_ptrs_Q7[2][46] = 46; s_silk_LTP_vq_ptrs_Q7[2][47] = 104; s_silk_LTP_vq_ptrs_Q7[2][48] = -22; s_silk_LTP_vq_ptrs_Q7[2][49] = 8;
        s_silk_LTP_vq_ptrs_Q7[2][50] = 18; s_silk_LTP_vq_ptrs_Q7[2][51] = 38; s_silk_LTP_vq_ptrs_Q7[2][52] = 48; s_silk_LTP_vq_ptrs_Q7[2][53] = 23; s_silk_LTP_vq_ptrs_Q7[2][54] = 0;
        s_silk_LTP_vq_ptrs_Q7[2][55] = -16; s_silk_LTP_vq_ptrs_Q7[2][56] = 70; s_silk_LTP_vq_ptrs_Q7[2][57] = 83; s_silk_LTP_vq_ptrs_Q7[2][58] = -21; s_silk_LTP_vq_ptrs_Q7[2][59] = 11;
        s_silk_LTP_vq_ptrs_Q7[2][60] = 5; s_silk_LTP_vq_ptrs_Q7[2][61] = -11; s_silk_LTP_vq_ptrs_Q7[2][62] = 117; s_silk_LTP_vq_ptrs_Q7[2][63] = 22; s_silk_LTP_vq_ptrs_Q7[2][64] = -8;
        s_silk_LTP_vq_ptrs_Q7[2][65] = -6; s_silk_LTP_vq_ptrs_Q7[2][66] = 23; s_silk_LTP_vq_ptrs_Q7[2][67] = 117; s_silk_LTP_vq_ptrs_Q7[2][68] = -12; s_silk_LTP_vq_ptrs_Q7[2][69] = 3;
        s_silk_LTP_vq_ptrs_Q7[2][70] = 3; s_silk_LTP_vq_ptrs_Q7[2][71] = -8; s_silk_LTP_vq_ptrs_Q7[2][72] = 95; s_silk_LTP_vq_ptrs_Q7[2][73] = 28; s_silk_LTP_vq_ptrs_Q7[2][74] = 4;
        s_silk_LTP_vq_ptrs_Q7[2][75] = -10; s_silk_LTP_vq_ptrs_Q7[2][76] = 15; s_silk_LTP_vq_ptrs_Q7[2][77] = 77; s_silk_LTP_vq_ptrs_Q7[2][78] = 60; s_silk_LTP_vq_ptrs_Q7[2][79] = -15;
        s_silk_LTP_vq_ptrs_Q7[2][80] = -1; s_silk_LTP_vq_ptrs_Q7[2][81] = 4; s_silk_LTP_vq_ptrs_Q7[2][82] = 124; s_silk_LTP_vq_ptrs_Q7[2][83] = 2; s_silk_LTP_vq_ptrs_Q7[2][84] = -4;
        s_silk_LTP_vq_ptrs_Q7[2][85] = 3; s_silk_LTP_vq_ptrs_Q7[2][86] = 38; s_silk_LTP_vq_ptrs_Q7[2][87] = 84; s_silk_LTP_vq_ptrs_Q7[2][88] = 24; s_silk_LTP_vq_ptrs_Q7[2][89] = -25;
        s_silk_LTP_vq_ptrs_Q7[2][90] = 2; s_silk_LTP_vq_ptrs_Q7[2][91] = 13; s_silk_LTP_vq_ptrs_Q7[2][92] = 42; s_silk_LTP_vq_ptrs_Q7[2][93] = 13; s_silk_LTP_vq_ptrs_Q7[2][94] = 31;
        s_silk_LTP_vq_ptrs_Q7[2][95] = 21; s_silk_LTP_vq_ptrs_Q7[2][96] = -4; s_silk_LTP_vq_ptrs_Q7[2][97] = 56; s_silk_LTP_vq_ptrs_Q7[2][98] = 46; s_silk_LTP_vq_ptrs_Q7[2][99] = -1;
        s_silk_LTP_vq_ptrs_Q7[2][100] = -1; s_silk_LTP_vq_ptrs_Q7[2][101] = 35; s_silk_LTP_vq_ptrs_Q7[2][102] = 79; s_silk_LTP_vq_ptrs_Q7[2][103] = -13; s_silk_LTP_vq_ptrs_Q7[2][104] = 19;
        s_silk_LTP_vq_ptrs_Q7[2][105] = -7; s_silk_LTP_vq_ptrs_Q7[2][106] = 65; s_silk_LTP_vq_ptrs_Q7[2][107] = 88; s_silk_LTP_vq_ptrs_Q7[2][108] = -9; s_silk_LTP_vq_ptrs_Q7[2][109] = -14;
        s_silk_LTP_vq_ptrs_Q7[2][110] = 20; s_silk_LTP_vq_ptrs_Q7[2][111] = 4; s_silk_LTP_vq_ptrs_Q7[2][112] = 81; s_silk_LTP_vq_ptrs_Q7[2][113] = 49; s_silk_LTP_vq_ptrs_Q7[2][114] = -29;
        s_silk_LTP_vq_ptrs_Q7[2][115] = 20; s_silk_LTP_vq_ptrs_Q7[2][116] = 0; s_silk_LTP_vq_ptrs_Q7[2][117] = 75; s_silk_LTP_vq_ptrs_Q7[2][118] = 3; s_silk_LTP_vq_ptrs_Q7[2][119] = -17;
        s_silk_LTP_vq_ptrs_Q7[2][120] = 5; s_silk_LTP_vq_ptrs_Q7[2][121] = -9; s_silk_LTP_vq_ptrs_Q7[2][122] = 44; s_silk_LTP_vq_ptrs_Q7[2][123] = 92; s_silk_LTP_vq_ptrs_Q7[2][124] = -8;
        s_silk_LTP_vq_ptrs_Q7[2][125] = 1; s_silk_LTP_vq_ptrs_Q7[2][126] = -3; s_silk_LTP_vq_ptrs_Q7[2][127] = 22; s_silk_LTP_vq_ptrs_Q7[2][128] = 69; s_silk_LTP_vq_ptrs_Q7[2][129] = 31;
        s_silk_LTP_vq_ptrs_Q7[2][130] = -6; s_silk_LTP_vq_ptrs_Q7[2][131] = 95; s_silk_LTP_vq_ptrs_Q7[2][132] = 41; s_silk_LTP_vq_ptrs_Q7[2][133] = -12; s_silk_LTP_vq_ptrs_Q7[2][134] = 5;
        s_silk_LTP_vq_ptrs_Q7[2][135] = 39; s_silk_LTP_vq_ptrs_Q7[2][136] = 67; s_silk_LTP_vq_ptrs_Q7[2][137] = 16; s_silk_LTP_vq_ptrs_Q7[2][138] = -4; s_silk_LTP_vq_ptrs_Q7[2][139] = 1;
        s_silk_LTP_vq_ptrs_Q7[2][140] = 0; s_silk_LTP_vq_ptrs_Q7[2][141] = -6; s_silk_LTP_vq_ptrs_Q7[2][142] = 120; s_silk_LTP_vq_ptrs_Q7[2][143] = 55; s_silk_LTP_vq_ptrs_Q7[2][144] = -36;
        s_silk_LTP_vq_ptrs_Q7[2][145] = -13; s_silk_LTP_vq_ptrs_Q7[2][146] = 44; s_silk_LTP_vq_ptrs_Q7[2][147] = 122; s_silk_LTP_vq_ptrs_Q7[2][148] = 4; s_silk_LTP_vq_ptrs_Q7[2][149] = -24;
        s_silk_LTP_vq_ptrs_Q7[2][150] = 81; s_silk_LTP_vq_ptrs_Q7[2][151] = 5; s_silk_LTP_vq_ptrs_Q7[2][152] = 11; s_silk_LTP_vq_ptrs_Q7[2][153] = 3; s_silk_LTP_vq_ptrs_Q7[2][154] = 7;
        s_silk_LTP_vq_ptrs_Q7[2][155] = 2; s_silk_LTP_vq_ptrs_Q7[2][156] = 0; s_silk_LTP_vq_ptrs_Q7[2][157] = 9; s_silk_LTP_vq_ptrs_Q7[2][158] = 10; s_silk_LTP_vq_ptrs_Q7[2][159] = 88;


    }

    return (const signed char **) s_silk_LTP_vq_ptrs_Q7;
}

/* Maximum frequency-dependent response of the pitch taps above,
   computed as max(abs(freqz(taps))) */
opus_uint8 ** s_silk_LTP_vq_gain_ptrs_Q7 = 0;
const opus_uint8 **get_silk_LTP_vq_gain_ptrs_Q7(void){
    if(s_silk_LTP_vq_gain_ptrs_Q7 == NULL) {
        s_silk_LTP_vq_gain_ptrs_Q7 = malloc(sizeof(opus_uint8 *) * 3);

        s_silk_LTP_vq_gain_ptrs_Q7[0] = malloc(sizeof(opus_uint8) * 8);
        s_silk_LTP_vq_gain_ptrs_Q7[0][0] = 46; s_silk_LTP_vq_gain_ptrs_Q7[0][1] = 2;
        s_silk_LTP_vq_gain_ptrs_Q7[0][2] = 90; s_silk_LTP_vq_gain_ptrs_Q7[0][3] = 87;
        s_silk_LTP_vq_gain_ptrs_Q7[0][4] = 93; s_silk_LTP_vq_gain_ptrs_Q7[0][5] = 91;
        s_silk_LTP_vq_gain_ptrs_Q7[0][6] = 82; s_silk_LTP_vq_gain_ptrs_Q7[0][7] = 98;

        s_silk_LTP_vq_gain_ptrs_Q7[1] = malloc(sizeof(opus_uint8) * 16);
        s_silk_LTP_vq_gain_ptrs_Q7[1][0] = 109; s_silk_LTP_vq_gain_ptrs_Q7[1][1] = 120;
        s_silk_LTP_vq_gain_ptrs_Q7[1][2] = 118; s_silk_LTP_vq_gain_ptrs_Q7[1][3] = 12;
        s_silk_LTP_vq_gain_ptrs_Q7[1][4] = 113; s_silk_LTP_vq_gain_ptrs_Q7[1][5] = 115;
        s_silk_LTP_vq_gain_ptrs_Q7[1][6] = 117; s_silk_LTP_vq_gain_ptrs_Q7[1][7] = 119;
        s_silk_LTP_vq_gain_ptrs_Q7[1][8] = 99; s_silk_LTP_vq_gain_ptrs_Q7[1][9] = 59;
        s_silk_LTP_vq_gain_ptrs_Q7[1][10] = 87; s_silk_LTP_vq_gain_ptrs_Q7[1][11] = 111;
        s_silk_LTP_vq_gain_ptrs_Q7[1][12] = 63; s_silk_LTP_vq_gain_ptrs_Q7[1][13] = 111;
        s_silk_LTP_vq_gain_ptrs_Q7[1][14] = 112; s_silk_LTP_vq_gain_ptrs_Q7[1][15] = 80;

        s_silk_LTP_vq_gain_ptrs_Q7[2] = malloc(sizeof(opus_uint8) * 32);
        s_silk_LTP_vq_gain_ptrs_Q7[2][0] = 126; s_silk_LTP_vq_gain_ptrs_Q7[2][1] = 124;
        s_silk_LTP_vq_gain_ptrs_Q7[2][2] = 125; s_silk_LTP_vq_gain_ptrs_Q7[2][3] = 124;
        s_silk_LTP_vq_gain_ptrs_Q7[2][4] = 129; s_silk_LTP_vq_gain_ptrs_Q7[2][5] = 121;
        s_silk_LTP_vq_gain_ptrs_Q7[2][6] = 126; s_silk_LTP_vq_gain_ptrs_Q7[2][7] = 23;
        s_silk_LTP_vq_gain_ptrs_Q7[2][8] = 132; s_silk_LTP_vq_gain_ptrs_Q7[2][9] = 127;
        s_silk_LTP_vq_gain_ptrs_Q7[2][10] = 127; s_silk_LTP_vq_gain_ptrs_Q7[2][11] = 127;
        s_silk_LTP_vq_gain_ptrs_Q7[2][12] = 126; s_silk_LTP_vq_gain_ptrs_Q7[2][13] = 127;
        s_silk_LTP_vq_gain_ptrs_Q7[2][14] = 122; s_silk_LTP_vq_gain_ptrs_Q7[2][15] = 133;
        s_silk_LTP_vq_gain_ptrs_Q7[2][16] = 130; s_silk_LTP_vq_gain_ptrs_Q7[2][17] = 134;
        s_silk_LTP_vq_gain_ptrs_Q7[2][18] = 101; s_silk_LTP_vq_gain_ptrs_Q7[2][19] = 118;
        s_silk_LTP_vq_gain_ptrs_Q7[2][20] = 119; s_silk_LTP_vq_gain_ptrs_Q7[2][21] = 145;
        s_silk_LTP_vq_gain_ptrs_Q7[2][22] = 126; s_silk_LTP_vq_gain_ptrs_Q7[2][23] = 86;
        s_silk_LTP_vq_gain_ptrs_Q7[2][24] = 124; s_silk_LTP_vq_gain_ptrs_Q7[2][25] = 120;
        s_silk_LTP_vq_gain_ptrs_Q7[2][26] = 123; s_silk_LTP_vq_gain_ptrs_Q7[2][27] = 119;
        s_silk_LTP_vq_gain_ptrs_Q7[2][28] = 170; s_silk_LTP_vq_gain_ptrs_Q7[2][29] = 173;
        s_silk_LTP_vq_gain_ptrs_Q7[2][30] = 107; s_silk_LTP_vq_gain_ptrs_Q7[2][31] = 109;

    }

    return (const unsigned char **) s_silk_LTP_vq_gain_ptrs_Q7;
}

