/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLanguage_h_
#define __RCLanguage_h_ 1

#include "base/RCString.h"
#include "base/RCSingleton.h"
#include "language/RCLanguageRes.h"
#include "common/RCSharedLibrary.h"
#include <stdarg.h>

BEGIN_NAMESPACE_RCZIP

class RCLanguage
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCLanguage() ;
    
    /** Ĭ����������
    */
    ~RCLanguage() ;

public:

    /** ��ʼ����Դ��̬���ӿ�
    @param [in] resFileName ��Դ�ļ���
    @return ���سɹ��򷵻�true, ���򷵻�false
    */
    bool SetResFileName(const RCString& resFileName) ;
    
    /** ��ȡ��Դ�ļ���
    @return ������Դ�ļ�����������·��
    */
    RCString GetResFileName(void) const ;
    
    /** �����ַ���, �ַ��������Ϊ 511 �ֽ�
    @param [in] resourceID ��ԴID
    @return ���ؼ��ص��ַ�����ʧ���򷵻ؿմ�
    */
    RCString LoadStr(uint32_t resourceID) ;
    
    /** ���ظ�ʽ���ַ����������ɱ䣬�����ַ��������Ϊ 1023 �ֽ�
    @param [in] resourceID ��ԴID
    @return ���ؼ��ص��ַ�����ʧ���򷵻ؿմ�
     */
    RCString LoadFormatStr(uint32_t resourceID, ...) ;
    
    /** ���ظ�ʽ���ַ����������ɱ䣬�����ַ��������Ϊ 1023 �ֽ�
    @param [in] resourceID ��ԴID
    @param [in] args �ɱ�����б�
    @return ���ؼ��ص��ַ�����ʧ���򷵻ؿմ�
     */
    RCString LoadFormatStr(uint32_t resourceID, va_list args) ;

    /** ��ȡ��Դģ��ľ��
    @return ������Դģ��ľ��,ʧ���򷵻ؿ�
    */
    RCSharedLibrary::shared_lib_module GetResHandle(void) const;
        
    /** ж��������ģ��
    */
    bool UnLoadLanguage(void) ;

private:
    
    /** ʵ����
    */
    class TImpl ;
    
    /** ʵ�ֶ���
    */
    TImpl* m_impl ;
};

/** ���Թ�����ĵ���
*/
typedef RCSingleton<RCLanguage> RCLang ;

/** �����ַ���
@param [in] resourceID ��ԴID
@return ���ؼ��ص��ַ���ֵ
*/
inline RCString LoadStr(uint32_t resourceID)
{
    return RCLang::Instance().LoadStr(resourceID) ;
}

/** ���ظ�ʽ���ַ����������ɱ�
@param [in] resourceID ��ԴID
@param [in] ... �ɱ�����б�
@return ���ؼ��ص��ַ���ֵ
*/
inline RCString LoadFormatStr(uint32_t resourceID, ...)
{
    va_list args;
    va_start(args, resourceID) ;
    RCString result = RCLang::Instance().LoadFormatStr(resourceID, args) ;
    va_end(args) ; 
    return result ;
}

/** ��ȡ��Դģ��ľ��
@return ������Դ�ļ���Ӧ��ϵͳƽ̨���
*/
inline RCSharedLibrary::shared_lib_module GetResHandle(void)
{
    return RCLang::Instance().GetResHandle();
}


/** ������Դ�ļ����ĵ���������
*/
#define RC_SET_RESOURCE_FUNCTION "SetResFileName"

/** ������Դ�ļ����ĵ�������ԭ��
@param [in] szFileName ��Դ�ļ�����������·�����ַ�����'\0'��β
*/
extern "C"{
    typedef RCZIP_API void (*PFNSetResurceFileNameFunc)(const RCString::value_type* szFileName) ;
}

END_NAMESPACE_RCZIP

#endif //__RCLanguage_h_
