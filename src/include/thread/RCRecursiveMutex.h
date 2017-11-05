/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRecursiveMutex_h_
#define __RCRecursiveMutex_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RCRecursiveMutex:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRecursiveMutex() ;
    
    /** Ĭ����������
    */
    ~RCRecursiveMutex() ;
    
public:

    /** ��ȡ�������ȡ��������һֱ�ȴ�
    */    
    void Lock() ;
        
    /** ���Ի�ȡ��
    @return ���ȡ����������true,���ȡ�������򷵻�false
    */
    bool TryLock() ;
        
    /** �ͷ���
    */
    void UnLock() ;

private:
    
    /** ʵ������
    */
    struct TImpl ;
    TImpl* m_impl ;
};

/** �Զ�����������
*/
class RCRecursiveMutexLock:
    private RCNonCopyable
{
public:
    
    /** Ĭ�Ϲ��캯������ȡ��
    *@param [in] mutex ��Ҫ��ȡ����
    */
    explicit RCRecursiveMutexLock(RCRecursiveMutex* mutex):
        m_mutex(mutex)
    {
        if(m_mutex)
        {
            m_mutex->Lock() ;
        }
    }
    
    /** Ĭ�������������ͷ���
    */
    ~RCRecursiveMutexLock()
    {
        if(m_mutex)
        {
            m_mutex->UnLock() ;
        }
    }
    
private:
    /** ��Ҫ��������
    */
    RCRecursiveMutex* m_mutex ;
};

END_NAMESPACE_RCZIP

#endif //__RCRecursiveMutex_h_
