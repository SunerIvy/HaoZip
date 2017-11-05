/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileInfo_h_
#define __RCFileInfo_h_ 1

#include "base/RCString.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCFileInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCFileInfo() ;
    
    /** Ĭ����������
    */
    ~RCFileInfo() ;
    
public:
    
    /** �����ļ���С
    @param [in] size �ļ���Сֵ
    */
    void SetSize(uint64_t size) ;
    
    /** �����ļ�����ʱ��
    @param [in] cTime �ļ�����ʱ��ֵ
    */
    void SetCreateTime(const RC_FILE_TIME& cTime) ;
    
    /** �����ļ�����ʱ��
    @param [in] aTime �ļ�����ʱ��ֵ
    */
    void SetAccessTime(const RC_FILE_TIME& aTime) ;
    
    /** �����ļ��޸�ʱ��
    @param [in] mTime �ļ��޸�ʱ��ֵ
    */
    void SetModifyTime(const RC_FILE_TIME& mTime) ;
    
    /** �����ļ�����
    @param [in] attrib �ļ�����ֵ
    */
    void SetAttribuite( uint64_t attrib) ;
    
    /** �����ļ���
    @param [in] fileName �ļ���������·��
    */
    void SetFileName(const RCString& fileName) ;
    
    /** ��ȡ�ļ���С
    @return �����ļ���С
    */
    uint64_t GetSize(void) const ;
    
    /** ��ȡ�ļ�����ʱ��
    @return �����ļ�����ʱ��
    */
    const RC_FILE_TIME& GetCreateTime(void) const ;
    
    /** ��ȡ�ļ�����ʱ��
    @return �����ļ�����ʱ��
    */
    const RC_FILE_TIME& GetAccessTime(void) const ;
    
    /** ��ȡ�ļ��޸�ʱ��
    @return �����ļ��޸�ʱ��
    */
    const RC_FILE_TIME& GetModifyTime(void) const ;
    
    /** ��ȡ�ļ�����
    @return �����ļ�����
    */
    uint64_t GetAttribuite(void) const ;
    
    /** ��ȡ�ļ���
    @return �����ļ���
    */
    const RCString& GetFileName(void) const ;
    
    /** �Ƿ���й鵵����
    @return ���Ϊ�鵵���ԣ�����true, ���򷵻�false
    */
    bool IsArchived() const ;
    
    /** �Ƿ����ѹ������
    @return ���Ϊѹ�����ԣ�����true, ���򷵻�false
    */
    bool IsCompressed() const ;
    
    /** �Ƿ�ΪĿ¼
    @return ���ΪĿ¼������true, ���򷵻�false
    */
    bool IsDir() const ;
    
    /** �Ƿ�Ϊ��������
    @return ���Ϊ�������ԣ�����true, ���򷵻�false
    */
    bool IsEncrypted() ;
    
    /** �Ƿ�Ϊ��������
    @return ���Ϊ�������ԣ�����true, ���򷵻�false
    */
    bool IsHidden() const ;
    
    /** �Ƿ�ΪNormal����
    @return ���ΪNormal���ԣ�����true, ���򷵻�false
    */
    bool IsNormal() const ;
    
    /** �Ƿ�Ϊֻ������
    @return ���Ϊֻ�����ԣ�����true, ���򷵻�false
    */
    bool IsReadOnly() const ;
    
    /** �Ƿ�Ϊϵͳ����
    @return ���Ϊϵͳ���ԣ�����true, ���򷵻�false
    */
    bool IsSystem() const ;
    
    /** �Ƿ�Ϊ��ʱ����
    @return ���Ϊ��ʱ���ԣ�����true, ���򷵻�false
    */
    bool IsTemporary() const ;
    
    /** �Ƿ�Ϊ��Ŀ¼
    @return ���Ϊ"." ���� ".."������true, ���򷵻�false
    */
    bool IsDots() const;
    
private:
    
    /** �ļ���С
    */
    uint64_t m_size ;
    
    /** �ļ�����ʱ��
    */
    RC_FILE_TIME m_cTime ;
    
    
    /** �ļ�����ʱ��
    */
    RC_FILE_TIME m_aTime ;
    
    /** �ļ��޸�ʱ��
    */
    RC_FILE_TIME m_mTime ;
    
    /** �ļ�����
    */
    uint64_t m_attrib ;
    
    /** �ļ���
    */
    RCString m_fileName ;
};

END_NAMESPACE_RCZIP

#endif //__RCFileInfo_h_
