/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialOutTempBufferImp_h_
#define __RCSequentialOutTempBufferImp_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCInOutTempBuffer;

class RCSequentialOutTempBufferImp:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSequentialOutTempBufferImp() ;
    
    /** Ĭ����������
    */
    ~RCSequentialOutTempBufferImp() ;
    
public:
    
    /** ��ʼ��
    */
    void Init(RCInOutTempBuffer* buffer) ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ����� RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** �������������
    */
    RCInOutTempBuffer* m_buffer ;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialOutTempBufferImp_h_
