/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCNsisHeader_h_
#define __RCNsisHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace RCNsisSignature
{
    const int kSignatureSize = 16;

    extern byte_t kSignature[kSignatureSize];
}

namespace RCNsisHeader
{
    const uint32_t kFlagsMask = 0xF ;

    namespace NFlags
    {
        const uint32_t kUninstall = 1 ;
        const uint32_t kSilent    = 2 ;
        const uint32_t kNoCrc     = 4 ; 
        const uint32_t kForceCrc  = 8 ; 
    }
}

END_NAMESPACE_RCZIP

#endif //__RCNsisHeader_h_
