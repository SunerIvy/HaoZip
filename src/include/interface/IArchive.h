/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IArchive_h
#define __IArchive_h 1

#include "interface/IProgress.h"
#include "interface/IArchiveInfo.h"
#include "base/RCString.h"
#include "common/RCProperty.h"
#include "archive/extract/RCExtractDefs.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ�������ļ�ʱ���ʽ����
*/
enum RCArchiveFileTimeType
{
    /** Windows�ļ�ʱ��
    */
    RC_ARCHIVE_FILE_TIME_TYPE_WINDOWS   = 0 , 
    
    /** UNIX�ļ�ʱ��
    */
    RC_ARCHIVE_FILE_TIME_TYPE_UNIX      = 1 ,
    
    /** DOS�ļ�ʱ��
    */ 
    RC_ARCHIVE_FILE_TIME_TYPE_DOS       = 2
};

/** ��ѹ�ļ��������
*/
enum RCArchiveExtractResult
{
    /** ��ѹ�ɹ�
    */
    RC_ARCHIVE_EXTRACT_RESULT_OK                    = 0 ,
    
    /** ��ѹʱ������֧�ֵ��㷨
    */
    RC_ARCHIVE_EXTRACT_RESULT_UNSUPPORTED_METHOD    = 1 ,
    
    /** ��ѹʱ������������
    */
    RC_ARCHIVE_EXTRACT_RESULT_DATA_ERROR            = 2 ,
    
    /** ��ѹʱ����CRCУ�����
    */
    RC_ARCHIVE_EXTRACT_RESULT_CRC_ERROR             = 3
};

/** ��ѹ�ļ�ѯ��ģʽ
*/
enum RCArchiveExtractAskMode
{
    /** ���ڽ�ѹ�ļ�
    */
    RC_ARCHIVE_EXTRACT_ASK_MODE_EXTRACT         = 0 ,
    
    /** ���ڲ����ļ�
    */
    RC_ARCHIVE_EXTRACT_ASK_MODE_TEST            = 1 ,
    
    /** ���������ļ�
    */
    RC_ARCHIVE_EXTRACT_ASK_MODE_SKIP            = 2 ,
    
    /** û�пɽ�ѹ���ļ�
    */
    RC_ARCHIVE_EXTRACT_ASK_MODE_NO_FILE         = 3
};

/** ѹ���ļ��������
*/
enum RCArchiveUpdateResult
{
    /** ѹ���ļ������ɹ�
    */
    RC_ARCHIVE_UPDATE_RESULT_OK     = 0 ,
    
    /** ѹ���ļ�����ʧ��
    */
    RC_ARCHIVE_UPDATE_RESULT_ERROR  = 1
};

/** �ӿ�ID����
*/
enum
{
    IID_IArchiveOpenCallback     = IID_IARCHIVE_BASE,
    IID_IArchiveExtractCallback ,
    IID_IArchiveOpenVolumeCallback ,
    IID_IInArchiveGetStream ,
    IID_IArchiveOpenSetSubArchiveName ,
    IID_IInArchive ,
    IID_IArchiveUpdateCallback ,
    IID_IArchiveUpdateCallback2 ,
    IID_IOutArchive ,
    IID_ISetProperties ,
    IID_IArchiveCodecsInfo ,
    IID_IArchiveVolumeType
};

class IInStream ;
class ISequentialInStream ;
class ISequentialOutStream ;

/** ѹ���ļ��־���Ϣ
*/
struct RCArchiveVolumeItem
{
    /** �־��ļ���
    */
    RCString m_filename;
    
    /** �����
    */
    unsigned short m_volumeIndex;
    
    /** �Ƿ�Ϊ��һ����
    */
    bool m_isFirst;
    
    /** �Ƿ�Ϊ���һ����
    */
    bool m_isEnd;

    /** �Ƚϲ�����
    @param [in] item ��Ҫ�Ƚϵľ���Ϣ
    @return �����ǰ�����С�ڱȽϾ���ţ�����true, ���򷵻�false
    */
    bool operator< (const RCArchiveVolumeItem& item) const   
    {   
        return m_volumeIndex < item.m_volumeIndex;
    }
};

/** �ļ��򿪻ص��ӿ� 
*/
class IArchiveOpenCallback:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveOpenCallback } ;
    
