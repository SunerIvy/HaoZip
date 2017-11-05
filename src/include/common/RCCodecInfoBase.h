/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCodecInfoBase_h_
#define __RCCodecInfoBase_h_ 1

#include "interface/ICodecInfo.h"
#include "base/RCRefCounted.h"

BEGIN_NAMESPACE_RCZIP

/** ����빫�û��࣬ʵ�����ü�������
*/
class RCCodecInfoBase:
    public ICodecInfo,
    public RCRefCounted
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCodecInfoBase() ;
    
    /** Ĭ����������
    */
    virtual ~RCCodecInfoBase() ;

public:
    
    /** �������ü���
    */
    virtual void AddRef(void) ;
    
    /** �������ü���
    */
    virtual void Release() ;
};

END_NAMESPACE_RCZIP

#endif //__RCCodecInfoBase_h_
