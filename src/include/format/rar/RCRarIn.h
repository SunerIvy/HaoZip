/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarIn_h_
#define __RCRarIn_h_ 1

#include "RCRarHeader.h"
#include "RCRarItem.h"
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/IPassword.h"
#include "common/RCBuffer.h"
#include "crypto/RarAES/RCRarAESDecoder.h"

BEGIN_NAMESPACE_RCZIP

class RCRarInArchiveInfo
{
public:

    /** ��ʼλ��
    */
    uint64_t m_startPosition;

    /** ���
    */
    uint16_t m_flags;

    /** ע��λ��
    */
    uint64_t m_commentPosition;

    /** ע�ʹ�С
    */
    uint16_t m_commentSize;

    /** ע��
    */
    RCString m_comment;

public:

    /** �Ƿ��ǹ�ʵѹ��
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSolid() const
    {
        return (m_flags & RCRarHeader::NArchive::kSolid) != 0;
    }

    /** �Ƿ���ע��
    @return �з���true�����򷵻�false
    */
    bool IsCommented() const
    {
        //return (Flags & RCRarHeader::NArchive::kComment) != 0;
        return !m_comment.empty();
    }

    /** �Ƿ��Ƿ־�
    @return �Ƿ���true�����򷵻�false
    */
    bool IsVolume() const
    {
        return (m_flags & RCRarHeader::NArchive::kVolume) != 0;
    }

    /** �Ƿ����·־���
    @return �Ƿ���true�����򷵻�false
    */
    bool HaveNewVolumeName() const
    {
        return (m_flags & RCRarHeader::NArchive::kNewVolName) != 0;
    }

    /** �Ƿ��Ǽ���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEncrypted() const
    {
        return (m_flags & RCRarHeader::NArchive::kBlockEncryption) != 0;
    }
};

class RCRarIn
{
public:

    /** ���ĵ�
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream, const uint64_t* searchHeaderSizeLimit, IArchiveOpenCallback* openArchiveCallback = 0);

    /** �ر�
    */
    void Close();

    /** ��ȡ��һ��
    @param [in] codecsInfo ���������
    @param [in] item ��
    @param [in] getTextPassword ���������
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @param [out] decryptionError �Ƿ���ܴ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult GetNextItem(ICompressCodecsInfo* codecsInfo,
                        RCRarItemExPtr& item,
                        ICryptoGetTextPassword* getTextPassword,
                        IArchiveOpenCallback* openArchiveCallback,
                        bool& decryptionError);

    /** �����ĵ�ע��
    */
    void SkipArchiveComment();

    /** ��ȡ�ĵ���Ϣ
    @param [out] archiveInfo �ĵ���Ϣ  
    */
    void GetArchiveInfo(RCRarInArchiveInfo &archiveInfo) const;

    /** ���ĵ��ж�λ
    @param [in] position λ��
    @return �ɹ�����true�����򷵻�false
    */
    bool SeekInArchive(uint64_t position);

    /** ������������
    @param [in] position λ��
    @param [in] size ��С
    @return �����
    */
    ISequentialInStream* CreateLimitedStream(uint64_t position, uint64_t size);

protected:

    /** ��һ���ֽ�
    @return ����һ���ֽ�
    */
    byte_t ReadByte();

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32();

    /** ��ʱ��
    @param [in] mask ����
    @param [out] rarTime ����ʱ��
    */
    void ReadTime(byte_t mask, RCRarTime& rarTime);

    /** ��ɼ��ܿ�
    */
    void FinishCryptoBlock()
    {
        if (m_cryptoMode)
        {
            while ((m_cryptoPos & 0xF) != 0)
            {
                m_cryptoPos++;
                m_position++;
            }
        }
    }

protected:

    /** �ļ�ͷ������
    */
    RCByteBuffer m_fileHeaderData;

    /** �ļ�ͷ����
    */
    RCRarHeader::NBlock::CBlock m_blockHeader;

    /** rarAES������
    */
    RCRarAESDecoder* m_rarAESSpec;

    /** rarAES������
    */
    ICompressFilterPtr m_rarAES;

    /** ��ǰ����(it must point to start of Rar::Block)
    */
    byte_t* m_curData;

    /** ��ǰλ��
    */
    uint32_t m_curPos;

    /** ���λ��
    */
    uint32_t m_posLimit;

    /** ��������
    */
    RCBuffer<byte_t> m_decryptedData;

    /** �������ݴ�С
    */
    uint32_t m_decryptedDataSize;

    /** �Ƿ��Ǽ���ģʽ
    */
    bool m_cryptoMode;

    /** ����λ��
    */
    uint32_t m_cryptoPos;

private:

    /** ������
    @param [in] item ����Ϣ
    @param [in] nameSize ���ִ�С
    */
    void ReadName(RCRarItemExPtr& item, int nameSize);

    /** ����ʵͷ
    @param [in] item ����Ϣ
    */
    void ReadHeaderReal(RCRarItemExPtr& item);

    /** ���ֽ�
    @param [out] data ���ض�ȡ������
    @param [in] size ��ȡ�Ĵ�С
    @param [in] aProcessedSize ����ʵ�ʶ����Ĵ�С
    */
    HResult ReadBytes(void* data, uint32_t size, uint32_t* aProcessedSize);

    /** ���ֽڲ�����Ƿ����ָ����С
    @param [out] data ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    @return �ɹ�����true�����򷵻�false
    */
    bool ReadBytesAndTestSize(void* data, uint32_t size);

    /** ���ֽڲ�����Ƿ���ȷ
    @param [out] data ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    */
    void ReadBytesAndTestResult(void* data, uint32_t size);

    /** ���Ҳ���ȡ��־
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ҷ�Χ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FindAndReadMarker(IInStream* stream, const uint64_t* searchHeaderSizeLimit);

    /** ���ĵ�
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ļ���ʽǩ�������ƫ��λ��
    @param [in] openArchiveCallback ���ĵ��ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open2(IInStream* stream, const uint64_t* searchHeaderSizeLimit, IArchiveOpenCallback* openArchiveCallback);

    /** ��Ӷ�λֵ
    @param [in] addValue ��ӵ�ֵ
    */
    void AddToSeekValue(uint64_t addValue);

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** ��������ʼλ��
    */
    uint64_t m_streamStartPosition;

    /** λ��
    */
    uint64_t m_position;

    /** �ĵ�����ʼλ��
    */
    uint64_t m_archiveStartPosition;

    /** �ĵ�ͷ
    */
    RCRarHeader::NArchive::CHeader360 m_archiveHeader;

    /** ����
    */
    RCCharBuffer m_nameBuffer;

    /** unicode����
    */
    RCBuffer<char_t> m_unicodeNameBuffer;

    /** �Ƿ�λ�ĵ��е�ע��
    */
    bool m_seekOnArchiveComment;

    /** �ĵ��е�ע��λ��
    */
    uint64_t m_archiveCommentPosition;
};

END_NAMESPACE_RCZIP

#endif //__RCRarIn_h_
