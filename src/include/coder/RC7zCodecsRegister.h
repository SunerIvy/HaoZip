/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zCodecsRegister_h_
#define __RC7zCodecsRegister_h_ 1

#include "coder/RCCodecsManager.h"

BEGIN_NAMESPACE_RCZIP

/** 7z�Խ�ѹģ�����ע��
*/
class RC7zCodecsRegister:
    public RCCodecsManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zCodecsRegister() ;
    
    /** Ĭ����������
    */
    virtual ~RC7zCodecsRegister() ;
    
public:
    
    /** ���������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult LoadCodecs(void) ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zCodecsRegister_h_