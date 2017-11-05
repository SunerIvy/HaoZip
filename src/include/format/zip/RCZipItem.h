/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipItem_h_
#define __RCZipItem_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "common/RCBuffer.h"
#include "common/RCVector.h"
#include "common/RCStringConvert.h"
#include "filesystem/RCFileDefs.h"
#include "RCZipHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RCZipVersion
{
    /** �汾
    */
    byte_t m_version ;

    /** ����ϵͳ
    */
    byte_t m_hostOS ;
};

bool operator==(const RCZipVersion& v1, const RCZipVersion& v2) ;

bool operator!=(const RCZipVersion& v1, const RCZipVersion& v2) ;

struct RCZipExtraSubBlock
{
    /** ID
    */
    uint16_t m_id ;

    /** DATA
    */
    RCByteBuffer m_data ;

    /** ��ѹNTFSʱ��
    */
    bool ExtractNtfsTime(int index, RC_FILE_TIME& ft) const ;

    /** ��ѹUNIXʱ��
    */
    bool ExtractUnixTime(int index, uint32_t& res) const ;
};

struct RCZipWzAESExtraField
{
    /** �汾
    */
    uint16_t m_vendorVersion ; // 0x0001 - AE-1, 0x0002 - AE-2,

    /** ǿ��
    */
    byte_t m_strength ;        // 1 - 128-bit , 2 - 192-bit , 3 - 256-bit

    /** ģʽ
    */
    uint16_t m_method ;

    /** Ĭ�Ϲ��캯��
    */
    RCZipWzAESExtraField(): m_vendorVersion(2), m_strength(3), m_method(0) {}

    /** �Ƿ���ҪCRC
    @return ��Ҫ����true�����򷵻�false
    */
    bool NeedCrc() const 
    { 
        return (m_vendorVersion == 1);
    }

    /** ���ӿ��������
    @param [in] sb �ӿ�
    @return �ɹ�����true�����򷵻�false
    */
    bool ParseFromSubBlock(const RCZipExtraSubBlock& sb)
    {
        if (sb.m_id != RCZipHeader::NExtraID::kWzAES)
        {
            return false;
        }

        if (sb.m_data.GetCapacity() < 7)
        {
            return false;
        }

        const byte_t *p = sb.m_data.data() ;
        m_vendorVersion = (((uint16_t)p[1]) << 8) | p[0];
        if (p[2] != 'A' || p[3] != 'E')
        {
            return false;
        }

        m_strength = p[4];
        m_method = (((uint16_t)p[6]) << 16) | p[5];

        return true;
    }

    /** �����ӿ�
    @param [out] sb �����ӿ���Ϣ
    */
    void SetSubBlock(RCZipExtraSubBlock& sb) const
    {
        sb.m_data.SetCapacity(7) ;
        sb.m_id = RCZipHeader::NExtraID::kWzAES;
        byte_t *p = sb.m_data.data() ;
        p[0] = (byte_t)m_vendorVersion;
        p[1] = (byte_t)(m_vendorVersion >> 8) ;
        p[2] = 'A';
        p[3] = 'E';
        p[4] = m_strength;
        p[5] = (byte_t)m_method;
        p[6] = (byte_t)(m_method >> 8) ;
    }
};

namespace RCZipStrongCryptoFlags
{
    const uint16_t kDES      = 0x6601 ;

    const uint16_t kRC2old   = 0x6602 ;

    const uint16_t k3DES168  = 0x6603 ;

    const uint16_t k3DES112  = 0x6609 ;

    const uint16_t kAES128   = 0x660E ;

    const uint16_t kAES192   = 0x660F;

    const uint16_t kAES256   = 0x6610 ;

    const uint16_t kRC2      = 0x6702 ;

    const uint16_t kBlowfish = 0x6720 ;

    const uint16_t kTwofish  = 0x6721 ;

    const uint16_t kRC4      = 0x6801 ;
}

