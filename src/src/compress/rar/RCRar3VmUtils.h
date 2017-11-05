/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3VmUtils_h_
#define __RCRar3VmUtils_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RCRar3VmMemBitDecoder ;

class RCRar3VmUtils:
    private RCNonCopyable
{
public:

    static uint32_t GetValue32(const void* addr) ;
    static void SetValue32(void* addr, uint32_t value) ;
    static uint32_t ReadEncodedUInt32(RCRar3VmMemBitDecoder& inp) ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar3VmUtils_h_
