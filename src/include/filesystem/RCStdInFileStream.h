/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStdInFileStream_h_
#define __RCStdInFileStream_h_ 1

#include "base/RCDefs.h"
#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinStdInFileStream.h"
#else
    #include "filesystem/linux/RCLinStdInFileStream.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** ����̨������
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinStdInFileStream RCStdInFileStream ;
#else
    typedef RCLinStdInFileStream RCStdInFileStream ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCStdInFileStream_h_
