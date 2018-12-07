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



#include "main.h"

/* shell coder; pulse-subframe length is hardcoded */

static OPUS_INLINE void combine_pulses(
    opus_int         *out,   /* O    combined pulses vector [len] */
    const opus_int   *in,    /* I    input vector       [2 * len] */
    const opus_int   len     /* I    number of OUTPUT samples     */
)
{
    opus_int k;
    for( k = 0; k < len; k++ ) {
        out[ k ] = in[ 2 * k ] + in[ 2 * k + 1 ];
    }
}

static OPUS_INLINE void encode_split(
    ec_enc                      *psRangeEnc,    /* I/O  compressor data structure                   */
    const opus_int              p_child1,       /* I    pulse amplitude of first child subframe     */
    const opus_int              p,              /* I    pulse amplitude of current subframe         */
    const opus_uint8            *shell_table    /* I    table of shell cdfs                         */
)
{
    if( p > 0 ) {
        ec_enc_icdf( psRangeEnc, p_child1, &shell_table[ get_silk_shell_code_table_offsets()[ p ] ], 8 );
    }
}

silk_shell_code_table_struct * get_silk_shell_code_table(void);
silk_shell_code_table_struct *shellCodeTablePtr = 0;
silk_shell_code_table_struct * get_silk_shell_code_table(void){
    if(shellCodeTablePtr == NULL){
        shellCodeTablePtr = (silk_shell_code_table_struct*)opus_alloc_scratch(sizeof(silk_shell_code_table_struct));

        opus_uint8 silk_shell_code_table0[ 152 ] = {
                128,      0,    214,     42,      0,    235,    128,     21,
                0,    244,    184,     72,     11,      0,    248,    214,
                128,     42,      7,      0,    248,    225,    170,     80,
                25,      5,      0,    251,    236,    198,    126,     54,
                18,      3,      0,    250,    238,    211,    159,     82,
                35,     15,      5,      0,    250,    231,    203,    168,
                128,     88,     53,     25,      6,      0,    252,    238,
                216,    185,    148,    108,     71,     40,     18,      4,
                0,    253,    243,    225,    199,    166,    128,     90,
                57,     31,     13,      3,      0,    254,    246,    233,
                212,    183,    147,    109,     73,     44,     23,     10,
                2,      0,    255,    250,    240,    223,    198,    166,
                128,     90,     58,     33,     16,      6,      1,      0,
                255,    251,    244,    231,    210,    181,    146,    110,
                75,     46,     25,     12,      5,      1,      0,    255,
                253,    248,    238,    221,    196,    164,    128,     92,
                60,     35,     18,      8,      3,      1,      0,    255,
                253,    249,    242,    229,    208,    180,    146,    110,
                76,     48,     27,     14,      7,      3,      1,      0
        };
        memcpy(shellCodeTablePtr->silk_shell_code_table0 , silk_shell_code_table0, 152);

        opus_uint8 silk_shell_code_table1[ 152 ] = {
                129,      0,    207,     50,      0,    236,    129,     20,
                0,    245,    185,     72,     10,      0,    249,    213,
                129,     42,      6,      0,    250,    226,    169,     87,
                27,      4,      0,    251,    233,    194,    130,     62,
                20,      4,      0,    250,    236,    207,    160,     99,
                47,     17,      3,      0,    255,    240,    217,    182,
                131,     81,     41,     11,      1,      0,    255,    254,
                233,    201,    159,    107,     61,     20,      2,      1,
                0,    255,    249,    233,    206,    170,    128,     86,
                50,     23,      7,      1,      0,    255,    250,    238,
                217,    186,    148,    108,     70,     39,     18,      6,
                1,      0,    255,    252,    243,    226,    200,    166,
                128,     90,     56,     30,     13,      4,      1,      0,
                255,    252,    245,    231,    209,    180,    146,    110,
                76,     47,     25,     11,      4,      1,      0,    255,
                253,    248,    237,    219,    194,    163,    128,     93,
                62,     37,     19,      8,      3,      1,      0,    255,
                254,    250,    241,    226,    205,    177,    145,    111,
                79,     51,     30,     15,      6,      2,      1,      0
        };
        memcpy(shellCodeTablePtr->silk_shell_code_table1 , silk_shell_code_table1, 152);

        opus_uint8 silk_shell_code_table2[ 152 ] = {
                129,      0,    203,     54,      0,    234,    129,     23,
                0,    245,    184,     73,     10,      0,    250,    215,
                129,     41,      5,      0,    252,    232,    173,     86,
                24,      3,      0,    253,    240,    200,    129,     56,
                15,      2,      0,    253,    244,    217,    164,     94,
                38,     10,      1,      0,    253,    245,    226,    189,
                132,     71,     27,      7,      1,      0,    253,    246,
                231,    203,    159,    105,     56,     23,      6,      1,
                0,    255,    248,    235,    213,    179,    133,     85,
                47,     19,      5,      1,      0,    255,    254,    243,
                221,    194,    159,    117,     70,     37,     12,      2,
                1,      0,    255,    254,    248,    234,    208,    171,
                128,     85,     48,     22,      8,      2,      1,      0,
                255,    254,    250,    240,    220,    189,    149,    107,
                67,     36,     16,      6,      2,      1,      0,    255,
                254,    251,    243,    227,    201,    166,    128,     90,
                55,     29,     13,      5,      2,      1,      0,    255,
                254,    252,    246,    234,    213,    183,    147,    109,
                73,     43,     22,     10,      4,      2,      1,      0
        };
        memcpy(shellCodeTablePtr->silk_shell_code_table2 , silk_shell_code_table2, 152);

        opus_uint8 silk_shell_code_table3[ 152 ] = {
                130,      0,    200,     58,      0,    231,    130,     26,
                0,    244,    184,     76,     12,      0,    249,    214,
                130,     43,      6,      0,    252,    232,    173,     87,
                24,      3,      0,    253,    241,    203,    131,     56,
                14,      2,      0,    254,    246,    221,    167,     94,
                35,      8,      1,      0,    254,    249,    232,    193,
                130,     65,     23,      5,      1,      0,    255,    251,
                239,    211,    162,     99,     45,     15,      4,      1,
                0,    255,    251,    243,    223,    186,    131,     74,
                33,     11,      3,      1,      0,    255,    252,    245,
                230,    202,    158,    105,     57,     24,      8,      2,
                1,      0,    255,    253,    247,    235,    214,    179,
                132,     84,     44,     19,      7,      2,      1,      0,
                255,    254,    250,    240,    223,    196,    159,    112,
                69,     36,     15,      6,      2,      1,      0,    255,
                254,    253,    245,    231,    209,    176,    136,     93,
                55,     27,     11,      3,      2,      1,      0,    255,
                254,    253,    252,    239,    221,    194,    158,    117,
                76,     42,     18,      4,      3,      2,      1,      0
        };
        memcpy(shellCodeTablePtr->silk_shell_code_table3 , silk_shell_code_table3, 152);
    }

    return shellCodeTablePtr;
}

