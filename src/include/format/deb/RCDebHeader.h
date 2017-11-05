/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDebHeader_h_
#define __RCDebHeader_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

class RCDebDefs
{
public:
    static const int32_t kSignatureLen = 8;

    //static const char *kSignature  = "!<arch>\n";
    static const char *kSignature;

    static const int32_t kNameSize = 16;
    static const int32_t kTimeSize = 12;
    static const int32_t kModeSize = 8;
    static const int32_t kSizeSize = 10;
    static const int32_t kHeaderSize = kNameSize + kTimeSize + 6 + 6 + kModeSize + kSizeSize + 1 + 1;

    static void MyStrNCpy(char *dest, const char *src, int32_t size);
    static bool OctalToNumber(const char *s, int32_t size, uint64_t &res);
    static bool OctalToNumber32(const char *s, int32_t size, uint32_t &res);
    static bool DecimalToNumber(const char *s, int32_t size, uint64_t &res);
    static bool DecimalToNumber32(const char *s, int32_t size, uint32_t &res);
};

class RCDebItem
{
public:

    /** �ļ��� 
    */
    RCStringA m_name;

    /** ��С
    */
    uint64_t m_size;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** ģʽ
    */
    uint32_t m_mode;

    /** ͷ��ƫ��λ��
    */
    uint64_t m_headerPos;

    /** ����ƫ��λ��
    @return ��������ƫ��λ��
    */
    uint64_t GetDataPos() const
    {
        return m_headerPos + RCDebDefs::kHeaderSize; 
    };
};

class RCDebInArchive
{
public:

    /** ���ĵ�
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream);

    /** ��ȡ��һ��
    @param [out] filled �Ƿ����
    @param [out] itemInfo deb����Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult GetNextItem(bool& filled, RCDebItem& itemInfo);

    /** ��������
    @param [in] ������С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SkipData(uint64_t dataSize);

private:
    
    /** ��ȡ��һ��
    @param [out] filled �Ƿ����
    @param [out] itemInfo deb����Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult GetNextItemReal(bool &filled, RCDebItem &itemInfo);

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** λ��
    */
    uint64_t m_position;
};

END_NAMESPACE_RCZIP

#endif //__RCDebHeader_h_