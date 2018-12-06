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



#include "pitch_est_defines.h"
#include "../celt/os_support.h"



pitch_analysis_core_table_struct *s_pitch_analysis_core_table_struct_ptr = 0;
pitch_analysis_core_table_struct * get_pitch_analysis_core_table_struct(void){
    if(s_pitch_analysis_core_table_struct_ptr == NULL) {
        s_pitch_analysis_core_table_struct_ptr = opus_alloc_scratch(sizeof(pitch_analysis_core_table_struct));

        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][1] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][2] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][3] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][4] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][6] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][7] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][8] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][9] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[0][10] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][1] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][2] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][3] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][6] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][7] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][8] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][9] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[1][10] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][1] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][2] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][3] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][6] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][7] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][8] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][9] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[2][10] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][1] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][2] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][3] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][5] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][6] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][7] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][8] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][9] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2[3][10] = -1;


        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][1] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][2] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][3] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][5] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][6] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][7] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][8] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][9] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][10] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][11] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][12] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][13] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][14] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][15] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][16] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][17] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][18] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][19] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][20] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][21] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][22] = 4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][23] = 4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][24] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][25] = 5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][26] = -6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][27] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][28] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][29] = -7;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][30] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][31] = 5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][32] = 8;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[0][33] = -9;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][1] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][2] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][3] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][6] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][7] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][8] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][9] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][10] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][11] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][12] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][13] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][14] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][15] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][16] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][17] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][18] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][19] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][20] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][21] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][22] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][23] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][24] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][25] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][26] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][27] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][28] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][29] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][30] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][31] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][32] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[1][33] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][1] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][2] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][3] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][4] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][6] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][7] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][8] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][9] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][10] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][11] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][12] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][13] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][14] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][15] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][16] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][17] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][18] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][19] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][20] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][21] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][22] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][23] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][24] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][25] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][26] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][27] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][28] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][29] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][30] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][31] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][32] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[2][33] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][1] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][2] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][3] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][4] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][5] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][6] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][7] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][8] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][9] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][10] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][11] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][12] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][13] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][14] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][15] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][16] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][17] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][18] = 4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][19] = 4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][20] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][21] = 5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][22] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][23] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][24] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][25] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][26] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][27] = 5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][28] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][29] = 8;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][30] = -6;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][31] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][32] = -7;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3[3][33] = 9;


        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][0][0] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][0][1] = 8;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][1][0] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][1][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][2][0] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][2][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][3][0] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[0][3][1] = 10;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][0][0] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][0][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][1][0] = -4;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][1][1] = 10;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][2][0] = -6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][2][1] = 10;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][3][0] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[1][3][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][0][0] = -6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][0][1] = 10;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][1][0] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][1][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][2][0] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][2][1] = 6;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][3][0] = -5;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3[2][3][1] = 10;


        s_pitch_analysis_core_table_struct_ptr->silk_nb_cbk_searchs_stage3[0] = 16;
        s_pitch_analysis_core_table_struct_ptr->silk_nb_cbk_searchs_stage3[1] = 24;
        s_pitch_analysis_core_table_struct_ptr->silk_nb_cbk_searchs_stage3[2] = 34;


        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[0][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[0][1] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[0][2] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[1][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[1][1] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage2_10_ms[1][2] = 1;


        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][1] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][2] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][3] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][4] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][5] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][6] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][7] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][8] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][9] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][10] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[0][11] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][0] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][1] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][2] = 0;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][3] = 1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][4] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][5] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][6] = -1;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][7] = 2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][8] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][9] = 3;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][10] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_CB_lags_stage3_10_ms[1][11] = 3;


        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3_10_ms[0][0] = -3;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3_10_ms[0][1] = 7;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3_10_ms[1][0] = -2;
        s_pitch_analysis_core_table_struct_ptr->silk_Lag_range_stage3_10_ms[1][1] = 7;
    }

    return s_pitch_analysis_core_table_struct_ptr;
}