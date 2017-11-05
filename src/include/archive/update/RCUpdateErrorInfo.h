/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef  __RCUpdateErrorInfo_h_
#define __RCUpdateErrorInfo_h_ 1

#include "base/RCTypes.h"
#include "base/RCWindowsDefs.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** ������Ϣ
*/
class RCErrorInfo
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCErrorInfo() ;

public:
    
    /** ����ϵͳ�����
    @param [in] systemError ϵͳ�����
    */
    void SetSystemError(HResult systemError);
    
    /** ȡ��ϵͳ�����
    @return ����ϵͳ�����
    */
    const HResult GetSystemError(void) const;

    /** ���ô����ļ���
    @param [in] fileName �ļ���
    */
    void SetFileName(const RCString& fileName);
    
    /** ȡ�ô����ļ���
    @return ���ش����ļ���
    */
    const RCString& GetFileName(void) const;

    /** ���ô����ļ���
    @param [in] fileName2 �ļ���
    */
    void SetFileName2(const RCString& fileName2);
    
    /** ȡ�ô����ļ���
    @return ���ش����ļ���
    */
    const RCString& GetFileName2(void) const;

    /** ���ô�����Ϣ
    @param [in] message ������Ϣ
    */
    void SetMessage(const RCString& message);
    
    /** ���ش�����Ϣ
    @return ���ش�����Ϣ
    */
    const RCString& GetMessage(void) const;

    /** ��������Ϣת�����ַ���
    @return ���ش�����Ϣ��
    */
    RCString ToString(void) const ;

private:
    
    /** ϵͳ�����
    */
    HResult m_systemError;

    /** �ļ���
    */
    RCString m_fileName;

    /** �ļ���2
    */
    RCString m_fileName2;

    /** ������Ϣ
    */
    RCString m_message;
    
};

/** ѹ�������´�����Ϣ�ṹ
*/
struct RCUpdateErrorInfo : 
    public RCErrorInfo
{
};

END_NAMESPACE_RCZIP

#endif //__RCUpdateErrorInfo_h_
