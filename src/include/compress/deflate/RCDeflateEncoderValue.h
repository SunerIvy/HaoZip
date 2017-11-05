/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateEncoderValue_h_
#define __RCDeflateEncoderValue_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate ����ֵ
*/
class RCDeflateEncoderValue
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateEncoderValue() ;
    
    /** Ĭ����������
    */
    ~RCDeflateEncoderValue() ;
    
public:
    
    /** �����Ƿ��ַ�
    */
    void SetAsLiteral() ;
    
    /** �����Ƿ��ַ�
    */
    bool IsLiteral() const ;

public:
    
    /** ����
    */
    uint16_t m_len ;
    
    /** λ��
    */
    uint16_t m_pos ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateEncoderValue_h_
