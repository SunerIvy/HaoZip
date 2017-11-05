/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/deb/RCDebArchiveInfo.h"
#include "format/deb/RCDebHandler.h"

BEGIN_NAMESPACE_RCZIP

static IInArchive* CreateRCDebHandlerIn()
{
    RCDebHandler* deb = new RCDebHandler;
    if (deb)
    {
        return (IInArchive*)deb;
    }
    return 0;
}

static IOutArchive* CreateRCDebHandlerOut()
{
    return 0;
}


RCDebArchiveInfo::RCDebArchiveInfo()
{
}

RCDebArchiveInfo::~RCDebArchiveInfo()
{
}

RCArchiveID RCDebArchiveInfo::GetArchiveID() const 
{
    return RC_ARCHIVE_DEB;
}

RCString RCDebArchiveInfo::GetName() const 
{
    return RC_ARCHIVE_TYPE_DEB ;
}

RCString RCDebArchiveInfo::GetExt() const 
{
    return _T("deb");
}

RCString RCDebArchiveInfo::GetAddExt() const 
{
    return _T("");
}

void RCDebArchiveInfo::GetSignature(std::vector<byte_t>& signature) const 
{
    signature.clear();
    signature.push_back('!');
    signature.push_back('<');
    signature.push_back('a');
    signature.push_back('r');
    signature.push_back('c');
    signature.push_back('h');
    signature.push_back('>');
    signature.push_back('\n');
}

bool RCDebArchiveInfo::IsKeepName() const 
{
    return false;
}

PFNCreateInArchive RCDebArchiveInfo::GetCreateInArchiveFunc(void) const 
{
    return CreateRCDebHandlerIn;
}

PFNCreateOutArchive RCDebArchiveInfo::GetCreateOutArchiveFunc(void) const 
{
    return CreateRCDebHandlerOut;
}

END_NAMESPACE_RCZIP
