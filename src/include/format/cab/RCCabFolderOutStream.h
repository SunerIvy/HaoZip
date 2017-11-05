/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabFolderOutStream_h_
#define __RCCabFolderOutStream_h_ 1

#include "interface/IStream.h"
#include "interface/IArchive.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBuffer.h"
#include "format/cab/RCCabIn.h"

BEGIN_NAMESPACE_RCZIP

class RCCabFolderOutStream :
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize);

public:

    /** д���ļ�
    */
    HResult WriteEmptyFiles();

    /** ��ʼ��  
    @param [in] database cab��������
    @param [in] extractStatuses ��������С
    @param [in] startIndex ��ʼ����
    @param [in] folderSize �ļ��д�С
    @param [in] extractCallback ��ѹ�ص��ӿ�ָ��
    @param [in] testMode �Ƿ��ǲ���ģʽ
    */
    void Init(const RCCabMvDatabaseEx* database, 
              const RCVector<bool>* extractStatuses, 
              int32_t startIndex,
              uint64_t folderSize,
              IArchiveExtractCallback *extractCallback,
              bool testMode);

    /** flush������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FlushCorrupted();

    /** �Ƿ�֧��
    @return �Ƿ���RC_S_OK�����򷵻ش����
    */
    HResult Unsupported();

    /** ��ȡʣ���С
    @return ����ʣ���С
    */
    uint64_t GetRemain() const ;

    /** ��ȡ�ļ����е�ƫ��λ��
    @return ƫ��λ��
    */
    uint64_t GetPosInFolder() const ;

private:

    /** ���ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenFile();

    /** �ر��ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CloseFile() ;

    /** д�ļ�
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [in] processedSize ʵ��д��Ĵ�С
    @param [in] isOK �Ƿ�ok
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Write2(const void* data, uint32_t size, uint32_t* processedSize, bool isOK);

private:

    /** cab��������
    */
    const RCCabMvDatabaseEx* m_database;

    /** ��ѹ״̬
    */
    const RCVector<bool>* m_extractStatuses;

    /** ��ʼ����
    */
    int32_t m_startIndex;

    /** ��ǰ����
    */
    int32_t m_currentIndex;

    /** ��ѹ�ص��ӿ�ָ��
    */
    IArchiveExtractCallbackPtr m_extractCallback;

    /** �Ƿ��ǲ���ģʽ
    */
    bool m_testMode;

    /** ��ʵ�����
    */
    ISequentialOutStreamPtr m_realOutStream;

    /** �Ƿ�ok
    */
    bool m_isOk;

    /** �ļ��Ƿ񱻴�
    */
    bool m_fileIsOpen;

    /** ʣ���ļ���С
    */
    uint32_t m_remainFileSize;

    /** �ļ��д�С
    */
    uint64_t m_folderSize;

    /** �ļ��е�ƫ��λ��
    */
    uint64_t m_posInFolder;

    /** ���ݻ�����
    */
    RCByteBuffer m_tempBuf;

    /** �Ƿ�����ʱ������ģʽ
    */
    bool m_tempBufMode;

    /** �Ƿ�֧��
    */
    bool m_isSupported;

    /** �ļ���������ʼƫ��
    */
    uint32_t m_bufStartFolderOffset;
};

END_NAMESPACE_RCZIP

#endif //__RCCabFolderOutStream_h_