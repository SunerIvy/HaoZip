/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateCOMDecoder_h_
#define __RCDeflateCOMDecoder_h_ 1

#include "compress/deflate/RCDeflateDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate ������
*/
class RCDeflateCOMDecoder:
    public RCDeflateDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateCOMDecoder():
        RCDeflateDecoder(false)
    {
    };
    
    /** Ĭ����������
    */
    virtual ~RCDeflateCOMDecoder() {} ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateCOMDecoder_h_
