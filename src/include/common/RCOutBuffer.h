/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutBuffer_h_
#define __RCOutBuffer_h_ 1

#include "interface/IStream.h"
#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class ISequentialOutStream ;

/** ���������
*/
class RCOutBuffer:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCOutBuffer() ;
    
    /** Ĭ����������
    */
    ~RCOutBuffer() ;

public:
    
    /** ����������
    @param [in] bufferSize ��������С
    @return �ɹ�����true,ʧ�ܷ���false
    */
    bool Create(uint32_t bufferSize);
    
    /** ��ʼ��
    */
    void Init();
    
    /** �ͷŻ�����
    */
    void Free();

    /** ���� Mem Stream
    @param [in] buffer ��������ַ
    */
    void SetMemStream(byte_t* buffer) ;
    
    /** ���������
    @param [in] stream �����ָ��
    */
    void SetStream(ISequentialOutStream* stream) ;
  
    /** ������д�������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult Flush() ;
    
    /** ������д������������ʧ�����׳��쳣
    */
    void FlushWithCheck();
    
    /** �ͷ������
    */
    void ReleaseStream() ;

    /** д���ֽ�
    @param [in] value ��Ҫд����ֽ�ֵ
    @throws ���д����ʧ�����쳣
    */
    void WriteByte(byte_t value) ;
    
    /** д����ֽ�
    @param [in] data �ֽ���ʼ��ַ
    @param [in] size �ֽڳ���
    @throws ���д����ʧ�����쳣
    */
    void WriteBytes(const void* data, size_t size) ;
    
    /** ��ȡ�Ѵ������ݴ�С
    @return �����Ѵ���ĳ���
    */
    uint64_t GetProcessedSize() const;
    
protected:    
    
    /** ������д�������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult FlushPart() ;
    
protected:
    
    /** ���ݻ�����
    */
    byte_t* m_buffer ;
    
    /** ����ƫ��
    */
    uint32_t m_pos ;
    
    /** ��������ƫ��
    */
    uint32_t m_limitPos ;
    
    /** ����λ��ƫ��
    */
    uint32_t m_streamPos ;
    
    /** ��������С
    */
    uint32_t m_bufferSize ;
    
    /** ������ӿ�
    */
    ISequentialOutStreamPtr m_spStream ;
    
    /** �Ѵ����С
    */
    uint64_t m_processedSize ;
    
    /** �ڴ滺������ַ
    */
    byte_t* m_buffer2 ;
    
    /** �Ƿ��Ѿ��ﵽ��������С
    */
    bool m_overDict ;
};

END_NAMESPACE_RCZIP

#endif //__RCOutBuffer_h_
