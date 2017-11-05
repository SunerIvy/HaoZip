/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinInFileStream_h_
#define __RCWinInFileStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "filesystem/windows/RCWinInFile.h"

BEGIN_NAMESPACE_RCZIP

class RCWinInFileStream:
    public IUnknownImpl4<IInStream,
                         IStreamGetSize,
                         ICloneStream,
                         IStreamGetFileName>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWinInFileStream() ;
    
    /** Ĭ����������
    */
    ~RCWinInFileStream() ;
    
public:
    
    /** ���ļ�
    @param [in] fileName �ļ���
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Open(const RCString& fileName);
    
    /** ����ʽ���ļ�
    @param [in] fileName �ļ���
    @param [in] shareForWrite �Ƿ����ù���д����
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool OpenShared(const RCString& fileName, bool shareForWrite);
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;

    /** ��ȡ����
    @param [out] size �������ĳ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult GetSize(uint64_t* size) ;

    /**  Clone ������ 
    @return Clone �������������ʧ�ܷ���NULL
    */
    virtual IUnknown* Clone(void) ;
    
    /** ��ȡ����Ӧ���ļ�����������·��
    @param [in] fileName �ļ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult GetFileName(RCString& fileName) ;
    
private:
    
    /** �ļ����ݶ�ȡʵ�ֶ���
    */
    RCWinInFile m_file ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinInFileStream_h_
