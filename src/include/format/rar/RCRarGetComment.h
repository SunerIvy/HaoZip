/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarGetComment_h_
#define __RCRarGetComment_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "interface/IPassword.h"

BEGIN_NAMESPACE_RCZIP

class RCRarGetComment
{
public:

#ifndef RCZIP_UNICODE
    /** ��ȡRARע��
    @param [in] filename �ļ���
    @param [out] comment ����ע��
    @param [in] getTextPassword ���������
    @return �ɹ�����true�����򷵻�false
    */
    static bool GetRarComment(const char* filename, RCStringA& comment, ICryptoGetTextPassword* getTextPassword);

#else
    /** ��ȡRARע��
    @param [in] filename �ļ���
    @param [out] comment ����ע��
    @param [in] getTextPassword ���������
    @return �ɹ�����true�����򷵻�false
    */
    static bool GetRarComment(const wchar_t* filename, RCStringW& comment, ICryptoGetTextPassword* getTextPassword);
    
#endif
};

END_NAMESPACE_RCZIP

#endif //__RCRarGetComment_h_