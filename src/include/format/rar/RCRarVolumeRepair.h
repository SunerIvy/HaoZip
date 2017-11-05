/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarVolumeRepair_h_
#define __RCRarVolumeRepair_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCRarVolumeRepair
{
public:

    /** ����ԭʼ��¼
    @param [in] filename �ļ��� 
    @param [in] volumeIndex �־�� 
    @param [in] isFirst �Ƿ��׸��־� 
    @param [in] isEnd �Ƿ����־�
    */
    void Push(RCString filename, unsigned short volumeIndex, bool isFirst, bool isEnd);

    /** �޸�
    @param [out] outputFilenames �޸���ķ־�����
    @param [in] volumeFirst ��һ���־�·��
    @param [in] silent �Ƿ�Ĭ
    @param [in] openArchiveCallbackWrap ����ص�
    @return �ɹ�����true�����򷵻�false
    */
    bool Repair(RCVector<RCString>& outputFilenames, RCString& volumeFirst, bool silent, IArchiveOpenCallbackPtr openArchiveCallbackWrap);

private:

    /** ��
    */
    RCVector<RCArchiveVolumeItem> m_items;
};

END_NAMESPACE_RCZIP

#endif //RCRarVolumeRepair_h_
