/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDSEE2Context_h_
#define __RCPPMDSEE2Context_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** SEE-contexts for PPM-contexts with masked symbols
*/
class RCPPMDSEE2Context:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDSEE2Context() ;
    
    /** Ĭ����������
    */
    ~RCPPMDSEE2Context() ;

public:

    /** �ܼ�
    */
    uint16_t m_summ ;

    /** ƫ��
    */
    byte_t m_shift ;

    /** ����
    */
    byte_t m_count ;

public:

    /** ��ʼ��
    @param [in] InitVal ��ʼֵ
    */
    void init(int32_t InitVal) ;

    /** ȡ��Mean
    @return ����Mean
    */
    uint32_t getMean() ;

    /** ����
    */
    void update() ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDSEE2Context_h_
