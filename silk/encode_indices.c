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

/* Encode side-information parameters to payload */
void silk_encode_indices(
    silk_encoder_state          *psEncC,                        /* I/O  Encoder state                               */
    ec_enc                      *psRangeEnc,                    /* I/O  Compressor data structure                   */
    opus_int                    FrameIndex,                     /* I    Frame number                                */
    opus_int                    encode_LBRR,                    /* I    Flag indicating LBRR data is being encoded  */
    opus_int                    condCoding                      /* I    The type of conditional coding to use       */
)
{
    opus_int   i, k, typeOffset;
//    opus_int   encode_absolute_lagIndex;
    opus_int16 ec_ix[ MAX_LPC_ORDER ];
    opus_uint8 pred_Q8[ MAX_LPC_ORDER ];
    const SideInfoIndices *psIndices;

    if( encode_LBRR ) {
         psIndices = &psEncC->indices_LBRR[ FrameIndex ];
    } else {
         psIndices = &psEncC->indices;
    }

    /*******************************************/
    /* Encode signal type and quantizer offset */
    /*******************************************/
    typeOffset = 2 * psIndices->signalType + psIndices->quantOffsetType;
    if( encode_LBRR || typeOffset >= 2 ) {
        ec_enc_icdf( psRangeEnc, typeOffset - 2, get_silk_type_offset_VAD_iCDF(), 8 );
    } else {
        ec_enc_icdf( psRangeEnc, typeOffset, get_silk_type_offset_no_VAD_iCDF(), 8 );
    }

    /****************/
    /* Encode gains */
    /****************/
    /* first subframe */
    if( condCoding == CODE_CONDITIONALLY ) {
        /* conditional coding */
        ec_enc_icdf( psRangeEnc, psIndices->GainsIndices[ 0 ], get_silk_delta_gain_iCDF(), 8 );
    } else {
        /* independent coding, in two stages: MSB bits followed by 3 LSBs */
        ec_enc_icdf( psRangeEnc, silk_RSHIFT( psIndices->GainsIndices[ 0 ], 3 ), get_silk_gain_iCDF()[ psIndices->signalType ], 8 );
        ec_enc_icdf( psRangeEnc, psIndices->GainsIndices[ 0 ] & 7, get_silk_uniform8_iCDF(), 8 );
    }

    /* remaining subframes */
    for( i = 1; i < psEncC->nb_subfr; i++ ) {
        ec_enc_icdf( psRangeEnc, psIndices->GainsIndices[ i ], get_silk_delta_gain_iCDF(), 8 );
    }

    /****************/
    /* Encode NLSFs */
    /****************/
    ec_enc_icdf( psRangeEnc, psIndices->NLSFIndices[ 0 ], &psEncC->psNLSF_CB->CB1_iCDF[ ( psIndices->signalType >> 1 ) * psEncC->psNLSF_CB->nVectors ], 8 );
    silk_NLSF_unpack( ec_ix, pred_Q8, psEncC->psNLSF_CB, psIndices->NLSFIndices[ 0 ] );
    for( i = 0; i < psEncC->psNLSF_CB->order; i++ ) {
        if( psIndices->NLSFIndices[ i+1 ] >= NLSF_QUANT_MAX_AMPLITUDE ) {
            ec_enc_icdf( psRangeEnc, 2 * NLSF_QUANT_MAX_AMPLITUDE, &psEncC->psNLSF_CB->ec_iCDF[ ec_ix[ i ] ], 8 );
            ec_enc_icdf( psRangeEnc, psIndices->NLSFIndices[ i+1 ] - NLSF_QUANT_MAX_AMPLITUDE, get_silk_NLSF_EXT_iCDF(), 8 );
        } else if( psIndices->NLSFIndices[ i+1 ] <= -NLSF_QUANT_MAX_AMPLITUDE ) {
            ec_enc_icdf( psRangeEnc, 0, &psEncC->psNLSF_CB->ec_iCDF[ ec_ix[ i ] ], 8 );
            ec_enc_icdf( psRangeEnc, -psIndices->NLSFIndices[ i+1 ] - NLSF_QUANT_MAX_AMPLITUDE, get_silk_NLSF_EXT_iCDF(), 8 );
        } else {
            ec_enc_icdf( psRangeEnc, psIndices->NLSFIndices[ i+1 ] + NLSF_QUANT_MAX_AMPLITUDE, &psEncC->psNLSF_CB->ec_iCDF[ ec_ix[ i ] ], 8 );
        }
    }

    /* Encode NLSF interpolation factor */
    if( psEncC->nb_subfr == MAX_NB_SUBFR ) {
        ec_enc_icdf( psRangeEnc, psIndices->NLSFInterpCoef_Q2, get_silk_NLSF_interpolation_factor_iCDF(), 8 );
    }

    psEncC->ec_prevSignalType = psIndices->signalType;

    /***************/
    /* Encode seed */
    /***************/
    ec_enc_icdf( psRangeEnc, psIndices->Seed, get_silk_uniform4_iCDF(), 8 );
}
