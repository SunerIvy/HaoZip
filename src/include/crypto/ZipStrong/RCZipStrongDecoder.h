/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipStrongDecoder_h_
#define __RCZipStrongDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Zip Strong Key �ṹ
*/
struct RCZipStrongKeyInfo
{

    /** ��Key
    */
    byte_t m_masterKey[32] ;
    
    /** Key ��С
    */
    uint32_t m_keySize ;
    
    /** ��������
    @param [in] data ����
    @param [in] size ��С
    */
    void SetPassword(const byte_t* data, uint32_t size) ;
};

/** Zip Strong ����������
*/
class RCZipStrongBaseDecoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoSetPassword>
{
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
    RCZipStrongKeyInfo m_key ;
    
    /** aes ������
    */
    ICompressFilterPtr m_aesFilter ;
    
    /** ����
    */
    RCByteBuffer m_buf ;
};

/** Zip Strong ������
*/
class RCZipStrongDecoder:
    public RCZipStrongBaseDecoder
{
public:

    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    uint32_t Filter(byte_t* data, uint32_t size) ;

    /** ��ȡͷ���
    @param [in] inStream ������
    @param [in] crc crcУ��
    @param [in] unpackSize ��ѹ���С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadHeader(ISequentialInStream *inStream, uint32_t crc, uint64_t unpackSize) ;
    
    /** �������
    @param [out] isPasswordOK �����Ƿ���ȷ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CheckPassword(bool &isPasswordOK) ;
    
private:
    
    /** iv��С
    */
    uint32_t m_ivSize ;
    
    /** iv
    */
    byte_t m_iv[16] ;
    
    /** rem��С
    */
    uint32_t m_remSize ;
};

END_NAMESPACE_RCZIP

#endif //__RCZipStrongDecoder_h_