struct RCZipStrongCryptoField
{
    /** ��ʽ
    */
    uint16_t m_format ;

    /** ALG
    */
    uint16_t m_algId ;

    /** ����
    */
    uint16_t m_bitLen ;

    /** ��־
    */
    uint16_t m_flags;

    /** ���ӿ��������
    @param [in] sb �ӿ�
    @return �ɹ�����true�����򷵻�false
    */
    bool ParseFromSubBlock(const RCZipExtraSubBlock& sb)
    {
        if (sb.m_id != RCZipHeader::NExtraID::kStrongEncrypt)
        {
            return false;
        }

        const byte_t* p = sb.m_data.data();
        if (sb.m_data.GetCapacity() < 8)
        {
            return false;
        }

        m_format = (((uint16_t)p[1]) << 8) | p[0];
        m_algId  = (((uint16_t)p[3]) << 8) | p[2];
        m_bitLen = (((uint16_t)p[5]) << 8) | p[4];
        m_flags  = (((uint16_t)p[7]) << 8) | p[6];

        return (m_format == 2) ;
    }
};

struct RCZipExtraBlock
{
    /** �ӿ�
    */
    RCVector<RCZipExtraSubBlock> m_subBlocks ;

    /** ���
    */
    void Clear() 
    { 
        m_subBlocks.clear();
    }

    /** ��ȡ��С
    */
    size_t GetSize() const
    {
        size_t res = 0;
        for (uint32_t i = 0; i < (uint32_t)m_subBlocks.size(); i++)
        {
            res += m_subBlocks[i].m_data.GetCapacity() + 2 + 2;
        }
        return res;
    }

    /** ��ȡWzAES��Ϣ
    @param [out] aesField ����WzAES��Ϣ
    @return �ɹ�����true�����򷵻�false
    */
    bool GetWzAESField(RCZipWzAESExtraField &aesField) const
    {
        for (uint32_t i = 0; i < (uint32_t)m_subBlocks.size(); i++)
        {
            if (aesField.ParseFromSubBlock(m_subBlocks[i]))
            {
                return true;
            }
        }
        return false;
    }

    /** ��ȡ������Ϣ
    @param [out] f ���ؼ�����Ϣ
    @return �ɹ�����true�����򷵻�false
    */
    bool GetStrongCryptoField(RCZipStrongCryptoField &f) const
    {
        for (uint32_t i = 0; i < (uint32_t)m_subBlocks.size(); i++)
        {
            if (f.ParseFromSubBlock(m_subBlocks[i]))
            {
                return true;
            }
        }
        return false;
    }

    /** �Ƿ���WzAES��Ϣ
    @return �з���true�����򷵻�false
    */
    bool HasWzAesField() const
    {
        RCZipWzAESExtraField aesField;

        return GetWzAESField(aesField);
    }

    /** ��ȡntfsʱ��
    @param [in] index ���
    @param [in] ft ʱ����Ϣ
    @return �ɹ�����true�����򷵻�false
    */
    bool GetNtfsTime(int32_t index, RC_FILE_TIME &ft) const
    {
        for (uint32_t i = 0; i < (uint32_t)m_subBlocks.size(); i++)
        {
            const RCZipExtraSubBlock &sb = m_subBlocks[i];

            if (sb.m_id == RCZipHeader::NExtraID::kNTFS)
            {
                return sb.ExtractNtfsTime(index, ft);
            }
        }
        return false;
    }

    /** ��ȡunixʱ��
    @param [in] index ���
    @param [in] res ʱ����Ϣ
    @return �ɹ�����true�����򷵻�false
    */ 
    bool GetUnixTime(int32_t index, uint32_t& res) const
    {
        for (int32_t i = 0; i < (int32_t)m_subBlocks.size(); i++)
        {
            const RCZipExtraSubBlock& sb = m_subBlocks[i];
            if (sb.m_id == RCZipHeader::NExtraID::kUnixTime)
            {
                return sb.ExtractUnixTime(index, res);
            }
        }
        return false;
    }

