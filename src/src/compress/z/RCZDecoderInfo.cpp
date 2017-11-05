/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/z/RCZDecoderInfo.h"
#include "compress/z/RCZDecoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCZDecoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

void* ZDecoderCreateCodecFunc(void)
{
    return (void*)(ICompressCoder*)(new RCZDecoder);
}

RCZDecoderInfo::RCZDecoderInfo()
{
}

RCZDecoderInfo::~RCZDecoderInfo()
{
}

PFNCreateCodec RCZDecoderInfo::GetCreateDecoderFunc(void) const
{
    return ZDecoderCreateCodecFunc ;
}

RC_IID RCZDecoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressCoder ;
}

PFNCreateCodec RCZDecoderInfo::GetCreateEncoderFunc(void) const
{
    return NULL ;
}

RC_IID RCZDecoderInfo::GetEncoderIID(void) const
{
    return (RC_IID)IID_INVALID ;
}

RCMethodID RCZDecoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_COMPRESS_Z ;
}

RCString RCZDecoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_COMPRESS_Z ;
}

uint32_t RCZDecoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCZDecoderInfo::IsFilter(void) const 
{
    return false ;
}

uint32_t RCZDecoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCZDecoderInfo::IsEncoderAssigned(void) const
{
    return false ;
}
    
bool RCZDecoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCZDecoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
