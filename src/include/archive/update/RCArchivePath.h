/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchivePath_h_
#define __RCArchivePath_h_ 1

#include "base/RCDefs.h"
#include "base/RCTypes.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ĵ�·��
*/
class RCArchivePath
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchivePath() ;
    
    /** Ĭ����������
    */
    ~RCArchivePath() ;
    
    /** �������캯��
    */
    RCArchivePath(const RCArchivePath& rhs) ;
    
    /** ��ֵ������
    */
    RCArchivePath& operator= (const RCArchivePath& rhs) ;
    
public:

    /** ���ַ���������Ϣ
    @param [in] path ·��
    */
    void ParseFromPath(const RCString& path);

    /** ȡ���ļ�·��,������չ��
    @return �����ļ�·��,������չ��
    */
    RCString GetPathWithoutExt() const;

    /** ȡ����ʱĿ¼
    @return ������ʱĿ¼
    */
    RCString GetTempPath_() const;

    /** ȡ������·��
    @return ��������·��
    */
    RCString GetFinalPath() const;

public:
    
    /** �����ļ�(Ŀ¼)ǰ׺����\
    @param [in] prefix ǰ׺
    */
    void SetPrefix(const RCString& prefix) ;

    /** �����ļ���
    @param [in] name �ļ���
    */
    void SetName(const RCString& name) ;

    /** �����ļ���չ��
    @param [in] baseExtension ��չ��
    */
    void SetBaseExtension(const RCString& baseExtension) ;

    /** ���÷־��ļ���չ��
    @param [in] volExtension �־���չ��
    */
    void SetVolExtension(const RCString& volExtension) ;

    /** �����Ƿ�ʹ����ʱĿ¼
    @param [in] temp �Ƿ�ʹ����ʱĿ¼
    */
    void SetTemp(bool temp) ;

    /** ������ʱĿ¼ǰ׺
    @param [in] tempPrefix ��ʱĿ¼ǰ׺
    */
    void SetTempPrefix(const RCString& tempPrefix) ;

    /** ������ʱ�ļ���׺��
    @param [in] tempPostfix ��ʱĿ¼��׺
    */
    void SetTempPostfix(const RCString& tempPostfix) ;

public:
    
    /** ��ȡ�ļ�(Ŀ¼)ǰ׺����\
    @return ����ǰ׺
    */
    const RCString& GetPrefix(void) const ;

    /** ��ȡ�ļ���
    @return �����ļ���
    */
    const RCString& GetName(void) const ;

    /** ��ȡ�ļ���չ��
    @return ������չ��
    */
    const RCString& GetBaseExtension(void) const ;

    /** ��ȡ�־��ļ���չ��
    @return ���ط־���չ��
    */
    const RCString& GetVolExtension(void) const ;

    /** ��ȡ�Ƿ�ʹ����ʱĿ¼
    @return ʹ����ʱĿ¼����true,���򷵻�false
    */
    bool GetTemp(void) const;

    /** ��ȡ��ʱĿ¼ǰ׺
    @return ������ʱĿ¼ǰ׺
    */
    RCString& GetTempPrefix(void);

    /** ��ȡ��ʱ�ļ���׺��
    @return ������ʱĿ¼��׺
    */
    const RCString& GetTempPostfix(void) const;

private:
    
    /** �ļ�(Ŀ¼)ǰ׺����\
    */
    RCString m_prefix ;

    /** �ļ���
    */
    RCString m_name ;

    /** �ļ���չ��
    */
    RCString m_baseExtension ;

    /** �־��ļ���չ��
    */
    RCString m_volExtension ;

    /** �Ƿ�ʹ����ʱĿ¼
    */
    bool m_temp ;

    /** ��ʱĿ¼ǰ׺
    */
    RCString m_tempPrefix ;

    /** ��ʱ�ļ���׺��
    */
    RCString m_tempPostfix ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchivePath_h_
