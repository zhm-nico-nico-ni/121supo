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



/* Approximate sigmoid function */

#include "SigProc_FIX.h"
#include "../celt/os_support.h"

const opus_int32 *get_sigm_LUT_slope_Q10(void);
/* fprintf(1, '%d, ', round(1024 * ([1 ./ (1 + exp(-(1:5))), 1] - 1 ./ (1 + exp(-(0:5)))))); */
opus_int32 * sigm_LUT_slope_Q10ptr = 0;
const opus_int32 *get_sigm_LUT_slope_Q10(void){
    if(sigm_LUT_slope_Q10ptr == 0){
        sigm_LUT_slope_Q10ptr = opus_alloc_scratch(sizeof(opus_int32) * 6);

        sigm_LUT_slope_Q10ptr[0] = 237;
        sigm_LUT_slope_Q10ptr[1] = 153;
        sigm_LUT_slope_Q10ptr[2] = 73;
        sigm_LUT_slope_Q10ptr[3] = 30;
        sigm_LUT_slope_Q10ptr[4] = 12;
        sigm_LUT_slope_Q10ptr[5] = 7;
    }

    return sigm_LUT_slope_Q10ptr;
}

/* fprintf(1, '%d, ', round(32767 * 1 ./ (1 + exp(-(0:5))))); */

const opus_int32 *get_sigm_LUT_pos_Q15(void);
opus_int32 *sigm_LUT_pos_Q15ptr = 0;
const opus_int32 *get_sigm_LUT_pos_Q15(void){
    if(sigm_LUT_pos_Q15ptr == 0){
        sigm_LUT_pos_Q15ptr = opus_alloc_scratch(sizeof(opus_int32) * 6);

        sigm_LUT_pos_Q15ptr[0] = 16384;
        sigm_LUT_pos_Q15ptr[1] = 23955;
        sigm_LUT_pos_Q15ptr[2] = 28861;
        sigm_LUT_pos_Q15ptr[3] = 31213;
        sigm_LUT_pos_Q15ptr[4] = 32178;
        sigm_LUT_pos_Q15ptr[5] = 32548;
    }

    return sigm_LUT_pos_Q15ptr;
}

const opus_int32 *get_sigm_LUT_neg_Q15(void);
/* fprintf(1, '%d, ', round(32767 * 1 ./ (1 + exp((0:5))))); */
opus_int32 *sigm_LUT_neg_Q15ptr = 0;
const opus_int32 *get_sigm_LUT_neg_Q15(void){
    if(sigm_LUT_neg_Q15ptr == 0){
        sigm_LUT_neg_Q15ptr = opus_alloc_scratch(sizeof(opus_int32) * 6);

        sigm_LUT_neg_Q15ptr[0] = 16384;
        sigm_LUT_neg_Q15ptr[1] = 8812;
        sigm_LUT_neg_Q15ptr[2] = 3906;
        sigm_LUT_neg_Q15ptr[3] = 1554;
        sigm_LUT_neg_Q15ptr[4] = 589;
        sigm_LUT_neg_Q15ptr[5] = 219;
    }

    return sigm_LUT_neg_Q15ptr;
}


opus_int silk_sigm_Q15(
        opus_int                    in_Q5               /* I                                                                */
)
{
    opus_int ind;

    if( in_Q5 < 0 ) {
        /* Negative input */
        in_Q5 = -in_Q5;
        if( in_Q5 >= 6 * 32 ) {
            return 0;        /* Clip */
        } else {
            /* Linear interpolation of look up table */
            ind = silk_RSHIFT( in_Q5, 5 );
            return( get_sigm_LUT_neg_Q15()[ ind ] - silk_SMULBB( get_sigm_LUT_slope_Q10()[ ind ], in_Q5 & 0x1F ) );
        }
    } else {
        /* Positive input */
        if( in_Q5 >= 6 * 32 ) {
            return 32767;        /* clip */
        } else {
            /* Linear interpolation of look up table */
            ind = silk_RSHIFT( in_Q5, 5 );
            return( get_sigm_LUT_pos_Q15()[ ind ] + silk_SMULBB( get_sigm_LUT_slope_Q10()[ ind ], in_Q5 & 0x1F ) );
        }
    }
}

