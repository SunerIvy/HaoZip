/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDummyOutStream_h_
#define __RCDummyOutStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCDummyOutStream:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDummyOutStream() ;
    
    /** Ĭ����������
    */
    ~RCDummyOutStream() ;

public:

    /** ������
    @param [in] outStream �����
    */
    void SetStream(ISequentialOutStream* outStream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ��ʼ��
    */
    void Init() ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:

    /** �����
    */
    ISequentialOutStreamPtr m_stream ;

    /** ��С
    */
    uint64_t m_size ;
};

/** RCDummyOutStream����ָ��
*/
typedef RCComPtr<RCDummyOutStream>  RCDummyOutStreamPtr ;

END_NAMESPACE_RCZIP

#endif //__RCDummyOutStream_h_
