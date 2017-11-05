/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2Handler_h_
#define __RCBZip2Handler_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "interface/IStream.h"
#include "common/RCSystemUtils.h"
#include "filesystem/RCTempFile.h"

BEGIN_NAMESPACE_RCZIP

class RCBZip2Handler:
    public IUnknownImpl5<IInArchive,
                         IOutArchive,
                         ISetCompressCodecsInfo,
                         ISetProperties,
                         IInArchiveGetStream>

{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2Handler() ;

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
    virtual HResult Extract(const RCVector<uint32_t>& indices, int32_t testMode, IArchiveExtractCallback* extractCallback);
    
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

    /** ��ȡ��
    @param [in] index �����±�ֵ
    @param [out] stream �����������ӿڣ����ü�����1
    @param [in] openCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialInStream** stream, IArchiveOpenCallback* openCallback);  
        
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

private:    
    
    /** ��ʼ��ѹ���㷨����
    */
    void InitMethodProperties() ;
    
private:

    /** ѹ�����ļ���
    */
    IInStreamPtr m_stream ;

    /** �����
    */
    ISequentialInStreamPtr m_seqStream ;
    
    /** ѹ�����С
    */
    uint64_t m_packSize ;

    /** ������ʼλ��
    */
    uint64_t m_startPosition ;
    
    /** ѹ�����Сֵ�Ƿ���Ч
    */
    bool m_packSizeDefined ;

    /** �������Ϣ������
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo ;

    /** Ƕ�װ���ѹ��ʱ�ļ�
    */
    RCTempFile m_tmpFile;

    /** Ƕ�װ����ļ���
    */
    IInStreamPtr m_subStream;

    //@{

    /** @name 
    */

    /** ѹ������
    */
    uint32_t m_level;

    /** �ֵ��С
    */
    uint32_t m_dicSize;

    /** passes
    */
    uint32_t m_numPasses;

    /** �߳���
    */
    uint32_t m_numThreads;

    //@}
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2Handler_h_
