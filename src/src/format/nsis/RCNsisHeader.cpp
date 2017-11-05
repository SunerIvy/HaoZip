/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/nsis/RCNsisHeader.h"

/////////////////////////////////////////////////////////////////
//RCNsisHeader class implementation

BEGIN_NAMESPACE_RCZIP

namespace RCNsisSignature
{
    byte_t kSignature[kSignatureSize] = 
    { 
        0xEF + 1, 0xBE, 0xAD, 0xDE, 0x4E, 0x75, 0x6C, 0x6C, 
        0x73, 0x6F, 0x66, 0x74, 0x49, 0x6E, 0x73, 0x74
    };

    class RCSignatureInitializer 
    {
    public:

        RCSignatureInitializer() 
        { 
            kSignature[0]--; 
        } 
    };

    static RCSignatureInitializer g_signatureInitializer;
}

END_NAMESPACE_RCZIP
