/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar20Crypto_h_
#define __RCRar20Crypto_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** Rar20 ����
*/
class RCRar20Crypto:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar20Crypto() ;
    
    /** Ĭ����������
    */
    ~RCRar20Crypto() ;
    
public:

    /** �����
    @param [in] buf ��������
    */
    void EncryptBlock(byte_t *buf) ;

    /** �����
    @param [in] buf ��������
    */
    void DecryptBlock(byte_t *buf) ;

    /** ��������
    @param [in] password ����
    @param [in] passwordLength ����
    */
    void SetPassword(const byte_t *password, uint32_t passwordLength);
    
private:

    /** SubstLong
    @param [in] t ����
    */
    uint32_t SubstLong(uint32_t t) ;

    /** ����key
    @param [in] data ����
    */
    void UpdateKeys(const byte_t* data);

    /** ���ܿ�
    @param [in] buf ���ݻ���
    @param [in] encrypt �Ƿ����
    */
    void CryptBlock(byte_t* buf, bool encrypt);

    /** ����
    @param [in] b1 �ֽ�1
    @param [in] b2 �ֽ�2
    */
    void Swap(byte_t *b1, byte_t *b2) ;

    /** ����Сͷ�洢uint32
    @param [in] p ����
    @return ����uint32
    */
    uint32_t GetUInt32FromMemLE(const byte_t *p) ;

    /** uint32д��Сͷ�洢
    @param [in] v uint32ֵ
    @param [in] p ���ݻ���
    */
    void WriteUInt32ToMemLE(uint32_t v, byte_t *p) ;
        
private:

    /** �ӱ�
    */
    byte_t m_substTable[256];

    /** keys
    */
    uint32_t m_keys[4];
};

END_NAMESPACE_RCZIP

#endif //__RCRar20Crypto_h_
