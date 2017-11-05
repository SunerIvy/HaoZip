/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchBCJx86Decoder.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranchBCJx86Decoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCBranchBCJx86Decoder::SubFilter(byte_t* data, uint32_t size)
{
    return (uint32_t)::x86_Convert(data, size, m_bufferPos, &m_prevMask, 0);
}

void RCBranchBCJx86Decoder::SubInit() 
{
    x86Init() ;
}

END_NAMESPACE_RCZIP
