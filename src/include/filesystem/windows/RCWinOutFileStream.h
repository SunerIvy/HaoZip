/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinOutFileStream_h_
#define __RCWinOutFileStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "filesystem/windows/RCWinOutFile.h"

BEGIN_NAMESPACE_RCZIP

class IOutStreamEvent ;

class RCWinOutFileStream:
    public IUnknownImpl2<IOutStream,
                         IStreamGetFileName>
{
public:

    /** ���캯��
    @param [in] outStreamEvent IOд���¼�����ص��ӿ�
    */
    RCWinOutFileStream(IOutStreamEvent* outStreamEvent = NULL) ;
    
    /** Ĭ����������
    */
    ~RCWinOutFileStream() ;

public:
    
    /** �����ļ�
    @param [in] fileName �ļ���
    @param [in] createAlways �Ƿ�ʼ�մ����ļ�
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Create(const RCString& fileName, bool createAlways) ;
    
    /** ���ļ�
    @param [in] fileName �ļ���
    @param [in] creationDisposition ��������
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Open(const RCString& fileName, DWORD creationDisposition) ;
    
    /** �ر��ļ�
    @return �رճɹ�����RC_S_OK, ���򷵻ش�����
    */
    HResult Close() ;
    
    /** �����ļ�ʱ��
    @param [in] cTime �ļ�����ʱ��
    @param [in] aTime �ļ�������ʱ��
    @param [in] mTime �ļ��޸�ʱ��
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetTime(const FILETIME* cTime, const FILETIME* aTime, const FILETIME* mTime) ;
    
    /** �����ļ��޸�ʱ��
    @param [in] mTime �ļ��޸�ʱ��
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool SetMTime(const FILETIME* mTime) ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
    /** ������С
    @param [in] newSize �µĴ�С 
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetSize(uint64_t newSize) ;

    /** �Ѵ���ĵĴ�С
    @return �����Ѵ����С
    */
    virtual uint64_t GetProcessedSize(void) const ;
    
    /** ��ȡ����Ӧ���ļ�����������·��
    @param [out] fileName ���ص�ǰ���ļ�����������·��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetFileName(RCString& fileName) ;
    
private:
    
    /** д������ʵ��
    */
    RCWinOutFile m_file ;
    
    /** �Ѿ�д����ֽ���
    */
    uint64_t m_processedSize;
};

END_NAMESPACE_RCZIP

#endif //__RCWinOutFileStream_h_
