/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtract_h_
#define __RCExtract_h_ 1

#include "archive/manager/RCArchiveCodecs.h"
#include "archive/extract/RCExtractOptions.h"
#include "archive/extract/RCExtractStatus.h"
#include "archive/common/RCWildcardCensorNode.h"
#include "interface/IArchiveInfo.h"
#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** �򿪽���ص��ӿ�
*/
class IOpenCallbackUI ;

/** ��ѹ����ص��ӿ�
*/
class IExtractCallbackUI ;

/** ͨ���ƥ��
*/
class RCWildcardCensorNode ;

/** ��ѹ�ص��ӿ�
*/
class RCExtractArchiveCallback;

/** ������¼��ӿ�
*/
class IOutStreamEvent ;

/** ��ѹ����
*/
class RCExtract:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCExtract() ;
    
    /** Ĭ����������
    */
    ~RCExtract() ;

public:
    
    /** ��ѹ����
    @param [in] spCodecs ���������
    @param [in] formatIndices �ļ���ʽ�б�
    @param [in] archivePaths ѹ����·���б�
    @param [in] archivePathsFull ѹ����ȫ·���б�
    @param [in] wildcardCensor ͨ���ƥ��
    @param [in] options ��ѹ����
    @param [in] openCallbackUI ѹ�����򿪻ص�����
    @param [in] extractCallbackUI ��ѹ�ص�����
    @param [out] errorMessage ������Ϣ
    @param [out] stat ��ѹ״̬
    @param [in] outStreamEvent ������¼��ӿ�
    @param [in] overWriteMode �ļ�����ģʽ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult DecompressArchives(const RCArchiveCodecsPtr& spCodecs, 
                               const RCVector<RCArchiveID>& formatIndices,
                               RCVector<RCString>& archivePaths, 
                               RCVector<RCString>& archivePathsFull,
                               const RCWildcardCensorNode& wildcardCensor,
                               const RCExtractOptions& options,
                               IOpenCallbackUI* openCallbackUI,
                               IExtractCallbackUI* extractCallbackUI,
                               RCString& errorMessage,
                               RCExtractStatus& stat,
                               IOutStreamEvent* outStreamEvent,
                               RCExractOverwriteMode* overWriteMode = 0);
private:
    
    /** �����ļ���ѹ����
    @param [in] archive �����ĵ�
    @param [in] packSize ѹ����С
    @param [in] wildcardCensor ͨ���ƥ��
    @param [in] options ��ѹ����
    @param [in] extractCallbackUI ��ѹ����ص��ӿ�
    @param [in] extractArchiveCallback �ĵ���ѹ�ص��ӿ�
    @param [out] errorMessage ������Ϣ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult DecompressArchive(IInArchive* archive,
                              uint64_t packSize,
                              const RCWildcardCensorNode& wildcardCensor,
                              const RCExtractOptions& options,
                              IExtractCallbackUI* extractCallbackUI,
                              RCExtractArchiveCallback* extractArchiveCallback,
                              RCString& errorMessage);

private:
    
    /** TRar�ļ�
    */
    struct TRarFile;

    /** Rar�ļ���
    */
    class RCRarFileName;

};

END_NAMESPACE_RCZIP

#endif //__RCExtract_h_
