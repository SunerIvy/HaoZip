/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/split/RCSplitArchiveInfo.h"
#include "format/split/RCSplitHandler.h"

/////////////////////////////////////////////////////////////////
//RCSplitArchiveInfo class implementation

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCSplitHandlerIn()
{
    RCSplitHandler* split = new RCSplitHandler;
    if (split)
    {
        return (IInArchive*)split;
    }
    return 0;
}

IOutArchive* CreateRCSplitHandlerOut()
{
    return 0;
}

RCSplitArchiveInfo::RCSplitArchiveInfo()
{
}

RCSplitArchiveInfo::~RCSplitArchiveInfo()
{
}

RCArchiveID RCSplitArchiveInfo::GetArchiveID() const
{
    return RC_ARCHIVE_SPLIT ;
}

RCString RCSplitArchiveInfo::GetName() const
{
    return RC_ARCHIVE_TYPE_SPLIT ;
}

RCString RCSplitArchiveInfo::GetExt() const
{
    return _T("001") ;
}

RCString RCSplitArchiveInfo::GetAddExt() const
{
    return _T("") ;
}

void RCSplitArchiveInfo::GetSignature(std::vector<byte_t>& signature) const
{
    signature.clear() ;
}

bool RCSplitArchiveInfo::IsKeepName() const
{
    return false ;
}

PFNCreateInArchive RCSplitArchiveInfo::GetCreateInArchiveFunc(void) const
{
    return CreateRCSplitHandlerIn ;
}

PFNCreateOutArchive RCSplitArchiveInfo::GetCreateOutArchiveFunc(void) const
{
    return CreateRCSplitHandlerOut ;
}

END_NAMESPACE_RCZIP
