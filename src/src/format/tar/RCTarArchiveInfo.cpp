/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/tar/RCTarArchiveInfo.h"
#include "format/tar/RCTarHandler.h"

/////////////////////////////////////////////////////////////////
//RCTarArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCTarHandlerIn()
{
    RCTarHandler* tar = new RCTarHandler;
    if (tar)
    {
        return (IInArchive*)tar;
    }
    return 0;
}

IOutArchive* CreateRCTarHandlerOut()
{
    RCTarHandler* tar = new RCTarHandler;
    if (tar)
    {
        return (IOutArchive*)tar;
    }
    return 0;
}

RCTarArchiveInfo::RCTarArchiveInfo()
{
}

RCTarArchiveInfo::~RCTarArchiveInfo()
{
}

RCArchiveID RCTarArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_TAR ;
}

RCString RCTarArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_TAR ;
}

RCString RCTarArchiveInfo::GetExt() const
{
    return _T("tar") ;
}

RCString RCTarArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCTarArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(5) ;
    signature.push_back('u') ;
    signature.push_back('s') ;
    signature.push_back('t') ;
    signature.push_back('a') ;
    signature.push_back('r') ;
}

bool RCTarArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCTarArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCTarHandlerIn ;
}

PFNCreateOutArchive RCTarArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCTarHandlerOut ;
}

END_NAMESPACE_RCZIP
