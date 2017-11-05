/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIsoIn_h_
#define __RCIsoIn_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "common/RCStringBuffer.h"
#include "common/RCStringUtil.h"
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "RCIsoItem.h"
#include "RCIsoHeader.h"
#include "RCIsoDir.h"

BEGIN_NAMESPACE_RCZIP

struct RCIsoDateTime
{
    /** ��
    */
    uint16_t m_year;

    /** ��
    */
    byte_t m_month;

    /** ��
    */
    byte_t m_day;

    /** Сʱ
    */
    byte_t m_hour;

    /** ����
    */
    byte_t m_minute;

    /** ��
    */
    byte_t m_second;

    /** �ٷ�֮һ
    */
    byte_t m_hundredths;

    /** gmtƫ��
    */
    signed char m_gmtOffset;

    /** ��ָ��
    @return �Ƿ���ture�����򷵻�false
    */
    bool NotSpecified() const ;
};

struct RCIsoBootRecordDescriptor
{
    /** ����ϵͳid
    */
    byte_t m_bootSystemId[32];

    /** ����id
    */
    byte_t m_bootId[32];

    /** ����ϵͳʹ�õĻ�����
    */
    byte_t m_bootSystemUse[1977];
};

struct RCIsoBootValidationEntry
{
    /** ƽ̨id
    */
    byte_t m_platformId;

    /** id
    */
    byte_t m_id[24];
};

struct RCIsoBootInitialEntry
{
    /** ������
    */
    bool m_bootable;

    /** ����ý������
    */
    byte_t m_bootMediaType;

    /** ���ض�
    */
    uint16_t m_loadSegment;

    /** ϵͳ����
    */
    byte_t m_systemType;

    /** ������
    */
    uint16_t m_sectorCount;

    /** ����RBA
    */
    uint32_t m_loadRBA;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const;

    /** ��ȡ����
    @return ��������
    */
    RCString GetName() const;
};

struct RCIsoVolumeDescriptor
{
    /** ���־
    */
    byte_t m_volFlags;

    /** ϵͳid
    */
    byte_t m_systemId[32];

    /** ��id
    */
    byte_t m_volumeId[32];

    /** ��ռ��С
    */
    uint32_t m_volumeSpaceSize;

    /** ת������
    */
    byte_t m_escapeSequence[32];

    /** �����ô�С
    */
    uint16_t m_volumeSetSize;

    /** �����к�
    */
    uint16_t m_volumeSequenceNumber;

    /** �߼����С
    */
    uint16_t m_logicalBlockSize;

    /** ·�����С
    */
    uint32_t m_pathTableSize;

    /** ·����λ��(��λ)
    */
    uint32_t m_lPathTableLocation;

    /** ����·����λ��(��λ)
    */
    uint32_t m_lOptionalPathTableLocation;

    /** ·����λ��(��λ)
    */
    uint32_t m_mPathTableLocation;

    /** ����·����λ��(��λ)
    */
    uint32_t m_mOptionalPathTableLocation;

    /** ��Ŀ¼��¼
    */
    RCIsoDirRecord m_rootDirRecord;

    /** �������id
    */
    byte_t m_volumeSetId[128];

    /** ����id
    */
    byte_t m_publisherId[128];

    /** �����걨id 
    */
    byte_t m_dataPreparerId[128];

    /** Ӧ�ó���id
    */
    byte_t m_applicationId[128];

    /** ��˾�ļ�id 
    */
    byte_t m_copyrightFileId[37];

    /** �����ļ�id
    */
    byte_t m_abstractFileId[37];

    /** bib�ļ�id
    */
    byte_t m_bibFileId[37];

    /** ���������ڻ���
    */
    RCIsoDateTime m_cTime;

    /** ���ĵ�����ʱ��
    */
    RCIsoDateTime m_mTime;

    /** ��Ч����ʱ��
    */
    RCIsoDateTime m_expirationTime;

    /** ��Ч����ʱ��
    */
    RCIsoDateTime m_effectiveTime;

    /** �ļ��ṹ�汾(default 1)
    */
    byte_t m_fileStructureVersion;

    /** Ӧ�ó���ʹ�õĻ�����
    */
    byte_t m_applicationUse[512];

    /** �Ƿ���joliet
    */
    bool IsJoliet() const;
};

struct RCIsoRef
{
    /** Ŀ¼
    */
    RCIsoDir* m_dir;

    /** ����
    */
    uint32_t m_index;
};

static const uint32_t s_blockSize = 1 << 11;

class RCIsoInArchive
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCIsoInArchive() ;

public:

    /** ���ĵ�
    @param [in] stream �������ӿ�
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream, IArchiveOpenCallback* openArchiveCallback);

    /** ���
    */
    void Clear();

    /** ����
    */
    void Reset();

    /** �Ƿ���joliet
    */
    bool IsJoliet() const ;

    /** ��ȡ�������С
    @param [in] index ����
    @return �����������С
    */
    uint64_t GetBootItemSize(int32_t index) const;

