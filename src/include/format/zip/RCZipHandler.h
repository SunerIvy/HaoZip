/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipHandler_h_
#define __RCZipHandler_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "interface/IStream.h"
#include "common/RCSystemUtils.h"
#include "RCZipExtFilter.h"
#include "RCZipFileFilter.h"
#include "RCZipItem.h"
#include "RCZipIn.h"

BEGIN_NAMESPACE_RCZIP

class RCZipHandler:
    public IUnknownImpl4<IInArchive,IOutArchive,ISetCompressCodecsInfo,ISetProperties>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipHandler() ;

    /** Ĭ����������
    */
    ~RCZipHandler() ;

public:

    /** ���ĵ�
    @param [in] stream �������ӿ�
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Open(IInStream* stream, uint64_t maxCheckStartPosition, IArchiveOpenCallback* openArchiveCallback);
    
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
    virtual HResult Extract(const std::vector<uint32_t>& indices, int32_t testMode, IArchiveExtractCallback* extractCallback);
    
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
    
public:

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

public:

    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) ;

public:

    /** ��������
    @param [in] propertyArray �ĵ�������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetProperties(const RCPropertyNamePairArray& propertyArray) ;

public:

    /** �ļ���չ���㷨������
    */
    static RCVector<RCZipExtFilterPtr> s_extFilters;

    /** �ļ��㷨������
    */
    static RCZipFileFilter s_fileFilter;

private:
    /** �Ƿ������������ļ����͹���
    */
    bool m_hasExtFilters ;

    /** �Ƿ��������ļ�ѹ���㷨����
    */
    bool m_hasFileFilters ;

private:

    /** zip items
    */
    RCVector<RCZipItemExPtr> m_zipItems;

#ifdef COMPRESS_MT
    /** �����ĵ�
    */
    RCVector<RCZipInPtr> m_zipInArchive;

    /** ������
    */
    RCVector<IInStreamPtr> m_spInStream;
#else
    /** �����ĵ�
    */
    RCZipIn m_zipInArchive;
#endif

    /** �������������ӿ�ָ��
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo;

    //@{

    /** @name method mode 
    */

    /** ѹ���ȼ�
    */
    int32_t m_level;

    /** ��ģʽ
    */
    int32_t m_mainMethod;

    /** �ֵ��С
    */
    uint32_t m_dicSize;

    /** algo
    */
    uint32_t m_algo;

    /** passes
    */
    uint32_t m_numPasses;

    /** fastbytes
    */
    uint32_t m_numFastBytes;

    /** ƥ����������
    */
    uint32_t m_numMatchFinderCycles;

    /** �Ƿ�ƥ����������
    */
    bool m_numMatchFinderCyclesDefined;

    //@}

    //@{

    /** @name AES
    */

    /** ǿ��ACEģʽ
    */
    bool m_forceAesMode;

    /** �Ƿ���ACEģʽ
    */
    bool m_isAesMode;

    /** AESģʽ�ܳ�
    */
    byte_t m_aesKeyMode;

    //@}

    //@{

    /** @name local
    */

    /** ntfsʱ��
    */
    bool m_writeNtfsTimeExtra;

    /** local
    */
    bool m_forseLocal;

    /** utf8
    */
    bool m_forseUtf8;

    //@}

#ifdef COMPRESS_MT
    /** �߳���
    */
    uint32_t m_numThreads;
#endif

    void InitMethodProperties()
    {
        m_level      = -1;
        m_mainMethod = -1;
        m_algo       = 0xFFFFFFFF;
        m_dicSize    = 0xFFFFFFFF;
        m_numPasses  = 0xFFFFFFFF;
        m_numFastBytes = 0xFFFFFFFF;
        m_numMatchFinderCycles = 0xFFFFFFFF;
        m_numMatchFinderCyclesDefined = false;

        m_forceAesMode = false;
        m_isAesMode  = false;
        m_aesKeyMode = 3; // aes-256

        m_writeNtfsTimeExtra = true;
        m_forseLocal = false;
        m_forseUtf8  = false;

#ifdef COMPRESS_MT
        m_numThreads = RCSystemUtils::GetNumberOfProcessors();
#endif
    }
};

END_NAMESPACE_RCZIP

#endif //__RCZipHandler_h_
