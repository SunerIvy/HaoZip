/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInFileStream_h_
#define __RCInFileStream_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinInFileStream.h"
#else
    #include "filesystem/linux/RCLinInFileStream.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** ��ȡ�ļ��������װ
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinInFileStream RCInFileStream ;
#else
    #include "filesystem/linux/RCLinInFileStream.h"
#endif

END_NAMESPACE_RCZIP

#endif //__RCInFileStream_h_
