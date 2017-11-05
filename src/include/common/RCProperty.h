/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCProperty_h_
#define __RCProperty_h_ 1

#include "base/RCString.h"
#include "interface/RCPropertyID.h"
#include "common/RCVariant.h"
#include <utility>
#include <vector>

BEGIN_NAMESPACE_RCZIP

/** �������ƣ�����ֵ�Ľṹ
    Key   ����������
    Value ������ֵ
*/
typedef std::pair<RCString,RCVariant> RCPropertyNamePair ;

/** ��������
*/    
typedef std::vector<RCPropertyNamePair> RCPropertyNamePairArray ;
    
/** �������ƣ�����ֵ�Ľṹ
    Key   ������ID
    Value ������ֵ
*/
typedef std::pair<RCPropertyID,RCVariant> RCPropertyIDPair ;

/** ��������
*/    
typedef std::vector<RCPropertyIDPair> RCPropertyIDPairArray ;

END_NAMESPACE_RCZIP

#endif //__RCProperty_h_
