/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialOutStreamImp_h_
#define __RCSequentialOutStreamImp_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "common/RCDynamicBuffer.h"

BEGIN_NAMESPACE_RCZIP

class RCWriteBuffer ;

class RCSequentialOutStreamImp:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSequentialOutStreamImp() ;
    
    /** Ĭ����������
    */
    ~RCSequentialOutStreamImp() ;
    
public:
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ��ȡ��С
    @return �������ݴ�С
    */
    size_t GetSize() const ;
    
    /** ��ȡ������
    @return ���ػ���������
    */
    const RCDynamicByteBuffer& GetBuffer() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ����� RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** д��������ݻ�����
    */
    RCWriteBuffer& m_writeBuffer ;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialOutStreamImp_h_
