/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/cab/RCCabTempCabInBuffer2.h"

BEGIN_NAMESPACE_RCZIP

byte_t RCCabTempCabInBuffer2::ReadByte()
{
    return m_buffer[m_pos++];
}

uint32_t RCCabTempCabInBuffer2::ReadUInt32()
{
    uint32_t value = 0;
    for (int32_t i = 0; i < 4; i++)
    {
        value |= (((uint32_t)ReadByte()) << (8 * i));
    }
    return value;
}

uint16_t RCCabTempCabInBuffer2::ReadUInt16()
{
    uint16_t value = 0;
    for (int32_t i = 0; i < 2; i++)
    {
        value |= (((uint16_t)ReadByte()) << (8 * i));
    }
    return value;
}

END_NAMESPACE_RCZIP
