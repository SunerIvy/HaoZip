/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/rpm/RCRpmArchiveInfo.h"
#include "format/rpm/RCRpmHandler.h"

BEGIN_NAMESPACE_RCZIP

static IInArchive* CreateRCRpmHandlerIn()
{
    RCRpmHandler* rpm = new RCRpmHandler;
    if (rpm)
    {
        return (IInArchive*)rpm;
    }
    return 0;
}

static IOutArchive* CreateRCRpmHandlerOut()
{
    return 0;
}

RCRpmArchiveInfo::RCRpmArchiveInfo()
{
}

RCRpmArchiveInfo::~RCRpmArchiveInfo()
{
}

RCArchiveID RCRpmArchiveInfo::GetArchiveID() const 
{
    return RC_ARCHIVE_RPM;
}

RCString RCRpmArchiveInfo::GetName() const 
{
    return RC_ARCHIVE_TYPE_RPM ;
}

RCString RCRpmArchiveInfo::GetExt() const 
{
    return _T("rpm");
}

RCString RCRpmArchiveInfo::GetAddExt() const 
{
    return _T("");
}

void RCRpmArchiveInfo::GetSignature(std::vector<byte_t>& signature) const 
{
    signature.clear();
    signature.push_back(0xED) ;
    signature.push_back(0xAB) ;
    signature.push_back(0xEE) ;
    signature.push_back(0xDB) ;
}

bool RCRpmArchiveInfo::IsKeepName() const 
{
    return false;
}

PFNCreateInArchive RCRpmArchiveInfo::GetCreateInArchiveFunc(void) const 
{
    return CreateRCRpmHandlerIn;
}

PFNCreateOutArchive RCRpmArchiveInfo::GetCreateOutArchiveFunc(void) const 
{
    return CreateRCRpmHandlerOut;
}

END_NAMESPACE_RCZIP

