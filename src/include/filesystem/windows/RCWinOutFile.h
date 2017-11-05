/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinOutFile_h_
#define __RCWinOutFile_h_ 1

#include "filesystem/windows/RCWinFileBase.h"

BEGIN_NAMESPACE_RCZIP

class IOutStreamEvent ;

class RCWinOutFile:
    public RCWinFileBase
{
public:

    /** ���캯��
    @param [in] outStreamEvent IOд���¼�����ص��ӿ�
    */
    RCWinOutFile(IOutStreamEvent* outStreamEvent = NULL) ;
    
    /** Ĭ����������
    */
    ~RCWinOutFile() ;
    
public:
    
    /** ���ļ�
    @param [in] fileName �ļ���
    @param [in] creationDisposition ��������
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Open(const RCString& fileName, DWORD creationDisposition) ;
    
    /** �����ļ�
    @param [in] fileName �ļ���
    @param [in] createAlways �Ƿ�ʼ�մ����ļ�
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Create(const RCString& fileName, bool createAlways);
    
    /** �����ļ�ʱ��
    @param [in] cTime �ļ�����ʱ��
    @param [in] aTime �ļ�������ʱ��
    @param [in] mTime �ļ��޸�ʱ��
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetTime(const FILETIME* cTime, const FILETIME* aTime, const FILETIME* mTime);
    
    /** �����ļ��޸�ʱ��
    @param [in] mTime �ļ��޸�ʱ��
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetMTime(const FILETIME* mTime);
    
    /** д������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @param [out] processedSize ʵ��д������ݳ���
    @param [out] result ʧ��ʱ���ش�����
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Write(const void* data, uint32_t size, uint32_t& processedSize, HResult* result = NULL) ;
    
    /** ���ļ�ָ�붨λ���ļ�β
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetEndOfFile();
    
    /** �����ļ�����
    @param [in] length �ļ�����
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetLength(uint64_t length) ;
   
private:

    /** д������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @param [out] processedSize ʵ��д������ݳ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult WritePart(const void* data, uint32_t size, uint32_t& processedSize) ;    
    
    /** ���ļ�
    @param [in] fileName �ļ���
    @param [in] shareMode ��������
    @param [in] creationDisposition ��������
    @param [in] flagsAndAttributes ���λ
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Open(const RCString& fileName, 
              DWORD shareMode,
              DWORD creationDisposition,
              DWORD flagsAndAttributes) ;
    
private:
    
    /** IOд���¼�����ص��ӿ�
    */
    IOutStreamEvent* m_outStreamEvent ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinOutFile_h_
