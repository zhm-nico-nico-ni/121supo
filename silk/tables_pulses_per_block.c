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


opus_uint8 **s_silk_pulses_per_block_iCDF = 0;
const opus_uint8 **get_silk_pulses_per_block_iCDF(void){
    if(s_silk_pulses_per_block_iCDF == 0){
        s_silk_pulses_per_block_iCDF = opus_alloc(sizeof(opus_uint8 *) * 10);

        s_silk_pulses_per_block_iCDF[0] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[0][0] = 125;
        s_silk_pulses_per_block_iCDF[0][1] = 51;
        s_silk_pulses_per_block_iCDF[0][2] = 26;
        s_silk_pulses_per_block_iCDF[0][3] = 18;
        s_silk_pulses_per_block_iCDF[0][4] = 15;
        s_silk_pulses_per_block_iCDF[0][5] = 12;
        s_silk_pulses_per_block_iCDF[0][6] = 11;
        s_silk_pulses_per_block_iCDF[0][7] = 10;
        s_silk_pulses_per_block_iCDF[0][8] = 9;
        s_silk_pulses_per_block_iCDF[0][9] = 8;
        s_silk_pulses_per_block_iCDF[0][10] = 7;
        s_silk_pulses_per_block_iCDF[0][11] = 6;
        s_silk_pulses_per_block_iCDF[0][12] = 5;
        s_silk_pulses_per_block_iCDF[0][13] = 4;
        s_silk_pulses_per_block_iCDF[0][14] = 3;
        s_silk_pulses_per_block_iCDF[0][15] = 2;
        s_silk_pulses_per_block_iCDF[0][16] = 1;
        s_silk_pulses_per_block_iCDF[0][17] = 0;
        s_silk_pulses_per_block_iCDF[1] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[1][0] = 198;
        s_silk_pulses_per_block_iCDF[1][1] = 105;
        s_silk_pulses_per_block_iCDF[1][2] = 45;
        s_silk_pulses_per_block_iCDF[1][3] = 22;
        s_silk_pulses_per_block_iCDF[1][4] = 15;
        s_silk_pulses_per_block_iCDF[1][5] = 12;
        s_silk_pulses_per_block_iCDF[1][6] = 11;
        s_silk_pulses_per_block_iCDF[1][7] = 10;
        s_silk_pulses_per_block_iCDF[1][8] = 9;
        s_silk_pulses_per_block_iCDF[1][9] = 8;
        s_silk_pulses_per_block_iCDF[1][10] = 7;
        s_silk_pulses_per_block_iCDF[1][11] = 6;
        s_silk_pulses_per_block_iCDF[1][12] = 5;
        s_silk_pulses_per_block_iCDF[1][13] = 4;
        s_silk_pulses_per_block_iCDF[1][14] = 3;
        s_silk_pulses_per_block_iCDF[1][15] = 2;
        s_silk_pulses_per_block_iCDF[1][16] = 1;
        s_silk_pulses_per_block_iCDF[1][17] = 0;
        s_silk_pulses_per_block_iCDF[2] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[2][0] = 213;
        s_silk_pulses_per_block_iCDF[2][1] = 162;
        s_silk_pulses_per_block_iCDF[2][2] = 116;
        s_silk_pulses_per_block_iCDF[2][3] = 83;
        s_silk_pulses_per_block_iCDF[2][4] = 59;
        s_silk_pulses_per_block_iCDF[2][5] = 43;
        s_silk_pulses_per_block_iCDF[2][6] = 32;
        s_silk_pulses_per_block_iCDF[2][7] = 24;
        s_silk_pulses_per_block_iCDF[2][8] = 18;
        s_silk_pulses_per_block_iCDF[2][9] = 15;
        s_silk_pulses_per_block_iCDF[2][10] = 12;
        s_silk_pulses_per_block_iCDF[2][11] = 9;
        s_silk_pulses_per_block_iCDF[2][12] = 7;
        s_silk_pulses_per_block_iCDF[2][13] = 6;
        s_silk_pulses_per_block_iCDF[2][14] = 5;
        s_silk_pulses_per_block_iCDF[2][15] = 3;
        s_silk_pulses_per_block_iCDF[2][16] = 2;
        s_silk_pulses_per_block_iCDF[2][17] = 0;
        s_silk_pulses_per_block_iCDF[3] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[3][0] = 239;
        s_silk_pulses_per_block_iCDF[3][1] = 187;
        s_silk_pulses_per_block_iCDF[3][2] = 116;
        s_silk_pulses_per_block_iCDF[3][3] = 59;
        s_silk_pulses_per_block_iCDF[3][4] = 28;
        s_silk_pulses_per_block_iCDF[3][5] = 16;
        s_silk_pulses_per_block_iCDF[3][6] = 11;
        s_silk_pulses_per_block_iCDF[3][7] = 10;
        s_silk_pulses_per_block_iCDF[3][8] = 9;
        s_silk_pulses_per_block_iCDF[3][9] = 8;
        s_silk_pulses_per_block_iCDF[3][10] = 7;
        s_silk_pulses_per_block_iCDF[3][11] = 6;
        s_silk_pulses_per_block_iCDF[3][12] = 5;
        s_silk_pulses_per_block_iCDF[3][13] = 4;
        s_silk_pulses_per_block_iCDF[3][14] = 3;
        s_silk_pulses_per_block_iCDF[3][15] = 2;
        s_silk_pulses_per_block_iCDF[3][16] = 1;
        s_silk_pulses_per_block_iCDF[3][17] = 0;
        s_silk_pulses_per_block_iCDF[4] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[4][0] = 250;
        s_silk_pulses_per_block_iCDF[4][1] = 229;
        s_silk_pulses_per_block_iCDF[4][2] = 188;
        s_silk_pulses_per_block_iCDF[4][3] = 135;
        s_silk_pulses_per_block_iCDF[4][4] = 86;
        s_silk_pulses_per_block_iCDF[4][5] = 51;
        s_silk_pulses_per_block_iCDF[4][6] = 30;
        s_silk_pulses_per_block_iCDF[4][7] = 19;
        s_silk_pulses_per_block_iCDF[4][8] = 13;
        s_silk_pulses_per_block_iCDF[4][9] = 10;
        s_silk_pulses_per_block_iCDF[4][10] = 8;
        s_silk_pulses_per_block_iCDF[4][11] = 6;
        s_silk_pulses_per_block_iCDF[4][12] = 5;
        s_silk_pulses_per_block_iCDF[4][13] = 4;
        s_silk_pulses_per_block_iCDF[4][14] = 3;
        s_silk_pulses_per_block_iCDF[4][15] = 2;
        s_silk_pulses_per_block_iCDF[4][16] = 1;
        s_silk_pulses_per_block_iCDF[4][17] = 0;
        s_silk_pulses_per_block_iCDF[5] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[5][0] = 249;
        s_silk_pulses_per_block_iCDF[5][1] = 235;
        s_silk_pulses_per_block_iCDF[5][2] = 213;
        s_silk_pulses_per_block_iCDF[5][3] = 185;
        s_silk_pulses_per_block_iCDF[5][4] = 156;
        s_silk_pulses_per_block_iCDF[5][5] = 128;
        s_silk_pulses_per_block_iCDF[5][6] = 103;
        s_silk_pulses_per_block_iCDF[5][7] = 83;
        s_silk_pulses_per_block_iCDF[5][8] = 66;
        s_silk_pulses_per_block_iCDF[5][9] = 53;
        s_silk_pulses_per_block_iCDF[5][10] = 42;
        s_silk_pulses_per_block_iCDF[5][11] = 33;
        s_silk_pulses_per_block_iCDF[5][12] = 26;
        s_silk_pulses_per_block_iCDF[5][13] = 21;
        s_silk_pulses_per_block_iCDF[5][14] = 17;
        s_silk_pulses_per_block_iCDF[5][15] = 13;
        s_silk_pulses_per_block_iCDF[5][16] = 10;
        s_silk_pulses_per_block_iCDF[5][17] = 0;
        s_silk_pulses_per_block_iCDF[6] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[6][0] = 254;
        s_silk_pulses_per_block_iCDF[6][1] = 249;
        s_silk_pulses_per_block_iCDF[6][2] = 235;
        s_silk_pulses_per_block_iCDF[6][3] = 206;
        s_silk_pulses_per_block_iCDF[6][4] = 164;
        s_silk_pulses_per_block_iCDF[6][5] = 118;
        s_silk_pulses_per_block_iCDF[6][6] = 77;
        s_silk_pulses_per_block_iCDF[6][7] = 46;
        s_silk_pulses_per_block_iCDF[6][8] = 27;
        s_silk_pulses_per_block_iCDF[6][9] = 16;
        s_silk_pulses_per_block_iCDF[6][10] = 10;
        s_silk_pulses_per_block_iCDF[6][11] = 7;
        s_silk_pulses_per_block_iCDF[6][12] = 5;
        s_silk_pulses_per_block_iCDF[6][13] = 4;
        s_silk_pulses_per_block_iCDF[6][14] = 3;
        s_silk_pulses_per_block_iCDF[6][15] = 2;
        s_silk_pulses_per_block_iCDF[6][16] = 1;
        s_silk_pulses_per_block_iCDF[6][17] = 0;
        s_silk_pulses_per_block_iCDF[7] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[7][0] = 255;
        s_silk_pulses_per_block_iCDF[7][1] = 253;
        s_silk_pulses_per_block_iCDF[7][2] = 249;
        s_silk_pulses_per_block_iCDF[7][3] = 239;
        s_silk_pulses_per_block_iCDF[7][4] = 220;
        s_silk_pulses_per_block_iCDF[7][5] = 191;
        s_silk_pulses_per_block_iCDF[7][6] = 156;
        s_silk_pulses_per_block_iCDF[7][7] = 119;
        s_silk_pulses_per_block_iCDF[7][8] = 85;
        s_silk_pulses_per_block_iCDF[7][9] = 57;
        s_silk_pulses_per_block_iCDF[7][10] = 37;
        s_silk_pulses_per_block_iCDF[7][11] = 23;
        s_silk_pulses_per_block_iCDF[7][12] = 15;
        s_silk_pulses_per_block_iCDF[7][13] = 10;
        s_silk_pulses_per_block_iCDF[7][14] = 6;
        s_silk_pulses_per_block_iCDF[7][15] = 4;
        s_silk_pulses_per_block_iCDF[7][16] = 2;
        s_silk_pulses_per_block_iCDF[7][17] = 0;
        s_silk_pulses_per_block_iCDF[8] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[8][0] = 255;
        s_silk_pulses_per_block_iCDF[8][1] = 253;
        s_silk_pulses_per_block_iCDF[8][2] = 251;
        s_silk_pulses_per_block_iCDF[8][3] = 246;
        s_silk_pulses_per_block_iCDF[8][4] = 237;
        s_silk_pulses_per_block_iCDF[8][5] = 223;
        s_silk_pulses_per_block_iCDF[8][6] = 203;
        s_silk_pulses_per_block_iCDF[8][7] = 179;
        s_silk_pulses_per_block_iCDF[8][8] = 152;
        s_silk_pulses_per_block_iCDF[8][9] = 124;
        s_silk_pulses_per_block_iCDF[8][10] = 98;
        s_silk_pulses_per_block_iCDF[8][11] = 75;
        s_silk_pulses_per_block_iCDF[8][12] = 55;
        s_silk_pulses_per_block_iCDF[8][13] = 40;
        s_silk_pulses_per_block_iCDF[8][14] = 29;
        s_silk_pulses_per_block_iCDF[8][15] = 21;
        s_silk_pulses_per_block_iCDF[8][16] = 15;
        s_silk_pulses_per_block_iCDF[8][17] = 0;
        s_silk_pulses_per_block_iCDF[9] = opus_alloc(18);
        s_silk_pulses_per_block_iCDF[9][0] = 255;
        s_silk_pulses_per_block_iCDF[9][1] = 254;
        s_silk_pulses_per_block_iCDF[9][2] = 253;
        s_silk_pulses_per_block_iCDF[9][3] = 247;
        s_silk_pulses_per_block_iCDF[9][4] = 220;
        s_silk_pulses_per_block_iCDF[9][5] = 162;
        s_silk_pulses_per_block_iCDF[9][6] = 106;
        s_silk_pulses_per_block_iCDF[9][7] = 67;
        s_silk_pulses_per_block_iCDF[9][8] = 42;
        s_silk_pulses_per_block_iCDF[9][9] = 28;
        s_silk_pulses_per_block_iCDF[9][10] = 18;
        s_silk_pulses_per_block_iCDF[9][11] = 12;
        s_silk_pulses_per_block_iCDF[9][12] = 9;
        s_silk_pulses_per_block_iCDF[9][13] = 6;
        s_silk_pulses_per_block_iCDF[9][14] = 4;
        s_silk_pulses_per_block_iCDF[9][15] = 3;
        s_silk_pulses_per_block_iCDF[9][16] = 2;
        s_silk_pulses_per_block_iCDF[9][17] = 0;
    }

    return (const unsigned char **) s_silk_pulses_per_block_iCDF;
}


