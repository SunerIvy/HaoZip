/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1Context_h_
#define __RCSha1Context_h_ 1

#include "crypto/hash/RCSha1ContextBase2.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 ������
*/
class RCSha1Context:
    public RCSha1ContextBase2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1Context() ;
    
    /** Ĭ����������
    */
    ~RCSha1Context() ;

public:
    
    /** ����
    @param [in] data ����
    @param [in] size ��С
    @param [in] rar350Mode �Ƿ�rar350ģʽ
    */
    void Update(byte_t *data, size_t size, bool rar350Mode = false);

    /** ����
    @param [in] data ����
    @param [in] size ��С
    */
    void Update(const byte_t *data, size_t size) ;

    /** ��������
    @param [out] digest ���ؽ��
    */
    void Final(byte_t *digest);
};

END_NAMESPACE_RCZIP

#endif //__RCSha1Context_h_
