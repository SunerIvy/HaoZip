/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimBitStream_h_
#define __RCWimBitStream_h_ 1

#include "base/RCDefs.h"
#include "common/RCInBuffer.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

/** Wim λ������
*/
class RCWimBitStream
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimBitStream() ;
    
    /** Ĭ����������
    */
    ~RCWimBitStream() ;
    
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

    /** ֱ�Ӷ�ȡ�ֽ�
    @return ���ض�ȡ���ֽ�
    */
    byte_t DirectReadByte() ;

    /** ������
    */
    void Normalize() ;

    /** ����ֵ
    @param [in] numBits λ��
    @return ����uint32ֵ
    */
    uint32_t GetValue(uint32_t numBits) ;

    /** �ƶ�λ�� 
    @param [in] numBits λ��
    */
    void MovePos(uint32_t numBits) ;

    /** ��ȡλ
    @param [in] numBits λ��
    @return ����uint32
    */
    uint32_t ReadBits(uint32_t numBits) ;
    
private:

    /** ������
    */
    RCInBuffer m_stream;

    /**
    */
    uint32_t m_value;

    /**
    */
    uint32_t m_bitPos;
};

END_NAMESPACE_RCZIP

#endif //__RCWimBitStream_h_
