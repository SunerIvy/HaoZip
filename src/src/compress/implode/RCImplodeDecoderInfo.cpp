/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/implode/RCImplodeDecoderInfo.h"
#include "compress/implode/RCImplodeDecoder.h"
#include "interface/ICoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCImplodeDecoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

void* ImplodeDecoderCreateCodecFunc(void)
{
    return (void*)(ICompressCoder*)(new RCImplodeDecoder);
}

RCImplodeDecoderInfo::RCImplodeDecoderInfo()
{
}

RCImplodeDecoderInfo::~RCImplodeDecoderInfo()
{
}

PFNCreateCodec RCImplodeDecoderInfo::GetCreateDecoderFunc(void) const
{
    return ImplodeDecoderCreateCodecFunc ;
}

RC_IID RCImplodeDecoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressCoder ;
}

PFNCreateCodec RCImplodeDecoderInfo::GetCreateEncoderFunc(void) const
{
    return NULL ;
}

RC_IID RCImplodeDecoderInfo::GetEncoderIID(void) const
{
    return (RC_IID)IID_INVALID ;
}

RCMethodID RCImplodeDecoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_COMPRESS_IMPLODE ;
}

RCString RCImplodeDecoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_COMPRESS_IMPLODE ;
}

uint32_t RCImplodeDecoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCImplodeDecoderInfo::IsFilter(void) const 
{
    return false ;
}

uint32_t RCImplodeDecoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCImplodeDecoderInfo::IsEncoderAssigned(void) const
{
    return false ;
}
    
bool RCImplodeDecoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCImplodeDecoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
