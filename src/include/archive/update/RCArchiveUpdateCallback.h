/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveUpdateCallback_h_
#define __RCArchiveUpdateCallback_h_ 1

#include "base/RCTypes.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "interface/IArchive.h"
#include "interface/IPassword.h"
#include "interface/RCPropertyID.h"
#include "filesystem/RCFileInfo.h"
#include "archive/common/RCDirItem.h"
#include "archive/common/RCDirItems.h"
#include "archive/common/RCArcItem.h"
#include "archive/update/RCUpdateCallbackUI.h"
#include "archive/update/RCUpdatePair2.h"
#include "archive/update/RCUpdateOptions.h"
#include "archive/update/RCArchiveUpdateFilter.h"
#include "common/RCVariant.h"

BEGIN_NAMESPACE_RCZIP

/** ������¼��ӿ�
*/
class IOutStreamEvent ;

/** �ĵ�ѹ�������»ص��ӿ�
*/
class RCArchiveUpdateCallback : 
    public IUnknownImpl6<IArchiveUpdateCallback2, 
                         ICryptoGetTextPassword2, 
                         ICryptoGetTextPassword,
                         ICompressProgressInfo,
                         IMtCompressProgressInfo,
                         ISetMultiThreadMode>
{
public:
    
    /** ���캯��
    @param [in] outStreamEvent ������¼��ӿ�
    */
    RCArchiveUpdateCallback(IOutStreamEvent* outStreamEvent);
    
public:
    
    /** ��ɰٷֱ�
    @param [in] inSize �����ֽ���
    @param [in] outSize ����ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize);
    
    /** �����ļ�����
    @param [in] total �ļ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetTotal(uint64_t total);
    
    /** �����������
    @param [in] completeValue �������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t completeValue);
    
    /** ���ø�����Ŀ��Ϣ
    @param [in] index ���
    @param [out] newData ������
    @param [out] newProperties ������
    @param [out] indexInArchive ���ڱ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetUpdateItemInfo(uint32_t index, 
                                      int32_t& newData, 
                                      int32_t& newProperties, 
                                      uint32_t& indexInArchive ) ;
    
    /** ȡ������
    @param [in] index �ļ����
    @param [in] propID ���Ա��
    @param [in] value ����ֵ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetProperty(uint32_t index, RCPropertyID propID, RCVariant& value) ;
    
    /** ȡ���ĵ�����
    @param [in] propID ���Ա��
    @param [in] value ����ֵ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetArchiveProperty(RCPropertyID propID, RCVariant& value) ;
    
    /** ȡ���ļ�������
    @param [in] index �ļ����
    @param [out] inStream �ļ�������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialInStream **inStream) ;
    
    /** �����ļ��������
    @param [in] index �ļ����
    @param [in] operationResult �������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t operationResult);
    
    /** ȡ�÷־��С
    @param [in] index �־���
    @param [out] size �־��С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetVolumeSize(uint32_t index, uint64_t& size);
    
    /** ȡ�÷־���
    @param [in] index �־���
    @param [out]  volumeStream �־���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetVolumeStream(uint32_t index, ISequentialOutStream **volumeStream) ;
    
    /** ȡ������
    @param [out] passwordIsDefined �����Ƿ��� ����0��ʾû�ж������룬����1��ʾ������
    @param [out] password ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CryptoGetTextPassword2(int32_t *passwordIsDefined, RCString& password);
    
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
    
    /** ����ѹ����ѹ���߳�ģʽ
    @param [in] isMultThread �Ƿ�Ϊ���߳�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetMultiThread(bool isMultThread) ;

public:
    
    /** ȡ�÷־�����
    @return ���ط־�����
    */
    const RCString& GetVolName(void) const;
    
    /** ���÷־�����
    @param [in] volName �־�����
    */
    void SetVolName(const RCString& volName);

    /** ȡ�÷־���չ��
    @return ���ط־���չ��
    */
    const RCString& GetVolExt(void) const;
    
    /** ���÷־���չ��
    @param [in] volExt �־���չ��
    */
    void SetVolExt(const RCString& volExt);

    /** ���ؽ�����»ص��ӿ�
    @return ������»ص��ӿ�
    */
    const RCUpdateCallbackUI* GetCallback() const;
    
    /** ���ý�����»ص��ӿ�
    @param [in] callback ������»ص��ӿ�
    */
    void SetCallback(RCUpdateCallbackUI* callback);
    
    /** �����Ƿ���д
    @return ����д����true,���򷵻�false
    */
    bool GetShareForWrite(void) const;
    
    /** ���ù���д
    @param [in] shareForWrite
    */
    void SetShareForWrite(bool shareForWrite);

    /** �����Ƿ��׼����ģʽ
    @return �����Ƿ��׼����ģʽ
    */
    bool GetStdInMode(void) const;
    
    /** �����Ƿ��׼����ģʽ
    @param [in] stdInMode ��׼����ģʽ
    */
    void SetStdInMode(bool stdInMode);

    /** ���ظ������б�
    @return ���ظ������б�
    */
    const RCDirItems* GetDirItems(void) const;
    
    /** ���ø�����
    @param [in] dirItems ������
    */
    void SetDirItems(const RCDirItems* dirItems);

    /** ȡ�ð������б�
    @return ���ذ������б�
    */
    const std::vector<RCArcItem>* GetArcItems(void) const;
        
    /** ���ð������б�
    @param [in] arcItems ���б�
    */
    void SetArcItems(const std::vector<RCArcItem>* arcItems);

    /** ȡ�ø��±Ƚ��б�
    @return ���ظ��±Ƚ��б�
    */
    const std::vector<RCUpdatePair2>* GetUpdatePairs(void) const;
        
    /** ���ø��±Ƚ��б�
    @param [in] updatePairs2 ���±Ƚ��б�
    */
    void SetUpdatePairs(const std::vector<RCUpdatePair2>* updatePairs2);

    /** ȡ���������б�
    @return �����������б�
    */
    const std::vector<RCString>* GetNewNames(void) const;
    
    /** �����������б�
    @param [in] newNames �������б�
    */
    void SetNewNames(const std::vector<RCString>* newNames) ;

    /** ȡ�������ĵ�ָ��
    @return �����ĵ�ָ��
    */
    const IInArchivePtr& GetArchive(void) const;
    
    /** ȡ�������ĵ�ָ������
    @return �����ĵ�ָ������
    */
    IInArchivePtr& GetArchive(void);

    /** ���ñ���·��ģʽ
    @param [in] pathMode ·������ģʽ
    */
    void SetPathMode(RCUpdateOptions::path_mode pathMode) ;
        
    /** ����ѹ���ļ�������
    @param [in] spUpdateFilter �ļ�������ָ��
    */
    void SetUpdateFileter(const RCArchiveUpdateFilterPtr& spUpdateFilter) ;
    
    /** ��ȡѹ���ļ�������
    @return ����ѹ���ļ�������
    */
    RCArchiveUpdateFilterPtr GetUpdateFileter(void) const ;

private:

    /** �־��С
    */
    std::vector<uint64_t> m_volumesSizes;

    /** �־�����
    */
    RCString m_volName;

    /** �־��׺
    */
    RCString m_volExt;

    /** ������ʾ�ص�
    */
    RCUpdateCallbackUI* m_callback;

    /** ����д
    */
    bool m_shareForWrite;

    /** ��׼����ģʽ
    */
    bool m_stdInMode;

    /** Ŀ¼����
    */
    const RCDirItems *m_dirItems;

    /** �������
    */
    const std::vector<RCArcItem>* m_arcItems;

    /**
    */
    const std::vector<RCUpdatePair2>* m_updatePairs;

    /** 
    */
    const std::vector<RCString> *m_newNames;

    /** �����ĵ��ӿ�
    */
    IInArchivePtr m_archive;
    
    /** ����·��ģʽ
    */
    RCUpdateOptions::path_mode m_pathMode ;
    
    /** IO ����ص�����
    */
    IOutStreamEvent* m_outStreamEvent ;
    
    /** ѹ���ļ�������
    */
    RCArchiveUpdateFilterPtr m_spUpdateFilter ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveUpdateCallback_h_
