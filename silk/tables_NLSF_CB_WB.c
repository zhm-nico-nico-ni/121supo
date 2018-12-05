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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include "tables.h"


silk_NLSF_CB_struct * _silk_NLSF_CB_WB;
silk_NLSF_CB_struct *getSilk_NLSF_CB_WB(void) {
    if (_silk_NLSF_CB_WB == NULL) {
        _silk_NLSF_CB_WB = (silk_NLSF_CB_struct*)malloc(sizeof(silk_NLSF_CB_struct));
        opus_uint8 silk_NLSF_CB1_WB_Q8[512] = {
                7, 23, 38, 54, 69, 85, 100, 116,
                131, 147, 162, 178, 193, 208, 223, 239,
                13, 25, 41, 55, 69, 83, 98, 112,
                127, 142, 157, 171, 187, 203, 220, 236,
                15, 21, 34, 51, 61, 78, 92, 106,
                126, 136, 152, 167, 185, 205, 225, 240,
                10, 21, 36, 50, 63, 79, 95, 110,
                126, 141, 157, 173, 189, 205, 221, 237,
                17, 20, 37, 51, 59, 78, 89, 107,
                123, 134, 150, 164, 184, 205, 224, 240,
                10, 15, 32, 51, 67, 81, 96, 112,
                129, 142, 158, 173, 189, 204, 220, 236,
                8, 21, 37, 51, 65, 79, 98, 113,
                126, 138, 155, 168, 179, 192, 209, 218,
                12, 15, 34, 55, 63, 78, 87, 108,
                118, 131, 148, 167, 185, 203, 219, 236,
                16, 19, 32, 36, 56, 79, 91, 108,
                118, 136, 154, 171, 186, 204, 220, 237,
                11, 28, 43, 58, 74, 89, 105, 120,
                135, 150, 165, 180, 196, 211, 226, 241,
                6, 16, 33, 46, 60, 75, 92, 107,
                123, 137, 156, 169, 185, 199, 214, 225,
                11, 19, 30, 44, 57, 74, 89, 105,
                121, 135, 152, 169, 186, 202, 218, 234,
                12, 19, 29, 46, 57, 71, 88, 100,
                120, 132, 148, 165, 182, 199, 216, 233,
                17, 23, 35, 46, 56, 77, 92, 106,
                123, 134, 152, 167, 185, 204, 222, 237,
                14, 17, 45, 53, 63, 75, 89, 107,
                115, 132, 151, 171, 188, 206, 221, 240,
                9, 16, 29, 40, 56, 71, 88, 103,
                119, 137, 154, 171, 189, 205, 222, 237,
                16, 19, 36, 48, 57, 76, 87, 105,
                118, 132, 150, 167, 185, 202, 218, 236,
                12, 17, 29, 54, 71, 81, 94, 104,
                126, 136, 149, 164, 182, 201, 221, 237,
                15, 28, 47, 62, 79, 97, 115, 129,
                142, 155, 168, 180, 194, 208, 223, 238,
                8, 14, 30, 45, 62, 78, 94, 111,
                127, 143, 159, 175, 192, 207, 223, 239,
                17, 30, 49, 62, 79, 92, 107, 119,
                132, 145, 160, 174, 190, 204, 220, 235,
                14, 19, 36, 45, 61, 76, 91, 108,
                121, 138, 154, 172, 189, 205, 222, 238,
                12, 18, 31, 45, 60, 76, 91, 107,
                123, 138, 154, 171, 187, 204, 221, 236,
                13, 17, 31, 43, 53, 70, 83, 103,
                114, 131, 149, 167, 185, 203, 220, 237,
                17, 22, 35, 42, 58, 78, 93, 110,
                125, 139, 155, 170, 188, 206, 224, 240,
                8, 15, 34, 50, 67, 83, 99, 115,
                131, 146, 162, 178, 193, 209, 224, 239,
                13, 16, 41, 66, 73, 86, 95, 111,
                128, 137, 150, 163, 183, 206, 225, 241,
                17, 25, 37, 52, 63, 75, 92, 102,
                119, 132, 144, 160, 175, 191, 212, 231,
                19, 31, 49, 65, 83, 100, 117, 133,
                147, 161, 174, 187, 200, 213, 227, 242,
                18, 31, 52, 68, 88, 103, 117, 126,
                138, 149, 163, 177, 192, 207, 223, 239,
                16, 29, 47, 61, 76, 90, 106, 119,
                133, 147, 161, 176, 193, 209, 224, 240,
                15, 21, 35, 50, 61, 73, 86, 97,
                110, 119, 129, 141, 175, 198, 218, 237
        };
        opus_uint8 *silk_NLSF_CB1_WB_Q8ptr = malloc(sizeof(opus_uint8) * 512 + 1);
        memcpy(silk_NLSF_CB1_WB_Q8ptr, silk_NLSF_CB1_WB_Q8, 512);

        opus_int16 *silk_NLSF_CB1_WB_Wght_Q9ptr = malloc(sizeof(opus_int16) * 512);
        silk_NLSF_CB1_WB_Wght_Q9ptr[0] = 3657; silk_NLSF_CB1_WB_Wght_Q9ptr[1] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[2] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[3] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[4] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[5] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[6] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[7] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[8] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[9] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[10] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[11] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[12] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[13] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[14] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[15] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[16] = 3216; silk_NLSF_CB1_WB_Wght_Q9ptr[17] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[18] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[19] = 3056;
        silk_NLSF_CB1_WB_Wght_Q9ptr[20] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[21] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[22] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[23] = 3010;
        silk_NLSF_CB1_WB_Wght_Q9ptr[24] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[25] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[26] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[27] = 2972;
        silk_NLSF_CB1_WB_Wght_Q9ptr[28] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[29] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[30] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[31] = 2726;
        silk_NLSF_CB1_WB_Wght_Q9ptr[32] = 3920; silk_NLSF_CB1_WB_Wght_Q9ptr[33] = 4014; silk_NLSF_CB1_WB_Wght_Q9ptr[34] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[35] = 3207;
        silk_NLSF_CB1_WB_Wght_Q9ptr[36] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[37] = 2934; silk_NLSF_CB1_WB_Wght_Q9ptr[38] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[39] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[40] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[41] = 3244; silk_NLSF_CB1_WB_Wght_Q9ptr[42] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[43] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[44] = 2620; silk_NLSF_CB1_WB_Wght_Q9ptr[45] = 2553; silk_NLSF_CB1_WB_Wght_Q9ptr[46] = 2780; silk_NLSF_CB1_WB_Wght_Q9ptr[47] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[48] = 3516; silk_NLSF_CB1_WB_Wght_Q9ptr[49] = 3197; silk_NLSF_CB1_WB_Wght_Q9ptr[50] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[51] = 3103;
        silk_NLSF_CB1_WB_Wght_Q9ptr[52] = 3019; silk_NLSF_CB1_WB_Wght_Q9ptr[53] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[54] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[55] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[56] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[57] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[58] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[59] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[60] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[61] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[62] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[63] = 2753;
        silk_NLSF_CB1_WB_Wght_Q9ptr[64] = 5054; silk_NLSF_CB1_WB_Wght_Q9ptr[65] = 5054; silk_NLSF_CB1_WB_Wght_Q9ptr[66] = 2934; silk_NLSF_CB1_WB_Wght_Q9ptr[67] = 3573;
        silk_NLSF_CB1_WB_Wght_Q9ptr[68] = 3385; silk_NLSF_CB1_WB_Wght_Q9ptr[69] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[70] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[71] = 2793;
        silk_NLSF_CB1_WB_Wght_Q9ptr[72] = 3160; silk_NLSF_CB1_WB_Wght_Q9ptr[73] = 3160; silk_NLSF_CB1_WB_Wght_Q9ptr[74] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[75] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[76] = 2513; silk_NLSF_CB1_WB_Wght_Q9ptr[77] = 2540; silk_NLSF_CB1_WB_Wght_Q9ptr[78] = 2753; silk_NLSF_CB1_WB_Wght_Q9ptr[79] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[80] = 4428; silk_NLSF_CB1_WB_Wght_Q9ptr[81] = 4149; silk_NLSF_CB1_WB_Wght_Q9ptr[82] = 2700; silk_NLSF_CB1_WB_Wght_Q9ptr[83] = 2753;
        silk_NLSF_CB1_WB_Wght_Q9ptr[84] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[85] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[86] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[87] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[88] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[89] = 3019; silk_NLSF_CB1_WB_Wght_Q9ptr[90] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[91] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[92] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[93] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[94] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[95] = 2726;
        silk_NLSF_CB1_WB_Wght_Q9ptr[96] = 3620; silk_NLSF_CB1_WB_Wght_Q9ptr[97] = 3019; silk_NLSF_CB1_WB_Wght_Q9ptr[98] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[99] = 3056;
        silk_NLSF_CB1_WB_Wght_Q9ptr[100] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[101] = 2873; silk_NLSF_CB1_WB_Wght_Q9ptr[102] = 2806; silk_NLSF_CB1_WB_Wght_Q9ptr[103] = 3056;
        silk_NLSF_CB1_WB_Wght_Q9ptr[104] = 3216; silk_NLSF_CB1_WB_Wght_Q9ptr[105] = 3047; silk_NLSF_CB1_WB_Wght_Q9ptr[106] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[107] = 3291;
        silk_NLSF_CB1_WB_Wght_Q9ptr[108] = 3291; silk_NLSF_CB1_WB_Wght_Q9ptr[109] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[110] = 3310; silk_NLSF_CB1_WB_Wght_Q9ptr[111] = 2991;
        silk_NLSF_CB1_WB_Wght_Q9ptr[112] = 5227; silk_NLSF_CB1_WB_Wght_Q9ptr[113] = 5014; silk_NLSF_CB1_WB_Wght_Q9ptr[114] = 2540; silk_NLSF_CB1_WB_Wght_Q9ptr[115] = 3338;
        silk_NLSF_CB1_WB_Wght_Q9ptr[116] = 3526; silk_NLSF_CB1_WB_Wght_Q9ptr[117] = 3385; silk_NLSF_CB1_WB_Wght_Q9ptr[118] = 3197; silk_NLSF_CB1_WB_Wght_Q9ptr[119] = 3094;
        silk_NLSF_CB1_WB_Wght_Q9ptr[120] = 3376; silk_NLSF_CB1_WB_Wght_Q9ptr[121] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[122] = 2700; silk_NLSF_CB1_WB_Wght_Q9ptr[123] = 2647;
        silk_NLSF_CB1_WB_Wght_Q9ptr[124] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[125] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[126] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[127] = 2673;
        silk_NLSF_CB1_WB_Wght_Q9ptr[128] = 5081; silk_NLSF_CB1_WB_Wght_Q9ptr[129] = 5174; silk_NLSF_CB1_WB_Wght_Q9ptr[130] = 4615; silk_NLSF_CB1_WB_Wght_Q9ptr[131] = 4428;
        silk_NLSF_CB1_WB_Wght_Q9ptr[132] = 2460; silk_NLSF_CB1_WB_Wght_Q9ptr[133] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[134] = 3047; silk_NLSF_CB1_WB_Wght_Q9ptr[135] = 3207;
        silk_NLSF_CB1_WB_Wght_Q9ptr[136] = 3169; silk_NLSF_CB1_WB_Wght_Q9ptr[137] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[138] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[139] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[140] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[141] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[142] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[143] = 2700;
        silk_NLSF_CB1_WB_Wght_Q9ptr[144] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[145] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[146] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[147] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[148] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[149] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[150] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[151] = 2963;
        silk_NLSF_CB1_WB_Wght_Q9ptr[152] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[153] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[154] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[155] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[156] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[157] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[158] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[159] = 2963;
        silk_NLSF_CB1_WB_Wght_Q9ptr[160] = 4202; silk_NLSF_CB1_WB_Wght_Q9ptr[161] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[162] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[163] = 3103;
        silk_NLSF_CB1_WB_Wght_Q9ptr[164] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[165] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[166] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[167] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[168] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[169] = 2873; silk_NLSF_CB1_WB_Wght_Q9ptr[170] = 2916; silk_NLSF_CB1_WB_Wght_Q9ptr[171] = 3019;
        silk_NLSF_CB1_WB_Wght_Q9ptr[172] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[173] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[174] = 3197; silk_NLSF_CB1_WB_Wght_Q9ptr[175] = 2873;
        silk_NLSF_CB1_WB_Wght_Q9ptr[176] = 3760; silk_NLSF_CB1_WB_Wght_Q9ptr[177] = 3760; silk_NLSF_CB1_WB_Wght_Q9ptr[178] = 3244; silk_NLSF_CB1_WB_Wght_Q9ptr[179] = 3103;
        silk_NLSF_CB1_WB_Wght_Q9ptr[180] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[181] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[182] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[183] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[184] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[185] = 2934; silk_NLSF_CB1_WB_Wght_Q9ptr[186] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[187] = 2793;
        silk_NLSF_CB1_WB_Wght_Q9ptr[188] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[189] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[190] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[191] = 2660;
        silk_NLSF_CB1_WB_Wght_Q9ptr[192] = 3854; silk_NLSF_CB1_WB_Wght_Q9ptr[193] = 4014; silk_NLSF_CB1_WB_Wght_Q9ptr[194] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[195] = 3122;
        silk_NLSF_CB1_WB_Wght_Q9ptr[196] = 3244; silk_NLSF_CB1_WB_Wght_Q9ptr[197] = 2934; silk_NLSF_CB1_WB_Wght_Q9ptr[198] = 3047; silk_NLSF_CB1_WB_Wght_Q9ptr[199] = 2963;
        silk_NLSF_CB1_WB_Wght_Q9ptr[200] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[201] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[202] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[203] = 2793;
        silk_NLSF_CB1_WB_Wght_Q9ptr[204] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[205] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[206] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[207] = 2580;
        silk_NLSF_CB1_WB_Wght_Q9ptr[208] = 3845; silk_NLSF_CB1_WB_Wght_Q9ptr[209] = 4080; silk_NLSF_CB1_WB_Wght_Q9ptr[210] = 3357; silk_NLSF_CB1_WB_Wght_Q9ptr[211] = 3516;
        silk_NLSF_CB1_WB_Wght_Q9ptr[212] = 3094; silk_NLSF_CB1_WB_Wght_Q9ptr[213] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[214] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[215] = 2934;
        silk_NLSF_CB1_WB_Wght_Q9ptr[216] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[217] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[218] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[219] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[220] = 2647; silk_NLSF_CB1_WB_Wght_Q9ptr[221] = 2647; silk_NLSF_CB1_WB_Wght_Q9ptr[222] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[223] = 2806;
        silk_NLSF_CB1_WB_Wght_Q9ptr[224] = 5147; silk_NLSF_CB1_WB_Wght_Q9ptr[225] = 4894; silk_NLSF_CB1_WB_Wght_Q9ptr[226] = 3225; silk_NLSF_CB1_WB_Wght_Q9ptr[227] = 3845;
        silk_NLSF_CB1_WB_Wght_Q9ptr[228] = 3441; silk_NLSF_CB1_WB_Wght_Q9ptr[229] = 3169; silk_NLSF_CB1_WB_Wght_Q9ptr[230] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[231] = 3413;
        silk_NLSF_CB1_WB_Wght_Q9ptr[232] = 3451; silk_NLSF_CB1_WB_Wght_Q9ptr[233] = 2700; silk_NLSF_CB1_WB_Wght_Q9ptr[234] = 2580; silk_NLSF_CB1_WB_Wght_Q9ptr[235] = 2673;
        silk_NLSF_CB1_WB_Wght_Q9ptr[236] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[237] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[238] = 2806; silk_NLSF_CB1_WB_Wght_Q9ptr[239] = 2753;
        silk_NLSF_CB1_WB_Wght_Q9ptr[240] = 4109; silk_NLSF_CB1_WB_Wght_Q9ptr[241] = 3789; silk_NLSF_CB1_WB_Wght_Q9ptr[242] = 3291; silk_NLSF_CB1_WB_Wght_Q9ptr[243] = 3160;
        silk_NLSF_CB1_WB_Wght_Q9ptr[244] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[245] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[246] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[247] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[248] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[249] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[250] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[251] = 2740;
        silk_NLSF_CB1_WB_Wght_Q9ptr[252] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[253] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[254] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[255] = 2806;
        silk_NLSF_CB1_WB_Wght_Q9ptr[256] = 5081; silk_NLSF_CB1_WB_Wght_Q9ptr[257] = 5054; silk_NLSF_CB1_WB_Wght_Q9ptr[258] = 3047; silk_NLSF_CB1_WB_Wght_Q9ptr[259] = 3545;
        silk_NLSF_CB1_WB_Wght_Q9ptr[260] = 3244; silk_NLSF_CB1_WB_Wght_Q9ptr[261] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[262] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[263] = 2944;
        silk_NLSF_CB1_WB_Wght_Q9ptr[264] = 3103; silk_NLSF_CB1_WB_Wght_Q9ptr[265] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[266] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[267] = 2740;
        silk_NLSF_CB1_WB_Wght_Q9ptr[268] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[269] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[270] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[271] = 2620;
        silk_NLSF_CB1_WB_Wght_Q9ptr[272] = 4309; silk_NLSF_CB1_WB_Wght_Q9ptr[273] = 4309; silk_NLSF_CB1_WB_Wght_Q9ptr[274] = 2860; silk_NLSF_CB1_WB_Wght_Q9ptr[275] = 2527;
        silk_NLSF_CB1_WB_Wght_Q9ptr[276] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[277] = 3376; silk_NLSF_CB1_WB_Wght_Q9ptr[278] = 3376; silk_NLSF_CB1_WB_Wght_Q9ptr[279] = 3075;
        silk_NLSF_CB1_WB_Wght_Q9ptr[280] = 3075; silk_NLSF_CB1_WB_Wght_Q9ptr[281] = 3376; silk_NLSF_CB1_WB_Wght_Q9ptr[282] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[283] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[284] = 2647; silk_NLSF_CB1_WB_Wght_Q9ptr[285] = 2580; silk_NLSF_CB1_WB_Wght_Q9ptr[286] = 2726; silk_NLSF_CB1_WB_Wght_Q9ptr[287] = 2753;
        silk_NLSF_CB1_WB_Wght_Q9ptr[288] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[289] = 2916; silk_NLSF_CB1_WB_Wght_Q9ptr[290] = 2806; silk_NLSF_CB1_WB_Wght_Q9ptr[291] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[292] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[293] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[294] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[295] = 3103;
        silk_NLSF_CB1_WB_Wght_Q9ptr[296] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[297] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[298] = 3216; silk_NLSF_CB1_WB_Wght_Q9ptr[299] = 3169;
        silk_NLSF_CB1_WB_Wght_Q9ptr[300] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[301] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[302] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[303] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[304] = 4375; silk_NLSF_CB1_WB_Wght_Q9ptr[305] = 3882; silk_NLSF_CB1_WB_Wght_Q9ptr[306] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[307] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[308] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[309] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[310] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[311] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[312] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[313] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[314] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[315] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[316] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[317] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[318] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[319] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[320] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[321] = 2916; silk_NLSF_CB1_WB_Wght_Q9ptr[322] = 2916; silk_NLSF_CB1_WB_Wght_Q9ptr[323] = 2981;
        silk_NLSF_CB1_WB_Wght_Q9ptr[324] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[325] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[326] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[327] = 3216;
        silk_NLSF_CB1_WB_Wght_Q9ptr[328] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[329] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[330] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[331] = 2972;
        silk_NLSF_CB1_WB_Wght_Q9ptr[332] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[333] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[334] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[335] = 2740;
        silk_NLSF_CB1_WB_Wght_Q9ptr[336] = 4229; silk_NLSF_CB1_WB_Wght_Q9ptr[337] = 4149; silk_NLSF_CB1_WB_Wght_Q9ptr[338] = 3310; silk_NLSF_CB1_WB_Wght_Q9ptr[339] = 3347;
        silk_NLSF_CB1_WB_Wght_Q9ptr[340] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[341] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[342] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[343] = 2981;
        silk_NLSF_CB1_WB_Wght_Q9ptr[344] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[345] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[346] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[347] = 2740;
        silk_NLSF_CB1_WB_Wght_Q9ptr[348] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[349] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[350] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[351] = 2793;
        silk_NLSF_CB1_WB_Wght_Q9ptr[352] = 4080; silk_NLSF_CB1_WB_Wght_Q9ptr[353] = 4014; silk_NLSF_CB1_WB_Wght_Q9ptr[354] = 3103; silk_NLSF_CB1_WB_Wght_Q9ptr[355] = 3010;
        silk_NLSF_CB1_WB_Wght_Q9ptr[356] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[357] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[358] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[359] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[360] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[361] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[362] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[363] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[364] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[365] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[366] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[367] = 2780;
        silk_NLSF_CB1_WB_Wght_Q9ptr[368] = 4615; silk_NLSF_CB1_WB_Wght_Q9ptr[369] = 4575; silk_NLSF_CB1_WB_Wght_Q9ptr[370] = 3169; silk_NLSF_CB1_WB_Wght_Q9ptr[371] = 3441;
        silk_NLSF_CB1_WB_Wght_Q9ptr[372] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[373] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[374] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[375] = 3038;
        silk_NLSF_CB1_WB_Wght_Q9ptr[376] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[377] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[378] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[379] = 2687;
        silk_NLSF_CB1_WB_Wght_Q9ptr[380] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[381] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[382] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[383] = 2700;
        silk_NLSF_CB1_WB_Wght_Q9ptr[384] = 4149; silk_NLSF_CB1_WB_Wght_Q9ptr[385] = 4269; silk_NLSF_CB1_WB_Wght_Q9ptr[386] = 3789; silk_NLSF_CB1_WB_Wght_Q9ptr[387] = 3657;
        silk_NLSF_CB1_WB_Wght_Q9ptr[388] = 2726; silk_NLSF_CB1_WB_Wght_Q9ptr[389] = 2780; silk_NLSF_CB1_WB_Wght_Q9ptr[390] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[391] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[392] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[393] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[394] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[395] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[396] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[397] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[398] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[399] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[400] = 4215; silk_NLSF_CB1_WB_Wght_Q9ptr[401] = 3554; silk_NLSF_CB1_WB_Wght_Q9ptr[402] = 2753; silk_NLSF_CB1_WB_Wght_Q9ptr[403] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[404] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[405] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[406] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[407] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[408] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[409] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[410] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[411] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[412] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[413] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[414] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[415] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[416] = 5174; silk_NLSF_CB1_WB_Wght_Q9ptr[417] = 4921; silk_NLSF_CB1_WB_Wght_Q9ptr[418] = 2261; silk_NLSF_CB1_WB_Wght_Q9ptr[419] = 3432;
        silk_NLSF_CB1_WB_Wght_Q9ptr[420] = 3789; silk_NLSF_CB1_WB_Wght_Q9ptr[421] = 3479; silk_NLSF_CB1_WB_Wght_Q9ptr[422] = 3347; silk_NLSF_CB1_WB_Wght_Q9ptr[423] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[424] = 3310; silk_NLSF_CB1_WB_Wght_Q9ptr[425] = 3479; silk_NLSF_CB1_WB_Wght_Q9ptr[426] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[427] = 2897;
        silk_NLSF_CB1_WB_Wght_Q9ptr[428] = 2460; silk_NLSF_CB1_WB_Wght_Q9ptr[429] = 2487; silk_NLSF_CB1_WB_Wght_Q9ptr[430] = 2753; silk_NLSF_CB1_WB_Wght_Q9ptr[431] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[432] = 3451; silk_NLSF_CB1_WB_Wght_Q9ptr[433] = 3685; silk_NLSF_CB1_WB_Wght_Q9ptr[434] = 3122; silk_NLSF_CB1_WB_Wght_Q9ptr[435] = 3197;
        silk_NLSF_CB1_WB_Wght_Q9ptr[436] = 3357; silk_NLSF_CB1_WB_Wght_Q9ptr[437] = 3047; silk_NLSF_CB1_WB_Wght_Q9ptr[438] = 3207; silk_NLSF_CB1_WB_Wght_Q9ptr[439] = 3207;
        silk_NLSF_CB1_WB_Wght_Q9ptr[440] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[441] = 3216; silk_NLSF_CB1_WB_Wght_Q9ptr[442] = 3085; silk_NLSF_CB1_WB_Wght_Q9ptr[443] = 2925;
        silk_NLSF_CB1_WB_Wght_Q9ptr[444] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[445] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[446] = 2540; silk_NLSF_CB1_WB_Wght_Q9ptr[447] = 2434;
        silk_NLSF_CB1_WB_Wght_Q9ptr[448] = 2981; silk_NLSF_CB1_WB_Wght_Q9ptr[449] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[450] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[451] = 2793;
        silk_NLSF_CB1_WB_Wght_Q9ptr[452] = 2740; silk_NLSF_CB1_WB_Wght_Q9ptr[453] = 2793; silk_NLSF_CB1_WB_Wght_Q9ptr[454] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[455] = 2972;
        silk_NLSF_CB1_WB_Wght_Q9ptr[456] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[457] = 3103; silk_NLSF_CB1_WB_Wght_Q9ptr[458] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[459] = 3150;
        silk_NLSF_CB1_WB_Wght_Q9ptr[460] = 3150; silk_NLSF_CB1_WB_Wght_Q9ptr[461] = 3103; silk_NLSF_CB1_WB_Wght_Q9ptr[462] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[463] = 3010;
        silk_NLSF_CB1_WB_Wght_Q9ptr[464] = 2944; silk_NLSF_CB1_WB_Wght_Q9ptr[465] = 2873; silk_NLSF_CB1_WB_Wght_Q9ptr[466] = 2687; silk_NLSF_CB1_WB_Wght_Q9ptr[467] = 2726;
        silk_NLSF_CB1_WB_Wght_Q9ptr[468] = 2780; silk_NLSF_CB1_WB_Wght_Q9ptr[469] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[470] = 3432; silk_NLSF_CB1_WB_Wght_Q9ptr[471] = 3545;
        silk_NLSF_CB1_WB_Wght_Q9ptr[472] = 3357; silk_NLSF_CB1_WB_Wght_Q9ptr[473] = 3244; silk_NLSF_CB1_WB_Wght_Q9ptr[474] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[475] = 3010;
        silk_NLSF_CB1_WB_Wght_Q9ptr[476] = 2963; silk_NLSF_CB1_WB_Wght_Q9ptr[477] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[478] = 2888; silk_NLSF_CB1_WB_Wght_Q9ptr[479] = 2846;
        silk_NLSF_CB1_WB_Wght_Q9ptr[480] = 3019; silk_NLSF_CB1_WB_Wght_Q9ptr[481] = 2944; silk_NLSF_CB1_WB_Wght_Q9ptr[482] = 2897; silk_NLSF_CB1_WB_Wght_Q9ptr[483] = 3010;
        silk_NLSF_CB1_WB_Wght_Q9ptr[484] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[485] = 2972; silk_NLSF_CB1_WB_Wght_Q9ptr[486] = 3019; silk_NLSF_CB1_WB_Wght_Q9ptr[487] = 3103;
        silk_NLSF_CB1_WB_Wght_Q9ptr[488] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[489] = 3056; silk_NLSF_CB1_WB_Wght_Q9ptr[490] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[491] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[492] = 2846; silk_NLSF_CB1_WB_Wght_Q9ptr[493] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[494] = 2925; silk_NLSF_CB1_WB_Wght_Q9ptr[495] = 2888;
        silk_NLSF_CB1_WB_Wght_Q9ptr[496] = 3920; silk_NLSF_CB1_WB_Wght_Q9ptr[497] = 3967; silk_NLSF_CB1_WB_Wght_Q9ptr[498] = 3010; silk_NLSF_CB1_WB_Wght_Q9ptr[499] = 3197;
        silk_NLSF_CB1_WB_Wght_Q9ptr[500] = 3357; silk_NLSF_CB1_WB_Wght_Q9ptr[501] = 3216; silk_NLSF_CB1_WB_Wght_Q9ptr[502] = 3291; silk_NLSF_CB1_WB_Wght_Q9ptr[503] = 3291;
        silk_NLSF_CB1_WB_Wght_Q9ptr[504] = 3479; silk_NLSF_CB1_WB_Wght_Q9ptr[505] = 3704; silk_NLSF_CB1_WB_Wght_Q9ptr[506] = 3441; silk_NLSF_CB1_WB_Wght_Q9ptr[507] = 2726;
        silk_NLSF_CB1_WB_Wght_Q9ptr[508] = 2181; silk_NLSF_CB1_WB_Wght_Q9ptr[509] = 2460; silk_NLSF_CB1_WB_Wght_Q9ptr[510] = 2580; silk_NLSF_CB1_WB_Wght_Q9ptr[511] = 2607;

        opus_uint8 silk_NLSF_CB1_iCDF_WB[ 64 ] = {
                225,    204,    201,    184,    183,    175,    158,    154,
                153,    135,    119,    115,    113,    110,    109,     99,
                98,     95,     79,     68,     52,     50,     48,     45,
                43,     32,     31,     27,     18,     10,      3,      0,
                255,    251,    235,    230,    212,    201,    196,    182,
                167,    166,    163,    151,    138,    124,    110,    104,
                90,     78,     76,     70,     69,     57,     45,     34,
                24,     21,     11,      6,      5,      4,      3,      0
        };
        opus_uint8 *silk_NLSF_CB1_iCDF_WB9ptr = malloc(sizeof(opus_uint8) * 64);
        memcpy(silk_NLSF_CB1_iCDF_WB9ptr, silk_NLSF_CB1_iCDF_WB, 64);

        opus_uint8 silk_NLSF_PRED_WB_Q8[ 30 ] = {
                175,    148,    160,    176,    178,    173,    174,    164,
                177,    174,    196,    182,    198,    192,    182,     68,
                62,     66,     60,     72,    117,     85,     90,    118,
                136,    151,    142,    160,    142,    155
        };
        opus_uint8 *silk_NLSF_PRED_WB_Q8ptr = malloc(sizeof(opus_uint8) * 30);
        memcpy(silk_NLSF_PRED_WB_Q8ptr, silk_NLSF_PRED_WB_Q8, 30);

        opus_uint8 silk_NLSF_CB2_SELECT_WB[ 256 ] = {
                0,      0,      0,      0,      0,      0,      0,      1,
                100,    102,    102,     68,     68,     36,     34,     96,
                164,    107,    158,    185,    180,    185,    139,    102,
                64,     66,     36,     34,     34,      0,      1,     32,
                208,    139,    141,    191,    152,    185,    155,    104,
                96,    171,    104,    166,    102,    102,    102,    132,
                1,      0,      0,      0,      0,     16,     16,      0,
                80,    109,     78,    107,    185,    139,    103,    101,
                208,    212,    141,    139,    173,    153,    123,    103,
                36,      0,      0,      0,      0,      0,      0,      1,
                48,      0,      0,      0,      0,      0,      0,     32,
                68,    135,    123,    119,    119,    103,     69,     98,
                68,    103,    120,    118,    118,    102,     71,     98,
                134,    136,    157,    184,    182,    153,    139,    134,
                208,    168,    248,     75,    189,    143,    121,    107,
                32,     49,     34,     34,     34,      0,     17,      2,
                210,    235,    139,    123,    185,    137,    105,    134,
                98,    135,    104,    182,    100,    183,    171,    134,
                100,     70,     68,     70,     66,     66,     34,    131,
                64,    166,    102,     68,     36,      2,      1,      0,
                134,    166,    102,     68,     34,     34,     66,    132,
                212,    246,    158,    139,    107,    107,     87,    102,
                100,    219,    125,    122,    137,    118,    103,    132,
                114,    135,    137,    105,    171,    106,     50,     34,
                164,    214,    141,    143,    185,    151,    121,    103,
                192,     34,      0,      0,      0,      0,      0,      1,
                208,    109,     74,    187,    134,    249,    159,    137,
                102,    110,    154,    118,     87,    101,    119,    101,
                0,      2,      0,     36,     36,     66,     68,     35,
                96,    164,    102,    100,     36,      0,      2,     33,
                167,    138,    174,    102,    100,     84,      2,      2,
                100,    107,    120,    119,     36,    197,     24,      0
        };
        opus_uint8 *silk_NLSF_CB2_SELECT_WBptr = malloc(sizeof(opus_uint8) * 256);
        memcpy(silk_NLSF_CB2_SELECT_WBptr, silk_NLSF_CB2_SELECT_WB, 256);

        const opus_uint8 silk_NLSF_CB2_iCDF_WB[ 72 ] = {
                255,    254,    253,    244,     12,      3,      2,      1,
                0,    255,    254,    252,    224,     38,      3,      2,
                1,      0,    255,    254,    251,    209,     57,      4,
                2,      1,      0,    255,    254,    244,    195,     69,
                4,      2,      1,      0,    255,    251,    232,    184,
                84,      7,      2,      1,      0,    255,    254,    240,
                186,     86,     14,      2,      1,      0,    255,    254,
                239,    178,     91,     30,      5,      1,      0,    255,
                248,    227,    177,    100,     19,      2,      1,      0
        };
        opus_uint8 *silk_NLSF_CB2_iCDF_WBptr = malloc(sizeof(opus_uint8) * 72);
        memcpy(silk_NLSF_CB2_iCDF_WBptr, silk_NLSF_CB2_iCDF_WB, 72);

        opus_uint8 silk_NLSF_CB2_BITS_WB_Q5[ 72 ] = {
                255,    255,    255,    156,      4,    154,    255,    255,
                255,    255,    255,    227,    102,     15,     92,    255,
                255,    255,    255,    255,    213,     83,     24,     72,
                236,    255,    255,    255,    255,    150,     76,     33,
                63,    214,    255,    255,    255,    190,    121,     77,
                43,     55,    185,    255,    255,    255,    245,    137,
                71,     43,     59,    139,    255,    255,    255,    255,
                131,     66,     50,     66,    107,    194,    255,    255,
                166,    116,     76,     55,     53,    125,    255,    255
        };
        opus_uint8 *silk_NLSF_CB2_BITS_WB_Q5ptr = malloc(sizeof(opus_uint8) * 72);
        memcpy(silk_NLSF_CB2_BITS_WB_Q5ptr, silk_NLSF_CB2_BITS_WB_Q5, 72);

        opus_int16 *silk_NLSF_DELTA_MIN_WB_Q15ptr = (opus_int16*)malloc(sizeof(opus_int16) * 17);
        silk_NLSF_DELTA_MIN_WB_Q15ptr[0] = 100;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[1] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[2] = 40;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[3] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[4] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[5] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[6] = 5;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[7] = 14;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[8] = 14;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[9] = 10;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[10] = 11;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[11] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[12] = 8;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[13] = 9;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[14] = 7;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[15] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[16] = 347;

        _silk_NLSF_CB_WB->nVectors = 32;
        _silk_NLSF_CB_WB->order = 16;
        _silk_NLSF_CB_WB->quantStepSize_Q16 =  SILK_FIX_CONST(0.15, 16 );
        _silk_NLSF_CB_WB->invQuantStepSize_Q6 =  SILK_FIX_CONST( 1.0 / 0.15, 6 );
        _silk_NLSF_CB_WB->CB1_NLSF_Q8 = silk_NLSF_CB1_WB_Q8ptr;
        _silk_NLSF_CB_WB->CB1_Wght_Q9 = silk_NLSF_CB1_WB_Wght_Q9ptr;
        _silk_NLSF_CB_WB->CB1_iCDF = silk_NLSF_CB1_iCDF_WB9ptr;
        _silk_NLSF_CB_WB->pred_Q8 = silk_NLSF_PRED_WB_Q8ptr;
        _silk_NLSF_CB_WB->ec_sel = silk_NLSF_CB2_SELECT_WBptr;
        _silk_NLSF_CB_WB->ec_iCDF = silk_NLSF_CB2_iCDF_WBptr;
        _silk_NLSF_CB_WB->ec_Rates_Q5 = silk_NLSF_CB2_BITS_WB_Q5ptr;
        _silk_NLSF_CB_WB->deltaMin_Q15 = silk_NLSF_DELTA_MIN_WB_Q15ptr;
    }
    silk_NLSF_CB_struct* test = _silk_NLSF_CB_WB;
    return test;
}

