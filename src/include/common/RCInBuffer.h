/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInBuffer_h_
#define __RCInBuffer_h_ 1

#include "interface/IStream.h"
#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** ���뻺����
*/
class RCInBuffer:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCInBuffer() ;
    
    /** Ĭ����������
    */
    ~RCInBuffer() ;
    
public:

    /** ����������
    @param [in] bufferSize ��������С
    @return �ɹ�����true,ʧ�ܷ���false
    */
    bool Create(uint32_t bufferSize) ;
    
    /** ��ʼ��
    */
    void Init();
    
    /** �ͷŻ�����
    */
    void Free() ;
  
    /** ����������
    @param [in] stream ��������ָ��
    */
    void SetStream(ISequentialInStream* stream) ;

    /** �ͷ�������
    */
    void ReleaseStream() ;

    /** ��ȡ�ֽ�
    @param [out] value ��ȡ���ֽ�ֵ
    @return �ɹ�����true, ʧ���򷵻�false
    @throws �����ȡ����ʧ�����쳣
    */
    bool ReadByte(byte_t& value) ;
    
    /** ��ȡ�ֽ�
    @return ���ض�ȡ���ֽڣ����ʧ�ܷ���0xFF
    @throws �����ȡ����ʧ�����쳣
    */
    byte_t ReadByte() ;
    
    /** ��ȡ���ֽ�
    @param [out] buf ��Ŷ�ȡ����Ļ�������ַ
    @param [in]  size �������ĳ���
    @return ����ʵ�ʶ�ȡ�ĳ���
    @throws �����ȡ����ʧ�����쳣
    */
    uint32_t ReadBytes(byte_t* buf, uint32_t size) ;
    
    /** ��ȡ��ǰ��ȡ���ֽ���
    @return �����Ѿ�����Ĵ�С
    */
    uint64_t GetProcessedSize() const ;
    
    /** �Ƿ����
    @return ����������������true�����򷵻�false
    */
    bool WasFinished() const ;
  
private:
    
    /** ��ȡ���ݿ�
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool ReadBlock() ;
    
    /** ��ȡ���ݿ�
    @return �ɹ����ض��������ݣ�ʧ���򷵻�0xFF
    */
    byte_t ReadBlock2() ;
       
private:
    
    /** ���ݻ�����
    */
    byte_t* m_buffer ;
    
    /** ��Ч���ݻ�����
    */
    byte_t* m_bufferLimit ;
    
    /** ����������ַ
    */
    byte_t* m_bufferBase ;
    
    /** ������
    */
    ISequentialInStreamPtr m_spStream ;
    
    /** �Ѵ����С
    */
    uint64_t m_processedSize ;
    
    /** ��������С
    */
    uint32_t m_bufferSize ;
    
    /** �Ƿ������
    */
    bool m_wasFinished ;
};

END_NAMESPACE_RCZIP

#endif //__RCInBuffer_h_
