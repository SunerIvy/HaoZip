/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/copy/RCCopyCoderInfo.h"
#include "compress/copy/RCCopyCoder.h"
#include "interface/ICoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCCopyCoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

void* CopyCoderCreateCodecFunc(void)
{
    return (void*)(ICompressCoder*)(new RCCopyCoder);
}

RCCopyCoderInfo::RCCopyCoderInfo()
{
}

RCCopyCoderInfo::~RCCopyCoderInfo()
{
}

PFNCreateCodec RCCopyCoderInfo::GetCreateDecoderFunc(void) const
{
    return CopyCoderCreateCodecFunc ;
}

RC_IID RCCopyCoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressCoder ;
}

PFNCreateCodec RCCopyCoderInfo::GetCreateEncoderFunc(void) const
{
    return CopyCoderCreateCodecFunc ;
}

RC_IID RCCopyCoderInfo::GetEncoderIID(void) const
{
    return IID_ICompressCoder ;
}

RCMethodID RCCopyCoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_COMPRESS_COPY ;
}

RCString RCCopyCoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_COMPRESS_COPY ;
}

uint32_t RCCopyCoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCCopyCoderInfo::IsFilter(void) const 
{
    return false ;
}

uint32_t RCCopyCoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCCopyCoderInfo::IsEncoderAssigned(void) const
{
    return true ;
}
    
bool RCCopyCoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCCopyCoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
