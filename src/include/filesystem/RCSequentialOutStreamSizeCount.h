/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialOutStreamSizeCount_h_
#define __RCSequentialOutStreamSizeCount_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCSequentialOutStreamSizeCount:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSequentialOutStreamSizeCount() ;
    
    /** Ĭ����������
    */
    ~RCSequentialOutStreamSizeCount() ;
    
public:
    
    /** ����������ӿ�
    @param [in] stream ������ӿ�ָ��
    */
    void SetStream(ISequentialOutStream* stream) ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ��ȡ���ݴ�С
    @return �������ݴ�С
    */
    uint64_t GetSize() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ����� RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** ������ӿ�
    */
    ISequentialOutStreamPtr m_spOutStream ;
    
    /** ���ݴ�С
    */
    uint64_t m_size ;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialOutStreamSizeCount_h_
