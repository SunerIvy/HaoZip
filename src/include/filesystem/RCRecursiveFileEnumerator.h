/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRecursiveFileEnumerator_h_
#define __RCRecursiveFileEnumerator_h_ 1

#include "filesystem/RCFileInfo.h"

BEGIN_NAMESPACE_RCZIP

class RCFileEnumeratorCallback ;

/** ������ȡһ��Ŀ¼�Լ���Ŀ¼�е������ļ�
    ��ȡ�ݹ����ģʽ
*/
class RCRecursiveFileEnumerator
{    
public:
    
    /** ����Ŀ¼�Լ��ݹ�����Ŀ¼��ȡ�ļ�
    @param [in] path ��Ҫ������Ŀ¼, ��C:\
    @param [in] callback �����ص�����, ������ΪNULL
    @return �ɹ����� RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult Recusive(RCString path, 
                     RCFileEnumeratorCallback* callback) ;
    

};

END_NAMESPACE_RCZIP

#endif //__RCRecursiveFileEnumerator_h_
