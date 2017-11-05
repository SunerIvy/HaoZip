/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/wim/RCWimItem.h"

/////////////////////////////////////////////////////////////////
//RCWimItem class implementation

BEGIN_NAMESPACE_RCZIP

RCWimItem::RCWimItem():
    m_hasMetadata(true), 
    m_streamIndex(-1) 
{
}

RCWimItem::~RCWimItem()
{
}

bool RCWimItem::isDir() const
{
    return m_hasMetadata && ((m_attrib & 0x10) != 0);
}

bool RCWimItem::HasStream() const
{
    for (int32_t i = 0; i < s_kWimHashSize; ++i)
    {
        if (m_hash[i] != 0)
        {
            return true;
        }
    }
    return false;
}

END_NAMESPACE_RCZIP
