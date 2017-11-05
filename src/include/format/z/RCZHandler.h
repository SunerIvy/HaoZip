/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZHandler_h_
#define __RCZHandler_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "interface/IStream.h"
#include "interface/RCMethodDefs.h"
#include "filesystem/RCTempFile.h"

BEGIN_NAMESPACE_RCZIP

class RCZHandler:
    public IUnknownImpl3<IInArchive, 
                         ISetCompressCodecsInfo,
                         IInArchiveGetStream>
{
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
    virtual HResult Close();

    /** ��ȡ���ݸ���
    @param [out] numItems �����ĵ����ݸ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfItems(uint32_t& numItems);

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
    virtual HResult GetPropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType);

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
    virtual HResult GetArchivePropertyInfo(uint32_t index, RCString& name, RCPropertyID& propID, RCVariantType::RCVariantID& varType);

    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) ;
    
    /** ��ȡ��
    @param [in] index �����±�ֵ
    @param [out] stream �����������ӿڣ����ü�����1
    @param [in] openCallback �򿪽��Ȼص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetStream(uint32_t index, ISequentialInStream** stream, IArchiveOpenCallback* openCallback) ;

private:

    /** �ж��Ƿ�ΪǶ�׵�tar��ʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult IsNestedTarFile(void) ;
    
private:

    /** �������������ӿ�ָ��
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo;

    /** ������
    */
    IInStreamPtr m_stream;

    /** ������ʼλ��
    */
    uint64_t m_streamStartPosition;

    /** ѹ������С
    */
    uint64_t m_packSize;

    /** ����
    */
    byte_t m_properties;

    /** ǩ����С
    */
    static const int s_signatureSize = 3;
    
    /** Ƕ�װ���ѹ��ʱ�ļ�
    */
    RCTempFile m_tmpFile;

    /** Ƕ�װ����ļ���
    */
    IInStreamPtr m_subStream;
};

END_NAMESPACE_RCZIP

#endif //__RCZHandler_h_