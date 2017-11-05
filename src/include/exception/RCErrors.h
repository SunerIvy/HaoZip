/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCErrors_h_
#define __RCErrors_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** ����źʹ�����Ϣ����
*/
class RCErrors:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCErrors() ;
    
    /** Ĭ����������
    */
    ~RCErrors() ;

public:

#ifndef RCZIP_OS_WIN
    /** ��ȡ��׼�����(errno)
    @return ���ش����
    */
    static int32_t GetStdErrorCode(void) ;
#endif
    
    /** ��ȡϵͳ��صĴ����(��Windows�µ�GetLastError())
    @return ����HResult��ʽ�Ĵ����
    */
    static HResult GetSystemErrorCode(void) ;

#ifndef RCZIP_OS_WIN    
    /** ���ݴ����ȡ�ô�����Ϣ
    @param [in] errorCode �����
    @return �����Ŷ�Ӧ�Ĵ�����Ϣ
    */
    static RCString GetStdErrorMessage(int32_t errorCode) ;
#endif
    
    /** ���ݴ����ȡ�ô�����Ϣ
    @param [in] hr HResult��ʽ�Ĵ����
    @return �����Ŷ�Ӧ�Ĵ�����Ϣ
    */
    static RCString GetSystemErrorMessage(HResult hr) ;
    
    /** HResult��ϵͳ�����֮���ת��
    @param [in] hr HResult��ʽ�Ĵ����
    @return ���ز���ϵͳ��صĴ����
    */
    static int32_t ConvertToSystemError(HResult hr) ;
    
    /** ϵͳ�������HResult֮���ת��
    @param [in] errorCode ����ϵͳ��صĴ����
    @return ����HResult��ʽ�Ĵ����
    */
    static HResult ConvertToHResult(int32_t errorCode) ;
    
    /** bool ����ת����HResult
    @param [in] result ��Ҫת����boolֵ
    @return ����HResult��ʽ�Ĵ����
    */
    static HResult ConvertBoolToHRESULT(bool result) ;
    
    /** ��ȡ��ǰϵͳ����ţ���Windowsƽ̨��ΪGetLastError()���ؽ��
    @return ����HResult��ʽ�Ĵ����
    */
    static HResult GetLastErrorCode(void) ;
    
    /** ��ȡ��ǰ��ϵͳ������Ϣ����Windowsƽ̨��ΪGetLastError()��Ӧ�Ĵ�����Ϣ
    @return �������һ�δ���Ŷ�Ӧ�Ĵ�����Ϣ��������Ǵ����򷵻ؿմ�
    */
    static RCString GetLastErrorMessage(void) ;
};

END_NAMESPACE_RCZIP

#endif //__RCErrors_h_
