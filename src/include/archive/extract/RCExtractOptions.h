/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtractOptions_h_
#define __RCExtractOptions_h_  1

#include "base/RCTypes.h"
#include "archive/extract/RCExtractDefs.h"
#include "archive/common/RCArchiveProperty.h"
#include "common/RCVector.h"
#include "filesystem/RCFileInfo.h"

BEGIN_NAMESPACE_RCZIP

/** ��ѹѡ�߲���
*/
class RCExtractOptions
{
public:
    
    /** ���캯��
    */
    RCExtractOptions() ;

public:
    
    /** �Ƿ�Ϊ��׼����̨���ģʽ
    */
    bool m_isStdOutMode;
    
    /** ����ģʽ
    */
    bool m_isTestMode ;
    
    /** ��������ʾ��ȷ�ϻش�
    */
    bool m_isYesToAll ;
    
    /** ���·�ʽ
    */
    RCExractUpdateMode m_updateMode ;
    
    /** ·������ģʽ
    */
    RCExractPathMode m_pathMode ;
    
    /** �����ļ�����ģʽ
    */
    RCExractOverwriteMode m_overwriteMode ;
    
    /** �Ƿ������ļ�
    */
    bool m_keepDamageFiles ;

    /** �ĵ��ļ���Ϣ
    */
    RCFileInfo m_archiveFileInfo ;

    /** ���·��
    */
    RCString m_outputDir ;
    
    /** Ĭ��ѹ���ļ���
    */
    RCString m_defaultItemName ;
    
    /** ��ѹ����
    */
    RCVector<RCArchiveProperty> m_properties ;
    
    /** ��ѹ����Ŀ¼
    */
    bool m_extractToSubDir;

    /** �ظ�����Ŀ¼�Ƴ�����
    */
    bool m_removeSameRoot;
    
    /** ��ѹ�ļ�ʱ�����Ա��
    */
    RCExractFileTimeFlag m_fileTimeFlag ;

    /** ��Ҫ�Ƴ���Ŀ¼
    */
    RCVector<RCString> m_setRemovePathList;
};

END_NAMESPACE_RCZIP

#endif //__RCExtractOptions_h_
