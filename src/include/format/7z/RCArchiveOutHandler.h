/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveOutHandler_h_
#define __RCArchiveOutHandler_h_ 1

#include "format/common/RCMethodProps.h"
#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "common/RCVariant.h"
#include "RC7zExtFilter.h"
#include "RC7zFileFilter.h"

BEGIN_NAMESPACE_RCZIP

struct RCOneMethodInfo
{
    /** ����
    */
    RCVector<RCArchiveProp> m_properties;

    /** ģʽ��
    */
    RCString m_methodName;

    /** �Ƿ���LZMA
    */
    bool IsLzma() const ;

    /** �Ƿ���BZIP2
    */
    bool IsBZip2() const ;

    /** �Ƿ���PPMD
    */
    bool IsPPMd() const ;

    /** �Ƿ���Deflate
    */
    bool IsDeflate() const ;
};

class RCArchiveOutHandler:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveOutHandler() ;
    
    /** Ĭ����������
    */
    ~RCArchiveOutHandler() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;

    /** ��ʼ����ʵ
    */
    void InitSolid() ;

    /** ��ʼ����ʵ�ļ�
    */
    void InitSolidFiles() ;

    /** ��ʼ����ʵ��С
    */
    void InitSolidSize() ;

    /** ����������֮ǰ
    */
    void BeforeSetProperty() ;

    /** ��������
    @param [in] nameSpec
    @param [in] value
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetProperty(const RCString& nameSpec, const RCVariant& value) ;

    /** ���ù�ʵ
    @param [in] s ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetSolidSettings(const RCString& s);

    /** ���ù�ʵ
    @param [in] value ��ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetSolidSettings(const RCVariant& value) ;

    /** ���ò���
    @param [in] oneMethodInfo ģʽ��Ϣ
    @param [in] name ����
    @param [in] value ��ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetParam(RCOneMethodInfo& oneMethodInfo, const RCString& name, const RCString& value);

    /** ���ò���
    @param [in] oneMethodInfo ģʽ��Ϣ
    @param [in] srcString ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetParams(RCOneMethodInfo& oneMethodInfo, const RCString& srcString);

    /** ����ѹ��ģʽ
    @param [in] oneMethodInfo ģʽ��Ϣ
    @param [in] numThreads �̸߳���
    @param [in] totalSize �ܴ�С
    */
    void SetCompressionMethod2(RCOneMethodInfo& oneMethodInfo, uint32_t numThreads, uint64_t totalSize);
    
public:

    /** �̸߳���
    */
    uint32_t m_numThreads ;

    /** crc��С
    */
    uint32_t m_crcSize ;

    /** ģʽ
    */
    RCVector<RCOneMethodInfo> m_methods;

    /** �Ƿ��Ƴ��Խ�ѹ��
    */
    bool m_removeSfxBlock;

    /** ��ʵѹ�����ļ���
    */
    uint64_t m_numSolidFiles;

    /** ��ʵѹ�����ֽ���
    */
    uint64_t m_numSolidBytes;

    /** �Ƿ����ʵѹ�����ֽ���
    */
    bool m_numSolidBytesDefined;

    /** �Ƿ��й�ʵѹ����չ��Ϣ
    */ 
    bool m_solidExtension;

    /** �Ƿ���ѹ��ͷ
    */
    bool m_compressHeaders;

    /** �Ƿ�ָ���˼���ͷ
    */
    bool m_encryptHeadersSpecified;

    /** �Ƿ��м���ͷ
    */
    bool m_encryptHeaders;

    /** �Ƿ�д����ʱ��
    */
    bool m_writeCTime;

    /** �Ƿ�д����ʱ��
    */
    bool m_writeATime;

    /** �Ƿ�д�޸�ʱ��
    */
    bool m_writeMTime;

    /** �Ƿ��Զ�����
    */
    bool m_autoFilter;

    /** ѹ������
    */
    uint32_t m_level;

    /** �Ƿ�־�
    */
    bool m_volumeMode;

    /** ��С��
    */
    uint32_t m_minNumber;

    /** CPU����
    */
    uint32_t m_numProcessors;

    /** ���ֵ��С
    */
    uint32_t m_mainDicSize;

    /** ���ֵ�ģʽ����
    */
    uint32_t m_mainDicMethodIndex;

    /** �ļ���չ���㷨������
    */
    static RCVector<RC7zExtFilterPtr> s_extFilters ;

    /** �ļ��㷨������
    */
    static RC7zFileFilter s_fileFilter ;

private:

    /** �Ƿ������������ļ����͹���
    */
    bool m_hasExtFilters ;

    /** �Ƿ��������ļ�ѹ���㷨����
    */
    bool m_hasFileFilters ;
};

/** ����ģʽ������
@param [out] oneMethodInfo ���ģʽ����
@param [in] propID ����ID
@param [in] value ��ֵ
*/
void SetOneMethodProp(RCOneMethodInfo& oneMethodInfo, 
                      RCPropertyID propID,
                      const RCVariant& value);
END_NAMESPACE_RCZIP

#endif //__RCArchiveOutHandler_h_
