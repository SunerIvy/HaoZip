/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdate_h_
#define __RCUpdate_h_ 1

#include "base/RCtypes.h"
#include "base/RCWindowsDefs.h"
#include "archive/manager/RCArchiveCodecs.h"
#include "archive/update/RCUpdateOptions.h"
#include "archive/update/RCUpdateErrorInfo.h"
#include "archive/update/RCUpdateCallbackUI.h"
#include "archive/update/RCCompressMethodMode.h"
#include "archive/common/IOpenCallbackUI.h"
#include "archive/common/RCArcItem.h"
#include "archive/common/RCDirItems.h"
#include "archive/common/RCTempFiles.h"

BEGIN_NAMESPACE_RCZIP

/** ͨ���ƥ��
*/
class RCWildcardCensor ;

/** ������¼��ӿ�
*/
class IOutStreamEvent ;

/** �������̷�װ
*/
class RCUpdate
{
public:

    /** ѹ������
    @param [in] codecs ���������
    @param [in] censor ͨ���ƥ��
    @param [in] options ���²���
    @param [out]  errorInfo ������Ϣ
    @param [in] openCallback �򿪻ص��ӿ�
    @param [in] callback ����ص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult UpdateArchive(const RCArchiveCodecsPtr& codecs,
                                 const RCWildcardCensor& censor,
                                 RCUpdateOptions& options,
                                 RCUpdateErrorInfo& errorInfo,
                                 IOpenCallbackUI* openCallback,
                                 RCUpdateCallbackUI2* callback);
private:
    
    /** ����ѹ���ļ�����
    @param [in] codecs ���������
    @param [in] options ���²���
    @param [in] archive �����ĵ�
    @param [in] arcItems �����ļ��б�
    @param [in] dirItems �������б�
    @param [in] tempFiles ��ʱ�ļ�
    @param [out] errorInfo ������Ϣ
    @param [in] callback ���»ص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult UpdateWithItemLists(const RCArchiveCodecsPtr& codecs,
                                       RCUpdateOptions& options,
                                       IInArchive* archive,
                                       const RCVector<RCArcItem>& arcItems,
                                       RCDirItems& dirItems,
                                       RCTempFiles& tempFiles,
                                       RCUpdateErrorInfo& errorInfo,
                                       RCUpdateCallbackUI2* callback);

    /** ��ȡ�����ĵ��е�����
    @param [in] censor ͨ���ƥ��
    @param [in] archive �����ĵ�
    @param [in] defaultItemName ȱʡ�ļ���
    @param [out] archiveFileInfo �ĵ���Ϣ
    @param [out] arcItems �������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult EnumerateInArchiveItems(const RCWildcardCensor& censor,
                                           IInArchive* archive,
                                           const RCString& defaultItemName,
                                           RCFileInfo& archiveFileInfo,
                                           RCVector<RCArcItem>& arcItems);

    /** ѹ������
    @param [in] codecs ���������
    @param [in] actionSet ���·�ʽ
    @param [in] archive �����ĵ�
    @param [in] compressionMethod ѹ��ģʽ
    @param [out] archivePath �ĵ�·��
    @param [in] arcItems �������б�
    @param [in] shareForWrite ����д
    @param [in] stdInMode ��׼����ģʽ
    @param [in] stdOutMode ��׼���ģʽ
    @param [in] isTestMode ����ģʽ
    @param [in] dirItems �������б�
    @param [in] sfxMode �Խ�ѹģʽ
    @param [in] sfxModule �Խ�ѹģ���ļ���
    @param [in] volumesSizes �־��С
    @param [in] tempFiles ��ʱ�ļ�
    @param [out] errorInfo ������Ϣ
    @param [in] callback ����ص��ӿ�
    @param [in] pathMode ·������ģʽ
    @param [in] outStreamEvent ������¼��ӿ�
    @param [in] options ���²���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult Compress(const RCArchiveCodecsPtr& codecs,
                            const RCActionSet& actionSet,
                            IInArchive* archive,
                            const RCCompressMethodMode& compressionMethod,
                            RCArchivePath& archivePath,
                            const RCVector<RCArcItem>& arcItems,
                            bool shareForWrite,
                            bool stdInMode,
                            bool stdOutMode,
                            bool isTestMode,
                            const RCDirItems& dirItems,
                            bool sfxMode,                            
                            const RCString& sfxModule,
                            const RCVector<uint64_t>& volumesSizes,
                            RCTempFiles& tempFiles,
                            RCUpdateErrorInfo& errorInfo,
                            RCUpdateCallbackUI* callback,
                            RCUpdateOptions::path_mode pathMode,
                            IOutStreamEvent* outStreamEvent,
                            const RCUpdateOptions& options );


    /** ��������
    @param [in] inStream ������
    @param [in] outStream �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult CopyBlock(ISequentialInStream* inStream, 
                             ISequentialOutStream* outStream);

    /** �Ƚ��ļ�ʱ��
    @param [in] arcItems �������б�
    @param [in] arcItemIndex ��Ŀ���
    @param [in] mTime �޸�ʱ��
    @return = 0, ���
            < 0, ���� < mTime
            > 0, ���� > mTime
    */
    static int32_t CompareArchiveItemFileTime(const RCVector<RCArcItem>& arcItems,
                                              size_t arcItemIndex,
                                              const RC_FILE_TIME& mTime) ;

    /** �����Ҫ���µ����ļ������й���
    @param [in] arcItems �������б�
    @param [in] dirItems �������б�
    @param [in] deleteNoneExists ɾ��������
    */
    static void FilterDirItems(const RCVector<RCArcItem>& arcItems,
                               RCDirItems& dirItems,
                               bool deleteNoneExists) ;

    /** ����Ѿ������ĵ��е��ļ������й���
    @param [in] arcItems �������б�
    @param [in] dirItems �������б�
    */
    static void FilterArcItems(RCVector<RCArcItem>& arcItems,
                               const RCDirItems& dirItems) ;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdate_h_
