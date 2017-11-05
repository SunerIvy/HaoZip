/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutFileStream_h_
#define __RCOutFileStream_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinOutFileStream.h"
#else
    #include "filesystem/linux/RCLinOutFileStream.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** д�ļ���������
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinOutFileStream RCOutFileStream ;
#else
    typedef RCLinOutFileStream RCOutFileStream ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCOutFileStream_h_
