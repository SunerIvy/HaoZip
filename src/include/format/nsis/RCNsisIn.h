/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCNsisIn_h_
#define __RCNsisIn_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "common/RCBuffer.h"
#include "common/RCVector.h"
#include "RCNsisDecode.h"
#include "RCNsisItem.h"

BEGIN_NAMESPACE_RCZIP

class RCNsisIn
{
public:

    /** ���ĵ�
    @param [in] codecsInfo ���������ָ��
    @param [in] inStream ������
    @param [in] maxCheckStartPosition �����ļ���ʽǩ�������ƫ��λ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(ICompressCodecsInfo* codecsInfo, IInStream* inStream, const uint64_t* maxCheckStartPosition);

    /** ���
    */
    void Clear();

    /** ��ȡƫ��
    @return ����ƫ��
    */
    uint32_t GetOffset() const
    {
        return m_isSolid ? 4 : 0;
    }

    /** ��ȡ����λ��
    @param [in] index ����
    @return ��������λ��
    */
    uint64_t GetDataPos(int index)
    {
        const RCNsisItem& item = m_items[index];
        return GetOffset() + m_firstHeader.m_headerLength + item.m_pos;
    }

    /**  ��ȡ��ʵ���λ��
    @param [in] index ����
    @return ���ع�ʵ���λ��
    */
    uint64_t GetPosOfSolidItem(int index) const
    {
        const RCNsisItem& item = m_items[index];
        return 4 + m_firstHeader.m_headerLength + item.m_pos;
    }

    /** ��ȡ�޹�ʵ���λ��
    @param [in] index ����
    @return �����޹�ʵ���λ��
    */
    uint64_t GetPosOfNonSolidItem(int index) const
    {
        const RCNsisItem& item = m_items[index];
        return m_streamOffset + m_nonSolidStartOffset + 4  + item.m_pos;
    }

    /** �ͷ�
    */
    void Release()
    {
        m_decoder.Release();
    }

private:

    /** ��ȡ�ֽ�
    @return ��ȡ�ֽ�ֵ
    */
    byte_t ReadByte();

    /** ��ȡ�޷�������
    @param [out] v ����ֵ
    @return �ɹ�����true,���򷵻�false
    */
    uint32_t ReadUInt32();

    /** ���ĵ�
    @param [in] codecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open2(ICompressCodecsInfo* codecsInfo);

    /** ��ȡ���ͷ��
    @param [out] bh ���ؿ��ͷ������
    */
    void ReadBlockHeader(RCNsisBlockHeader& bh);

    /** ��ȡascii�ַ���
    @param [in] pos ƫ��
    @return ����ascii�ַ���
    */
    RCStringA ReadStringA(uint32_t pos) const;

    /** ��ȡunicode�ַ���
    @param [in] pos ƫ��
    @return ����unicode�ַ���
    */
    RCString ReadStringU(uint32_t pos) const;

    /** ��ȡ�ַ���
    @param [in] pos ƫ��
    @return �����ַ���
    */
    RCStringA ReadString2A(uint32_t pos) const;

    /** ��ȡ�ַ���
    @param [in] pos ƫ��
    @return �����ַ���
    */
    RCString ReadString2U(uint32_t pos) const;

    /** ��ȡ�ַ���
    @param [in] pos ƫ��
    @return �����ַ���
    */
    RCStringA ReadString2(uint32_t pos) const;

    /** ��ȡ�ַ���
    @param [in] pos ƫ��
    @return �����ַ���
    */
    RCStringA ReadString2Qw(uint32_t pos) const;

    /** ��ȡ���
    @param [in] bh ���ͷ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadEntries(const RCNsisBlockHeader& bh);

    /** ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Parse();

public:

    /** ��ƫ��
    */
    uint64_t m_streamOffset;

    /** nsid������
    */
    RCNsisDecode m_decoder;

    /** nsis��
    */
    RCVector<RCNsisItem> m_items;

    /** ��һ��ͷ��
    */
    RCNsisFirstHeader m_firstHeader;

    /** ѹ������
    */
    RCNsisMethodType::EEnum m_method;

    /** �ֵ��С
    */
    uint32_t m_dictionarySize;

    /** �Ƿ��ǹ�ʵ
    */
    bool m_isSolid;

    /** �Ƿ��ù���
    */
    bool m_useFilter;

    /** ���˱�־ 
    */
    bool m_filterFlag;

    /** �Ƿ���unicode
    */
    bool m_isUnicode;

#ifdef NSIS_SCRIPT

    /** �ű�
    */
    RCStringA m_script;

#endif

private:

    /** �ĵ���С
    */
    uint64_t m_archiveSize;

    /** ������
    */
    IInStreamPtr m_stream;

    /** ����
    */
    RCByteBuffer m_data;

    /** ��С
    */
    uint64_t m_size;

    /** ����λ��
    */
    size_t m_posInData;

    /** �ַ�λ��
    */
    uint32_t m_stringsPos;

    /** ͷ���Ƿ�ѹ��
    */
    bool m_headerIsCompressed;

    /**  �޹�ʵ��ʼƫ��
    */
    uint32_t m_nonSolidStartOffset;
};

END_NAMESPACE_RCZIP

#endif //__RCNsisIn_h_
