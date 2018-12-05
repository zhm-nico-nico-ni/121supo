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
#include "tables.h"

const opus_uint8 silk_LTP_per_index_iCDF[3] = {
       179,     99,      0
};

static const opus_uint8 silk_LTP_gain_BITS_Q5_0[8] = {
        15,    131,    138,    138,    155,    155,    173,    173
};

static const opus_uint8 silk_LTP_gain_BITS_Q5_1[16] = {
        69,     93,    115,    118,    131,    138,    141,    138,
       150,    150,    155,    150,    155,    160,    166,    160
};

static const opus_uint8 silk_LTP_gain_BITS_Q5_2[32] = {
       131,    128,    134,    141,    141,    141,    145,    145,
       145,    150,    155,    155,    155,    155,    160,    160,
       160,    160,    166,    166,    173,    173,    182,    192,
       182,    192,    192,    192,    205,    192,    205,    224
};



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

    return s_silk_LTP_gain_iCDF_ptrs;
}

const opus_uint8 * const silk_LTP_gain_BITS_Q5_ptrs[NB_LTP_CBKS] = {
    silk_LTP_gain_BITS_Q5_0,
    silk_LTP_gain_BITS_Q5_1,
    silk_LTP_gain_BITS_Q5_2
};

static const opus_int8 silk_LTP_gain_vq_0[8][5] =
{
{
         4,      6,     24,      7,      5
},
{
         0,      0,      2,      0,      0
},
{
        12,     28,     41,     13,     -4
},
{
        -9,     15,     42,     25,     14
},
{
         1,     -2,     62,     41,     -9
},
{
       -10,     37,     65,     -4,      3
},
{
        -6,      4,     66,      7,     -8
},
{
        16,     14,     38,     -3,     33
}
};

static const opus_int8 silk_LTP_gain_vq_1[16][5] =
{
{
        13,     22,     39,     23,     12
},
{
        -1,     36,     64,     27,     -6
},
{
        -7,     10,     55,     43,     17
},
{
         1,      1,      8,      1,      1
},
{
         6,    -11,     74,     53,     -9
},
{
       -12,     55,     76,    -12,      8
},
{
        -3,      3,     93,     27,     -4
},
{
        26,     39,     59,      3,     -8
},
{
         2,      0,     77,     11,      9
},
{
        -8,     22,     44,     -6,      7
},
{
        40,      9,     26,      3,      9
},
{
        -7,     20,    101,     -7,      4
},
{
         3,     -8,     42,     26,      0
},
{
       -15,     33,     68,      2,     23
},
{
        -2,     55,     46,     -2,     15
},
{
         3,     -1,     21,     16,     41
}
};

static const opus_int8 silk_LTP_gain_vq_2[32][5] =
{
{
        -6,     27,     61,     39,      5
},
{
       -11,     42,     88,      4,      1
},
{
        -2,     60,     65,      6,     -4
},
{
        -1,     -5,     73,     56,      1
},
{
        -9,     19,     94,     29,     -9
},
{
         0,     12,     99,      6,      4
},
{
         8,    -19,    102,     46,    -13
},
{
         3,      2,     13,      3,      2
},
{
         9,    -21,     84,     72,    -18
},
{
       -11,     46,    104,    -22,      8
},
{
        18,     38,     48,     23,      0
},
{
       -16,     70,     83,    -21,     11
},
{
         5,    -11,    117,     22,     -8
},
{
        -6,     23,    117,    -12,      3
},
{
         3,     -8,     95,     28,      4
},
{
       -10,     15,     77,     60,    -15
},
{
        -1,      4,    124,      2,     -4
},
{
         3,     38,     84,     24,    -25
},
{
         2,     13,     42,     13,     31
},
{
        21,     -4,     56,     46,     -1
},
{
        -1,     35,     79,    -13,     19
},
{
        -7,     65,     88,     -9,    -14
},
{
        20,      4,     81,     49,    -29
},
{
        20,      0,     75,      3,    -17
},
{
         5,     -9,     44,     92,     -8
},
{
         1,     -3,     22,     69,     31
},
{
        -6,     95,     41,    -12,      5
},
{
        39,     67,     16,     -4,      1
},
{
         0,     -6,    120,     55,    -36
},
{
       -13,     44,    122,      4,    -24
},
{
        81,      5,     11,      3,      7
},
{
         2,      0,      9,     10,     88
}
};

const opus_int8 * const silk_LTP_vq_ptrs_Q7[NB_LTP_CBKS] = {
    (opus_int8 *)&silk_LTP_gain_vq_0[0][0],
    (opus_int8 *)&silk_LTP_gain_vq_1[0][0],
    (opus_int8 *)&silk_LTP_gain_vq_2[0][0]
};

/* Maximum frequency-dependent response of the pitch taps above,
   computed as max(abs(freqz(taps))) */
static const opus_uint8 silk_LTP_gain_vq_0_gain[8] = {
      46,      2,     90,     87,     93,     91,     82,     98
};

static const opus_uint8 silk_LTP_gain_vq_1_gain[16] = {
     109,    120,    118,     12,    113,    115,    117,    119,
      99,     59,     87,    111,     63,    111,    112,     80
};

static const opus_uint8 silk_LTP_gain_vq_2_gain[32] = {
     126,    124,    125,    124,    129,    121,    126,     23,
     132,    127,    127,    127,    126,    127,    122,    133,
     130,    134,    101,    118,    119,    145,    126,     86,
     124,    120,    123,    119,    170,    173,    107,    109
};

const opus_uint8 * const silk_LTP_vq_gain_ptrs_Q7[NB_LTP_CBKS] = {
    &silk_LTP_gain_vq_0_gain[0],
    &silk_LTP_gain_vq_1_gain[0],
    &silk_LTP_gain_vq_2_gain[0]
};

const opus_int8 silk_LTP_vq_sizes[NB_LTP_CBKS] = {
    8, 16, 32
};
