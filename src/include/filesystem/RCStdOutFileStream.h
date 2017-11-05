/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStdOutFileStream_h_
#define __RCStdOutFileStream_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinStdOutFileStream.h"
#else
    #include "filesystem/linux/RCLinStdOutFileStream.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** ����̨�����
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinStdOutFileStream RCStdOutFileStream ;
#else
    typedef RCLinStdOutFileStream RCStdOutFileStream ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCStdOutFileStream_h_
