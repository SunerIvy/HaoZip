/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateNsisCOMDecoder_h_
#define __RCDeflateNsisCOMDecoder_h_ 1

#include "compress/deflate/RCDeflateDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate NSIS ������
*/
class RCDeflateNsisCOMDecoder:
    public RCDeflateDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateNsisCOMDecoder():
        RCDeflateDecoder(false,true)
    {
    };
    
    /** Ĭ����������
    */
    virtual ~RCDeflateNsisCOMDecoder() {} ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateNsisCOMDecoder_h_
