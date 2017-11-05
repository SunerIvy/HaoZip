/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/Rar20/RCRar20DecoderInfo.h"
#include "crypto/Rar20/RCRar20Decoder.h"
#include "interface/ICoder.h"
#include "interface/RCMethodDefs.h"

/////////////////////////////////////////////////////////////////
//RCRar20DecoderInfo class implementation

BEGIN_NAMESPACE_RCZIP

/** �����������ĺ���
*/
void* RCRar20CreateDecoder()
{
    return (ICompressFilter*)(new RCRar20Decoder) ;
}

RCRar20DecoderInfo::RCRar20DecoderInfo()
{
}

RCRar20DecoderInfo::~RCRar20DecoderInfo()
{
}

PFNCreateCodec RCRar20DecoderInfo::GetCreateDecoderFunc(void) const
{
    return RCRar20CreateDecoder ;
}

RC_IID RCRar20DecoderInfo::GetDecoderIID(void) const
{
    return IID_ICompressFilter ;
}

PFNCreateCodec RCRar20DecoderInfo::GetCreateEncoderFunc(void) const
{
    return NULL ;
}

RC_IID RCRar20DecoderInfo::GetEncoderIID(void) const
{
    return (RC_IID)IID_INVALID ;
}

RCMethodID RCRar20DecoderInfo::GetMethodID(void) const
{
    return RCMethod::ID_CRYPTO_RAR_20 ;
}

RCString RCRar20DecoderInfo::GetMethodName(void) const
{
    return RC_METHOD_NAME_CRYPTO_RAR_20 ;
}

uint32_t RCRar20DecoderInfo::GetNumInStreams(void) const
{
    return 1 ;
}

bool RCRar20DecoderInfo::IsFilter(void) const 
{
    return true ;
}

uint32_t RCRar20DecoderInfo::GetNumOutStreams(void) const
{
    return 1 ;
}
    
bool RCRar20DecoderInfo::IsEncoderAssigned(void) const
{
    return false ;
}
    
bool RCRar20DecoderInfo::IsDecoderAssigned(void) const
{
    return true ;
}
    
bool RCRar20DecoderInfo::IsSimpleCodec(void) const
{
    return true ;
}

END_NAMESPACE_RCZIP
