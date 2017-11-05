/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeEncoder_h_
#define __RCRangeEncoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCOutBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Range ����
*/
class RCRangeEncoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRangeEncoder() ;
    
    /** Ĭ����������
    */
    ~RCRangeEncoder() ;

public:
    /** Get Low
    */
    uint64_t GetLow(void) const ;
    
    /** Get Range
    */
    uint32_t GetRange(void) const ;
    
    /** Get Out Stream
    */
    RCOutBuffer& GetStream(void) ;
    
    /** Set Low
    @param [in] low ֵ
    */
    void SetLow(uint64_t low) ;
    
    /** Set Range
    @param [in] range ֵ
    */
    void SetRange(uint32_t range) ;

    /** ����
    @param [in] bufferSize �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;

    /** ���������
    @param [in] stream �����
    */
    void SetStream(ISequentialOutStream *stream) ;

    /** ��ʼ��
    */
    void Init() ;
 
    /** Flush����
    */
    void FlushData() ;

    /** Flush��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult FlushStream() ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ����
    @param [in] start ��ʼ
    @param [in] size ��С
    @param [in] total ����
    */
    void Encode(uint32_t start, uint32_t size, uint32_t total) ;

    /** ShiftLow
    */
    void ShiftLow() ;

    /** λ����
    @param [in] value ��ֵ
    @param [in] numBits λ��
    */
    void EncodeDirectBits(uint32_t value, int32_t numBits) ;

    /** λ����
    @param [in] size0 ��С
    @param [in] numTotalBits λ��
    @param [in] symbol ����
    */
    void EncodeBit(uint32_t size0, uint32_t numTotalBits, uint32_t symbol) ;

    /** ȡ���Ѵ����С
    @return �����Ѵ����С
    */
    uint64_t GetProcessedSize() ;
    
private:

    /** cache ��С
    */
    uint32_t m_cacheSize ;

    /** cache
    */
    byte_t m_cache ;

    /** low
    */
    uint64_t m_low ;

    /** range
    */
    uint32_t m_range ;

    /** ���������
    */
    RCOutBuffer m_stream ;
};

END_NAMESPACE_RCZIP

#endif //__RCRangeEncoder_h_
