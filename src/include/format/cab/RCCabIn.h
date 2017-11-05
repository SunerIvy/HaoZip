/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabIn_h_
#define __RCCabIn_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCVector.h"
#include "common/RCInBuffer.h"
#include "format/cab/RCCabHeader.h"
#include "format/cab/RCCabItem.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

struct RCCabOtherArchive
{
    /** �ļ���
    */
    RCStringA m_fileName;

    /** ������
    */
    RCStringA m_diskName;
};

struct RCCabArchiveFileInfo
{
    /** �ΰ汾��
    */
    byte_t  m_versionMinor;

    /** ���汾��
    */
    byte_t  m_versionMajor;

    /** �ļ�����
    */
    uint16_t m_numFolders;

    /** �ļ���
    */
    uint16_t  m_numFiles;

    /** ��־
    */
    uint16_t  m_flags;

    /** ����ID
    */
    uint16_t  m_setID;

    /** �ڲ�����
    */
    uint16_t  m_cabinetNumber;

    /** ǰһ���ڲ��������С
    */
    uint16_t m_perCabinetAreaSize;

    /** ǰһ���ļ��������С
    */
    byte_t m_perFolderAreaSize;

    /** ǰһ�����ݿ������С
    */
    byte_t m_perDataBlockAreaSize;

    /** ǰһ���ĵ�
    */
    RCCabOtherArchive m_prevArc;

    /** ��һ���ĵ�
    */
    RCCabOtherArchive m_nextArc;

    /** �Ƿ�����
    @return �Ƿ���true�����򷵻�false
    */
    bool ReserveBlockPresent() const ;

    /** �Ƿ���ǰһ���ڲ���
    @return �з���true�����򷵻�false
    */
    bool IsTherePrev() const ;

    /** �Ƿ�����һ���ڲ���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsThereNext() const ;

    /** ��ȡ���ݿ鱣����С
    @return �������ݿ鱣����С
    */
    byte_t GetDataBlockReserveSize() const ;

    /** Ĭ�Ϲ��캯��
    */
    RCCabArchiveFileInfo();

    /** ���
    */
    void Clear();
};

struct RCCabInArchiveInfo : 
    public RCCabArchiveFileInfo
{
    /** ��С
    */
    uint32_t m_size;

    /** �ļ�ͷ��ƫ��
    */
    uint32_t m_fileHeadersOffset;
};

class RCCabDatabase
{
public:

    /** ���
    */
    void Clear();

    /** �Ƿ���ǰһ���ļ���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsTherePrevFolder() const;

    /** ��ȡ���ļ��ı��
    @return �������ļ��ı��
    */
    int32_t GetNumberOfNewFolders() const;

    /** ��ȡ�ļ�ƫ��
    @return �����ļ�ƫ��
    */
    uint32_t GetFileOffset(int32_t index) const ;

    /** ��ȡ�ļ���С
    @return �����ļ���С
    */
    uint32_t GetFileSize(int32_t index) const ;

public:

    /** ��ʼλ��
    */
    uint64_t m_startPosition;

    /** cab�ĵ���Ϣ
    */
    RCCabInArchiveInfo m_archiveInfo;

    /** cab�ļ�����Ϣ
    */
    RCVector<RCCabFolder> m_folders;

    /** cab����Ϣ
    */
    RCVector<RCCabItem> m_items;
};

class RCCabDatabaseEx: 
    public RCCabDatabase
{
public:

    /** ������
    */
    IInStreamPtr m_stream;
};

struct RCCabMvItem
{
    /** ������
    */
    int32_t m_volumeIndex;

    /** ������
    */
    int32_t m_itemIndex;
};

class RCCabMvDatabaseEx
{
public:

    /** ��ȡ�ļ�������
    @return �����ļ�������
    */
    int32_t GetFolderIndex(const RCCabMvItem *mvi) const;

    /** ���
    */
    void Clear();

    /** �������
    */
    void FillSortAndShrink();

    /** ���
    @return ͨ����鷵��true�����򷵻�false
    */
    bool Check();

public:

    /** cabÿ���������Ϣ
    */
    RCVector<RCCabDatabaseEx> m_volumes;

    /** cabMv��
    */
    RCVector<RCCabMvItem> m_items;

    /** �ھ��е���ʼ�ļ���
    */
    RCVector<int32_t> m_startFolderOfVol;

    /** �ļ�������ʼ�ļ�����
    */
    RCVector<int32_t> m_folderStartFileIndex;

private:

    /** ���Ƿ����
    @param [in] i1 ������һ
    @param [in] i2 ��������
    @return ��Է���true�����򷵻�false
    */
    bool AreItemsEqual(int32_t i1, int32_t i2);
};

class RCCabInArchive
{
public:

    /** ���ĵ�
    @param [in] searchHeaderSizeLimit ����ͷ�������ƫ��λ��
    @param [in] db cab��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(const uint64_t* searchHeaderSizeLimit, RCCabDatabaseEx& db);

    /** �Ƚ�cabMv��
    @param [in] p1 cabMv��һ
    @param [in] p1 cabMv���
    @param [in] param ����
    @return ��Է���0�����򷵻�����
    */
    static int32_t CompareMvItems(const RCCabMvItem* p1, const RCCabMvItem* p2, void* param);

public:

    /** ��־
    */
    static byte_t s_marker[RCCabHeaderDefs::kMarkerSize];

private:

    /** ��ȡһ���ֽ�
    @return ���ض�ȡ�ֽ�ֵ
    */
    byte_t Read8();

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t Read16();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t Read32();
    
    /** ��ȫ�Ķ��ļ���
    */
    RCStringA SafeReadName();

    /** ����
    @param [in] size �����Ĵ�С
    */
    void Skip(uint32_t size);

    /** �������ĵ�
    @param [out] oa ����cab�ĵ���Ϣ 
    */
    void ReadOtherArchive(RCCabOtherArchive& oa);

private:

    /** �����ڴ�
    */
    RCInBuffer m_inBuffer;
};

END_NAMESPACE_RCZIP

#endif //__RCCabIn_h_