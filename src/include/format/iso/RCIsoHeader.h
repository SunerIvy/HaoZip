/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIsoHeader_h_
#define __RCIsoHeader_h_ 1

#include "base/RCTypes.h"

BEGIN_NAMESPACE_RCZIP

class RCIsoHeaderDefs
{
public:

    /** ����������
    */
    enum NVolDescType
    {
        kBootRecord = 0,
        kPrimaryVol = 1,
        kSupplementaryVol = 2,
        kVolParttition = 3,
        kTerminator = 255
    };

    enum
    {
        kVersion = 1
    };

    enum NFileFlags
    {
        kDirectory = 1 << 1
    };

    static const uint32_t kStartPos = 0x8000;

    /** �������id
    */
    enum NBootEntryId
    {
        kValidationEntry = 1,
        kInitialEntryNotBootable = 0,
        kInitialEntryBootable = 0x88
    };

    /** ����ƽ̨id
    */
    enum NBootPlatformId
    {
        kX86 = 0,
        kPowerPC = 1,
        kMac = 2
    };

    static const byte_t kBootMediaTypeMask = 0xF;

    /** ����ý������
    */
    enum NBootMediaType
    {
        kNoEmulation = 0,
        k1d2Floppy = 1,
        k1d44Floppy = 2,
        k2d88Floppy = 3,
        kHardDisk = 4
    };

    static const int32_t kNumBootMediaTypes = 5;

    static const char *kElToritoSpec;

    static const wchar_t *kMediaTypes[];
};

END_NAMESPACE_RCZIP

#endif //__RCIsoHeader_h_
