/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZlibOutStreamWithAdler_h_
#define __RCZlibOutStreamWithAdler_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Zlib �����
*/
class RCZlibOutStreamWithAdler:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZlibOutStreamWithAdler() ;
    
    /** Ĭ����������
    */
    ~RCZlibOutStreamWithAdler() ;
    
public:
    
    /** ���������
    @param [in] stream �����
    */
    void SetStream(ISequentialOutStream *stream) ;
    
    /** �ͷ���
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ȡ��Adler
    @return ����Adler
    */
    uint32_t GetAdler() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;

private:
    
    /** Adler����
    @param [in] adler
    @param [in] buf ���ݻ���
    @param [in] size ��С
    @return ���ظ����ֽ���
    */
    static uint32_t Adler32Update(uint32_t adler, const byte_t* buf, size_t size) ;    
    
private:
    
    /** �����
    */
    ISequentialOutStreamPtr m_stream ;
    
    /** Adler
    */
    uint32_t m_adler ;
};

END_NAMESPACE_RCZIP

#endif //__RCZlibOutStreamWithAdler_h_
