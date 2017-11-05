/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipOut_h_
#define __RCZipOut_h_ 1

#include "base/RCDefs.h"
#include "interface/IStream.h"
#include "common/RCOutBuffer.h"
#include "RCZipItem.h"

BEGIN_NAMESPACE_RCZIP

class RCZipOut
{
public:

    /** Ĭ����������
    */
    ~RCZipOut();

public:

    /** ������
    @param [in] outStream �����
    */
    void Create(IOutStream* outStream) ;

    /** �ƶ���ʼλ��
    @param [in] distanceToMove �ƶ���С
    */
    void MoveBasePosition(uint64_t distanceToMove) ;

    /** ��ȡ��ǰλ��
    @return ���ص�ǰλ��
    */
    uint64_t GetCurrentPosition() const;

    /** ׼��дzip64��ѹ������
    @param [in] fileNameLength �ļ�������
    @param [in] isZip64 �Ƿ���zip64
    @param [in] aesEncryption �Ƿ���aes����
    */
    void PrepareWriteCompressedDataZip64(uint16_t fileNameLength, 
                                         bool isZip64,
                                         bool aesEncryption) ;

    /** ׼��дѹ������
    @param [in] fileNameLength �ļ�������
    @param [in] unPackSize ��ѹ��С
    @param [in] aesEncryption �Ƿ���aes����
    */    
    void PrepareWriteCompressedData(uint16_t fileNameLength,
                                    uint64_t unPackSize,
                                    bool aesEncryption) ;

    /** ׼��дѹ������
    @param [in] fileNameLength �ļ�������
    @param [in] unPackSize ��ѹ��С
    @param [in] packSize ѹ����С
    @param [in] aesEncryption �Ƿ���aes����
    */
    void PrepareWriteCompressedData2(uint16_t fileNameLength,
                                     uint64_t unPackSize,
                                     uint64_t packSize,
                                     bool aesEncryption) ;

    /** д����ͷ
    @param [in] item item��Ϣ
    */
    void WriteLocalHeader(RCZipItem& item) ;

    /** д��Ŀ¼
    @param [in] items item ��Ϣ
    @param [in] comment ע����Ϣ
    */
    void WriteCentralDir(const RCVector<RCZipItemPtr>& items, 
                         const RCByteBuffer& comment) ;

    /** Ϊѹ��������
    @param [in] outStream �����
    */
    void CreateStreamForCompressing(IOutStream** outStream) ;

    /** Ϊ����������
    @param [in] outStream �����
    */  
    void CreateStreamForCopying(ISequentialOutStream** outStream) ;

    /** ��λ��������ʼλ��
    */
    void SeekToPackedDataPosition() ;

    /** �޸ķ־���(�����zip�־���Ϊ����)
    */
    void WriteSignleVolumeSignature();

private:

    /** д�ֽ�
    @param [in] buffer �ڴ�
    @param [in] size ��С
    */
    void WriteBytes(const void* buffer, uint32_t size) ;

    /** дһ���ֽ�
    @param [in] b �ֽ�
    */
    void WriteByte(byte_t b) ;

    /** д�����ֽ�
    @param [in] value 32λ��ֵ
    */
    void WriteUInt16(uint16_t value) ;

    /** д�ĸ��ֽ�
    @param [in] value 32λ��ֵ
    */
    void WriteUInt32(uint32_t value) ;

    /** д�˸��ֽ�
    @param [in] value 64λ��ֵ
    */
    void WriteUInt64(uint64_t value) ;

    /** д��ͷ
    @param [in] item item��Ϣ
    */
    void WriteCentralHeader(const RCZipItemPtr& item) ;

    /** д��չ��Ϣ
    @param [in] extra ��չ��Ϣ
    */
    void WriteExtra(const RCZipExtraBlock& extra) ;

    /** ��λ
    @param [in] offset ƫ��
    */
    void SeekTo(uint64_t offset) ;

    /** ��ȡ��ͷд����̵Ĵ�С
    @param [in] item item��Ϣ
    */
    uint64_t GetCentralHeaderSize(const RCZipItemPtr& item);

private:

    /** �����
    */
    IOutStreamPtr m_stream ;

    /** �����С
    */
    RCOutBuffer m_outBuffer ;

    /** ��ʼλ��
    */
    uint64_t m_basePosition ;

    /** �����ļ�ͷ��С
    */
    uint32_t m_localFileHeaderSize ;

    /** ��չ��С
    */
    uint32_t m_extraSize ;

    /** �Ƿ���zip64
    */
    bool m_isZip64 ;

    /** �Ƿ�����zip�־�
    */
    bool m_isSplit;

    /** �־�����������ӿ�
    */
    IMultiVolStreamPtr m_multiVolStream;
};

END_NAMESPACE_RCZIP

#endif //__RCZipOut_h_
