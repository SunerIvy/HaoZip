/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDummyOutFileStream_h_
#define __RCDummyOutFileStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCDummyOutFileStream:
    public IUnknownImpl<IOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDummyOutFileStream() ;
    
    /** Ĭ����������
    */
    ~RCDummyOutFileStream() ;

public:
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
    /** ������С
    @param [in] newSize �µĴ�С 
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetSize(uint64_t newSize) ;

    /** �Ѵ���ĵĴ�С
    @return �����Ѵ���ĵĴ�С 
    */
    virtual uint64_t GetProcessedSize(void) const ;
    
    /** �ر������
    */
    void Close() ;
    
private:
    
    /** �Ѿ�д������ݴ�С
    */
    uint64_t m_processedSize;
    
    /** ��ǰ�ļ�ָ��ƫ��λ��
    */
    uint64_t m_currentPos ;
};

END_NAMESPACE_RCZIP

#endif //__RCDummyOutFileStream_h_
