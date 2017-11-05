/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1ContextBase2_h_
#define __RCSha1ContextBase2_h_ 1

#include "crypto/hash/RCSha1ContextBase.h"
#include "crypto/hash/RCSha1Defs.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 �����Ļ���2
*/
class RCSha1ContextBase2:
    public RCSha1ContextBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1ContextBase2() ;
    
    /** Ĭ����������
    */
    ~RCSha1ContextBase2() ;

public:

    /** ��ʼ��
    */
    void Init() ;

protected:

    /** ���¿�
    */
    void UpdateBlock() ;
            
protected:

    /** ����
    */
    uint32_t m_count2 ;

    /** ����
    */
    uint32_t m_buffer[RCSha1Defs::kBlockSizeInWords];  
};

END_NAMESPACE_RCZIP

#endif //__RCSha1ContextBase2_h_
