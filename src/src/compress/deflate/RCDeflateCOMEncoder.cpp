/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateCOMEncoder.h"

/////////////////////////////////////////////////////////////////
//RCDeflateCOMEncoder class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateCOMEncoder::RCDeflateCOMEncoder():
    RCDeflateEncoder(false)
{
}

RCDeflateCOMEncoder::~RCDeflateCOMEncoder()
{
}

HResult RCDeflateCOMEncoder::Code(ISequentialInStream* inStream,
                                  ISequentialOutStream* outStream, 
                                  const uint64_t* inSize, 
                                  const uint64_t* outSize,
                                  ICompressProgressInfo* progress)
{
    return BaseCode(inStream, outStream, inSize, outSize, progress) ;
}

HResult RCDeflateCOMEncoder::SetCoderProperties(const RCPropertyIDPairArray& propertyArray)
{
    return BaseSetEncoderProperties2(propertyArray);
}

END_NAMESPACE_RCZIP
