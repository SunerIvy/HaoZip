/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2CRCTableInit_h_
#define __RCBZip2CRCTableInit_h_ 1

#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 CRC���ʼ��
*/
class RCBZip2CRCTableInit
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2CRCTableInit() ;
    
    /** Ĭ����������
    */
    ~RCBZip2CRCTableInit() ;
};

typedef RCSingleton<RCBZip2CRCTableInit> RCBZip2CRCInit ;

END_NAMESPACE_RCZIP

#endif //__RCBZip2CRCTableInit_h_
