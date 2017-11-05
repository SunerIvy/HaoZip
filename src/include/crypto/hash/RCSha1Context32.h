/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1Context32_h_
#define __RCSha1Context32_h_ 1

#include "crypto/hash/RCSha1ContextBase2.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 ������
*/
class RCSha1Context32:
    public RCSha1ContextBase2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1Context32() ;
    
    /** Ĭ����������
    */
    ~RCSha1Context32() ;
public:

    /** ����
    @param [in] data ����
    @param [in] size ���ݴ�С
    */
    void Update(const uint32_t *data, size_t size);

    /** ��������
    @param [out] digest ���ؼ�����
    */
    void Final(uint32_t *digest);
};

END_NAMESPACE_RCZIP

#endif //__RCSha1Context32_h_
