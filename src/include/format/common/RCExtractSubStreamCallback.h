/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Ƕ�װ���ѹ���Ȼص��ӿ�
*/
class RCExtractSubStreamCallback :
    public IUnknownImpl<IArchiveExtractCallback>
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCExtractSubStreamCallback() ;
    
    /** ��������
    */
    virtual ~RCExtractSubStreamCallback() ;
    
    /** ��ʼ��
    @param [in] destFileName ��ѹ�ļ���Ŀ���ļ�����������·��
    @param [in] fileSize �ļ���ѹ���С�� ���Ϊ uint64_t(-1) ��ʾδ֪��С
    @param [in] openCallback ���ĵ����Ȼص��ӿ�
    @return �ɹ�����true�����򷵻�false
    */
    bool Init(const RCString& destFileName, 
              uint64_t fileSize,
              IArchiveOpenCallback* openCallback) ;
    
public:
    
    /** ��������
    @param [in] total ���������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetTotal(uint64_t total) ;
    
    /** ��ǰ���
    @param [in] completed ��ǰ��ɵ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t completed) ;
    
public:
    
    /** ��ȡ�����
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [out] outStream ������Ľӿ�ָ�룬���ü�����1
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialOutStream** outStream, int32_t askExtractMode) ;
    
    /** ׼����ѹ����
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult PrepareOperation(uint32_t index, int32_t askExtractMode) ;
    
    /** ���ý��
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] resultEOperationResult �������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t resultEOperationResult) ;
    
    /** ���ö��߳̽�ѹ���
    @param [in] isMultiThreads ���Ϊtrue����ǰΪ���߳̽�ѹģʽ������Ϊ���߳̽�ѹģʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetMultiThreadMode(bool isMultiThreads) ;

    /** ��ȡ��ѹ·��
    @param [out] path ��ѹ·��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetDestinationDirectory(RCString& path) ;
    
    /** ��ȡ��Ҫ�ӽ�ѹ·����ȥ����·������
    @param [out] removePathParts ��Ҫ�ӽ�ѹ·����ȥ����·������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetRemovePathParts(RCVector<RCString>& removePathParts) ;

    /** ��ȡ��ѹ·��ѡ��
    @param [out] pathMode ��ѹ·��ѡ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetPathMode(RCExractPathMode& pathMode) ;

    /** ��ȡ��ѹ����ѡ��
    @param [out] overwriteMode ��ѹ����ѡ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetOverwriteMode(RCExractOverwriteMode& overwriteMode) ;

    /** ��ȡ��ѹ���·�ʽ
    @param [out] updateMode ��ѹ���·�ʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetUpdateMode(RCExractUpdateMode& updateMode) ;
    
    /** �Ƿ������ļ�
    @return �Ƿ���true�����򷵻�false
    */
    virtual bool IsKeepDamageFiles(void) ;
    
private:

    /** ���ĵ��ӿ�
    */
    IArchiveOpenCallback* m_openCallback ;
    
    /** ��ѹĿ���ļ���
    */ 
    RCString m_destFileName ;
    
    /** �ļ���С
    */
    uint64_t m_fileSize ;
    
    /** Ŀ��������Ľӿ�ָ��
    */
    ISequentialOutStreamPtr m_spOutFileStream ;
};

END_NAMESPACE_RCZIP
