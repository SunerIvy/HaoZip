/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDmgDefs_h_
#define __RCDmgDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCDmgDefs
{
public:

    enum
    {
        METHOD_ZERO_0 = 0,
        METHOD_COPY   = 1,
        METHOD_ZERO_2 = 2,
        METHOD_ADC    = 0x80000004,
        METHOD_ZLIB   = 0x80000005,
        METHOD_BZIP2  = 0x80000006,
        METHOD_DUMMY  = 0x7FFFFFFE,
        METHOD_END    = 0xFFFFFFFF
    };
};

END_NAMESPACE_RCZIP

#endif //__RCDmgDefs_h_
