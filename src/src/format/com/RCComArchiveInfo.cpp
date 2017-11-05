/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/com/RCComArchiveInfo.h"
#include "format/com/RCComHandler.h"

BEGIN_NAMESPACE_RCZIP

static IInArchive* CreateRCComHandlerIn()
{
    RCComHandler* com = new RCComHandler;
    if (com)
    {
        return (IInArchive*)com;
    }
    return 0;
}

static IOutArchive* CreateRCComHandlerOut()
{
    return 0;
}


RCComArchiveInfo::RCComArchiveInfo()
{
}

RCComArchiveInfo::~RCComArchiveInfo()
{
}

RCArchiveID RCComArchiveInfo::GetArchiveID() const 
{
    return RC_ARCHIVE_COM;
}

RCString RCComArchiveInfo::GetName() const 
{
    return RC_ARCHIVE_TYPE_COM ;
}

RCString RCComArchiveInfo::GetExt() const 
{
    //return _T("msi msp doc xls ppt");
    return _T("msi msp");
}

RCString RCComArchiveInfo::GetAddExt() const 
{
    return _T("");
}

void RCComArchiveInfo::GetSignature(std::vector<byte_t>& signature) const 
{
    signature.clear();
    signature.push_back(0xD0);
    signature.push_back(0xCF);
    signature.push_back(0x11);
    signature.push_back(0xE0);
    signature.push_back(0xA1);
    signature.push_back(0xB1);
    signature.push_back(0x1A);
    signature.push_back(0xE1);
}

bool RCComArchiveInfo::IsKeepName() const 
{
    return false;
}

PFNCreateInArchive RCComArchiveInfo::GetCreateInArchiveFunc(void) const 
{
    return CreateRCComHandlerIn;
}

PFNCreateOutArchive RCComArchiveInfo::GetCreateOutArchiveFunc(void) const 
{
    return CreateRCComHandlerOut;
}

END_NAMESPACE_RCZIP
