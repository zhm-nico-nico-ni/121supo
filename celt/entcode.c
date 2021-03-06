/* Copyright (c) 2001-2011 Timothy B. Terriberry
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



#include "entcode.h"


int ec_ilog(opus_uint32 _v){
  /*On a Pentium M, this branchless version tested as the fastest on
     1,000,000,000 random 32-bit integers, edging out a similar version with
     branches, and a 256-entry LUT version.*/
  int ret;
  int m;
  ret= _v != 0;
  m= ((_v & 0xFFFF0000LL) != 0) << 4;
  _v>>=m;
  ret|=m;
  m= ((_v & 0xFF00) != 0) << 3;
  _v>>=m;
  ret|=m;
  m= ((_v & 0xF0) != 0) << 2;
  _v>>=m;
  ret|=m;
  m= ((_v & 0xC) != 0) << 1;
  _v>>=m;
  ret|=m;
  ret+= (_v & 0x2) != 0;
  return ret;
}


