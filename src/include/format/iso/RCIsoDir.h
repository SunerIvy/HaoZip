/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIsoDir_h_
#define __RCIsoDir_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "common/RCStringBuffer.h"
#include "common/RCStringUtil.h"
#include "RCIsoItem.h"
#include "RCIsoHeader.h"

#ifdef RCZIP_OS_WIN
#define CHAR_PATH_SEPARATOR '\\'
#define WCHAR_PATH_SEPARATOR L'\\'
#define WSTRING_PATH_SEPARATOR L"\\"
#else
#define CHAR_PATH_SEPARATOR '/'
#define WCHAR_PATH_SEPARATOR L'/'
#define WSTRING_PATH_SEPARATOR L"/"
#endif

BEGIN_NAMESPACE_RCZIP

struct RCIsoDir :
    public RCIsoDirRecord
{
    /** ��·��
    */
    RCIsoDir* m_parent;

    /** ����
    */
    RCVector<RCIsoDir> m_subItems;

    /** ���
    */
    void Clear();

    /** ��ȡ����
    @param [in] checkSusp �Ƿ���susp
    @param [in] skipSize �����Ĵ�С
    @return ���س���
    */
    int32_t GetLength(bool checkSusp, int32_t skipSize) const;

    /** ��ȡ����
    @return ���س���
    */
    int32_t GetLengthU() const;

    /** ��ȡ·��
    @param [in] checkSusp �Ƿ���susp
    @param [in] skipSize �����Ĵ�С
    @return ����·��
    */
    RCStringA GetPath(bool checkSusp, int32_t skipSize) const;

    /** ��ȡunicode·��
    @return ����unicode����
    */
    RCString GetPathU() const;
};

END_NAMESPACE_RCZIP

#endif //__RCIsoDir_h_