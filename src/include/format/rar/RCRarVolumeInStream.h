/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarVolumeInStream_h_
#define __RCRarVolumeInStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"
#include "base/RCSmartPtr.h"
#include "RCRarIn.h"
#include "RCRarItem.h"

BEGIN_NAMESPACE_RCZIP

struct RCRarRefItem
{
    /** ������
    */
    int32_t m_volumeIndex;

    /** ������
    */
    int32_t m_itemIndex;

    /** �����
    */
    int32_t m_numItems;
};

/** RCRarRefItem����ָ��
*/
typedef RCSharedPtr<RCRarRefItem>  RCRarRefItemPtr ;

class RCRarFolderInStream:
    public IUnknownImpl<ISequentialInStream>
{

public:

    /** ��ȡ����
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize);

    /** ��ʼ��
    @param [in] archives �ĵ�
    @param [in] items ��
    @param [in] refItem ref��
    */
    void Init(RCVector<RCRarIn>* archives,
              const RCVector<RCRarItemExPtr>* items,
              const RCRarRefItemPtr& refItem);

private:

    /** ����
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult OpenStream();

    /** �ر���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult CloseStream();

private:

    /** crc
    */
    RCVector<uint32_t> m_crcs;

    /** �ĵ�
    */
    RCVector<RCRarIn>* m_archives;

    /** ��
    */
    const RCVector<RCRarItemExPtr>* m_items;

    /** ref��
    */
    RCRarRefItemPtr m_refItem;

    /** ��ǰ����
    */
    int32_t m_curIndex;

    /** crc
    */
    uint32_t m_crc;

    /** �ļ��Ƿ񱻴�
    */
    bool m_fileIsOpen;

    /** ������
    */
    ISequentialInStreamPtr m_stream;
};

END_NAMESPACE_RCZIP

#endif //__RCRarVolumeInStream_h_
