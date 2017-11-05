/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtractingFilePath_h_
#define __RCExtractingFilePath_h_ 1

#include "common/RCVector.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** ��ѹ�ļ�·��
*/
class RCExtractingFilePath
{
public:

    /** ɸѡ��ȷ·��
    @param [in,out] pathParts �ļ�·���б�
    */
    static void MakeCorrectPath(RCVector<RCString>& pathParts) ;
    
    /** ����·��
    @param [in] parts ����·��
    @return �������ɵ�·��
    */
    static RCString MakePathNameFromParts(const RCVector<RCString>& parts) ;
    
    /** ����·��
    @param [in] path ԭ·��
    @return �������ɵ�·��
    */
    static RCString GetCorrectFsPath(const RCString& path) ;
    
    /** ����·��
    @param [in] path ԭ·��
    @return �������ɵ�·��
    */
    static RCString GetCorrectFullFsPath(const RCString& path) ;
    
private:

    /** ȡ��ȷ���ļ���
    @param [in] path ԭ�ļ���
    @return ������ȷ���ļ���
    */
    static RCString GetCorrectFileName(const RCString& path) ;

    /** �滻�ַ�
    @param [in] s ԭ�ַ���
    @return �滻���ַ���
    */
    static RCString ReplaceIncorrectChars(const RCString& s) ;

#ifdef RCZIP_OS_WIN

    /** ����β
    @param [in] name �ļ���
    @param [in] len �ļ�������
    @return ��ȷ����true,���򷵻�false
    */
    static bool CheckTail(const RCString& name, int32_t len) ;

    /** ����ļ�����
    @param [in] name �ļ���
    @param [in] reservedName ��������
    @return ��ȷ����true,���򷵻�false
    */
    static bool CheckNameNum(const RCString& name, char_t* reservedName) ;

    /** ����Ƿ�֧��
    @param [in] name �ļ���
    @return ֧�ַ���true,���򷵻�false
    */
    static bool IsSupportedName(const RCString& name) ;
#endif
};

END_NAMESPACE_RCZIP

#endif //__RCExtractingFilePath_h_
