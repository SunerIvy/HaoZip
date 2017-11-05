/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESBaseCoder_h_
#define __RC7zAESBaseCoder_h_ 1


#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "crypto/7zAES/RC7zAESBase.h"

BEGIN_NAMESPACE_RCZIP

/** 7z AES Base ������
*/
class RC7zAESBaseCoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoSetPassword
                        >,
    public RC7zAESBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zAESBaseCoder() ;
    
    /** Ĭ����������
    */
    ~RC7zAESBaseCoder() ;

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
    
protected:
    
    /** ����������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CreateFilter() = 0 ;
    
protected:

    /** AES Filter
    */
    ICompressFilterPtr m_aesFilter ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESBaseCoder_h_
