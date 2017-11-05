/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfFile_h_
#define __RCUdfFile_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "common/RCVector.h"
#include "RCUdfCDString.h"
#include "RCUdfHeader.h"
#include "RCUdfCrc16.h"

BEGIN_NAMESPACE_RCZIP

/** Udf �ļ�
*/
struct RCUdfFile
{
    /** ID
    */
    RCUdfCDString m_id;

    /** �ļ����
    */
    int32_t m_itemIndex;

    /** Ĭ�Ϲ��캯��
    */
    RCUdfFile();

    /** �����ļ���
    */
    RCString GetName() const;
};

/** Udf My Extent 
*/
struct RCUdfMyExtent
{
    /** λ��
    */
    uint32_t m_pos;

    /** ����
    */
    uint32_t m_len;

    /** ����
    */
    int32_t m_partitionRef;

    /** ���س���
    @return ���س���
    */
    uint32_t GetLen() const;

    /** ��������
    @return ��������
    */
    uint32_t GetType() const;

    /** �Ƿ�ΪRec
    @return Rec����true,���򷵻�false
    */
    bool IsRecAndAlloc() const;
};

/** Udf ��
*/
struct RCUdfItem
{
    /** icb Tag
    */
    RCUdfIcbTag m_icbTag;

    /** ��С
    */
    uint64_t m_size;

    /** ���¼
    */
    uint64_t m_numLogBlockRecorded;

    /** ����ʱ��
    */
    RCUdfTime m_aTime;

    /** �޸�ʱ��
    */
    RCUdfTime m_mTime;

    /** �Ƿ�����
    */
    bool m_isInline;

    /** ���ݻ���
    */
    RCByteBuffer m_inlineData;

    /** extent �б�
    */
    RCVector<RCUdfMyExtent> m_extents;

    /** sub File �б�
    */
    RCVector<int32_t> m_subFiles;

    /** ����
    @param [in] buf ���ݻ���
    */
    void Parse(const byte_t *buf);

    /** �Ƿ�ΪRec
    @return Rec����true,���򷵻�false
    */
    bool IsRecAndAlloc() const;

    /** ����Chunk�ܴ�С
    @return ����Chunk�ܴ�С
    */
    uint64_t GetChunksSumSize() const;

    /** ���Chunk��С
    @return ��ȷ����true,���򷵻�false
    */
    bool CheckChunkSizes() const;

    /** �Ƿ���Ŀ¼
    @return Ŀ¼����true,���򷵻�false
    */
    bool IsDir() const;
};

typedef RCSharedPtr<RCUdfItem> RCUdfItemPtr;

/** Udf Tag
*/
struct RCUdfTag
{
    /** ID
    */
    uint16_t m_id;

    /** �汾
    */
    uint16_t m_version;

    /** ����
    @param [in] buf ���ݻ���
    @param [in] size ���ݴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Parse(const byte_t *buf, size_t size);
};

/** Udf File ID
*/
struct RCUdfFileId
{
    /** �ļ�����
    */
    byte_t m_fileCharacteristics;

    /** ID
    */
    RCUdfCDString m_id;

    /** ICB
    */
    RCUdfLongAllocDesc m_icb;

    /** �Ƿ���
    @return ��������true,���򷵻�false
    */
    bool IsItLinkParent() const;

    /**
    @param [in] p ���ݻ���
    @param [in] size ���ݴ�С
    @param [out] processed �����ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Parse(const byte_t *p, size_t size, size_t &processed);
};

/** Udf Extent
*/
struct RCUdfExtent
{
    /** ����
    */
    uint32_t m_len;

    /** λ��
    */
    uint32_t m_pos;

    /** ����
    @param [in] buf ���ݻ���
    */
    void Parse(const byte_t *buf);
};

END_NAMESPACE_RCZIP

#endif //__RCUdfFile_h_
