/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar20Decoder_h_
#define __RCRar20Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "crypto/Rar20/RCRar20Crypto.h"

BEGIN_NAMESPACE_RCZIP

/** Rar20 ������
*/
class RCRar20Decoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoSetPassword
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar20Decoder() ;
    
    /** Ĭ����������
    */
    ~RCRar20Decoder() ;
    
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
    
private:

    /** ��/������
    */
    RCRar20Crypto m_coder ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar20Decoder_h_
