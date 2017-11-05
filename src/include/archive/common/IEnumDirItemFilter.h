/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IEnumDirItemFilter_h_
#define __IEnumDirItemFilter_h_ 1

#include "base/RCString.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** �ļ���Ϣ��
*/
class RCFileInfo ;

/** ��ѹ���ļ����ų��������ӿ�
*/
class IEnumDirItemFilter
{
public:
    
    /** ��������
    */
    virtual ~IEnumDirItemFilter() {} ;
    
public:
    
    /** ���ļ����й���
    @param [in] filePathPrefix ��ѹ�����ļ�·��ǰ׺
    @param [in] fileInfo ��ѹ�����ļ�����
    @return ����ֵ��RC_S_OK - ��ʾ���ļ��ѱ����ˣ�Ӧ������
                     RC_S_FALSE - ��ʾ���ļ��ɽ���ѹ��
                     ����ֵ����������
                    
    */
    virtual HResult Filter(const RCString& filePathPrefix, const RCFileInfo& fileInfo) = 0 ;
};

/** ����ָ�붨��
*/
typedef RCSharedPtr<IEnumDirItemFilter> IEnumDirItemFilterPtr ;

END_NAMESPACE_RCZIP

#endif //__IEnumDirItemFilter_h_
