/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/rar/RCRarVolumeRepair.h"
#include "filesystem/RCFileTime.h"
#include "common/RCStringConvert.h"
#include "common/RCStringUtil.h"
#include "format/common/RCItemNameUtils.h"
#include "format/common/RCOutStreamWithCRC.h"
#include "common/RCCreateCoder.h"
#include "common/RCFilterCoder.h"
#include "common/RCLocalProgress.h"
#include "interface/RCMethodDefs.h"
#include "crypto/Rar20/RCRar20Decoder.h"
#include "crypto/WzAES/RCWzAESDecoder.h"
#include "format/common/RCPropData.h"
#include "format/rar/RCRarGetComment.h"
#include "format/rar/RCRarFileInfoParse.h"
#include "filesystem/RCFindFile.h"
#include "filesystem/RCFileInfo.h"
#include "filesystem/RCFileSystemUtils.h"
#include "thread/RCThread.h"
#include "thread/RCSynchronization.h"
#include "locked/RCMtExtractProgressMixer.h"
#include "locked/RCMtExtractProgress.h"
#include "locked/RCMtLocalProgress.h"
#include "interface/RCArchiveType.h"

/////////////////////////////////////////////////////////////////
//RCRarVolumeRepair class implementation

BEGIN_NAMESPACE_RCZIP

void RCRarVolumeRepair::Push(RCString filename, unsigned short volumeIndex, bool isFirst, bool isEnd)
{
    RCArchiveVolumeItem item;
    item.m_filename = filename;
    item.m_volumeIndex = volumeIndex;
    item.m_isFirst = isFirst;
    item.m_isEnd = isEnd;

    m_items.push_back(item);
}

bool RCRarVolumeRepair::Repair(RCVector<RCString>& outputFilenames, RCString& volumeFirst, bool silent, IArchiveOpenCallbackPtr openArchiveCallbackWrap)
{
    /** �Զ������ҵķ־�

        1 ������ܷ������λ���������������������������ĩ���������ȷ
        2 ���2�����㣬���ܷ������λ�������������������
        3 ���3���㣬�򵯳��Ի���ѡ��
    */
    if (m_items.size() == 0)
    {
        return false;
    }

    sort(m_items.begin(), m_items.end());

    // �ܷ������λ�������������������
    for (uint32_t i = 0; i < m_items.size(); i++)
    {
        if (m_items[i].m_volumeIndex == i)
        {
            if (i == 0)
            {
                if (!m_items[i].m_isFirst)
                {
                    break;
                }
                else if (m_items[i].m_isEnd)
                {
                    // ����ֻ��һ���־�
                    volumeFirst = m_items[i].m_filename;
                    return true;
                }
            }
            else if (m_items[i].m_isEnd)
            {
                // ����־�
                volumeFirst = m_items[0].m_filename;
                for (uint32_t j = 1; j < m_items.size(); j++)
                {
                    outputFilenames.push_back(m_items[j].m_filename);
                }
                return true;
            }
        }
        else
        {
            break;
        }
    }

    // �ܷ������λ�������������������
    bool find = false;

    // ��1�����Ѿ�Ѱ�ҵ��ķ־�������š�
    uint32_t chainCurrent = 0;
    for (uint32_t i = 0; i < m_items.size(); i++)
    {
        if (static_cast<uint32_t>(m_items[i].m_volumeIndex + 1) == chainCurrent)
        {
            // ��ǰ�־�ŵ����Ѿ�Ѱ�ҵ��ķ־�������ţ����ж��Ƿ�������������������ҵ��ˡ�

            if (i == 0 && (!m_items[i].m_isFirst))
            {
                continue;
            }

            if (m_items[i].m_isEnd)
            {
                find = true;
                break;
            }
        }
        else if (static_cast<uint32_t>(m_items[i].m_volumeIndex + 1) == (chainCurrent + 1))
        {
            // ��ǰ�־�ŵ����Ѿ�Ѱ�ҵ��ķ־�������ŵ���һ�־����Ѿ�Ѱ�ҵ��ķ־�����������ӡ�

            if (m_items[i].m_isEnd)
            {
                find = true;
                break;
            }

            chainCurrent++;
        }
        else
        {
            // ��ȱʧ
            break;
        }
    }

    if (silent || (!find) || (!openArchiveCallbackWrap))
    {
        return false;
    }

    //�����Ի���
    if (openArchiveCallbackWrap->VolumeRepair(m_items, volumeFirst, outputFilenames) == RC_S_OK)
    {
        return true;
    }

    outputFilenames.clear();
    return false;
}

END_NAMESPACE_RCZIP
