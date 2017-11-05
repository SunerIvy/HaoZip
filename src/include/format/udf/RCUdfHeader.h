/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfHeader_h_
#define __RCUdfHeader_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "RCUdfMap32.h"

#ifdef RCZIP_OS_WIN
#define CHAR_PATH_SEPARATOR '\\'
#define WCHAR_PATH_SEPARATOR L'\\'
#define WSTRING_PATH_SEPARATOR L"\\"
#else
#define CHAR_PATH_SEPARATOR '/'
#define WCHAR_PATH_SEPARATOR L'/'
#define WSTRING_PATH_SEPARATOR L"/"
#endif

BEGIN_NAMESPACE_RCZIP

/** Udf ��������
*/
class RCUdfDefs
{
public:
    enum EShortAllocDescType
    {
        SHORT_ALLOC_DESC_TYPE_RECORDED_AND_ALLOCATED = 0,
        SHORT_ALLOC_DESC_TYPE_NOT_RECORDED_BUT_ALLOCATED = 1,
        SHORT_ALLOC_DESC_TYPE_NOT_RECORDED_AND_NOT_ALLOCATED = 2,
        SHORT_ALLOC_DESC_TYPE_NEXT_EXTENT = 3
    };

    enum EIcbFileType
    {
        ICB_FILE_TYPE_DIR = 4,
        ICB_FILE_TYPE_FILE = 5
    };

    enum EIcbDescriptorType
    {
        ICB_DESC_TYPE_SHORT = 0,
        ICB_DESC_TYPE_LONG = 1,
        ICB_DESC_TYPE_EXTENDED = 2,
        ICB_DESC_TYPE_INLINE = 3
    };

    enum EDescriptorType
    {
        DESC_TYPE_SPOARING_TABLE = 0, // UDF
        DESC_TYPE_PRIM_VOL = 1,
        DESC_TYPE_ANCHOR_VOL_PTR = 2,
        DESC_TYPE_VOL_PTR = 3,
        DESC_TYPE_IMPL_USE_VOL = 4,
        DESC_TYPE_PARTITION = 5,
        DESC_TYPE_LOGICAL_VOL = 6,
        DESC_TYPE_UNALLOC_SPACE = 7,
        DESC_TYPE_TERMINATING = 8,
        DESC_TYPE_LOGICAL_VOL_INTEGRITY = 9,
        DESC_TYPE_FILESET = 256,
        DESC_TYPE_FILEID  = 257,
        DESC_TYPE_ALLOCATION_EXTENT = 258,
        DESC_TYPE_INDIRECT = 259,
        DESC_TYPE_TERMINAL = 260,
        DESC_TYPE_FILE = 261,
        DESC_TYPE_EXTENDED_ATTR_HEADER = 262,
        DESC_TYPE_UNALLOCATED_SPACE = 263,
        DESC_TYPE_SPACE_BITMAP = 264,
        DESC_TYPE_PARTITION_INTEGRITY = 265,
        DESC_TYPE_EXTENDED_FILE = 266,
    };

    static const int32_t s_numPartitionsMax = 64;
    static const int32_t s_numLogVolumesMax = 64;
    static const int32_t s_numRecureseLevelsMax = 1 << 10;
    static const int32_t s_numItemsMax = 1 << 27;
    static const int32_t s_numFilesMax = 1 << 28;
    static const int32_t s_numRefsMax = 1 << 28;
    static const uint32_t s_numExtentsMax = (uint32_t)1 << 30;
    static const uint64_t s_fileNameLengthTotalMax = (uint64_t)1 << 33;
    static const uint64_t s_inlineExtentsSizeMax = (uint64_t)1 << 33;
    static const byte_t s_fileidCharacsParent = (1 << 3);
};

/** Udf Time
*/
struct RCUdfTime
{
    /** ����
    */
    byte_t m_data[12];

    /** ����ʱ������
    */
    unsigned GetType() const;

    /** �Ƿ�Ϊ����ʱ��
    @return ���ط���true,���򷵻�false
    */
    bool IsLocal() const;

    /** ���ط���
    @return ���ط���ƫ��
    */
    int32_t GetMinutesOffset() const;

    /** ������
    @return �������
    */
    unsigned GetYear() const;

    /** ����
    @param [in] buf ����
    */
    void Parse(const byte_t *buf);
};

/** Udf ����
*/
struct RCUdfPartition
{
    /** ��ֵ
    */
    uint16_t m_number;

    /** λ��
    */
    uint32_t m_pos;

    /** ����
    */
    uint32_t m_len;

    /** ����
    */
    int32_t m_volIndex;

    /** ���ձ�
    */
    RCUdfMap32Ptr m_map;

    /** ���캯��
    */
    RCUdfPartition();

    /** �������캯��
    @param [in] ����ԭ��
    */
    RCUdfPartition(const RCUdfPartition& val);

    /** =����������
    */
    RCUdfPartition& operator=(const RCUdfPartition& val);
};

/** Udf �߼����ַ
*/
struct RCUdfLogBlockAddr
{
    /** λ��
    */
    uint32_t m_pos;

    /** ����
    */
    uint16_t m_partitionRef;

    /** ����
    @param [in] buf ����
    */
    void Parse(const byte_t *buf);
};

/** Udf ������
*/
struct RCUdfShortAllocDesc
{
    /** ����
    */
    uint32_t m_len;

    /** λ��
    */
    uint32_t m_pos;

    /** ����
    @param [in] buf ����
    */
    void Parse(const byte_t *buf);
};

/** Udf ������
*/
struct RCUdfLongAllocDesc
{
    /** ����
    */
    uint32_t m_len;

    /** ��ַ
    */
    RCUdfLogBlockAddr m_location;

    /** ���س���
    @return ���س���
    */
    uint32_t GetLen() const;

    /** ��������
    @return ��������
    */
    uint32_t GetType() const;

    /** �����Ƿ�ΪRec
    @return Rec����true,���򷵻�false
    */
    bool IsRecAndAlloc() const;

    /** ����
    @param [in] buf ����
    */
    void Parse(const byte_t *buf);
};

/** Udf �������ձ�
*/
struct RCUdfPartitionMap
{
    /** ����
    */
    byte_t m_type;

    /** ������
    */
    uint16_t m_partitionNumber;

    /** �������
    */
    int32_t m_partitionIndex;
};

/** Udf Icb Tag
*/
struct RCUdfIcbTag
{
    /** �ļ�����
    */
    byte_t m_fileType;

    /** ��־
    */
    uint16_t m_flags;

    /** �Ƿ�Ŀ¼
    @return Ŀ¼����true,���򷵻�false
    */
    bool IsDir() const;

    /** ������������
    @return ������������
    */
    int32_t GetDescriptorType() const;

    /** ����
    @param [in] p ����
    */
    void Parse(const byte_t *p);
};

END_NAMESPACE_RCZIP

#endif //__RCUdfHeader_h_
