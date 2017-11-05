/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/bzip2/RCBZip2CombinedCRC.h"

/////////////////////////////////////////////////////////////////
//RCBZip2CombinedCRC class implementation

BEGIN_NAMESPACE_RCZIP

RCBZip2CombinedCRC::RCBZip2CombinedCRC():
    m_value(0)
{
}

RCBZip2CombinedCRC::~RCBZip2CombinedCRC()
{
}

void RCBZip2CombinedCRC::Init()
{
    m_value = 0;
}

void RCBZip2CombinedCRC::Update(uint32_t v)
{
    m_value = ((m_value << 1) | (m_value >> 31)) ^ v;
}

uint32_t RCBZip2CombinedCRC::GetDigest() const
{
    return m_value ;
}

END_NAMESPACE_RCZIP
