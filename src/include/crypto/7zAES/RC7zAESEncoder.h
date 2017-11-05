/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESEncoder_h_
#define __RC7zAESEncoder_h_ 1

#include "crypto/7zAES/RC7zAESBaseCoder.h"

BEGIN_NAMESPACE_RCZIP

/** 7z AES ������
*/
class RC7zAESEncoder:
    public RC7zAESBaseCoder,
    public ICompressWriteCoderProperties,
    public ICryptoResetInitVector
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zAESEncoder() ;
    
    /** Ĭ����������
    */
    ~RC7zAESEncoder() ;
    
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
    
    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) ;
    
    /** ���ü��ܳ�ʼ������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ResetInitVector() ;
    
private:

    /** ����������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CreateFilter() ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESEncoder_h_
