/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStringBuffer_h_
#define __RCStringBuffer_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "common/RCStringUtil.h"

BEGIN_NAMESPACE_RCZIP

template <class string_type>
class RCStringBufferBase:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    @param [in] str �ַ���ָ��
    */
    explicit RCStringBufferBase(string_type* str) ;
    
    /** Ĭ����������
    */
    ~RCStringBufferBase() ;
    
    /** ��ȡ������
    @param [in] minBufLength ����������
    @return ���ػ�������ַ, ���minBufLengthΪ0�� ����NULL
    */
    typename string_type::value_type* GetBuffer(uint32_t minBufLength) ;
    
    /** �ͷŻ�����, ��β�㷽ʽ�����ַ�������
    */
    void ReleaseBuffer() ;
    
    /** �ͷŻ�����,���ѻ��������ݸ�ֵ���ַ���
    @param [in] newLength �ַ������ݳ���
    */
    void ReleaseBuffer(uint32_t newLength) ;

private:
    
    /** �ַ�����ַ
    */
    string_type* m_str ;
    
    /** ��������ַ
    */
    typename string_type::value_type* m_buffer ;
        
    /** ����������
    */
    uint32_t m_length ;
};

typedef RCStringBufferBase<RCStringA> RCStringBufferA ;
typedef RCStringBufferBase<RCStringW> RCStringBufferW ;

#ifdef RCZIP_UNICODE
    typedef RCStringBufferW RCStringBuffer ;
#else
    typedef RCStringBufferA RCStringBuffer ;
#endif

END_NAMESPACE_RCZIP

/** ģ��ʵ���ļ�
*/
#include "RCStringBuffer.inl"

#endif //__RCStringBuffer_h_
