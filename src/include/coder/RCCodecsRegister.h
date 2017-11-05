/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCodecsRegister_h_
#define __RCCodecsRegister_h_ 1

#include "coder/RCCodecsManager.h"

BEGIN_NAMESPACE_RCZIP

/** �Ӵ����о�̬�������� 
*/
class RCCodecsRegister:
    public RCCodecsManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCodecsRegister() ;
    
    /** Ĭ����������
    */
    virtual ~RCCodecsRegister() ;
    
public:
    
    /** ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult LoadCodecs(void) ;
};

END_NAMESPACE_RCZIP

#endif //__RCCodecsRegister_h_
