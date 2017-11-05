/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/zip/RCZipHeader.h"

/////////////////////////////////////////////////////////////////
//RCZipHeader class implementation

BEGIN_NAMESPACE_RCZIP

namespace RCZipSignature
{
    uint32_t kLocalFileHeader             = 0x04034B50 + 1;
    uint32_t kDataDescriptor              = 0x08074B50 + 1;
    uint32_t kCentralFileHeader           = 0x02014B50 + 1;
    uint32_t kEndOfCentralDir             = 0x06054B50 + 1;
    uint32_t kZip64EndOfCentralDir        = 0x06064B50 + 1;
    uint32_t kZip64EndOfCentralDirLocator = 0x07064B50 + 1;
    uint32_t kZipSingleVolumeSignature      = 0x03034B50 + 1;

    class RCMarkersInitializer
    {
    public:
        RCMarkersInitializer()
        {
            kLocalFileHeader--;
            kDataDescriptor--;
            kCentralFileHeader--;
            kEndOfCentralDir--;
            kZip64EndOfCentralDir--;
            kZip64EndOfCentralDirLocator--;
            kZipSingleVolumeSignature--;
        }
    };

    static RCMarkersInitializer g_markerInitializer;
}

END_NAMESPACE_RCZIP
