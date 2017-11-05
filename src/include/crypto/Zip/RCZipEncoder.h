/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipEncoder_h_
#define __RCZipEncoder_h_ 1

#include "crypto/Zip/RCZipCipher.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** ����������
*/
class ISequentialOutStream ;

/** Zip ������
*/
class RCZipEncoder:
    public IUnknownImpl3<ICompressFilter,
                         ICryptoSetPassword,
                         ICryptoSetCRC>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipEncoder() ;
    
    /** Ĭ����������
    */
    ~RCZipEncoder() ;
    
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
    
    /** ��������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetPassword(const byte_t* data, uint32_t size) ;
    
    /** ����CRCֵ
    @param [in] crc CRC��ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetCRC(uint32_t crc) ;
    
    /** дͷ���
    @param [in] outStream �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteHeader(ISequentialOutStream *outStream) ;
    
private:

    /** zip cipher ������
    */
    RCZipCipher m_cipher;

    /** crc У��ֵ
    */
    uint32_t m_crc;
};

END_NAMESPACE_RCZIP

#endif //__RCZipEncoder_h_
