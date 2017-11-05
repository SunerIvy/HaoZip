/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCChmItem_h_
#define __RCChmItem_h_ 1

#include "base/RCString.h"
#include "common/RCVector.h"
#include "common/RCBuffer.h"
#include "archive/common/RCGuidDefs.h"

BEGIN_NAMESPACE_RCZIP

struct RCChmItem
{
    /** ��
    */
    uint64_t m_section;

    /** ƫ��
    */
    uint64_t m_offset;

    /** ��С
    */
    uint64_t m_size;

    /** ����
    */
    RCStringA m_name;

    /** �Ƿ��������Ŀ
    @return �Ƿ���true�����򷵻�false
    */
    bool IsFormatRelatedItem() const
    {
        if (m_name.length() < 2)
        {
            return false;
        }
        return m_name[0] == ':' && m_name[1] == ':';
    }

    /** �Ƿ����û���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsUserItem() const
    {
        if (m_name.length() < 2)
        {
            return false;
        }
        return m_name[0] == '/';
    }

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const
    {
        if (m_name.length() == 0)
        {
            return false;
        }
        return (m_name[m_name.length() - 1] == '/');
    }
};

struct RCChmDatabase
{
    /** ����ƫ��
    */
    uint64_t m_contentOffset;

    /** chm��
    */
    RCVector<RCChmItem> m_items;

    /** �¸�ʽ�ַ���
    */
    RCStringA m_newFormatString;

    /** ������ʽ
    */
    bool m_help2Format;

    /** �¸�ʽ
    */
    bool m_newFormat;

    /** ������
    @param [in] name ������
    @return ����������
    */
    int32_t FindItem(const RCStringA& name) const
    {
        for (int32_t i = 0; i <(int32_t)m_items.size(); i++)
        {
            if (m_items[i].m_name == name)
            {
                return i;
            }
        }
        return -1;
    }

    /** ���
    */
    void Clear()
    {
        m_newFormat = false;
        m_newFormatString.clear();
        m_help2Format = false;
        m_items.clear();
    }
};

struct RCChmResetTable
{
    /** ��ѹ��С
    */
    uint64_t m_uncompressedSize;

    /** ѹ����С
    */
    uint64_t m_compressedSize;

    /** ���С
    */
    uint64_t m_blockSize;

    /** ����ƫ��
    */
    RCVector<uint64_t> m_resetOffsets;

    /** ��ȡ���е�ѹ����С
    @param [in] blockIndex ������ 
    @param [in] numBlocks �����
    @param [out] size ���ش�С
    @return �ɹ���ȡ����true�����򷵻�false
    */
    bool GetCompressedSizeOfBlocks(uint64_t blockIndex, uint32_t numBlocks, uint64_t &size) const
    {
        if (blockIndex >= m_resetOffsets.size())
        {
            return false;
        }

        uint64_t startPos = m_resetOffsets[(int32_t)blockIndex];
        if (blockIndex + numBlocks >= m_resetOffsets.size())
        {
            size = m_compressedSize - startPos;
        }
        else
        {
            size = m_resetOffsets[(int32_t)(blockIndex + numBlocks)] - startPos;
        }
        return true;
    }

    /** ��ȡ���е�ѹ����С
    @param [in] blockIndex ������ 
    @param [out] size ���ش�С
    @return �ɹ���ȡ����true�����򷵻�false
    */
    bool GetCompressedSizeOfBlock(uint64_t blockIndex, uint64_t& size) const
    {
        return GetCompressedSizeOfBlocks(blockIndex, 1, size);
    }

    /** ��ȡ��ĸ���
    @param [in] size ��С
    @return ���ؿ����
    */
    uint64_t GetNumBlocks(uint64_t size) const
    {
        return (size + m_blockSize - 1) / m_blockSize;
    }
};

struct RCChmLzxInfo
{
    /** �汾
    */
    uint32_t m_version;

    /** ���ü��
    */
    uint32_t m_resetInterval;

    /** ���ڴ�С
    */
    uint32_t m_windowSize;

    /** cache��С
    */
    uint32_t m_cacheSize;

    /** ���ñ�
    */
    RCChmResetTable m_resetTable;

    /** ��ȡ�ֵ�λ��
    @return �����ֵ�λ��
    */
    uint32_t GetNumDictBits() const
    {
        if (m_version == 2 || m_version == 3)
        {
            for (int32_t i = 0; i <= 31; i++)
            {
                if (((uint32_t)1 << i) >= m_windowSize)
                {
                    return 15 + i;
                }
            }
        }
        return 0;
    }

    /** ��ȡ�ļ��д�С
    @return �����ļ��д�С
    */
    uint64_t GetFolderSize() const
    { 
        return m_resetTable.m_blockSize * m_resetInterval; 
    };

    /** ��ȡ�ļ��и���
    @param [in] �ļ���ƫ��
    @return �����ļ��и���
    */
    uint64_t GetFolder(uint64_t offset) const
    { 
        return offset / GetFolderSize();
    };

