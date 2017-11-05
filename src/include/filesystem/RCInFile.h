/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInFile_h_
#define __RCInFile_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinInFile.h"    
#else
    #include "filesystem/linux/RCLinInFile.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** ��ȡ�ļ�ʵ����
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinInFile RCInFile ;    
#else
    typedef RCLinInFile RCInFile ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCInFile_h_
