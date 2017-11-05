/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdateArchiveCommand_h_
#define __RCUpdateArchiveCommand_h_ 1

#include "base/RCString.h"
#include "archive/update/RCArchivePath.h"
#include "archive/update/RCUpdateAction.h"

BEGIN_NAMESPACE_RCZIP
   
/** �ĵ���������ṹ
*/
class RCUpdateArchiveCommand
{
public:
    
    /** �����û��ĵ�·��
    @param [in] userArchivePath
    */
    void SetUserArchivePath(const RCString& userArchivePath);
    
    /** ȡ���û��ĵ�·��
    @return �����û��ĵ�·��
    */
    const RCString& GetUserArchivePath(void) const;

    /** �����ĵ�·��
    @return �����ĵ�·��
    */
    RCArchivePath& GetArchivePath(void);
    
    /** �����ĵ�·��
    @return �����ĵ�·��
    */
    const RCArchivePath& GetArchivePath(void) const;

    /** ���ظ��²���
    @return ���ظ��²���
    */
    RCActionSet& GetActionSet(void);
    
    /** ���ظ��²���
    @return ���ظ��²���
    */
    const RCActionSet& GetActionSet(void) const;

private:

    /** ʹ���ĵ�·��
    */
    RCString m_userArchivePath;

    /** �ĵ�·��
    */
    RCArchivePath m_archivePath;

    /** ���²�������
    */
    RCActionSet m_actionSet;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdateArchiveCommand_h_
