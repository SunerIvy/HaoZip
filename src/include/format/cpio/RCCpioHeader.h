/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCpioHeader_h_
#define __RCCpioHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace RCCpioHeader
{
    namespace NMagic
    {
        extern const char* kMagic1 ;
        extern const char* kMagic2 ;
        extern const char* kMagic3 ;
        extern const char* kEndName ;
        extern const byte_t kMagicForRecord2[2] ;
    }

    const uint32_t kRecord2Size     = 26 ;
    const uint32_t kRecordSize      = 110 ;
    const uint32_t kOctRecordSize   = 76 ;
}

END_NAMESPACE_RCZIP

#endif //__RCCpioHeader_h_
