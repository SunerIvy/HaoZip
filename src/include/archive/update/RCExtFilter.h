/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdateExtFilter_h_
#define __RCUpdateExtFilter_h_ 1

#include "base/RCDefs.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** ����չ������
*/
class RCExtFilter
{
public:

    /** �ļ���չ��
    */
    RCString m_fileExt;

    /** ѹ���㷨ID
    */
    RCMethodID m_methodID;

    /** ����
    */
    int32_t m_level;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdateExtFilter_h_
