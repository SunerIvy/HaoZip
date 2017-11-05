/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/dmg/RCDmgArchiveInfo.h"
#include "format/dmg/RCDmgHandler.h"

/////////////////////////////////////////////////////////////////
//RCDmgArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCDmgHandlerIn()
{
    RCDmgHandler* dmg = new RCDmgHandler;
    if (dmg)
    {
        return (IInArchive*)dmg;
    }
    return 0;
}

IOutArchive* CreateRCDmgHandlerOut()
{
    return 0;
}

RCDmgArchiveInfo::RCDmgArchiveInfo()
{
}

RCDmgArchiveInfo::~RCDmgArchiveInfo()
{
}

RCArchiveID RCDmgArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_DMG ;
}

RCString RCDmgArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_DMG ;
}

RCString RCDmgArchiveInfo::GetExt() const
{
    return _T("dmg") ;
}

RCString RCDmgArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCDmgArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
}

bool RCDmgArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCDmgArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCDmgHandlerIn ;
}

PFNCreateOutArchive RCDmgArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCDmgHandlerOut ;
}

END_NAMESPACE_RCZIP
