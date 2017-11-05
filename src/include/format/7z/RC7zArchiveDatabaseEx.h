/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zArchiveDatabaseEx_h_
#define __RC7zArchiveDatabaseEx_h_ 1

#include "format/7z/RC7zItem.h"
#include "format/7z/RC7zInArchiveInfo.h"

BEGIN_NAMESPACE_RCZIP

class RC7zArchiveDatabaseEx:
    public RC7zArchiveDatabase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zArchiveDatabaseEx() ;
    
    /** Ĭ����������
    */
    ~RC7zArchiveDatabaseEx() ;

public:

    /** ����
    */
    void Clear() ;

    /** ��ʼ�ļ�����ʼ������
    */
    void FillFolderStartPackStream();

    /** ��ʼ��ʼλ��
    */
    void FillStartPos();

    /** ��ʼ�ļ�����ʼ�ļ�����
    @throws ʧ�����쳣
    */
    void FillFolderStartFileIndex();

    /** ��ʼ
    */
    void Fill() ;

    /** ��ȡ�ļ�������λ��
    @param [in] folderIndex �ļ�������
    @param [in] indexInFolder ���ļ�������
    @return �����ļ�������λ��
    */
    uint64_t GetFolderStreamPos(int32_t folderIndex, int32_t indexInFolder) const ;

    /** ��ȡ�ļ��������а��Ĵ�С
    @param [in] folderIndex �ļ�������
    @return �����ļ��������а��Ĵ�С
    */
    uint64_t GetFolderFullPackSize(int32_t folderIndex) const ;

    /** ��ȡ�ļ��а�������С
    @param [in] folderIndex �ļ�������
    @param [in] streamIndex ��ʼ����
    @return �����ļ��а�������С
    */
    uint64_t GetFolderPackStreamSize(int32_t folderIndex, int32_t streamIndex) const ;

    /** ��ȡ�ļ����Ĵ�С
    @param [in] fileIndex �ļ�����
    @return �ļ����Ĵ�С
    */
    uint64_t GetFilePackSize(RC7zNum fileIndex) const ;

public:

    /** �ĵ���Ϣ
    */
    RC7zInArchiveInfo m_archiveInfo;

    /** ��������ʼλ��
    */
    RCVector<uint64_t> m_packStreamStartPositions;

    /** �ļ�����ʼ����������
    */
    RCVector<RC7zNum> m_folderStartPackStreamIndex;

    /** �ļ�����ʼ�ļ�����
    */
    RCVector<RC7zNum> m_folderStartFileIndex;

    /** �ļ��������ļ���������map
    */
    RCVector<RC7zNum> m_fileIndexToFolderIndexMap;

    /** ͷ�ļ���С
    */
    uint64_t m_headersSize;

    /** �����С
    */
    uint64_t m_phySize;
};

END_NAMESPACE_RCZIP

#endif //__RC7zArchiveDatabaseEx_h_
