/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipDecoder_h_
#define __RCZipDecoder_h_ 1

#include "crypto/Zip/RCZipCipher.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Zip ������
*/
class RCZipDecoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoSetPassword>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipDecoder() ;
    
    /** Ĭ����������
    */
    ~RCZipDecoder() ;

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
    
    /** ��ȡͷ���
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadHeader(ISequentialInStream *inStream) ;
    
private:

    /** zip cipher ������
    */
    RCZipCipher m_cipher;
};

END_NAMESPACE_RCZIP

#endif //__RCZipDecoder_h_
