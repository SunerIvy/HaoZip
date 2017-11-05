/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSingleton_h_
#define __RCSingleton_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Singleton ģ��
    �÷���
        class A ;
        typedef RCSingleton<T> B ;
*/
template <class T>
class RCSingleton:
    private T
{
public:
    
    /** ��ȡSingleton����
    */
    static T& Instance() ;

#ifdef _DEBUG
private:
    
    /** Ĭ�Ϲ��캯��
    */
    RCSingleton() {} ;
    
    /** Ĭ����������
    */
    ~RCSingleton() {} ;

    /** �������캯��
    */
    RCSingleton(const RCSingleton& rhs) ;
    
    /** ��ֵ������
    */
    RCSingleton& operator= (const RCSingleton& rhs) ;
#endif

};

/** ��������ʵ�֣����̰߳�ȫ����Ҫ�����߿����̰߳�ȫ��
@return ���ص������������
*/
template <class T>
T& RCSingleton<T>::Instance()
{
    static RCSingleton<T> sObject ;
    return (sObject);
}

END_NAMESPACE_RCZIP

#endif //__RCSingleton_h_