    /** ��ȡ�ļ���ƫ��
    @param [in] folderIndex �ļ�������
    @return �����ļ���ƫ��
    */
    uint64_t GetFolderPos(uint64_t folderIndex) const
    {
        return folderIndex * GetFolderSize();
    };

    /** ���ļ����е�������ȡ������
    @param [in] folderIndex �ļ�������
    @return ���ؿ�����
    */
    uint64_t GetBlockIndexFromFolderIndex(uint64_t folderIndex) const
    {
        return folderIndex * m_resetInterval;
    };

    /** ��ȡ�ļ����е�ƫ��
    @param [in] folderIndex �ļ�������
    @param [out] offset ����ƫ��
    @return �ɹ�����true�����򷵻�false
    */
    bool GetOffsetOfFolder(uint64_t folderIndex, uint64_t& offset) const
    {
        uint64_t blockIndex = GetBlockIndexFromFolderIndex(folderIndex);
        if (blockIndex >= m_resetTable.m_resetOffsets.size())
        {
            return false;
        }
        offset = m_resetTable.m_resetOffsets[(int32_t)blockIndex];
        return true;
    }

    /** ��ȡ�ļ��е�ѹ����С
    @param [in] folderIndex �ļ�������
    @param [out] size ���ش�С
    @return �ɹ�����true�����򷵻�false
    */
    bool GetCompressedSizeOfFolder(uint64_t folderIndex, uint64_t& size) const
    {
        uint64_t blockIndex = GetBlockIndexFromFolderIndex(folderIndex);
        return m_resetTable.GetCompressedSizeOfBlocks(blockIndex, m_resetInterval, size);
    }
};

struct RCChmMethodInfo
{
    /** GUID
    */
    RC_GUID m_guid;

    /** ��������
    */
    RCByteBuffer m_controlData;

    /** lzx��Ϣ
    */
    RCChmLzxInfo m_lzxInfo;

    /** �Ƿ���lzx
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLzx() const;

    /** �Ƿ���des
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDes() const;

    /** ��ȡGUID�ַ�
    @return ����GUID�ַ�
    */
    RCStringA GetGuidString() const;

    /** ��ȡ����
    @return ��������
    */
    RCString GetName() const;
};

struct RCChmSectionInfo
{
    /** ƫ��
    */
    uint64_t m_offset;

    /** ѹ����С
    */
    uint64_t m_compressedSize;

    /** ��ѹ��С
    */
    uint64_t m_uncompressedSize;

    /** ����
    */
    RCStringA m_name;

    /** ����
    */
    RCVector<RCChmMethodInfo> m_methods;

    /** �Ƿ���lzx
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLzx() const;

    /** ��ȡ������
    @return ���ط�����
    */
    RCString GetMethodName() const;
};

class RCChmFilesDatabase: public RCChmDatabase
{
public:

    /** ��ȡ�ļ���С
    @param [in] �ļ�����
    @return �ļ���С
    */
    uint64_t GetFileSize(int32_t fileIndex) const
    { 
        return m_items[m_indices[fileIndex]].m_size;
    }

    /** ��ȡ�ļ�ƫ��
    @param [in] �ļ�����
    @return �ļ�ƫ��
    */
    uint64_t GetFileOffset(int32_t fileIndex) const
    { 
        return m_items[m_indices[fileIndex]].m_offset;
    }

    /** ��ȡ�ļ��и���
    @param [in] fileIndex �ļ�����
    @return �����ļ��и���
    */
    uint64_t GetFolder(int32_t fileIndex) const
    {
        const RCChmItem& item = m_items[m_indices[fileIndex]];
        const RCChmSectionInfo& section = m_sections[(int32_t)item.m_section];
        if (section.IsLzx())
        {
            return section.m_methods[0].m_lzxInfo.GetFolder(item.m_offset);
        }
        return 0;
    }

    /** ��ȡ���һ���ļ��и���
    @param [in] fileIndex �ļ�����
    @return �����ļ��и���
    */
    uint64_t GetLastFolder(int32_t fileIndex) const
    {
        const RCChmItem& item = m_items[m_indices[fileIndex]];
        const RCChmSectionInfo& section = m_sections[(int32_t)item.m_section];
        if (section.IsLzx())
        {
            return section.m_methods[0].m_lzxInfo.GetFolder(item.m_offset + item.m_size - 1);
        }
        return 0;
    }

    /** �ߵȼ����
    */
    void HighLevelClear()
    {
        m_lowLevel = true;
        m_indices.clear();
        m_sections.clear();
    }

    /** ���
    */
    void Clear()
    {
        RCChmDatabase::Clear();
        HighLevelClear();
    }

    /** ������������
    */
    void SetIndices();

    /** ����
    */
    void Sort();

    /** ���
    @return ͨ����鷵��true�����򷵻�false
    */
    bool Check();

public:

    /** �͵�
    */
    bool m_lowLevel;

    /** ��������
    */
    RCVector<int32_t> m_indices;

    /** ����Ϣ
    */
    RCVector<RCChmSectionInfo> m_sections;
};

END_NAMESPACE_RCZIP

#endif //__RCChmItem_h_
