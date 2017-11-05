/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateEncoderValue.h"

/////////////////////////////////////////////////////////////////
//RCDeflateEncoderValue class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateEncoderValue::RCDeflateEncoderValue():
    m_len(0),
    m_pos(0)
{
}

RCDeflateEncoderValue::~RCDeflateEncoderValue()
{
}

void RCDeflateEncoderValue::SetAsLiteral()
{
    m_len = (1 << 15);
}

bool RCDeflateEncoderValue::IsLiteral() const
{
    return (m_len >= (1 << 15));
}

END_NAMESPACE_RCZIP
