/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/hfs/RCHfsArchiveInfo.h"
#include "format/hfs/RCHfsHandler.h"

/////////////////////////////////////////////////////////////////
//RCHfsArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCHfsHandlerIn()
{
    RCHfsHandler* hfs = new RCHfsHandler;
    if (hfs)
    {
        return (IInArchive*)hfs;
    }
    return 0;
}

IOutArchive* CreateRCHfsHandlerOut()
{
    return 0;
}

RCHfsArchiveInfo::RCHfsArchiveInfo()
{
}

RCHfsArchiveInfo::~RCHfsArchiveInfo()
{
}

RCArchiveID RCHfsArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_HFS ;
}

RCString RCHfsArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_HFS ;
}

RCString RCHfsArchiveInfo::GetExt() const
{
    return _T("hfs") ;
}

RCString RCHfsArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCHfsArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
    signature.push_back('H') ;
    signature.push_back('+') ;
    signature.push_back(0) ;
    signature.push_back(4) ;
}

bool RCHfsArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCHfsArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCHfsHandlerIn ;
}

PFNCreateOutArchive RCHfsArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCHfsHandlerOut ;
}

END_NAMESPACE_RCZIP
