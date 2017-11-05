/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/nsis/RCNsisArchiveInfo.h"
#include "format/nsis/RCNsisHandler.h"

/////////////////////////////////////////////////////////////////
//RCNsisArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCNsisHandlerIn()
{
    RCNsisHandler* nsis = new RCNsisHandler;
    if (nsis)
    {
        return (IInArchive*)nsis;
    }
    return 0;
}

IOutArchive* CreateRCNsisHandlerOut()
{
    return 0;
}

RCNsisArchiveInfo::RCNsisArchiveInfo()
{
}

RCNsisArchiveInfo::~RCNsisArchiveInfo()
{
}

RCArchiveID RCNsisArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_NSIS ;
}

RCString RCNsisArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_NSIS ;
}

RCString RCNsisArchiveInfo::GetExt() const
{
    return _T("") ;
}

RCString RCNsisArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCNsisArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(16) ;        
    signature.push_back(0xEF) ;
    signature.push_back(0xBE) ;
    signature.push_back(0xAD) ;
    signature.push_back(0xDE) ;
    signature.push_back(0x4E) ;
    signature.push_back(0x75) ;
    signature.push_back(0x6C) ;
    signature.push_back(0x6C) ;
    signature.push_back(0x73) ;
    signature.push_back(0x6F) ;
    signature.push_back(0x66) ;
    signature.push_back(0x74) ;
    signature.push_back(0x49) ;
    signature.push_back(0x6E) ;
    signature.push_back(0x73) ;
    signature.push_back(0x74) ;
}

bool RCNsisArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCNsisArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCNsisHandlerIn ;
}

PFNCreateOutArchive RCNsisArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCNsisHandlerOut ;
}

END_NAMESPACE_RCZIP
