/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeltaEncoder_h_
#define __RCDeltaEncoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "RCDelta.h"

BEGIN_NAMESPACE_RCZIP

/** Delta ������
*/
class RCDeltaEncoder:
    public RCDelta,
    public IUnknownImpl3<ICompressFilter,
                         ICompressSetCoderProperties,
                         ICompressWriteCoderProperties>
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
    virtual uint32_t Filter(byte_t* data, uint32_t size) ;

    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;

    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeltaEncoder_h_
