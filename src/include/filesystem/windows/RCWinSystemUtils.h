/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinSystemUtils_h_
#define __RCWinSystemUtils_h_ 1

#include "base/RCString.h"
#include "base/RCWindowsDefs.h"

BEGIN_NAMESPACE_RCZIP

/** windowsƽ̨ϵͳ��ع�����
*/
class RCWinSystemUtils
{
public:
    
    /** ��ȡWindowsĿ¼
    @param [out] path ����·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyGetWindowsDirectory(RCString& path) ;
    
    /** ��ȡSystemĿ¼
    @param [out] path ����·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyGetSystemDirectory(RCString& path) ;
    
    /** ����Ŀ¼ʱ��
    @param [in] fileName Ŀ¼����
    @param [in] cTime �ļ�����ʱ��
    @param [in] aTime �ļ�������ʱ��
    @param [in] mTime �ļ��޸�ʱ��
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool SetDirTime(const RCString& fileName, 
                           const FILETIME* cTime, 
                           const FILETIME* aTime,
                           const FILETIME* mTime) ;
   
    /** �����ļ�����
    @param [in] fileName �ļ���
    @param [in] fileAttributes �ļ�����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MySetFileAttributes(const RCString& fileName, DWORD fileAttributes) ;
    
    /** �ƶ��ļ������Ŀ������򷵻�ʧ��
    @param [in] existFileName ��Ҫ�ƶ����ļ�
    @param [in] newFileName Ŀ���ļ���
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyMoveFile(const RCString& existFileName, const RCString& newFileName) ;
    
    /** �ƶ��ļ�,���Ŀ���ļ������򸲸�
    @param [in] existFileName ��Ҫ�ƶ����ļ�
    @param [in] newFileName Ŀ���ļ���
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyMoveFileEx(const RCString& existFileName, const RCString& newFileName) ;
    
    /** ɾ��Ŀ¼������ɾ����Ŀ¼
    @param [in] pathName ·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyRemoveDirectory(const RCString& pathName) ;
    
    /** ����Ŀ¼
    @param [in] pathName ·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyCreateDirectory(const RCString& pathName) ;
    
    /** �����༶Ŀ¼
    @param [in] pathName ·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool CreateComplexDirectory(const RCString& pathName) ;
    
    /** ɾ���ļ�
    @param [in] fileName ��Ҫɾ�����ļ�
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool DeleteFileAlways(const RCString& fileName);
    
    /** ɾ���ļ��У�����������Ŀ¼������
    @param [in] pathName ·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool RemoveDirectoryWithSubItems(const RCString& pathName) ;
    
    /** ��ȡ��ʱĿ¼
    @param [in] resultPath ������ʱĿ¼��
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyGetTempPath(RCString& resultPath);
    
    /** ��ȡ��ʱ�ļ���
    @param [in] dirPath ��ʱ�ļ�����Ŀ¼
    @param [in] prefix ��ʱ�ļ�ǰ׺
    @param [out] resultPath ��ʱ�ļ�����������·��
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyGetTempFileName(const RCString& dirPath, const RCString& prefix, RCString& resultPath) ;

    /** ��ȡ�ļ�������·����
    @param [in] fileName �ļ���
    @param [out] resultPath ����·����
    @param [out] fileNamePartStartIndex �ļ�����ʼ�±�ֵ
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MyGetFullPathName(const RCString& fileName, RCString& resultPath, int32_t& fileNamePartStartIndex);
    
    /** ���õ�ǰ·��
    @param [in] path ·����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MySetCurrentDirectory(const RCString& path) ;
    
    /** ��ָ��Ŀ¼�����ļ�
    @param [in] path ��Ҫ���ҵ�·��
    @param [in] fileName ��Ҫ���ҵ��ļ���
    @param [in] extension ��Ҫ�����ļ�����չ��
    @param [out] resultPath ���·��
    @param [out] filePart �ļ������ֵ���ʼ�±�ֵ
    @return �ɹ�����true��ʧ�ܷ���false
    */
    static bool MySearchPath(const RCString& path, 
                             const RCString& fileName,
                             const RCString& extension,
                             RCString& resultPath,
                             int32_t& filePart) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinSystemUtils_h_
