/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/7z/RC7zInArchiveInfo.h"

/////////////////////////////////////////////////////////////////
//RC7zInArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

RC7zInArchiveInfo::RC7zInArchiveInfo():
    m_startPosition(0),
    m_startPositionAfterHeader(0),
    m_dataStartPosition(0),
    m_dataStartPosition2(0)
{
}

RC7zInArchiveInfo::~RC7zInArchiveInfo()
{
}

void RC7zInArchiveInfo::Clear()
{
    m_fileInfoPopIDs.clear();
}

END_NAMESPACE_RCZIP
