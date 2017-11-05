/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/zipsplit/RCZipSplitArchiveInfo.h"
#include "format/zipsplit/RCZipSplitHandler.h"
#include "common/RCStringUtil.h"

BEGIN_NAMESPACE_RCZIP

IInArchive* CreateRCZipSplitHandlerIn()
{
    RCZipSplitHandler* split = new RCZipSplitHandler;
    if (split)
    {
        return (IInArchive*)split;
    }
    return 0;
}

IOutArchive* CreateRCZipSplitHandlerOut()
{
    return 0;
}

RCZipSplitArchiveInfo::RCZipSplitArchiveInfo()
{
}

RCZipSplitArchiveInfo::~RCZipSplitArchiveInfo()
{
}

RCArchiveID RCZipSplitArchiveInfo::GetArchiveID() const 
{
    return RC_ARCHIVE_ZIP_SPLIT;
}

RCString RCZipSplitArchiveInfo::GetName() const 
{
    return RC_ARCHIVE_TYPE_ZIP_SPLIT;
}

RCString RCZipSplitArchiveInfo::GetExt() const 
{   //ע�����99���־�ĺ�׺��
    RCString ret;
    for (uint32_t i = 1; i < 100; i++)
    {
        RCString ext;
        RCStringUtil::Format(ext, _T("z%.2d"), i);
        if (!ret.empty())
        {
            ret += _T(" ");
        }
        ret += ext;
    }
    return ret;
}

RCString RCZipSplitArchiveInfo::GetAddExt() const 
{
    return _T("");
}

void RCZipSplitArchiveInfo::GetSignature(std::vector<byte_t>& signature) const 
{
    signature.clear();
}
    
bool RCZipSplitArchiveInfo::IsKeepName() const 
{
    return false;
}

PFNCreateInArchive RCZipSplitArchiveInfo::GetCreateInArchiveFunc(void) const 
{
    return CreateRCZipSplitHandlerIn;
}

PFNCreateOutArchive RCZipSplitArchiveInfo::GetCreateOutArchiveFunc(void) const 
{
    return CreateRCZipSplitHandlerOut;
}

END_NAMESPACE_RCZIP
