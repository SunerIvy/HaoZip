/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPropertyIDUtils_h_
#define __RCPropertyIDUtils_h_ 1

#include "base/RCString.h"
#include "interface/RCPropertyID.h"
#include "common/RCVariant.h"
#include "filesystem/RCFileDefs.h"
#include "interface/RCArchiveType.h"

BEGIN_NAMESPACE_RCZIP

class RCPropertyIDUtils
{
public:

    /** ������ת���ɿ�����ʾ���ַ���
    @param [in] propID ����ID
    @param [in] propValue ��Ҫת��������ֵ
    @return ������ʾ�õ������ַ��������ʧ�ܷ��ؿմ�
    */
    static RCString ConvertPropertyToString(RCPropIDEnumType propID, 
                                            const RCVariant& propValue) ;

    
    /** ������ת���ɿ�����ʾ���ַ���
    @param [in] propID ����ID
    @param [in] propValue ��Ҫת��������ֵ
    @param [out] value ������ʾ�õ������ַ���
    @return ���ʧ�ܷ���false�� ����ɹ�����true
    */
    static bool ConvertPropertyToString(RCPropIDEnumType propID, 
                                        const RCVariant& propValue,
                                        RCString& value) ;

    /** ���ļ�ʱ��ת�����ַ���
    @param [in] fileTime �ļ�ʱ��
    @param [in] includeTime �Ƿ����ʱ�䣨ָʱ�֣�
    @param [in] includeSeconds �Ƿ������
    @return ������ʾ���ַ��������ʧ�ܷ��ؿմ�
    */
    static RCString ConvertFileTimeToString(const RC_FILE_TIME& fileTime, 
                                            bool includeTime, 
                                            bool includeSeconds) ;
    
    /** ���ļ���Сת�����ַ�����ʾ�� ÿ��λ�ö��ŷָ�
    @param [in] fileSize �ļ���Сֵ
    @return ����ת������ַ���
    */
    static RCString ConvertFileSizeToString(uint64_t fileSize) ;
    
    /** ���ļ���Сת�����ַ�����ʾ�� ��KB/MB����ʾ�� ����KB����ֵ
    @param [in] fileSize �ļ���Сֵ
    @return ����ת������ַ���
    */
    static RCString ConvertFileSize(uint64_t fileSize) ;
    
    /** ���ļ���ʽ����ת��Ϊ�ַ���
    @param [in] archiveType �ļ���ʽֵ
    @return ����ת������ַ���
    */
    static RCString ConvertArchiveType(RCArchiveType archiveType) ;
};

END_NAMESPACE_RCZIP

#endif //__RCPropertyIDUtils_h_
