/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeBitDecoder_h_
#define __RCRangeBitDecoder_h_ 1

#include "compress/range/RCRangeBitModel.h"
#include "compress/range/RCRangeDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Range Bit ������
*/
template <int32_t numMoveBits>
class RCRangeBitDecoder:
    public RCRangeBitModel<numMoveBits>
{
public:

    /** ����
    @param [in] decoder ������
    @return ���ؽ����ֽ���
    */
    uint32_t Decode(RCRangeDecoder *decoder) ;
};

END_NAMESPACE_RCZIP

#include "RCRangeBitDecoder.inl"

#endif //__RCRangeBitDecoder_h_
