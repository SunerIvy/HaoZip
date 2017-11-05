/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDRangeDecoderVirt_h_
#define __RCPPMDRangeDecoderVirt_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ���н���
*/
class RCPPMDRangeDecoderVirt
{
public:

    /** ���ط�ֵ
    @param [in] total ����
    @return ���ط�ֵ
    */
    virtual uint32_t GetThreshold(uint32_t total) = 0 ;

    /** ����
    @param [in] start ��ʼ
    @param [in] size ��С
    */
    virtual void Decode(uint32_t start, uint32_t size) = 0 ;

    /** λ����
    @param [in] size0 ��С
    @param [in] numTotalBits λ����
    */
    virtual uint32_t DecodeBit(uint32_t size0, uint32_t numTotalBits) = 0 ;

protected:
    
    /** Ĭ����������
    */
    ~RCPPMDRangeDecoderVirt() {} ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDRangeDecoderVirt_h_
