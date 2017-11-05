/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMutex_h_
#define __RCMutex_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** ���ɵݹ黥���� 
*/
class RCMutex:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMutex() ;
    
    /** Ĭ����������
    */
    ~RCMutex() ;
    
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
class RCMutexLock:
    private RCNonCopyable
{
public:
    
    /** Ĭ�Ϲ��캯������ȡ��
    *@param [in] mutex ��Ҫ��ȡ����
    */
    explicit RCMutexLock(RCMutex* mutex):
        m_mutex(mutex)
    {
        if(m_mutex)
        {
            m_mutex->Lock() ;
        }
    }
    
    /** Ĭ�������������ͷ���
    */
    ~RCMutexLock()
    {
        if(m_mutex)
        {
            m_mutex->UnLock() ;
        }
    }
    
private:
    /** ��Ҫ��������
    */
    RCMutex* m_mutex ;
};

END_NAMESPACE_RCZIP

#endif //__RCMutex_h_
