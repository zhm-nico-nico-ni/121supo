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

#ifndef SILK_DEFINE_H
#define SILK_DEFINE_H

#include "errors.h"
#include "typedef.h"



/* Max number of encoder channels (1/2) */
#define ENCODER_NUM_CHANNELS                    1

#define MAX_FRAMES_PER_PACKET                   3

/* Limits on bitrate */
#define MIN_TARGET_RATE_BPS                     5000
#define MAX_TARGET_RATE_BPS                     80000
#define TARGET_RATE_TAB_SZ                      8


/* DTX settings */
#define NB_SPEECH_FRAMES_BEFORE_DTX             10      /* eq 200 ms */
#define MAX_CONSECUTIVE_DTX                     20      /* eq 400 ms */

/* Maximum sampling frequency */
#define MAX_FS_KHZ                              16

/* Signal types */
#define TYPE_NO_VOICE_ACTIVITY                  0
#define TYPE_VOICED                             2

/* Conditional coding types */
#define CODE_INDEPENDENTLY                      0
#define CODE_INDEPENDENTLY_NO_LTP_SCALING       1
#define CODE_CONDITIONALLY                      2


/* Range of pitch lag estimates */
//#define PITCH_EST_MIN_LAG_MS                    2       /* 2 ms -> 500 Hz */
//#define PITCH_EST_MAX_LAG_MS                    18      /* 18 ms -> 56 Hz */

/* Maximum number of subframes */
#define MAX_NB_SUBFR                            4

/* Number of samples per frame */
#define LTP_MEM_LENGTH_MS                       10
#define SUB_FRAME_LENGTH_MS                     5
#define MAX_SUB_FRAME_LENGTH                    ( SUB_FRAME_LENGTH_MS * MAX_FS_KHZ )
#define MAX_FRAME_LENGTH_MS                     ( SUB_FRAME_LENGTH_MS * MAX_NB_SUBFR )
#define MAX_FRAME_LENGTH                        ( MAX_FRAME_LENGTH_MS * MAX_FS_KHZ )

/* Milliseconds of lookahead for pitch analysis */
#define LA_PITCH_MS                             2

/* Order of LPC used in find pitch */
#define MAX_FIND_PITCH_LPC_ORDER                16

/* Length of LPC window used in find pitch */
#define FIND_PITCH_LPC_WIN_MS                   ( 20 + (LA_PITCH_MS << 1) )
#define FIND_PITCH_LPC_WIN_MS_2_SF              ( 10 + (LA_PITCH_MS << 1) )

/* Milliseconds of lookahead for noise shape analysis */
#define LA_SHAPE_MS                             5
#define LA_SHAPE_MAX                            ( LA_SHAPE_MS * MAX_FS_KHZ )

/* dB level of lowest gain quantization level */
#define MIN_QGAIN_DB                            2
/* dB level of highest gain quantization level */
#define MAX_QGAIN_DB                            88
/* Number of gain quantization levels */
#define N_LEVELS_QGAIN                          64
/* Max increase in gain quantization index */
#define MAX_DELTA_GAIN_QUANT                    36
/* Max decrease in gain quantization index */
#define MIN_DELTA_GAIN_QUANT                    -4

/* Quantization offsets (multiples of 4) */
#define OFFSET_VL_Q10                           32
#define OFFSET_VH_Q10                           100
#define OFFSET_UVL_Q10                          100
#define OFFSET_UVH_Q10                          240

#define QUANT_LEVEL_ADJUST_Q10                  80

/* Maximum numbers of iterations used to stabilize an LPC vector */
#define MAX_LPC_STABILIZE_ITERATIONS            16
#define MAX_PREDICTION_POWER_GAIN               1e4f
#define MAX_PREDICTION_POWER_GAIN_AFTER_RESET   1e2f

#define MAX_LPC_ORDER                           16

/* Find Pred Coef defines */
#define LTP_ORDER                               5


/* Flag to use harmonic noise shaping */
#define USE_HARM_SHAPING                        0

/* Max LPC order of noise shaping filters */
#define MAX_SHAPE_LPC_ORDER                     24

#define HARM_SHAPE_FIR_TAPS                     3

/* Maximum number of delayed decision states */
#define MAX_DEL_DEC_STATES                      4

#define DECISION_DELAY                          40

/* Number of subframes for excitation entropy coding */
#define SHELL_CODEC_FRAME_LENGTH                16
#define LOG2_SHELL_CODEC_FRAME_LENGTH           4
#define MAX_NB_SHELL_BLOCKS                     ( MAX_FRAME_LENGTH / SHELL_CODEC_FRAME_LENGTH )

/* Number of rate levels, for entropy coding of excitation */
#define N_RATE_LEVELS                           10

/* Maximum sum of pulses per shell coding frame */
#define SILK_MAX_PULSES                         16


#define NSQ_LPC_BUF_LENGTH                     MAX_LPC_ORDER

/***************************/
/* Voice activity detector */
/***************************/
#define VAD_N_BANDS                             2

/* Size of the piecewise linear cosine approximation table for the LSFs */
#define LSF_COS_TAB_SZ_FIX                      128

/******************/
/* NLSF quantizer */
/******************/
#define NLSF_W_Q                                2
#define NLSF_QUANT_MAX_AMPLITUDE                4
#define NLSF_QUANT_MAX_AMPLITUDE_EXT            10
#define NLSF_QUANT_LEVEL_ADJ                    0.1
#define NLSF_QUANT_DEL_DEC_STATES_LOG2          2
#define NLSF_QUANT_DEL_DEC_STATES               ( 1 << NLSF_QUANT_DEL_DEC_STATES_LOG2 )

/* Transition filtering for mode switching */
#define TRANSITION_TIME_MS                      5120    /* 5120 = 64 * FRAME_LENGTH_MS * ( TRANSITION_INT_NUM - 1 ) = 64*(20*4)*/
#define TRANSITION_FRAMES                       ( TRANSITION_TIME_MS / MAX_FRAME_LENGTH_MS )





#endif
