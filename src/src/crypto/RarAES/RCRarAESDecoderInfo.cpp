/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/RarAES/RCRarAESDecoderInfo.h"
#include "crypto/RarAES/RCRarAESDecoder.h"
#include "interface/ICoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCRarAESDecoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

/** �����������ĺ���
*/
void* RCRarAESCreateDecoder()
{
    return (ICompressFilter*)(new RCRarAESDecoder) ;
}

RCRarAESDecoderInfo::RCRarAESDecoderInfo()
{
}

RCRarAESDecoderInfo::~RCRarAESDecoderInfo()
{
}

PFNCreateCodec RCRarAESDecoderInfo::GetCreateDecoderFunc(void) const
{
    return RCRarAESCreateDecoder ;
}

RC_IID RCRarAESDecoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressFilter ;
}

PFNCreateCodec RCRarAESDecoderInfo::GetCreateEncoderFunc(void) const
{
    return NULL ;
}

RC_IID RCRarAESDecoderInfo::GetEncoderIID(void) const
{
    return (RC_IID)IID_INVALID ;
}

RCMethodID RCRarAESDecoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_CRYPTO_RAR_29 ;
}

RCString RCRarAESDecoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_CRYPTO_RAR_29 ;
}

uint32_t RCRarAESDecoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCRarAESDecoderInfo::IsFilter(void) const 
{
    return true ;
}

uint32_t RCRarAESDecoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCRarAESDecoderInfo::IsEncoderAssigned(void) const
{
    return false ;
}
    
bool RCRarAESDecoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCRarAESDecoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
