/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtractMode_h
#define __RCExtractMode_h 1

#include "base/RCTypes.h"

BEGIN_NAMESPACE_RCZIP

/** ��ѹ��������
*/
class RCExtractDefs
{
public:
    
    /** ���·�ʽ
    */
    enum update_type
    {
        /** ��ѹ���滻�ļ�
        */
        RC_EXTRACT_REPLACE      = 0 ,
        
        /** ��ѹ�������ļ�
        */
        RC_EXTRACT_UPDATE       = 1 ,
        
        /** ���������Ѿ����ڵ��ļ�
        */
        RC_EXTRACT_UPDATE_EXIST = 2
    };
    
    /** ��ѹ·��ģʽ
    */
    enum path_type
    {
        /** ��ѹ��ȫ·��
        */
        RC_EXTRACT_FULL_PATH     = 0 ,
    
        /** ����ѹ·��
        */
        RC_EXTRACT_NO_PATH       = 1 ,
    
        /** ��ѹ����·��
        */
        RC_EXTRACT_ABSOLUTE_PATH = 2 ,
        
        /** ��ѹ��ǰ·��
        */
        RC_EXTRACT_CURRENT_PATH = 3
    };
    
    /** ��ѹ����ģʽ
    */
    enum overwrite_type
    {
        /** ����ǰ��ʾȷ��
        */
        RC_ASK_BEFORE           = 0 ,
        
        /** ����ǰ����ʾ
        */
        RC_WITHOUT_PROMPT       = 1 ,
        
        /** �����Ѿ����ڵ��ļ���������
        */
        RC_SKIP_EXISTING        = 2 ,
        
        /** �����ļ��Զ�������
        */
        RC_AUTO_RENAME          = 3 ,
        
        /** �Ծ��ļ��Զ�������
        */
        RC_AUTO_RENAME_EXISTING = 4
    };
    
    /** �ļ����ǻش�����
    */
    enum overwrite_answer_type
    {
        RC_ANSWER_YES               = 0 ,
        RC_ANSWER_YES_TO_ALL        = 1 ,
        RC_ANSWER_NO                = 2 ,
        RC_ANSWER_NO_TO_ALL         = 3 ,
        RC_ANSWER_AUTO_RENAME       = 4 ,
        RC_ANSWER_AUTO_RENAME_ALL   = 5 ,
        RC_ANSWER_USER_RENAME       = 6 ,
        RC_ANSWER_CANCEL            = 7
    };
    
    /** ��ѹѯ������
    */
    enum ask_mode_type
    {
        RC_ASK_EXTRACT  = 0 ,
        RC_ASK_TEST     = 1 ,
        RC_ASK_SKIP     = 2
    };
    
    /** ��ѹ���
    */
    enum result_type
    {
        RC_EXTRACT_OK                   = 0 ,
        RC_EXTRACT_UNSUPPORTED_METHOD   = 1 ,
        RC_EXTRACT_DATA_ERROR           = 2 ,
        RC_EXTRACT_CRC_ERROR            = 3
    };
    
    /** ��ѹ�ļ�ʱ��ѡ��
    */
    enum file_time_flag
    {
        /** �����ļ��޸�ʱ��
        */
        RC_EXTRACT_FILE_SAVE_MTIME      = 1 << 1 ,
        
        /** �����ļ�����ʱ��
        */
        RC_EXTRACT_FILE_SAVE_CTIME      = 1 << 2 ,

        /** �����ļ�������ʱ��
        */
        RC_EXTRACT_FILE_SAVE_ATIME      = 1 << 3
    };
};

typedef RCExtractDefs::update_type              RCExractUpdateMode ;
typedef RCExtractDefs::path_type                RCExractPathMode ;
typedef RCExtractDefs::overwrite_type           RCExractOverwriteMode ;
typedef RCExtractDefs::overwrite_answer_type    RCExractOverwriteAnswer ;
typedef RCExtractDefs::ask_mode_type            RCExractAskMode ;
typedef RCExtractDefs::result_type              RCExractOperationResult ;
typedef uint32_t                                RCExractFileTimeFlag ;

END_NAMESPACE_RCZIP
#endif
