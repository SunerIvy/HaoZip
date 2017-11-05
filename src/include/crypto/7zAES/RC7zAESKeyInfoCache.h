/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESKeyInfoCache_h_
#define __RC7zAESKeyInfoCache_h_ 1

#include "crypto/7zAES/RC7zAESKeyInfo.h"
#include <vector>

BEGIN_NAMESPACE_RCZIP

/** 7z AES Key Info Cache
*/
class RC7zAESKeyInfoCache
{
public:

    /** ���캯��
    */
    RC7zAESKeyInfoCache(size_t size) ;
    
    /** Ĭ����������
    */
    ~RC7zAESKeyInfoCache() ;

public:

    /** ���� 
    @param [in] key ���ҵ�key
    @return �ɹ�����true,���򷵻�false
    */
    bool Find(RC7zAESKeyInfo& key) ;

    /** ����
    @param [in] key ���ӵ�key
    */
    void Add(RC7zAESKeyInfo& key) ;
    
private:


    /** ��С
    */
    size_t m_size ;

    /** Key �б�
    */
    std::vector<RC7zAESKeyInfo> m_keys ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESKeyInfoCache_h_
