/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeltaDecoder_h_
#define __RCDeltaDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "RCDelta.h"

BEGIN_NAMESPACE_RCZIP

/** Delta ������
*/
class RCDeltaDecoder:
    public RCDelta,
    public IUnknownImpl2<ICompressFilter,
                         ICompressSetDecoderProperties2>
{
public:
    
    /** ��ʼ��
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
};

END_NAMESPACE_RCZIP

#endif //__RCDeltaDecoder_h_
