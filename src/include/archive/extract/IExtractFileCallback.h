/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IExtractFileCallback_h_
#define __IExtractFileCallback_h_ 1

#include "interface/IProgress.h"
#include "base/RCString.h"
#include "archive/extract/RCExtractDefs.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ��ѹ���ļ��н�ѹ�ļ��ص������õ�λ�������ļ�
*/
class IExtractFolderArchiveCallback:
    public IProgress
{
public:

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
                                 RCString& newFileName) = 0 ;
    
    /** ��ѹ�ļ�ǰ�ص�����
    @param [in] index �ļ����
    @param [in] name �ļ�����
    @param [in] isFolder �Ƿ�Ϊ�ļ���
    @param [in] askExtractMode ��ѹѯ��ģʽ
    @param [in] unPackSize ԭ��С
    @param [in] position ��ɴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */                            
    virtual HResult PrepareOperation( uint32_t index,
                                      const RCString& name, 
                                      bool isFolder,                                       
                                      RCExractAskMode askExtractMode, 
                                      uint64_t unPackSize,
                                      const uint64_t* position) = 0 ;
    
    /** ��ѹ�ļ�������Ϣ
    @param [in] index ���
    @param [in] message ������Ϣ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult MessageError(uint32_t index, const RCString& message) = 0 ;
    
    /** ��ѹ�ļ��������
    @param [in] index �ļ����
    @param [in] operationResult ��ѹ���
    @param [in] encrypted �Ƿ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index,
                                       RCExractOperationResult operationResult,
                                       bool encrypted) = 0 ;

protected:
    
    /** Ĭ����������
    */
    virtual ~IExtractFolderArchiveCallback() {} ;
};

/** ѹ���ļ���ѹ����ص������õ�λ��ѹ����
*/
class IExtractCallbackUI : 
    public IExtractFolderArchiveCallback
{
public:
    
    /** ��ѹ���ļ�֮ǰ�¼�
    @param [in] name ѹ���ļ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult BeforeOpen(const RCString& name) = 0 ;
    
    /** ��ѹ���ļ�����¼�
    @param [in] name ѹ���ļ���
    @param [in] result ��ѹ���ļ����
    @param [in] encrypted ѹ���ļ��Ƿ�Ϊ�����ļ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenResult(const RCString& name, HResult result, bool encrypted) = 0 ;
    
    /** ѹ���ļ���û���ļ����Խ�ѹ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ThereAreNoFiles() = 0 ;
    
    /** ѹ���ļ���ѹ���
    @param [in] result ��ѹ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ExtractResult(HResult result) = 0;
    
    /** ���ý�ѹ����
    @param [in] password ��ѹ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetPassword(const RCString& password) = 0 ;

    /** ���ؽ�ѹ�����еĴ�����
    @return ���ؽ�ѹ���̴�����
    */
    virtual uint64_t GetErrorCount(void) = 0 ;

protected:
    
    /** Ĭ����������
    */
    virtual ~IExtractCallbackUI() {} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IExtractFolderArchiveCallback> IExtractFolderArchiveCallbackPtr ;

END_NAMESPACE_RCZIP

#endif //__IExtractFileCallback_h_