public:

    /** �ĵ���С
    */
    uint64_t m_archiveSize;

    /** iso ref
    */
    RCVector<RCIsoRef> m_refs;

    /** ������
    */
    RCVector<RCIsoVolumeDescriptor> m_volDescs;

    /** ������������
    */
    int32_t m_mainVolDescIndex;

    /** ���С
    */
    uint32_t m_blockSize;

    /** �������
    */
    RCVector<RCIsoBootInitialEntry> m_bootEntries;

    /** �Ƿ���susp
    */
    bool m_isSusp;

    /** susp�����Ĵ�С
    */
    int32_t m_suspSkipSize;

private:

    /** ����
    @param [in] size �����Ĵ�С
    */
    void Skip(size_t size);

    /** ����0�ֽ�
    @param [in] size �����Ĵ�С
    */
    void SkipZeros(size_t size);

    /** ��ȡ�ֽ�
    @return ���ض�ȡ���ֽڣ����ʧ�ܷ���0xFF
    @throws �����ȡ����ʧ�����쳣
    */
    byte_t ReadByte();

    /** ��ȡ���ֽ�
    @param [out] buf ��Ŷ�ȡ����Ļ�������ַ
    @param [in]  size �������ĳ���
    @return ����ʵ�ʶ�ȡ�ĳ���
    */
    void ReadBytes(byte_t *data, uint32_t size);

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16Spec();

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16();

    /** ���ĸ��ֽ�ת��32λ�޷�������(С�ֽ���)
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32Le();

    /** ���ĸ��ֽ�ת��32λ�޷�������(���ֽ���)
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32Be();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32();

    /** ���˸��ֽ�ת��64λ�޷�������
    @return ����64λ�޷�������
    */
    uint64_t ReadUInt64();

    /** ��ȡ����
    @param [in] numDigits ����
    @retrun ��������
    */
    uint32_t ReadDigits(int32_t numDigits);

    /** ��ȡ����ʱ��
    @param [out] t ��������ʱ��
    */
    void ReadDateTime(RCIsoDateTime& d);

    /** ��ȡ��¼����ʱ��
    @param [out] t ���ؼ�¼����ʱ��
    */
    void ReadRecordingDateTime(RCIsoRecordingDateTime& t);

    /** ��ȡ·����¼
    @param [out] r ����·����¼
    @param [in] len ��ȡ�ĳ���
    */
    void ReadDirRecord2(RCIsoDirRecord &r, byte_t len);

    /** ��ȡ������¼
    @param [out] r ����������¼
    */
    void ReadDirRecord(RCIsoDirRecord &r);

    /** �����������¼��������Ϣ
    @param [out] d ����������¼��������Ϣ
    */
    void ReadBootRecordDescriptor(RCIsoBootRecordDescriptor& d);

    /** ���������
    @param [out] d ���ؾ��������Ϣ
    */
    void ReadVolumeDescriptor(RCIsoVolumeDescriptor& d);

    /** ��λ����
    @param [in] blockIndex �������
    */
    void SeekToBlock(uint32_t blockIndex);

    /** ��·��
    @param [in] d ·����Ϣ
    @param [in] level �ȼ�
    */
    void ReadDir(RCIsoDir& d, int32_t level);

    /** ����Refs
    */
    void CreateRefs(RCIsoDir &d);

    /** ��������Ϣ
    */
    void ReadBootInfo();

    /** ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult Open2();

    /** ���ǩ��
    @param [in] sig ǩ��
    @param [in] data ��������
    @return ͨ����鷵��true�����򷵻�false
    */
    static inline bool CheckSignature(const byte_t* sig, const byte_t* data);

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** ƫ��λ��
    */
    uint64_t m_position;

    /** ������
    */
    byte_t m_buffer[s_blockSize];

    /** ����ƫ��
    */
    uint32_t m_bufferPos;

    /** ��Ŀ¼
    */
    RCIsoDir m_rootDir;

    /** �����Ƿ���
    */
    bool m_bootIsDefined;

    /** ������¼������Ϣ
    */
    RCIsoBootRecordDescriptor m_bootDesc;

    /** ���ĵ��ص��ӿ�
        ��Ҫ�Ĵ�������쳣�ĳ���ʾ����
    */
    IArchiveOpenCallback* m_openArchiveCallback;

    static const byte_t s_sigCD001[5];

    static const byte_t s_sigNSR02[5];

    static const byte_t s_sigNSR03[5];

    static const byte_t s_sigBEA01[5];

    static const byte_t s_sigTEA01[5];

};

END_NAMESPACE_RCZIP

#endif //__RCIsoIn_h_
