/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCString_h_
#define __RCString_h_ 1

#include "base/RCDefs.h"
#include <string>

BEGIN_NAMESPACE_RCZIP

/** Unicode�汾��String
*/
typedef std::wstring RCStringW ; 
    
/** Ansi�汾��String
*/
typedef std::string  RCStringA ;

/** String ���ͺ궨��
*/
#if defined (RCZIP_UNICODE)
    typedef RCStringW  RCString ;
#else
    typedef RCStringA  RCString ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCString_h_
