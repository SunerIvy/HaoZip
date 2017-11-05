/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLimitedSequentialOutStream_h_
#define __RCLimitedSequentialOutStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCLimitedSequentialOutStream:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLimitedSequentialOutStream() ;
    
    /** Ĭ����������
    */
    ~RCLimitedSequentialOutStream() ;

public:
    
    /** ����������ӿ�
    @param [in] stream ������ӿ�ָ��
    */
    void SetStream(ISequentialOutStream* stream) ;
    
    /** �ͷ������
    */
    void ReleaseStream() ;
    
    /** ��ʼ��
    @param [in] size �������С
    @param [in] overflowIsAllowed �Ƿ������������
    */
    void Init(uint64_t size, bool overflowIsAllowed = false) ;
    
    /** �Ƿ��Ѿ����
    @return ����Ѿ���ɷ���true, ���򷵻�false
    */
    bool IsFinishedOK() const ;
    
    /** ��ȡ���ݴ�С
    @return �������ݴ�С
    */
    uint64_t GetRem() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** ������ӿ�
    */
    ISequentialOutStreamPtr m_spOutStream ;
    
    /** ���ݴ�С
    */
    uint64_t m_size ;
    
    /** �Ƿ����
    */
    bool m_overflow ;
    
    /** �Ƿ��������
    */
    bool m_overflowIsAllowed ;
};

typedef RCComPtr<RCLimitedSequentialOutStream> RCLimitedSequentialOutStreamPtr ;

END_NAMESPACE_RCZIP

#endif //__RCLimitedSequentialOutStream_h_
