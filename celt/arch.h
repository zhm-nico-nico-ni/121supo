/* Copyright (c) 2003-2008 Jean-Marc Valin
   Copyright (c) 2007-2008 CSIRO
   Copyright (c) 2007-2009 Xiph.Org Foundation
   Written by Jean-Marc Valin */
/**
   @file arch.h
   @brief Various architecture definitions for CELT
*/
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

#ifndef ARCH_H
#define ARCH_H

#include "../opus_include/opus_types.h"
#include "../opus_include/opus_defines.h"

//# if !defined(__GNUC_PREREQ)
//#  if defined(__GNUC__)&&defined(__GNUC_MINOR__)
//#   define __GNUC_PREREQ(_maj,_min) \
// ((__GNUC__<<16)+__GNUC_MINOR__>=((_maj)<<16)+(_min))
//#  else
//#   define __GNUC_PREREQ(_maj,_min) 0
//#  endif
//# endif

//#if OPUS_GNUC_PREREQ(3, 0)
//#define opus_likely(x)       (__builtin_expect(!!(x), 1))
//#define opus_unlikely(x)     (__builtin_expect(!!(x), 0))
//#else
#define opus_likely(x)       (!!(x))
#define opus_unlikely(x)     (!!(x))
//#endif



#define celt_assert(cond)
#define celt_assert2(cond, message)


#define IMUL32(a,b) ((a)*(b))

#define MIN16(a,b) ((a) < (b) ? (a) : (b))   /**< Minimum 16-bit value.   */
#define MAX16(a,b) ((a) > (b) ? (a) : (b))   /**< Maximum 16-bit value.   */
//#define MIN32(a,b) ((a) < (b) ? (a) : (b))   /**< Minimum 32-bit value.   */
#define MAX32(a,b) ((a) > (b) ? (a) : (b))   /**< Maximum 32-bit value.   */
#define IMIN(a,b) ((a) < (b) ? (a) : (b))   /**< Minimum int value.   */
#define IMAX(a,b) ((a) > (b) ? (a) : (b))   /**< Maximum int value.   */




typedef opus_int16 opus_val16;
typedef opus_int32 opus_val32;



/* Safe saturation value for 32-bit signals. Should be less than
   2^31*(1-0.85) to avoid blowing up on DC at deemphasis.*/


#define DB_SHIFT 10


#include "fixed_generic.h"

//#ifdef OPUS_ARM_PRESUME_AARCH64_NEON_INTR
//#include "arm/fixed_arm64.h"
//#elif OPUS_ARM_INLINE_EDSP
//#include "arm/fixed_armv5e.h"
//#elif defined (OPUS_ARM_INLINE_ASM)
//#include "arm/fixed_armv4.h"
//#elif defined (BFIN_ASM)
//#include "fixed_bfin.h"
//#elif defined (TI_C5X_ASM)
//#include "fixed_c5x.h"
//#elif defined (TI_C6X_ASM)
//#include "fixed_c6x.h"
//#endif





#ifndef GLOBAL_STACK_SIZE

#define GLOBAL_STACK_SIZE 120000 //TODO change this

#endif

#endif /* ARCH_H */
