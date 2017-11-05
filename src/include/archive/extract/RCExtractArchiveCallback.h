/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtractArchiveCallback_h_
#define __RCExtractArchiveCallback_h_ 1

#include "archive/extract/IExtractFileCallback.h"
#include "archive/extract/RCExtractDefs.h"
#include "interface/IArchive.h"
#include "interface/IPassword.h"
#include "interface/ICoder.h"
#include "interface/IOverwrite.h"
#include "interface/IUnknownImpl.h"
#include "interface/RCPropertyID.h"
#include "common/RCVector.h"
#include "filesystem/RCOutFileStream.h"
#include "thread/RCMutex.h"
#include <set>
#include <list>

BEGIN_NAMESPACE_RCZIP

/** ��ѹ������ʾ
*/
class RCLocalProgress ;

/** ������¼��ӿ�
*/
class IOutStreamEvent ;

/** �ĵ���ѹ�ص��ӿ�
*/
class RCExtractArchiveCallback:
    public IUnknownImpl4< IArchiveExtractCallback,
                          ICryptoGetTextPassword,
                          IMtCompressProgressInfo,
                          IAskOverwrite
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCExtractArchiveCallback() ;
    
    /** Ĭ����������
    */
    virtual ~RCExtractArchiveCallback() ;
    
public:
    
    /** ��������
    @param [in] total ���������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetTotal(uint64_t total) ;
    
    /** ��ǰ���
    @param [in] completed ��ǰ��ɵ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t completed) ;
    
    /** ��ȡ�����
    @param [in] index �����±�ֵ
    @param [out] outStream ������Ľӿ�ָ�룬���ü�����1
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialOutStream** outStream, int32_t askExtractMode) ;
    
    /** ׼����ѹ����
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult PrepareOperation(uint32_t index, int32_t askExtractMode) ;
    
    /** ���ý��
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] resultEOperationResult �������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t resultEOperationResult) ;
    
    /** ���ö��߳̽�ѹ���
    @param [in] isMultiThreads ���Ϊtrue����ǰΪ���߳̽�ѹģʽ������Ϊ���߳̽�ѹģʽ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetMultiThreadMode(bool isMultiThreads) ;
    
    /** ��ȡ����
    @param [out] password ��ȡ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CryptoGetTextPassword(RCString& password) ;
    
    /** ����ѹ������
    @param [in] index ��ǰ�����±�
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetRatioInfo(uint32_t index, uint64_t inSize, uint64_t outSize) ;

    /** ��ȡ��ѹ·��
    @param [out] path ��ѹ·��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetDestinationDirectory(RCString& path) ;

    /** ��ȡ��Ҫ�ӽ�ѹ·����ȥ����·������
    @param [out] removePathParts ��Ҫ�ӽ�ѹ·����ȥ����·������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetRemovePathParts(RCVector<RCString>& removePathParts) ;

    /** ��ȡ��ѹ·��ѡ��
    @param [out] pathMode ��ѹ·��ѡ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetPathMode(RCExractPathMode& pathMode) ;

    /** ��ȡ��ѹ����ѡ��
    @param [out] overwriteMode ��ѹ����ѡ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetOverwriteMode(RCExractOverwriteMode& overwriteMode) ;

    /** ��ȡ��ѹ���·�ʽ
    @param [out] updateMode ��ѹ���·�ʽ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetUpdateMode(RCExractUpdateMode& updateMode) ;

    /** �ļ�����ȷ�Ͻӿ�
    @param [in] existName �Ѿ����ڵ��ļ�·��
    @param [in] existTime �Ѿ����ڵ��ļ�ʱ��
    @param [in] existSize �Ѿ����ڵ��ļ���С
    @param [in] newName ���ļ���
    @param [in] newTime ���ļ�ʱ��
    @param [in] newSize ���ļ���С
    @param [in] isEnableRename �Ƿ�֧������������
    @param [out] answer ȷ�Ͻ��
    @param [out] newFileName ����������������ļ�ʱ�������û�ָ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult AskOverwrite(const RCString& existName,
                                 const RC_FILE_TIME* existTime, 
                                 const uint64_t* existSize,
                                 const RCString& newName,
                                 const RC_FILE_TIME* newTime, 
                                 const uint64_t* newSize,
                                 bool isEnableRename,
                                 RCExractOverwriteAnswer& answer,
                                 RCString& newFileName) ;

    /** �Ƿ������ļ�
    @return �������ļ�����true,���򷵻�false
    */
    virtual bool IsKeepDamageFiles(void) ;
    