    /** �Ƴ�δ֪�ӿ�
    */ 
    void RemoveUnknownSubBlocks()
    {
        for (int32_t i = (int32_t)m_subBlocks.size() - 1; i >= 0; i--)
        { 
            if (m_subBlocks[i].m_id != RCZipHeader::NExtraID::kWzAES)
            {
                RCVectorUtils::Delete(m_subBlocks, i);
            }
        }
    }
};

class RCZipLocalItem
{
public:

    /** ��ѹ�汾
    */
    RCZipVersion m_extractVersion ;

    /** ��־
    */
    uint16_t m_flags ;

    /** ѹ��ģʽ
    */
    uint16_t m_compressionMethod ;

    /** ʱ��
    */
    uint32_t m_time ;

    /** �ļ�crc
    */
    uint32_t m_fileCRC ;

    /** ѹ����С
    */
    uint64_t m_packSize ;

    /** ��ѹ��С
    */
    uint64_t m_unPackSize ;

    /** �ļ���
    */
    RCStringA m_name ;

    /** ������չ��Ϣ
    */
    RCZipExtraBlock m_localExtra ;

public:

    /** �Ƿ���UTF8����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsUtf8() const
    {
        return (m_flags & RCZipHeader::NFlags::kUtf8) != 0; 
    }

    /** �Ƿ��Ǽ���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEncrypted() const
    { 
        return (m_flags & RCZipHeader::NFlags::kEncrypted) != 0; 
    }

    /** �Ƿ���Strong����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsStrongEncrypted() const
    { 
        return IsEncrypted() && (m_flags & RCZipHeader::NFlags::kStrongEncrypted) != 0;
    }

    /** �Ƿ���acs����
    @return �Ƿ���true�����򷵻�false
    */  
    bool IsAesEncrypted() const 
    {
        return IsEncrypted() && (IsStrongEncrypted() || m_compressionMethod == RCZipHeader::NCompressionMethod::kWzAES); 
    }
 
    /** �Ƿ���LzmaEOS
    @return �Ƿ���true�����򷵻�false
    */ 
    bool IsLzmaEOS() const
    { 
        return (m_flags & RCZipHeader::NFlags::kLzmaEOS) != 0;
    }

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const;

    /** �Ƿ��Ǻ�����
    @return �Ƿ���true�����򷵻�false
    */
    bool IgnoreItem() const
    { 
        return false; 
    }

    /** ��ȡwindows�µ�����
    @return ����
    */
    uint32_t GetWinAttributes() const ;

    /** �Ƿ�������
    @return �Ƿ���true�����򷵻�false
    */
    bool HasDescriptor() const
    { 
        return (m_flags & RCZipHeader::NFlags::kDescriptorUsedMask) != 0;
    }

    /** ��ȡunicode�ַ���
    @return unicode�ַ���
    */
    RCString GetUnicodeString(const RCStringA &s) const
    {
        RCString res;
        if (IsUtf8())
        {    
            if (!RCStringConvert::ConvertUTF8ToUnicode(s.c_str(), s.length(), res))
            {
                res.clear();
            }
        }

        if (res.empty())
        {
            res = RCStringConvert::MultiByteToUnicodeString(s, GetCodePage());
        }

        return res;
    }

public:

    /** �����־
    */
    void ClearFlags() 
    {
        m_flags = 0;
    }

    /** �����Ƿ����
    */
    void SetEncrypted(bool encrypted) ;

    /** ����UTF8
    */
    void SetUtf8(bool isUtf8) ;

    /** ��ȡ�ַ�����
    @return �����ַ�����
    */
    uint16_t GetCodePage() const
    { 
        return  RC_CP_OEMCP;
    }
  
private:

    /** ���ñ�־
    @param [in] startBitNumber
    @param [in] numBits
    @param [in] value
    */
    void SetFlagBits(int startBitNumber, int numBits, int value) ;

