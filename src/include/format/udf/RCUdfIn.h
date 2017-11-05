/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfIn_h_
#define __RCUdfIn_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "interface/IStream.h"
#include "common/RCVector.h"
#include "common/RCBuffer.h"
#include "RCUdfCDString.h"
#include "RCUdfHeader.h"
#include "RCUdfFile.h"

BEGIN_NAMESPACE_RCZIP

/** Udf Ref
*/
struct RCUdfRef
{
    /** �����
    */
    int32_t m_parent;

    /** �ļ����
    */
    int32_t m_fileIndex;
};

/** Udf �ļ�����
*/
struct RCUdfFileSet
{
    /** ʱ��
    */
    RCUdfTime m_recodringTime;

    /** root ICB
    */
    RCUdfLongAllocDesc m_rootDirICB;

    /** ref �б�
    */
    RCVector<RCUdfRef> m_refs;
};

/** Udf �߼���
*/
struct RCUdfLogVol
{
    /** ID
    */
    RCUdfCDString128 m_id;

    /** ���С
    */
    uint32_t m_blockSize;

    /** �ļ�������
    */
    RCUdfLongAllocDesc m_fileSetLocation;

    /** �������ձ�
    */
    RCVector<RCUdfPartitionMap> m_partitionMaps;

    /** �ļ���
    */
    RCVector<RCUdfFileSet> m_fileSets;

    /** ��������
    @return ��������
    */
    RCString GetName() const;
};

/** Udf Progress Virt
*/
struct RCUdfProgressVirt
{
    /** ��������
    @param [in] numBytes ���ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetTotal(uint64_t numBytes) = 0;

    /** ���������
    @param [in] numFiles ����ļ���
    @param [in] numBytes ����ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetCompleted(uint64_t numFiles, uint64_t numBytes) = 0;

    /** �������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetCompleted() = 0;
};

/** Udf ���봦��
*/
class RCUdfInArchive
{   
public:

    /** ��
    @param [in] inStream ������
    @param [in] progress �򿪽���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream *inStream, RCUdfProgressVirt *progress);

    /** ���
    */
    void Clear();

    /** ����ע��
    @return ����ע��
    */
    RCString GetComment() const;

    /** ȡ��Item·��
    @param [in] volIndex ����
    @param [in] fsIndex �ļ����
    @param [in] refIndex ref���
    @param [in] showVolName �Ƿ���ʾ����
    @param [in] showFsName �Ƿ���ʾ����
    @return ����Item·��
    */
    RCString GetItemPath(int32_t volIndex, 
                         int32_t fsIndex, 
                         int32_t refIndex, 
                         bool showVolName, 
                         bool showFsName) const;

    /** ���Item Extent
    @param [in] volIndex ����
    @param [in] item ����Ϣ
    @return ��ȷ����true,���򷵻�false
    */
    bool CheckItemExtents(int32_t volIndex, const RCUdfItem &item) const;

public:

    /** �����б�
    */
    RCVector<RCUdfPartition> m_partitions;

    /** �߼����б�
    */
    RCVector<RCUdfLogVol> m_logVols;

    /** �ļ����б�
    */
    RCVector<RCUdfItemPtr> m_items;

    /** �ļ��б�
    */
    RCVector<RCUdfFile> m_files;

    /** �߼�������
    */
    int32_t m_secLogSize;

private:

    /** ��ȡ����
    @param [in] volIndex ����
    @param [in] partitionRef ������
    @param [in] blockPos ��λ��
    @param [in] len ����
    @param [in] buf ����ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Read(int32_t volIndex, int32_t partitionRef, uint32_t blockPos, uint32_t len, byte_t *buf);

    /** ��ȡ����
    @param [in] volIndex ����
    @param [in] lad ����
    @param [in] buf ����ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Read(int32_t volIndex, const RCUdfLongAllocDesc &lad, byte_t *buf);

    /** �ļ���ȡ
    @param [in] volIndex ����
    @param [in] item �ļ���
    @param [in] buf ����ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadFromFile(int32_t volIndex, const RCUdfItem &item, RCByteBuffer &buf);

    /** �ļ����ȡ
    @param [in] volIndex ����
    @param [in] fsIndex fs���
    @param [in] lad ����
    @param [in] numRecurseAllowed ����ĵݹ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadFileItem(int32_t volIndex, int32_t fsIndex, const RCUdfLongAllocDesc &lad, int32_t numRecurseAllowed);

    /** ��ȡ��
    @param [in] volIndex ����
    @param [in] fsIndex fs���
    @param [in] lad ����
    @param [in] numRecurseAllowed ����ĵݹ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadItem(int32_t volIndex, int32_t fsIndex, const RCUdfLongAllocDesc &lad, int32_t numRecurseAllowed);

    /** ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open2();

    /** ��ȡ�ļ�Ref 
    @param [in] fs
    @param [in] fileIndex �ļ����
    @param [in] parent �����
    @param [in] numRecurseAllowed ����ĵݹ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FillRefs(RCUdfFileSet &fs, int32_t fileIndex, int32_t parent, int32_t numRecurseAllowed);

    /** ���Extent
    @param [in] volIndex ����
    @param [in] partitionRef  ����Ref
    @param [in] blockPos ��λ��
    @param [in] len ����
    @return �ɹ�����true,���򷵻�false
    */
    bool CheckExtent(int32_t volIndex, int32_t partitionRef, uint32_t blockPos, uint32_t len) const;

    /** ��������
    @param [out] res �ַ���
    @param [in] addString �����ַ���
    */
    static void UpdateWithName(RCString &res, const RCString &addString);

    /** ȡ��Spec����
    @param [in] name ����
    @return ����Spec����
    */
    static RCString GetSpecName(const RCString &name);

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** ���Ȼص��ӿ�
    */
    RCUdfProgressVirt* m_progress;

    /** �Ѿ������ֽ�
    */
    uint64_t m_processedProgressBytes;

    /** �ļ�������
    */
    uint64_t m_fileNameLengthTotal;

    /** Ref����
    */
    int32_t m_numRefs;

    /** Extent����
    */
    uint32_t m_numExtents;

    /** Extent ����
    */
    uint64_t m_inlineExtentsSize;
};

END_NAMESPACE_RCZIP

#endif //__RCUdfIn_h_