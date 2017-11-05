/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWzAESDecoder_h_
#define __RCWzAESDecoder_h_ 1

#include "crypto/WzAES/RCWzAESBaseCoder.h"

BEGIN_NAMESPACE_RCZIP

/** WzAES ������
*/
class RCWzAESDecoder:
    public RCWzAESBaseCoder,
    public ICompressSetDecoderProperties2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWzAESDecoder() ;
    
    /** Ĭ����������
    */
    ~RCWzAESDecoder() ;
    
public:

    /** ��ȡͷ����
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadHeader(ISequentialInStream* inStream);

    /** �������
    @return �ɹ�����true,���򷵻�false
    */
    bool CheckPasswordVerifyCode();

    /** ���mac
    @param [in] inStream ������
    @param [out] isOK �Ƿ���ȷ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CheckMac(ISequentialInStream* inStream, bool& isOK);
        
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
};

END_NAMESPACE_RCZIP

#endif //__RCWzAESDecoder_h_
