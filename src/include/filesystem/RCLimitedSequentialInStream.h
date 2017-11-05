/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLimitedSequentialInStream_h_
#define __RCLimitedSequentialInStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCLimitedSequentialInStream:
    public IUnknownImpl<ISequentialInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLimitedSequentialInStream() ;
    
    /** Ĭ����������
    */
    ~RCLimitedSequentialInStream() ;
    
public:
    
    /** �����������ӿ�
    @param [in] stream �������ӿ�ָ��
    */
    void SetStream(ISequentialInStream* stream) ;
    
    /** ��ʼ��
    @param [in] streamSize �����ݴ�С
    */
    void Init(uint64_t streamSize) ;
    
    /** ��ȡ���ݴ�С
    @return �������ݴ�Сֵ
    */
    uint64_t GetSize() const ;
    
    /** �Ƿ��Ѿ��������λ��
    @return ����true��ʾ�Ѵ����λ�ã����򷵻�false
    */
    bool WasFinished() const ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** �������ӿ�
    */
    ISequentialInStreamPtr m_spInStream;
    
    /** ���ݴ�С
    */
    uint64_t m_size;
    
    /** ����ƫ��λ��
    */
    uint64_t m_pos;
    
    /** �����Ƿ��Ѿ�����
    */
    bool m_wasFinished;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCLimitedSequentialInStream>   RCLimitedSequentialInStreamPtr ;

END_NAMESPACE_RCZIP

#endif //__RCLimitedSequentialInStream_h_
