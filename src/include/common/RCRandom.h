/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRandom_h_
#define __RCRandom_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RCRandom:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRandom() ;
    
    /** Ĭ����������
    */
    ~RCRandom() ;
    
public:
    
    /** ʹ�õ�ǰʱ���ʼ��
    */
    void Init() ;
    
    /** ָ�����ӽ��г�ʼ��
    @param [in] seed ��ʼ����������ֵ
    */
    void Init(uint32_t seed) ;
    
    /** ���������
    @return �������ɵ������ֵ
    */
    int32_t Generate() const ;
};

END_NAMESPACE_RCZIP

#endif //__RCRandom_h_
