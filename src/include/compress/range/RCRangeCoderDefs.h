/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeCoderDefs_h_
#define __RCRangeCoderDefs_h_ 1

#include "base/RCDefs.h"
#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

/** Range ���볣������
*/
class RCRangeCoderDefs
{
public:

    static const int32_t    s_kNumTopBits = 24 ;
    static const uint32_t   s_kTopValue = (1 << s_kNumTopBits) ;
    
    static const int32_t    s_kNumBitModelTotalBits  = 11;
    static const uint32_t   s_kBitModelTotal = (1 << s_kNumBitModelTotalBits);
    static const int32_t    s_kNumMoveReducingBits = 4;
    static const int32_t    s_kNumBitPriceShiftBits = 4;
    static const uint32_t   s_kBitPrice = 1 << s_kNumBitPriceShiftBits;
    static uint32_t         s_probPrices[s_kBitModelTotal >> s_kNumMoveReducingBits] ;
    
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCRangeCoderDefs() ;
    
    /** Ĭ����������
    */
    ~RCRangeCoderDefs() ;    
};

typedef RCSingleton<RCRangeCoderDefs> RCRangeCoderInit ;

END_NAMESPACE_RCZIP

#endif //__RCRangeCoderDefs_h_
