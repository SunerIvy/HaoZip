/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "algorithm/RCInitCRCTable.h"
#include "algorithm/7zCrc.h"

/////////////////////////////////////////////////////////////////
//RCInitCRCTable class implementation

BEGIN_NAMESPACE_RCZIP

RCInitCRCTableImpl::RCInitCRCTableImpl()
{
    CrcGenerateTable() ;
}


END_NAMESPACE_RCZIP
