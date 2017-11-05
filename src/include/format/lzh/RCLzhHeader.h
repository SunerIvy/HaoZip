/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhHeader_h_
#define __RCLzhHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

#ifdef RCZIP_OS_WIN
#define CHAR_PATH_SEPARATOR '\\'
#define WCHAR_PATH_SEPARATOR L'\\'
#define WSTRING_PATH_SEPARATOR L"\\"
#else
#define CHAR_PATH_SEPARATOR '/'
#define WCHAR_PATH_SEPARATOR L'/'
#define WSTRING_PATH_SEPARATOR L"/"
#endif

class RCLzhHeader
{
public:

    /** ����id��С
    */
    static const int s_methodIdSize = 5;

    /** ��չid�ļ���
    */
    static const byte_t s_extIdFileName = 0x01;

    /** ��չidĿ¼��
    */
    static const byte_t s_extIdDirName  = 0x02;

    /** ��չid unixʱ��
    */
    static const byte_t s_extIdUnixTime = 0x54;
};


END_NAMESPACE_RCZIP

#endif //__RCLzhHeader_h_
