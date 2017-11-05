/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2MsbfEncoderTemp_h_
#define __RCBZip2MsbfEncoderTemp_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 Msbf ����
*/
class RCBZip2MsbfEncoderTemp:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2MsbfEncoderTemp() ;
    
    /** Ĭ����������
    */
    ~RCBZip2MsbfEncoderTemp() ;
    
public:
    
    /** ������
    @param [in] buffer ����ָ��
    */
    void SetStream(byte_t* buffer) ;
    
    /** ������ָ��
    @return ������ָ��
    */
    byte_t* GetStream() const ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** Flush����
    */
    void Flush() ;
    
    /** д��λ
    @param [in] value ��ֵ
    @param [in] numBits λ��
    */
    void WriteBits(uint32_t value, int32_t numBits) ;
    
    /** �����ֽ�λ��
    @return �����ֽ�λ��
    */
    uint32_t GetBytePos() const ;
    
    /** ����λ��
    @return ����λ��
    */
    uint32_t GetPos() const ;
    
    /** ���ص�ǰ�ֽ�
    @return ���ص�ǰ�ֽ�
    */
    byte_t GetCurByte() const ;
    
    /** ����λ��
    @param [in] bitPos λ��
    */
    void SetPos(uint32_t bitPos) ;
    
    /** ����״̬
    @param [in] bitPos λ��
    @param [in] curByte ��ǰ�ֽ�
    */
    void SetCurState(int32_t bitPos, byte_t curByte) ;
    
private:
    
    /** λ��
    */
    uint32_t m_pos;
    
    /** bit λ��
    */
    int32_t m_bitPos;
    
    /** ��ǰ�ֽ�
    */
    byte_t m_curByte;
    
    /** ����ָ��
    */
    byte_t* m_buffer;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2MsbfEncoderTemp_h_
