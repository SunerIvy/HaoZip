/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFilePath_h_
#define __RCFilePath_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** Unicode�汾·�������� 
*/
typedef RCStringW RCFilePathW ;

/** Ansi�汾·�������� 
*/
typedef RCStringA  RCFilePathA ;

/** Ĭ��·�������� 
*/
#if defined (RCZIP_UNICODE)
    typedef RCFilePathW  RCFilePath ;
#else
    typedef RCFilePathA  RCFilePath ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCFilePath_h_
