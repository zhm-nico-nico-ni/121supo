/* Copyright (c) 2010-2011 Xiph.Org Foundation, Skype Limited
   Written by Jean-Marc Valin and Koen Vos */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @file opus_defines.h
 * @brief Opus reference implementation constants
 */

#ifndef OPUS_DEFINES_H
#define OPUS_DEFINES_H

#include "opus_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup opus_errorcodes Error codes
 * @{
 */
/** No error @hideinitializer*/
#define OPUS_OK                0
/** One or more invalid/out of range arguments @hideinitializer*/
#define OPUS_BAD_ARG          -1
/** Not enough bytes allocated in the buffer @hideinitializer*/
#define OPUS_BUFFER_TOO_SMALL -2
/** An internal error was detected @hideinitializer*/
#define OPUS_INTERNAL_ERROR   -3
/** The compressed data passed is corrupted @hideinitializer*/
#define OPUS_INVALID_PACKET   -4
/** Invalid/unsupported request number @hideinitializer*/
#define OPUS_UNIMPLEMENTED    -5
/** An encoder or decoder structure is invalid or already freed @hideinitializer*/
#define OPUS_INVALID_STATE    -6
/** Memory allocation has failed @hideinitializer*/
#define OPUS_ALLOC_FAIL       -7
/**@}*/

/** @cond OPUS_INTERNAL_DOC */
/**Export control for opus functions */

#ifndef OPUS_EXPORT
# if defined(WIN32)
#  if defined(OPUS_BUILD) && defined(DLL_EXPORT)
#   define OPUS_EXPORT __declspec(dllexport)
#  else
#   define OPUS_EXPORT
#  endif
# elif defined(__GNUC__) && defined(OPUS_BUILD)
#  define OPUS_EXPORT __attribute__ ((visibility ("default")))
# else
#  define OPUS_EXPORT
# endif
#endif

# if !defined(OPUS_GNUC_PREREQ)
#  if defined(__GNUC__)&&defined(__GNUC_MINOR__)
#   define OPUS_GNUC_PREREQ(_maj,_min) \
 ((__GNUC__<<16)+__GNUC_MINOR__>=((_maj)<<16)+(_min))
#  else
#   define OPUS_GNUC_PREREQ(_maj,_min) 0
#  endif
# endif

#if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L) )
# if OPUS_GNUC_PREREQ(3,0)
#  define OPUS_RESTRICT __restrict__
# elif (defined(_MSC_VER) && _MSC_VER >= 1400)
#  define OPUS_RESTRICT __restrict
# else
#  define OPUS_RESTRICT
# endif
#else
# define OPUS_RESTRICT restrict
#endif

#if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L) )
# if OPUS_GNUC_PREREQ(2,7)
#  define OPUS_INLINE __inline__
# elif (defined(_MSC_VER))
#  define OPUS_INLINE __inline
# else
#  define OPUS_INLINE
# endif
#else
# define OPUS_INLINE inline
#endif

/**Warning attributes for opus functions
  * NONNULL is not used in OPUS_BUILD to avoid the compiler optimizing out
  * some paranoid null checks. */
#if defined(__GNUC__) && OPUS_GNUC_PREREQ(3, 4)
# define OPUS_WARN_UNUSED_RESULT __attribute__ ((__warn_unused_result__))
#else
# define OPUS_WARN_UNUSED_RESULT
#endif
#if !defined(OPUS_BUILD) && defined(__GNUC__) && OPUS_GNUC_PREREQ(3, 4)
# define OPUS_ARG_NONNULL(_x)  __attribute__ ((__nonnull__(_x)))
#else
# define OPUS_ARG_NONNULL(_x)
#endif

/** These are the actual Encoder CTL ID numbers.
  * They should not be used directly by applications.
  * In general, SETs should be even and GETs should be odd.*/
#define OPUS_SET_APPLICATION_REQUEST         4000
#define OPUS_GET_APPLICATION_REQUEST         4001
#define OPUS_SET_BITRATE_REQUEST             4002
#define OPUS_GET_BITRATE_REQUEST             4003
#define OPUS_SET_MAX_BANDWIDTH_REQUEST       4004
#define OPUS_GET_MAX_BANDWIDTH_REQUEST       4005
#define OPUS_SET_VBR_REQUEST                 4006
#define OPUS_GET_VBR_REQUEST                 4007
#define OPUS_SET_BANDWIDTH_REQUEST           4008
#define OPUS_GET_BANDWIDTH_REQUEST           4009
#define OPUS_SET_COMPLEXITY_REQUEST          4010
#define OPUS_GET_COMPLEXITY_REQUEST          4011
#define OPUS_SET_INBAND_FEC_REQUEST          4012
#define OPUS_GET_INBAND_FEC_REQUEST          4013
#define OPUS_SET_PACKET_LOSS_PERC_REQUEST    4014
#define OPUS_GET_PACKET_LOSS_PERC_REQUEST    4015
#define OPUS_SET_DTX_REQUEST                 4016
#define OPUS_GET_DTX_REQUEST                 4017
#define OPUS_SET_VBR_CONSTRAINT_REQUEST      4020
#define OPUS_GET_VBR_CONSTRAINT_REQUEST      4021
#define OPUS_SET_FORCE_CHANNELS_REQUEST      4022
#define OPUS_GET_FORCE_CHANNELS_REQUEST      4023
#define OPUS_SET_SIGNAL_REQUEST              4024
#define OPUS_GET_SIGNAL_REQUEST              4025
#define OPUS_GET_LOOKAHEAD_REQUEST           4027
/* #define OPUS_RESET_STATE 4028 */
#define OPUS_GET_SAMPLE_RATE_REQUEST         4029
#define OPUS_GET_FINAL_RANGE_REQUEST         4031
#define OPUS_GET_PITCH_REQUEST               4033
#define OPUS_SET_GAIN_REQUEST                4034
#define OPUS_GET_GAIN_REQUEST                4045 /* Should have been 4035 */
#define OPUS_SET_LSB_DEPTH_REQUEST           4036
#define OPUS_GET_LSB_DEPTH_REQUEST           4037
#define OPUS_GET_LAST_PACKET_DURATION_REQUEST 4039
#define OPUS_SET_EXPERT_FRAME_DURATION_REQUEST 4040
#define OPUS_GET_EXPERT_FRAME_DURATION_REQUEST 4041
#define OPUS_SET_PREDICTION_DISABLED_REQUEST 4042
#define OPUS_GET_PREDICTION_DISABLED_REQUEST 4043
/* Don't use 4045, it's already taken by OPUS_GET_GAIN_REQUEST */
#define OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST 4046
#define OPUS_GET_PHASE_INVERSION_DISABLED_REQUEST 4047

/* Macros to trigger compilation errors when the wrong types are provided to a CTL */
#define __opus_check_int(x) (((void)((x) == (opus_int32)0)), (opus_int32)(x))
#define __opus_check_int_ptr(ptr) ((ptr) + ((ptr) - (opus_int32*)(ptr)))
#define __opus_check_uint_ptr(ptr) ((ptr) + ((ptr) - (opus_uint32*)(ptr)))
#define __opus_check_val16_ptr(ptr) ((ptr) + ((ptr) - (opus_val16*)(ptr)))
/** @endcond */

/** @defgroup opus_ctlvalues Pre-defined values for CTL interface
  * @see opus_genericctls, opus_encoderctls
  * @{
  */
/* Values for the various encoder CTLs */
#define OPUS_AUTO                           -1000 /**<Auto/default setting @hideinitializer*/
#define OPUS_BITRATE_MAX                       -1 /**<Maximum bitrate @hideinitializer*/

/** Best for most VoIP/videoconference applications where listening quality and intelligibility matter most
 * @hideinitializer */
#define OPUS_APPLICATION_VOIP                2048
/** Best for broadcast/high-fidelity application where the decoded audio should be as close as possible to the input
 * @hideinitializer */
#define OPUS_APPLICATION_AUDIO               2049
/** Only use when lowest-achievable latency is what matters most. Voice-optimized modes cannot be used.
 * @hideinitializer */
#define OPUS_APPLICATION_RESTRICTED_LOWDELAY 2051

#define OPUS_SIGNAL_VOICE                    3001 /**< Signal being encoded is voice */
#define OPUS_SIGNAL_MUSIC                    3002 /**< Signal being encoded is music */
#define OPUS_BANDWIDTH_NARROWBAND            1101 /**< 4 kHz bandpass @hideinitializer*/
#define OPUS_BANDWIDTH_MEDIUMBAND            1102 /**< 6 kHz bandpass @hideinitializer*/
#define OPUS_BANDWIDTH_WIDEBAND              1103 /**< 8 kHz bandpass @hideinitializer*/
#define OPUS_BANDWIDTH_SUPERWIDEBAND         1104 /**<12 kHz bandpass @hideinitializer*/
#define OPUS_BANDWIDTH_FULLBAND              1105 /**<20 kHz bandpass @hideinitializer*/

#define OPUS_FRAMESIZE_ARG                   5000 /**< Select frame size from the argument (default) */
#define OPUS_FRAMESIZE_2_5_MS                5001 /**< Use 2.5 ms frames */
#define OPUS_FRAMESIZE_5_MS                  5002 /**< Use 5 ms frames */
#define OPUS_FRAMESIZE_10_MS                 5003 /**< Use 10 ms frames */
#define OPUS_FRAMESIZE_20_MS                 5004 /**< Use 20 ms frames */
#define OPUS_FRAMESIZE_40_MS                 5005 /**< Use 40 ms frames */
#define OPUS_FRAMESIZE_60_MS                 5006 /**< Use 60 ms frames */
#define OPUS_FRAMESIZE_80_MS                 5007 /**< Use 80 ms frames */
#define OPUS_FRAMESIZE_100_MS                5008 /**< Use 100 ms frames */
#define OPUS_FRAMESIZE_120_MS                5009 /**< Use 120 ms frames */

/**@}*/

/** Resets the codec state to be equivalent to a freshly initialized state.
  * This should be called when switching streams in order to prevent
  * the back to back decoding from giving different results from
  * one at a time decoding.
  * @hideinitializer */
#define OPUS_RESET_STATE 4028



#ifdef __cplusplus
}
#endif

#endif /* OPUS_DEFINES_H */
