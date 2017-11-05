/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1Hmac_h_
#define __RCSha1Hmac_h_ 1

#include "crypto/hash/RCSha1Context.h"
#include "crypto/hash/RCSha1Defs.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 Hmac
*/
class RCSha1Hmac
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1Hmac() ;
    
    /** Ĭ����������
    */
    ~RCSha1Hmac() ;

public:
    
    /** ����key
    @param [in] key keyֵ
    @param [in] keySize ��С
    */
    void SetKey(const byte_t *key, size_t keySize);

    /** ����
    @param [in] data ����
    @param [in] dataSize ���ݴ�С
    */
    void Update(const byte_t *data, size_t dataSize);

    /** ��������
    @param [in] mac mac��ַ
    @param [in] macSize mac��С
    */
    void Final(byte_t *mac, size_t macSize = RCSha1Defs::kDigestSize);
        
private:

    /** sha
    */
    RCSha1Context m_sha ;

    /** sha2
    */
    RCSha1Context m_sha2 ;
};

END_NAMESPACE_RCZIP

#endif //__RCSha1Hmac_h_
