/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArcItem_h_
#define __RCArcItem_h_ 1

#include "base/RCString.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ��������Ϣ
*/
class RCArcItem
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArcItem() ;
    
    /** Ĭ����������
    */
    ~RCArcItem() ;
    
public:
    
    /** ���ô�С
    @param [in] size ���С
    */
    void SetSize(uint64_t size) ;
    
    /** �����޸�ʵ��
    @param [in] mTime �޸�ʵ��
    */
    void SetModifyTime(const RC_FILE_TIME& mTime);
    
    /** ����������
    @param [in] name ������
    */
    void SetName(const RCString& name) ;
    
    /** �����Ƿ�ΪĿ¼
    @param [in] isDir �Ƿ�ΪĿ¼
    */
    void SetIsDir(bool isDir);
    
    /** �����Ƿ����С
    @param [in] sizeDefined ��С�Ƿ���
    */
    void SetSizeDefined(bool sizeDefined) ;
    
    /** �����Ƿ����޸�ʱ��
    @param [in] mTimeDefined �޸�ʱ���Ƿ���
    */
    void SetMTimeDefined(bool mTimeDefined) ;
    
    /** �����Ƿ�ͨ���ƥ��
    @param [in] censored �Ƿ�ͨ���ƥ��
    */
    void SetCensored(bool censored) ;
    
    /** �����Ƿ������
    @param [in] indexInServer �������
    */
    void SetIndexInServer(uint32_t indexInServer);
    
    /** ����ʱ������
    @param [in] timeType ʱ������
    */
    void SetTimeType(int32_t timeType) ;
    
    /** �������С
    @return �������С
    */
    uint64_t GetSize(void) const ;
    
    /** �������޸�ʱ��
    @return �������޸�ʱ��
    */
    const RC_FILE_TIME& GetModifyTime(void) const ;
    
    /** ����������
    @return ��������������
    */
    RCString& GetName(void);
    
    /** ����������
    @return ����������
    */
    const RCString& GetName(void) const;
    
    /** �����Ƿ�ΪĿ¼
    @return ��Ŀ¼���� true,���򷵻� false
    */
    bool IsDir(void) const ;
    
    /** �����Ƿ����С
    @return �����С���� true,���򷵻� false
    */
    bool GetSizeDefined(void) const ;
    
    /** �����Ƿ����޸�ʱ��
    @return �����޸�ʱ�䷵�� true,���򷵻� false
    */
    bool GetMTimeDefined(void) const ;
    
    /** �����Ƿ�ͨ���ƥ��
    @return ƥ�䷵��true,���򷵻�false
    */
    bool GetCensored(void) const ;
    
    /** �������
    @return �������
    */
    uint32_t GetIndexInServer(void) const ;
    
    /** ����ʱ������
    @return ����ʱ������
    */
    int32_t GetTimeType(void) const ;
    
private:
    
    /** ��С
    */
    uint64_t m_size ;

    /** �޸�ʱ��
    */
    RC_FILE_TIME m_mTime ;

    /** ����
    */
    RCString m_name ;

    /** �Ƿ�Ŀ¼
    */
    bool m_isDir ;

    /** �Ƿ��д�Сֵ
    */
    bool m_sizeDefined ;
    
    /** �Ƿ����޸�ʱ��
    */
    bool m_mTimeDefined ;

    /** �Ƿ�ͨ���ƥ��
    */
    bool m_censored;

    /** ���
    */
    uint32_t m_indexInServer;

    /** ʱ������
    */
    int32_t m_timeType ;
};

END_NAMESPACE_RCZIP

#endif //__RCArcItem_h_
