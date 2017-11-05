/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLockedInStream_h_
#define __RCLockedInStream_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/IStream.h"
#include "thread/RCMutex.h"

BEGIN_NAMESPACE_RCZIP

class RCLockedInStream:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLockedInStream() ;
    
    /** Ĭ����������
    */
    ~RCLockedInStream() ;
    
public:
    
    /** ��ʼ��
    @param [in] stream �������ӿ�
    */
    void Init(IInStream* stream) ;
    
    /** ��ȡ����
    @param [in] startPos ��ʼλ��
    @param [out] data ���ݻ�����
    @param [in] size ������ȡ�����ݳ���
    @param [out] processedSize ����ʵ�ʶ�ȡ�����ݳ���
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult Read(uint64_t startPos, 
                 void* data, 
                 uint32_t size, 
                 uint32_t* processedSize);
    
private:
    
    /** �����������ӿ�
    */
    IInStreamPtr m_stream ;
    
    /** ���߳�ͬ����
    */
    RCMutex m_lock ;
};

END_NAMESPACE_RCZIP

#endif //__RCLockedInStream_h_
