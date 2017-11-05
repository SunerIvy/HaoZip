/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zOutArchive_h_
#define __RC7zOutArchive_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "format/7z/RC7zWriteBufferLoc.h"
#include "format/7z/RC7zEncoder.h"
#include "common/RCOutBuffer.h"
#include "common/RCBuffer.h"
#include "format/7z/RC7zItem.h"
#include "format/7z/RC7zHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RC7zHeaderOptions
{
    /** �Ƿ�ѹ����ͷ
    */
    bool m_compressMainHeader;

    /** �Ƿ�д����ʱ��
    */
    bool m_writeCTime;

    /** �Ƿ�д����ʱ��
    */
    bool m_writeATime;

    /** �Ƿ�д����ʱ��
    */
    bool m_writeMTime;

    /** Ĭ�Ϲ��캯��
    */
    RC7zHeaderOptions():
        m_compressMainHeader(true),
        m_writeCTime(false),
        m_writeATime(false),
        m_writeMTime(true)
    {
    }
};

class RC7zOutArchive:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zOutArchive() ;
    
    /** Ĭ����������
    */
    ~RC7zOutArchive() ;
    
public:

    /** ����
    @param [in] stream �����
    @param [in] endMarker �Ƿ��н������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Create(ISequentialOutStream* stream, bool endMarker) ;

    /** �ر�
    */
    void Close() ;

    /** �����ĵ�ͷ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SkipPrefixArchiveHeader() ;

    /** д��������
    @param [in] codecsInfo ���������
    @param [in] db ��������
    @param [in] options ѹ��ѡ��
    @param [in] headerOptions ͷѡ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteDatabase(ICompressCodecsInfo* codecsInfo,
                          const RC7zArchiveDatabase& db,
                          const RC7zCompressionMethodMode* options,
                          const RC7zHeaderOptions& headerOptions) ;

#ifdef _7Z_VOL

    /** ��ȡ���ͷ��С
    @param [in] dataSize ���ݴ�С
    @param [in] nameLength ���ֳ���
    @param [in] props ����
    @return ���ͷ��С
    */
    static uint32_t GetVolHeadersSize(uint64_t dataSize, int32_t nameLength = 0, bool props = false);

    /** ��ȡ������ݴ�С
    @param [in] volSize ���С
    @param [in] nameLength ���ֳ���
    @param [in] props ����
    @return ������ݴ�С
    */
    static uint64_t GetVolPureSize(uint64_t volSize, int32_t nameLength = 0, bool props = false);
#endif
  
public:

    /** ��ȡ������ӿ�
    @return �����
    */
    ISequentialOutStreamPtr GetSeqOutStream() ;
    
