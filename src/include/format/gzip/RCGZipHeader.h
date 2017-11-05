/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCGZipHeader_h_
#define __RCGZipHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace RCGZipSignature
{
    static const uint16_t kSignature = 0x8B1F ;
}

namespace RCGZipHeader
{
    /** ��־
    */
    namespace NFlags
    {
        const byte_t kIsText  = 1 << 0;
        const byte_t kCrc     = 1 << 1;
        const byte_t kExtra   = 1 << 2;
        const byte_t kName    = 1 << 3;
        const byte_t kComment = 1 << 4;
    }

    /** ��ѹ����
    */
    namespace NExtraFlags
    {
        const byte_t kMaximum = 2;
        const byte_t kFastest = 4;
    }

    /** ѹ������
    */
    namespace NCompressionMethod
    {
        const byte_t kDeflate = 8;
    }

    /** ƽ̨ϵͳ
    */
    namespace NHostOS
    {
        enum EEnum
        {
            kFAT = 0,
            kAMIGA,
            kVMS,
            kUnix,
            kVM_CMS,
            kAtari,
            kHPFS,
            kMac,
            kZ_System,
            kCPM,
            kTOPS20,
            kNTFS,
            kQDOS,
            kAcorn,
            kVFAT,
            kMVS,
            kBeOS,
            kTandem,
            
            kUnknown = 255
        };
    }
}

END_NAMESPACE_RCZIP

#endif //__RCGZipHeader_h_
