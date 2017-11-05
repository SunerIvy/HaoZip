/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialOutStreamImp2_h_
#define __RCSequentialOutStreamImp2_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCSequentialOutStreamImp2:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSequentialOutStreamImp2() ;
    
    /** Ĭ����������
    */
    ~RCSequentialOutStreamImp2() ;
    
public:
    
    /** ��ʼ��
    @param [in] buffer ��������ַ
    @param [in] size ��������С
    */
    void Init(byte_t* buffer, size_t size) ;
    
    /** ��ȡ��ǰ����ָ��
    @return ���ص�ǰ����ָ��λ��
    */
    size_t GetPos() const ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ����� RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** ��������ַ
    */
    byte_t* m_buffer ;
    
    /** ����������
    */
    size_t m_size;
    
    /** ��ǰ����λ��
    */
    size_t m_pos;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialOutStreamImp2_h_
