/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDDecodeInfo_h_
#define __RCPPMDDecodeInfo_h_ 1

#include "compress/ppmd/RCPPMDInfo.h"
#include "compress/ppmd/RCPPMDRangeDecoderVirt.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ������
*/
class RCPPMDDecodeInfo:
    public RCPPMDInfo
{
public:

    /** ����
    @param [in] rangeDecoder ������
    */
    void DecodeBinSymbol(RCPPMDRangeDecoderVirt* rangeDecoder) ;
    
    /** ����
    @param [in] rangeDecoder ������
    */
    void DecodeSymbol1(RCPPMDRangeDecoderVirt* rangeDecoder) ;
    
    /** ����
    @param [in] rangeDecoder ������
    */
    void DecodeSymbol2(RCPPMDRangeDecoderVirt* rangeDecoder) ;
    
    /** ����
    @param [in] rangeDecoder ������
    @return ���ؽ����ֽ���
    */
    int32_t DecodeSymbol(RCPPMDRangeDecoderVirt* rangeDecoder) ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDDecodeInfo_h_
