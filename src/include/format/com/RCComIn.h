/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCComIn_h_
#define __RCComIn_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "interface/IStream.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

struct RCUInt32Buf
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCUInt32Buf();

    /** Ĭ����������
    */
    ~RCUInt32Buf();

    /** �ͷ��ڴ�
    */
    void Free();

    /** �����ڴ�
    */
    bool Allocate(uint32_t numItems);

    /** ����ȡ��ַ������
    @return ���ص�ַ
    */
    operator uint32_t *() const;

private:

    /** �ڴ�����
    */
    uint32_t* m_buf;
};

class RCComDefs
{
public:
    static const uint32_t s_free       = 0xFFFFFFFF;
    static const uint32_t s_endOfChain = 0xFFFFFFFE;
    static const uint32_t s_fatSector  = 0xFFFFFFFD;
    static const uint32_t s_matSector  = 0xFFFFFFFC;
    static const uint32_t s_maxValue   = 0xFFFFFFFA;
    static const byte_t s_empty = 0;
    static const byte_t s_storage = 1;
    static const byte_t s_stream = 2;
    static const byte_t s_lockBytes = 3;
    static const byte_t s_property = 4;
    static const byte_t s_rootStorage = 5;
    static const uint32_t s_nameSizeMax = 64;
};

struct RCComItem
{
    /** ����
    */
    byte_t m_name[RCComDefs::s_nameSizeMax];

    /** ����ʱ��
    */
    RC_FILE_TIME m_cTime;

    /** �޸�ʱ��
    */
    RC_FILE_TIME m_mTime;

    /** ��С
    */
    uint64_t m_size;

    /** ��ڵ�
    */
    uint32_t m_leftDid;

    /** �ҽڵ�
    */
    uint32_t m_rightDid;

    /** �ӽڵ�
    */
    uint32_t m_sonDid;

    /** SID
    */
    uint32_t m_sid;

    /** ����
    */
    byte_t m_type;

    /** �Ƿ��ǿ�
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEmpty() const;

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const;

    /** ����
    @param [in] p �ڴ�����
    @param [in] mode64bit �Ƿ���64λ
    */
    void Parse(const byte_t* p, bool mode64bit) ;
};

struct RCComRef
{
    /** ���ڵ�
    */
    int32_t m_parent;

    /** Did
    */
    uint32_t m_did;
};

class RCComDatabase
{
public:

    /** fat
    */
    RCUInt32Buf m_fat;

    /** fat��С
    */
    uint32_t m_fatSize;

    /** SID
    */
    RCUInt32Buf m_miniSids;

    /** �����ж��ٸ���
    */
    uint32_t m_numSectorsInMiniStream;

    /** mat
    */
    RCUInt32Buf m_mat;

    /** mat��С
    */
    uint32_t m_matSize;

    /** com��
    */
    RCVector<RCComItem> m_items;

    /** comRef
    */
    RCVector<RCComRef> m_refs;

    /** ������С��С
    */
    uint32_t m_longStreamMinSize;

    /** ����ֽڴ�С
    */
    int32_t m_sectorSizeBits;

    /** �����С�ֽڴ�С
    */
    int32_t m_miniSectorSizeBits;

public:

    /** ��ӽڵ�
    @param [in] parent ���ڵ�
    @param [in] did did
    */
    HResult AddNode(int32_t parent, uint32_t did);

    /** ��� 
    */
    void Clear();

    /** �Ƿ��Ǵ����
    @param [in] ����С
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLargeStream(uint64_t size) const ;

    /** ��ȡ��·��
    @param [in] index ����
    @return ����·��
    */
    RCString GetItemPath(uint32_t index) const;

    /** ��ȡ��İ���С
    @param [in] size ��С
    @return ���ذ���С
    */
    uint64_t GetItemPackSize(uint64_t size) const ;

    /** ��ȡMini��
    @param [in] sid SID
    @param [out] res �غ�
    @return �ɹ�����true�����򷵻�false
    */
    bool GetMiniCluster(uint32_t sid, uint64_t& res) const ;

    /** ��
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult Open(IInStream* inStream) ;
};

class RCComFuncImpl
{
public:

    /** ��ȡ����
    @param [in] inStream ������
    @param [out] buf ���ض�ȡ������
    @param [in] sectorSizeBits ������С
    @param [in] sid SID
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    static HResult ReadSector(IInStream* inStream, byte_t* buf, int32_t sectorSizeBits, uint32_t sid);

    /** ��ȡID
    @param [in] inStream ������
    @param [out] buf ���ض�ȡ������
    @param [in] sectorSizeBits ������С
    @param [in] sid SID
    @param [in] dest ����ID
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    static HResult ReadIDs(IInStream* inStream, byte_t* buf, int32_t sectorSizeBits, uint32_t sid, uint32_t* dest);

    /** ��ȡ�ļ�ʱ��
    @param [in] p �ڴ�����
    @param [out] ft �����ļ�ʱ��
    */
    static void GetFileTimeFromMem(const byte_t* p, RC_FILE_TIME* ft);

    /** ���ļ����������
    @param [in] s �ļ���
    @return ���������
    */
    static RCString CompoundNameToFileName(const RCString& s);

    /** ���ļ������Msi����
    @param [in] name �ļ���
    @param [out] resultName Msi����
    @return �ɹ�����true�����򷵻�false
    */
    static bool CompoundMsiNameToFileName(const RCString& name, RCString &resultName);

    /** ת������
    @param [in] p �ڴ�����
    @return ��������
    */
    static RCString ConvertName(const byte_t *p);

    /** �ļ�ʱ��ת����UInt64
    @param [in] tt �ļ�ʱ��
    @return ����UInt64��ʾ���ļ�ʱ��
    */
    static uint64_t RCFileTime2UInt64(const RC_FILE_TIME& tt);
};

END_NAMESPACE_RCZIP

#endif //__RCComIn_h_