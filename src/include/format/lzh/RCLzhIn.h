/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhIn_h_
#define __RCLzhIn_h_ 1

#include "interface/IStream.h"
#include "RCLzhItem.h"

BEGIN_NAMESPACE_RCZIP

class RCLzhIn
{
public:

    /** ���ĵ�
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream);

    /** ��ȡ��һ����
    @param [out] filled �Ƿ������
    @param [out] item ������һ��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult GetNextItem(bool& filled, RCLzhItemEx& item);

    /** ����
    @param [in] numBytes �������ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Skip(uint64_t numBytes);

private:

    /** ��ȡ���ֽ�
    @param [out] data ��Ŷ�ȡ����Ļ�������ַ
    @param [in] size �������ĳ���
    @param [out] processedSize ����ʵ�ʶ�ȡ�ĳ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadBytes(void* data, uint32_t size, uint32_t& processedSize);

    /** ����ȡ���ֽ�
    @param [out] data ��Ŷ�ȡ����Ļ�������ַ
    @param [in] size �������ĳ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CheckReadBytes(void* data, uint32_t size);

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** ƫ��λ��
    */
    uint64_t m_position;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhIn_h_
