/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateCOMDecoder64_h_
#define __RCDeflateCOMDecoder64_h_ 1

#include "compress/deflate/RCDeflateDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate 64������
*/
class RCDeflateCOMDecoder64:
    public RCDeflateDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateCOMDecoder64():
        RCDeflateDecoder(true)
    {
    };
    
    /** Ĭ����������
    */
    virtual ~RCDeflateCOMDecoder64() {} ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateCOMDecoder64_h_
