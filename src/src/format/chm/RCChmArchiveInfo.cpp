/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/chm/RCChmArchiveInfo.h"
#include "format/chm/RCChmHandler.h"

/////////////////////////////////////////////////////////////////
//RCChmArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCChmHandlerIn()
{
    RCChmHandler* chm = new RCChmHandler;
    if (chm)
    {
        return (IInArchive*)chm;
    }
    return 0;
}

IOutArchive* CreateRCChmHandlerOut()
{
    return 0;
}

RCChmArchiveInfo::RCChmArchiveInfo()
{
}

RCChmArchiveInfo::~RCChmArchiveInfo()
{
}

RCArchiveID RCChmArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_CHM ;
}

RCString RCChmArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_CHM ;
}

RCString RCChmArchiveInfo::GetExt() const
{
    return _T("chm chi chq chw hxs hxi hxr hxq hxw lit") ;
}

RCString RCChmArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCChmArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(4) ;        
    signature.push_back('I') ;
    signature.push_back('T') ;
    signature.push_back('S') ;
    signature.push_back('F') ;
}

bool RCChmArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCChmArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCChmHandlerIn ;
}

PFNCreateOutArchive RCChmArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCChmHandlerOut ;
}

END_NAMESPACE_RCZIP
