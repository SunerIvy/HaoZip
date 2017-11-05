/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/zip/RCZipArchiveInfo.h"
#include "format/zip/RCZipHandler.h"

/////////////////////////////////////////////////////////////////
//RCZipArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCZipHandlerIn()
{
    RCZipHandler* zip = new RCZipHandler;
    if (zip)
    {
        return (IInArchive*)zip;
    }
    return 0;
}

IOutArchive* CreateRCZipHandlerOut()
{
    RCZipHandler* zip = new RCZipHandler;
    if (zip)
    {
        return (IOutArchive*)zip;
    }
    return 0;
}

RCZipArchiveInfo::RCZipArchiveInfo()
{
}

RCZipArchiveInfo::~RCZipArchiveInfo()
{
}

RCArchiveID RCZipArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_ZIP ;
}

RCString RCZipArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_ZIP ;
}

RCString RCZipArchiveInfo::GetExt() const
{
    return _T("zip jar xpi") ;
}

RCString RCZipArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCZipArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(4) ;
    signature.push_back(0x50) ;
    signature.push_back(0x4B) ;
    signature.push_back(0x03) ;
    signature.push_back(0x04) ;
}

bool RCZipArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCZipArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCZipHandlerIn ;
}

PFNCreateOutArchive RCZipArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCZipHandlerOut ;
}

END_NAMESPACE_RCZIP
