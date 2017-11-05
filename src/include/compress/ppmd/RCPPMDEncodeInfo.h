/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDEncodeInfo_h_
#define __RCPPMDEncodeInfo_h_ 1

#include "compress/ppmd/RCPPMDInfo.h"
#include "compress/range/RCRangeEncoder.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ��������Ϣ
*/
class RCPPMDEncodeInfo:
    public RCPPMDInfo
{
public:

    /** ����
    @param [in] symbol ����
    @param [in] rangeEncoder ������
    */
    void EncodeBinSymbol(int32_t symbol, RCRangeEncoder* rangeEncoder) ;
    
    /** ����
    @param [in] symbol ����
    @param [in] rangeEncoder ������
    */
    void EncodeSymbol1(int32_t symbol, RCRangeEncoder* rangeEncoder) ;
    
    /** ����
    @param [in] symbol ����
    @param [in] rangeEncoder ������
    */
    void EncodeSymbol2(int32_t symbol, RCRangeEncoder* rangeEncoder) ;
    
    /** ����
    @param [in] c 
    @param [in] rangeEncoder ������
    */
    void EncodeSymbol(int32_t c, RCRangeEncoder* rangeEncoder) ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDEncodeInfo_h_
