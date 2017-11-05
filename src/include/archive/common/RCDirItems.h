/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDirItems_h_
#define __RCDirItems_h_ 1

#include "archive/common/RCDirItem.h"
#include "base/RCNonCopyable.h"
#include "common/RCVector.h"
#include "base/RCString.h"
#include "filesystem/RCFileInfo.h"

BEGIN_NAMESPACE_RCZIP

/** Ŀ¼���
*/
class RCDirItems:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDirItems() ;
    
    /** Ĭ����������
    */
    ~RCDirItems() ;
    
public:
    
    /** ͨ���
    */
    static const RCString::value_type s_kAnyStringWildcard;
        
    /** Ŀ¼�ָ��
    */
    static const RCString::value_type s_kDirDelimiter;

    /** ���Ŀ¼��
    @param [in] phyParent �����ڵ�
    @param [in] logParent �߼����ڵ�
    @param [in] fi �ļ���Ϣ
    @param [out] dirItems Ŀ¼���
    */
    static void AddDirFileInfo(int32_t phyParent, 
                               int32_t logParent, 
                               const RCFileInfo& fi, 
                               RCVector<RCDirItemPtr>& dirItems);

        
    /** �ж��ļ��Ƿ�ɶ�
    @param [in] fileName �ļ���
    @param [out] errorCode �����
    @return �ɶ�����true,���򷵻�false
    */
    static bool IsReadableFile(const RCString& fileName, uint64_t& errorCode) ;
    
public:
    
    /** ����Ŀ¼���
    @return ����Ŀ¼���
    */
    const RCVector<RCDirItemPtr>& GetItems() const ;
    
    /** ����Ŀ¼�������
    @return ����Ŀ¼�������
    */
    RCVector<RCDirItemPtr>& GetItems() ;

    /** ����Ŀ¼����
    @return ����Ŀ¼����
    */
    int32_t GetNumFolders() const;
    
    /** ��������·��
    @param [in] index ���
    @return ���ظ���ŵ�����·��
    */
    RCString GetPhyPath(int32_t index) const;
    
    /** �����߼�·��
    @param [in] index ���
    @return ���ظ���ŵ��߼�·��
    */
    RCString GetLogPath(int32_t index) const;

    /** ����ǰ׺
    @param [in] phyParent �����ڵ�
    @param [in] logParent �߼����ڵ�
    @param [in] prefix ǰ׺
    @return ������ӱ��
    */
    int32_t AddPrefix(int32_t phyParent, int32_t logParent, const RCString &prefix);

    /** ɾ�����һ��ǰ׺
    */
    void DeleteLastPrefix();

    /** ö��Ŀ¼
    @param [in] phyParent �����ڵ�
    @param [in] logParent �߼����ڵ�
    @param [in] phyPrefix ����ǰ׺
    @param [out] errorPaths ����·��
    @param [out] errorCodes ������
    */
    void EnumerateDirectory(int32_t phyParent,
                            int32_t logParent, 
                            const RCString& phyPrefix,
                            RCVector<RCString>& errorPaths, 
                            RCVector<uint64_t>& errorCodes) ;

    /** ö��Ŀ¼��
    @param [in] phyPrefix ����ǰ׺
    @param [in] logPrefix �߼�ǰ׺
    @param [in] filePaths �ļ��б�
    @param [out] errorPaths ����·���б�
    @param [out] errorCodes �������б�
    */
    void EnumerateDirItems2(const RCString& phyPrefix, 
                            const RCString& logPrefix,
                            const RCVector<RCString>& filePaths,
                            RCVector<RCString>& errorPaths, 
                            std::vector<uint64_t>& errorCodes);

    /** ��������
    */
    void ReserveDown();

    /** ��ȡ�ļ����޸�ʱ��
    @param [in] index �����
    @return �����޸�ʱ��
    */
    RC_FILE_TIME GetModifyTime(int32_t index) const ;
    
private:
    
    /** ����ǰ׺·��
    @param [in] parents ���ڵ��б�
    @param [in] index  ���
    @param [in] name ����
    @return ����ǰ׺·��
    */
    RCString GetPrefixesPath(const RCIntVector& parents, int32_t index, const RCString &name) const;

private:
    
    /** ǰ׺�б�
    */
    RCVector<RCString> m_prefixes ;
    
    /** �����ڵ��б�
    */
    RCIntVector m_phyParents ;
    
    /** �߼����ڵ��б�
    */
    RCIntVector m_logParents ;    
    
    /** Ŀ¼���б�
    */
    RCVector<RCDirItemPtr> m_items ;
};

END_NAMESPACE_RCZIP

#endif //__RCDirItems_h_
