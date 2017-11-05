/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileEnumeratorCallback_h_
#define __RCFileEnumeratorCallback_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCFileInfo ;

/** �����ļ��ص��ӿ�
*/
class RCFileEnumeratorCallback
{
protected:
    
    /** Ĭ����������
    */
    ~RCFileEnumeratorCallback() {} ;
    
public:
    
    /** ��ȡһ���ļ�
    @param [in] filePath �ļ�·�������һ���ַ�Ϊ·���ָ���
    @param [in] fileName �ļ���������·��
    @param [out] fileInfo ����ȡ�����ļ�������Ϣ
    @return �ɹ�RC_S_OK, ������ز���RC_S_OK�����������������ֹ
    */
    virtual HResult OnFindFile(const RCString& filePath, 
                               const RCString& fileName, 
                               RCFileInfo& fileInfo) = 0 ;
};

END_NAMESPACE_RCZIP

#endif //__RCFileEnumeratorCallback_h_
