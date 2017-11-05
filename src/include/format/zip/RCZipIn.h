/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipIn_h_
#define __RCZipIn_h_ 1

#include "base/RCDefs.h"
#include "common/RCBuffer.h"
#include "common/RCInBuffer.h"
#include "interface/IStream.h"
#include "base/RCString.h"
#include "RCZipItem.h"

BEGIN_NAMESPACE_RCZIP

namespace RCZipInException
{
    /** RCZipIn�е��쳣����
    */
    enum RCZipInExceptionType
    {
        kUnexpectedEndOfArchive = 0,

        kArchiceHeaderCRCError,

        kFileHeaderCRCError,

        kIncorrectArchive,

        kMultiVolumeArchiveAreNotSupported,

        kReadStreamError,

        kSeekStreamError
    };
}

class RCZipInArchiveInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipInArchiveInfo():
      m_base(0),
      m_startPosition(0),
      m_commentSizePosition(0) 
    {}

public:

    /** ���
    */
    void Clear()
    {
        m_base = 0;
        m_startPosition = 0;
        m_commentSizePosition = 0;
        m_comment.SetCapacity(0) ;
    }

public:

    /** ����ַ
    */
    uint64_t m_base ;

    /** ��ʼλ��
    */
    uint64_t m_startPosition ;

    /** ע�ʹ�Сλ��
    */
    uint64_t m_commentSizePosition ;

    /** ע��
    */
    RCByteBuffer m_comment ;
};

class RCZipProgressVirt
{
public:

    /** ��������
    @param [in] numFiles �ļ���
    */
    virtual HResult SetTotal(uint64_t numFiles) = 0 ;

    /** ���������
    @param [in] numFiles �ļ���
    */
    virtual HResult SetCompleted(uint64_t numFiles) = 0 ;
};

struct RCZipCdInfo
{
    /** ��С
    */
    uint64_t m_size ;

    /** ƫ��
    */
    uint64_t m_offset ;
};

class RCZipIn
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipIn() ;
    
private:

    /** ������
    */
    IInStreamPtr m_stream ;

    /** ǩ��
    */
    uint32_t m_signature ;

    /** ����ʼλ��
    */
    uint64_t m_streamStartPosition ;

    /** λ��
    */
    uint64_t m_position ;

    /** ��������
    */
    bool m_inBufMode ;

    /** ����
    */
    RCInBuffer m_inBuffer ;

