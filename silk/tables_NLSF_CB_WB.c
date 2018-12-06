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


silk_NLSF_CB_struct * _silk_NLSF_CB_WB;
silk_NLSF_CB_struct *getSilk_NLSF_CB_WB(void) {
    if (_silk_NLSF_CB_WB == NULL) {
        _silk_NLSF_CB_WB = (silk_NLSF_CB_struct*)malloc(sizeof(silk_NLSF_CB_struct));

        opus_uint8 *silk_NLSF_CB1_WB_Q8ptr = malloc(sizeof(opus_uint8) * 512);
        silk_NLSF_CB1_WB_Q8ptr[0] = 7; silk_NLSF_CB1_WB_Q8ptr[1] = 23; silk_NLSF_CB1_WB_Q8ptr[2] = 38; silk_NLSF_CB1_WB_Q8ptr[3] = 54;
        silk_NLSF_CB1_WB_Q8ptr[4] = 69; silk_NLSF_CB1_WB_Q8ptr[5] = 85; silk_NLSF_CB1_WB_Q8ptr[6] = 100; silk_NLSF_CB1_WB_Q8ptr[7] = 116;
        silk_NLSF_CB1_WB_Q8ptr[8] = 131; silk_NLSF_CB1_WB_Q8ptr[9] = 147; silk_NLSF_CB1_WB_Q8ptr[10] = 162; silk_NLSF_CB1_WB_Q8ptr[11] = 178;
        silk_NLSF_CB1_WB_Q8ptr[12] = 193; silk_NLSF_CB1_WB_Q8ptr[13] = 208; silk_NLSF_CB1_WB_Q8ptr[14] = 223; silk_NLSF_CB1_WB_Q8ptr[15] = 239;
        silk_NLSF_CB1_WB_Q8ptr[16] = 13; silk_NLSF_CB1_WB_Q8ptr[17] = 25; silk_NLSF_CB1_WB_Q8ptr[18] = 41; silk_NLSF_CB1_WB_Q8ptr[19] = 55;
        silk_NLSF_CB1_WB_Q8ptr[20] = 69; silk_NLSF_CB1_WB_Q8ptr[21] = 83; silk_NLSF_CB1_WB_Q8ptr[22] = 98; silk_NLSF_CB1_WB_Q8ptr[23] = 112;
        silk_NLSF_CB1_WB_Q8ptr[24] = 127; silk_NLSF_CB1_WB_Q8ptr[25] = 142; silk_NLSF_CB1_WB_Q8ptr[26] = 157; silk_NLSF_CB1_WB_Q8ptr[27] = 171;
        silk_NLSF_CB1_WB_Q8ptr[28] = 187; silk_NLSF_CB1_WB_Q8ptr[29] = 203; silk_NLSF_CB1_WB_Q8ptr[30] = 220; silk_NLSF_CB1_WB_Q8ptr[31] = 236;
        silk_NLSF_CB1_WB_Q8ptr[32] = 15; silk_NLSF_CB1_WB_Q8ptr[33] = 21; silk_NLSF_CB1_WB_Q8ptr[34] = 34; silk_NLSF_CB1_WB_Q8ptr[35] = 51;
        silk_NLSF_CB1_WB_Q8ptr[36] = 61; silk_NLSF_CB1_WB_Q8ptr[37] = 78; silk_NLSF_CB1_WB_Q8ptr[38] = 92; silk_NLSF_CB1_WB_Q8ptr[39] = 106;
        silk_NLSF_CB1_WB_Q8ptr[40] = 126; silk_NLSF_CB1_WB_Q8ptr[41] = 136; silk_NLSF_CB1_WB_Q8ptr[42] = 152; silk_NLSF_CB1_WB_Q8ptr[43] = 167;
        silk_NLSF_CB1_WB_Q8ptr[44] = 185; silk_NLSF_CB1_WB_Q8ptr[45] = 205; silk_NLSF_CB1_WB_Q8ptr[46] = 225; silk_NLSF_CB1_WB_Q8ptr[47] = 240;
        silk_NLSF_CB1_WB_Q8ptr[48] = 10; silk_NLSF_CB1_WB_Q8ptr[49] = 21; silk_NLSF_CB1_WB_Q8ptr[50] = 36; silk_NLSF_CB1_WB_Q8ptr[51] = 50;
        silk_NLSF_CB1_WB_Q8ptr[52] = 63; silk_NLSF_CB1_WB_Q8ptr[53] = 79; silk_NLSF_CB1_WB_Q8ptr[54] = 95; silk_NLSF_CB1_WB_Q8ptr[55] = 110;
        silk_NLSF_CB1_WB_Q8ptr[56] = 126; silk_NLSF_CB1_WB_Q8ptr[57] = 141; silk_NLSF_CB1_WB_Q8ptr[58] = 157; silk_NLSF_CB1_WB_Q8ptr[59] = 173;
        silk_NLSF_CB1_WB_Q8ptr[60] = 189; silk_NLSF_CB1_WB_Q8ptr[61] = 205; silk_NLSF_CB1_WB_Q8ptr[62] = 221; silk_NLSF_CB1_WB_Q8ptr[63] = 237;
        silk_NLSF_CB1_WB_Q8ptr[64] = 17; silk_NLSF_CB1_WB_Q8ptr[65] = 20; silk_NLSF_CB1_WB_Q8ptr[66] = 37; silk_NLSF_CB1_WB_Q8ptr[67] = 51;
        silk_NLSF_CB1_WB_Q8ptr[68] = 59; silk_NLSF_CB1_WB_Q8ptr[69] = 78; silk_NLSF_CB1_WB_Q8ptr[70] = 89; silk_NLSF_CB1_WB_Q8ptr[71] = 107;
        silk_NLSF_CB1_WB_Q8ptr[72] = 123; silk_NLSF_CB1_WB_Q8ptr[73] = 134; silk_NLSF_CB1_WB_Q8ptr[74] = 150; silk_NLSF_CB1_WB_Q8ptr[75] = 164;
        silk_NLSF_CB1_WB_Q8ptr[76] = 184; silk_NLSF_CB1_WB_Q8ptr[77] = 205; silk_NLSF_CB1_WB_Q8ptr[78] = 224; silk_NLSF_CB1_WB_Q8ptr[79] = 240;
        silk_NLSF_CB1_WB_Q8ptr[80] = 10; silk_NLSF_CB1_WB_Q8ptr[81] = 15; silk_NLSF_CB1_WB_Q8ptr[82] = 32; silk_NLSF_CB1_WB_Q8ptr[83] = 51;
        silk_NLSF_CB1_WB_Q8ptr[84] = 67; silk_NLSF_CB1_WB_Q8ptr[85] = 81; silk_NLSF_CB1_WB_Q8ptr[86] = 96; silk_NLSF_CB1_WB_Q8ptr[87] = 112;
        silk_NLSF_CB1_WB_Q8ptr[88] = 129; silk_NLSF_CB1_WB_Q8ptr[89] = 142; silk_NLSF_CB1_WB_Q8ptr[90] = 158; silk_NLSF_CB1_WB_Q8ptr[91] = 173;
        silk_NLSF_CB1_WB_Q8ptr[92] = 189; silk_NLSF_CB1_WB_Q8ptr[93] = 204; silk_NLSF_CB1_WB_Q8ptr[94] = 220; silk_NLSF_CB1_WB_Q8ptr[95] = 236;
        silk_NLSF_CB1_WB_Q8ptr[96] = 8; silk_NLSF_CB1_WB_Q8ptr[97] = 21; silk_NLSF_CB1_WB_Q8ptr[98] = 37; silk_NLSF_CB1_WB_Q8ptr[99] = 51;
        silk_NLSF_CB1_WB_Q8ptr[100] = 65; silk_NLSF_CB1_WB_Q8ptr[101] = 79; silk_NLSF_CB1_WB_Q8ptr[102] = 98; silk_NLSF_CB1_WB_Q8ptr[103] = 113;
        silk_NLSF_CB1_WB_Q8ptr[104] = 126; silk_NLSF_CB1_WB_Q8ptr[105] = 138; silk_NLSF_CB1_WB_Q8ptr[106] = 155; silk_NLSF_CB1_WB_Q8ptr[107] = 168;
        silk_NLSF_CB1_WB_Q8ptr[108] = 179; silk_NLSF_CB1_WB_Q8ptr[109] = 192; silk_NLSF_CB1_WB_Q8ptr[110] = 209; silk_NLSF_CB1_WB_Q8ptr[111] = 218;
        silk_NLSF_CB1_WB_Q8ptr[112] = 12; silk_NLSF_CB1_WB_Q8ptr[113] = 15; silk_NLSF_CB1_WB_Q8ptr[114] = 34; silk_NLSF_CB1_WB_Q8ptr[115] = 55;
        silk_NLSF_CB1_WB_Q8ptr[116] = 63; silk_NLSF_CB1_WB_Q8ptr[117] = 78; silk_NLSF_CB1_WB_Q8ptr[118] = 87; silk_NLSF_CB1_WB_Q8ptr[119] = 108;
        silk_NLSF_CB1_WB_Q8ptr[120] = 118; silk_NLSF_CB1_WB_Q8ptr[121] = 131; silk_NLSF_CB1_WB_Q8ptr[122] = 148; silk_NLSF_CB1_WB_Q8ptr[123] = 167;
        silk_NLSF_CB1_WB_Q8ptr[124] = 185; silk_NLSF_CB1_WB_Q8ptr[125] = 203; silk_NLSF_CB1_WB_Q8ptr[126] = 219; silk_NLSF_CB1_WB_Q8ptr[127] = 236;
        silk_NLSF_CB1_WB_Q8ptr[128] = 16; silk_NLSF_CB1_WB_Q8ptr[129] = 19; silk_NLSF_CB1_WB_Q8ptr[130] = 32; silk_NLSF_CB1_WB_Q8ptr[131] = 36;
        silk_NLSF_CB1_WB_Q8ptr[132] = 56; silk_NLSF_CB1_WB_Q8ptr[133] = 79; silk_NLSF_CB1_WB_Q8ptr[134] = 91; silk_NLSF_CB1_WB_Q8ptr[135] = 108;
        silk_NLSF_CB1_WB_Q8ptr[136] = 118; silk_NLSF_CB1_WB_Q8ptr[137] = 136; silk_NLSF_CB1_WB_Q8ptr[138] = 154; silk_NLSF_CB1_WB_Q8ptr[139] = 171;
        silk_NLSF_CB1_WB_Q8ptr[140] = 186; silk_NLSF_CB1_WB_Q8ptr[141] = 204; silk_NLSF_CB1_WB_Q8ptr[142] = 220; silk_NLSF_CB1_WB_Q8ptr[143] = 237;
        silk_NLSF_CB1_WB_Q8ptr[144] = 11; silk_NLSF_CB1_WB_Q8ptr[145] = 28; silk_NLSF_CB1_WB_Q8ptr[146] = 43; silk_NLSF_CB1_WB_Q8ptr[147] = 58;
        silk_NLSF_CB1_WB_Q8ptr[148] = 74; silk_NLSF_CB1_WB_Q8ptr[149] = 89; silk_NLSF_CB1_WB_Q8ptr[150] = 105; silk_NLSF_CB1_WB_Q8ptr[151] = 120;
        silk_NLSF_CB1_WB_Q8ptr[152] = 135; silk_NLSF_CB1_WB_Q8ptr[153] = 150; silk_NLSF_CB1_WB_Q8ptr[154] = 165; silk_NLSF_CB1_WB_Q8ptr[155] = 180;
        silk_NLSF_CB1_WB_Q8ptr[156] = 196; silk_NLSF_CB1_WB_Q8ptr[157] = 211; silk_NLSF_CB1_WB_Q8ptr[158] = 226; silk_NLSF_CB1_WB_Q8ptr[159] = 241;
        silk_NLSF_CB1_WB_Q8ptr[160] = 6; silk_NLSF_CB1_WB_Q8ptr[161] = 16; silk_NLSF_CB1_WB_Q8ptr[162] = 33; silk_NLSF_CB1_WB_Q8ptr[163] = 46;
        silk_NLSF_CB1_WB_Q8ptr[164] = 60; silk_NLSF_CB1_WB_Q8ptr[165] = 75; silk_NLSF_CB1_WB_Q8ptr[166] = 92; silk_NLSF_CB1_WB_Q8ptr[167] = 107;
        silk_NLSF_CB1_WB_Q8ptr[168] = 123; silk_NLSF_CB1_WB_Q8ptr[169] = 137; silk_NLSF_CB1_WB_Q8ptr[170] = 156; silk_NLSF_CB1_WB_Q8ptr[171] = 169;
        silk_NLSF_CB1_WB_Q8ptr[172] = 185; silk_NLSF_CB1_WB_Q8ptr[173] = 199; silk_NLSF_CB1_WB_Q8ptr[174] = 214; silk_NLSF_CB1_WB_Q8ptr[175] = 225;
        silk_NLSF_CB1_WB_Q8ptr[176] = 11; silk_NLSF_CB1_WB_Q8ptr[177] = 19; silk_NLSF_CB1_WB_Q8ptr[178] = 30; silk_NLSF_CB1_WB_Q8ptr[179] = 44;
        silk_NLSF_CB1_WB_Q8ptr[180] = 57; silk_NLSF_CB1_WB_Q8ptr[181] = 74; silk_NLSF_CB1_WB_Q8ptr[182] = 89; silk_NLSF_CB1_WB_Q8ptr[183] = 105;
        silk_NLSF_CB1_WB_Q8ptr[184] = 121; silk_NLSF_CB1_WB_Q8ptr[185] = 135; silk_NLSF_CB1_WB_Q8ptr[186] = 152; silk_NLSF_CB1_WB_Q8ptr[187] = 169;
        silk_NLSF_CB1_WB_Q8ptr[188] = 186; silk_NLSF_CB1_WB_Q8ptr[189] = 202; silk_NLSF_CB1_WB_Q8ptr[190] = 218; silk_NLSF_CB1_WB_Q8ptr[191] = 234;
        silk_NLSF_CB1_WB_Q8ptr[192] = 12; silk_NLSF_CB1_WB_Q8ptr[193] = 19; silk_NLSF_CB1_WB_Q8ptr[194] = 29; silk_NLSF_CB1_WB_Q8ptr[195] = 46;
        silk_NLSF_CB1_WB_Q8ptr[196] = 57; silk_NLSF_CB1_WB_Q8ptr[197] = 71; silk_NLSF_CB1_WB_Q8ptr[198] = 88; silk_NLSF_CB1_WB_Q8ptr[199] = 100;
        silk_NLSF_CB1_WB_Q8ptr[200] = 120; silk_NLSF_CB1_WB_Q8ptr[201] = 132; silk_NLSF_CB1_WB_Q8ptr[202] = 148; silk_NLSF_CB1_WB_Q8ptr[203] = 165;
        silk_NLSF_CB1_WB_Q8ptr[204] = 182; silk_NLSF_CB1_WB_Q8ptr[205] = 199; silk_NLSF_CB1_WB_Q8ptr[206] = 216; silk_NLSF_CB1_WB_Q8ptr[207] = 233;
        silk_NLSF_CB1_WB_Q8ptr[208] = 17; silk_NLSF_CB1_WB_Q8ptr[209] = 23; silk_NLSF_CB1_WB_Q8ptr[210] = 35; silk_NLSF_CB1_WB_Q8ptr[211] = 46;
        silk_NLSF_CB1_WB_Q8ptr[212] = 56; silk_NLSF_CB1_WB_Q8ptr[213] = 77; silk_NLSF_CB1_WB_Q8ptr[214] = 92; silk_NLSF_CB1_WB_Q8ptr[215] = 106;
        silk_NLSF_CB1_WB_Q8ptr[216] = 123; silk_NLSF_CB1_WB_Q8ptr[217] = 134; silk_NLSF_CB1_WB_Q8ptr[218] = 152; silk_NLSF_CB1_WB_Q8ptr[219] = 167;
        silk_NLSF_CB1_WB_Q8ptr[220] = 185; silk_NLSF_CB1_WB_Q8ptr[221] = 204; silk_NLSF_CB1_WB_Q8ptr[222] = 222; silk_NLSF_CB1_WB_Q8ptr[223] = 237;
        silk_NLSF_CB1_WB_Q8ptr[224] = 14; silk_NLSF_CB1_WB_Q8ptr[225] = 17; silk_NLSF_CB1_WB_Q8ptr[226] = 45; silk_NLSF_CB1_WB_Q8ptr[227] = 53;
        silk_NLSF_CB1_WB_Q8ptr[228] = 63; silk_NLSF_CB1_WB_Q8ptr[229] = 75; silk_NLSF_CB1_WB_Q8ptr[230] = 89; silk_NLSF_CB1_WB_Q8ptr[231] = 107;
        silk_NLSF_CB1_WB_Q8ptr[232] = 115; silk_NLSF_CB1_WB_Q8ptr[233] = 132; silk_NLSF_CB1_WB_Q8ptr[234] = 151; silk_NLSF_CB1_WB_Q8ptr[235] = 171;
        silk_NLSF_CB1_WB_Q8ptr[236] = 188; silk_NLSF_CB1_WB_Q8ptr[237] = 206; silk_NLSF_CB1_WB_Q8ptr[238] = 221; silk_NLSF_CB1_WB_Q8ptr[239] = 240;
        silk_NLSF_CB1_WB_Q8ptr[240] = 9; silk_NLSF_CB1_WB_Q8ptr[241] = 16; silk_NLSF_CB1_WB_Q8ptr[242] = 29; silk_NLSF_CB1_WB_Q8ptr[243] = 40;
        silk_NLSF_CB1_WB_Q8ptr[244] = 56; silk_NLSF_CB1_WB_Q8ptr[245] = 71; silk_NLSF_CB1_WB_Q8ptr[246] = 88; silk_NLSF_CB1_WB_Q8ptr[247] = 103;
        silk_NLSF_CB1_WB_Q8ptr[248] = 119; silk_NLSF_CB1_WB_Q8ptr[249] = 137; silk_NLSF_CB1_WB_Q8ptr[250] = 154; silk_NLSF_CB1_WB_Q8ptr[251] = 171;
        silk_NLSF_CB1_WB_Q8ptr[252] = 189; silk_NLSF_CB1_WB_Q8ptr[253] = 205; silk_NLSF_CB1_WB_Q8ptr[254] = 222; silk_NLSF_CB1_WB_Q8ptr[255] = 237;
        silk_NLSF_CB1_WB_Q8ptr[256] = 16; silk_NLSF_CB1_WB_Q8ptr[257] = 19; silk_NLSF_CB1_WB_Q8ptr[258] = 36; silk_NLSF_CB1_WB_Q8ptr[259] = 48;
        silk_NLSF_CB1_WB_Q8ptr[260] = 57; silk_NLSF_CB1_WB_Q8ptr[261] = 76; silk_NLSF_CB1_WB_Q8ptr[262] = 87; silk_NLSF_CB1_WB_Q8ptr[263] = 105;
        silk_NLSF_CB1_WB_Q8ptr[264] = 118; silk_NLSF_CB1_WB_Q8ptr[265] = 132; silk_NLSF_CB1_WB_Q8ptr[266] = 150; silk_NLSF_CB1_WB_Q8ptr[267] = 167;
        silk_NLSF_CB1_WB_Q8ptr[268] = 185; silk_NLSF_CB1_WB_Q8ptr[269] = 202; silk_NLSF_CB1_WB_Q8ptr[270] = 218; silk_NLSF_CB1_WB_Q8ptr[271] = 236;
        silk_NLSF_CB1_WB_Q8ptr[272] = 12; silk_NLSF_CB1_WB_Q8ptr[273] = 17; silk_NLSF_CB1_WB_Q8ptr[274] = 29; silk_NLSF_CB1_WB_Q8ptr[275] = 54;
        silk_NLSF_CB1_WB_Q8ptr[276] = 71; silk_NLSF_CB1_WB_Q8ptr[277] = 81; silk_NLSF_CB1_WB_Q8ptr[278] = 94; silk_NLSF_CB1_WB_Q8ptr[279] = 104;
        silk_NLSF_CB1_WB_Q8ptr[280] = 126; silk_NLSF_CB1_WB_Q8ptr[281] = 136; silk_NLSF_CB1_WB_Q8ptr[282] = 149; silk_NLSF_CB1_WB_Q8ptr[283] = 164;
        silk_NLSF_CB1_WB_Q8ptr[284] = 182; silk_NLSF_CB1_WB_Q8ptr[285] = 201; silk_NLSF_CB1_WB_Q8ptr[286] = 221; silk_NLSF_CB1_WB_Q8ptr[287] = 237;
        silk_NLSF_CB1_WB_Q8ptr[288] = 15; silk_NLSF_CB1_WB_Q8ptr[289] = 28; silk_NLSF_CB1_WB_Q8ptr[290] = 47; silk_NLSF_CB1_WB_Q8ptr[291] = 62;
        silk_NLSF_CB1_WB_Q8ptr[292] = 79; silk_NLSF_CB1_WB_Q8ptr[293] = 97; silk_NLSF_CB1_WB_Q8ptr[294] = 115; silk_NLSF_CB1_WB_Q8ptr[295] = 129;
        silk_NLSF_CB1_WB_Q8ptr[296] = 142; silk_NLSF_CB1_WB_Q8ptr[297] = 155; silk_NLSF_CB1_WB_Q8ptr[298] = 168; silk_NLSF_CB1_WB_Q8ptr[299] = 180;
        silk_NLSF_CB1_WB_Q8ptr[300] = 194; silk_NLSF_CB1_WB_Q8ptr[301] = 208; silk_NLSF_CB1_WB_Q8ptr[302] = 223; silk_NLSF_CB1_WB_Q8ptr[303] = 238;
        silk_NLSF_CB1_WB_Q8ptr[304] = 8; silk_NLSF_CB1_WB_Q8ptr[305] = 14; silk_NLSF_CB1_WB_Q8ptr[306] = 30; silk_NLSF_CB1_WB_Q8ptr[307] = 45;
        silk_NLSF_CB1_WB_Q8ptr[308] = 62; silk_NLSF_CB1_WB_Q8ptr[309] = 78; silk_NLSF_CB1_WB_Q8ptr[310] = 94; silk_NLSF_CB1_WB_Q8ptr[311] = 111;
        silk_NLSF_CB1_WB_Q8ptr[312] = 127; silk_NLSF_CB1_WB_Q8ptr[313] = 143; silk_NLSF_CB1_WB_Q8ptr[314] = 159; silk_NLSF_CB1_WB_Q8ptr[315] = 175;
        silk_NLSF_CB1_WB_Q8ptr[316] = 192; silk_NLSF_CB1_WB_Q8ptr[317] = 207; silk_NLSF_CB1_WB_Q8ptr[318] = 223; silk_NLSF_CB1_WB_Q8ptr[319] = 239;
        silk_NLSF_CB1_WB_Q8ptr[320] = 17; silk_NLSF_CB1_WB_Q8ptr[321] = 30; silk_NLSF_CB1_WB_Q8ptr[322] = 49; silk_NLSF_CB1_WB_Q8ptr[323] = 62;
        silk_NLSF_CB1_WB_Q8ptr[324] = 79; silk_NLSF_CB1_WB_Q8ptr[325] = 92; silk_NLSF_CB1_WB_Q8ptr[326] = 107; silk_NLSF_CB1_WB_Q8ptr[327] = 119;
        silk_NLSF_CB1_WB_Q8ptr[328] = 132; silk_NLSF_CB1_WB_Q8ptr[329] = 145; silk_NLSF_CB1_WB_Q8ptr[330] = 160; silk_NLSF_CB1_WB_Q8ptr[331] = 174;
        silk_NLSF_CB1_WB_Q8ptr[332] = 190; silk_NLSF_CB1_WB_Q8ptr[333] = 204; silk_NLSF_CB1_WB_Q8ptr[334] = 220; silk_NLSF_CB1_WB_Q8ptr[335] = 235;
        silk_NLSF_CB1_WB_Q8ptr[336] = 14; silk_NLSF_CB1_WB_Q8ptr[337] = 19; silk_NLSF_CB1_WB_Q8ptr[338] = 36; silk_NLSF_CB1_WB_Q8ptr[339] = 45;
        silk_NLSF_CB1_WB_Q8ptr[340] = 61; silk_NLSF_CB1_WB_Q8ptr[341] = 76; silk_NLSF_CB1_WB_Q8ptr[342] = 91; silk_NLSF_CB1_WB_Q8ptr[343] = 108;
        silk_NLSF_CB1_WB_Q8ptr[344] = 121; silk_NLSF_CB1_WB_Q8ptr[345] = 138; silk_NLSF_CB1_WB_Q8ptr[346] = 154; silk_NLSF_CB1_WB_Q8ptr[347] = 172;
        silk_NLSF_CB1_WB_Q8ptr[348] = 189; silk_NLSF_CB1_WB_Q8ptr[349] = 205; silk_NLSF_CB1_WB_Q8ptr[350] = 222; silk_NLSF_CB1_WB_Q8ptr[351] = 238;
        silk_NLSF_CB1_WB_Q8ptr[352] = 12; silk_NLSF_CB1_WB_Q8ptr[353] = 18; silk_NLSF_CB1_WB_Q8ptr[354] = 31; silk_NLSF_CB1_WB_Q8ptr[355] = 45;
        silk_NLSF_CB1_WB_Q8ptr[356] = 60; silk_NLSF_CB1_WB_Q8ptr[357] = 76; silk_NLSF_CB1_WB_Q8ptr[358] = 91; silk_NLSF_CB1_WB_Q8ptr[359] = 107;
        silk_NLSF_CB1_WB_Q8ptr[360] = 123; silk_NLSF_CB1_WB_Q8ptr[361] = 138; silk_NLSF_CB1_WB_Q8ptr[362] = 154; silk_NLSF_CB1_WB_Q8ptr[363] = 171;
        silk_NLSF_CB1_WB_Q8ptr[364] = 187; silk_NLSF_CB1_WB_Q8ptr[365] = 204; silk_NLSF_CB1_WB_Q8ptr[366] = 221; silk_NLSF_CB1_WB_Q8ptr[367] = 236;
        silk_NLSF_CB1_WB_Q8ptr[368] = 13; silk_NLSF_CB1_WB_Q8ptr[369] = 17; silk_NLSF_CB1_WB_Q8ptr[370] = 31; silk_NLSF_CB1_WB_Q8ptr[371] = 43;
        silk_NLSF_CB1_WB_Q8ptr[372] = 53; silk_NLSF_CB1_WB_Q8ptr[373] = 70; silk_NLSF_CB1_WB_Q8ptr[374] = 83; silk_NLSF_CB1_WB_Q8ptr[375] = 103;
        silk_NLSF_CB1_WB_Q8ptr[376] = 114; silk_NLSF_CB1_WB_Q8ptr[377] = 131; silk_NLSF_CB1_WB_Q8ptr[378] = 149; silk_NLSF_CB1_WB_Q8ptr[379] = 167;
        silk_NLSF_CB1_WB_Q8ptr[380] = 185; silk_NLSF_CB1_WB_Q8ptr[381] = 203; silk_NLSF_CB1_WB_Q8ptr[382] = 220; silk_NLSF_CB1_WB_Q8ptr[383] = 237;
        silk_NLSF_CB1_WB_Q8ptr[384] = 17; silk_NLSF_CB1_WB_Q8ptr[385] = 22; silk_NLSF_CB1_WB_Q8ptr[386] = 35; silk_NLSF_CB1_WB_Q8ptr[387] = 42;
        silk_NLSF_CB1_WB_Q8ptr[388] = 58; silk_NLSF_CB1_WB_Q8ptr[389] = 78; silk_NLSF_CB1_WB_Q8ptr[390] = 93; silk_NLSF_CB1_WB_Q8ptr[391] = 110;
        silk_NLSF_CB1_WB_Q8ptr[392] = 125; silk_NLSF_CB1_WB_Q8ptr[393] = 139; silk_NLSF_CB1_WB_Q8ptr[394] = 155; silk_NLSF_CB1_WB_Q8ptr[395] = 170;
        silk_NLSF_CB1_WB_Q8ptr[396] = 188; silk_NLSF_CB1_WB_Q8ptr[397] = 206; silk_NLSF_CB1_WB_Q8ptr[398] = 224; silk_NLSF_CB1_WB_Q8ptr[399] = 240;
        silk_NLSF_CB1_WB_Q8ptr[400] = 8; silk_NLSF_CB1_WB_Q8ptr[401] = 15; silk_NLSF_CB1_WB_Q8ptr[402] = 34; silk_NLSF_CB1_WB_Q8ptr[403] = 50;
        silk_NLSF_CB1_WB_Q8ptr[404] = 67; silk_NLSF_CB1_WB_Q8ptr[405] = 83; silk_NLSF_CB1_WB_Q8ptr[406] = 99; silk_NLSF_CB1_WB_Q8ptr[407] = 115;
        silk_NLSF_CB1_WB_Q8ptr[408] = 131; silk_NLSF_CB1_WB_Q8ptr[409] = 146; silk_NLSF_CB1_WB_Q8ptr[410] = 162; silk_NLSF_CB1_WB_Q8ptr[411] = 178;
        silk_NLSF_CB1_WB_Q8ptr[412] = 193; silk_NLSF_CB1_WB_Q8ptr[413] = 209; silk_NLSF_CB1_WB_Q8ptr[414] = 224; silk_NLSF_CB1_WB_Q8ptr[415] = 239;
        silk_NLSF_CB1_WB_Q8ptr[416] = 13; silk_NLSF_CB1_WB_Q8ptr[417] = 16; silk_NLSF_CB1_WB_Q8ptr[418] = 41; silk_NLSF_CB1_WB_Q8ptr[419] = 66;
        silk_NLSF_CB1_WB_Q8ptr[420] = 73; silk_NLSF_CB1_WB_Q8ptr[421] = 86; silk_NLSF_CB1_WB_Q8ptr[422] = 95; silk_NLSF_CB1_WB_Q8ptr[423] = 111;
        silk_NLSF_CB1_WB_Q8ptr[424] = 128; silk_NLSF_CB1_WB_Q8ptr[425] = 137; silk_NLSF_CB1_WB_Q8ptr[426] = 150; silk_NLSF_CB1_WB_Q8ptr[427] = 163;
        silk_NLSF_CB1_WB_Q8ptr[428] = 183; silk_NLSF_CB1_WB_Q8ptr[429] = 206; silk_NLSF_CB1_WB_Q8ptr[430] = 225; silk_NLSF_CB1_WB_Q8ptr[431] = 241;
        silk_NLSF_CB1_WB_Q8ptr[432] = 17; silk_NLSF_CB1_WB_Q8ptr[433] = 25; silk_NLSF_CB1_WB_Q8ptr[434] = 37; silk_NLSF_CB1_WB_Q8ptr[435] = 52;
        silk_NLSF_CB1_WB_Q8ptr[436] = 63; silk_NLSF_CB1_WB_Q8ptr[437] = 75; silk_NLSF_CB1_WB_Q8ptr[438] = 92; silk_NLSF_CB1_WB_Q8ptr[439] = 102;
        silk_NLSF_CB1_WB_Q8ptr[440] = 119; silk_NLSF_CB1_WB_Q8ptr[441] = 132; silk_NLSF_CB1_WB_Q8ptr[442] = 144; silk_NLSF_CB1_WB_Q8ptr[443] = 160;
        silk_NLSF_CB1_WB_Q8ptr[444] = 175; silk_NLSF_CB1_WB_Q8ptr[445] = 191; silk_NLSF_CB1_WB_Q8ptr[446] = 212; silk_NLSF_CB1_WB_Q8ptr[447] = 231;
        silk_NLSF_CB1_WB_Q8ptr[448] = 19; silk_NLSF_CB1_WB_Q8ptr[449] = 31; silk_NLSF_CB1_WB_Q8ptr[450] = 49; silk_NLSF_CB1_WB_Q8ptr[451] = 65;
        silk_NLSF_CB1_WB_Q8ptr[452] = 83; silk_NLSF_CB1_WB_Q8ptr[453] = 100; silk_NLSF_CB1_WB_Q8ptr[454] = 117; silk_NLSF_CB1_WB_Q8ptr[455] = 133;
        silk_NLSF_CB1_WB_Q8ptr[456] = 147; silk_NLSF_CB1_WB_Q8ptr[457] = 161; silk_NLSF_CB1_WB_Q8ptr[458] = 174; silk_NLSF_CB1_WB_Q8ptr[459] = 187;
        silk_NLSF_CB1_WB_Q8ptr[460] = 200; silk_NLSF_CB1_WB_Q8ptr[461] = 213; silk_NLSF_CB1_WB_Q8ptr[462] = 227; silk_NLSF_CB1_WB_Q8ptr[463] = 242;
        silk_NLSF_CB1_WB_Q8ptr[464] = 18; silk_NLSF_CB1_WB_Q8ptr[465] = 31; silk_NLSF_CB1_WB_Q8ptr[466] = 52; silk_NLSF_CB1_WB_Q8ptr[467] = 68;
        silk_NLSF_CB1_WB_Q8ptr[468] = 88; silk_NLSF_CB1_WB_Q8ptr[469] = 103; silk_NLSF_CB1_WB_Q8ptr[470] = 117; silk_NLSF_CB1_WB_Q8ptr[471] = 126;
        silk_NLSF_CB1_WB_Q8ptr[472] = 138; silk_NLSF_CB1_WB_Q8ptr[473] = 149; silk_NLSF_CB1_WB_Q8ptr[474] = 163; silk_NLSF_CB1_WB_Q8ptr[475] = 177;
        silk_NLSF_CB1_WB_Q8ptr[476] = 192; silk_NLSF_CB1_WB_Q8ptr[477] = 207; silk_NLSF_CB1_WB_Q8ptr[478] = 223; silk_NLSF_CB1_WB_Q8ptr[479] = 239;
        silk_NLSF_CB1_WB_Q8ptr[480] = 16; silk_NLSF_CB1_WB_Q8ptr[481] = 29; silk_NLSF_CB1_WB_Q8ptr[482] = 47; silk_NLSF_CB1_WB_Q8ptr[483] = 61;
        silk_NLSF_CB1_WB_Q8ptr[484] = 76; silk_NLSF_CB1_WB_Q8ptr[485] = 90; silk_NLSF_CB1_WB_Q8ptr[486] = 106; silk_NLSF_CB1_WB_Q8ptr[487] = 119;
        silk_NLSF_CB1_WB_Q8ptr[488] = 133; silk_NLSF_CB1_WB_Q8ptr[489] = 147; silk_NLSF_CB1_WB_Q8ptr[490] = 161; silk_NLSF_CB1_WB_Q8ptr[491] = 176;
        silk_NLSF_CB1_WB_Q8ptr[492] = 193; silk_NLSF_CB1_WB_Q8ptr[493] = 209; silk_NLSF_CB1_WB_Q8ptr[494] = 224; silk_NLSF_CB1_WB_Q8ptr[495] = 240;
        silk_NLSF_CB1_WB_Q8ptr[496] = 15; silk_NLSF_CB1_WB_Q8ptr[497] = 21; silk_NLSF_CB1_WB_Q8ptr[498] = 35; silk_NLSF_CB1_WB_Q8ptr[499] = 50;
        silk_NLSF_CB1_WB_Q8ptr[500] = 61; silk_NLSF_CB1_WB_Q8ptr[501] = 73; silk_NLSF_CB1_WB_Q8ptr[502] = 86; silk_NLSF_CB1_WB_Q8ptr[503] = 97;
        silk_NLSF_CB1_WB_Q8ptr[504] = 110; silk_NLSF_CB1_WB_Q8ptr[505] = 119; silk_NLSF_CB1_WB_Q8ptr[506] = 129; silk_NLSF_CB1_WB_Q8ptr[507] = 141;
        silk_NLSF_CB1_WB_Q8ptr[508] = 175; silk_NLSF_CB1_WB_Q8ptr[509] = 198; silk_NLSF_CB1_WB_Q8ptr[510] = 218; silk_NLSF_CB1_WB_Q8ptr[511] = 237;

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


        opus_uint8 *silk_NLSF_CB1_iCDF_WBptr = malloc(sizeof(opus_uint8) * 64);
        silk_NLSF_CB1_iCDF_WBptr[0] = 225; silk_NLSF_CB1_iCDF_WBptr[1] = 204; silk_NLSF_CB1_iCDF_WBptr[2] = 201; silk_NLSF_CB1_iCDF_WBptr[3] = 184;
        silk_NLSF_CB1_iCDF_WBptr[4] = 183; silk_NLSF_CB1_iCDF_WBptr[5] = 175; silk_NLSF_CB1_iCDF_WBptr[6] = 158; silk_NLSF_CB1_iCDF_WBptr[7] = 154;
        silk_NLSF_CB1_iCDF_WBptr[8] = 153; silk_NLSF_CB1_iCDF_WBptr[9] = 135; silk_NLSF_CB1_iCDF_WBptr[10] = 119; silk_NLSF_CB1_iCDF_WBptr[11] = 115;
        silk_NLSF_CB1_iCDF_WBptr[12] = 113; silk_NLSF_CB1_iCDF_WBptr[13] = 110; silk_NLSF_CB1_iCDF_WBptr[14] = 109; silk_NLSF_CB1_iCDF_WBptr[15] = 99;
        silk_NLSF_CB1_iCDF_WBptr[16] = 98; silk_NLSF_CB1_iCDF_WBptr[17] = 95; silk_NLSF_CB1_iCDF_WBptr[18] = 79; silk_NLSF_CB1_iCDF_WBptr[19] = 68;
        silk_NLSF_CB1_iCDF_WBptr[20] = 52; silk_NLSF_CB1_iCDF_WBptr[21] = 50; silk_NLSF_CB1_iCDF_WBptr[22] = 48; silk_NLSF_CB1_iCDF_WBptr[23] = 45;
        silk_NLSF_CB1_iCDF_WBptr[24] = 43; silk_NLSF_CB1_iCDF_WBptr[25] = 32; silk_NLSF_CB1_iCDF_WBptr[26] = 31; silk_NLSF_CB1_iCDF_WBptr[27] = 27;
        silk_NLSF_CB1_iCDF_WBptr[28] = 18; silk_NLSF_CB1_iCDF_WBptr[29] = 10; silk_NLSF_CB1_iCDF_WBptr[30] = 3; silk_NLSF_CB1_iCDF_WBptr[31] = 0;
        silk_NLSF_CB1_iCDF_WBptr[32] = 255; silk_NLSF_CB1_iCDF_WBptr[33] = 251; silk_NLSF_CB1_iCDF_WBptr[34] = 235; silk_NLSF_CB1_iCDF_WBptr[35] = 230;
        silk_NLSF_CB1_iCDF_WBptr[36] = 212; silk_NLSF_CB1_iCDF_WBptr[37] = 201; silk_NLSF_CB1_iCDF_WBptr[38] = 196; silk_NLSF_CB1_iCDF_WBptr[39] = 182;
        silk_NLSF_CB1_iCDF_WBptr[40] = 167; silk_NLSF_CB1_iCDF_WBptr[41] = 166; silk_NLSF_CB1_iCDF_WBptr[42] = 163; silk_NLSF_CB1_iCDF_WBptr[43] = 151;
        silk_NLSF_CB1_iCDF_WBptr[44] = 138; silk_NLSF_CB1_iCDF_WBptr[45] = 124; silk_NLSF_CB1_iCDF_WBptr[46] = 110; silk_NLSF_CB1_iCDF_WBptr[47] = 104;
        silk_NLSF_CB1_iCDF_WBptr[48] = 90; silk_NLSF_CB1_iCDF_WBptr[49] = 78; silk_NLSF_CB1_iCDF_WBptr[50] = 76; silk_NLSF_CB1_iCDF_WBptr[51] = 70;
        silk_NLSF_CB1_iCDF_WBptr[52] = 69; silk_NLSF_CB1_iCDF_WBptr[53] = 57; silk_NLSF_CB1_iCDF_WBptr[54] = 45; silk_NLSF_CB1_iCDF_WBptr[55] = 34;
        silk_NLSF_CB1_iCDF_WBptr[56] = 24; silk_NLSF_CB1_iCDF_WBptr[57] = 21; silk_NLSF_CB1_iCDF_WBptr[58] = 11; silk_NLSF_CB1_iCDF_WBptr[59] = 6;
        silk_NLSF_CB1_iCDF_WBptr[60] = 5; silk_NLSF_CB1_iCDF_WBptr[61] = 4; silk_NLSF_CB1_iCDF_WBptr[62] = 3; silk_NLSF_CB1_iCDF_WBptr[63] = 0;

        opus_uint8 silk_NLSF_PRED_WB_Q8[ 30 ] = {
                175,    148,    160,    176,    178,    173,    174,    164,
                177,    174,    196,    182,    198,    192,    182,     68,
                62,     66,     60,     72,    117,     85,     90,    118,
                136,    151,    142,    160,    142,    155
        };
        opus_uint8 *silk_NLSF_PRED_WB_Q8ptr = malloc(sizeof(opus_uint8) * 30);
        memcpy(silk_NLSF_PRED_WB_Q8ptr, silk_NLSF_PRED_WB_Q8, 30);


        opus_uint8 *silk_NLSF_CB2_SELECT_WBptr = malloc(sizeof(opus_uint8) * 256);
        silk_NLSF_CB2_SELECT_WBptr[0] = 0; silk_NLSF_CB2_SELECT_WBptr[1] = 0; silk_NLSF_CB2_SELECT_WBptr[2] = 0; silk_NLSF_CB2_SELECT_WBptr[3] = 0;
        silk_NLSF_CB2_SELECT_WBptr[4] = 0; silk_NLSF_CB2_SELECT_WBptr[5] = 0; silk_NLSF_CB2_SELECT_WBptr[6] = 0; silk_NLSF_CB2_SELECT_WBptr[7] = 1;
        silk_NLSF_CB2_SELECT_WBptr[8] = 100; silk_NLSF_CB2_SELECT_WBptr[9] = 102; silk_NLSF_CB2_SELECT_WBptr[10] = 102; silk_NLSF_CB2_SELECT_WBptr[11] = 68;
        silk_NLSF_CB2_SELECT_WBptr[12] = 68; silk_NLSF_CB2_SELECT_WBptr[13] = 36; silk_NLSF_CB2_SELECT_WBptr[14] = 34; silk_NLSF_CB2_SELECT_WBptr[15] = 96;
        silk_NLSF_CB2_SELECT_WBptr[16] = 164; silk_NLSF_CB2_SELECT_WBptr[17] = 107; silk_NLSF_CB2_SELECT_WBptr[18] = 158; silk_NLSF_CB2_SELECT_WBptr[19] = 185;
        silk_NLSF_CB2_SELECT_WBptr[20] = 180; silk_NLSF_CB2_SELECT_WBptr[21] = 185; silk_NLSF_CB2_SELECT_WBptr[22] = 139; silk_NLSF_CB2_SELECT_WBptr[23] = 102;
        silk_NLSF_CB2_SELECT_WBptr[24] = 64; silk_NLSF_CB2_SELECT_WBptr[25] = 66; silk_NLSF_CB2_SELECT_WBptr[26] = 36; silk_NLSF_CB2_SELECT_WBptr[27] = 34;
        silk_NLSF_CB2_SELECT_WBptr[28] = 34; silk_NLSF_CB2_SELECT_WBptr[29] = 0; silk_NLSF_CB2_SELECT_WBptr[30] = 1; silk_NLSF_CB2_SELECT_WBptr[31] = 32;
        silk_NLSF_CB2_SELECT_WBptr[32] = 208; silk_NLSF_CB2_SELECT_WBptr[33] = 139; silk_NLSF_CB2_SELECT_WBptr[34] = 141; silk_NLSF_CB2_SELECT_WBptr[35] = 191;
        silk_NLSF_CB2_SELECT_WBptr[36] = 152; silk_NLSF_CB2_SELECT_WBptr[37] = 185; silk_NLSF_CB2_SELECT_WBptr[38] = 155; silk_NLSF_CB2_SELECT_WBptr[39] = 104;
        silk_NLSF_CB2_SELECT_WBptr[40] = 96; silk_NLSF_CB2_SELECT_WBptr[41] = 171; silk_NLSF_CB2_SELECT_WBptr[42] = 104; silk_NLSF_CB2_SELECT_WBptr[43] = 166;
        silk_NLSF_CB2_SELECT_WBptr[44] = 102; silk_NLSF_CB2_SELECT_WBptr[45] = 102; silk_NLSF_CB2_SELECT_WBptr[46] = 102; silk_NLSF_CB2_SELECT_WBptr[47] = 132;
        silk_NLSF_CB2_SELECT_WBptr[48] = 1; silk_NLSF_CB2_SELECT_WBptr[49] = 0; silk_NLSF_CB2_SELECT_WBptr[50] = 0; silk_NLSF_CB2_SELECT_WBptr[51] = 0;
        silk_NLSF_CB2_SELECT_WBptr[52] = 0; silk_NLSF_CB2_SELECT_WBptr[53] = 16; silk_NLSF_CB2_SELECT_WBptr[54] = 16; silk_NLSF_CB2_SELECT_WBptr[55] = 0;
        silk_NLSF_CB2_SELECT_WBptr[56] = 80; silk_NLSF_CB2_SELECT_WBptr[57] = 109; silk_NLSF_CB2_SELECT_WBptr[58] = 78; silk_NLSF_CB2_SELECT_WBptr[59] = 107;
        silk_NLSF_CB2_SELECT_WBptr[60] = 185; silk_NLSF_CB2_SELECT_WBptr[61] = 139; silk_NLSF_CB2_SELECT_WBptr[62] = 103; silk_NLSF_CB2_SELECT_WBptr[63] = 101;
        silk_NLSF_CB2_SELECT_WBptr[64] = 208; silk_NLSF_CB2_SELECT_WBptr[65] = 212; silk_NLSF_CB2_SELECT_WBptr[66] = 141; silk_NLSF_CB2_SELECT_WBptr[67] = 139;
        silk_NLSF_CB2_SELECT_WBptr[68] = 173; silk_NLSF_CB2_SELECT_WBptr[69] = 153; silk_NLSF_CB2_SELECT_WBptr[70] = 123; silk_NLSF_CB2_SELECT_WBptr[71] = 103;
        silk_NLSF_CB2_SELECT_WBptr[72] = 36; silk_NLSF_CB2_SELECT_WBptr[73] = 0; silk_NLSF_CB2_SELECT_WBptr[74] = 0; silk_NLSF_CB2_SELECT_WBptr[75] = 0;
        silk_NLSF_CB2_SELECT_WBptr[76] = 0; silk_NLSF_CB2_SELECT_WBptr[77] = 0; silk_NLSF_CB2_SELECT_WBptr[78] = 0; silk_NLSF_CB2_SELECT_WBptr[79] = 1;
        silk_NLSF_CB2_SELECT_WBptr[80] = 48; silk_NLSF_CB2_SELECT_WBptr[81] = 0; silk_NLSF_CB2_SELECT_WBptr[82] = 0; silk_NLSF_CB2_SELECT_WBptr[83] = 0;
        silk_NLSF_CB2_SELECT_WBptr[84] = 0; silk_NLSF_CB2_SELECT_WBptr[85] = 0; silk_NLSF_CB2_SELECT_WBptr[86] = 0; silk_NLSF_CB2_SELECT_WBptr[87] = 32;
        silk_NLSF_CB2_SELECT_WBptr[88] = 68; silk_NLSF_CB2_SELECT_WBptr[89] = 135; silk_NLSF_CB2_SELECT_WBptr[90] = 123; silk_NLSF_CB2_SELECT_WBptr[91] = 119;
        silk_NLSF_CB2_SELECT_WBptr[92] = 119; silk_NLSF_CB2_SELECT_WBptr[93] = 103; silk_NLSF_CB2_SELECT_WBptr[94] = 69; silk_NLSF_CB2_SELECT_WBptr[95] = 98;
        silk_NLSF_CB2_SELECT_WBptr[96] = 68; silk_NLSF_CB2_SELECT_WBptr[97] = 103; silk_NLSF_CB2_SELECT_WBptr[98] = 120; silk_NLSF_CB2_SELECT_WBptr[99] = 118;
        silk_NLSF_CB2_SELECT_WBptr[100] = 118; silk_NLSF_CB2_SELECT_WBptr[101] = 102; silk_NLSF_CB2_SELECT_WBptr[102] = 71; silk_NLSF_CB2_SELECT_WBptr[103] = 98;
        silk_NLSF_CB2_SELECT_WBptr[104] = 134; silk_NLSF_CB2_SELECT_WBptr[105] = 136; silk_NLSF_CB2_SELECT_WBptr[106] = 157; silk_NLSF_CB2_SELECT_WBptr[107] = 184;
        silk_NLSF_CB2_SELECT_WBptr[108] = 182; silk_NLSF_CB2_SELECT_WBptr[109] = 153; silk_NLSF_CB2_SELECT_WBptr[110] = 139; silk_NLSF_CB2_SELECT_WBptr[111] = 134;
        silk_NLSF_CB2_SELECT_WBptr[112] = 208; silk_NLSF_CB2_SELECT_WBptr[113] = 168; silk_NLSF_CB2_SELECT_WBptr[114] = 248; silk_NLSF_CB2_SELECT_WBptr[115] = 75;
        silk_NLSF_CB2_SELECT_WBptr[116] = 189; silk_NLSF_CB2_SELECT_WBptr[117] = 143; silk_NLSF_CB2_SELECT_WBptr[118] = 121; silk_NLSF_CB2_SELECT_WBptr[119] = 107;
        silk_NLSF_CB2_SELECT_WBptr[120] = 32; silk_NLSF_CB2_SELECT_WBptr[121] = 49; silk_NLSF_CB2_SELECT_WBptr[122] = 34; silk_NLSF_CB2_SELECT_WBptr[123] = 34;
        silk_NLSF_CB2_SELECT_WBptr[124] = 34; silk_NLSF_CB2_SELECT_WBptr[125] = 0; silk_NLSF_CB2_SELECT_WBptr[126] = 17; silk_NLSF_CB2_SELECT_WBptr[127] = 2;
        silk_NLSF_CB2_SELECT_WBptr[128] = 210; silk_NLSF_CB2_SELECT_WBptr[129] = 235; silk_NLSF_CB2_SELECT_WBptr[130] = 139; silk_NLSF_CB2_SELECT_WBptr[131] = 123;
        silk_NLSF_CB2_SELECT_WBptr[132] = 185; silk_NLSF_CB2_SELECT_WBptr[133] = 137; silk_NLSF_CB2_SELECT_WBptr[134] = 105; silk_NLSF_CB2_SELECT_WBptr[135] = 134;
        silk_NLSF_CB2_SELECT_WBptr[136] = 98; silk_NLSF_CB2_SELECT_WBptr[137] = 135; silk_NLSF_CB2_SELECT_WBptr[138] = 104; silk_NLSF_CB2_SELECT_WBptr[139] = 182;
        silk_NLSF_CB2_SELECT_WBptr[140] = 100; silk_NLSF_CB2_SELECT_WBptr[141] = 183; silk_NLSF_CB2_SELECT_WBptr[142] = 171; silk_NLSF_CB2_SELECT_WBptr[143] = 134;
        silk_NLSF_CB2_SELECT_WBptr[144] = 100; silk_NLSF_CB2_SELECT_WBptr[145] = 70; silk_NLSF_CB2_SELECT_WBptr[146] = 68; silk_NLSF_CB2_SELECT_WBptr[147] = 70;
        silk_NLSF_CB2_SELECT_WBptr[148] = 66; silk_NLSF_CB2_SELECT_WBptr[149] = 66; silk_NLSF_CB2_SELECT_WBptr[150] = 34; silk_NLSF_CB2_SELECT_WBptr[151] = 131;
        silk_NLSF_CB2_SELECT_WBptr[152] = 64; silk_NLSF_CB2_SELECT_WBptr[153] = 166; silk_NLSF_CB2_SELECT_WBptr[154] = 102; silk_NLSF_CB2_SELECT_WBptr[155] = 68;
        silk_NLSF_CB2_SELECT_WBptr[156] = 36; silk_NLSF_CB2_SELECT_WBptr[157] = 2; silk_NLSF_CB2_SELECT_WBptr[158] = 1; silk_NLSF_CB2_SELECT_WBptr[159] = 0;
        silk_NLSF_CB2_SELECT_WBptr[160] = 134; silk_NLSF_CB2_SELECT_WBptr[161] = 166; silk_NLSF_CB2_SELECT_WBptr[162] = 102; silk_NLSF_CB2_SELECT_WBptr[163] = 68;
        silk_NLSF_CB2_SELECT_WBptr[164] = 34; silk_NLSF_CB2_SELECT_WBptr[165] = 34; silk_NLSF_CB2_SELECT_WBptr[166] = 66; silk_NLSF_CB2_SELECT_WBptr[167] = 132;
        silk_NLSF_CB2_SELECT_WBptr[168] = 212; silk_NLSF_CB2_SELECT_WBptr[169] = 246; silk_NLSF_CB2_SELECT_WBptr[170] = 158; silk_NLSF_CB2_SELECT_WBptr[171] = 139;
        silk_NLSF_CB2_SELECT_WBptr[172] = 107; silk_NLSF_CB2_SELECT_WBptr[173] = 107; silk_NLSF_CB2_SELECT_WBptr[174] = 87; silk_NLSF_CB2_SELECT_WBptr[175] = 102;
        silk_NLSF_CB2_SELECT_WBptr[176] = 100; silk_NLSF_CB2_SELECT_WBptr[177] = 219; silk_NLSF_CB2_SELECT_WBptr[178] = 125; silk_NLSF_CB2_SELECT_WBptr[179] = 122;
        silk_NLSF_CB2_SELECT_WBptr[180] = 137; silk_NLSF_CB2_SELECT_WBptr[181] = 118; silk_NLSF_CB2_SELECT_WBptr[182] = 103; silk_NLSF_CB2_SELECT_WBptr[183] = 132;
        silk_NLSF_CB2_SELECT_WBptr[184] = 114; silk_NLSF_CB2_SELECT_WBptr[185] = 135; silk_NLSF_CB2_SELECT_WBptr[186] = 137; silk_NLSF_CB2_SELECT_WBptr[187] = 105;
        silk_NLSF_CB2_SELECT_WBptr[188] = 171; silk_NLSF_CB2_SELECT_WBptr[189] = 106; silk_NLSF_CB2_SELECT_WBptr[190] = 50; silk_NLSF_CB2_SELECT_WBptr[191] = 34;
        silk_NLSF_CB2_SELECT_WBptr[192] = 164; silk_NLSF_CB2_SELECT_WBptr[193] = 214; silk_NLSF_CB2_SELECT_WBptr[194] = 141; silk_NLSF_CB2_SELECT_WBptr[195] = 143;
        silk_NLSF_CB2_SELECT_WBptr[196] = 185; silk_NLSF_CB2_SELECT_WBptr[197] = 151; silk_NLSF_CB2_SELECT_WBptr[198] = 121; silk_NLSF_CB2_SELECT_WBptr[199] = 103;
        silk_NLSF_CB2_SELECT_WBptr[200] = 192; silk_NLSF_CB2_SELECT_WBptr[201] = 34; silk_NLSF_CB2_SELECT_WBptr[202] = 0; silk_NLSF_CB2_SELECT_WBptr[203] = 0;
        silk_NLSF_CB2_SELECT_WBptr[204] = 0; silk_NLSF_CB2_SELECT_WBptr[205] = 0; silk_NLSF_CB2_SELECT_WBptr[206] = 0; silk_NLSF_CB2_SELECT_WBptr[207] = 1;
        silk_NLSF_CB2_SELECT_WBptr[208] = 208; silk_NLSF_CB2_SELECT_WBptr[209] = 109; silk_NLSF_CB2_SELECT_WBptr[210] = 74; silk_NLSF_CB2_SELECT_WBptr[211] = 187;
        silk_NLSF_CB2_SELECT_WBptr[212] = 134; silk_NLSF_CB2_SELECT_WBptr[213] = 249; silk_NLSF_CB2_SELECT_WBptr[214] = 159; silk_NLSF_CB2_SELECT_WBptr[215] = 137;
        silk_NLSF_CB2_SELECT_WBptr[216] = 102; silk_NLSF_CB2_SELECT_WBptr[217] = 110; silk_NLSF_CB2_SELECT_WBptr[218] = 154; silk_NLSF_CB2_SELECT_WBptr[219] = 118;
        silk_NLSF_CB2_SELECT_WBptr[220] = 87; silk_NLSF_CB2_SELECT_WBptr[221] = 101; silk_NLSF_CB2_SELECT_WBptr[222] = 119; silk_NLSF_CB2_SELECT_WBptr[223] = 101;
        silk_NLSF_CB2_SELECT_WBptr[224] = 0; silk_NLSF_CB2_SELECT_WBptr[225] = 2; silk_NLSF_CB2_SELECT_WBptr[226] = 0; silk_NLSF_CB2_SELECT_WBptr[227] = 36;
        silk_NLSF_CB2_SELECT_WBptr[228] = 36; silk_NLSF_CB2_SELECT_WBptr[229] = 66; silk_NLSF_CB2_SELECT_WBptr[230] = 68; silk_NLSF_CB2_SELECT_WBptr[231] = 35;
        silk_NLSF_CB2_SELECT_WBptr[232] = 96; silk_NLSF_CB2_SELECT_WBptr[233] = 164; silk_NLSF_CB2_SELECT_WBptr[234] = 102; silk_NLSF_CB2_SELECT_WBptr[235] = 100;
        silk_NLSF_CB2_SELECT_WBptr[236] = 36; silk_NLSF_CB2_SELECT_WBptr[237] = 0; silk_NLSF_CB2_SELECT_WBptr[238] = 2; silk_NLSF_CB2_SELECT_WBptr[239] = 33;
        silk_NLSF_CB2_SELECT_WBptr[240] = 167; silk_NLSF_CB2_SELECT_WBptr[241] = 138; silk_NLSF_CB2_SELECT_WBptr[242] = 174; silk_NLSF_CB2_SELECT_WBptr[243] = 102;
        silk_NLSF_CB2_SELECT_WBptr[244] = 100; silk_NLSF_CB2_SELECT_WBptr[245] = 84; silk_NLSF_CB2_SELECT_WBptr[246] = 2; silk_NLSF_CB2_SELECT_WBptr[247] = 2;
        silk_NLSF_CB2_SELECT_WBptr[248] = 100; silk_NLSF_CB2_SELECT_WBptr[249] = 107; silk_NLSF_CB2_SELECT_WBptr[250] = 120; silk_NLSF_CB2_SELECT_WBptr[251] = 119;
        silk_NLSF_CB2_SELECT_WBptr[252] = 36; silk_NLSF_CB2_SELECT_WBptr[253] = 197; silk_NLSF_CB2_SELECT_WBptr[254] = 24; silk_NLSF_CB2_SELECT_WBptr[255] = 0;


        opus_uint8 *silk_NLSF_CB2_iCDF_WBptr = malloc(sizeof(opus_uint8) * 72);
        silk_NLSF_CB2_iCDF_WBptr[0] = 255; silk_NLSF_CB2_iCDF_WBptr[1] = 254; silk_NLSF_CB2_iCDF_WBptr[2] = 253; silk_NLSF_CB2_iCDF_WBptr[3] = 244;
        silk_NLSF_CB2_iCDF_WBptr[4] = 12; silk_NLSF_CB2_iCDF_WBptr[5] = 3; silk_NLSF_CB2_iCDF_WBptr[6] = 2; silk_NLSF_CB2_iCDF_WBptr[7] = 1;
        silk_NLSF_CB2_iCDF_WBptr[8] = 0; silk_NLSF_CB2_iCDF_WBptr[9] = 255; silk_NLSF_CB2_iCDF_WBptr[10] = 254; silk_NLSF_CB2_iCDF_WBptr[11] = 252;
        silk_NLSF_CB2_iCDF_WBptr[12] = 224; silk_NLSF_CB2_iCDF_WBptr[13] = 38; silk_NLSF_CB2_iCDF_WBptr[14] = 3; silk_NLSF_CB2_iCDF_WBptr[15] = 2;
        silk_NLSF_CB2_iCDF_WBptr[16] = 1; silk_NLSF_CB2_iCDF_WBptr[17] = 0; silk_NLSF_CB2_iCDF_WBptr[18] = 255; silk_NLSF_CB2_iCDF_WBptr[19] = 254;
        silk_NLSF_CB2_iCDF_WBptr[20] = 251; silk_NLSF_CB2_iCDF_WBptr[21] = 209; silk_NLSF_CB2_iCDF_WBptr[22] = 57; silk_NLSF_CB2_iCDF_WBptr[23] = 4;
        silk_NLSF_CB2_iCDF_WBptr[24] = 2; silk_NLSF_CB2_iCDF_WBptr[25] = 1; silk_NLSF_CB2_iCDF_WBptr[26] = 0; silk_NLSF_CB2_iCDF_WBptr[27] = 255;
        silk_NLSF_CB2_iCDF_WBptr[28] = 254; silk_NLSF_CB2_iCDF_WBptr[29] = 244; silk_NLSF_CB2_iCDF_WBptr[30] = 195; silk_NLSF_CB2_iCDF_WBptr[31] = 69;
        silk_NLSF_CB2_iCDF_WBptr[32] = 4; silk_NLSF_CB2_iCDF_WBptr[33] = 2; silk_NLSF_CB2_iCDF_WBptr[34] = 1; silk_NLSF_CB2_iCDF_WBptr[35] = 0;
        silk_NLSF_CB2_iCDF_WBptr[36] = 255; silk_NLSF_CB2_iCDF_WBptr[37] = 251; silk_NLSF_CB2_iCDF_WBptr[38] = 232; silk_NLSF_CB2_iCDF_WBptr[39] = 184;
        silk_NLSF_CB2_iCDF_WBptr[40] = 84; silk_NLSF_CB2_iCDF_WBptr[41] = 7; silk_NLSF_CB2_iCDF_WBptr[42] = 2; silk_NLSF_CB2_iCDF_WBptr[43] = 1;
        silk_NLSF_CB2_iCDF_WBptr[44] = 0; silk_NLSF_CB2_iCDF_WBptr[45] = 255; silk_NLSF_CB2_iCDF_WBptr[46] = 254; silk_NLSF_CB2_iCDF_WBptr[47] = 240;
        silk_NLSF_CB2_iCDF_WBptr[48] = 186; silk_NLSF_CB2_iCDF_WBptr[49] = 86; silk_NLSF_CB2_iCDF_WBptr[50] = 14; silk_NLSF_CB2_iCDF_WBptr[51] = 2;
        silk_NLSF_CB2_iCDF_WBptr[52] = 1; silk_NLSF_CB2_iCDF_WBptr[53] = 0; silk_NLSF_CB2_iCDF_WBptr[54] = 255; silk_NLSF_CB2_iCDF_WBptr[55] = 254;
        silk_NLSF_CB2_iCDF_WBptr[56] = 239; silk_NLSF_CB2_iCDF_WBptr[57] = 178; silk_NLSF_CB2_iCDF_WBptr[58] = 91; silk_NLSF_CB2_iCDF_WBptr[59] = 30;
        silk_NLSF_CB2_iCDF_WBptr[60] = 5; silk_NLSF_CB2_iCDF_WBptr[61] = 1; silk_NLSF_CB2_iCDF_WBptr[62] = 0; silk_NLSF_CB2_iCDF_WBptr[63] = 255;
        silk_NLSF_CB2_iCDF_WBptr[64] = 248; silk_NLSF_CB2_iCDF_WBptr[65] = 227; silk_NLSF_CB2_iCDF_WBptr[66] = 177; silk_NLSF_CB2_iCDF_WBptr[67] = 100;
        silk_NLSF_CB2_iCDF_WBptr[68] = 19; silk_NLSF_CB2_iCDF_WBptr[69] = 2; silk_NLSF_CB2_iCDF_WBptr[70] = 1; silk_NLSF_CB2_iCDF_WBptr[71] = 0;


        opus_uint8 *silk_NLSF_CB2_BITS_WB_Q5ptr = malloc(sizeof(opus_uint8) * 72);
        silk_NLSF_CB2_BITS_WB_Q5ptr[0] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[1] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[2] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[3] = 156;
        silk_NLSF_CB2_BITS_WB_Q5ptr[4] = 4; silk_NLSF_CB2_BITS_WB_Q5ptr[5] = 154; silk_NLSF_CB2_BITS_WB_Q5ptr[6] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[7] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[8] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[9] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[10] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[11] = 227;
        silk_NLSF_CB2_BITS_WB_Q5ptr[12] = 102; silk_NLSF_CB2_BITS_WB_Q5ptr[13] = 15; silk_NLSF_CB2_BITS_WB_Q5ptr[14] = 92; silk_NLSF_CB2_BITS_WB_Q5ptr[15] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[16] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[17] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[18] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[19] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[20] = 213; silk_NLSF_CB2_BITS_WB_Q5ptr[21] = 83; silk_NLSF_CB2_BITS_WB_Q5ptr[22] = 24; silk_NLSF_CB2_BITS_WB_Q5ptr[23] = 72;
        silk_NLSF_CB2_BITS_WB_Q5ptr[24] = 236; silk_NLSF_CB2_BITS_WB_Q5ptr[25] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[26] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[27] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[28] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[29] = 150; silk_NLSF_CB2_BITS_WB_Q5ptr[30] = 76; silk_NLSF_CB2_BITS_WB_Q5ptr[31] = 33;
        silk_NLSF_CB2_BITS_WB_Q5ptr[32] = 63; silk_NLSF_CB2_BITS_WB_Q5ptr[33] = 214; silk_NLSF_CB2_BITS_WB_Q5ptr[34] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[35] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[36] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[37] = 190; silk_NLSF_CB2_BITS_WB_Q5ptr[38] = 121; silk_NLSF_CB2_BITS_WB_Q5ptr[39] = 77;
        silk_NLSF_CB2_BITS_WB_Q5ptr[40] = 43; silk_NLSF_CB2_BITS_WB_Q5ptr[41] = 55; silk_NLSF_CB2_BITS_WB_Q5ptr[42] = 185; silk_NLSF_CB2_BITS_WB_Q5ptr[43] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[44] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[45] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[46] = 245; silk_NLSF_CB2_BITS_WB_Q5ptr[47] = 137;
        silk_NLSF_CB2_BITS_WB_Q5ptr[48] = 71; silk_NLSF_CB2_BITS_WB_Q5ptr[49] = 43; silk_NLSF_CB2_BITS_WB_Q5ptr[50] = 59; silk_NLSF_CB2_BITS_WB_Q5ptr[51] = 139;
        silk_NLSF_CB2_BITS_WB_Q5ptr[52] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[53] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[54] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[55] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[56] = 131; silk_NLSF_CB2_BITS_WB_Q5ptr[57] = 66; silk_NLSF_CB2_BITS_WB_Q5ptr[58] = 50; silk_NLSF_CB2_BITS_WB_Q5ptr[59] = 66;
        silk_NLSF_CB2_BITS_WB_Q5ptr[60] = 107; silk_NLSF_CB2_BITS_WB_Q5ptr[61] = 194; silk_NLSF_CB2_BITS_WB_Q5ptr[62] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[63] = 255;
        silk_NLSF_CB2_BITS_WB_Q5ptr[64] = 166; silk_NLSF_CB2_BITS_WB_Q5ptr[65] = 116; silk_NLSF_CB2_BITS_WB_Q5ptr[66] = 76; silk_NLSF_CB2_BITS_WB_Q5ptr[67] = 55;
        silk_NLSF_CB2_BITS_WB_Q5ptr[68] = 53; silk_NLSF_CB2_BITS_WB_Q5ptr[69] = 125; silk_NLSF_CB2_BITS_WB_Q5ptr[70] = 255; silk_NLSF_CB2_BITS_WB_Q5ptr[71] = 255;


        opus_int16 *silk_NLSF_DELTA_MIN_WB_Q15ptr = (opus_int16*)malloc(sizeof(opus_int16) * 17);
        silk_NLSF_DELTA_MIN_WB_Q15ptr[0] = 100;silk_NLSF_DELTA_MIN_WB_Q15ptr[8] = 14;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[1] = 3;silk_NLSF_DELTA_MIN_WB_Q15ptr[9] = 10;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[2] = 40;silk_NLSF_DELTA_MIN_WB_Q15ptr[10] = 11;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[3] = 3;silk_NLSF_DELTA_MIN_WB_Q15ptr[11] = 3;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[4] = 3;silk_NLSF_DELTA_MIN_WB_Q15ptr[12] = 8;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[5] = 3;silk_NLSF_DELTA_MIN_WB_Q15ptr[13] = 9;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[6] = 5;silk_NLSF_DELTA_MIN_WB_Q15ptr[14] = 7;
        silk_NLSF_DELTA_MIN_WB_Q15ptr[7] = 14;silk_NLSF_DELTA_MIN_WB_Q15ptr[15] = 3;


        _silk_NLSF_CB_WB->nVectors = 32;
        _silk_NLSF_CB_WB->order = 16;
        _silk_NLSF_CB_WB->quantStepSize_Q16 =  SILK_FIX_CONST(0.15, 16 );
        _silk_NLSF_CB_WB->invQuantStepSize_Q6 =  SILK_FIX_CONST( 1.0 / 0.15, 6 );
        _silk_NLSF_CB_WB->CB1_NLSF_Q8 = silk_NLSF_CB1_WB_Q8ptr;
        _silk_NLSF_CB_WB->CB1_Wght_Q9 = silk_NLSF_CB1_WB_Wght_Q9ptr;
        _silk_NLSF_CB_WB->CB1_iCDF = silk_NLSF_CB1_iCDF_WBptr;
        _silk_NLSF_CB_WB->pred_Q8 = silk_NLSF_PRED_WB_Q8ptr;
        _silk_NLSF_CB_WB->ec_sel = silk_NLSF_CB2_SELECT_WBptr;
        _silk_NLSF_CB_WB->ec_iCDF = silk_NLSF_CB2_iCDF_WBptr;
        _silk_NLSF_CB_WB->ec_Rates_Q5 = silk_NLSF_CB2_BITS_WB_Q5ptr;
        _silk_NLSF_CB_WB->deltaMin_Q15 = silk_NLSF_DELTA_MIN_WB_Q15ptr;
    }
    silk_NLSF_CB_struct* test = _silk_NLSF_CB_WB;
    return test;
}

