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
//#define OPUS_UNIMPLEMENTED    -5
/** An encoder or decoder structure is invalid or already freed @hideinitializer*/
//#define OPUS_INVALID_STATE    -6
/** Memory allocation has failed @hideinitializer*/
#define OPUS_ALLOC_FAIL       -7
/**@}*/

/** @cond OPUS_INTERNAL_DOC */
/**Export control for opus functions */

#define OPUS_EXPORT

//# if !defined(OPUS_GNUC_PREREQ)
//#  if defined(__GNUC__)&&defined(__GNUC_MINOR__)
//#   define OPUS_GNUC_PREREQ(_maj,_min) \
// ((__GNUC__<<16)+__GNUC_MINOR__>=((_maj)<<16)+(_min))
//#  else
//#   define OPUS_GNUC_PREREQ(_maj,_min) 0
//#  endif
//# endif

//#if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L) )
//# if OPUS_GNUC_PREREQ(3,0)
//#  define OPUS_RESTRICT __restrict__
//# elif (defined(_MSC_VER) && _MSC_VER >= 1400)
//#  define OPUS_RESTRICT __restrict
//# else
//#  define OPUS_RESTRICT
//# endif
//#else
//# define OPUS_RESTRICT restrict
//#endif

//#if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L) )
//# if OPUS_GNUC_PREREQ(2,7)
//#  define OPUS_INLINE __inline__
//# elif (defined(_MSC_VER))
//#  define OPUS_INLINE __inline
//# else
#  define OPUS_INLINE __inline
//# endif
//#else
//# define OPUS_INLINE inline
//#endif

/**Warning attributes for opus functions
  * NONNULL is not used in OPUS_BUILD to avoid the compiler optimizing out
  * some paranoid null checks. */
//#if defined(__GNUC__) && OPUS_GNUC_PREREQ(3, 4)
//# define OPUS_WARN_UNUSED_RESULT __attribute__ ((__warn_unused_result__))
//#else
# define OPUS_WARN_UNUSED_RESULT
//#endif
//#if !defined(OPUS_BUILD) && defined(__GNUC__) && OPUS_GNUC_PREREQ(3, 4)
//# define OPUS_ARG_NONNULL(_x)  __attribute__ ((__nonnull__(_x)))
//#else
# define OPUS_ARG_NONNULL(_x)
//#endif

/** These are the actual Encoder CTL ID numbers.
  * They should not be used directly by applications.
  * In general, SETs should be even and GETs should be odd.*/
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
//#define OPUS_FRAMESIZE_5_MS                  5002 /**< Use 5 ms frames */
//#define OPUS_FRAMESIZE_10_MS                 5003 /**< Use 10 ms frames */
//#define OPUS_FRAMESIZE_20_MS                 5004 /**< Use 20 ms frames */
#define OPUS_FRAMESIZE_40_MS                 5005 /**< Use 40 ms frames */
//#define OPUS_FRAMESIZE_60_MS                 5006 /**< Use 60 ms frames */
//#define OPUS_FRAMESIZE_80_MS                 5007 /**< Use 80 ms frames */
//#define OPUS_FRAMESIZE_100_MS                5008 /**< Use 100 ms frames */
#define OPUS_FRAMESIZE_120_MS                5009 /**< Use 120 ms frames */

/**@}*/




#ifdef __cplusplus
}
#endif

#endif /* OPUS_DEFINES_H */
