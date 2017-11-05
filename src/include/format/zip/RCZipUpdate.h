/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipUpdate_h_
#define __RCZipUpdate_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "filesystem/RCFileDefs.h"
#include "interface/ICoder.h"
#include "interface/IArchive.h"
#include "RCZipItem.h"
#include "RCZipIn.h"
#include "RCZipCompressionMethodMode.h"

BEGIN_NAMESPACE_RCZIP

class RCZipUpdate
{
public:

    struct RCZipUpdateRange
    {
        /** λ��
        */
        uint64_t m_position;

        /** ��С
        */
        uint64_t m_size;

        /** Ĭ�Ϲ��캯��
        */
        RCZipUpdateRange():
            m_position(0),
            m_size(0)
        {
        };

        /** ���캯��
        */
        RCZipUpdateRange(uint64_t position, uint64_t size): 
            m_position(position), 
            m_size(size)
        {
        };
    };

    struct RCZipUpdateItem
    {
        /** �Ƿ���������
        */
        bool m_newData;

        /** �Ƿ���������
        */
        bool m_newProperties;

        /** �Ƿ���Ŀ¼
        */
        bool m_isDir;

        /** �Ƿ���ntfsʱ��
        */
        bool m_ntfsTimeIsDefined;

        /** �Ƿ�UTF8
        */
        bool m_isUtf8;

        /** ��archive�е�����
        */
        int32_t m_indexInArchive;

        /** ��client�е�����
        */
        int32_t m_indexInClient;

        /** ����
        */
        uint32_t m_attributes;

        /** ʱ��
        */
        uint32_t m_time;

        /** ��С
        */
        uint64_t m_size;

        /** ����
        */
        RCStringA m_name;

        /** ntfs�޸�ʱ��
        */
        RC_FILE_TIME m_ntfsMTime;

        /** ntfs����ʱ��
        */
        RC_FILE_TIME m_ntfsATime;

        /** ntfs����ʱ��
        */
        RC_FILE_TIME m_ntfsCTime;

        /** Ĭ�Ϲ��캯��
        */
        RCZipUpdateItem(): 
            m_newData(false),
            m_newProperties(false),
            m_isDir(false),
            m_ntfsTimeIsDefined(false), 
            m_isUtf8(false), 
            m_indexInArchive(0),
            m_indexInClient(0),
            m_attributes(0),
            m_time(0),
            m_size(0)
        {
        }
    };

    /** RCZipUpdateItem����ָ��
    */
    typedef RCSharedPtr<RCZipUpdateItem>  RCZipUpdateItemPtr ;

public:

    /** ѹ������
    @param [in] codecsInfo ���������
    @param [in] inputItems ����items��Ϣ
    @param [in] updateItems ����items��Ϣ
    @param [in] seqOutStream �����
    @param [in] inArchive �����ĵ�
    @param [in] compressionMethodMode ѹ��ģʽ
    @param [in] updateCallback ���¹������ص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult UpdateArchive(ICompressCodecsInfo* codecsInfo,
                                 const RCVector<RCZipItemExPtr>& inputItems,
                                 const RCVector<RCZipUpdateItemPtr>& updateItems,
                                 ISequentialOutStream* seqOutStream,
                                 RCZipIn* inArchive,
                                 RCZipCompressionMethodMode* compressionMethodMode,
                                 IArchiveUpdateCallback* updateCallback);
};

END_NAMESPACE_RCZIP

#endif //__RCZipUpdate_h_
