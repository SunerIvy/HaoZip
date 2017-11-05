/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveRegister_h_
#define __RCArchiveRegister_h_ 1

#include "archive/manager/RCArchiveManager.h"

BEGIN_NAMESPACE_RCZIP

/** �Ӵ����о�̬�����ĵ���ʽ��Ϣ 
*/
class RCArchiveRegister:
    public RCArchiveManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveRegister() ;
    
    /** Ĭ����������
    */
    virtual ~RCArchiveRegister() ;
    
public:
    
    /** �����ĵ���ʽ
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult LoadArchives(void) ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveRegister_h_
