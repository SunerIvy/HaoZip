/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFilePathUtils_h_
#define __RCFilePathUtils_h_ 1

#include "filesystem/RCFilePath.h"
#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCFilePathUtils
{
public:
    
    /** �ж�·���Ƿ����
    @param [in] p �ļ�·��
    @return ������ڷ���true, ���򷵻�false
    */ 
    static bool IsExists(const RCFilePath& p) ;
    
    /** �ж��Ƿ�ΪĿ¼
    @param [in] p �ļ�·��
    @return ���ΪĿ¼����true, ���򷵻�false
    */
    static bool IsDirectory(const RCFilePath& p) ;
    
    /** �ж��Ƿ�Ϊ�գ������Ŀ¼����Ŀ¼��û�����ݷ���true��������ļ������ļ���СΪ0����true
    @param [in] p �ļ�·��
    @return ���Ϊ�շ���true, ���򷵻�false
    */
    static bool IsEmpty(const RCFilePath& p) ;
        
    /** ��ȡ�ļ���С
    @param [in] fileName �ļ���
    @return �����ļ���С�����ļ������ڣ����� 0
    */
    static uint64_t FileSize(const RCFilePath& fileName) ;
    
    /** ɾ��Ŀ¼������Ŀ¼�������ļ���
    @param [in] path ·����
    @return ����ɾ�����ļ�����
    */
    static uint64_t RemoveAll(const RCFilePath& path) ;
    
    /** ������Ŀ¼�����ļ�
    @param [in] from ��Ҫ���������ļ�
    @param [in] to ����Ϊ���ļ���
    @return �ɹ�����true, ���򷵻�false
    */
    static bool Rename(const RCFilePath& from, const RCFilePath& to) ;
    
    /** �����ļ�����Ŀ¼
    @param [in] from Դ�ļ�·��
    @param [in] to Դ�ļ�·��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool CopyPathFile(const RCFilePath& from, const RCFilePath& to) ;
    
    /** ����Ŀ¼��֧�ֶ༶Ŀ¼
    @param [in] path Ŀ¼��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool CreateDirectories(const RCFilePath& path) ;
    
    /** ��ȡ�ļ�����չ��
    @param [in] path �ļ���
    @return �����ļ�����չ��
    */
    static RCString Extension(const RCFilePath& path) ;
    
    /** ��ȡ�ļ�����ȥ����չ��
    @param [in] path �ļ���
    @return �����ļ����ļ������֣�������չ��
    */
    static RCString BaseName(const RCFilePath& path) ;
    
    /** �޸���չ�����ַ���������������ʵ�ļ�����
    @param [in] path �ļ���
    @param [in] newExtension �µ���չ��
    @return �����޸���չ�������·��
    */
    static RCString ChangeExtension(const RCFilePath& path, const RCString& newExtension) ; 

    /** ��ȡ���е��Ӷ���
    @param [in] path �ļ�·��
    @param [out] sons ��ǰĿ¼�У�����һ����ļ�·�����ļ���
    */
    static void GetAllSons(const RCFilePath& path, RCVector<RCString>& sons);
};

END_NAMESPACE_RCZIP

#endif //__RCFilePathUtils_h_
