/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfMap32_h_
#define __RCUdfMap32_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCSmartPtr.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** Udf Map
*/
class RCUdfMap32:
    private RCNonCopyable
{
public:
    
    /** Ĭ����������
    */
    ~RCUdfMap32() ;
    
    /** ��������, ������Ѿ����ڣ�����ֵ���ݣ���������ڣ��������½ڵ�
    @param [in] key ������
    @param [in] value ֵ����
    @return �����key�Ѿ����ڣ�����true, ���򷵻�false
    */
    bool Set(uint32_t key, uint32_t value) ;
    
    /** ��������
    @param [in] key ��Ҫ���ҵļ�����
    @param [out] valueRes ���ز��ҵ���ֵ
    @return ����ҵ�����true, ���򷵻�false
    */
    bool Find(uint32_t key, uint32_t& valueRes) const ;
    
    /** �������
    */
    void Clear() ;
    
private:
    
    /** �ڲ�ʵ�ֺ���
    @param [in] value 
    @param [in] startPos ��ʼλ��
    @param [in] numBits λ��
    */
    static uint32_t GetSubBits(uint32_t value, uint32_t startPos, uint32_t numBits) ;
    
private:

    /** �ڵ����Ͷ���
    */
    struct RCUdfMapNode ;
    
    /** �ڵ�����
    */
    RCVector<RCUdfMapNode*> m_nodes ;
};

typedef RCSharedPtr<RCUdfMap32> RCUdfMap32Ptr;

END_NAMESPACE_RCZIP

#endif //__RCUdfMap32_h_
