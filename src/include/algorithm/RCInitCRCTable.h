/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInitCRCTable_h_
#define __RCInitCRCTable_h_ 1

#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

class RCInitCRCTableImpl
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCInitCRCTableImpl() ;
};

typedef RCSingleton<RCInitCRCTableImpl> RCInitCRCTable ;

END_NAMESPACE_RCZIP

#endif //__RCInitCRCTable_h_
