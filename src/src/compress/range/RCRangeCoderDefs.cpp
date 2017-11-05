/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/range/RCRangeCoderDefs.h"

/////////////////////////////////////////////////////////////////
//RCRangeCoderDefs class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCRangeCoderDefs::s_probPrices[s_kBitModelTotal >> s_kNumMoveReducingBits] ;

RCRangeCoderDefs::RCRangeCoderDefs()
{
    for (uint32_t i = (1 << s_kNumMoveReducingBits) / 2; i < s_kBitModelTotal; i += (1 << s_kNumMoveReducingBits))
    {
        const int kCyclesBits = s_kNumBitPriceShiftBits;
        uint32_t w = i;
        uint32_t bitCount = 0;
        for (int j = 0; j < kCyclesBits; j++)
        {
            w = w * w;
            bitCount <<= 1;
            while (w >= ((uint32_t)1 << 16))
            {
                w >>= 1;
                bitCount++;
            }
        }
        s_probPrices[i >> s_kNumMoveReducingBits] = ((s_kNumBitModelTotalBits << kCyclesBits) - 15 - bitCount);
    }
}

RCRangeCoderDefs::~RCRangeCoderDefs()
{
}


END_NAMESPACE_RCZIP