private:
    
    /** д������
    @param [in] data ���ݻ���
    @param [in] size ���ݴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteDirect(const void* data, uint32_t size) ;

    /** ��ȡ��ǰλ��
    @return ���ص�ǰλ��
    */
    uint64_t GetPos() const ;

    /** д����ֽ�
    @param [in] data �ֽ���ʼ��ַ
    @param [in] size �ֽڳ���
    */
    void WriteBytes(const void* data, size_t size) ;

    /** д����ֽ�
    @param [in] data д���byte buffer
    */
    void WriteBytes(const RCByteBuffer& data) ;

    /** д���ֽ�
    @param [in] b ��Ҫд����ֽ�ֵ
    */
    void WriteByte(byte_t b) ;

    /** д�ĸ��ֽ�
    @param [in] value 32λ��ֵ
    */
    void WriteUInt32(uint32_t value) ;

    /** д�˸��ֽ�
    @param [in] value 64λ��ֵ
    */
    void WriteUInt64(uint64_t value) ;

    /** д����
    @param [in] value 64λ��ֵ
    */
    void WriteNumber(uint64_t value) ;

    /** дID
    @param [in] value 64λ��ֵ
    */
    void WriteID(uint64_t value) ;

    /** д�ļ���
    @param [in] folder �ļ���
    */
    void WriteFolder(const RC7zFolder& folder) ;

    /** дbool����
    @param [in] boolVector bool����
    */
    void WriteBoolVector(const RCBoolVector& boolVector) ;

    /** дhash
    @param [in] digestsDefined �Ƿ���hashժҪ
    @param [in] hashDigests  hashժҪ
    */
    void WriteHashDigests(const RCBoolVector& digestsDefined,
                          const RCVector<uint32_t>& hashDigests) ;

    /** дѹ����Ϣ
    @param [in] dataOffset ����ƫ��
    @param [in] packSizes ѹ������С
    @param [in] packCRCsDefined �Ƿ��а���crc
    @param [in] packCRCs ����crc
    */
    void WritePackInfo(uint64_t dataOffset,
                       const RCVector<uint64_t>& packSizes,
                       const RCBoolVector& packCRCsDefined,
                       const RCVector<uint32_t>& packCRCs) ;

    /** д��ѹ��Ϣ
    @param [in] folders �ļ���
    */
    void WriteUnpackInfo(const RCVector<RC7zFolder>& folders);

    /** д����Ϣ
    @param [in] folders �ļ���
    @param [in] numUnpackStreamsInFolders �ļ������ж��ٸ�������
    @param [in] unpackSizes ��ѹ��С
    @param [in] digestsDefined �Ƿ���hashժҪ
    @param [in] hashDigests hashժҪ
    */
    void WriteSubStreamsInfo(const RCVector<RC7zFolder>& folders,
                             const RCVector<RC7zNum>& numUnpackStreamsInFolders,
                             const RCVector<uint64_t>& unpackSizes,
                             const RCBoolVector& digestsDefined,
                             const RCVector<uint32_t>& hashDigests);

    /** ��������
    @param [in] pos λ��
    @param [in] alignSize �������
    */
    void SkipAlign(uint32_t pos, uint32_t alignSize) ; 

    /**дRCBoolVector
    @param [in] v bool����
    @param [in] numDefined �����˶��ٸ�
    @param [in] type ����
    @param [in] itemSize ��Ĵ�С
    */
    void WriteAlignedBoolHeader(const RCBoolVector& v, int32_t numDefined, byte_t type, uint32_t itemSize) ;

    /** дRC7zUInt64DefVector
    @param [in] v RC7zUInt64DefVector
    @param [in] type ����
    */
    void WriteUInt64DefVector(const RC7zUInt64DefVector& v, byte_t type) ;  

    /** ѹ����
    @param [in] codecsInfo ���������
    @param [in] encoder ѹ���ӿ�
    @param [in] data ����
    @param [in] packSizes ���Ĵ�С
    @param [in] folders �ļ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult EncodeStream(ICompressCodecsInfo* codecsInfo,
                         RC7zEncoder& encoder, 
                         const RCByteBuffer& data,
                         RCVector<uint64_t>& packSizes, 
                         RCVector<RC7zFolder>& folders) ;

    /** дͷ��Ϣ
    @param [in] db ��������
    @param [in] headerOptions ͷѡ��
    @param [in] headerOffset ͷƫ��
    */
    void WriteHeader(const RC7zArchiveDatabase& db,
                     const RC7zHeaderOptions& headerOptions,
                     uint64_t& headerOffset) ;

    /** дǩ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteSignature() ; 

    /** д��ʼͷ��Ϣ
    @param [in] h ��ʼͷ��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteStartHeader(const RC7zStartHeader& h) ; 
    
#ifdef _7Z_VOL

    /** д���ǩ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteFinishSignature() ;

    /** д���ͷ
    @param [in] h ���ͷ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteFinishHeader(const RC7zFinishHeader& h) ;

#endif
  
private:

    /** д���ֽ��ֽ�
    @param [in] stream �����
    @param [in] data �ڴ�����
    @param [in] size �ڴ��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult WriteBytes(ISequentialOutStream* stream, const void* data, size_t size) ; 

    /** ��ȡ�����ݴ�С
    @param [in] value
    @return ���ش����ݴ�С
    */
    static uint32_t GetBigNumberSize(uint64_t value) ;

    /** �����޷���32λ
    @param [out] p ���ָ��
    @param [in] d 32λ����
    */
    static void SetUInt32(byte_t* p, uint32_t d) ;

    /** �����޷���64λ
    @param [in] p ���ָ��
    @param [in] d 64λ����
    */
    static void SetUInt64(byte_t* p, uint64_t d) ;
    
private:

    /** �����
    */
    ISequentialOutStreamPtr m_spSeqOutStream ;

    /** ͷƫ��
    */
    uint64_t m_prefixHeaderPos ;

    /** �Ƿ��Ǽ���ģʽ
    */
    bool m_countMode;

    /** �Ƿ�д����
    */
    bool m_writeToStream;

    /** �����С
    */
    size_t m_countSize;

    /** crc
    */
    uint32_t m_crc;

    /** ���������
    */
    RCOutBuffer m_outByte;

    /** ���������
    */
    RC7zWriteBufferLoc m_outByte2;

    /**���������
    */
    IOutStreamPtr m_spOutStream ;
    
#ifdef _7Z_VOL
    
    /** �Ƿ��н������
    */
    bool m_endMarker;

#endif
};

END_NAMESPACE_RCZIP

#endif //__RC7zOutArchive_h_
