/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveOpenCallback_h_
#define __RCArchiveOpenCallback_h_ 1

#include "archive/common/IOpenCallbackUI.h"
#include "interface/IPassword.h"
#include "interface/IArchive.h"
#include "interface/IUnknownImpl.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "filesystem/RCFileInfo.h"

BEGIN_NAMESPACE_RCZIP

/** �ĵ��򿪻ص��ӿ�
*/
class RCArchiveOpenCallback:
    public IUnknownImpl4< IArchiveOpenCallback,
                          IArchiveOpenVolumeCallback,
                          IArchiveOpenSetSubArchiveName,
                          ICryptoGetTextPassword
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveOpenCallback() ;
    
    /** Ĭ����������
    */
    ~RCArchiveOpenCallback() ;

public:
    
    /** ��ʼ��
    @param [in] folderPrefix �ļ�·��������Ӧ����·���ָ���
    @param [in] fileName �ļ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Init(const RCString& folderPrefix,  const RCString& fileName) ;
    
    /** ��m_fileNames�в����ļ����������ִ�Сд
    @param [in] name �ļ���
    @return �����±꣬���ʧ�ܷ���-1
    */
    int32_t FindName(const RCString& name);

public:
    
    /** ������
    @param [in] files �ܵ��ļ�����
    @param [in] bytes �ܵ��ļ���С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetTotal(uint64_t files, uint64_t bytes) ;
    
    /** �������
    @param [in] files �Ѿ���ɵ��ļ�����
    @param [in] bytes �Ѿ���ɵ��ļ���С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t files, uint64_t bytes) ;

    /** ����Ƿ���ֹ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CheckBreak();
    
    /** �޸��־�
    @param [in] items �޸�ǰ�ķ־�����
    @param [in] volumeFirst ��һ���־�
    @param [out] outputFilenames �޸���ķ־�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult VolumeRepair(const RCVector<RCArchiveVolumeItem>& items, RCString& volumeFirst, RCVector<RCString>& outputFilenames);
    
    /** ���ô���
    @param [in] errorCode �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetError(int32_t errorCode) ;

    /** ��ȡ����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetProperty(RCPropertyID propID, RCVariant& value) ;
    
    /** ��ȡ��
    @param [in] name ������������
    @param [out] inStream �����������ӿڣ����ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(const RCString& name, IInStream** inStream) ;
    
    /** ��ȡ·��
    @param [out] folder ����·��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFolderPrefix(RCString& folder);

    /** ��������
    @param [in] name �ĵ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetSubArchiveName(const RCString& name) ;
    
    /** ��ȡ����
    @param [out] password ��ȡ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CryptoGetTextPassword(RCString& password) ;
    
    /** ��ȡ�ļ��б�
    @return �����ļ��б�
    */
    RCVector<RCString>& GetFileNames() ;
    
    /** ��ȡ�ļ��б�
    @return �����ļ��б�
    */
    const RCVector<RCString>& GetFileNames() const ;
    
    /** ��ȡ IOpenCallbackUI �ӿ�
    @return ���ؽ���򿪻ص��ӿ�ָ��
    */
    IOpenCallbackUI* GetCallback() ;
    
    /** ��ȡ IOpenCallbackUI �ӿ�
    @return ���ؽ���򿪻ص��ӿ�ָ��
    */
    const IOpenCallbackUI* GetCallback() const ;
    
    /** ���� IOpenCallbackUI �ӿ�
    @param [in] callback ����򿪻ص��ӿ�
    */
    void SetCallback(IOpenCallbackUI* callback) ;
    
    /** ��ȡ IArchiveOpenCallback �ӿ�
    @return �����ĵ��򿪻ص��ӿ�ָ��
    */
    const IArchiveOpenCallbackPtr& GetReOpenCallback() const ;
    
    /** ���� IArchiveOpenCallback �ӿ�
    @param [in] reOpenCallback �ļ��򿪻ص��ӿ�ָ��
    */
    void SetReOpenCallback( const IArchiveOpenCallbackPtr& reOpenCallback) ;
    
    /** ����TotalSize
    @param [in] totalSize �����ܴ�С
    */
    void SetTotalSize(uint64_t totalSize) ;
    
    /** ��ȡTotalSize
    @return �����ܴ�С
    */
    uint64_t GetTotalSize() const ;
    
    /** ��ȡTotalSize����
    @return �����ܴ�С������
    */
    uint64_t& TotalSize() ;
    
private:
    
    /** �ļ����б�
    */
    RCVector<RCString> m_fileNames ;
    
    /** �򿪽���ص��ӿ�ָ��
    */
    IOpenCallbackUI* m_callback ;
    
    /** �ĵ��򿪻ص��ӿ�ָ��
    */
    IArchiveOpenCallbackPtr m_reOpenCallback ;
    
    /** �ܴ�С
    */
    uint64_t m_totalSize ;
    
private:
    
    /** Ŀ¼ǰ׺
    */
    RCString m_folderPrefix ;
    
    /** �ļ���Ϣ�ṹ
    */
    RCFileInfo m_fileInfo;
    
    /** ���ĵ�ģʽ
    */
    bool m_subArchiveMode ;
    
    /** ���ĵ�����
    */
    RCString m_subArchiveName ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveOpenCallback_h_
