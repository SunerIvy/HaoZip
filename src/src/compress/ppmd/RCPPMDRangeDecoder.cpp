/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/ppmd/RCPPMDRangeDecoder.h"

/////////////////////////////////////////////////////////////////
//RCPPMDRangeDecoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCPPMDRangeDecoder::GetThreshold(uint32_t total)
{
    return RCRangeDecoder::GetThreshold(total);
}

void RCPPMDRangeDecoder::Decode(uint32_t start, uint32_t size)
{
    RCRangeDecoder::Decode(start, size);
}

uint32_t RCPPMDRangeDecoder::DecodeBit(uint32_t size0, uint32_t numTotalBits)
{
    return RCRangeDecoder::DecodeBit(size0, numTotalBits);
}

END_NAMESPACE_RCZIP
