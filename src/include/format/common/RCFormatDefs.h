/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFormatDefs_h_
#define __RCFormatDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

#define RC_CREATE_ARCHIVE_FUN_NAME      "CreateArchiveInfoObjects"
#define RC_CREATE_ARCHIVE_FUN_TNAME  _T("CreateArchiveInfoObjects")

extern "C"{
    /** �����ĵ���Ϣ������, ���ض�������ΪIArchiveInfo�ӿ�ָ���������ʼ��ַ�����һ��Ԫ�غ���ΪNULL
    @param [out] outObject ����IArchiveInfo�ӿ�ָ�룬���ü�������1
    */
    typedef HResult (*RCCreateArchiveFunction)(void** outObject) ;
}

END_NAMESPACE_RCZIP

#endif //__RCFormatDefs_h_
