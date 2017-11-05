/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzxBitStreamDecoder_h_
#define __RCLzxBitStreamDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Lzx ������
*/
class RCLzxBitStreamDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzxBitStreamDecoder() ;
    
    /** Ĭ����������
    */
    ~RCLzxBitStreamDecoder() ;
    
public:
    
    /** ����
    @param [in] bufferSize �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;
    
    /** ����������
    @param [in] s ������
    */
    void SetStream(ISequentialInStream *s) ;
    
    /** �ͷ���
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** �����Ѵ����С
    @return �����Ѿ������С
    */
    uint64_t GetProcessedSize() const ;
    
    /** ����Bitλ��
    @return ����Bitλ��
    */
    int32_t GetBitPosition() const ;
    
    /** �淶��
    */
    void Normalize() ;
    
    /** �����ƶ�λ������ֵ
    @param [in] numBits λ��
    @return ������ֵ
    */
    uint32_t GetValue(int32_t numBits) const ;
    
    /** �ƶ�λ��
    @param [in] numBits �ƶ�λ��
    */
    void MovePos(uint32_t numBits) ;
    
    /** ��ȡλ
    @param [in] numBits λ��
    @return ���ض�ȡ�ֽ���
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** ��ȡλ
    @param [in] numBits λ��
    @return �����ֽ���
    */
    uint32_t ReadBitsBig(int32_t numBits) ;
    
    /** ��ȡ�޷�������
    @param [out] v ����ֵ
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadUInt32(uint32_t &v) ;
    
    /** ֱ�Ӷ�ȡ�ֽ�
    @return ���ض�ȡ���ֽ�
    */
    byte_t DirectReadByte() ;
    
private:
    
    /** ���뻺��
    */
    RCInBuffer m_stream ;
    
    /** ��ֵ
    */
    uint32_t m_value ;
    
    /** λƫ����
    */
    int32_t m_bitPos ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzxBitStreamDecoder_h_
