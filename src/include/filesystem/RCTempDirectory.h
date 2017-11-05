/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTempDirectory_h_
#define __RCTempDirectory_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCTempDirectory:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCTempDirectory() ;
    
    /** Ĭ����������
    */
    ~RCTempDirectory() ;
    
public:
    
    /** ��ȡ��ʱĿ¼·��
    @return ������ʱ·��
    */
    const RCString& GetPath() const ;
    
    /** ɾ����ʱĿ¼
    @return �ɹ�����true, ʧ���򷵻�false
    */
    bool Remove() ;
    
    /** ����ʱ����ֹɾ����ʱĿ¼
    */
    void DisableDeleting() ;
    
    /** ������ʱĿ¼
    @return �ɹ�����true�����򷵻�false
    */
    bool CreateTempDirectory(void) ;
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [in] dirPath ������ʱĿ¼��Ŀ¼
    @return �ɹ�����true�����򷵻�false
    */
    bool CreateTempDirectory(const RCString& dirPath) ;
    
private:
    
    /** ������ʱĿ¼
    @param [in] prefix ������ʱĿ¼�õ��ļ�ǰ׺
    @return �ɹ�����true�����򷵻�false
    */
    bool Create(const RCString& prefix) ;
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [in] dirPath ������ʱĿ¼��Ŀ¼
    @param [in] prefix ������ʱ�ļ��õ��ļ�ǰ׺
    @return �ɹ�����true�����򷵻�false
    */
    bool Create(const RCString& dirPath, const RCString& prefix) ;
    
private:
    
    /** �Ƿ�ɾ����ʱĿ¼���
    */
    bool m_mustBeDeleted;
    
    /** ��ʱĿ¼·��
    */
    RCString m_tempDir;
};

END_NAMESPACE_RCZIP

#endif //__RCTempDirectory_h_
