/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "base/RCString.h"

#ifndef __RCDefaultName_h_
#define __RCDefaultName_h_ 1

BEGIN_NAMESPACE_RCZIP

/** ȱʡ����
*/
class RCDefaultName
{
public:

    /** ����ȱʡ����2
    @param [in] fileName �ļ���
    @param [in] extension �ļ���չ��
    @param [in] addSubExtension �������չ��
    @return ����ȱʡ�ļ���
    */
    static RCString GetDefaultName2(const RCString& fileName,
                                    const RCString& extension,
                                    const RCString& addSubExtension) ;
private:

    /** ����ȱʡ����3
    @param [in] fileName �ļ���
    @param [in] extension �ļ���չ��
    @param [in] addSubExtension �������չ��
    @return ����ȱʡ�ļ���
    */
    static RCString GetDefaultName3(const RCString& fileName,
                                    const RCString& extension, 
                                    const RCString& addSubExtension) ;

private:
    
    /** ���ļ�����
    */
    static const RCString s_emptyFileAlias;
};

END_NAMESPACE_RCZIP

#endif //__RCDefaultName_h_
