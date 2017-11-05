/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarItem_h_
#define __RCRarItem_h_ 1

#include "RCRarHeader.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

struct RCRarTime
{
    /** dosʱ��
    */
    uint32_t m_dosTime;

    /** ��λ��
    */
    byte_t m_lowSecond;

    /** ʱ��
    */
    byte_t m_subTime[3];
};

struct RCRarItem
{
    /** ��С
    */
    uint64_t m_size;

    /** ����С
    */
    uint64_t m_packSize;

    /** ����ʱ��
    */
    RCRarTime m_cTime;

    /** ����ʱ��
    */
    RCRarTime m_aTime;

    /** ����ʱ��
    */
    RCRarTime m_mTime;

    /** crc
    */
    uint32_t m_fileCRC;

    /** ����
    */
    uint32_t m_attrib;

    /** ���
    */
    uint16_t m_flags;

    /** ƽ̨ϵͳ
    */
    byte_t m_hostOS;

    /** ��ѹ�汾
    */
    byte_t m_unPackVersion;

    /** ����
    */
    byte_t m_method;

    /** �Ƿ��д���ʱ��
    */
    bool m_cTimeDefined;

    /** �Ƿ��з���ʱ��
    */
    bool m_aTimeDefined;

    /** ����
    */
    RCStringA m_name;

    /** unicode����
    */
    RCString m_unicodeName;

    /** salt(�����õ�)
    */
    byte_t m_salt[8];

    /** �Ƿ����
    @return �Ƿ���true����զ����false
    */
    bool IsEncrypted() const { return (m_flags & RCRarHeader::NFile::kEncrypted) != 0; }

    /** �Ƿ��ǹ�ʵѹ��
    @return �Ƿ���true����զ����false
    */
    bool IsSolid() const { return (m_flags & RCRarHeader::NFile::kSolid) != 0; }

    /** �Ƿ���ע��
    @return �Ƿ���true����զ����false
    */
    bool IsCommented() const { return (m_flags & RCRarHeader::NFile::kComment) != 0; }

    /** ֮ǰ�Ƿ��з־��
    @return �Ƿ���true����զ����false
    */
    bool IsSplitBefore() const { return (m_flags & RCRarHeader::NFile::kSplitBefore) != 0; }

    /** ֮���Ƿ��з־��
    @return �Ƿ���true����զ����false
    */
    bool IsSplitAfter() const { return (m_flags & RCRarHeader::NFile::kSplitAfter) != 0; }

    /** �Ƿ���salt
    @return �з���true����զ����false
    */
    bool HasSalt() const { return (m_flags & RCRarHeader::NFile::kSalt) != 0; }

    /** �Ƿ�����չʱ��
    @return �з���true����զ����false
    */
    bool HasExtTime() const { return (m_flags & RCRarHeader::NFile::kExtTime) != 0; }

    /** �Ƿ���unicode����
    @return �з���true����զ����false
    */
    bool HasUnicodeName() const { return (m_flags & RCRarHeader::NFile::kUnicodeName) != 0; }

    /** �Ƿ����ϰ汾
    @return �Ƿ���true����զ����false
    */
    bool IsOldVersion() const { return (m_flags & RCRarHeader::NFile::kOldVersion) != 0; }

    /** ��ȡ�ֵ��С
    @return �����ֵ��С
    */
    uint32_t GetDictSize() const { return (m_flags >> RCRarHeader::NFile::kDictBitStart) & RCRarHeader::NFile::kDictMask; }

    /** �Ƿ���·��
    @return �Ƿ���true����զ����false
    */
    bool IsDir() const;

    /** �Ƿ��Ǻ�����
    @return �Ƿ���true����զ����false
    */
    bool IgnoreItem() const;

    /** ��ȡwindows�µ�����
    @return ��������
    */
    uint32_t GetWinAttributes() const;

    /** Ĭ�Ϲ��캯��
    */
    RCRarItem(): 
      m_cTimeDefined(false), 
      m_aTimeDefined(false) {}
};

class RCRarItemEx: public RCRarItem
{
public:

    /** ��ȡ������С
    @return ����������С
    */
    uint64_t GetFullSize() const { return m_mainPartSize + m_commentSize + m_alignSize + m_packSize; };

    /** ��ȡע��λ��
    @return ����ע��λ��
    */
    uint64_t GetCommentPosition() const { return m_position + m_mainPartSize; };

    /** ��ȡ����λ��
    @return ��������λ��
    */
    uint64_t GetDataPosition() const { return GetCommentPosition() + m_commentSize + m_alignSize; };

public:

    /** λ��
    */
    uint64_t m_position;

    /** ���ϴ�С
    */
    uint16_t m_mainPartSize;

    /** ע�ʹ�С
    */
    uint16_t m_commentSize;

    /** �����С
    */
    uint16_t m_alignSize;
};

/** RCRarItemEx����ָ��
*/
typedef RCSharedPtr<RCRarItemEx>  RCRarItemExPtr ;

END_NAMESPACE_RCZIP

#endif //__RCRarItem_h_
