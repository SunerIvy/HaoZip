/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTarUpdate_h_
#define __RCTarUpdate_h_ 1

#include "base/RCString.h"
#include "interface/IStream.h"
#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "RCTarItem.h"

BEGIN_NAMESPACE_RCZIP

/** Tar ����
*/
class RCTarUpdate
{
public:

    /** Tar ������
    */
    struct RCTarUpdateItem
    {
        /** ���ڱ��
        */
        int32_t m_indexInArchive;

        /** �ͻ��˱��
        */
        int32_t m_indexInClient;

        /** ʱ��
        */
        uint32_t m_time;

        /** ģʽ
        */
        uint32_t m_mode;

        /** ��С
        */
        uint64_t m_size;

        /** ����
        */
        RCStringA m_name;

        /** �û�
        */
        RCStringA m_user;

        /** �û���
        */
        RCStringA m_group;

        /** �Ƿ�������
        */
        bool m_newData;

        /** �Ƿ�������
        */
        bool m_newProps;

        /** �Ƿ�λĿ¼
        */
        bool m_isDir;
    };

public:

    /** ���µ��ĵ�
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inputItems ������
    @param [in] updateItems ������
    @param [in] updateCallback ���»ص��ӿ�
    @param [in] compressCodecsInfo ���������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult UpdateArchive(IInStream *inStream,
                                 ISequentialOutStream *outStream,
                                 const std::vector<RCTarItemEx> &inputItems,
                                 const std::vector<RCTarUpdateItem> &updateItems,
                                 IArchiveUpdateCallback *updateCallback,
                                 ICompressCodecsInfoPtr compressCodecsInfo);
};

END_NAMESPACE_RCZIP

#endif //__RCTarUpdate_h_
