/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFilePathAutoRename_h_
#define __RCFilePathAutoRename_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ļ��Զ�������
*/
class RCFilePathAutoRename
{
public:

    /** �Զ�������
    @param [in] fullProcessedPath ԭ·��
    @return �ɹ�����true,���򷵻�false
    */
    static bool AutoRenamePath(RCString& fullProcessedPath) ;

private:

    /** �����������ļ���
    @param [in] name ԭ�ļ���
    @param [in] extension ��չ��
    @param [in] value ��ֵ
    @param [out] path �������ļ���
    @return �ɹ�����true,���򷵻�false
    */
    static  bool MakeAutoName(const RCString& name,
                              const RCString& extension,
                              int32_t value,
                              RCString& path) ;
};

END_NAMESPACE_RCZIP

#endif //__RCFilePathAutoRename_h_