public:
    
    /** ������
    @param [in] files �ܵ��ļ����������Ϊ -1, ���ʾ�޷�ͨ���ļ�����ʾ����
    @param [in] bytes �ܵ��ļ���С�����Ϊ -1, ���ʾ�޷�ͨ���ֽ�����ʾ����
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetTotal(uint64_t files, uint64_t bytes) = 0 ;
    
    /** �������
    @param [in] files �Ѿ���ɵ��ļ�����
    @param [in] bytes �Ѿ���ɵ��ļ���С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetCompleted(uint64_t files, uint64_t bytes) = 0 ;

    /** ����Ƿ���ֹ
    @return ������ֹ����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult CheckBreak() = 0;

    /** �޸��־�
    @param [in] items �޸�ǰ�ķ־�����
    @param [out] volumeFirst ��һ���־�
    @param [out] outputFilenames �޸���ķ־�����
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult VolumeRepair(const RCVector<RCArchiveVolumeItem>& items, RCString& volumeFirst, RCVector<RCString>& outputFilenames) = 0;
    
    /** ���ô���
    @param [in] errorCode �����
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetError(int32_t errorCode) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IArchiveOpenCallback(){} ;
};

/** �ĵ���ѹ�ص��ӿ� 
*/
class IArchiveExtractCallback : 
    public IProgress
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveExtractCallback } ;
    
public:
    
    /** ��ȡ�����
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [out] outStream ������Ľӿ�ָ�룬���ü�����1
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetStream(uint32_t index, ISequentialOutStream** outStream, int32_t askExtractMode) = 0 ;
    
    /** ׼����ѹ����
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] askExtractMode ��ѹģʽ
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult PrepareOperation(uint32_t index, int32_t askExtractMode) = 0 ;
    
    /** ���ý��
    @param [in] index ��ѹ�ļ�����Ŀ¼���±�ֵ
    @param [in] resultEOperationResult �������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t resultEOperationResult) = 0 ;
    
    /** ���ö��߳̽�ѹ���
    @param [in] isMultiThreads ���Ϊtrue����ǰΪ���߳̽�ѹģʽ������Ϊ���߳̽�ѹģʽ
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetMultiThreadMode(bool isMultiThreads) = 0 ;

    /** ��ȡ��ѹ·��
    @param [out] path ��ѹ·��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetDestinationDirectory(RCString& path) = 0 ;
    
    /** ��ȡ��Ҫ�ӽ�ѹ·����ȥ����·������
    @param [out] removePathParts ��Ҫ�ӽ�ѹ·����ȥ����·������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetRemovePathParts(RCVector<RCString>& removePathParts) = 0 ;

    /** ��ȡ��ѹ·��ѡ��
    @param [out] pathMode ��ѹ·��ѡ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetPathMode(RCExractPathMode& pathMode) = 0 ;

    /** ��ȡ��ѹ����ѡ��
    @param [out] overwriteMode ��ѹ����ѡ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetOverwriteMode(RCExractOverwriteMode& overwriteMode) = 0 ;

    /** ��ȡ��ѹ���·�ʽ
    @param [out] updateMode ��ѹ���·�ʽ
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult GetUpdateMode(RCExractUpdateMode& updateMode) = 0 ;
    
    /** �Ƿ������ļ�
    return ����������ļ�������true, ���򷵻�false
    */
    virtual bool IsKeepDamageFiles(void) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IArchiveExtractCallback(){} ;
};


/** �򿪾�ص��ӿ� 
*/
class IArchiveOpenVolumeCallback:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveOpenVolumeCallback } ;
    
public:
    
    /** ��ȡ����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetProperty(RCPropertyID propID, RCVariant& value) = 0 ;
    
    /** ��ȡ��
    @param [in] name ������������
    @param [out] inStream �����������ӿڣ����ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(const RCString& name, IInStream** inStream) = 0 ;

    /** ��ȡ·��
    @param [out] folder ����·��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFolderPrefix(RCString& folder) = 0;
    
protected:
    
    /** Ĭ����������
    */
    ~IArchiveOpenVolumeCallback(){} ;
};

/** �����ĵ���ȡ���ӿ� 
*/
class IInArchiveGetStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IInArchiveGetStream } ;
    
public:
    
    /** ��ȡ��
    @param [in] index �����±�ֵ
    @param [out] stream �����������ӿڣ����ü�����1
    @param [in] openCallback �򿪽��Ȼص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialInStream** stream, IArchiveOpenCallback* openCallback) = 0 ;  

protected:
    
    /** Ĭ����������
    */
    ~IInArchiveGetStream(){} ;
};

