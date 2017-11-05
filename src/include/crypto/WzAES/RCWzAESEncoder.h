/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWzAESEncoder_h_
#define __RCWzAESEncoder_h_ 1

#include "crypto/WzAES/RCWzAESBaseCoder.h"

BEGIN_NAMESPACE_RCZIP

/** ���л�������
*/
class ISequentialOutStream ;

/** WzAES ������
*/
class RCWzAESEncoder:
    public RCWzAESBaseCoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWzAESEncoder() ;
    
    /** Ĭ����������
    */
    ~RCWzAESEncoder() ;
    
public:

    /** дͷ���
    @param [in] outStream �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteHeader(ISequentialOutStream* outStream) ;

    /** дβ���
    @param [in] outStream �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteFooter(ISequentialOutStream* outStream) ;

    /** ����keyģʽ
    @param [in] mode ģʽ
    */
    bool SetKeyMode(byte_t mode) ;
        
    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    virtual uint32_t Filter(byte_t* data, uint32_t size) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWzAESEncoder_h_
