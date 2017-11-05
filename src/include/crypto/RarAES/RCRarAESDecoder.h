/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarAESDecoder_h_
#define __RCRarAESDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBuffer.h"
#include "algorithm/Aes.h"

BEGIN_NAMESPACE_RCZIP

/** Rar AES ������
*/
class RCRarAESDecoder:
    public IUnknownImpl4<ICompressFilter,
                         ICompressSetDecoderProperties2,
                         ICryptoSetPassword,
                         ICompressSetCoderProperties>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRarAESDecoder() ;
    
    /** Ĭ����������
    */
    ~RCRarAESDecoder() ;
    
public:

    /** ��ʼ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Init() ;
    
    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    virtual uint32_t Filter(byte_t* data, uint32_t size) ;
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
    /** ��������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetPassword(const byte_t* data, uint32_t size) ;
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
private:

    /** ����
    */
    void Calculate() ;
    
private:

    /** Key Size
    */
    static const uint32_t s_kRarAesKeySize = 16 ;

    /** Max Password Length
    */
    static const uint32_t s_kMaxPasswordLength = 127 * 2;
    
private:

    /** salt
    */
    byte_t m_salt[8];

    /** �Ƿ�Salt
    */
    bool m_thereIsSalt;

    /** ����
    */
    RCByteBuffer m_buffer;

    /** aes Key
    */
    byte_t m_aesKey[s_kRarAesKeySize];

    /** aes ��ʼֵ
    */
    byte_t m_aesInit[AES_BLOCK_SIZE];

    /** �Ƿ����
    */
    bool m_needCalculate;

    /** aes
    */
    CAesCbc m_aes;

    /** �Ƿ�rar350ģʽ
    */
    bool m_rar350Mode;
};

END_NAMESPACE_RCZIP

#endif //__RCRarAESDecoder_h_
