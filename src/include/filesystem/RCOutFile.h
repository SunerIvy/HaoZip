/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutFile_h_
#define __RCOutFile_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "filesystem/windows/RCWinOutFile.h"    
#else
    #include "filesystem/linux/RCLinOutFile.h"
#endif


BEGIN_NAMESPACE_RCZIP

/** д�ļ�������
*/
#ifdef RCZIP_OS_WIN
    typedef RCWinOutFile RCOutFile ;
#else
    typedef RCLinOutFile RCOutFile ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCOutFile_h_
