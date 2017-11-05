/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArjInArchive_h_
#define __RCArjInArchive_h_ 1

#include "base/RCTypes.h"
#include "interface/IStream.h"
#include "interface/IArchive.h"
#include "RCArjHeader.h"
#include "RCArjItem.h"

BEGIN_NAMESPACE_RCZIP

class RCArjInArchive
{
public:
    /** ���ĵ�
    @param [in] searchHeaderSizeLimit ����ͷ�������ƫ��λ��
    */
    HResult Open(const uint64_t *searchHeaderSizeLimit);

    /** ��ȡ��һ�� 
    @param [out] filled �Ƿ����
    @param [out] item arj��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult GetNextItem(bool& filled, RCArjItem &item);

public:

    /** �ĵ�ͷ��
    */
    RCArjArchiveHeader m_header;

    /** ������
    */
    IInStream* m_stream;

    /** ���ĵ��ص��ӿ�ָ��
    */
    IArchiveOpenCallback* m_openArchiveCallback;

    /** �ļ���
    */
    uint64_t m_numFiles;

    /** �ֽ���
    */
    uint64_t m_numBytes;

private:

    /** ��ȡ��
    @param [out] filled �Ƿ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadBlock(bool& filled);

    /** ��ȡǩ���Ϳ�
    @param [out] filled �Ƿ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadSignatureAndBlock(bool& filled);

    /** ������չͷ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SkipExtendedHeaders();

    /** ��ȫ���ֽ�
    @param [out] data ����ʵ�ʶ���������
    @param [in] size ��ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SafeReadBytes(void *data, uint32_t size);

private:

    /** ���С
    */
    uint32_t m_blockSize;

    /** ������
    */
    byte_t m_block[RCArjDefs::kBlockSizeMax + 4];
};

END_NAMESPACE_RCZIP

#endif //__RCArjInArchive_h_