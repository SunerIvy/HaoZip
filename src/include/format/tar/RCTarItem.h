/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTarItem_h_
#define __RCTarItem_h_ 1

#include "format/common/RCItemNameUtils.h"
#include "common/RCStringConvert.h"
#include "base/RCString.h"
#include "RCTarHeader.h"

BEGIN_NAMESPACE_RCZIP

/** Tar ��ʽ�ļ���
*/
struct RCTarItem
{
    /** ����
    */
    RCStringA m_name;

    /** ��С
    */
    uint64_t m_size;

    /** ģʽ
    */
    uint32_t m_mode;

    /** UID
    */
    uint32_t m_uid;

    /** GID
    */
    uint32_t m_gid;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** ���豸
    */
    uint32_t m_deviceMajor;

    /** ���豸
    */
    uint32_t m_deviceMinor;

    /** ������
    */
    RCStringA m_linkName;

    /** �û�
    */
    RCStringA m_user ;

    /** �û���
    */
    RCStringA m_group ;

    /** Magic
    */
    char m_magic[8];

    /** ���ӱ�־
    */
    char m_linkFlag;

    /** ���豸�Ƿ���
    */
    bool m_deviceMajorDefined;

    /** ���豸�Ƿ���
    */
    bool m_deviceMinorDefined;

    /** ����Ƿ�ΪĿ¼
    @return Ŀ¼����true�����򷵻�false
    */
    bool IsDir() const
    {
        switch(m_linkFlag)
        {
          case RCTarHeader::NLinkFlag::s_directory:
          case RCTarHeader::NLinkFlag::s_dumpDir:
            return true;
          case RCTarHeader::NLinkFlag::s_oldNormal:
          case RCTarHeader::NLinkFlag::s_normal:
            return RCItemNameUtils::HasTailSlash(m_name, RC_CP_OEMCP);
        }
        return false;
    }

    /** ����Ƿ�Magic
    @return Magic����true�����򷵻�false
    */
    bool IsMagic() const
    {
        for (int i = 0; i < 5; i++)
          if (m_magic[i] != RCTarHeader::NMagic::s_usTar[i])
            return false;
        return true;
    }

    /** ȡ��ѹ����С
    @return ����ѹ����С
    */
    uint64_t GetPackSize() const { return (m_size + 0x1FF) & (~((uint64_t)0x1FF)); }
};

/** Tar �ļ���
*/
struct RCTarItemEx: public RCTarItem
{
    /** ͷλ��
    */
    uint64_t m_headerPosition;

    /** ���Ӵ�С
    */
    unsigned m_longLinkSize;

    /** ȡ������λ��
    @return ��������λ��
    */
    uint64_t GetDataPosition() const { return m_headerPosition + m_longLinkSize + RCTarHeader::s_recordSize; }

    /** ȡ�ô�С
    @return ���ش�С
    */
    uint64_t GetFullSize() const { return m_longLinkSize + RCTarHeader::s_recordSize + m_size; }
};

END_NAMESPACE_RCZIP

#endif //__RCItem_h_
