/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhDecoderDefs_h_
#define __RCLzhDecoderDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Lzh ���볣������
*/
class RCLzhDecoderDefs
{
public:

    static const int32_t s_kMaxHuffmanLen = 16; // Check it
    static const int32_t s_kNumSpecLevelSymbols = 3;
    static const int32_t s_kNumLevelSymbols = s_kNumSpecLevelSymbols + s_kMaxHuffmanLen;
    static const int32_t s_kDictBitsMax = 16;
    static const int32_t s_kNumDistanceSymbols = s_kDictBitsMax + 1;
    static const int32_t s_kMaxMatch = 256;
    static const int32_t s_kMinMatch = 3;
    static const int32_t s_kNumCSymbols = 256 + s_kMaxMatch + 2 - s_kMinMatch;
    
    static const uint32_t s_kHistorySize = (1 << 16);
    static const int32_t s_kBlockSizeBits = 16;
    static const int32_t s_kNumCBits = 9;
    static const int32_t s_kNumLevelBits = 5;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhDecoderDefs_h_

