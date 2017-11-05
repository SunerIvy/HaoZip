/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/rar/RCRarHeader.h"

/////////////////////////////////////////////////////////////////
//RCRarHeader class implementation

BEGIN_NAMESPACE_RCZIP

namespace RCRarHeader
{
    byte_t kMarker[kMarkerSize] = {0x52 + 1, 0x61, 0x72, 0x21, 0x1a, 0x07, 0x00};

    class RCMarkerInitializer
    {
    public:
        RCMarkerInitializer() { kMarker[0]--; };
    };

    static RCMarkerInitializer g_markerInitializer;
}

END_NAMESPACE_RCZIP
