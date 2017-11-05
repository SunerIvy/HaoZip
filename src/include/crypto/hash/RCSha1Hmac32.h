/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1Hmac32_h_
#define __RCSha1Hmac32_h_ 1

#include "crypto/hash/RCSha1Context32.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 Hmac
*/
class RCSha1Hmac32
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1Hmac32() ;
    
    /** Ĭ����������
    */
    ~RCSha1Hmac32() ;

public:

    /** ����key
    @param [in] key ���õ�key
    @param [in] keySize ��С
    */
    void SetKey(const byte_t *key, size_t keySize);

    /** ����
    @param [in] data ����
    @param [in] dataSize ���ݴ�С
    */
    void Update(const uint32_t *data, size_t dataSize) ;

    /** ��������
    @param [in] mac mac��ַ
    @param [in] macSize mac��С
    */
    void Final(uint32_t *mac, size_t macSize = RCSha1Defs::kDigestSizeInWords);  

    /** ����ժҪ
    @param [in] mac mac��ַ
    @param [in] numIteration ��������
    */
    void GetLoopXorDigest(uint32_t *mac, uint32_t numIteration);
    
private:

    /** sha
    */
    RCSha1Context32 m_sha ;

    /**
    */
    RCSha1Context32 m_sha2 ;
};

END_NAMESPACE_RCZIP

#endif //__RCSha1Hmac32_h_
