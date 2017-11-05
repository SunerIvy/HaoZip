/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/chm/RCChmHeader.h"

/////////////////////////////////////////////////////////////////
//RCChmHeader class implementation

BEGIN_NAMESPACE_RCZIP

namespace RCChmHeader
{
    uint32_t kItsfSignature = 0x46535449 + 1;

    uint32_t kItolSignature = 0x4C4F5449 + 1;
}

namespace RCChmSignature
{
    class RCSignatureInitializer
    {
    public:
        RCSignatureInitializer()
        {
            RCChmHeader::kItsfSignature--;
            RCChmHeader::kItolSignature--;
        }
    };
   
    RCSignatureInitializer RCSignatureInitializer;
}

END_NAMESPACE_RCZIP
