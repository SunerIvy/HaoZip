/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCEnumDirItemUpdateCallback_h_
#define __RCEnumDirItemUpdateCallback_h_ 1

#include "archive/common/RCEnumDirItems.h"
#include "archive/update/RCUpdateCallbackUI.h"

BEGIN_NAMESPACE_RCZIP

/** Ŀ¼ö�ٻص��ӿ�ʵ��
*/
struct RCEnumDirItemUpdateCallback : 
    public IEnumDirItemCallback
{
    /** ������»ص��ӿ�ָ��
    */
    RCUpdateCallbackUI2 *m_callback;
    
    /** ����ɨ�����
    @param [in] numFolders Ŀ¼��
    @param [in] numFiles �ļ���
    @param [in] path �ļ�·��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ScanProgress(uint64_t numFolders, uint64_t numFiles, const RCString& path)
    {
        if(m_callback)
        {
            return m_callback->ScanProgress(numFolders, numFiles, path);
        }
        else
        {
            return RC_S_OK ;
        }
    }
};

END_NAMESPACE_RCZIP

#endif //__RCEnumDirItemUpdateCallback_h_
