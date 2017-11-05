/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/lzma/RCLzma86ArchiveInfo.h"
#include "format/lzma/RCLzmaHandler.h"

/////////////////////////////////////////////////////////////////
//RCLzma86ArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCLzma86HandlerIn()
{
    RCLzmaHandler* lzma = new RCLzmaHandler(true) ;
    if (lzma)
    {
        return (IInArchive*)lzma;
    }
    return 0;
}

IOutArchive* CreateRCLzma86HandlerOut()
{
    return 0;
}

RCLzma86ArchiveInfo::RCLzma86ArchiveInfo()
{
}

RCLzma86ArchiveInfo::~RCLzma86ArchiveInfo()
{
}

RCArchiveID RCLzma86ArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_LZMA86 ;
}

RCString RCLzma86ArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_LZMA ;
}

RCString RCLzma86ArchiveInfo::GetExt() const
{
    return _T("lzma86") ;
}

RCString RCLzma86ArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCLzma86ArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
}

bool RCLzma86ArchiveInfo::IsKeepName() const
{
    return true ;
}

PFNCreateInArchive RCLzma86ArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCLzma86HandlerIn ;
}

PFNCreateOutArchive RCLzma86ArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCLzma86HandlerOut ;
}

END_NAMESPACE_RCZIP
