/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/cpio/RCCpioArchiveInfo.h"
#include "format/cpio/RCCpioHandler.h"

/////////////////////////////////////////////////////////////////
//RCCpioArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCCpioHandlerIn()
{
    RCCpioHandler* cpio = new RCCpioHandler;
    if (cpio)
    {
        return (IInArchive*)cpio;
    }
    return 0;
}

IOutArchive* CreateRCCpioHandlerOut()
{
    return 0;
}

RCCpioArchiveInfo::RCCpioArchiveInfo()
{
}

RCCpioArchiveInfo::~RCCpioArchiveInfo()
{
}

RCArchiveID RCCpioArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_CPIO ;
}

RCString RCCpioArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_CPIO ;
}

RCString RCCpioArchiveInfo::GetExt() const
{
    return _T("cpio") ;
}

RCString RCCpioArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCCpioArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
}

bool RCCpioArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCCpioArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCCpioHandlerIn ;
}

PFNCreateOutArchive RCCpioArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCCpioHandlerOut ;
}

END_NAMESPACE_RCZIP
