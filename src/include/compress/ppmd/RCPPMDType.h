/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDType_h_
#define __RCPPMDType_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

const int32_t kMaxOrderCompress = 32 ;

/** maximum allowed model order
*/
const int32_t MAX_O = 255 ; 

template <class T>
inline void _PPMD_SWAP(T& t1, T& t2)
{
    T tmp = t1 ; 
    t1 = t2 ; 
    t2 = tmp ;
}

END_NAMESPACE_RCZIP

#endif //__RCPPMDType_h_