public:

    /** ��λ
    @param [in] offset �ļ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Seek(uint64_t offset) ;

    /** ���Ҳ���ȡ��־
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ҷ�Χ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FindAndReadMarker(IInStream* stream, const uint64_t* searchHeaderSizeLimit) ;

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @param [out] value ���ض�ȡ��ֵ
    @return �ɹ�����true�����򷵻�false
    */
    bool ReadUInt32(uint32_t& value) ;

    /** ���ļ���
    @param [in] nameSize ���ֳ���
    @param [out] dest �����ļ���
    */
    void ReadFileName(uint32_t nameSize, RCStringA& dest) ;

    /** ���ֽ�
    @param [out] data ���ض�ȡ������
    @param [in] size ��ȡ�Ĵ�С
    @param [out] processedSize ����ʵ�ʶ����Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadBytes(void* data, uint32_t size, uint32_t* processedSize) ;

    /** ���ֽڲ�����Ƿ����ָ����С
    @param [out] data ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    bool ReadBytesAndTestSize(void* data, uint32_t size) ;

    /** ��ȫ���ֽ�
    @param [out] data ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    */
    void SafeReadBytes(void* data, uint32_t size) ;

    /** ���ڴ�
    @param [out] buffer ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    */
    void ReadBuffer(RCByteBuffer& buffer, uint32_t size) ;

    /** ��һ���ֽ�
    @return ����һ���ֽ�
    */
    byte_t ReadByte() ;

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16() ;

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32() ;

    /** ���˸��ֽ�ת��64λ�޷�������
    @return ����64λ�޷�������
    */
    uint64_t ReadUInt64() ;

    /** ����
    @param [in] num �����ĸ���
    */
    void Skip(uint64_t num) ;

    /** ����ƶ��ļ�ָ���λ��
    @param [in] addValue �ƶ��Ĵ�С
    */
    void IncreaseRealPosition(uint64_t addValue) ;

    /** ����չ��Ϣ
    @param [in] ��չ��С
    @param [out] extraBlock ������չ��
    @param [out] unpackSize ���ؽ�ѹ��С
    @param [out] packSize ����ѹ����С
    @param [out] localHeaderOffset ����ͷƫ��
    @param [out] diskStartNumber ���ش�����ʼ��
    */
    void ReadExtra(uint32_t extraSize,
                   RCZipExtraBlock& extraBlock,
                   uint64_t& unpackSize,
                   uint64_t& packSize,
                   uint64_t& localHeaderOffset,
                   uint32_t& diskStartNumber) ;

    /** ��ȡ����item
    @param [out] item ����zip item��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadLocalItem(RCZipItemEx& item) ;

    /** ��ȡ����item����
    @param [out] item ����zip item��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadLocalItemDescriptor(RCZipItemExPtr& item) ;

    /** ��ȡcd item
    @param [out] item ����zip item��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadCdItem(RCZipItemEx& item) ;

    /** ���Զ�ȡecd64
    @param [in] offset ƫ��
    @param [out] cdInfo ����cd��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult TryEcd64(uint64_t offset, RCZipCdInfo& cdInfo) ;

    /** ����cd
    @param [out] cdInfo ����cd��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FindCd(RCZipCdInfo& cdInfo) ;

    /** ���Զ�ȡcd
    @param [out] items ����zip items��Ϣ
    @param [out] cdOffset ����cdƫ��
    @param [out] cdSize ����cd��С
    @param [in] progress ���ȹ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult TryReadCd(RCVector <RCZipItemExPtr>& items,
                      uint64_t cdOffset,
                      uint64_t cdSize,
                      RCZipProgressVirt* progress) ;

    /** ��ȡcd
    @param [out] items ����zip items��Ϣ
    @param [out] cdOffset ����cdƫ��
    @param [out] cdSize ����cd��С
    @param [in] progress ���ȹ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadCd(RCVector<RCZipItemExPtr>& items,
                   uint64_t& cdOffset,
                   uint64_t& cdSize,
                   RCZipProgressVirt* progress) ;

    /** ��ȡ���غ�cd
    @param [out] items ����zip items��Ϣ
    @param [in] progress ���ȹ�����
    @param [out] cdOffset ����cdƫ��
    @param [out] numCdItems ����cd����
    @return �ɹ�����RC_S_OK�����򷵻ش����
   */
    HResult ReadLocalsAndCd(RCVector<RCZipItemExPtr>& items,
                            RCZipProgressVirt* progress,
                            uint64_t& cdOffset,
                            int32_t& numCdItems) ;

public:

    /** zip�ĵ���Ϣ
    */
    RCZipInArchiveInfo m_archiveInfo ;

    /** �Ƿ���zip64
    */
    bool m_isZip64 ;

    /** �Ƿ���ͷ��Ϣ
    */
    bool m_isOkHeaders ;

public:

    /** ��ȡͷ��Ϣ
    @param [out] items ����zip items��Ϣ
    @param [in] progress ���ȹ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadHeaders(RCVector<RCZipItemExPtr>& items, RCZipProgressVirt* progress) ;

    /** ��ȡcd item���item
    @param [out] items ����zip items��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadLocalItemAfterCdItem(RCZipItemEx& item) ;

    /** ��ȡ����cd item���item
    @param [out] items ����zip items��Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadLocalItemAfterCdItemFull(RCZipItemEx& item) ;

    /** ��
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ҷ�Χ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* stream, const uint64_t* searchHeaderSizeLimit) ;

    /** �ر�
    */
    void Close() ;

    /** �õ��ĵ���Ϣ
    @param [out] archiveInfo �����ĵ���Ϣ
    */
    void GetArchiveInfo(RCZipInArchiveInfo& archiveInfo) const;

    /** ���ĵ��ж�λ
    @param [in] position λ��
    @return �ɹ�����true�����򷵻�false
    */
    bool SeekInArchive(uint64_t position) ;

    /** ���������
    @param [in] position λ��
    @param [in] size ��С
    @return �������ӿ�
    */
    ISequentialInStream* CreateLimitedStream(uint64_t position, uint64_t size) ;

    /** ������
    @return �������ӿ�
    */
    IInStream* CreateStream() ;

    /** �Ƿ����
    @return �򿪷���true�����򷵻�false
    */
    bool IsOpen() const
    { 
        return m_stream != NULL;
    }
};

/** RCZipIn����ָ��
*/
typedef RCSharedPtr<RCZipIn> RCZipInPtr ;

END_NAMESPACE_RCZIP

#endif //__RCZipIn_h_
