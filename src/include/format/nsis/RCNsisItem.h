/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCNsisItem_h_
#define __RCNsisItem_h_ 1

#include "common/RCStringUtil.h"
#include "common/RCStringConvert.h"
#include "filesystem/RCFileDefs.h"
#include "RCNsisHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RCNsisFirstHeader
{
public:

    /** ��־
    */
    uint32_t m_flags;

    /** ͷ������
    */
    uint32_t m_headerLength;

    /** �ĵ���С
    */
    uint32_t m_archiveSize;

public:

    /** �Ƿ�crc
    @return �Ƿ���true�����򷵻�false
    */
    bool ThereIsCrc() const
    {
        if ((m_flags & RCNsisHeader::NFlags::kForceCrc) != 0)
        {
            return true;
        }
        return ((m_flags & RCNsisHeader::NFlags::kNoCrc) == 0);
    }

    /** ��ȡ���ݴ�С
    @return �������ݴ�С
    */
    uint32_t GetDataSize() const
    {
        return m_archiveSize - (ThereIsCrc() ? 4 : 0);
    }
};

struct RCNsisBlockHeader
{
    /** ƫ��
    */
    uint32_t m_offset;

    /** ����
    */
    uint32_t m_num;
};

struct RCNsisItem
{
public:

    /** ǰ׺
    */
    RCStringA m_prefixA;

    /** ǰ׺
    */
    RCString m_prefixU;

    /** ����
    */
    RCStringA m_nameA;

    /** ����
    */
    RCString m_nameU;

    /** �޸�ʱ��
    */
    RC_FILE_TIME m_mTime;

    /** �Ƿ���unicode
    */
    bool m_isUnicode;

    /** �Ƿ����
    */
    bool m_useFilter;

    /** �Ƿ���ѹ��
    */
    bool m_isCompressed;

    /** ��С�Ƿ���
    */
    bool m_sizeIsDefined;

    /** ѹ����С�Ƿ���
    */
    bool m_compressedSizeIsDefined;

    /** ���ƴ�С�Ƿ���
    */
    bool m_estimatedSizeIsDefined;

    /** λ��
    */
    uint32_t m_pos;

    /** ��С
    */
    uint32_t m_size;

    /** ѹ����С
    */
    uint32_t m_compressedSize;

    /** ���ƴ�С
    */
    uint32_t m_estimatedSize;

    /** �ֵ��С
    */
    uint32_t m_dictionarySize;

public:

    /** ���캯��
    */
    RCNsisItem(): 
      m_isUnicode(false),
      m_useFilter(false),
      m_isCompressed(true),
      m_sizeIsDefined(false),
      m_compressedSizeIsDefined(false),
      m_estimatedSizeIsDefined(false),
      m_size(0)
    {
    }

public:

    /** �Ƿ��ǰ�װĿ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsINSTDIR() const
    {
        return (m_prefixA.length() >= 3 || m_prefixU.length() >= 3);
    }

    /** ��ȡ����
    @param [in] unicode �Ƿ���unicode
    @return ��������
    */
    RCString GetReducedName(bool unicode) const
    {
        RCString  s;
        if (unicode)
        {
            s = m_prefixU;
        }
        else
        {
            s = RCStringConvert::MultiByteToUnicodeString(m_prefixA);
        }

        if (s.length() > 0)
        {
            if (s[s.length() - 1] != _T('\\'))
            {
                s += _T('\\');
            }
        }

        if (unicode)
        {
            s += m_nameU;
        }
        else
        {
            s += RCStringConvert::MultiByteToUnicodeString(m_nameA);
        }

        const int32_t len = 9;
        if (RCStringUtil::CompareNoCase(RCStringUtil::Left(s, len), _T("$INSTDIR\\")) == 0)
        {
            s = RCStringUtil::Mid(s, len);
        }
        return s;
    }
};

END_NAMESPACE_RCZIP

#endif //__RCNsisItem_h_
