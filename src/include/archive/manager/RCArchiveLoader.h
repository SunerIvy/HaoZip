/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveLoader_h_
#define __RCArchiveLoader_h_ 1

#include "archive/manager/RCArchiveManager.h"

BEGIN_NAMESPACE_RCZIP

/** �����ĵ���ʽ��Ϣ 
*/
class RCArchiveLoader:
    public RCArchiveManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveLoader() ;
    
    /** Ĭ����������
    */
    virtual ~RCArchiveLoader() ;
    
public:
    
    /** ��IArchiveInfo�ӿ������ĵ�������
    @param [in] archiveInfo IArchiveInfo�ӿ�ָ��
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    HResult LoadFormat(IArchiveInfo* archiveInfo) ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveLoader_h_
