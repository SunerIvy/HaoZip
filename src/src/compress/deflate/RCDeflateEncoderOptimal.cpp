/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateEncoderOptimal.h"

/////////////////////////////////////////////////////////////////
//RCDeflateEncoderOptimal class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateEncoderOptimal::RCDeflateEncoderOptimal():
    m_price(0),
    m_posPrev(0),
    m_backPrev(0)
{
}

RCDeflateEncoderOptimal::~RCDeflateEncoderOptimal()
{
}

END_NAMESPACE_RCZIP
