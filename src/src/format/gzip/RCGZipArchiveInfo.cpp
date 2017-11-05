/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/gzip/RCGZipArchiveInfo.h"
#include "format/gzip/RCGZipHandler.h"

/////////////////////////////////////////////////////////////////
//RCGZipArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCGZipHandlerIn()
{
    RCGZipHandler* gzip = new RCGZipHandler;
    if (gzip)
    {
        return (IInArchive*)gzip;
    }
    return 0;
}

IOutArchive* CreateRCGZipHandlerOut()
{
    RCGZipHandler* gzip = new RCGZipHandler;
    if (gzip)
    {
        return (IOutArchive*)gzip;
    }
    return 0;
}

RCGZipArchiveInfo::RCGZipArchiveInfo()
{
}

RCGZipArchiveInfo::~RCGZipArchiveInfo()
{
}

RCArchiveID RCGZipArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_GZIP ;
}

RCString RCGZipArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_GZIP ;
}

RCString RCGZipArchiveInfo::GetExt() const
{
    return _T("gz gzip tgz tpz") ;
}

RCString RCGZipArchiveInfo::GetAddExt() const
{
    return _T("* * .tar .tar") ;
}

void RCGZipArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(3) ;
    signature.push_back(0x1F) ;
    signature.push_back(0x8B) ;
    signature.push_back(8) ;
}

bool RCGZipArchiveInfo::IsKeepName() const
{
    return true ;
}

PFNCreateInArchive RCGZipArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCGZipHandlerIn ;
}

PFNCreateOutArchive RCGZipArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCGZipHandlerOut ;
}

END_NAMESPACE_RCZIP
