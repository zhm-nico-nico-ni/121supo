/* Copyright (C) 2007-2009 Xiph.Org Foundation
   Copyright (C) 2003-2008 Jean-Marc Valin
   Copyright (C) 2007-2008 CSIRO */
/**
   @file fixed_generic.h
   @brief Generic fixed-point operations
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

#ifndef FIXED_GENERIC_H
#define FIXED_GENERIC_H

/** Compile-time conversion of float constant to 16-bit value */
#define QCONST16(x,bits) ((opus_val16)(.5+(x)*(((opus_val32)1)<<(bits))))


/** Change a 32-bit value into a 16-bit value. The value is assumed to fit in 16-bit, otherwise the result is undefined */
#define EXTRACT16(x) ((opus_val16)(x))
/** Change a 16-bit value into a 32-bit value */
#define EXTEND32(x) ((opus_val32)(x))

/** Arithmetic shift-right of a 16-bit value */
#define SHR16(a,shift) ((a) >> (shift))
/** Arithmetic shift-right of a 32-bit value */
#define SHR32(a,shift) ((a) >> (shift))
/** Arithmetic shift-left of a 32-bit value */
#define SHL32(a,shift) ((opus_int32)((opus_uint32)(a)<<(shift)))

/** 32-bit arithmetic shift right with rounding-to-nearest instead of rounding down */
#define PSHR32(a,shift) (SHR32((a)+((EXTEND32(1)<<((shift))>>1)),shift))

/** "RAW" macros, should not be used outside of this header file */
#define SHR(a,shift) ((a) >> (shift))
#define SATURATE(x,a) (((x)>(a) ? (a) : (x)<-(a) ? -(a) : (x)))


/** Shift by a and round-to-neareast 32-bit value. Result is a 16-bit value */
//#define ROUND16(x,a) (EXTRACT16(PSHR32((x),(a))))

/** Divide by two */
#define HALF16(x)  (SHR16(x,1))
//#define HALF32(x)  (SHR32(x,1))

/** Add two 32-bit values */
#define ADD32(a,b) ((opus_val32)(a)+(opus_val32)(b))

/* (opus_val32)(opus_val16) gives TI compiler a hint that it's 16x16->32 multiply */
/** 16x16 multiplication where the result fits in 32 bits */
#define MULT16_16(a,b)     (((opus_val32)(opus_val16)(a))*((opus_val32)(opus_val16)(b)))

/** 16x16 multiply-add where the result fits in 32 bits */
#define MAC16_16(c,a,b) (ADD32((c),MULT16_16((a),(b))))
#define MULT16_16_Q15(a,b) (SHR(MULT16_16((a),(b)),15))


#if defined(MIPSr1_ASM)
#include "mips/fixed_generic_mipsr1.h"
#endif

#endif
