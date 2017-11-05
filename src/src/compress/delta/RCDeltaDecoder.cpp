/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/delta/RCDeltaDecoder.h"

/////////////////////////////////////////////////////////////////
//RCDeltaDecoder class implementation

BEGIN_NAMESPACE_RCZIP

HResult RCDeltaDecoder::Init()
{
    DeltaInit();
    return RC_S_OK;
}

uint32_t RCDeltaDecoder::Filter(byte_t* data, uint32_t size)
{
    Delta_Decode(m_state, m_delta, data, size);
    return size;
}

HResult RCDeltaDecoder::SetDecoderProperties2(const byte_t* data, uint32_t size)
{
    if (size != 1)
    {
        return RC_E_INVALIDARG;
    }
    m_delta = (unsigned)data[0] + 1;
    return RC_S_OK;
}

END_NAMESPACE_RCZIP
