/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSetProperties_h_
#define __RCSetProperties_h_ 1

#include "interface/IUnknown.h"
#include "common/RCVariant.h"
#include "common/RCVector.h"
#include "archive/common/RCArchiveProperty.h"

BEGIN_NAMESPACE_RCZIP

/** ��������
*/
class RCSetProperties
{
public:

    /** ��������
    @param [in] unknown Known�ӿ�
    @param [in] properties ��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult SetProperties(IUnknown* unknown, const RCVector<RCArchiveProperty>& properties) ;

private:

    /** �����ַ���
    @param [in] s �ַ���
    @param [in] prop variant
    */
    static void ParseNumberString(const RCString& s, RCVariant& prop) ;    
};

END_NAMESPACE_RCZIP

#endif //__RCSetProperties_h_
