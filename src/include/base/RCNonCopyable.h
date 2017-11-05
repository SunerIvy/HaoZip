/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCNonCopyable_h_
#define __RCNonCopyable_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

#ifdef _DEBUG

/** ��ֹ�����ƵĹ��û���
*/
class RCNonCopyable
{    
protected:
    
    /** Ĭ�Ϲ��캯��
    */
    RCNonCopyable() {} ;
    
    /** Ĭ����������
    */
    ~RCNonCopyable() {} ;

private:

    /** �������캯��
    */
    RCNonCopyable(const RCNonCopyable& from) ;
    
    /** ��ֵ������
    */
    const RCNonCopyable& operator= (const RCNonCopyable& from) ;
};

#else

/** Release�汾�Ŀջ����Ż�
*/
class RCNonCopyable
{

};

#endif

END_NAMESPACE_RCZIP

#endif //__RCNonCopyable_h_
