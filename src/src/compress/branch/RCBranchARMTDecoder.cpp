/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchARMTDecoder.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranchARMTDecoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCBranchARMTDecoder::SubFilter(byte_t* data, uint32_t size)
{
    return (uint32_t)::ARMT_Convert(data, size, m_bufferPos, 0);
}

END_NAMESPACE_RCZIP
