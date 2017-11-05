/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/7zAES/RC7zAESKeyInfoCache.h"

/////////////////////////////////////////////////////////////////
//RC7zAESKeyInfoCache class implementation

BEGIN_NAMESPACE_RCZIP

RC7zAESKeyInfoCache::RC7zAESKeyInfoCache(size_t size):
    m_size(size)
{
}

RC7zAESKeyInfoCache::~RC7zAESKeyInfoCache()
{
}

bool RC7zAESKeyInfoCache::Find(RC7zAESKeyInfo& key) 
{
    std::vector<RC7zAESKeyInfo>::iterator pos = m_keys.begin() ;
    for (; pos != m_keys.end(); ++pos)
    {
        const RC7zAESKeyInfo &cached = *pos ;
        if (key.IsEqualTo(cached))
        {
            for (size_t j = 0; j < RC7zAESKeyInfo::s_kKeySize; ++j)
            {
                key.m_key[j] = cached.m_key[j] ;
            }
            if (pos != m_keys.begin())
            {
                m_keys.erase(pos) ;
                m_keys.insert(m_keys.begin(), cached);
            }
            return true;
        }
    }
    return false ;
}

void RC7zAESKeyInfoCache::Add(RC7zAESKeyInfo& key)
{
    if (Find(key))
    {
        return ;
    }
    if (m_keys.size() >= m_size)
    {
        m_keys.pop_back();
        m_keys.insert(m_keys.begin(), key);
    }
}

END_NAMESPACE_RCZIP