public:
    
    /** ��ʼ��
    @param [in] archiveHandler ��ѹ�ĵ�����ӿ�
    @param [in] extractCallback2 ��ѹ�ص��ӿ�
    @param [in] stdOutMode �Ƿ�Ϊ����̨���ģʽ
    @param [in] directoryPath ��ѹ·��
    @param [in] removePathParts ��ѹ·������Ҫ�Ƴ���·������
    @param [in] itemDefaultName Ĭ�ϵ��ļ���
    @param [in] utcMTimeDefault Ĭ�ϵ��ļ��޸�ʱ��
    @param [in] attributesDefault Ĭ���ļ�����
    @param [in] packSize ѹ������С
    @param [in] fileTimeFlag ��ѹ�ļ�ʱ������
    */
    void Init( IInArchive* archiveHandler,
               IExtractFolderArchiveCallback* extractCallback2,
               bool stdOutMode,
               const RCString& directoryPath,
               const RCVector<RCString>& removePathParts,
               const RCString& itemDefaultName,
               const RC_FILE_TIME& utcMTimeDefault,
               uint64_t attributesDefault,
               uint64_t packSize,
               RCExractFileTimeFlag fileTimeFlag);
    
    /** ��ʼ����ѹѡ��
    @param [in] multiArchives �Ƿ�ͬʱ��ѹ����ĵ�
    @param [in] pathMode ��ѹ·��ѡ��
    @param [in] overwriteMode ��ѹ����ѡ��
    @param [in] updateMode ��ѹ���·�ʽ
    @param [in] isKeepDamageFiles �Ƿ������ļ�
    @param [in] extractToSubDir ��ѹÿ���ļ�����Ŀ¼��
    @param [in] outStreamEvent ��ѹʱ�����IO���¼�����
    */
    void InitForMulti(bool multiArchives,
                      RCExractPathMode pathMode,
                      RCExractOverwriteMode overwriteMode,
                      RCExractUpdateMode updateMode,
                      bool isKeepDamageFiles,
                      bool extractToSubDir,
                      IOutStreamEvent* outStreamEvent) ;
    
    /** ������Ҫ�Ƴ���·���飬ƽ�����ģʽ��ѹʹ��
    @param [in] removePathList ��Ҫ�Ƴ���·���б�
    */
    void SetRemovePathList(const RCVector<RCString>& removePathList) ;
    
    /** ��ȡ��ѹ���ȹ���ʵ�ֽӿ�
    @return ���ؽ�����ʾ�ӿ�ָ��
    */
    RCLocalProgress* GetLocalProgress() ;
    
    /** ��ȡ�Ѿ���ѹ���ļ��ܴ�С
    @return �����Ѿ���ѹ�ļ��ܴ�С
    */
    uint64_t GetUnpackSize() const ;
    
    /** ��ȡ�ļ�������
    @return �����ļ�������
    */
    uint64_t GetNumFolders() const ;
    
    /** ��ȡ�ļ�����
    @return �����ļ�����
    */
    uint64_t GetNumFiles() const ;
    
private: 
    
    /** �����༶Ŀ¼
    @param [in] dirPathParts ����Ŀ¼�б�
    @param [out] fullPath ������ĩ��Ŀ¼
    @return �ɹ�����true,���򷵻�false
    */
    bool CreateComplexDirectory(const RCVector<RCString>& dirPathParts, 
                                RCString& fullPath) ;

    /** ��ȡ�ļ�ʱ������
    @param [in] index �ļ����
    @param [in] propID ���Ա��
    @param [in] filetime �ļ�ʱ��
    @param [out] filetimeIsDefined �ļ�ʱ���Ƿ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult GetTime(int32_t index, 
                    RCPropertyID propID, 
                    RC_FILE_TIME& filetime, 
                    bool& filetimeIsDefined) ;
    
    /** ��������Ŀ¼
    @param [in] fullPath Ŀ¼ȫ·��
    @return �ɹ�����true,���򷵻�false
    */             
    bool CreateOneDirectory(const RCString& fullPath) ;
    
    /** �����ѹ�����ļ�����
    */
    void ClearExtractingFileInfo() ;
    
    /** ��ϴ���
    @param [in] index ���
    @param [in] errMsg ������Ϣ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult OnMessageError(int32_t index,const RCString& errMsg) ;
    
    /** ����Ƴ�Ŀ¼ǰ׺��
    @param [in] removePathParts ��Ҫ�Ƴ���Ŀ¼ǰ׺
    @param [in] pathParts ��ǰ��Ŀ¼�����ļ�
    @param [out] numRemovePathParts ��Ҫ�Ƴ�·��ǰ׺�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CheckRemovePathParts(const RCVector<RCString>& removePathParts,
                                 const RCVector<RCString>& pathParts,
                                 RCString::size_type& numRemovePathParts) const ;
    
private:
    
    /** �����ĵ��ӿ�
    */
    IInArchivePtr m_spInArchive ;
    
    /** ��ѹ�ص��ӿ�
    */
    IExtractFolderArchiveCallbackPtr m_extractCallback2 ;
    
    /** ��ѹ����ӿ�
    */
    ICryptoGetTextPasswordPtr m_cryptoGetTextPassword;
    
    /** ���·�ʽ
    */
    RCExractUpdateMode m_updateMode ;
    
    /** ��ѹ·��ѡ��
    */
    RCExractPathMode m_pathMode;
    
    /** ����ѡ��
    */
    RCExractOverwriteMode m_overwriteMode;
    
    /** �Ƿ������ļ�
    */
    bool m_keepDamageFiles ;
    
    /** ��ѹ����Ŀ¼
    */
    bool m_extractToSubDir;

    /** ��ѹĿ��·��
    */
    RCString m_directoryPath;
    
    /** ��ѹ���Ƿ���Ҫ���հ��ڵĴ���ʱ����½�ѹ����ļ�
    */
    bool m_writeCTime;
    
    /** ��ѹ���Ƿ���Ҫ���հ��ڵķ���ʱ����½�ѹ����ļ�
    */
    bool m_writeATime;
    
    /** ��ѹ���Ƿ���Ҫ���հ��ڵ��޸�ʱ����½�ѹ����ļ�
    */
    bool m_writeMTime;
    
    /** ��ѹ����Ҫ�Ӱ���·�����Ƴ���·������
    */
    RCVector<RCString> m_removePathParts;
    
    /** ��ѹ����Ҫ�Ƴ���·���飬ƽ�����ģʽ��ѹʹ��
    */
    RCVector<RCString> m_removePathList ;
    
    /** Ĭ�ϵİ���������
    */
    RCString m_itemDefaultName;
    
    /** Ĭ�ϵ��ļ��޸�ʱ��
    */
    RC_FILE_TIME m_utcMTimeDefault;
    
    /** Ĭ���ļ�����
    */
    uint64_t m_attributesDefault;
    
    /** �Ƿ�Ϊ����̨���ģʽ
    */
    bool m_stdOutMode ;
                              
