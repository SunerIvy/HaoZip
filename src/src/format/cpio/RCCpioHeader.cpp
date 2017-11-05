/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/cpio/RCCpioHeader.h"

/////////////////////////////////////////////////////////////////
//RCCpioHeader class implementation

BEGIN_NAMESPACE_RCZIP

namespace RCCpioHeader 
{
    namespace NMagic
    {
        const char* kMagic1 = "070701";
        const char* kMagic2 = "070702";
        const char* kMagic3 = "070707";
        const char* kEndName = "TRAILER!!!";
        const byte_t kMagicForRecord2[2] = { 0xC7, 0x71 };
    }

}

END_NAMESPACE_RCZIP
