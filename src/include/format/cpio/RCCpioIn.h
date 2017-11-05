/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCpioIn_h_
#define __RCCpioIn_h_ 1

#include "interface/IStream.h"
#include "RCCpioHeader.h"
#include "RCCpioItem.h"

BEGIN_NAMESPACE_RCZIP

static const uint32_t s_maxBlockSize = RCCpioHeader::kRecordSize;

class RCCpioIn
{
public:

    /** ��
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult Open(IInStream* inStream);

    /** ��ȡ����
    @param [in] filled �Ƿ��ȡ�ɹ�
    @param [out] itemInfo ��ȡ������������
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult GetNextItem(bool& filled, RCCpioItemEx& itemInfo);

    /** ����
    @param [in] numBytes ���������ֽ�
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult Skip(uint64_t numBytes);

    /** �������ݼ�¼
    @param [in] dataSize ���ݴ�С
    @param [in] align �����ֽ�
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult SkipDataRecords(uint64_t dataSize, uint32_t align);

private:

    /** ��ȡ�ֽ�
    @return ���ض�ȡ���ֽڣ����ʧ�ܷ���0xFF
    @throws �����ȡ����ʧ�����쳣
    */
    byte_t ReadByte();

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32();

    /** ��ȡ�˸��ֽ�ת��ʮ����������
    @param [in] resultValue ����ʮ����������
    @return �ɹ�����true�����򷵻�false
    */
    bool ReadNumber(uint32_t& resultValue);

    /** ��ȡ�ĸ��ֽ�ת��ʮ��������
    @param [in] size ��ȡ����λ
    @param [in] resultValue ����ʮ��������
    @return �ɹ�����true�����򷵻�false
    */
    bool ReadOctNumber(int32_t size, uint32_t& resultValue);

    /** ��ȡ���ֽ�
    @param [out] data ��Ŷ�ȡ����Ļ�������ַ
    @param [in] size �������ĳ���
    @param [in] processedSize ����ʵ�ʶ����Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadBytes(void* data, uint32_t size, uint32_t& processedSize);

private:

    /** ������
    */
    IInStreamPtr m_inStream;

    /** λ��
    */
    uint64_t m_position;

    /** ���С
    */
    uint16_t m_blockSize;

    /** ��
    */
    byte_t m_block[s_maxBlockSize];

    /** ��λ��
    */
    uint32_t m_blockPos;
};

END_NAMESPACE_RCZIP

#endif //__RCCpioIn_h_