/* Shell encoder, operates on one shell code frame of 16 pulses */
void silk_shell_encoder(
    ec_enc                      *psRangeEnc,                    /* I/O  compressor data structure                   */
    const opus_int              *pulses0                        /* I    data: nonnegative pulse amplitudes          */
)
{
    opus_int pulses1[ 8 ], pulses2[ 4 ], pulses3[ 2 ], pulses4[ 1 ];


    /* tree representation per pulse-subframe */
    combine_pulses( pulses1, pulses0, 8 );
    combine_pulses( pulses2, pulses1, 4 );
    combine_pulses( pulses3, pulses2, 2 );
    combine_pulses( pulses4, pulses3, 1 );

    encode_split( psRangeEnc, pulses3[  0 ], pulses4[ 0 ], get_silk_shell_code_table()->silk_shell_code_table3 );

    encode_split( psRangeEnc, pulses2[  0 ], pulses3[ 0 ], get_silk_shell_code_table()->silk_shell_code_table2 );

    encode_split( psRangeEnc, pulses1[  0 ], pulses2[ 0 ], get_silk_shell_code_table()->silk_shell_code_table1 );
    encode_split( psRangeEnc, pulses0[  0 ], pulses1[ 0 ], get_silk_shell_code_table()->silk_shell_code_table0 );
    encode_split( psRangeEnc, pulses0[  2 ], pulses1[ 1 ], get_silk_shell_code_table()->silk_shell_code_table0 );

    encode_split( psRangeEnc, pulses1[  2 ], pulses2[ 1 ], get_silk_shell_code_table()->silk_shell_code_table1 );
    encode_split( psRangeEnc, pulses0[  4 ], pulses1[ 2 ], get_silk_shell_code_table()->silk_shell_code_table0 );
    encode_split( psRangeEnc, pulses0[  6 ], pulses1[ 3 ], get_silk_shell_code_table()->silk_shell_code_table0 );

    encode_split( psRangeEnc, pulses2[  2 ], pulses3[ 1 ], get_silk_shell_code_table()->silk_shell_code_table2 );

    encode_split( psRangeEnc, pulses1[  4 ], pulses2[ 2 ], get_silk_shell_code_table()->silk_shell_code_table1 );
    encode_split( psRangeEnc, pulses0[  8 ], pulses1[ 4 ], get_silk_shell_code_table()->silk_shell_code_table0 );
    encode_split( psRangeEnc, pulses0[ 10 ], pulses1[ 5 ], get_silk_shell_code_table()->silk_shell_code_table0 );

    encode_split( psRangeEnc, pulses1[  6 ], pulses2[ 3 ], get_silk_shell_code_table()->silk_shell_code_table1 );
    encode_split( psRangeEnc, pulses0[ 12 ], pulses1[ 6 ], get_silk_shell_code_table()->silk_shell_code_table0 );
    encode_split( psRangeEnc, pulses0[ 14 ], pulses1[ 7 ], get_silk_shell_code_table()->silk_shell_code_table0 );
}


