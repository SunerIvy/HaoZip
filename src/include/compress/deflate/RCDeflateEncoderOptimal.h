/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateEncoderOptimal_h_
#define __RCDeflateEncoderOptimal_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Defalte �����Ż�
*/
class RCDeflateEncoderOptimal
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateEncoderOptimal() ;
    
    /** Ĭ����������
    */
    ~RCDeflateEncoderOptimal() ;
    
public:
    
    /** Ȩ��
    */
    uint32_t m_price ;
    
    /** Pos Prev
    */
    uint16_t m_posPrev ;
    
    /** Back Prev
    */
    uint16_t m_backPrev ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateEncoderOptimal_h_
