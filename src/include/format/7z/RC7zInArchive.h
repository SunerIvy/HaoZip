/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zInArchive_h_
#define __RC7zInArchive_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCVector.h"
#include "format/7z/RC7zDefs.h"
#include "format/7z/RC7zInByte.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "interface/IPassword.h"
#include "format/7z/RC7zInArchiveInfo.h"
#include "format/7z/RC7zItem.h"
#include "format/7z/RC7zArchiveDatabaseEx.h"

BEGIN_NAMESPACE_RCZIP

class RC7zInArchive:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zInArchive() ;

    /** Ĭ����������
    */
    ~RC7zInArchive() ;

public:


    /** ��
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ҷ�Χ
    @return �ɹ�����RC_S_OK�����򷵻ش���ţ�RC_S_FALSE��ʾ����7z��ʽ
    */
    HResult Open(IInStream* stream, const uint64_t* searchHeaderSizeLimit); 

    /** �ر�
    */
    void Close() ;

    /** ����������
    @param [in] codecsInfo ���������
    @param [in] db ��������
    @param [in] getTextPassword ���������
    @param [in] passwordIsDefined �Ƿ�������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadDatabase(ICompressCodecsInfo* codecsInfo,
                         RC7zArchiveDatabaseEx& db,
                         ICryptoGetTextPassword* getTextPassword, 
                         bool& passwordIsDefined) ;

private:

    class RC7zStreamSwitch ;

    /** ��Ԫ��RC7zStreamSwitch
    */
    friend class RC7zStreamSwitch ;

