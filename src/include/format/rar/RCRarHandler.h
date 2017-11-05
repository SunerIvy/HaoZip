/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarHandler_h_
#define __RCRarHandler_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "RCRarVolumeInStream.h"
#include "common/RCSystemUtils.h"

BEGIN_NAMESPACE_RCZIP

class RCRarHandler:
    public IUnknownImpl3<IInArchive,
                         ISetCompressCodecsInfo,
                         IArchiveVolumeType>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRarHandler()
    {
#ifdef COMPRESS_MT
        m_numThreads = RCSystemUtils::GetNumberOfProcessors();
#endif
    }

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

    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) ;

    /** ��ȡ��ʽ����
    @param [in] inStream �ļ�������
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [out] isVolume �־�ѹ��������true�����򷵻�false
    */
    virtual HResult GetVolumeType(IInStream* inStream, uint64_t maxCheckStartPosition, bool& isVolume) ;

private:

    /** ��ȡ���Ĵ�С
    @param [in] refIndex ����
    @return ���ذ��Ĵ�С
    */
    uint64_t GetPackSize(int32_t refIndex) const ;

    /** �Ƿ��ǹ�ʵѹ��
    @param [in] refIndex ����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSolid(int32_t refIndex)
    {
        const RCRarItemExPtr& item = m_items[m_refItems[refIndex]->m_itemIndex];
        if (item->m_unPackVersion < 20)
        {
            if (m_archiveInfo.IsSolid())
            {
                return (refIndex > 0);
            }
            return false;
        }
        return item->IsSolid();
    }

    /** ���ĵ�
    @param [in] stream ������
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open2(IInStream* stream, const uint64_t* maxCheckStartPosition, IArchiveOpenCallback* openArchiveCallback) ;

private:

    /** �������������ӿ�ָ��
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo ;

    /** ref��
    */
    RCVector<RCRarRefItemPtr> m_refItems ;

    /** ��
    */
    RCVector<RCRarItemExPtr> m_items ;

#ifdef COMPRESS_MT

    /** �ĵ�
    */
    RCVector<RCVector<RCRarIn>> m_archives;

    /** ������
    */
    RCVector<RCVector<IInStreamPtr>> m_spInStream;

#else

    /** �ĵ�
    */
    RCVector<RCRarIn> m_archives ;

#endif

    /** �ĵ���Ϣ
    */
    RCRarInArchiveInfo m_archiveInfo ;

#ifdef COMPRESS_MT

    /** �߳���
    */
    uint32_t m_numThreads ;

#endif
};

END_NAMESPACE_RCZIP

#endif //__RCRarHandler_h_
