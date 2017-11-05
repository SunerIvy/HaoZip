/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMethodProps_h_
#define __RCMethodProps_h_ 1

#include "interface/RCPropertyID.h"
#include "common/RCVariant.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

struct RCArchiveProp
{
    /** ����id
    */
    RCPropertyID m_id ;

    /** ����ֵ
    */
    RCVariant m_value ;
};

struct RCArchiveMethod
{
    /** ����id
    */
    RCMethodID m_id ;

    /** ����ֵ
    */
    RCVector<RCArchiveProp> m_properties ;
};

class IUnknown ;

class RCMethodProps
{
public:

    /** ���÷�������
    @param [in] method ����
    @param [in] inSizeForReduce �����С
    @param [in] coder ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult SetMethodProperties(const RCArchiveMethod& method, 
                                       const uint64_t* inSizeForReduce, 
                                       IUnknown* coder);
};

END_NAMESPACE_RCZIP

#endif //__RCMethodProps_h_
