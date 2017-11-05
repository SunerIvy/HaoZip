/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IOutStreamEvent_h_
#define __IOutStreamEvent_h_ 1

#include "base/RCString.h"

#ifdef RCZIP_OS_WIN
    #include "base/RCWindowsDefs.h"
#endif

BEGIN_NAMESPACE_RCZIP

/** �������IO�¼�
*/
class IOutStreamEvent
{
public:
    
    /** �������ļ�
    @param [in] fileName �´������ļ�����·��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult OnCreateFile(RCString fileName) = 0 ;
    
    /** �������ļ���
    @param [in] folderName �´������ļ�������·��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult OnCreateFolder(RCString folderName) = 0 ;
    
    /** ֪ͨWindows��Դ�����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult NotifyChange(void) = 0 ;
    
    /** IOд�����
    @param [in] fileName ��ǰ����д���ļ�������·��
    @param [in] fileSize ��ǰ����д����ļ���С
    @param [in] errorCode ��������Ĵ�����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult OnWriteFileError(RCString fileName, uint64_t fileSize, uint64_t errorCode) = 0 ;

#ifdef RCZIP_OS_WIN    
    
    /** ��ȡ���ھ������Windows��Ч
    @return ���ش��ھ��
    */
    virtual HWND GetHwnd() const = 0 ;
    
#endif 

protected:
       
    /** Ĭ����������
    */
    virtual ~IOutStreamEvent() {} ;
};

END_NAMESPACE_RCZIP

#endif //__IOutStreamEvent_h_
