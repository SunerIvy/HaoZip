/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRefCounted_h_
#define __RCRefCounted_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** ���ü�������
*/
class RCRefCounted:
    private RCNonCopyable
{
public:

    /** �������ü���
    */
    void Increase(void) const ;
    
    /** ��С���ü���,������ü�����С��0�������Destroy
    */
    void Decrease(void) const ;
    
protected:
    
    /** Ĭ�Ϲ��캯��
    */
    RCRefCounted() ;
    
    /** Ĭ����������
    */
    virtual ~RCRefCounted() ;
    
    /** ���ٶ���
    */
    virtual void Destroy() ;
    
private:
    
    /** ���ü���
    */
    mutable long m_lRefCount ;
};

END_NAMESPACE_RCZIP

#endif //__RCRefCounted_h_
