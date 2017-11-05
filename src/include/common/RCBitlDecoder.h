/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBitlDecoder_h_
#define __RCBitlDecoder_h_ 1

#include "common/RCBitlBaseDecoder.h"

BEGIN_NAMESPACE_RCZIP

template<class TInByte>
class RCBitlDecoder:
    public RCBitlBaseDecoder<TInByte>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBitlDecoder() ;
    
    /** Ĭ����������
    */
    ~RCBitlDecoder() ;
    
public:
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ����
    */
    void Normalize() ;  
    
    /** ��ȡλ��Ӧ��ֵ
    @param [in] numBits λ��
    @return λ��Ӧ��ֵ
    */
    uint32_t GetValue(int32_t numBits) ;
    
    /** �ƶ���ָ��λ
    @param [in] numBits λ��
    */
    void MovePos(int32_t numBits) ;
    
    /** ��ȡλ��
    @param [in] numBits λ��
    @return ����λ��Ӧֵ
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** ���뵽�ֽ�
    */
    void AlignToByte() ;
    
    /** ��ȡ�ֽ�
    @return ��ȡ�ֽ�ֵ
    */
    byte_t ReadByte() ;
    
private:
    
    /** ��������ֵ
    */
    uint32_t m_normalValue;
};

END_NAMESPACE_RCZIP

#include "RCBitlDecoder.inl"

#endif //__RCBitlDecoder_h_
