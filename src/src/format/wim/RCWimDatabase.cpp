/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/wim/RCWimDatabase.h"

/////////////////////////////////////////////////////////////////
//RCWimDatabase class implementation

BEGIN_NAMESPACE_RCZIP

RCWimDatabase::RCWimDatabase()
{
}

RCWimDatabase::~RCWimDatabase()
{
}

uint64_t RCWimDatabase::GetUnpackSize() const
{
    uint64_t res = 0;
    for (size_t i = 0; i < m_streams.size(); ++i)
    {
        res += m_streams[i].m_resource.m_unpackSize;
    }
    return res;
}

uint64_t RCWimDatabase::GetPackSize() const
{
    uint64_t res = 0;
    for (size_t i = 0; i < m_streams.size(); ++i)
    {
        res += m_streams[i].m_resource.m_packSize;
    }
    return res;
}

void RCWimDatabase::Clear()
{
    m_streams.clear();
    m_items.clear();
}

END_NAMESPACE_RCZIP
