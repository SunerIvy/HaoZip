/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhItem_h_
#define __RCLzhItem_h_ 1

#include "common/RCBuffer.h"
#include "common/RCVector.h"
#include "common/RCStringUtilA.h"
#include "algorithm/CpuArch.h"
#include "format/lzh/RCLzhHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RCLzhExtension
{
    /** ����
    */
    byte_t m_type;

    /** ���ݻ���
    */
    RCByteBuffer m_data;

    /** ��ȡ�ַ���
    @return �����ַ���
    */
    RCStringA GetString() const
    {
        RCStringA s;
        for (size_t i = 0; i < m_data.GetCapacity(); i++)
        {
            char c = (char)m_data[i];
            if (c == 0)
            {
                break;
            }
            s += c;
        }
        return s;
    }
};

struct RCLzhItem
{
public:

    /** ����
    */
    RCStringA m_name;

    /** ����
    */
    byte_t m_method[RCLzhHeader::s_methodIdSize];

    /** ѹ����С
    */
    uint32_t m_packSize;

    /** ��С
    */
    uint32_t m_size;

    /** �޸�ʱ��
    */
    uint32_t m_modifiedTime;

    /** ����
    */
    byte_t m_attributes;

    /** �ȼ�
    */
    byte_t m_level;

    /** crc
    */
    uint16_t m_crc;

    /** ����ϵͳid
    */
    byte_t m_osId;

    /** ��չ��Ϣ
    */
    RCVector<RCLzhExtension> m_extensions;

    /** �Ƿ�����Ч����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsValidMethod() const
    {
        return (m_method[0] == '-' && m_method[1] == 'l' && m_method[4] == '-');
    }

    /** �Ƿ���lh����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLhMethod() const
    {
        return (IsValidMethod() && m_method[2] == 'h');
    }

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const
    {
        return (IsLhMethod() && m_method[3] == 'd');
    }

    /** �Ƿ���copy����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsCopyMethod() const
    {
        return (IsLhMethod() && m_method[3] == '0') ||
            (IsValidMethod() && m_method[2] == 'z' && m_method[3] == '4');
    }

    /** �Ƿ���lh1 group����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLh1GroupMethod() const
    {
        if (!IsLhMethod())
        {
            return false;
        }

        switch(m_method[3])
        {
        case '1':
            return true;
        }
        return false;
    }

    /** �Ƿ���lh4 group����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsLh4GroupMethod() const
    {
        if (!IsLhMethod())
        {
            return false;
        }

        switch(m_method[3])
        {
        case '4':
        case '5':
        case '6':
        case '7':
            return true;
        }
        return false;
    }

    /** ��ȡ�ֵ��С
    @return �ɹ������ֵ��С�����򷵻�0
    */
    int32_t GetNumDictBits() const
    {
        if (!IsLhMethod())
        {
            return 0;
        }

        switch(m_method[3])
        {
        case '1':
            return 12;

        case '2':
            return 13;

        case '3':
            return 13;

        case '4':
            return 12;

        case '5':
            return 13;

        case '6':
            return 15;

        case '7':
            return 16;
        }
        return 0;
    }

    /** ������չ��Ϣ����
    @param [in] type ����
    @return �ɹ��������������򷵻�-1
    */
    int32_t FindExt(byte_t type) const
    {
        for (int32_t i = 0; i < (int32_t)m_extensions.size(); i++)
        {
            if (m_extensions[i].m_type == type)
            {
                return i;
            }
        }
        return -1;
    }

    /** ��ȡunixʱ��
    @param [out] value ����ʱ��
    @return �ɹ�����true�����򷵻�false
    */
    bool GetUnixTime(uint32_t& value) const
    {
        int32_t index = FindExt(RCLzhHeader::s_extIdUnixTime);
        if (index < 0)
        {
            if (m_level == 2)
            {
                value = m_modifiedTime;
                return true;
            }
            return false;
        }
        const byte_t *data = (const byte_t *)(m_extensions[index].m_data.data());
        value = GetUi32(data);
        return true;
    }

    /** ��ȡĿ¼��
    @return ����Ŀ¼��
    */
    RCStringA GetDirName() const
    {
        int32_t index = FindExt(RCLzhHeader::s_extIdDirName);
        if (index < 0)
        {
            return RCStringA();
        }
        return m_extensions[index].GetString();
    }

    /** ��ȡ�ļ���
    @return �����ļ���
    */
    RCStringA GetFileName() const
    {
        int32_t index = FindExt(RCLzhHeader::s_extIdFileName);
        if (index < 0)
        {
            return m_name;
        }
        return m_extensions[index].GetString();
    }

    /** ��ȡ����
    @return ��������
    */
    RCStringA GetName() const
    {
        RCStringA dirName = GetDirName();
        for(size_t index = 0; index < dirName.size(); ++index)
        {
            if(0xFF == dirName[index])
            {
                dirName[index] = '\\' ;
            }
        }
        if (!dirName.empty())
        {
            RCStringA::value_type c = dirName[dirName.length() - 1];
            if (c != '\\')
            {
                dirName += '\\';
            }
        }
        return dirName + GetFileName();
    }
};

class RCLzhItemEx: public RCLzhItem
{
public:

    /** ����ƫ��λ��
    */
    uint64_t m_dataPosition;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhItem_h_
