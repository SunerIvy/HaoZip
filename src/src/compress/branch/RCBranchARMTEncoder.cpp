/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchARMTEncoder.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranchARMTEncoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCBranchARMTEncoder::SubFilter(byte_t* data, uint32_t size)
{
    return (uint32_t)::ARMT_Convert(data, size, m_bufferPos, 1) ;
}

END_NAMESPACE_RCZIP
