/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCVirtThread_h_
#define __RCVirtThread_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RCThread ;

class RCVirtThread:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCVirtThread() ;
    
    /** Ĭ����������
    */
    virtual ~RCVirtThread() ;
    
public:
    
    /** �����߳�
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Start(void);
    
    /** �ȴ��߳̽���
    */
    void WaitFinish(void) ;
    
    /** ���߳���ִ�к������ú������������߳��˳�
    */
    virtual void Execute(void) = 0 ;
    
private:
    
    /** �߳�ʵ��
    */
    RCThread* m_thread ;
};

END_NAMESPACE_RCZIP

#endif //__RCVirtThread_h_
