/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCGZipDefs_h_
#define __RCGZipDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCGZipDefs
{
public:

    /** algo 1
    */
    static const uint32_t s_algo1 = 0;

    /** algo 5
    */
    static const uint32_t s_algo5 = 1;

    /** passes 1
    */
    static const uint32_t s_passes1  = 1;

    /** passes 7
    */
    static const uint32_t s_passes7  = 3;

    /** passes 9
    */
    static const uint32_t s_passes9  = 10;

    /** fastbytes 1
    */
    static const uint32_t s_fastBytes1 = 32;

    /** fastbytes 7
    */
    static const uint32_t s_fastBytes7 = 64;

    /** fastbytes 9
    */
    static const uint32_t s_fastBytes9 = 128;
};

END_NAMESPACE_RCZIP

#endif //__RCGZipDefs_h_