    /** ����bit mask
    @param [in] bitMask
    @param [in] enable
    */
    void SetBitMask(int bitMask, bool enable) ;
};

class RCZipItem:
    public RCZipLocalItem
{
public:

    /** �汾
    */
    RCZipVersion m_madeByVersion ;

    /** �ڲ�����
    */
    uint16_t m_internalAttributes ;

    /** �ⲿ����
    */
    uint32_t m_externalAttributes ;

    /** ������ʼ��
    */
    uint16_t m_diskNumberStart;

    /** ����ͷλ��
    */
    uint64_t m_localHeaderPosition ;

    /** ntfs�޸�ʱ��
    */
    RC_FILE_TIME m_ntfsMTime ;

    /** ntfs����ʱ��
    */
    RC_FILE_TIME m_ntfsATime ;

    /** ntfs����ʱ��
    */
    RC_FILE_TIME m_ntfsCTime ;

    /** ��չ����Ϣ
    */
    RCZipExtraBlock m_centralExtra ;

    /** ע��
    */
    RCByteBuffer m_comment ;

    /** from local
    */
    bool m_fromLocal ;

    /** from central
    */
    bool m_fromCentral ;

    /** �Ƿ���ntfsʱ��
    */
    bool m_ntfsTimeIsDefined ;

public:

    /** �Ƿ���Ŀ¼
    @return ��Ŀ¼����true�����򷵻�false
    */
    bool IsDir() const ;

    /** �õ�windows�µ�����
    @return ����
    */
    uint32_t GetWinAttributes() const ;

    /** �Ƿ���crc
    @return �Ƿ���true�����򷵻�false
    */
    bool IsThereCrc() const
    {
        if (m_compressionMethod == RCZipHeader::NCompressionMethod::kWzAES)
        {
            RCZipWzAESExtraField aesField;
            if (m_centralExtra.GetWzAESField(aesField))
            {
                return aesField.NeedCrc() ;
            }
        }
        return (m_fileCRC != 0 || !IsDir());
    }

    /** ��ȡ�ַ�����
    @return �����ַ�����
    */
    uint16_t GetCodePage() const
    {
        return (uint16_t)((m_madeByVersion.m_hostOS == RCZipHeader::NHostOS::kFAT
                          || m_madeByVersion.m_hostOS == RCZipHeader::NHostOS::kNTFS) ? 
                          RC_CP_OEMCP : RC_CP_ACP);
    }

    /** Ĭ�Ϲ��캯��
    */
    RCZipItem() : m_fromLocal(false), m_fromCentral(false), m_ntfsTimeIsDefined(false) {}
};

class RCZipItemEx:
    public RCZipItem
{
public:

    /** �ļ�ͷ�����ֵĴ�С
    */
    uint32_t m_fileHeaderWithNameSize ;

    /** ������չ��Ϣ
    */
    uint16_t m_localExtraSize ;

public:

    /** ��ȡ�������д�С
    @return �������д�С
    */
    uint64_t GetLocalFullSize() const
    { 
        return m_fileHeaderWithNameSize + m_localExtraSize + m_packSize +
            (HasDescriptor() ? RCZipHeader::kDataDescriptorSize : 0); 
    };

    /** ������չ��Ϣ��λ��
    @return  ��չ��Ϣ��λ��
    */
    uint64_t GetLocalExtraPosition() const
    { 
        return m_localHeaderPosition + m_fileHeaderWithNameSize; 
    };

    /** ��ȡ��������λ��
    @return����λ��
    */
    uint64_t GetDataPosition() const
    { 
        return GetLocalExtraPosition() + m_localExtraSize; 
    };
};

/** RCZipItem����ָ��
*/
typedef RCSharedPtr<RCZipItem>  RCZipItemPtr ;

/** RCZipItemEx����ָ��
*/
typedef RCSharedPtr<RCZipItemEx>  RCZipItemExPtr ;

END_NAMESPACE_RCZIP

#endif //__RCZipItem_h_
