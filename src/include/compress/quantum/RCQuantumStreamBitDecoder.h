/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCQuantumStreamBitDecoder_h_
#define __RCQuantumStreamBitDecoder_h_ 1

#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Quantum Bit ������
*/
class RCQuantumStreamBitDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCQuantumStreamBitDecoder() ;
    
    /** Ĭ����������
    */
    ~RCQuantumStreamBitDecoder() ;
    
public:

    /** ����
    @param [in] bufferSize �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;

    /** ����������
    @param [in] inStream ������
    */
    void SetStream(ISequentialInStream *inStream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** �������
    */
    void Finish() ;

    /** ��ʼ��
    */
    void Init() ;

    /** ȡ���Ѿ������С
    @return �����Ѵ����С
    */
    uint64_t GetProcessedSize() const ;

    /** �Ƿ����
    @return ��������true,���򷵻�false
    */
    bool WasFinished() const ;

    /** ��ȡλ
    @return ���ض�ȡ���
    */
    uint32_t ReadBit() ;

    /** ��ȡλ
    @param [in] numBits ��ȡλ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(int32_t numBits) ; // numBits > 0
    
private:

    /** ֵ
    */
    uint32_t m_value;

    /** ���뻺��
    */
    RCInBuffer m_stream;
};

END_NAMESPACE_RCZIP

#endif //__RCQuantumStreamBitDecoder_h_
