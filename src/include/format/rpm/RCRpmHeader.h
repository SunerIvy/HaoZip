/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRpmHeader_h_
#define __RCRpmHeader_h_ 1

#include "base/RCTypes.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

class RCRpmDefs
{
public:

    /** ������С
    */
    static const uint32_t s_leadSize = 96;

    /** �����Ϣ��С
    */
    static const uint32_t s_entryInfoSize = 16;

    /** ͷ����С
    */
    static const uint32_t s_csigHeaderSigSize = 16;

    /** �ַ�����
    @param [out] dest ���ؿ������ַ�
    @param [in] src Դ�ַ�
    @return ���ؿ������ַ�
    */
    template <class T>
    static inline T * MyStringCopy(T *dest, const T *src)
    {
        T *destStart = dest;
        while ((*dest++ = *src++) != 0);
        return destStart;
    }

    /** �ַ�����
    @param [in] s �ַ�
    @return �����ַ�����
    */
    template <class T>
    static inline int32_t MyStringLen(const T *s)
    {
        int32_t i;
        for (i = 0; s[i] != _T('\0'); i++);
        return i;
    }
};

struct RCRpmLead
{
    /** ��ʶ
    */
    unsigned char m_magic[4];

    /** ���汾
        not supported  ver1, only support 2,3 and lator
    */
    unsigned char m_major;

    /** �Ӱ汾
    */
    unsigned char m_minor;

    /** ����
    */
    uint16_t m_type;

    /** �ĵ�����
    */
    uint16_t m_archNum;

    /** ����
    */
    char m_name[66];

    /** ����ϵͳ����
    */
    uint16_t m_osNum;

    /** ǩ������
    */
    uint16_t m_signatureType;

    /** ������
        pad to 96 bytes -- 8 byte aligned
    */
    char m_reserved[16];

    /** ����ʶ
    @return ͨ����鷵��true�����򷵻�false
    */
    bool MagicCheck() const;
};

struct RCRpmSigHeaderSig
{
    /** ��ʶ
    */
    unsigned char m_magic[4];

    /** ������
    */
    uint32_t m_reserved;

    /** ������
        count of index entries
    */
    uint32_t m_indexLen;

    /** ���ݳ�
        number of bytes
    */
    uint32_t m_dataLen;

    /** ����ʶ
    @return ͨ����鷵��true�����򷵻�false
    */
    bool MagicCheck();

    /** ��ȡ��ʧͷ����
    @return ���ض�ʧͷ����
    */
    uint32_t GetLostHeaderLen();
};

struct RCRpmFuncWrapper
{
    /** ��ȡͷ������
    @param [in] inStream ������
    @param [out] h ����ͷ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ReadSigHeaderSig(IInStream* inStream, RCRpmSigHeaderSig& h);

    /** ���ĵ�
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult OpenArchive(IInStream* inStream);
};

END_NAMESPACE_RCZIP

#endif //__RCRpmHeader_h_
