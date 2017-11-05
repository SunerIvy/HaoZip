/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/lzx/RCLzxDecoderInfo.h"
#include "compress/lzx/RCLzxDecoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCLzxDecoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

void* LzxDecoderCreateCodecFunc(void)
{
    return (void*)(ICompressCoder*)(new RCLzxDecoder);
}

RCLzxDecoderInfo::RCLzxDecoderInfo()
{
}

RCLzxDecoderInfo::~RCLzxDecoderInfo()
{
}

PFNCreateCodec RCLzxDecoderInfo::GetCreateDecoderFunc(void) const
{
    return LzxDecoderCreateCodecFunc ;
}

RC_IID RCLzxDecoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressCoder ;
}

PFNCreateCodec RCLzxDecoderInfo::GetCreateEncoderFunc(void) const
{
    return NULL ;
}

RC_IID RCLzxDecoderInfo::GetEncoderIID(void) const
{
    return (RC_IID)IID_INVALID ;
}

RCMethodID RCLzxDecoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_COMPRESS_LZX ;
}

RCString RCLzxDecoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_COMPRESS_LZX ;
}

uint32_t RCLzxDecoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCLzxDecoderInfo::IsFilter(void) const 
{
    return false ;
}

uint32_t RCLzxDecoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCLzxDecoderInfo::IsEncoderAssigned(void) const
{
    return false ;
}
    
bool RCLzxDecoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCLzxDecoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
