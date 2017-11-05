/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinInFile_h_
#define __RCWinInFile_h_ 1

#include "filesystem/windows/RCWinFileBase.h"

BEGIN_NAMESPACE_RCZIP

class RCWinInFile:
    public RCWinFileBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWinInFile() ;
    
    /** Ĭ����������
    */
    ~RCWinInFile() ;
    
public:
    
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
              DWORD flagsAndAttributes);
              
    /** ����ʽ���ļ�
    @param [in] fileName �ļ���
    @param [in] shareForWrite �Ƿ����ù���д����
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool OpenShared(const RCString& fileName, bool shareForWrite);
    
    /** ���ļ�
    @param [in] fileName �ļ���
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Open(const RCString& fileName);
    
    /** ��ȡ�ļ�����
    @param [out] data ���ݻ�����
    @param [in] size ������ȡ�����ݴ�С
    @param [in] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Read(void* data, uint32_t size, uint32_t& processedSize);
    
private:
    
    /** �ֶζ�ȡ�ļ�����
    @param [out] data ���ݻ�����
    @param [in] size ������ȡ�����ݴ�С
    @param [in] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool ReadPart(void* data, uint32_t size, uint32_t& processedSize);
};

END_NAMESPACE_RCZIP

#endif //__RCWinInFile_h_