private:

    /** ��ѹ���ȹ���ʵ�ֽӿ�
    */
    RCLocalProgress* m_localProgressSpec;
    
    /** ��ѹ���Ƚӿ�
    */
    ICompressProgressInfoPtr m_localProgress;
    
    /** ѹ�����ܴ�С
    */
    uint64_t m_packTotal;
    
    /** ��ѹ���ܴ�С
    */
    uint64_t m_unpackTotal;

    /** �Ƿ�Ϊͬʱ��ѹ����ļ�
    */
    bool m_multiArchives;
    
    /** �ļ�������
    */
    uint64_t m_numFolders;
    
    /** �ļ�����
    */
    uint64_t m_numFiles;
    
    /** �Ѿ���ѹ���ļ��ܴ�С
    */
    uint64_t m_unpackSize;
    
    /** ��������
    */
    uint64_t m_numErrors ;
    
    /** ����ѹ���д�����Ŀ¼���棬Ϊ�Ż�IO����
    */
    typedef std::set<RCString> TCreatedDirectoryCache ;
    TCreatedDirectoryCache m_createdDirCache ;
    
    /** IO����¼�����
    */
    IOutStreamEvent* m_outStreamEvent ;
    
private:
    
    /** ��ǰ��ѹ���ļ���Ϣ
    */
    struct TExtractingFileInfo ;
    
    /** ��ǰ��ѹ���ļ���Ϣ��������
    */
    RCVector<TExtractingFileInfo*> m_extractingFileInfoArray ;
    
    /** �Ƿ�Ϊ���߳�ѹ��
    */
    bool m_isMultiThreads ;
    
    /** ���߳�ͬ����
    */
    RCMutex m_extractMutex ;
    
private:
    /** ��ȡĬ��ʹ�õĽ�ѹ�ļ���Ϣ
    */
    TExtractingFileInfo* GetDefaultExtractingFileInfo() ;
    
    /** ��ȡĬ��ʹ�õĽ�ѹ�ļ���Ϣ
    */
    TExtractingFileInfo* GetExtractingFileInfo(uint32_t index) ;
    
    /** �ͷŽ�ѹ�ļ���Ϣ
    */
    void ReleaseExtractingFileInfo(uint32_t index) ;
    
private:
    /** ��ɾ���ļ�
    */
    typedef std::list<RCString> TDeleteFileList ;
    TDeleteFileList m_deleteFileList ;  
    
    /** ����ʱ��Ҫ���õ�Ŀ¼ʱ��
    */
    struct TPendingDirTime
    {
        RCString m_dirPath ;
        RCFileTimeValue m_createTime ;
        RCFileTimeValue m_accessTime ;
        RCFileTimeValue m_modifyTime ;
    };
    typedef std::list<TPendingDirTime> TPendingDirTimeList ;
    TPendingDirTimeList m_pendingDirTimeList ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCExtractArchiveCallback> RCExtractArchiveCallbackPtr ;

END_NAMESPACE_RCZIP

#endif //__RCExtractArchiveCallback_h_
