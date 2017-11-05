/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1ContextBase_h_
#define __RCSha1ContextBase_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 �����Ļ���
*/
class RCSha1ContextBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSha1ContextBase() ;
    
    /** Ĭ����������
    */
    ~RCSha1ContextBase() ;
    
public:

    /** ��ʼ��
    */
    void Init();

    /** ȡ�ÿ�ժҪ
    @param [in] blockData ������
    @param [out] destDigest ժҪ
    @param [in] returnRes �Ƿ񷵻�Res
    */
    void GetBlockDigest(uint32_t *blockData, uint32_t *destDigest, bool returnRes = false);
    
    /** PrepareBlock can be used only when size <= 13. size in Words
    @param [in] block ��
    @param [in] size ��С
    */
    void PrepareBlock(uint32_t *block, uint32_t size) const;
    
protected:

    /** ���¿�
    @param [in] data ����
    @param [in] returnRes �Ƿ񷵻�Res
    */
    void UpdateBlock(uint32_t *data, bool returnRes = false) ;
        
protected:
    
    /** ״̬
    */
    uint32_t m_state[5] ;

    /** ����
    */
    uint64_t m_count ;
};

END_NAMESPACE_RCZIP

#endif //__RCSha1ContextBase_h_
