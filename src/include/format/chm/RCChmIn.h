/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCChmIn_h_
#define __RCChmIn_h_ 1

#include "common/RCInBuffer.h"
#include "RCChmItem.h"

BEGIN_NAMESPACE_RCZIP

class RCChmProgressVirt
{
public:

    /** ��������
    @param [in] numFiles �ļ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetTotal(uint64_t numFiles) = 0 ;

    /** ���������
    @param [in] numFiles �ļ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetCompleted(uint64_t numFiles) = 0 ;
};

class RCChmIn
{
public:

    /** ��chm�ļ�
    @param [in] inStream ������
    @param [out] database ���chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenChm(IInStream* inStream, RCChmDatabase& database);

    /** �򿪰����ļ�
    @param [in] inStream ������
    @param [out] database ���chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenHelp2(IInStream* inStream, RCChmDatabase& database);

    /** �򿪸߼�
    @param [in] inStream ������
    @param [out] database ���chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenHighLevel(IInStream* inStream, RCChmFilesDatabase& database);

    /** ��
    @param [in] inStream ������
    @param [in] searchHeaderSizeLimit ����ͷ�������ƫ��λ��
    @param [out] database ���chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open2(IInStream* inStream, const uint64_t* searchHeaderSizeLimit, RCChmFilesDatabase& database);

    /** ��
    @param [in] inStream ������
    @param [in] searchHeaderSizeLimit ����ͷ�������ƫ��λ��
    @param [out] database ���chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream, const uint64_t* searchHeaderSizeLimit, RCChmFilesDatabase& database);

private:

    /** ��һ���ֽ�
    @return ����һ���ֽ�
    */
    byte_t ReadByte();

    /** ���ֽ�
    @param [out] data ���ض�ȡ������
    @param [in] size ��ȡ�Ĵ�С
    */
    void ReadBytes(byte_t* data, uint32_t size);

    /** ����
    @param [in] size �����Ĵ�С
    */
    void Skip(size_t size);

    /** �������ֽ�ת��16λ�޷�������
    @return ����16λ�޷�������
    */
    uint16_t ReadUInt16();

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32();

    /** ���˸��ֽ�ת��64λ�޷�������
    @return ����64λ�޷�������
    */
    uint64_t ReadUInt64();

    /** �����ܵİ˸��ֽ�
    return ����64λ�޷�������
    */
    uint64_t ReadEncInt();

    /** ���ַ���
    @param [in] size ���Ĵ�С
    @param [out] s �����ַ���
    */
    void ReadString(int size, RCStringA &s);

    /** ��unicode�ַ���
    @param [in] size ���Ĵ�С
    @param [out] s ����unicode�ַ���
    */
    void ReadUString(int size, RCString &s);

    /** ��GUID
    @param [out] g ����GUDI
    */
    void ReadGUID(RC_GUID& g);

    /** ������Ϣ
    @param [in] inStream ������
    @param [in] pos λ��
    @param [in] size ��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadChunk(IInStream* inStream, uint64_t pos, uint64_t size);

    /** ��Ŀ¼���
    @param [in] database ����chm��������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadDirEntry(RCChmDatabase& database);

    /** ��ѹ��
    @param [in] inStream ������
    @param [in] database ��������
    @param [in] name ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult DecompressStream(IInStream* inStream, const RCChmDatabase& database, const RCStringA& name);

private:

    /** ��ʼλ��
    */
    uint64_t m_startPosition;

    /** ���뻺����
    */
    RCInBuffer m_inBuffer;

    /** ���С
    */
    uint64_t m_chunkSize;
};

END_NAMESPACE_RCZIP

#endif //__RCChmIn_h_
