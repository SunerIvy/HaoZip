/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchPPCDecoder.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranchPPCDecoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCBranchPPCDecoder::SubFilter(byte_t* data, uint32_t size)
{
    return (uint32_t)::PPC_Convert(data, size, m_bufferPos, 0);
}

END_NAMESPACE_RCZIP
