/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipCipher_h_
#define __RCZipCipher_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** Zip Cipher
*/
class RCZipCipher:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipCipher() ;
    
    /** Ĭ����������
    */
    ~RCZipCipher() ;
    
public:

    /** ��������
    @param [in] password ����
    @param [in] passwordLength ���볤��
    */
    void SetPassword(const byte_t *password, uint32_t passwordLength);

    /** ���ݽ���
    @param [in] encryptedByte ��������
    @return ���������
    */
    byte_t DecryptByte(byte_t encryptedByte);

    /** ���ݱ���
    @param [in] b ����ǰ����
    @return ���������
    */
    byte_t EncryptByte(byte_t b);

    /** ����ͷ���
    @param [in] buffer ���ݻ���
    */
    void DecryptHeader(byte_t *buffer);

    /** ����ͷ���
    @param [in] buffer ���ݻ���
    */
    void EncryptHeader(byte_t *buffer);
    
private:

    /** ����key 
    @param [in] b ����
    */
    void UpdateKeys(byte_t b) ;

    /** �����ֽ�
    @return ���ؽ����ֽ�
    */
    byte_t DecryptByteSpec() ;
        
public:
    
    /** ͷ��Ǵ�С
    */
    static const int32_t s_headerSize = 12 ;
        
private:

    /** keys
    */
    uint32_t m_keys[3] ;    
};

END_NAMESPACE_RCZIP

#endif //__RCZipCipher_h_
