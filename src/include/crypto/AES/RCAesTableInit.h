/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCAesTableInit_h_
#define __RCAesTableInit_h_ 1

#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

/** Aes ���ʼ��
*/
class RCAesTableInitImpl
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCAesTableInitImpl() ;
    
    /** Ĭ����������
    */
    ~RCAesTableInitImpl() ;
};

typedef RCSingleton<RCAesTableInitImpl> RCAesTableInit ;

END_NAMESPACE_RCZIP

#endif //__RCAesTableInit_h_
