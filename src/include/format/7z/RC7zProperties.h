/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zProperties_h_
#define __RC7zProperties_h_ 1

#include "interface/RCPropertyID.h"

BEGIN_NAMESPACE_RCZIP

class RC7zPropID
{
public:

    enum
    {
        kpidPackedSize0 = RCPropID::kpidUserDefined,
        kpidPackedSize1,
        kpidPackedSize2,
        kpidPackedSize3,
        kpidPackedSize4
    };
};

END_NAMESPACE_RCZIP

#endif //__RC7zProperties_h_
