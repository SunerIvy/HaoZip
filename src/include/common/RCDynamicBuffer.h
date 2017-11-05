/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDynamicBuffer_h_
#define __RCDynamicBuffer_h_ 1

#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

template <typename T> 
class RCDynamicBuffer:
    public RCBuffer<T>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDynamicBuffer() ;
    
    /** Ĭ����������
    */
    virtual ~RCDynamicBuffer() ;
    
    /** ָ����С�Ĺ��캯��
    @param [in] size ��������С
    */
    explicit RCDynamicBuffer(size_t size) ;
    
    /** �������캯��
    @param [in] from ���ƶ���
    */
    RCDynamicBuffer(const RCDynamicBuffer& from) ;
    
    /** ��ֵ������
    @param [in] from ���ƶ���
    */
    RCDynamicBuffer& operator= (const RCDynamicBuffer& from) ;
    
public:
    
    /** ȷ����������С��С��capacity
    @param [in] capacity ��������С
    */
    void EnsureCapacity(size_t capacity) ;
    
    /** ���ӻ�������С
    @param [in] size ���ӵĴ�С
    */
    void GrowLength(size_t size) ;
};

/** �ֽ����͵Ļ�����
*/
typedef RCDynamicBuffer<byte_t> RCDynamicByteBuffer ;

/** �ַ����͵Ļ�����
*/
typedef RCDynamicBuffer<char> RCDynamicCharBuffer ;

END_NAMESPACE_RCZIP

#include "RCDynamicBuffer.inl"

#endif //__RCDynamicBuffer_h_
