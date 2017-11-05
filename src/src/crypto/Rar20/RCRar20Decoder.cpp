/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/Rar20/RCRar20Decoder.h"

/////////////////////////////////////////////////////////////////
//RCRar20Decoder class implementation

BEGIN_NAMESPACE_RCZIP

RCRar20Decoder::RCRar20Decoder()
{
}

RCRar20Decoder::~RCRar20Decoder()
{
}

HResult RCRar20Decoder::Init() 
{
    return RC_S_OK ;
}

uint32_t RCRar20Decoder::Filter(byte_t* data, uint32_t size)
{
    const uint16_t kBlockSize = 16;
    if (size > 0 && size < kBlockSize)
    {
        return kBlockSize;
    }
    uint32_t i = 0 ;
    for (i = 0; i + kBlockSize <= size; i += kBlockSize)
    {
        m_coder.DecryptBlock(data + i);
     }
    return i ;
}

HResult RCRar20Decoder::CryptoSetPassword(const byte_t* data, uint32_t size)
{
    m_coder.SetPassword(data, size);
    return RC_S_OK ;
}

END_NAMESPACE_RCZIP
