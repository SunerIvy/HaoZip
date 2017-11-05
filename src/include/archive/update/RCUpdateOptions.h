/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdateOptions_h_
#define __RCUpdateOptions_h_ 1

#include "base/RCTypes.h"
#include "archive/update/RCCompressMethodMode.h"
#include "archive/update/RCUpdateArchiveCommand.h"
#include "archive/update/RCArchivePath.h"
#include "archive/update/RCArchiveUpdateFilter.h"
#include "archive/common/IEnumDirItemFilter.h"

BEGIN_NAMESPACE_RCZIP

class RCArchiveCodecs;
class IOutStreamEvent ;

/** ѹ��updateѡ�����
*/
class RCUpdateOptions
{
public:
    /** ���캯��
    */
    RCUpdateOptions() ;

public:
    
    /** ����·��ģʽ
    */
    enum path_mode
    {
        RC_UPDATE_RELATIVE_PATH = 0 ,
        RC_UPDATE_ABSOLUTE_PATH = 1 ,
        RC_UPDATE_NO_PATH       = 2 ,
        RC_UPDATE_ABSOLUTE_FULL_PATH = 3
    };
    
    /** ѹ������ģʽ
    */
    enum update_mode
    {
        RC_COMPRESS_FILES_ADD_REPLACE       = 0 ,
        RC_COMPRESS_FILES_ADD_UPDATE        = 1 ,
        RC_COMPRESS_FILES_UPDATE_EXIST_ONLY = 2 ,
        RC_COMPRESS_FILES_SYNC_CONTENT      = 3
    };
    
public:
    /** ��ʼ��
    @param [in] codecs ���������
    @param [in] formatIndices �ĵ���ʽ�б�
    @param [in] arcPath �ĵ�·��
    @param [in] pathMode ����·��ģʽ
    @param [in] updateMode ѹ������ģʽ
    @return �ɹ�����true,���򷵻�false
    */
    bool Init(const RCArchiveCodecs* codecs,
              const RCUIntVector& formatIndices, 
              const RCString& arcPath,
              RCUpdateOptions::path_mode pathMode = RC_UPDATE_RELATIVE_PATH,
              RCUpdateOptions::update_mode updateMode = RC_COMPRESS_FILES_ADD_REPLACE);
                
public:
    
    /** ȡ��ѹ����ʽ
    @return ����ѹ����ʽ
    */
    const RCCompressMethodMode& GetMethodMode(void) const;
    
    /** ȡ��ѹ����ʽ
    @return ����ѹ����ʽ
    */
    RCCompressMethodMode& GetMethodMode(void);

    /** ȡ��ѹ�������б�
    @return ����ѹ�������б�
    */
    const std::vector<RCUpdateArchiveCommand>& GetCommands(void) const;
        
    /** ȡ��ѹ�������б�
    @return ����ѹ�������б�
    */
    std::vector<RCUpdateArchiveCommand>& GetCommands(void);

    /** �Ƿ�����ĵ�
    @return �����ĵ�������true,���򷵻�false
    */
    bool GetUpdateArchiveItSelf(void) const;
    
    /** ���ø����ĵ�
    @param [in] updateArchiveItSelf �����ĵ�
    */
    void SetUpdateArchiveItSelf(bool updateArchiveItSelf);

    /** �����ĵ�·��
    @return �����ĵ�·��
    */
    const RCArchivePath& GetArchivePath(void) const;
    
    /** �����ĵ�·��
    @return �����ĵ�·��
    */
    RCArchivePath& GetArchivePath(void);

    /** �Խ�ѹģʽ
    @return �Խ�ѹģʽ����true,���򷵻�false
    */
    bool GetSfxMode(void) const;
    
    /** �����Խ�ѹģʽ
    @param [in] sfxMode �Խ�ѹģʽ
    */
    void SetSfxMode(bool sfxMode);

    /** �����Խ�ѹģ���ļ���
    @return �����Խ�ѹģ���ļ���
    */
    const RCString& GetSfxModule(void) const;
    
    /** �����Խ�ѹģ���ļ���
    @param [in] sfxModule �Խ�ѹģ��
    */
    void SetSfxModule(const RCString& sfxModule);

    /** ���ع���д
    @return ����д����true,���򷵻�false
    */
    bool GetOpenShareForWrite(void) const;
    
    /** ���ù���д
    @param [in] openShareForWrite ����д
    */
    void SetOpenShareForWrite(bool openShareForWrite);

    /** ��׼����ģʽ
    @return ��׼����ģʽ����true,���򷵻�false
    */
    bool GetStdInMode(void) const;
    
    /** ���ñ�׼����ģʽ
    @param [in] stdInMode ��׼����ģʽ
    */
    void SetStdInMode(bool stdInMode);

    /** ���ر�׼�����ļ���
    @return ���ر�׼�����ļ���
    */
    const RCString& GetStdInFileName(void) const;
    
    /** ���ñ�׼�����ļ���
    @param [in] stdInFileName ��׼�����ļ���
    */
    void SetStdInFileName(const RCString& stdInFileName);

    /** �Ƿ��׼���
    @return ��׼�������true,���򷵻�false
    */
    bool GetStdOutMode(void) const;
    
    /** ���ñ�׼���
    @param [in] stdOutMode ��׼���ģʽ
    */
    void SetStdOutMode(bool stdOutMode);
    
    /** �Ƿ����ģʽ
    @return ����ģʽ����true,���򷵻�false
    */
    bool IsTestMode(void) const ;
    
