/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOffsetOutStream_h_
#define __RCOffsetOutStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCOffsetOutStream:
    public IUnknownImpl<IOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCOffsetOutStream() ;
    
    /** Ĭ����������
    */
    ~RCOffsetOutStream() ;
    
    /** ��ʼ��
    @param [in] stream ������ӿ�ָ��
    @param [in] offset �������ƫ����
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش����
    */
    HResult Init(IOutStream* stream, uint64_t offset);
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
    /** ������С
    @param [in] newSize �µĴ�С 
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش����
    */
    virtual HResult SetSize(uint64_t newSize) ;
    
private:
    
    /** ƫ��ֵ
    */
    uint64_t m_offset;
    
    /** ������ӿ�
    */
    IOutStreamPtr m_spOutStream;
};

END_NAMESPACE_RCZIP

#endif //__RCOffsetOutStream_h_