opus_uint8 **s_silk_pulses_per_block_BITS_Q5;
const opus_uint8 **get_silk_pulses_per_block_BITS_Q5(void){
    if(s_silk_pulses_per_block_BITS_Q5 == 0){
        s_silk_pulses_per_block_BITS_Q5 = opus_alloc(sizeof(opus_uint8 *) * 9);

        s_silk_pulses_per_block_BITS_Q5[0] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[0][0] = 31;
        s_silk_pulses_per_block_BITS_Q5[0][1] = 57;
        s_silk_pulses_per_block_BITS_Q5[0][2] = 107;
        s_silk_pulses_per_block_BITS_Q5[0][3] = 160;
        s_silk_pulses_per_block_BITS_Q5[0][4] = 205;
        s_silk_pulses_per_block_BITS_Q5[0][5] = 205;
        s_silk_pulses_per_block_BITS_Q5[0][6] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][7] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][8] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][9] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][10] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][11] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][12] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][15] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[0][17] = 255;
        s_silk_pulses_per_block_BITS_Q5[1] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[1][0] = 69;
        s_silk_pulses_per_block_BITS_Q5[1][1] = 47;
        s_silk_pulses_per_block_BITS_Q5[1][2] = 67;
        s_silk_pulses_per_block_BITS_Q5[1][3] = 111;
        s_silk_pulses_per_block_BITS_Q5[1][4] = 166;
        s_silk_pulses_per_block_BITS_Q5[1][5] = 205;
        s_silk_pulses_per_block_BITS_Q5[1][6] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][7] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][8] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][9] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][10] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][11] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][12] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][15] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[1][17] = 255;
        s_silk_pulses_per_block_BITS_Q5[2] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[2][0] = 82;
        s_silk_pulses_per_block_BITS_Q5[2][1] = 74;
        s_silk_pulses_per_block_BITS_Q5[2][2] = 79;
        s_silk_pulses_per_block_BITS_Q5[2][3] = 95;
        s_silk_pulses_per_block_BITS_Q5[2][4] = 109;
        s_silk_pulses_per_block_BITS_Q5[2][5] = 128;
        s_silk_pulses_per_block_BITS_Q5[2][6] = 145;
        s_silk_pulses_per_block_BITS_Q5[2][7] = 160;
        s_silk_pulses_per_block_BITS_Q5[2][8] = 173;
        s_silk_pulses_per_block_BITS_Q5[2][9] = 205;
        s_silk_pulses_per_block_BITS_Q5[2][10] = 205;
        s_silk_pulses_per_block_BITS_Q5[2][11] = 205;
        s_silk_pulses_per_block_BITS_Q5[2][12] = 224;
        s_silk_pulses_per_block_BITS_Q5[2][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[2][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[2][15] = 224;
        s_silk_pulses_per_block_BITS_Q5[2][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[2][17] = 224;
        s_silk_pulses_per_block_BITS_Q5[3] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[3][0] = 125;
        s_silk_pulses_per_block_BITS_Q5[3][1] = 74;
        s_silk_pulses_per_block_BITS_Q5[3][2] = 59;
        s_silk_pulses_per_block_BITS_Q5[3][3] = 69;
        s_silk_pulses_per_block_BITS_Q5[3][4] = 97;
        s_silk_pulses_per_block_BITS_Q5[3][5] = 141;
        s_silk_pulses_per_block_BITS_Q5[3][6] = 182;
        s_silk_pulses_per_block_BITS_Q5[3][7] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][8] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][9] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][10] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][11] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][12] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][15] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[3][17] = 255;
        s_silk_pulses_per_block_BITS_Q5[4] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[4][0] = 173;
        s_silk_pulses_per_block_BITS_Q5[4][1] = 115;
        s_silk_pulses_per_block_BITS_Q5[4][2] = 85;
        s_silk_pulses_per_block_BITS_Q5[4][3] = 73;
        s_silk_pulses_per_block_BITS_Q5[4][4] = 76;
        s_silk_pulses_per_block_BITS_Q5[4][5] = 92;
        s_silk_pulses_per_block_BITS_Q5[4][6] = 115;
        s_silk_pulses_per_block_BITS_Q5[4][7] = 145;
        s_silk_pulses_per_block_BITS_Q5[4][8] = 173;
        s_silk_pulses_per_block_BITS_Q5[4][9] = 205;
        s_silk_pulses_per_block_BITS_Q5[4][10] = 224;
        s_silk_pulses_per_block_BITS_Q5[4][11] = 224;
        s_silk_pulses_per_block_BITS_Q5[4][12] = 255;
        s_silk_pulses_per_block_BITS_Q5[4][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[4][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[4][15] = 255;
        s_silk_pulses_per_block_BITS_Q5[4][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[4][17] = 255;
        s_silk_pulses_per_block_BITS_Q5[5] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[5][0] = 166;
        s_silk_pulses_per_block_BITS_Q5[5][1] = 134;
        s_silk_pulses_per_block_BITS_Q5[5][2] = 113;
        s_silk_pulses_per_block_BITS_Q5[5][3] = 102;
        s_silk_pulses_per_block_BITS_Q5[5][4] = 101;
        s_silk_pulses_per_block_BITS_Q5[5][5] = 102;
        s_silk_pulses_per_block_BITS_Q5[5][6] = 107;
        s_silk_pulses_per_block_BITS_Q5[5][7] = 118;
        s_silk_pulses_per_block_BITS_Q5[5][8] = 125;
        s_silk_pulses_per_block_BITS_Q5[5][9] = 138;
        s_silk_pulses_per_block_BITS_Q5[5][10] = 145;
        s_silk_pulses_per_block_BITS_Q5[5][11] = 155;
        s_silk_pulses_per_block_BITS_Q5[5][12] = 166;
        s_silk_pulses_per_block_BITS_Q5[5][13] = 182;
        s_silk_pulses_per_block_BITS_Q5[5][14] = 192;
        s_silk_pulses_per_block_BITS_Q5[5][15] = 192;
        s_silk_pulses_per_block_BITS_Q5[5][16] = 205;
        s_silk_pulses_per_block_BITS_Q5[5][17] = 150;
        s_silk_pulses_per_block_BITS_Q5[6] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[6][0] = 224;
        s_silk_pulses_per_block_BITS_Q5[6][1] = 182;
        s_silk_pulses_per_block_BITS_Q5[6][2] = 134;
        s_silk_pulses_per_block_BITS_Q5[6][3] = 101;
        s_silk_pulses_per_block_BITS_Q5[6][4] = 83;
        s_silk_pulses_per_block_BITS_Q5[6][5] = 79;
        s_silk_pulses_per_block_BITS_Q5[6][6] = 85;
        s_silk_pulses_per_block_BITS_Q5[6][7] = 97;
        s_silk_pulses_per_block_BITS_Q5[6][8] = 120;
        s_silk_pulses_per_block_BITS_Q5[6][9] = 145;
        s_silk_pulses_per_block_BITS_Q5[6][10] = 173;
        s_silk_pulses_per_block_BITS_Q5[6][11] = 205;
        s_silk_pulses_per_block_BITS_Q5[6][12] = 224;
        s_silk_pulses_per_block_BITS_Q5[6][13] = 255;
        s_silk_pulses_per_block_BITS_Q5[6][14] = 255;
        s_silk_pulses_per_block_BITS_Q5[6][15] = 255;
        s_silk_pulses_per_block_BITS_Q5[6][16] = 255;
        s_silk_pulses_per_block_BITS_Q5[6][17] = 255;
        s_silk_pulses_per_block_BITS_Q5[7] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[7][0] = 255;
        s_silk_pulses_per_block_BITS_Q5[7][1] = 224;
        s_silk_pulses_per_block_BITS_Q5[7][2] = 192;
        s_silk_pulses_per_block_BITS_Q5[7][3] = 150;
        s_silk_pulses_per_block_BITS_Q5[7][4] = 120;
        s_silk_pulses_per_block_BITS_Q5[7][5] = 101;
        s_silk_pulses_per_block_BITS_Q5[7][6] = 92;
        s_silk_pulses_per_block_BITS_Q5[7][7] = 89;
        s_silk_pulses_per_block_BITS_Q5[7][8] = 93;
        s_silk_pulses_per_block_BITS_Q5[7][9] = 102;
        s_silk_pulses_per_block_BITS_Q5[7][10] = 118;
        s_silk_pulses_per_block_BITS_Q5[7][11] = 134;
        s_silk_pulses_per_block_BITS_Q5[7][12] = 160;
        s_silk_pulses_per_block_BITS_Q5[7][13] = 182;
        s_silk_pulses_per_block_BITS_Q5[7][14] = 192;
        s_silk_pulses_per_block_BITS_Q5[7][15] = 224;
        s_silk_pulses_per_block_BITS_Q5[7][16] = 224;
        s_silk_pulses_per_block_BITS_Q5[7][17] = 224;
        s_silk_pulses_per_block_BITS_Q5[8] = opus_alloc(18);
        s_silk_pulses_per_block_BITS_Q5[8][0] = 255;
        s_silk_pulses_per_block_BITS_Q5[8][1] = 224;
        s_silk_pulses_per_block_BITS_Q5[8][2] = 224;
        s_silk_pulses_per_block_BITS_Q5[8][3] = 182;
        s_silk_pulses_per_block_BITS_Q5[8][4] = 155;
        s_silk_pulses_per_block_BITS_Q5[8][5] = 134;
        s_silk_pulses_per_block_BITS_Q5[8][6] = 118;
        s_silk_pulses_per_block_BITS_Q5[8][7] = 109;
        s_silk_pulses_per_block_BITS_Q5[8][8] = 104;
        s_silk_pulses_per_block_BITS_Q5[8][9] = 102;
        s_silk_pulses_per_block_BITS_Q5[8][10] = 106;
        s_silk_pulses_per_block_BITS_Q5[8][11] = 111;
        s_silk_pulses_per_block_BITS_Q5[8][12] = 118;
        s_silk_pulses_per_block_BITS_Q5[8][13] = 131;
        s_silk_pulses_per_block_BITS_Q5[8][14] = 145;
        s_silk_pulses_per_block_BITS_Q5[8][15] = 160;
        s_silk_pulses_per_block_BITS_Q5[8][16] = 173;
        s_silk_pulses_per_block_BITS_Q5[8][17] = 131;
    }

    return (const unsigned char **) s_silk_pulses_per_block_BITS_Q5;
};


opus_uint8 **s_silk_rate_levels_iCDF = 0;
const opus_uint8 **get_silk_rate_levels_iCDF(void){
    if(s_silk_rate_levels_iCDF == 0){
        s_silk_rate_levels_iCDF = opus_alloc(sizeof(opus_uint8 *) * 2);

        s_silk_rate_levels_iCDF[0] = opus_alloc(9);
        s_silk_rate_levels_iCDF[0][0] = 241;
        s_silk_rate_levels_iCDF[0][1] = 190;
        s_silk_rate_levels_iCDF[0][2] = 178;
        s_silk_rate_levels_iCDF[0][3] = 132;
        s_silk_rate_levels_iCDF[0][4] = 87;
        s_silk_rate_levels_iCDF[0][5] = 74;
        s_silk_rate_levels_iCDF[0][6] = 41;
        s_silk_rate_levels_iCDF[0][7] = 14;
        s_silk_rate_levels_iCDF[0][8] = 0;
        s_silk_rate_levels_iCDF[1] = opus_alloc(9);
        s_silk_rate_levels_iCDF[1][0] = 223;
        s_silk_rate_levels_iCDF[1][1] = 193;
        s_silk_rate_levels_iCDF[1][2] = 157;
        s_silk_rate_levels_iCDF[1][3] = 140;
        s_silk_rate_levels_iCDF[1][4] = 106;
        s_silk_rate_levels_iCDF[1][5] = 57;
        s_silk_rate_levels_iCDF[1][6] = 39;
        s_silk_rate_levels_iCDF[1][7] = 18;
        s_silk_rate_levels_iCDF[1][8] = 0;
    }

    return (const unsigned char **) s_silk_rate_levels_iCDF;
}


opus_uint8 **s_silk_rate_levels_BITS_Q5 = 0;
const opus_uint8 **get_silk_rate_levels_BITS_Q5(void){
    if(s_silk_rate_levels_BITS_Q5 == 0){
        s_silk_rate_levels_BITS_Q5 = opus_alloc(sizeof(opus_uint8 *) * 2);

        s_silk_rate_levels_BITS_Q5[0] = opus_alloc(9);
        s_silk_rate_levels_BITS_Q5[0][0] = 131;
        s_silk_rate_levels_BITS_Q5[0][1] = 74;
        s_silk_rate_levels_BITS_Q5[0][2] = 141;
        s_silk_rate_levels_BITS_Q5[0][3] = 79;
        s_silk_rate_levels_BITS_Q5[0][4] = 80;
        s_silk_rate_levels_BITS_Q5[0][5] = 138;
        s_silk_rate_levels_BITS_Q5[0][6] = 95;
        s_silk_rate_levels_BITS_Q5[0][7] = 104;
        s_silk_rate_levels_BITS_Q5[0][8] = 134;
        s_silk_rate_levels_BITS_Q5[1] = opus_alloc(9);
        s_silk_rate_levels_BITS_Q5[1][0] = 95;
        s_silk_rate_levels_BITS_Q5[1][1] = 99;
        s_silk_rate_levels_BITS_Q5[1][2] = 91;
        s_silk_rate_levels_BITS_Q5[1][3] = 125;
        s_silk_rate_levels_BITS_Q5[1][4] = 93;
        s_silk_rate_levels_BITS_Q5[1][5] = 76;
        s_silk_rate_levels_BITS_Q5[1][6] = 123;
        s_silk_rate_levels_BITS_Q5[1][7] = 115;
        s_silk_rate_levels_BITS_Q5[1][8] = 123;
    }

    return (const unsigned char **) s_silk_rate_levels_BITS_Q5;
}



opus_uint8 *s_silk_shell_code_table_offsets = 0;
const opus_uint8 * get_silk_shell_code_table_offsets(void){
    if(s_silk_shell_code_table_offsets == 0){
        s_silk_shell_code_table_offsets = opus_alloc(17);

        s_silk_shell_code_table_offsets[0] = 0; s_silk_shell_code_table_offsets[1] = 0;
        s_silk_shell_code_table_offsets[2] = 2; s_silk_shell_code_table_offsets[3] = 5;
        s_silk_shell_code_table_offsets[4] = 9; s_silk_shell_code_table_offsets[5] = 14;
        s_silk_shell_code_table_offsets[6] = 20; s_silk_shell_code_table_offsets[7] = 27;
        s_silk_shell_code_table_offsets[8] = 35; s_silk_shell_code_table_offsets[9] = 44;
        s_silk_shell_code_table_offsets[10] = 54; s_silk_shell_code_table_offsets[11] = 65;
        s_silk_shell_code_table_offsets[12] = 77; s_silk_shell_code_table_offsets[13] = 90;
        s_silk_shell_code_table_offsets[14] = 104; s_silk_shell_code_table_offsets[15] = 119;
        s_silk_shell_code_table_offsets[16] = 135;
    }

    return s_silk_shell_code_table_offsets;
}


opus_uint8 *s_silk_sign_iCDF = 0;
const opus_uint8 * get_silk_sign_iCDF(void){
    if(s_silk_sign_iCDF == 0){
        s_silk_sign_iCDF = opus_alloc(42);

        s_silk_sign_iCDF[0] = 254; s_silk_sign_iCDF[1] = 49;
        s_silk_sign_iCDF[2] = 67; s_silk_sign_iCDF[3] = 77;
        s_silk_sign_iCDF[4] = 82; s_silk_sign_iCDF[5] = 93;
        s_silk_sign_iCDF[6] = 99; s_silk_sign_iCDF[7] = 198;
        s_silk_sign_iCDF[8] = 11; s_silk_sign_iCDF[9] = 18;
        s_silk_sign_iCDF[10] = 24; s_silk_sign_iCDF[11] = 31;
        s_silk_sign_iCDF[12] = 36; s_silk_sign_iCDF[13] = 45;
        s_silk_sign_iCDF[14] = 255; s_silk_sign_iCDF[15] = 46;
        s_silk_sign_iCDF[16] = 66; s_silk_sign_iCDF[17] = 78;
        s_silk_sign_iCDF[18] = 87; s_silk_sign_iCDF[19] = 94;
        s_silk_sign_iCDF[20] = 104; s_silk_sign_iCDF[21] = 208;
        s_silk_sign_iCDF[22] = 14; s_silk_sign_iCDF[23] = 21;
        s_silk_sign_iCDF[24] = 32; s_silk_sign_iCDF[25] = 42;
        s_silk_sign_iCDF[26] = 51; s_silk_sign_iCDF[27] = 66;
        s_silk_sign_iCDF[28] = 255; s_silk_sign_iCDF[29] = 94;
        s_silk_sign_iCDF[30] = 104; s_silk_sign_iCDF[31] = 109;
        s_silk_sign_iCDF[32] = 112; s_silk_sign_iCDF[33] = 115;
        s_silk_sign_iCDF[34] = 118; s_silk_sign_iCDF[35] = 248;
        s_silk_sign_iCDF[36] = 53; s_silk_sign_iCDF[37] = 69;
        s_silk_sign_iCDF[38] = 80; s_silk_sign_iCDF[39] = 88;
        s_silk_sign_iCDF[40] = 95; s_silk_sign_iCDF[41] = 102;
    }

    return s_silk_sign_iCDF;
}
