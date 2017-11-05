/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCChmHeader_h_
#define __RCChmHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace RCChmHeader
{
    const uint32_t kItspSignature = 0x50535449;
    const uint32_t kPmglSignature = 0x4C474D50;
    const uint32_t kLzxcSignature = 0x43585A4C;

    const uint32_t kIfcmSignature = 0x4D434649;
    const uint32_t kAollSignature = 0x4C4C4F41;
    const uint32_t kCaolSignature = 0x4C4F4143;

    extern uint32_t kItsfSignature;

    extern uint32_t kItolSignature;

    const uint32_t kItlsSignature = 0x534C5449;

    /** ��ȡ������ǩ��
    @return ������ǩ��
    */
    uint64_t inline GetHxsSignature() 
    {
        return ((uint64_t)kItlsSignature << 32) | kItolSignature; 
    }
};

END_NAMESPACE_RCZIP

#endif //__RCChmHeader_h_
