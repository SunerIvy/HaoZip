/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBitmEncoder_h_
#define __RCBitmEncoder_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/IStream.h"
#include "common/RCOutBuffer.h"

BEGIN_NAMESPACE_RCZIP

template<class TOutByte>
class RCBitmEncoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBitmEncoder() ;
    
    /** Ĭ����������
    */
    ~RCBitmEncoder() ;
    
public:
    
    /** ����������
    @param [in] bufferSize ��������С
    @return �����ɹ�����true, ʧ���򷵻�false
    */
    bool Create(uint32_t bufferSize) ;
    
    /** ����������ӿ�
    @param [in] outStream ������ӿ�ָ��
    */
    void SetStream(ISequentialOutStream* outStream) ;
    
    /** �ͷ������
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ��д����
    @return ����ɹ�����RC_S_OK, ���򷵻ش�����
    */
    HResult Flush() ;
    
    /** д��λ��
    @param [in] value д�����ֵ
    @param [in] numBits д���λ��
    */
    void WriteBits(uint32_t value, int32_t numBits) ;
    
    /** ��ȡ�Ѵ����С
    @return �����Ѵ����С
    */
    uint64_t GetProcessedSize() const ;
    
private:
    
    /** ������ӿ�
    */
    TOutByte m_stream ;
    
    /** λƫ��λ��
    */
    int32_t m_bitPos ;
    
    /** ��ǰ�ֽ�ֵ
    */
    byte_t m_curByte ;
};

END_NAMESPACE_RCZIP

#include "RCBitmEncoder.inl"

#endif //__RCBitmEncoder_h_
