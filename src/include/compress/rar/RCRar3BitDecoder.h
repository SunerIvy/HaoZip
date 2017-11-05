/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3BitDecoder_h_
#define __RCRar3BitDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** RAR3 Bit ����ȸ
*/
class RCRar3BitDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar3BitDecoder() ;
    
    /** Ĭ����������
    */
    ~RCRar3BitDecoder() ;
    
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

    /** ��ʼ��
    */
    void Init() ;

    /** �����Ѿ������С
    @return �����Ѿ������С
    */
    uint64_t GetProcessedSize() const ;

    /** ����Bitλ��
    @return ����Bitλ��
    */
    uint32_t GetBitPosition() const ;

    /** ����ֵ
    @param [in] numBits λ��
    @return ����ֵ
    */
    uint32_t GetValue(uint32_t numBits) ;

    /** �ƶ�λ��
    @param [in] numBits λ��
    */
    void MovePos(uint32_t numBits) ;

    /** ��ȡλ����
    @param [in] numBits λ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(uint32_t numBits) ;
    
public:

    /** Bit λ��
    */
    uint32_t m_bitPos ;

    /** ����������
    */
    RCInBuffer m_stream ;
    
private:

    /** ֵ
    */
    uint32_t m_value ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar3BitDecoder_h_
