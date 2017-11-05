/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBitmDecoder_h_
#define __RCBitmDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

template<class TInByte>
class RCBitmDecoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBitmDecoder() ;
    
    /** Ĭ����������
    */
    ~RCBitmDecoder() ;

public:
    
    /** ����������
    @param [in] bufferSize ��������С
    @return �����ɹ�����true, ʧ���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;
    
    /** �����������ӿ�
    @param [in] inStream �������ӿ�ָ��
    */
    void SetStream(ISequentialInStream* inStream) ;
    
    /** �ͷ�������
    */
    void ReleaseStream(); 
    
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
    
    /** ��ȡλ��Ӧ��ֵ
    @param [in] numBits λ��
    @return λ��Ӧ��ֵ
    */
    uint32_t GetValue(uint32_t numBits) const ;  
    
    /** �ƶ���ָ��λ
    @param [in] numBits λ��
    */
    void MovePos(uint32_t numBits) ;  
    
    /** ��ȡλ��
    @param [in] numBits λ��
    @return ����λ��Ӧֵ
    */
    uint32_t ReadBits(uint32_t numBits) ;
    
    /** ���뵽�ֽ�
    */
    void AlignToByte() ;
    
private:
    
    /** ��ǰλ��λ��
    */
    uint32_t m_bitPos;
    
    /** ����ֵ
    */
    uint32_t m_value;
    
    /** ������������
    */
    TInByte m_stream ;
    
private:
    
    /** ����ֵλ��
    */
    static const int32_t s_kNumBigValueBits = 8 * 4 ;
    
    /** ��ֵ�ֽ���
    */
    static const int32_t s_kNumValueBytes = 3 ;
    
    /** ��ֵλ��
    */
    static const int32_t s_kNumValueBits = 8  * s_kNumValueBytes ;
    
    /** ��ֵ����
    */
    static const uint32_t s_kMask = (1 << s_kNumValueBits) - 1 ;
};

END_NAMESPACE_RCZIP

#include "RCBitmDecoder.inl"

#endif //__RCBitmDecoder_h_
