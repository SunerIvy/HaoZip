/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/lzh/RCLzhArchiveInfo.h"
#include "format/lzh/RCLzhHandler.h"

/////////////////////////////////////////////////////////////////
//RCLzhArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCLzhHandlerIn()
{
    RCLzhHandler* lzh = new RCLzhHandler;
    if (lzh)
    {
        return (IInArchive*)lzh;
    }
    return 0;
}

IOutArchive* CreateRCLzhHandlerOut()
{
    return 0;
}

RCLzhArchiveInfo::RCLzhArchiveInfo()
{
}

RCLzhArchiveInfo::~RCLzhArchiveInfo()
{
}

RCArchiveID RCLzhArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_LZH ;
}

RCString RCLzhArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_LZH ;
}

RCString RCLzhArchiveInfo::GetExt() const
{
    return _T("lzh lha") ;
}

RCString RCLzhArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCLzhArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.reserve(2) ;
    signature.push_back('-') ;
    signature.push_back('l') ;
}

bool RCLzhArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCLzhArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCLzhHandlerIn ;
}

PFNCreateOutArchive RCLzhArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCLzhHandlerOut ;
}

END_NAMESPACE_RCZIP
