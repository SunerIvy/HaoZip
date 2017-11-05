/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWzAESBaseCoder_h_
#define __RCWzAESBaseCoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "crypto/WzAES/RCWzAESKeyInfo.h"
#include "crypto/hash/RCSha1Hmac.h"
#include "algorithm/Aes.h"

BEGIN_NAMESPACE_RCZIP

/** WzAES ������
*/
class RCWzAESBaseCoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoSetPassword
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWzAESBaseCoder() ;
    
    /** Ĭ����������
    */
    ~RCWzAESBaseCoder() ;
    
public:

    /** ����ͷ��С
    @return ����ͷ��С
    */
    uint32_t GetHeaderSize() const ;
        
protected:

    /** ���ݱ���
    @param [in] data ���ݻ���
    @param [in] size ���ݴ�С
    */
    void EncryptData(byte_t *data, uint32_t size);
        
    /** ��ʼ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Init() ;
    
    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    virtual uint32_t Filter(byte_t* data, uint32_t size) = 0 ;
    
    /** ��������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetPassword(const byte_t* data, uint32_t size) ;
    
protected:

    /** key
    */
    RCWzAESKeyInfo m_key ;

    /** ����
    */
    uint32_t m_counter[AES_BLOCK_SIZE / 4];

    /** ����
    */
    byte_t m_buffer[AES_BLOCK_SIZE];

    /** hmac
    */
    RCSha1Hmac m_hmac;

    /** ��λ��
    */
    uint32_t m_blockPos;

    /** ����У��
    */
    byte_t m_pwdVerifFromArchive[RCWzAESDefs::s_kPwdVerifCodeSize];

    /** Aes
    */
    CAes m_aes ;
};

END_NAMESPACE_RCZIP

#endif //__RCWzAESBaseCoder_h_
