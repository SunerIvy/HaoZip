/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStreamBinder_h_
#define __RCStreamBinder_h_ 1

#include "base/RCNonCopyable.h"
#include "thread/RCSynchronization.h"

BEGIN_NAMESPACE_RCZIP

class ISequentialInStream ;
class ISequentialOutStream ;

class RCStreamBinder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCStreamBinder() ;
    
    /** Ĭ����������
    */
    ~RCStreamBinder() ;

public:
    
    /** ����ͬ����Event
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult CreateEvents() ;
    
    /** �������ӿ�
    @param [out] inStream �������ӿ�
    @param [out] outStream ������ӿ�
    */
    void CreateStreams(ISequentialInStream** inStream,
                       ISequentialOutStream** outStream) ;


    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** �ر����ݶ�
    */
    void CloseRead() ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    HResult Write(const void* data, uint32_t size, uint32_t* processedSize);
    
    /** �ر�����д
    */
    void CloseWrite() ;
    
    /** ���³�ʼ��
    */
    void ReInit() ;
    
    /** ��ȡ�Ѵ����С
    @return �����Ѵ������ݴ�С
    */
    uint64_t GetProcessedSize(void) const ;
    
private:
    
    /** �������ݶ�д��ͬ���¼�
    */
    RCManualResetEvent m_allBytesAreWritenEvent;
    
    /** �������ݿɶ�ȡͬ���¼�
    */
    RCManualResetEvent m_thereAreBytesToReadEvent;
    
    /** �����������ѹر�ͬ���¼�
    */
    RCManualResetEvent m_readStreamIsClosedEvent;

    /** ��������С
    */
    uint32_t m_bufferSize ;
    
    /** ���ݻ�����
    */
    const void* m_buffer ;
    
    /** �Ѵ������ݴ�С
    */
    uint64_t m_processedSize ;
};

END_NAMESPACE_RCZIP

#endif //__RCStreamBinder_h_
