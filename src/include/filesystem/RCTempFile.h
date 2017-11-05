/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTempFile_h_
#define __RCTempFile_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCTempFile:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCTempFile() ;
    
    /** Ĭ����������
    */
    ~RCTempFile() ;
    
public:
    /** ������ʱ���ֹɾ���ļ�
    */
    void DisableDeleting() ;
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [in] dirPath ������ʱ�ļ���Ŀ¼
    @param [out] resultPath ���ش�������ʱ�ļ�������������·��
    @return �ɹ�����true�����򷵻�false
    */
    bool CreateTempFile(const RCString& dirPath, RCString& resultPath);
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [out] resultPath ���ش�������ʱ�ļ�������������·��
    @return �ɹ�����true�����򷵻�false
    */
    bool CreateTempFile(RCString& resultPath);
       
    /** ɾ���ļ�
    @return �ɹ�ɾ������true�����򷵻�false
    */
    bool Remove();
    
    /** ��ȡ��ʱ�ļ���
    @return ������ʱ�ļ�����������·��
    */
    const RCString& GetFileName(void) const ;
    
private:
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [in] dirPath ������ʱ�ļ���Ŀ¼
    @param [in] prefix ������ʱ�ļ��õ��ļ�ǰ׺
    @param [out] resultPath ���ش�������ʱ�ļ�������������·��
    @return �ɹ�����true�����򷵻�false
    */
    bool Create(const RCString& dirPath, const RCString& prefix, RCString& resultPath) ;
    
    /** ������ʱ�ļ�����ͬʱ����ɾ�����
    @param [in] prefix ������ʱ�ļ���Ŀ¼ǰ׺
    @param [out] resultPath ���ش�������ʱ�ļ�������������·��
    @return �ɹ�����true�����򷵻�false
    */
    bool Create(const RCString& prefix, RCString& resultPath) ;
    
private:
    
    /** ������ʱ���Ƿ���Ҫɾ���ı��
    */
    bool m_mustBeDeleted ;
    
    /** ��ʱ�ļ���
    */
    RCString m_fileName ;
};

END_NAMESPACE_RCZIP

#endif //__RCTempFile_h_
