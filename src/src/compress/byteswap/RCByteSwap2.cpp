/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/byteswap/RCByteSwap2.h"

/////////////////////////////////////////////////////////////////
//RCByteSwap2 class implementation

BEGIN_NAMESPACE_RCZIP

RCByteSwap2::RCByteSwap2()
{
}

RCByteSwap2::~RCByteSwap2()
{
}

HResult RCByteSwap2::Init()
{
    return RC_S_OK ;
}

uint32_t RCByteSwap2::Filter(byte_t* data, uint32_t size)
{
    const uint32_t kStep = 2;
    uint32_t i = 0 ;
    byte_t b = 0 ;
    for (i = 0; i + kStep <= size; i += kStep)
    {
        b = data[i];
        data[i] = data[i + 1];
        data[i + 1] = b;
    }
    return i ;
}

END_NAMESPACE_RCZIP
