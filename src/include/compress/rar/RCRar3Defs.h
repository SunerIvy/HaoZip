/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3Defs_h_
#define __RCRar3Defs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** RAR3 ��������
*/
class RCRar3Defs
{
public:
    static const uint32_t s_kWindowSize = 1 << 22;
    static const uint32_t s_kWindowMask = (s_kWindowSize - 1);
    static const uint32_t s_kNumReps = 4;
    static const uint32_t s_kNumLen2Symbols = 8;
    static const uint32_t s_kLenTableSize = 28;
    static const uint32_t s_kMainTableSize = 256 + 1 + 1 + 1 + s_kNumReps + s_kNumLen2Symbols + s_kLenTableSize;
    static const uint32_t s_kDistTableSize = 60;
    static const int32_t  s_kNumAlignBits = 4;
    static const uint32_t s_kAlignTableSize = (1 << s_kNumAlignBits) + 1;
    static const uint32_t s_kLevelTableSize = 20;
    static const uint32_t s_kTablesSizesSum = s_kMainTableSize + s_kDistTableSize + s_kAlignTableSize + s_kLenTableSize;
    static const int32_t  s_kNumTopBits = 24;
    static const uint32_t s_kTopValue = (1 << s_kNumTopBits);
    static const uint32_t s_kBot = (1 << 15);
};

END_NAMESPACE_RCZIP

#endif //__RCRar3Defs_h_
