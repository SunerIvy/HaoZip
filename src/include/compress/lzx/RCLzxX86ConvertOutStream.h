/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzxX86ConvertOutStream_h_
#define __RCLzxX86ConvertOutStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Lzx �����
*/
class RCLzxX86ConvertOutStream:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzxX86ConvertOutStream() ;
    
    /** Ĭ����������
    */
    ~RCLzxX86ConvertOutStream() ;

public:
    
    /** ���������
    @param [in] outStream �����
    */
    void SetStream(ISequentialOutStream *outStream) ;
    
    /** �ͷ���
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    @param [in] translationMode ת��ģʽ
    @param [in] translationSize ת����С
    */
    void Init(bool translationMode, uint32_t translationSize) ;
    
    /** Flush����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** ת��
    */
    void MakeTranslation() ;

private:
    
    /** ��ѹ���С
    */
    static const int s_kUncompressedBlockSize = 1 << 15 ;
    
private:
    
    /** �����
    */
    ISequentialOutStreamPtr m_stream ;
    
    /** �Ѿ������С
    */
    uint32_t m_processedSize ;
    
    /** λ��
    */
    uint32_t m_pos ;
    
    /** ת����С
    */
    uint32_t m_translationSize ;
    
    /** �ͷ�ת��ģʽ
    */
    bool m_translationMode ;
    
    /** ����
    */
    byte_t m_buffer[s_kUncompressedBlockSize] ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzxX86ConvertOutStream_h_
