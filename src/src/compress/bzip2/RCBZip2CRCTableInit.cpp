/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/bzip2/RCBZip2CRCTableInit.h"
#include "compress/bzip2/RCBZip2CRC.h"

/////////////////////////////////////////////////////////////////
//RCBZip2CRCTableInit class implementation

BEGIN_NAMESPACE_RCZIP

RCBZip2CRCTableInit::RCBZip2CRCTableInit()
{
    RCBZip2CRC::InitTable() ;
}

RCBZip2CRCTableInit::~RCBZip2CRCTableInit()
{
    
}

END_NAMESPACE_RCZIP
