/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSemaphore_h_
#define __RCSemaphore_h_ 1

#include "thread/RCHandle.h"
#include "algorithm/Threads.h"

BEGIN_NAMESPACE_RCZIP

class RCSemaphore
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSemaphore() ;
   
    /** Ĭ����������
    */
    ~RCSemaphore() ;

public:

    /** �ر�Semaphore
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Close() ;

    /** ���ؾ��ֵ
    */
    operator HANDLE() const ;

    /** ����Semaphore
    @param [in] initiallyCount ��ʼ���ü���
    @param [in] maxCount ������ü���ֵ
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Create(uint32_t initiallyCount, uint32_t maxCount) ;

    /** �ͷ�Semaphore, ���ü�����1
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Release() ;

    /** �ͷ�Semaphore, ���ü����� releaseCount
    @param [in] releaseCount ��Ҫ�ͷŵ����ü���ֵ
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Release(uint32_t releaseCount) ;
    
    /** ��Semaphore����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Lock() ;
    
private:

    /** Semaphore����
    */
    ::CSemaphore m_object;
};

END_NAMESPACE_RCZIP

#endif //__RCSemaphore_h_
