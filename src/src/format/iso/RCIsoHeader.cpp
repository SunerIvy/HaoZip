/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/iso/RCIsoHeader.h"
#include "format/iso/RCIsoItem.h"

BEGIN_NAMESPACE_RCZIP

const char* RCIsoHeaderDefs::kElToritoSpec = "EL TORITO SPECIFICATION\0\0\0\0\0\0\0\0\0";

const wchar_t* RCIsoHeaderDefs::kMediaTypes[5] =
{
    L"NoEmulation",
    L"1.2M",
    L"1.44M",
    L"2.88M",
    L"HardDisk"
};

END_NAMESPACE_RCZIP
