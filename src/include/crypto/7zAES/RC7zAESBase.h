/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESBase_h_
#define __RC7zAESBase_h_ 1

#include "base/RCNonCopyable.h"
#include "crypto/7zAES/RC7zAESKeyInfoCache.h"
#include "thread/RCMutex.h"

BEGIN_NAMESPACE_RCZIP

/** 7z AES ����
*/
class RC7zAESBase:
    private RCNonCopyable
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RC7zAESBase() ;

    /** ����ժҪ
    */
    void CalculateDigest();
     
protected:

    /** key
    */
    RC7zAESKeyInfo m_key ;

    /** iv
    */
    byte_t m_iv[16] ;

    /** iv Size
    */
    uint32_t m_ivSize ;
     
private:

    /** Cached Keys
    */
    RC7zAESKeyInfoCache m_cachedKeys ;
    
private:

    /** Global Key Cache
    */
    static RC7zAESKeyInfoCache s_globalKeyCache ;

    /** lock
    */
    static RCMutex s_lock ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESBase_h_
