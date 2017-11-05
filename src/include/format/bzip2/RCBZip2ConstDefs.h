/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2ConstDefs_h_
#define __RCBZip2ConstDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCBZip2ConstDefs
{
public:

    /** bzip2 passes x1
    */
    static const uint32_t s_bzip2NumPassesX1 = 1;

    /** bzip2 passes x7
    */
    static const uint32_t s_bzip2NumPassesX7 = 2;

    /** bzip2 passes x9
    */
    static const uint32_t s_bzip2NumPassesX9 = 7;

    /** bzip2 �ֵ��С x1
    */
    static const uint32_t s_bzip2DicSizeX1 = 100000;

    /** bzip2 �ֵ��С x3
    */
    static const uint32_t s_bzip2DicSizeX3 = 500000;

    /** bzip2 �ֵ��С x5
    */
    static const uint32_t s_bzip2DicSizeX5 = 900000;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2ConstDefs_h_
