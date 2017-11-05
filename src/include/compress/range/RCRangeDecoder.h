/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeDecoder_h_
#define __RCRangeDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Range ������
*/
class RCRangeDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRangeDecoder() ;
    
    /** Ĭ����������
    */
    ~RCRangeDecoder() ;

public:

    /** ��������������
    @return �������뻺��
    */
    RCInBuffer& GetStream() ;

    /** ����Range
    @return ����Range
    */
    uint32_t GetRange(void) const ;

    /** ����Code
    @return ����Code
    */
    uint32_t GetCode(void) const ;

    /** ����Range
    @param [in] range ֵ
    */
    void SetRange(uint32_t range) ;

    /** ����code
    @param [in] code ֵ
    */
    void SetCode(uint32_t code) ;

    /** ����
    @param [in] bufferSize �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;

    /** ������
    */
    void Normalize() ;

    /** ����������
    @param [in] stream ������
    */
    void SetStream(ISequentialInStream *stream) ;

    /** ��ʼ��
    */
    void Init() ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ���ط�ֵ
    @param [in] total ����
    @return ���ط�ֵ
    */
    uint32_t GetThreshold(uint32_t total) ;

    /** ����
    @param [in] start ��ʼ
    @param [in] size ��С
    */
    void Decode(uint32_t start, uint32_t size) ;

    /** ֱ��λ����
    @param [in] numTotalBits λ��
    @return ���ؽ�����
    */
    uint32_t DecodeDirectBits(int numTotalBits) ;

    /** λ����
    @param [in] size0 ��С
    @param [in] numTotalBits λ����
    @return ���ؽ�����
    */
    uint32_t DecodeBit(uint32_t size0, uint32_t numTotalBits) ;

    /** �����Ѵ����С
    */
    uint64_t GetProcessedSize() ;
    
private:

    /** ���뻺��
    */
    RCInBuffer m_stream ;

    /** range
    */
    uint32_t m_range ;

    /** code
    */
    uint32_t m_code ;
};

END_NAMESPACE_RCZIP

#endif //__RCRangeDecoder_h_
