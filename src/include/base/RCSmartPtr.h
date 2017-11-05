/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSmartPtr_h_
#define __RCSmartPtr_h_ 1

#include <boost/smart_ptr.hpp>

/** ��������ָ��궨�壬boostʵ��ת��
*/
#define RCSharedPtr          boost::shared_ptr
    
/** ��������ָ������궨�壬boostʵ��ת��
*/
#define RCSharedArrayPtr     boost::shared_array

/** Scoped����ָ��궨�壬boostʵ��ת��
*/
#define RCScopedPtr          boost::scoped_ptr
    
/** Scoped����ָ������궨�壬boostʵ��ת��
*/
#define RCScopedArrayPtr     boost::scoped_array

#endif //__RCSmartPtr_h_
