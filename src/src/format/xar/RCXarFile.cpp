/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/xar/RCXarFile.h"

/////////////////////////////////////////////////////////////////
//RCXarFile class implementation

BEGIN_NAMESPACE_RCZIP

RCXarFile::RCXarFile():
    m_isDir(false), 
    m_hasData(false), 
    m_sha1IsDefined(false),
    m_parent(-1), 
    m_size(0), 
    m_packSize(0), 
    m_cTime(0), 
    m_mTime(0), 
    m_aTime(0) 
{
}

RCXarFile::~RCXarFile()
{
}

END_NAMESPACE_RCZIP
