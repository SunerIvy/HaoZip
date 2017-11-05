/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/byteswap/RCByteSwap4.h"

/////////////////////////////////////////////////////////////////
//RCByteSwap4 class implementation

BEGIN_NAMESPACE_RCZIP

RCByteSwap4::RCByteSwap4()
{
}

RCByteSwap4::~RCByteSwap4()
{
}

HResult RCByteSwap4::Init()
{
    return RC_S_OK ;
}

uint32_t RCByteSwap4::Filter(byte_t* data, uint32_t size)
{
    const uint32_t kStep = 4;
    uint32_t i = 0 ;
    byte_t b0 = 0 ;
    byte_t b1 = 0 ;
    for (i = 0; i + kStep <= size; i += kStep)
    {
        b0 = data[i];
        b1 = data[i + 1];
        data[i] = data[i + 3];
        data[i + 1] = data[i + 2];
        data[i + 2] = b1;
        data[i + 3] = b0;
    }
    return i ;
}

END_NAMESPACE_RCZIP
