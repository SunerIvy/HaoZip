/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCAutoResetEvent_h_
#define __RCAutoResetEvent_h_ 1

#include "thread/RCBaseEvent.h"

BEGIN_NAMESPACE_RCZIP

class RCAutoResetEvent: 
    public RCBaseEvent
{
public:

    /** ����Event
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes Create() ;

    /** ���û�д����Զ�����������Ѿ����������سɹ����
    @return �ɹ�����0, ���򷵻ش����
    */
    WRes CreateIfNotCreated() ;
};

END_NAMESPACE_RCZIP

#endif //__RCAutoResetEvent_h_