    /** ���ò���ģʽ
    @param [in] isTestMode ����ģʽ
    */
    void SetIsTestMode(bool isTestMode);

    /** �Ƿ�Email ģʽ
    @return Emailģʽ����true�����򷵻�false
    */
    bool GetEmailMode(void) const;
    
    /** ����Emailģʽ
    @param [in] emailMode Emailģʽ
    */
    void SetEmailMode(bool emailMode);

    /** �Ƿ�����ɾ��
    @return email��ɾ������true�����򷵻�false
    */
    bool GetEmailRemoveAfter(void) const;
    
    /** ����Email��ɾ��
    @param [in] emailRemoveAfter ������ɾ��
    */
    void SetEmailRemoveAfter(bool emailRemoveAfter);

    /** �����ʼ���ַ
    @return �����ʼ�������ַ
    */
    const RCString& GetEmailAddress(void) const;
    
    /** �����ʼ���ַ
    @param [in] emailAddress �ʼ����͵�ַ
    */
    void SetEmailAddress(const RCString& emailAddress);

    /** ���ع���Ŀ¼
    @return ���ع���Ŀ¼
    */
    const RCString& GetWorkDir(void) const;
    
    /** ���ù���Ŀ¼
    @param [in] workDir ����Ŀ¼
    */
    void SetWorkDir(const RCString& workDir);

    /** ȡ�÷־��С�б�
    @return ���ط־��С�б�
    */
    const std::vector<uint64_t>& GetVolumnSizes(void) const;
    
    /** ȡ�÷־��С�б�
    @return ���ط־��С�б�
    */
    std::vector<uint64_t>& GetVolumnSizes(void);
        
    /** ��ȡ����·��ģʽ
    @return ����·������ģʽ
    */
    RCUpdateOptions::path_mode GetPathMode() const ;
        
    /** ��ȡ���·�ʽ
    @return ���ظ��·�ʽ
    */
    RCUpdateOptions::update_mode GetUpdateMode() const ;
        
    /** ����IOд���¼�����
    @param [in] outStreamEvent ������¼��ӿ�
    */
    void SetOutStreamEvent(IOutStreamEvent* outStreamEvent) ;
    
    /** ��ȡIOд���¼�����
    @return ����������¼��ӿ�
    */
    IOutStreamEvent* GetOutStreamEvent() const ;
    
    /** ����ѹ���ļ�������
    @param [in] spUpdateFilter ѹ���ļ�������
    */
    void SetUpdateFileter(const RCArchiveUpdateFilterPtr& spUpdateFilter) ;
    
    /** ��ȡѹ���ļ�������
    @return ����ѹ���ļ�������
    */
    RCArchiveUpdateFilterPtr GetUpdateFileter(void) const ;
    
    /** ���ñ�ѹ�����ļ�������
    @param [in] spEnumDirItemFilter �ļ�ö�ٹ�����
    */
    void SetEnumDirItemFilter(const IEnumDirItemFilterPtr& spEnumDirItemFilter) ;
    
    /** ��ȡ��ѹ�����ļ�������
    @return ���ر�ѹ�����ļ�������
    */
    IEnumDirItemFilterPtr GetEnumDirItemFilter(void) const ;

private:
    
    /** ѹ������ģʽ
    */
    RCCompressMethodMode m_methodMode;

    /** ����
    */
    std::vector<RCUpdateArchiveCommand> m_commands;

    /** 
    */
    bool m_updateArchiveItSelf;

    /** �ĵ�·����Ϣ
    */
    RCArchivePath m_archivePath;

    /** �Խ�ѹģʽ
    */
    bool m_sfxMode;

    /** �Խ�ѹģ������
    */
    RCString m_sfxModule;

    /** ����д��
    */
    bool m_openShareForWrite;

    /** ��׼����ģʽ
    */
    bool m_stdInMode;

    /** ��׼�����ļ�����
    */
    RCString m_stdInFileName;

    /** ��׼���ģʽ
    */
    bool m_stdOutMode;
    
    /** �Ƿ�Ϊ����ģʽ, ����ģʽ������ѹ������ֻ��ѹ������
    */
    bool m_isTestMode ;

    /** �����ʼ�ģʽ
    */
    bool m_emailMode;

    /** ���ͺ�ɾ���ĵ�
    */
    bool m_emailRemoveAfter;

    /** �����ʼ���ַ
    */
    RCString m_emailAddress;

    /** ����Ŀ¼
    */
    RCString m_workingDir;

    /** �־��С
    */
    std::vector<uint64_t> m_volumnsSizes;
        
    /** ����·��ģʽ
    */
    RCUpdateOptions::path_mode m_pathMode ;
        
    /** ���·�ʽ
    */
    RCUpdateOptions::update_mode m_updateMode ;

    /** IO �¼�����
    */
    IOutStreamEvent* m_outStreamEvent ;
    
    /** ѹ���ļ�������
    */
    RCArchiveUpdateFilterPtr m_spUpdateFilter ;
    
    /** ȱʡ�ĵ�����
    */
    static RCString s_kDefaultArchiveType;
    
    /** �Խ�ѹ��չ��
    */
    static RCString s_kSFXExtension;
    
    /** ��ѹ�����ļ�������
    */
    IEnumDirItemFilterPtr m_spEnumDirItemFilter ;
};

END_NAMESPACE_RCZIP

#endif  //__RCUpdateOptions_h_
