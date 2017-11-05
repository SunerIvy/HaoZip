/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBitlBaseDecoder_h_
#define __RCBitlBaseDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCBitlDecoderData.h"

BEGIN_NAMESPACE_RCZIP

class ISequentialInStream ;

template<class TInByte>
class RCBitlBaseDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBitlBaseDecoder() ;
    
    /** Ĭ����������
    */
    ~RCBitlBaseDecoder() ;
    
public:
    
    /** ����������
    @param [in] bufferSize ��������С
    @return �ɹ�����true, ʧ���򷵻�false
    */   
    bool Create(uint32_t bufferSize) ;
    
    /** �����������ӿ�
    @param [in] inStream �������ӿ�ָ��
    */
    void SetStream(ISequentialInStream* inStream) ;
    
    /** �ͷ�������
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ��ȡ�Ѵ���������ֽ���
    @return �����Ѵ���������ֽ���
    */
    uint64_t GetProcessedSize() const ;
    
    /** ����
    */
    void Normalize() ; 
    
    /** ��ȡ�ֽ�λ
    @param [in] numBits ��ȡ��λ��
    @return ���ش�����
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** �ж�ExtraBits�Ƿ��Ѷ�ȡ
    @return ����Ѵ�����true, ���򷵻�false
    */
    bool ExtraBitsWereRead() const ;
    
    /** ExtraBits �ĸ���
    @return ExtraBits �ĸ���
    */
    uint32_t GetNumExtraBytes() const ;
    
protected:
    
    /** ��ǰλ��λ��
    */
    int32_t m_bitPos ;
    
    /** ����ֵ
    */
    uint32_t m_value ;
    
    /** ������������
    */
    TInByte m_stream ;
    
    /** ExtraBytes ����
    */
    uint32_t m_numExtraBytes;
};

END_NAMESPACE_RCZIP

#include "RCBitlBaseDecoder.inl"

#endif //__RCBitlBaseDecoder_h_
