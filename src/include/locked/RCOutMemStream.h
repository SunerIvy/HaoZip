/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutMemStream_h_
#define __RCOutMemStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "locked/RCMemLockBlocks.h"
#include "thread/RCSynchronization.h"

BEGIN_NAMESPACE_RCZIP

class RCMemBlockManagerMt ;

class RCOutMemStream:
    public IUnknownImpl<IOutStream>
{
public:

    /** ���캯��
    */
    explicit RCOutMemStream(RCMemBlockManagerMt* memManager) ;
    
    /** Ĭ����������
    */
    ~RCOutMemStream() ;
    
public:
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** �ͷ���Դ
    */
    void Free() ;
    
    /** ����ͬ����Event
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult CreateEvents() ;
    
    /** ����������ӿ�
    @param [in] outStream ������ӿ�ָ��
    */
    void SetOutStream(IOutStream* outStream) ;
    
    /** ����������ӿ�
    @param [in] outStream ������ӿ�ָ��
    */
    void SetSeqOutStream(ISequentialOutStream* outStream) ;
    
    /** �ͷ������
    */
    void ReleaseOutStream() ;
    
    /** ����д�������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult WriteToRealStream() ;
    
    /** ���������ڴ�������
    @param [out] blocks �ڴ�������
    */
    void DetachData(RCMemLockBlocks& blocks) ;
    
    /** ����Ϊ��ʵ���������ģʽ
    */
    void SetRealStreamMode() ;
    
    /** ֹͣд��
    @param [in] res �������
    @return �ɹ�����true, ���򷵻�false
    */
    void StopWriting(HResult res) ;
    
    /** �Ƿ�����¼��ѷ���
    @return ����ѷ�������true, ���򷵻�false
    */
    bool WasUnlockEventSent() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
    /** ������С
    @param [in] newSize �µĴ�С 
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetSize(uint64_t newSize) ;    
  
private:
    
    /** ��ȡ��ǰλ��
    @return ���ص�ǰλ��
    */
    uint64_t GetPos() const ;
    
private:
    
    /** ���߳��ڴ�������
    */
    RCMemBlockManagerMt* m_memManager ;
    
    /** ��ǰ�ڴ��������
    */
    size_t m_curBlockIndex ;
    
    /** ��ǰ�ڴ��λ��
    */
    size_t m_curBlockPos ;
    
    /** ��ʵ���������ģʽ
    */
    bool m_realStreamMode ;
    
    /** �����¼����ͱ��
    */    
    bool m_unlockEventWasSent;
    
    /** ֹͣд������Ľ��
    */
    HResult m_stopWriteResult ;
    
    /** �ڴ�������
    */
    RCMemLockBlocks m_blocks ;
    
    /** ˳�������
    */
    ISequentialOutStreamPtr m_spOutSeqStream ;
    
    /** �����
    */
    IOutStreamPtr m_spOutStream ;
    
    /** ֹͣд��ͬ���¼�
    */
    RCAutoResetEvent m_stopWritingEvent;
    
    /** д����ʵ��ͬ���¼�
    */
    RCAutoResetEvent m_writeToRealStreamEvent;
};

END_NAMESPACE_RCZIP

#endif //__RCOutMemStream_h_
