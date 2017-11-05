/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDRangeDecoder_h_
#define __RCPPMDRangeDecoder_h_ 1

#include "compress/ppmd/RCPPMDRangeDecoderVirt.h"
#include "compress/range/RCRangeDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ���н�����
*/
class RCPPMDRangeDecoder:
    public RCPPMDRangeDecoderVirt,
    public RCRangeDecoder
{
public:

    /** ���ط�ֵ
    @param [in] total ����
    @return ���ط�ֵ
    */
    virtual uint32_t GetThreshold(uint32_t total) ;

    /** ����
    @param [in] start ��ʼ
    @param [in] size ��С
    */
    virtual void Decode(uint32_t start, uint32_t size) ;

    /** λ����
    @param [in] size0 ��С
    @param [in] numTotalBits λ��
    */
    virtual uint32_t DecodeBit(uint32_t size0, uint32_t numTotalBits) ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDRangeDecoder_h_
