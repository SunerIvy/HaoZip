/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zFolderInStream_h_
#define __RC7zFolderInStream_h_ 1

#include "interface/IArchive.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCSequentialInStreamWithCRC ;

class RC7zFolderInStream:
    public IUnknownImpl2<ISequentialInStream,
                         ICompressGetSubStreamSize
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zFolderInStream() ;
    
    /** Ĭ����������
    */
    ~RC7zFolderInStream() ;
    
public:

    /** ��ʼ��
    @param [in] updateCallback
    @param [in] fileIndices �ļ���������
    @param [in] numFiles �ļ�����
    */
    void Init(IArchiveUpdateCallback* updateCallback,
              const uint32_t* fileIndices, 
              uint32_t numFiles);

    /** ��ȡ���д�С
    @return ���ش�С
    */
    uint64_t GetFullSize() const ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ��ȡ����С
    @param [in] subStream �����±�
    @param [out] size ���Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetSubStreamSize(uint64_t subStream, uint64_t& size) ;

public:

    /** �Ѵ���
    */
    RCBoolVector m_processed ;

    /** crc
    */
    RCVector<uint32_t> m_crcs ;

    /** ��С
    */
    RCVector<uint64_t> m_sizes ;
    
private:

    /** ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenStream() ;

    /** �ر���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CloseStream();

    /** ����crc
    */
    void AddDigest();
    
private:

    /** crc��������
    */
    RCSequentialInStreamWithCRC* m_inStreamWithHashSpec ;

    /** hash��������
    */
    ISequentialInStreamPtr m_inStreamWithHash;

    /** ���¹������ص��ӿ�
    */
    IArchiveUpdateCallbackPtr m_updateCallback;

    /** �Ƿ��е�ǰ��С
    */
    bool m_currentSizeIsDefined ;

    /** ��ǰ��С
    */
    uint64_t m_currentSize ;

    /** �ļ��Ƿ񱻴�
    */
    bool m_fileIsOpen;

    /** �ļ�ָ��λ��
    */
    uint64_t m_filePos;

    /** �ļ���������
    */
    const uint32_t* m_fileIndices;

    /** �ļ���
    */
    uint32_t m_numFiles;

    /** �ļ�����
    */
    uint32_t m_fileIndex;
};

END_NAMESPACE_RCZIP

#endif //__RC7zFolderInStream_h_
