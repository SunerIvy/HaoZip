/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdateFileFilter_h_
#define __RCUpdateFileFilter_h_ 1

#include "base/RCDefs.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** �ļ�����
*/
class RCFileFilter
{
public:

    /** �ļ�
    */
    RCString m_fileList;

    /** ѹ���㷨ID
    */
    RCMethodID m_methodID;

    /** ����
    */
    int32_t m_level;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdateFileFilter_h_
