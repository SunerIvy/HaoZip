/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/WzAES/RCWzAESKeyInfo.h"

/////////////////////////////////////////////////////////////////
//RCWzAESKeyInfo class implementation

BEGIN_NAMESPACE_RCZIP

RCWzAESKeyInfo::RCWzAESKeyInfo()
{
    Init();
}

RCWzAESKeyInfo::~RCWzAESKeyInfo()
{
}

void RCWzAESKeyInfo::Init()
{
    m_keySizeMode = 3 ;
}

uint32_t RCWzAESKeyInfo::GetKeySize() const
{
    return (8 * (m_keySizeMode & 3) + 8) ;
}

uint32_t RCWzAESKeyInfo::GetSaltSize() const
{
    return (4 * (m_keySizeMode & 3) + 4);
}

END_NAMESPACE_RCZIP
