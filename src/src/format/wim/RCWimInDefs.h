/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimInDefs_h_
#define __RCWimInDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

static const int32_t  s_kWimChunkSizeBits = 15;
static const uint32_t s_kWimChunkSize = (1 << s_kWimChunkSizeBits);

END_NAMESPACE_RCZIP

#endif //__RCWimInDefs_h_
