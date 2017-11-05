/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESDecoder_h_
#define __RC7zAESDecoder_h_ 1

#include "crypto/7zAES/RC7zAESBaseCoder.h"

BEGIN_NAMESPACE_RCZIP

/** 7z AES ������
*/
class RC7zAESDecoder:
    public RC7zAESBaseCoder,
    public ICompressSetDecoderProperties2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zAESDecoder() ;
    
    /** Ĭ����������
    */
    ~RC7zAESDecoder() ;
    
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject) ;
    
    /** �������ü���
    */
    virtual void AddRef(void) ;
    
    /** �������ü���
    */
    virtual void Release(void) ;
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;

private:

    /** ����������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CreateFilter() ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESDecoder_h_
