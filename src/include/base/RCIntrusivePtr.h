/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIntrusivePtr_h_
#define __RCIntrusivePtr_h_ 1

#include "base/RCRefCounted.h"
#include <boost/intrusive_ptr.hpp>

BEGIN_NAMESPACE_RCZIP

/** Intrusive����ָ��궨��
*/
    
#define RCIntrusivePtr  boost::intrusive_ptr

/** �Խӿڶ������ü�����1
@param [in,out] p �ӿ�ָ��
*/
inline void intrusive_ptr_add_ref(RCRefCounted* p)
{
    p->Increase() ;
}

/** �Խӿڶ������ü�����1
@param [in,out] p �ӿ�ָ��
*/
inline void intrusive_ptr_release(RCRefCounted* p)
{
    p->Decrease() ;
}

END_NAMESPACE_RCZIP

#endif //__RCIntrusivePtr_h_
