/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdateCallbackUI_h_
#define __RCUpdateCallbackUI_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "interface/RCPropertyID.h"
#include "common/RCVariant.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ���ļ�������
*/
class RCArchiveUpdateFilter ;

/** ѹ������ص��ӿ�
*/
class RCUpdateCallbackUI
{
public:

    /** ��������
    @param [in] total ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetTotal(uint64_t total) = 0;

    /** �������
    @param [in] completed �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t completed) = 0;

    /** �������������Ϣ
    @param [in] inSize �����ֽ���
    @param [in] outSize ����ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) = 0;
    
    /** ���õ����ļ�������Ϣ
    @param [in] index �ļ����
    @param [in] inSize �����ֽ���
    @param [in] outSize ����ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCompressRatioInfo(uint32_t index, uint64_t inSize, uint64_t outSize) = 0;

    /** ����û��Ƿ�ȡ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CheckBreak() = 0 ;

    /** ������ز���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Finilize() = 0 ;

    /** �����ļ���
    @param [in] numFiles �ļ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetNumFiles(uint64_t numFiles) = 0 ;

    /** ���ڶ�ȡ��ѹ�����ļ�
    @param [in] index ���ļ������
    @param [in] name ���ļ����ļ�����������·��
    @param [in] isAnti Anti����ֵ
    @param [in] modifyTime ���ļ�������޸�ʱ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, 
                              const RCString& name, 
                              bool isAnti, 
                              const RC_FILE_TIME& modifyTime) = 0 ;
    
    /** ��ȡѹ���ĵ�����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchiveProperty(RCPropertyID propID, RCVariant& value) = 0 ;

    /** ���ļ����
    @param [in] index �ļ����
    @param [in] name �ļ���
    @param [in] result �򿪽��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenFileResult(uint32_t index, const RCString& name, HResult result) = 0 ;

    /** ���ò������
    @param [in] index �ļ����
    @param [in] operationResult �������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t operationResult) = 0;

    /** ���ܿ�������
    @param [out] passwordIsDefined �����Ƿ��� ����0��ʾû�ж������룬����1��ʾ������
    @param [out] password ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CryptoGetTextPassword2(int32_t* passwordIsDefined, RCString& password) = 0 ;
    
    /** ����ѹ���ļ�ʱ��7z��ʵѹ����Ҫ������ܿ���
    @param [out] password ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CryptoGetTextPassword(RCString& password) = 0 ;

    /** ����ѹ����ѹ���߳�ģʽ
    @param [in] isMultThread �Ƿ�Ϊ���߳�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetMultiThread(bool isMultThread) = 0 ;
    
    /** ����ѹ��ע��
    @param [in] commentValue �µ�ע��ֵ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetComment(const RCString& commentValue) = 0 ;
};

/** ѹ����������ص�
*/
class RCUpdateCallbackUI2 : 
    public RCUpdateCallbackUI
{
public:
    
    /** ���ĵ����
    @param [in] name �ļ���
    @param [in] result �򿪽��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenResult(const RCString& name, HResult result) = 0 ;

    /** ��ʼɨ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult StartScanning() = 0 ;

    /** ɨ����Ȼص�
    @param [in] numFolders Ŀ¼��
    @param [in] numFiles �ļ���
    @param [in] path ɨ��·��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ScanProgress(uint64_t numFolders, uint64_t numFiles, const RCString& path) = 0 ;

    /** ɨ�����ص�
    @param [in] name ɨ��·��
    @param [in] systemError ϵͳ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CanNotFindError(const RCString& name, HResult systemError) = 0 ;

    /** ɨ����ɻص�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult FinishScanning() = 0 ;

    /** ��ʼ�ĵ�����
    @param [in] name �ļ���
    @param [in] updating �Ƿ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult StartArchive(const RCString& name, bool updating) =0 ;

    /** ����ĵ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult FinishArchive() = 0 ;
    
    /** ѯ��ͼƬת���ӿ�
    @param [in] updateFilter ͼƬת��������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OnAskFileFilter(RCArchiveUpdateFilter* updateFilter) = 0 ;
    
    /** ��ʼת��ͼƬ
    @param [in] imageFile ͼƬ�ļ���
    @param [in] destFile ת�����ļ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OnConvertImageStart(const RCString& imageFile, const RCString& destFile) = 0 ;
    
    /** ����ת��ͼƬ
    @param [in] imageFile ͼƬ�ļ���
    @param [in] result ת�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OnConvertImageEnd(const RCString& imageFile, HResult result) = 0 ;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdateCallbackUI_h_
