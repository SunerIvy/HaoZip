/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCManualResetEvent_h_
#define __RCManualResetEvent_h_ 1

#include "thread/RCBaseEvent.h"

BEGIN_NAMESPACE_RCZIP

class RCManualResetEvent: 
    public RCBaseEvent
{
public:
    
    /** ����Event
    @param [in] initiallyOwn �Ƿ��ʼ��Ϊӵ����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Create(bool initiallyOwn = false) ;
    
    /** ���û�д����Զ�����������Ѿ����������سɹ����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes CreateIfNotCreated() ;

#ifdef RCZIP_OS_WIN

    /** ��������Event
    @param [in] initiallyOwn �Ƿ��ʼ��Ϊӵ����
    @param [in] name ����
    */
    WRes CreateWithName(bool initiallyOwn, LPCTSTR name) ;
    
#endif
};

END_NAMESPACE_RCZIP

#endif //__RCManualResetEvent_h_