/** �������ĵ������ƽӿ�
*/
class IArchiveOpenSetSubArchiveName:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveOpenSetSubArchiveName } ;
    
public:
    
    /** ��������
    @param [in] name �ĵ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetSubArchiveName(const RCString& name) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IArchiveOpenSetSubArchiveName(){} ;    
};

/** �����ĵ��ӿ� 
*/
class IInArchive:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IInArchive } ;
    
public:
    
    /** ���ĵ�
    @param [in] stream �������ӿ�
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Open(IInStream* stream, uint64_t maxCheckStartPosition, IArchiveOpenCallback* openArchiveCallback) = 0;
    
    /** �ر��ĵ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Close() = 0 ;
    
    /** ��ȡ���ݸ���
    @param [out] numItems �����ĵ����ݸ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfItems(uint32_t& numItems) = 0 ;
    
    /** ��ȡ����
    @param [in] index ���Ե��±�
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetProperty(uint32_t index, RCPropertyID propID, RCVariant& value) = 0 ;
    
    /** ��ѹ
    @param [in] indices ��Ҫ��ѹ��Item �±����飬�����������Ϊ�ձ�ʾ��ѹȫ������
    @param [in] testMode 1Ϊ����ģʽ��0 Ϊ������ѹģʽ
    @param [in] extractCallback ��ѹ�ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Extract(const std::vector<uint32_t>& indices, int32_t testMode, IArchiveExtractCallback* extractCallback) = 0;
    
    /** ��ȡ�ĵ�����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchiveProperty(RCPropertyID propID, RCVariant& value) = 0;
    
    /** ��ȡ���Ը���
    @param [out] numProperties �������Ը���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfProperties(uint32_t& numProperties) = 0;
    
    /** ��ȡ������Ϣ
    @param [in] index �����±�ֵ
    @param [out] name ������������
    @param [out] propID ��������ID
    @param [out] varType ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetPropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType) = 0;
    
    /** ��ȡ�ĵ����Ը���
    @param [out] numProperties �������Ը���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfArchiveProperties(uint32_t& numProperties) = 0 ;
    
    /** ��ȡ�ĵ�������Ϣ
    @param [in] index �����±�ֵ
    @param [out] name ������������
    @param [out] propID ��������ID
    @param [out] varType ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchivePropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType) = 0;
    
protected:
    
    /** Ĭ����������
    */
    ~IInArchive(){} ;
};

/** �ĵ����»ص��ӿ�
*/
class IArchiveUpdateCallback : 
    public IProgress
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveUpdateCallback } ;
    
public:
    
    /** ��ȡ������Ϣ
    @param [in] index �����±�ֵ
    @param [out] newData ����������ݷ���1������Ǿ����ݷ���0
    @param [out] newProperties ����������Է���1������Ǿ����Է���0
    @param [out] indexInArchive ���������ĵ����±�ֵ�����ʧ�ܷ���-1
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetUpdateItemInfo(uint32_t index, 
                                      int32_t& newData,
                                      int32_t& newProperties,
                                      uint32_t& indexInArchive ) = 0 ;
    
    /** ��ȡ����
    @param [in] index �����±�
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetProperty(uint32_t index, RCPropertyID propID, RCVariant& value) = 0 ;
    
    /** ��ȡѹ���ĵ�����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchiveProperty(RCPropertyID propID, RCVariant& value) = 0 ;
    
    /** ��ȡ������
    @param [in] index ���������±�
    @param [out] inStream �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialInStream** inStream) = 0 ;
    
    /** ���ý��
    @param [in] index ���������±�
    @param [in] operationResult �������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetOperationResult(uint32_t index, int32_t operationResult) = 0 ;

protected:
    
    /** Ĭ����������
    */
    ~IArchiveUpdateCallback(){} ;
};

/** �ĵ����»ص��ӿ�
*/
class IArchiveUpdateCallback2 : 
    public IArchiveUpdateCallback
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveUpdateCallback2 } ;
    
