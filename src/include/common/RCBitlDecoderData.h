/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBitlDecoderData_h_
#define __RCBitlDecoderData_h_ 1

#include "base/RCDefs.h"
#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

class RCBitlDecoderData
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCBitlDecoderData() ;

public:
    
    /** ����ֵλ��
    */
    static const int32_t s_kNumBigValueBits = 8 * 4;
    
    /** ��ֵ�ֽ���
    */
    static const int32_t s_kNumValueBytes = 3;
    
    /** ��ֵλ��
    */
    static const int32_t s_kNumValueBits = 8  * RCBitlDecoderData::s_kNumValueBytes ;
    
    /** ��ֵ����
    */
    static const uint32_t s_kMask = (1 << s_kNumValueBits) - 1 ;
    
    /** Invert��
    */
    byte_t s_kInvertTable[256] ;    
};

typedef RCSingleton<RCBitlDecoderData>  RCBitlDefs ;

END_NAMESPACE_RCZIP

#endif //__RCBitlDecoderData_h_
