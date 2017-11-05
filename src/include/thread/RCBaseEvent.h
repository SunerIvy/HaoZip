/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBaseEvent_h_
#define __RCBaseEvent_h_ 1

#include "thread/RCHandle.h"
#include "algorithm/Threads.h"

BEGIN_NAMESPACE_RCZIP

class RCBaseEvent
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBaseEvent() ;

    /** Ĭ����������
    */
    ~RCBaseEvent() ;

public:

    /** Event�Ƿ񱻴���
    @return �������������true, ���򷵻�false
    */
    bool IsCreated() ;

    /** ���ؾ��ֵ
    */
    operator HANDLE() const ;

    /** �ر�Event
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Close() ;

#ifdef RCZIP_OS_WIN

    /** ����Event
    @param [in] manualReset �Ƿ�����manualReset����
    @param [in] initiallyOwn �Ƿ��ʼ��Ϊӵ����
    @param [in] name Event����
    @param [in] securityAttributes ��ȫ����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Create(bool manualReset,
                bool initiallyOwn,
                LPCTSTR name = NULL,
                LPSECURITY_ATTRIBUTES securityAttributes = NULL) ;

    /** Open Event
    @param [in] desiredAccess Desired Access ����
    @param [in] inheritHandle �Ƿ�̳о��
    @param [in] name Event����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Open(DWORD desiredAccess, bool inheritHandle, LPCTSTR name) ;
    
#endif

    /** Set Event
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Set() ;

    /** Set Event
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Reset() ;
    
    /** Lock Event
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Lock() ;
    
protected:

    /** Event����ֵ
    */
    ::CEvent m_object ;
};

END_NAMESPACE_RCZIP

#endif //__RCBaseEvent_h_
