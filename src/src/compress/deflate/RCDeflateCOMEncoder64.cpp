/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateCOMEncoder64.h"

/////////////////////////////////////////////////////////////////
//RCDeflateCOMEncoder64 class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateCOMEncoder64::RCDeflateCOMEncoder64():
    RCDeflateEncoder(true)
{
}

RCDeflateCOMEncoder64::~RCDeflateCOMEncoder64()
{
}

HResult RCDeflateCOMEncoder64::Code(ISequentialInStream* inStream,
                                  ISequentialOutStream* outStream, 
                                  const uint64_t* inSize, 
                                  const uint64_t* outSize,
                                  ICompressProgressInfo* progress)
{
    return BaseCode(inStream, outStream, inSize, outSize, progress) ;
}

HResult RCDeflateCOMEncoder64::SetCoderProperties(const RCPropertyIDPairArray& propertyArray)
{
    return BaseSetEncoderProperties2(propertyArray);
}

END_NAMESPACE_RCZIP
