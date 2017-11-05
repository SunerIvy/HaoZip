/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCEnumDirItems_h_
#define __RCEnumDirItems_h_ 1

#include "base/RCWindowsDefs.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "filesystem/RCFileEnumerator.h"
#include "filesystem/RCFileInfo.h"
#include "filesystem/RCFindFile.h"
#include "archive/common/RCWildcardCensorNode.h"
#include "archive/common/RCWildcardCensor.h"
#include "archive/common/RCDirItems.h"
#include "archive/common/IEnumDirItemFilter.h"

BEGIN_NAMESPACE_RCZIP

/** ö��Ŀ¼ʱ�Ļص��ӿ�
*/
class IEnumDirItemCallback
{
public:
    
    /** ���Ȼص�
    @param [in] numFolders Ŀ¼��
    @param [in] numFiles �ļ���
    @param [in] path �ļ�·��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ScanProgress(uint64_t numFolders, uint64_t numFiles, const RCString& path) = 0 ;
    
protected:
    
    /** ��������
    */
    ~IEnumDirItemCallback() {} ;
};

/** ͨ���ƥ��
*/
class RCWildcardCensor ;

/** Ŀ¼���
*/
class RCDirItems ;

/** ö��Ŀ¼
*/
class RCEnumDirItems
{
public:
    
    /** ���ñ�ѹ�����ļ�������
    @param [in] spEnumDirItemFilter �ļ�������ָ��
    */
    void SetEnumDirItemFilter(const IEnumDirItemFilterPtr& spEnumDirItemFilter) ;

    /** ö���ļ�Ŀ¼��Ϣ
    @param [in] censor ͨ���ƥ�䴦��
    @param [in] dirItems Ŀ¼��
    @param [in] callback ö�ٲ����ص��ӿ�ָ��
    @param [in] isForUpdateArchive �Ƿ�Ϊ����ѹ���ļ�ģʽ
    @param [out] errorPaths ö�ٲ�������·���б�
    @param [out] errorCodes ö�ٲ���������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult EnumerateItems( const RCWildcardCensor& censor,
                            RCDirItems& dirItems,
                            IEnumDirItemCallback* callback,
                            bool isForUpdateArchive,
                            RCVector<RCString>& errorPaths,
                            RCVector<HResult>& errorCodes) ;

private:
    
    /** ö��Ŀ¼
    @param [in] curNode ��ǰĿ¼
    @param [in] phyParent �����ڵ�
    @param [in] logParent �߼����ڵ�
    @param [in] phyPrefix ����ǰ׺
    @param [in] addArchivePrefix ���ӵ��ĵ�ǰ׺
    @param [out] dirItems Ŀ¼��Ϣ�б�
    @param [in] enterToSubFolders ö����Ŀ¼
    @param [in] callback ö�ٲ����ص�
    @param [in] isForUpdateArchive �Ƿ�����ĵ�
    @param [out] errorPaths ö�ٲ�������·���б�
    @param [out] errorCodes ö�ٲ���������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult EnumerateDirItems(  const RCWildcardCensorNode& curNode,
                                int32_t phyParent, 
                                int32_t logParent, 
                                const RCString& phyPrefix,
                                const RCVector<RCString>& addArchivePrefix,
                                RCDirItems& dirItems,
                                bool enterToSubFolders,
                                IEnumDirItemCallback* callback,
                                bool isForUpdateArchive,
                                RCVector<RCString>& errorPaths,
                                RCVector<HResult>& errorCodes) ;

    /** ö��Ŀ¼��
    @param [in] curNode ��ǰĿ¼
    @param [in] phyParent �����ڵ�
    @param [in] logParent �߼����ڵ�
    @param [in] curFolderName ��ǰĿ¼��
    @param [in] phyPrefix ����ǰ׺
    @param [in] addArchivePrefix ���ӵ��ĵ�ǰ׺
    @param [out] dirItems Ŀ¼��Ϣ�б�
    @param [in] enterToSubFolders �Ƿ�ö����Ŀ¼
    @param [in] callback ö�ٻص�
    @param [in] isForUpdateArchive �Ƿ�����ĵ�
    @param [out] errorPaths ö�ٲ�������·���б�
    @param [out] errorCodes ö�ٲ���������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult EnumerateDirItems_Spec( const RCWildcardCensorNode& curNode,
                                    int32_t phyParent, 
                                    int32_t logParent, 
                                    const RCString& curFolderName,
                                    const RCString& phyPrefix,
                                    const RCVector<RCString>& addArchivePrefix,
                                    RCDirItems& dirItems,
                                    bool enterToSubFolders,
                                    IEnumDirItemCallback* callback,
                                    bool isForUpdateArchive,
                                    RCVector<RCString>& errorPaths,
                                    RCVector<HResult>& errorCodes) ;

private:
    
    /** ��ѹ�����ļ�������
    */
    IEnumDirItemFilterPtr m_spEnumDirItemFilter ;
};

END_NAMESPACE_RCZIP

#endif //__RCEnumDirItems_h_
