/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCThread_h_
#define __RCThread_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** �̺߳�������
@param [in] pArg �Զ����̲߳���ָ��
*/
typedef void (*PFNThreadProc)(void* pArg) ;

/** �̹߳�����
*/
class RCThread:
    private RCNonCopyable
{
public:
    
    /** �߳�ID����
    */
    typedef unsigned long thread_id ;
   
public:
    
    /** ���캯��
    @param [in] pfnThreadProc �̺߳���
    @param [in] pArg �̺߳�������
    */
    RCThread(PFNThreadProc pfnThreadProc, void* pArg = NULL);
 
    /** ��������
    */
    ~RCThread() ; 
 
public:
    
    /** �����߳�
    @return �ɹ�����true,���򷵻�false
    */
    bool Start() ;
 
    /** �ȴ��߳̽���
    */
    void Join() ;
 
    /** �ȴ��̵߳�ʱ��
    @param [in] u32MilliSeconds �ȴ���ʱ��
    */
    void TimeJoin(uint32_t u32MilliSeconds);
 
    /** ��ø��̵߳�ID
    @return �����߳�ID
    */
    thread_id GetThreadID() ;
    
    /** �߳��Ƿ���������
    @return ����߳��������з���true, ���򷵻�false
    */
    bool IsRunning(void) const ;

public:
    
    /** �˳��߳�
    @param [in] u32ExitStatus �̵߳��˳�״̬
    */
    static void Exit(uint32_t u32ExitStatus) ;
 
    /** Sleep ����
     @param [in] u32MilliSeconds Sleep��ʱ��
    */
    static void Sleep(uint32_t u32MilliSeconds) ;
    
    /** �ó�CPU�������߳�
    */
    static void yield() ;
    
    /** ��õ�ǰ�̵߳�ID
    @return ���ص�ǰ�߳�ID
    */
    static thread_id GetCurrentThreadID() ;

private:
    
    /** ʵ������
    */
    struct TImpl ;
    TImpl* m_impl ;
};

/** �߳�����ָ�붨��
*/
typedef RCSharedPtr<RCThread> RCThreadPtr ;

END_NAMESPACE_RCZIP

#endif //__RCThread_h_