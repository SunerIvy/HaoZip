/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCChmFolderOutStream_h_
#define __RCChmFolderOutStream_h_ 1

#include "common/RCVector.h"
#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "RCChmItem.h"

BEGIN_NAMESPACE_RCZIP

class RCChmFolderOutStream:
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

    /** д����
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @param [in] isOK �Ƿ�ok
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Write2(const void* data, uint32_t size, uint32_t* processedSize, bool isOK);

    /** ��ʼ��
    @param [in] database chm��������
    @param [in] extractCallback ��ѹ�ص��ӿ�ָ��
    @param [in] testMode �Ƿ��ǲ���ģʽ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    void Init(const RCChmFilesDatabase* database, IArchiveExtractCallback* extractCallback, bool testMode);

    /** flush������
    @param [in] maxSize ����С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FlushCorrupted(uint64_t maxSize);

private:
    
    /** ���ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenFile();

    /** д���ļ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteEmptyFiles();

public:

    /** �ļ��д�С
    */
    uint64_t m_folderSize;

    /** �ļ�����λ��
    */
    uint64_t m_posInFolder;

    /** ����λ��
    */
    uint64_t m_posInSection;

    /** ��ѹ״̬
    */
    const RCVector<bool>* m_extractStatuses;

    /** ��ʼ����
    */
    int32_t m_startIndex;

    /** ��ǰ����
    */
    int32_t m_currentIndex;

    /** �ļ���
    */
    int32_t m_numFiles;

private:

    /** �������� 
    */
    const RCChmFilesDatabase* m_database;

    /** ��ѹ�ص��ӿ�ָ��
    */
    IArchiveExtractCallbackPtr m_extractCallback;

    /** �Ƿ��ǲ���ģʽ
    */
    bool m_testMode;

    /** �Ƿ�ok
    */
    bool m_isOk;

    /** �ļ��Ƿ��
    */
    bool m_fileIsOpen;

    /** ʣ���ļ���С
    */
    uint64_t m_remainFileSize;

    /** �����
    */
    ISequentialOutStreamPtr m_realOutStream;
};

END_NAMESPACE_RCZIP

#endif //__RCChmFolderOutStream_h_
