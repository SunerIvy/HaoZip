/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "crypto/AES/RCAesTableInit.h"
#include "algorithm/Aes.h"

/////////////////////////////////////////////////////////////////
//RCAesTableInitImpl class implementation

BEGIN_NAMESPACE_RCZIP

RCAesTableInitImpl::RCAesTableInitImpl()
{
    AesGenTables();
}

RCAesTableInitImpl::~RCAesTableInitImpl()
{
}

END_NAMESPACE_RCZIP
