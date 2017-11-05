/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMemoryAlloc_h_
#define __RCMemoryAlloc_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

class RCMemoryAlloc:
    private RCNonCopyable
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCMemoryAlloc() ;
    
    /** Ĭ����������
    */
    ~RCMemoryAlloc() ;
    
public:
    
    /** �����ڴ�
    @param [in] size ��Ҫ������ڴ�ռ��С���ֽ���
    @return �����ѷ�����ڴ��ַ�����ʧ�ܷ���NULL
    */
    void* MyAlloc(size_t size) ;
    
    /** �ͷ���MyAlloc������ڴ�
    @param [in] address ��Ҫ�ͷŵ��ڴ��ַ
    */
    void MyFree(void* address) ;
    
    /** ����LargePageSizeģʽ, ֻ��Windows֧�ָ����Եİ汾��Ч
    */
    void SetLargePageSize() ;

    /** �����ڴ�
    @param [in] size ��Ҫ������ڴ�ռ��С���ֽ���
    @return �����ѷ�����ڴ��ַ�����ʧ�ܷ���NULL
    */
    void* MidAlloc(size_t size);
    
    /** �ͷ���MidAlloc������ڴ�
    @param [in] address ��Ҫ�ͷŵ��ڴ��ַ
    */
    void MidFree(void* address);
    
    /** �����ڴ�
    @param [in] size ��Ҫ������ڴ�ռ��С���ֽ���
    @return �����ѷ�����ڴ��ַ�����ʧ�ܷ���NULL
    */
    void* BigAlloc(size_t size);
    
    /** �ͷ��ڴ�
    @param [in] address ��Ҫ�ͷŵ��ڴ��ַ
    */
    void BigFree(void* address);
    
private:
    
    /** LargePage �Ĵ�С����λΪ�ֽ�
    */
    uint64_t m_largePageSize ;
};

/** ����ʵ��
*/
typedef RCSingleton<RCMemoryAlloc> RCAlloc ;

END_NAMESPACE_RCZIP

#endif //__RCMemoryAlloc_h_
