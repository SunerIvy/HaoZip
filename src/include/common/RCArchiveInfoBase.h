/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveInfoBase_h_
#define __RCArchiveInfoBase_h_ 1

#include "interface/IArchiveInfo.h"
#include "base/RCRefCounted.h"

BEGIN_NAMESPACE_RCZIP

/** ����빫�û��࣬ʵ�����ü�������
*/
class RCArchiveInfoBase:
    public IArchiveInfo,
    public RCRefCounted
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveInfoBase() ;
    
    /** Ĭ����������
    */
    virtual ~RCArchiveInfoBase() ;

public:
      
    /** �������ü���
    */
    virtual void AddRef(void) ;
    
    /** �������ü���
    */
    virtual void Release(void) ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveInfoBase_h_
