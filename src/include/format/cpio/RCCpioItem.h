/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCpioItem_h_
#define __RCCpioItem_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"

#ifdef RCZIP_OS_WIN
#include <sys/stat.h>
#endif

BEGIN_NAMESPACE_RCZIP

struct RCCpioItem
{
    /** ����
    */
    RCStringA m_name;

    /** �����ڵ�
    */
    uint32_t m_inode;

    /** ģʽ 
    */
    uint32_t m_mode;

    /** UID
    */
    uint32_t m_uid;

    /** GID
    */
    uint32_t m_gid;

    /** ��С
    */
    uint32_t m_size;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    // char_t m_linkFlag;
    // RCStringA m_linkName; ?????

    /** ǩ�� 
    */
    char m_magic[8];

    /** ������
    */
    uint32_t m_numLinks;

    /** ѹ�����汾
    */
    uint32_t m_devMajor;

    /** ѹ���Ӱ汾
    */
    uint32_t m_devMinor;

    /** ��ѹ���汾
    */
    uint32_t m_rdevMajor;

    /** ��ѹ�Ӱ汾
    */
    uint32_t m_rdevMinor;

    /** У���
    */
    uint32_t m_chkSum;

    /** �Ƿ����
    */
    uint32_t m_align;

    /** �Ƿ���Ŀ¼
    @return �Ƿ���vtrue�����򷵻�false
    */
    bool IsDir() const
    {
        return (m_mode & 0170000) == 0040000 ;
    }
};

class RCCpioItemEx: 
    public RCCpioItem
{
public:

    /** ��ȡ����ƫ��λ��
    @return ��������ƫ��λ��
    */
    uint64_t GetDataPosition() const
    {
        return m_headerPosition + m_headerSize;
    };

public:

    /** ͷ��ƫ��λ��
    */
    uint64_t m_headerPosition;

    /** ͷ����С
    */
    uint32_t m_headerSize;
};

END_NAMESPACE_RCZIP

#endif //__RCCpioItem_h_
