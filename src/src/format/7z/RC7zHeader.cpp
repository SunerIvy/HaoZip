/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/7z/RC7zHeader.h"

/////////////////////////////////////////////////////////////////
//RC7zHeader class implementation

BEGIN_NAMESPACE_RCZIP

byte_t RC7zHeader::s_k7zSignature[RC7zHeader::s_k7zSignatureSize] =
        {'7' + 1, 'z', 0xBC, 0xAF, 0x27, 0x1C} ;

#ifdef _7Z_VOL
byte_t RC7zHeader::s_k7zFinishSignature[RC7zHeader::s_k7zSignatureSize] = 
        {'7' + 1, 'z', 0xBC, 0xAF, 0x27, 0x1C + 1};
#endif

namespace RC7zSignature
{
    class RCMarkersInitializer
    {
    public:
        RCMarkersInitializer()
        {
            RC7zHeader::s_k7zSignature[0]--;
#ifdef _7Z_VOL
            RC7zHeader::s_k7zFinishSignature[0]--;
#endif
        };
    };
   
    static RCMarkersInitializer g_markerInitializer;
}


END_NAMESPACE_RCZIP
