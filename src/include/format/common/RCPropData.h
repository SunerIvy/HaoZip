/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPropData_h_
#define __RCPropData_h_ 1

#include "base/RCString.h"
#include "common/RCVariant.h"

BEGIN_NAMESPACE_RCZIP

struct RCPropData
{
public:

    /** ������
    */
    RCString m_propName ;

    /** ����ID
    */
    uint32_t m_propID ;

    /** ��������
    */
    RCVariantType::RCVariantID m_varType ; 
};

END_NAMESPACE_RCZIP

#endif //__RCPropData_h_
