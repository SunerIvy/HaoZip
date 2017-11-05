/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3RangeDecoder_h_
#define __RCRar3RangeDecoder_h_ 1

#include "compress/rar/RCRar3BitDecoder.h"
#include "compress/ppmd/RCPPMDRangeDecoderVirt.h"

BEGIN_NAMESPACE_RCZIP

/** RAR3 Range ������
*/
class RCRar3RangeDecoder:
    public RCRar3BitDecoder,
    public RCPPMDRangeDecoderVirt
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar3RangeDecoder() ;
    
    /** Ĭ����������
    */
    ~RCRar3RangeDecoder() ;
    
public:

    /** ���滯
    */
    void Normalize() ;

    /** ��ʼ��������
    */
    void InitRangeCoder() ;

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
    @param [in] numTotalBits λ����
    @return ���ؽ�����
    */
    virtual uint32_t DecodeBit(uint32_t size0, uint32_t numTotalBits) ;
    
public:

    /** range
    */
    uint32_t m_range ;

    /** low
    */
    uint32_t m_low ;

    /** code
    */
    uint32_t m_code ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar3RangeDecoder_h_
