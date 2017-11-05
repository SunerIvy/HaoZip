/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCQuantumRangeDecoder_h_
#define __RCQuantumRangeDecoder_h_ 1

#include "compress/quantum/RCQuantumStreamBitDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Quantum Range ������
*/
class RCQuantumRangeDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCQuantumRangeDecoder() ;
    
    /** Ĭ����������
    */
    ~RCQuantumRangeDecoder() ;

public:

    /** ����
    @param [in] bufferSize �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;

    /** ����������
    @param [in] stream ������
    */
    void SetStream(ISequentialInStream* stream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ��ʼ��
    */
    void Init() ;

    /** ����
    */
    void Finish() ;

    /** �����Ѿ������С
    @return �����Ѵ����С
    */
    uint64_t GetProcessedSize() const ;

    /** ���ط�ֵ
    @param [in] total ����
    @return ���ط�ֵ
    */
    uint32_t GetThreshold(uint32_t total) const ;

    /** ����
    @param [in] start ��ʼ
    @param [in] end ����
    @param [in] total ����
    */
    void Decode(uint32_t start, uint32_t end, uint32_t total) ;
      
public:

    /** ������
    */
    RCQuantumStreamBitDecoder m_stream ;
    
private:

    /** ��λ
    */
    uint32_t m_low ;

    /** ����
    */
    uint32_t m_range ;

    /** ���
    */
    uint32_t m_code ;
};

END_NAMESPACE_RCZIP

#endif //__RCQuantumRangeDecoder_h_
