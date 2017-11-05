/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchBCJ2ImplDefs_h_
#define __RCBranchBCJ2ImplDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

inline bool IsJcc(byte_t b0, byte_t b1)
{
    return (b0 == 0x0F && (b1 & 0xF0) == 0x80);
}

inline bool IsJ(byte_t b0, byte_t b1)
{
    return ((b1 & 0xFE) == 0xE8 || IsJcc(b0, b1));
}

inline uint32_t GetIndex(byte_t b0, byte_t b1)
{
    return ((b1 == 0xE8) ? b0 : ((b1 == 0xE9) ? 256 : 257));
}

inline bool Test86MSByte(byte_t b)
{
  return (b == 0 || b == 0xFF);
}

static const int kBufferSize = 1 << 17 ;
static const uint32_t kDefaultLimit = (1 << 24) ;

END_NAMESPACE_RCZIP

#endif //__RCBranchBCJ2ImplDefs_h_
