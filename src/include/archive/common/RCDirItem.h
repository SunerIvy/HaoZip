/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDirItem_h_
#define __RCDirItem_h_ 1

#include "base/RCString.h"
#include "base/RCWindowsDefs.h"
#include "filesystem/RCFileDefs.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** Ŀ¼��
*/
class RCDirItem
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDirItem() ;
    
    /** Ĭ����������
    */
    ~RCDirItem() ;

private:
        
    /** �������캯��
    @param [in] rhs ��������
    */
    RCDirItem(const RCDirItem& rhs) ;
    
    /** ��ֵ������
    @param [in] rhs ���Ʋ���
    */
    RCDirItem& operator= (const RCDirItem& rhs) ;
    
public:
    
    /** �����ļ���С
    @param [in] size ���С
    */
    void SetSize(uint64_t size) ;
    
    /** �����ļ�����ʱ��
    @param [in] cTime ����ʱ��
    */
    void SetCreateTime(const RC_FILE_TIME& cTime) ;
    
    /** �����ļ�����ʱ��
    @param [in] aTime ����ʱ��
    */
    void SetAccessTime(const RC_FILE_TIME& aTime) ;
    
    /** �����ļ��޸�ʱ��
    @param [in] mTime �޸�ʱ��
    */
    void SetModifyTime(const RC_FILE_TIME& mTime) ;
    
    /** �����ļ�����
    @param [in] attrib ������
    */
    void SetAttribuite( uint64_t attrib) ;
    
    /** �����ļ���
    @param [in] fileName Ŀ¼������
    */
    void SetFileName(const RCString& fileName) ;
    
    /** ���������ڵ�
    @param [in] phyParent �����ڵ�
    */
    void SetPhyParent(int32_t phyParent) ;
    
    /** �����߼����ڵ�
    @param [in] logParent �߼����ڵ�
    */
    void SetLogParent(int32_t logParent) ;
    
    /** ��ȡ�ļ���С
    @return �����ļ���С
    */
    uint64_t GetSize(void) const ;
    
    /** ��ȡ�ļ�����ʱ��
    @return ���ش���ʱ��
    */
    const RC_FILE_TIME& GetCreateTime(void) const ;
    
    /** ��ȡ�ļ�����ʱ��
    @return ���ط���ʱ��
    */
    const RC_FILE_TIME& GetAccessTime(void) const ;
    
    /** ��ȡ�ļ��޸�ʱ��
    @return �����޸�ʱ��
    */
    const RC_FILE_TIME& GetModifyTime(void) const ;
    
    /** ��ȡ�ļ�����
    @return ��������
    */
    uint64_t GetAttribuite(void) const ;
    
    /** ��ȡ�ļ���
    @return �����ļ���
    */
    const RCString& GetFileName(void) const ;
    
    /** ��ȡ�����ڵ�
    @return ���������ڵ�
    */
    int32_t GetPhyParent(void) const ;
    
    /** ��ȡ�߼����ڵ�
    @return �����߼����ڵ�
    */
    int32_t GetLogParent(void) const ;
    
    /** �ж��Ƿ�ΪĿ¼
    @return ��Ŀ¼����true,���򷵻�false
    */
    bool IsDir() const ;
    
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
    
    /** �����ڵ�
    */
    int32_t m_phyParent ;
    
    /** �߼����ڵ�
    */
    int32_t m_logParent;
};

typedef RCSharedPtr<RCDirItem> RCDirItemPtr ; 

END_NAMESPACE_RCZIP

#endif //__RCDirItem_h_
