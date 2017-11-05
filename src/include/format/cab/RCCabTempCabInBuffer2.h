/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabTempCabInBuffer2_h_
#define __RCCabTempCabInBuffer2_h_ 1

#include "base/RCTypes.h"

BEGIN_NAMESPACE_RCZIP

class RCCabTempCabInBuffer2
{
public:

    /** ��ȡ�ֽ�
    @return ���ض�ȡ�ֽ�ֵ
    */
    byte_t ReadByte();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32();

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16();

public:

    /** ���ݿ�ͷ����С
    */
    static const uint32_t s_dataBlockHeaderSize = 8;

    /** ������ݿ�ͷ���Ļ�����
    */
    byte_t m_buffer[s_dataBlockHeaderSize];

    /** λ��
    */
    uint32_t m_pos;
};

END_NAMESPACE_RCZIP

#endif //__RCCabTempCabInBuffer2_h_