public:
    
    /** ��ȡ���С
    @param [in] index ����±�
    @param [out] size ��Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetVolumeSize(uint32_t index, uint64_t& size) = 0 ;
    
    /** ��ȡ���Ӧ����
    @param [in] index ����±�
    @param [out] volumeStream ������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetVolumeStream(uint32_t index, ISequentialOutStream** volumeStream) = 0 ;

protected:
    
    /** Ĭ����������
    */
    ~IArchiveUpdateCallback2(){} ;
};

/** ����ĵ��ӿ�
*/
class IOutArchive:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IOutArchive } ;
    
public:
    
    /** ��������
    @param [in] outStream ������Ľӿ�ָ��
    @param [in] numItems �ĵ����ݵĸ���
    @param [in] updateCallback �ĵ����½ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult UpdateItems(ISequentialOutStream* outStream, 
                                uint32_t numItems, 
                                IArchiveUpdateCallback* updateCallback) = 0 ;
    
    /** ��ȡ�ļ�ʱ������
    @param [out] type ʱ��������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFileTimeType(uint32_t& type) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IOutArchive(){} ;
};

/** �����ĵ����� 
*/
class ISetProperties:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ISetProperties } ;
    
public:
    
    /** ��������
    @param [in] propertyArray �ĵ�������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetProperties(const RCPropertyNamePairArray& propertyArray) = 0;

protected:
    
    /** Ĭ����������
    */
    ~ISetProperties(){} ;
};

typedef RCComPtr<IInArchive>                    IInArchivePtr ;
typedef RCComPtr<IOutArchive>                   IOutArchivePtr ;

/** �ĵ���ʽ����ӿ�
*/
class IArchiveCodecsInfo:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveCodecsInfo } ;
    
public:
    
    /** ��ȡ֧�ֵ��ĵ���ʽ����
    @param [out] numFormats �ĵ���ʽ��ʽ
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfFormats(uint32_t& numFormats) const = 0 ;
    
    /** ��ȡ�ĵ���Ϣ
    @param [in] index �ĵ���ʽ�±�
    @param [out] spArcInfo �ĵ���ʽ��Ϣ
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFormat(uint32_t index, IArchiveInfoPtr& spArcInfo) const = 0 ;
    
    /** ���������ĵ��ӿ�
    @param [in] index �ĵ���ʽ�±�
    @param [out] spInArchive �����ĵ��ӿ�
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult CreateInArchive(uint32_t index, IInArchivePtr& spInArchive) const = 0 ;
    
    /** ��������ĵ��ӿ�
    @param [in] index �ĵ���ʽ�±�
    @param [out] spOutArchive ����ĵ��ӿ�
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult CreateOutArchive(uint32_t index, IOutArchivePtr& spOutArchive) const = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IArchiveCodecsInfo(){} ; 
};

/** ��ȡ�ļ���ʽ�־����Խӿ�
*/
class IArchiveVolumeType:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IArchiveVolumeType } ;
    
public:
    /** ��ȡ��ʽ����
    @param [in] inStream �ļ�������
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [out] isVolume �־�ѹ��������true�����򷵻�false
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetVolumeType(IInStream* inStream, uint64_t maxCheckStartPosition, bool& isVolume) = 0 ;
        
protected:
    
    /** Ĭ����������
    */
    ~IArchiveVolumeType(){} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IArchiveOpenCallback>          IArchiveOpenCallbackPtr ;
typedef RCComPtr<IArchiveExtractCallback>       IArchiveExtractCallbackPtr ;
typedef RCComPtr<IArchiveOpenVolumeCallback>    IArchiveOpenVolumeCallbackPtr ;
typedef RCComPtr<IInArchiveGetStream>           IInArchiveGetStreamPtr ; 
typedef RCComPtr<IArchiveOpenSetSubArchiveName> IArchiveOpenSetSubArchiveNamePtr ;
typedef RCComPtr<IInArchive>                    IInArchivePtr ;
typedef RCComPtr<IArchiveUpdateCallback>        IArchiveUpdateCallbackPtr ;
typedef RCComPtr<IArchiveUpdateCallback2>       IArchiveUpdateCallback2Ptr ;
typedef RCComPtr<IOutArchive>                   IOutArchivePtr ;
typedef RCComPtr<ISetProperties>                ISetPropertiesPtr ;
typedef RCComPtr<IArchiveCodecsInfo>            IArchiveCodecsInfoPtr ;
typedef RCComPtr<IArchiveVolumeType>            IArchiveVolumeTypePtr ;

END_NAMESPACE_RCZIP

#endif //__IArchive_h
