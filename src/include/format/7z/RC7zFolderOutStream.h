/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zFolderOutStream_h_
#define __RC7zFolderOutStream_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCVector.h"
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RC7zArchiveDatabaseEx ;
class RCOutStreamWithCRC ;

class RC7zFolderOutStream:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zFolderOutStream() ;
    
    /** Ĭ����������
    */
    ~RC7zFolderOutStream() ;

public:

    /** ��ʼ��
    @param [in] archiveDatabase �ĵ���������
    @param [in] ref2Offset ƫ��
    @param [in] startIndex ��ʼ����
    @param [in] extractStatuses ��ѹ״̬
    @param [in] extractCallback ��ѹ�������ص��ӿ�
    @param [in] testMode �Ƿ��ǲ���ģʽ
    @param [in] checkCrc �Ƿ���Ҫ���CRC
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Init(const RC7zArchiveDatabaseEx* archiveDatabase,
                 uint32_t ref2Offset,
                 uint32_t startIndex,
                 const RCBoolVector* extractStatuses,
                 IArchiveExtractCallback* extractCallback,
                 bool testMode,
                 bool checkCrc) ;

    /** flush�𻵵�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FlushCorrupted(int32_t resultEOperationResult) ;

    /** �Ƿ�ȴ����
    @return �Ƿ���RC_S_OK�����򷵻�RC_E_FAIL
    */
    HResult WasWritingFinished() const ;

    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �Ƿ���RC_S_OK�����򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;

private:

    /** ���ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenFile() ;

    /** �ر��ļ������ý��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CloseFileAndSetResult(uint32_t index, int32_t res) ;

    /** �ر��ļ������ý��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CloseFileAndSetResult() ;

    /** ������ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ProcessEmptyFiles() ;
    
private:

    /** ��CRC�������
    */
    RCOutStreamWithCRC* m_crcStreamSpec ;

    /** CRC�����
    */
    ISequentialOutStreamPtr m_crcStream ;

    /** ��������
    */
    const RC7zArchiveDatabaseEx* m_db ;

    /** ��ѹ״̬
    */
    const RCBoolVector* m_extractStatuses ;

    /** ��ʼ����
    */
    uint32_t m_startIndex ;

    /** ƫ��
    */
    uint32_t m_ref2Offset ;

    /** ��ǰ����
    */
    int32_t m_currentIndex ;

    /** ��ѹ�������ص��ӿ�
    */
    IArchiveExtractCallbackPtr m_extractCallback ;

    /** �Ƿ��ǲ���ģʽ
    */
    bool m_testMode;

    /** �ļ��Ƿ��
    */
    bool m_fileIsOpen ;

    /** �Ƿ���CRC
    */
    bool m_checkCrc ;

    /** ��С
    */
    uint64_t m_rem ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zFolderOutStream_h_
