/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSharedLibrary_h_
#define __RCSharedLibrary_h_ 1

#include "base/RCDefs.h"

#ifdef RCZIP_OS_WIN
    #include "common/RCSharedLibWin32.h"
#else
    #include "common/RCSharedLibLinux.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** ��̬���ӿ���ع�����
*/
#ifdef RCZIP_OS_WIN
    /** Windowsƽ̨ʵ��
    */
    typedef RCSharedLibWin32 RCSharedLibrary ;
#else
    /** Linuxƽ̨ʵ�� 
    */
    typedef RCSharedLibLinux RCSharedLibrary ;
#endif

END_NAMESPACE_RCZIP

#endif //__RCSharedLibrary_h_
