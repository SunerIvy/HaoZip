/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeBitEncoder_h_
#define __RCRangeBitEncoder_h_ 1

#include "compress/range/RCRangeBitModel.h"
#include "compress/range/RCRangeEncoder.h"

BEGIN_NAMESPACE_RCZIP

/** Range Bit ������
*/
template <int32_t numMoveBits>
class RCRangeBitEncoder:
    public RCRangeBitModel<numMoveBits>
{
public:

    /** ����
    @param [in] encoder ������
    @param [in] symbol ����
    */
    void Encode(RCRangeEncoder* encoder, uint32_t symbol) ;

    /** ����Ȩ��
    @param [in] symbol ����
    @return ����Ȩ��
    */
    uint32_t GetPrice(uint32_t symbol) const ;

    /** ����Ȩ��
    @return ����Ȩ��
    */
    uint32_t GetPrice0() const ;

    /** ����Ȩ��
    @return ����Ȩ��
    */
    uint32_t GetPrice1() const ;    
};

END_NAMESPACE_RCZIP

#include "RCRangeBitEncoder.inl"

#endif //__RCRangeBitEncoder_h_
