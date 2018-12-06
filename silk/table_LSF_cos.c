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

#include <malloc.h>
#include "tables.h"

/* Cosine approximation table for LSF conversion */
/* Q12 values (even) */
opus_int16 * s_silk_LSFCosTab_FIX_Q12 = 0;
const opus_int16 *get_silk_LSFCosTab_FIX_Q12(void){
    if(s_silk_LSFCosTab_FIX_Q12 == NULL){
        s_silk_LSFCosTab_FIX_Q12 = malloc(sizeof(opus_int16) * (LSF_COS_TAB_SZ_FIX + 1));

        s_silk_LSFCosTab_FIX_Q12[0] = 8192; s_silk_LSFCosTab_FIX_Q12[1] = 8190; s_silk_LSFCosTab_FIX_Q12[2] = 8182; s_silk_LSFCosTab_FIX_Q12[3] = 8170; s_silk_LSFCosTab_FIX_Q12[4] = 8152;
        s_silk_LSFCosTab_FIX_Q12[5] = 8130; s_silk_LSFCosTab_FIX_Q12[6] = 8104; s_silk_LSFCosTab_FIX_Q12[7] = 8072; s_silk_LSFCosTab_FIX_Q12[8] = 8034; s_silk_LSFCosTab_FIX_Q12[9] = 7994;
        s_silk_LSFCosTab_FIX_Q12[10] = 7946; s_silk_LSFCosTab_FIX_Q12[11] = 7896; s_silk_LSFCosTab_FIX_Q12[12] = 7840; s_silk_LSFCosTab_FIX_Q12[13] = 7778; s_silk_LSFCosTab_FIX_Q12[14] = 7714;
        s_silk_LSFCosTab_FIX_Q12[15] = 7644; s_silk_LSFCosTab_FIX_Q12[16] = 7568; s_silk_LSFCosTab_FIX_Q12[17] = 7490; s_silk_LSFCosTab_FIX_Q12[18] = 7406; s_silk_LSFCosTab_FIX_Q12[19] = 7318;
        s_silk_LSFCosTab_FIX_Q12[20] = 7226; s_silk_LSFCosTab_FIX_Q12[21] = 7128; s_silk_LSFCosTab_FIX_Q12[22] = 7026; s_silk_LSFCosTab_FIX_Q12[23] = 6922; s_silk_LSFCosTab_FIX_Q12[24] = 6812;
        s_silk_LSFCosTab_FIX_Q12[25] = 6698; s_silk_LSFCosTab_FIX_Q12[26] = 6580; s_silk_LSFCosTab_FIX_Q12[27] = 6458; s_silk_LSFCosTab_FIX_Q12[28] = 6332; s_silk_LSFCosTab_FIX_Q12[29] = 6204;
        s_silk_LSFCosTab_FIX_Q12[30] = 6070; s_silk_LSFCosTab_FIX_Q12[31] = 5934; s_silk_LSFCosTab_FIX_Q12[32] = 5792; s_silk_LSFCosTab_FIX_Q12[33] = 5648; s_silk_LSFCosTab_FIX_Q12[34] = 5502;
        s_silk_LSFCosTab_FIX_Q12[35] = 5352; s_silk_LSFCosTab_FIX_Q12[36] = 5198; s_silk_LSFCosTab_FIX_Q12[37] = 5040; s_silk_LSFCosTab_FIX_Q12[38] = 4880; s_silk_LSFCosTab_FIX_Q12[39] = 4718;
        s_silk_LSFCosTab_FIX_Q12[40] = 4552; s_silk_LSFCosTab_FIX_Q12[41] = 4382; s_silk_LSFCosTab_FIX_Q12[42] = 4212; s_silk_LSFCosTab_FIX_Q12[43] = 4038; s_silk_LSFCosTab_FIX_Q12[44] = 3862;
        s_silk_LSFCosTab_FIX_Q12[45] = 3684; s_silk_LSFCosTab_FIX_Q12[46] = 3502; s_silk_LSFCosTab_FIX_Q12[47] = 3320; s_silk_LSFCosTab_FIX_Q12[48] = 3136; s_silk_LSFCosTab_FIX_Q12[49] = 2948;
        s_silk_LSFCosTab_FIX_Q12[50] = 2760; s_silk_LSFCosTab_FIX_Q12[51] = 2570; s_silk_LSFCosTab_FIX_Q12[52] = 2378; s_silk_LSFCosTab_FIX_Q12[53] = 2186; s_silk_LSFCosTab_FIX_Q12[54] = 1990;
        s_silk_LSFCosTab_FIX_Q12[55] = 1794; s_silk_LSFCosTab_FIX_Q12[56] = 1598; s_silk_LSFCosTab_FIX_Q12[57] = 1400; s_silk_LSFCosTab_FIX_Q12[58] = 1202; s_silk_LSFCosTab_FIX_Q12[59] = 1002;
        s_silk_LSFCosTab_FIX_Q12[60] = 802; s_silk_LSFCosTab_FIX_Q12[61] = 602; s_silk_LSFCosTab_FIX_Q12[62] = 402; s_silk_LSFCosTab_FIX_Q12[63] = 202; s_silk_LSFCosTab_FIX_Q12[64] = 0;
        s_silk_LSFCosTab_FIX_Q12[65] = -202; s_silk_LSFCosTab_FIX_Q12[66] = -402; s_silk_LSFCosTab_FIX_Q12[67] = -602; s_silk_LSFCosTab_FIX_Q12[68] = -802; s_silk_LSFCosTab_FIX_Q12[69] = -1002;
        s_silk_LSFCosTab_FIX_Q12[70] = -1202; s_silk_LSFCosTab_FIX_Q12[71] = -1400; s_silk_LSFCosTab_FIX_Q12[72] = -1598; s_silk_LSFCosTab_FIX_Q12[73] = -1794; s_silk_LSFCosTab_FIX_Q12[74] = -1990;
        s_silk_LSFCosTab_FIX_Q12[75] = -2186; s_silk_LSFCosTab_FIX_Q12[76] = -2378; s_silk_LSFCosTab_FIX_Q12[77] = -2570; s_silk_LSFCosTab_FIX_Q12[78] = -2760; s_silk_LSFCosTab_FIX_Q12[79] = -2948;
        s_silk_LSFCosTab_FIX_Q12[80] = -3136; s_silk_LSFCosTab_FIX_Q12[81] = -3320; s_silk_LSFCosTab_FIX_Q12[82] = -3502; s_silk_LSFCosTab_FIX_Q12[83] = -3684; s_silk_LSFCosTab_FIX_Q12[84] = -3862;
        s_silk_LSFCosTab_FIX_Q12[85] = -4038; s_silk_LSFCosTab_FIX_Q12[86] = -4212; s_silk_LSFCosTab_FIX_Q12[87] = -4382; s_silk_LSFCosTab_FIX_Q12[88] = -4552; s_silk_LSFCosTab_FIX_Q12[89] = -4718;
        s_silk_LSFCosTab_FIX_Q12[90] = -4880; s_silk_LSFCosTab_FIX_Q12[91] = -5040; s_silk_LSFCosTab_FIX_Q12[92] = -5198; s_silk_LSFCosTab_FIX_Q12[93] = -5352; s_silk_LSFCosTab_FIX_Q12[94] = -5502;
        s_silk_LSFCosTab_FIX_Q12[95] = -5648; s_silk_LSFCosTab_FIX_Q12[96] = -5792; s_silk_LSFCosTab_FIX_Q12[97] = -5934; s_silk_LSFCosTab_FIX_Q12[98] = -6070; s_silk_LSFCosTab_FIX_Q12[99] = -6204;
        s_silk_LSFCosTab_FIX_Q12[100] = -6332; s_silk_LSFCosTab_FIX_Q12[101] = -6458; s_silk_LSFCosTab_FIX_Q12[102] = -6580; s_silk_LSFCosTab_FIX_Q12[103] = -6698; s_silk_LSFCosTab_FIX_Q12[104] = -6812;
        s_silk_LSFCosTab_FIX_Q12[105] = -6922; s_silk_LSFCosTab_FIX_Q12[106] = -7026; s_silk_LSFCosTab_FIX_Q12[107] = -7128; s_silk_LSFCosTab_FIX_Q12[108] = -7226; s_silk_LSFCosTab_FIX_Q12[109] = -7318;
        s_silk_LSFCosTab_FIX_Q12[110] = -7406; s_silk_LSFCosTab_FIX_Q12[111] = -7490; s_silk_LSFCosTab_FIX_Q12[112] = -7568; s_silk_LSFCosTab_FIX_Q12[113] = -7644; s_silk_LSFCosTab_FIX_Q12[114] = -7714;
        s_silk_LSFCosTab_FIX_Q12[115] = -7778; s_silk_LSFCosTab_FIX_Q12[116] = -7840; s_silk_LSFCosTab_FIX_Q12[117] = -7896; s_silk_LSFCosTab_FIX_Q12[118] = -7946; s_silk_LSFCosTab_FIX_Q12[119] = -7994;
        s_silk_LSFCosTab_FIX_Q12[120] = -8034; s_silk_LSFCosTab_FIX_Q12[121] = -8072; s_silk_LSFCosTab_FIX_Q12[122] = -8104; s_silk_LSFCosTab_FIX_Q12[123] = -8130; s_silk_LSFCosTab_FIX_Q12[124] = -8152;
        s_silk_LSFCosTab_FIX_Q12[125] = -8170; s_silk_LSFCosTab_FIX_Q12[126] = -8182; s_silk_LSFCosTab_FIX_Q12[127] = -8190; s_silk_LSFCosTab_FIX_Q12[128] = -8192;
    }
    return (const opus_int16 *) s_silk_LSFCosTab_FIX_Q12;
}