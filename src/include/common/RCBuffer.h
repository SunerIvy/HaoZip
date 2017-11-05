/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBuffer_h_
#define __RCBuffer_h_ 1

#include "base/RCDefs.h"
#include <algorithm>
#include <cstring>

BEGIN_NAMESPACE_RCZIP

template <typename T> 
class RCBuffer
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBuffer() ;
    
    /** Ĭ����������
    */
    virtual ~RCBuffer() ;
    
    /** ָ����С�Ĺ��캯��
    @param [in] size ��������С
    */
    explicit RCBuffer(size_t size) ;
    
    /** �������캯��
    @param [in] from ���ƵĶ���
    */
    RCBuffer(const RCBuffer& from) ;
    
    /** ��ֵ������
    @param [in] from ���ƵĶ���
    */
    RCBuffer& operator= (const RCBuffer& from) ;
    
public:
    
    /** ��ȡ��������С
    @return ���ػ�������С
    */
    size_t GetCapacity() const ;
    
    /** ���û�������С
    @param [in] newCapacity �µĻ�������С
    */
    void SetCapacity(size_t newCapacity) ;
    
    /** �ͷŻ�����
    */
    void Free() ;
    
    /** ��ȡ��������ַ
    @return ���ػ�������ַ
    */
    T* data() ;
    
    /** ֻ����ʽ��ȡ��������ַ
    @return ���ػ�������ַ
    */
    const T* data() const ;
    
    /** �������ݳ���
    @param [in] dataLen ���ݳ���
    */
    void SetDataLength(size_t dataLen) ;
    
    /** ��ȡ���ݳ���
    @return �������ݳ���
    */
    size_t GetDataLength(void) const ;
    
    /** operator []
    @param [in] index ��ֵ�±�
    @return �����±��Ӧ��ֵ
    */
    const T operator [] (size_t index) const ;
    
protected:
    
    /** ��������С
    */
    size_t m_capacity;
    
    /** ����������
    */
    T* m_data ;
    
    /** ���ݴ�С
    */
    size_t m_dataLen ;
};

/** �ֽ����͵Ļ�����
*/
typedef RCBuffer<byte_t> RCByteBuffer ;

/** �ַ����͵Ļ�����
*/
typedef RCBuffer<char> RCCharBuffer ;

END_NAMESPACE_RCZIP

#include "RCBuffer.inl"

#endif //__RCBuffer_h_
