/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/lzh/RCLzhCRC.h"

/////////////////////////////////////////////////////////////////
//RCLzhCRC class implementation

BEGIN_NAMESPACE_RCZIP

static const uint16_t s_crcPoly = 0xA001;

uint16_t RCLzhCRC::s_table[256];

void RCLzhCRC::InitTable()
{
    for (uint32_t i = 0; i < 256; i++)
    {
        uint32_t r = i;
        for (int32_t j = 0; j < 8; j++)
        {
            if (r & 1)
            {
                r = (r >> 1) ^ s_crcPoly;
            }
            else
            {
                r >>= 1;
            }
        }
        RCLzhCRC::s_table[i] = (uint16_t)r;
    }
}

class CCRCTableInit
{
public:

    /** Ĭ�Ϲ��캯��
    */
    CCRCTableInit() 
    { 
        RCLzhCRC::InitTable();
    }

}g_crcTableInit;

void RCLzhCRC::Update(const void *data, size_t size)
{
    uint16_t v = m_value;
    const byte_t* p = (const byte_t *)data;
    for (; size > 0; size--, p++)
    {
        v = (uint16_t)(s_table[((byte_t)(v)) ^ *p] ^ (v >> 8));
    }
    m_value = v;
}

END_NAMESPACE_RCZIP
