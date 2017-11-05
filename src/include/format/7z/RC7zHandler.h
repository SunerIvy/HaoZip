/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zHandler_h_
#define __RC7zHandler_h_ 1

#include "RCArchiveOutHandler.h"
#include "format/7z/RC7zArchiveDatabaseEx.h"
#include "format/7z/RC7zCompressionMode.h"
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"
#include "format/7z/RC7zCompressionMode.h"
#include "format/7z/RC7zItem.h"

BEGIN_NAMESPACE_RCZIP

#ifdef RC_STATIC_SFX  

class RC7zHandler:
    public IUnknownImpl2<IInArchive,
                         ISetCompressCodecsInfo>

#else

class RC7zHandler:
    public RCArchiveOutHandler,
    public IUnknownImpl4<IInArchive,
                         IOutArchive,
                         ISetProperties,
                         ISetCompressCodecsInfo>
#endif
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zHandler() ;
    
    /** Ĭ����������
    */
    ~RC7zHandler() ;
    
public:

    //@{
    /**@name IInArchive �ӿ�
    */
    
    /** ���ĵ�
    @param [in] stream �������ӿ�
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Open(IInStream* stream, uint64_t maxCheckStartPosition, IArchiveOpenCallback* openArchiveCallback) ;
    
    /** �ر��ĵ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Close() ;
    
    /** ��ȡ���ݸ���
    @param [out] numItems �����ĵ����ݸ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfItems(uint32_t& numItems) ;
    
    /** ��ȡ����
    @param [in] index ���Ե��±�
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetProperty(uint32_t index, RCPropertyID propID, RCVariant& value) ;
    
    /** ��ѹ
    @param [in] indices ��Ҫ��ѹ��Item �±����飬�����������Ϊ�ձ�ʾ��ѹȫ������
    @param [in] testMode 1Ϊ����ģʽ��0 Ϊ������ѹģʽ
    @param [in] extractCallback ��ѹ�ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Extract(const std::vector<uint32_t>& indices, int32_t testMode, IArchiveExtractCallback* extractCallback) ;
    
    /** ��ȡ�ĵ�����
    @param [in] propID ����ID
    @param [out] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchiveProperty(RCPropertyID propID, RCVariant& value) ;
    
    /** ��ȡ���Ը���
    @param [out] numProperties �������Ը���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfProperties(uint32_t& numProperties) ;
    
    /** ��ȡ������Ϣ
    @param [in] index �����±�ֵ
    @param [out] name ������������
    @param [out] propID ��������ID
    @param [out] varType ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetPropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType) ;
    
    /** ��ȡ�ĵ����Ը���
    @param [out] numProperties �������Ը���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfArchiveProperties(uint32_t& numProperties) ;
    
    /** ��ȡ�ĵ�������Ϣ
    @param [in] index �����±�ֵ
    @param [out] name ������������
    @param [out] propID ��������ID
    @param [out] varType ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetArchivePropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType) ;
    
    //@}

#ifndef RC_STATIC_SFX

    //@{
    /**@name IOutArchive �ӿ�
    */
    
    /** ��������
    @param [in] outStream ������Ľӿ�ָ��
    @param [in] numItems �ĵ����ݵĸ���
    @param [in] updateCallback �ĵ����½ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult UpdateItems(ISequentialOutStream* outStream, 
                                uint32_t numItems, 
                                IArchiveUpdateCallback* updateCallback) ;
    
    /** ��ȡ�ļ�ʱ������
    @param [out] type ʱ��������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFileTimeType(uint32_t& type) ;
    
    //@} 
    
    //@{
    /**@name ISetProperties �ӿ�
    */
    
    /** ��������
    @param [in] propertyArray �ĵ�������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetProperties(const RCPropertyNamePairArray& propertyArray) ;
    
    //@}
    
#endif
    
    //@{
    /**@name ISetCompressCodecsInfo �ӿ�
    */
    
    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) ;
    
    //@}
    
private:
    
    /** �Ƿ����
    @param [in] index2 ����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEncrypted(uint32_t index2) const ;

#ifndef RC_STATIC_SFX 

    /** ��������
    @param [in] methodMode ѹ��ģʽ
    @param [in] updateCallback ��ѹ�ص�������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetPassword(RC7zCompressionMethodMode& methodMode, IArchiveUpdateCallback* updateCallback) ;

    /** ����ѹ��ģʽ
    @param [in] methodMode ѹ��ģʽ
    @param [in] methodsInfo ģʽ��Ϣ
    @param [in] numThreads �߳���
    @param [in] totalSize �ܴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetCompressionMethod(RC7zCompressionMethodMode& methodMode, 
                                 RCVector<RCOneMethodInfo>& methodsInfo, 
                                 uint32_t numThreads,
                                 uint64_t totalSize) ;

    /** ����ѹ��ģʽ 
    @param [in] methodMode ѹ��ģʽ
    @param [in] headerMethod ͷѹ��ģʽ
    @param [in] totalSize �ܴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetCompressionMethod(RC7zCompressionMethodMode& methodMode,
                                 RC7zCompressionMethodMode& headerMethod,
                                 uint64_t totalSize) ;
#endif

    /** ��ȡ����
    @param [in] index ����
    @param [in] propID ����ID
    @param [in] value ����ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult DoGetProperty(uint32_t index, RCPropertyID propID, RCVariant& value) ;

private:

    /** �Ƿ���copyģʽ
    @param [in] methodName ģʽ��
    @return �Ƿ���true�����򷵻�false
    */
    static bool IsCopyMethod(const RCString& methodName) ;
    
private:

    /** ������
    */
    IInStreamPtr m_inStream ;

    /** �ĵ���������
    */
    RC7zArchiveDatabaseEx m_db ;

    /** �Ƿ�������
    */
    bool m_passwordIsDefined ;

    /** �߳���
    */
    uint32_t m_numThreads ;

    /** crc��С
    */
    uint32_t m_crcSize ; 

    /** ����Ϣ
    */
    RCVector<RC7zBind> m_binds ;

    /** ���������
    */
    ICompressCodecsInfoPtr m_codecsInfo ;
    
#ifndef RC_STATIC_SFX

    /** ��С�ֽ����ȡUint32
    @param [in] p �ڴ�����
    @return uint32
    */
    static uint32_t GetUInt32FromMemLE(const byte_t* p) ;

    /** Uint32ת���ַ���
    @param [in] value ��ֵ
    @return �ַ���
    */
    static RCString ConvertUInt32ToString(uint32_t value) ;

    /** ��Сת���ַ���
    @param [in] value ��ֵ
    @return �ַ���
    */
    static RCString GetStringForSizeValue(uint32_t value) ;

    /** ��ȡ������
    @param [in] value ��ֵ
    @return �ַ���
    */
    static RCString::value_type GetHex(byte_t value) ;

    /** �ַ�������Ӷ�����
    @param [in,out] result �����ַ����������ַ���
    @param [in] value ��ֵ
    */
    static void AddHexToString(RCString& result, byte_t value) ; 

#endif

    /** �ļ���Ϣ
    */
    RCVector<uint64_t> m_fileInfoPopIDs;

    /** ��ʼ������ID
    */
    void FillPopIDs() ;

    /** ��������
    @param [in] v RC7zUInt64DefVector
    @param [in] index ����
    @param [in] prop ����
    */
    static void SetPropFromUInt64Def(RC7zUInt64DefVector& v, int32_t index, RCVariant& prop) ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zHandler_h_