private:

    /** ����ֽ���
    @param [in] buffer ����
    @param [in] size ��С
    */
    void AddByteStream(const byte_t* buffer, size_t size) ;

    /** ɾ���ֽ���
    */
    void DeleteByteStream() ;

    /** ���Ҳ���ȡǩ��
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit �����ҷ�Χ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FindAndReadSignature(IInStream* stream, const uint64_t* searchHeaderSizeLimit) ;

    /** ���ֽ�
    @param [out] data ���ض�ȡ������
    @param [in] size ��ȡ�Ĵ�С
    */
    void ReadBytes(byte_t *data, size_t size) ;

    /** ��һ���ֽ�
    @return ����һ���ֽ�
    */
    byte_t ReadByte() ;

    /** ����
    @return ����64λ�޷�������
    */
    uint64_t ReadNumber() ;

    /** ����
    @return ����RC7zNum
    */
    RC7zNum ReadNum() ;

   /** ��ID
    @return ����RC7zNum
    */
    uint64_t ReadID() ;

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32() ;

    /** ���˸��ֽ�ת��64λ�޷�������
    @return ����64λ�޷�������
    */
    uint64_t ReadUInt64() ;

    /** ����
    @param [in] size �����Ĵ�С
    */
    void SkipData(uint64_t size) ;

    /** ����
    */
    void SkipData() ;

    /** �ȴ�����
    @param [in] attribute ����
    */
    void WaitAttribute(uint64_t attribute) ;

    /** ��ȡ�ĵ�����
    @param [out] archiveInfo �����ĵ�����
    */
    void ReadArchiveProperties(RC7zInArchiveInfo& archiveInfo) ;

    /** ��ȡ��һ���ļ���
    @param [out] itemInfo �����ļ���Ϣ
    */
    void GetNextFolderItem(RC7zFolder& itemInfo) ;

    /** ��ȡhash
    @param [in] numItems ������
    @param [in] digestsDefined ���������Ŀ
    @param [in,out] digests ����hash
    */
    void ReadHashDigests(int32_t numItems,
                         RCBoolVector& digestsDefined, 
                         RCVector<uint32_t>& digests) ;

    /** ��ȡ����Ϣ
    @param [in] dataOffset ����ƫ��
    @param [in] packSizes ����С
    @param [in] packCRCsDefined �Ƿ������crc
    @param [in] packCRCs crc�б�
    */
    void ReadPackInfo(uint64_t& dataOffset,
                      RCVector<uint64_t>& packSizes,
                      RCBoolVector& packCRCsDefined,
                      RCVector<uint32_t>& packCRCs);

    /** ��ȡ��ѹ��Ϣ
    @param [in] dataVector ����
    @param [in] folders �ļ�����Ϣ
    */
    void ReadUnpackInfo(const RCVector<RCByteBuffer>* dataVector,
                        RCVector<RC7zFolder>& folders);

    /** ��ȡ��������Ϣ
    @param [in] folders �ļ���
    @param [in] numUnpackStreamsInFolders ���н�ѹ��������
    @param [in] unpackSizes ��ѹ��С
    @param [in] digestsDefined ժҪ����
    @param [in] digests ժҪ��Ϣ
    */
    void ReadSubStreamsInfo(const RCVector<RC7zFolder>& folders,
                            RCVector<RC7zNum>& numUnpackStreamsInFolders,
                            RCVector<uint64_t>& unpackSizes,
                            RCBoolVector& digestsDefined,
                            RCVector<uint32_t>& digests) ;

    /** ��ȡ������Ϣ
    @param [in] dataVector ����
    @param [in] dataOffset ����ƫ��
    @param [in] packSizes ���Ĵ�С
    @param [in] packCRCsDefined crc��Ϣ�Ƿ���
    @param [in] packCRCs CRC��Ϣ
    @param [in] folders �ļ���
    @param [in] numUnpackStreamsInFolders ���н�ѹ��������
    @param [in] unpackSizes ��ѹ��С
    @param [in] digestsDefined ժҪ����
    @param [in] digests ժҪ��Ϣ
    */
    void ReadStreamsInfo(const RCVector<RCByteBuffer>* dataVector,
                         uint64_t& dataOffset,
                         RCVector<uint64_t>& packSizes,
                         RCBoolVector& packCRCsDefined,
                         RCVector<uint32_t>& packCRCs,
                         RCVector<RC7zFolder>& folders,
                         RCVector<RC7zNum>& numUnpackStreamsInFolders,
                         RCVector<uint64_t>& unpackSizes,
                         RCBoolVector& digestsDefined,
                         RCVector<uint32_t>& digests);

    /** ��ȡRCBoolVector
    @param [in] numItems ��ȡ���ٸ�
    @param [out] v ����RCBoolVector
    */
    void ReadBoolVector(int32_t numItems, RCBoolVector& v) ;

    /** ��ȡRCBoolVector
    @param [in] numItems ��ȡ���ٸ�
    @param [out] v ����RCBoolVector
    */
    void ReadBoolVector2(int32_t numItems, RCBoolVector& v) ;

    /** ��ȡRC7zUInt64DefVector
    @param [in] dataVector ����
    @param [out] v ����RC7zUInt64DefVector
    @param [in] numFiles ��ȡ���ٸ�
    */
    void ReadUInt64DefVector(const RCVector<RCByteBuffer>& dataVector,
                             RC7zUInt64DefVector& v, 
                             int32_t numFiles);

    /** �������������
    @param [in] codecsInfo ���������
    @param [in] baseOffset ����ƫ��
    @param [in] dataOffset ����ƫ��
    @param [in] dataVector ����
    @param [in] getTextPassword ���������
    @param [in] passwordIsDefined �Ƿ�������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadAndDecodePackedStreams(ICompressCodecsInfo* codecsInfo,
                                       uint64_t baseOffset, 
                                       uint64_t& dataOffset,
                                       RCVector<RCByteBuffer>& dataVector, 
                                       ICryptoGetTextPassword* getTextPassword, 
                                       bool& passwordIsDefined);

    /** ������Ϣ
    @param [in] codecsInfo ���������
    @param [in] db ��������
    @param [in] getTextPassword ���������
    @param [in] passwordIsDefined �Ƿ�������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadHeader(ICompressCodecsInfo* codecsInfo,
                       RC7zArchiveDatabaseEx& db,
                       ICryptoGetTextPassword* getTextPassword, 
                       bool& passwordIsDefined);  

    /** ��������Ϣ
    @param [in] codecsInfo ���������
    @param [in] db ��������
    @param [in] getTextPassword ���������
    @param [in] passwordIsDefined �Ƿ�������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadDatabase2(ICompressCodecsInfo* codecsInfo,
                          RC7zArchiveDatabaseEx& db,
                          ICryptoGetTextPassword* getTextPassword, 
                          bool& passwordIsDefined);
                                
private:

    /** ���ǩ��
    @param [in] p ����
    @return �Ƿ���true�����򷵻�false
    */
    static bool TestSignatureCandidate(const byte_t* p) ;

private:

    /** ������
    */
    IInStreamPtr m_stream;

    /** ����
    */
    RCVector<RC7zInBytePtr> m_inByteVector;

    /** ����
    */
    RC7zInBytePtr m_inByteBack ; 

    /** �ĵ���ʼ����λ��
    */
    uint64_t m_arhiveBeginStreamPosition;

    /** ͷ��Ϣ
    */
    byte_t m_header[RC7zDefs::s_headerSize];

    /** ͷ��С
    */
    uint64_t m_headersSize;
};

END_NAMESPACE_RCZIP

#endif //__RC7zInArchive_h_
