/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileName_h_
#define __RCFileName_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCFileName
{
public:
    
    /** ��ȡ·���ָ���: ��windowsƽ̨�� '\\'
    @return ����·���ָ���
    */
    static char_t GetDirDelimiter(void) ; 
    
    /** ��ȡ·���ָ���: ����'/'
    @return ����·���ָ���'/'
    */
    static char_t GetPosixDirDelimiter(void) ; 
    
    /** ��ȡ���·��֮��ķָ���
    @return ���ض��·��֮��ķָ���
    */
    static char_t GetDirsSplitChar(void) ; 
    
    /** ��ȡͨ�����* �ַ�
    @return ���� * �ַ�
    */
    static char_t GetAnyStringWildcard(void) ; 
    
    /** ��·������ȷ����·���ָ���Ϊ���һ���ַ�
    @param [in,out] dirPath ��Ҫ�����·����
    */
    static void NormalizeDirPathPrefix(RCString& dirPath) ;
    
    /** ��·������ȷ����·���ָ���Ϊƽ̨��׼�ķָ���
    @param [in,out] dirPath ��Ҫ�����·����
    */
    static void NormalizeDirPathDelimiter(RCString& dirPath) ;
    
    /** ����·��
    @param [in] dirPath ·����
    @param [in] fileName ·���������ļ���
    @return �������ӵ�·����
    */
    static RCString JoinFileName(const RCString& dirPath, const RCString& fileName) ;
    
    /** �ָ�·��
    @param [in] fullName ����·����
    @param [out] pureName �ļ�������
    @param [out] extensionDelimiter ��չ���ָ���
    @param [out] extension ��չ��
    */
    static void SplitNameToPureNameAndExtension(const RCString& fullName,
                                                RCString& pureName,
                                                RCString& extensionDelimiter,
                                                RCString& extension) ;
    /** ��·�����߼���˫����
    @param [in] filePath �ļ�·��
    @return ���ش�������ļ�·��
    */
    static RCString GetQuotedFilePath(const RCString& filePath) ;
    
    /** ��·�����߼���˫����
    @param [in] filePath �ļ�·��
    @return ���ش�������ļ�·��
    */
    static RCString RemoveQuoteFromFilePath(const RCString& filePath) ;
    
    /** �ж��Ƿ�Ϊ����·��
    @param [in] filePath �ļ�·��
    @return ���Ϊ����·��������true, ���򷵻�false
    */
    static bool IsCompletedPath(const RCString& filePath) ;

    /** ��ȡ�ļ����н�ֹʹ�õ��ַ���
    @param [in] path �ļ����Ƿ��·��
    @return ���غ���ֹʹ���ַ����ַ���
    */
    static RCString GetFileNameForbidChar(bool path = false);
    
    /** �ж��Ƿ���ͨ���
    @param [in] fileName �ļ�·��
    @return �������ͨ�������true, ���򷵻�false
    */
    static bool HasWildcardChar(const RCString& fileName) ;
};

END_NAMESPACE_RCZIP

#endif //__RCFileName_h_
