/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInOutTempBuffer_h_
#define __RCInOutTempBuffer_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "filesystem/RCOutFile.h"
#include "filesystem/RCTempFile.h"

BEGIN_NAMESPACE_RCZIP

class ISequentialOutStream ;

class RCInOutTempBuffer:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCInOutTempBuffer() ;
    
    /** Ĭ����������
    */
    ~RCInOutTempBuffer() ;

public:
    
    /** ����������
    */
    void Create() ;
    
    /** д������ʼ��
    */
    void InitWriting() ;
    
    /** д������
    @param [in] data ���ݵ�ַ
    @param [in] size ���ݳ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool Write(const void* data, uint32_t size) ;
    
    /** ��ȡ���ݳ���
    @return �������ݳ���
    */
    uint64_t GetDataSize() const ;
    
    /** ���������е�����д�������
    @param [in] stream ������ӿ�
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult WriteToStream(ISequentialOutStream* stream) ;
    
private:
    
    /** �ͷŻ�����
    */
    void Free(void) ;
    
    /** ����д���ļ�
    @param [in] data ���ݵ�ַ
    @param [in] size ���ݳ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool WriteToFile(const void* data, uint32_t size) ;
    
private:
    
    /** ��������ַ
    */
    byte_t* m_buf ;
    
    /** ��ǰ����ָ��ƫ��
    */
    uint32_t m_bufPos ;
    
    /** ��ʱ�ļ���
    */
    RCString m_tempFileName ;
    
    /** ��ʱ�ļ��Ƿ��ѱ�����
    */
    bool m_tempFileCreated ;
    
    /** ���ݳ���
    */
    uint64_t m_size ;
    
    /** ����CRCУ��ֵ
    */
    uint32_t m_crc ;
    
    /** ��ʱ�ļ�������
    */
    RCTempFile m_tempFile ;
    
    /** ����ļ�������
    */
    RCOutFile m_outFile ;
};

END_NAMESPACE_RCZIP

#endif //__RCInOutTempBuffer_h_
