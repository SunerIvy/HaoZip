/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchConverter.h"

/////////////////////////////////////////////////////////////////
//RCBranchConverter class implementation

BEGIN_NAMESPACE_RCZIP

RCBranchConverter::RCBranchConverter():
    m_bufferPos(0)
{
}

RCBranchConverter::~RCBranchConverter()
{
}

void RCBranchConverter::SubInit()
{
}

HResult RCBranchConverter::Init()
{
    m_bufferPos = 0 ;
    SubInit() ;
    return RC_S_OK ;
}

uint32_t RCBranchConverter::Filter(byte_t* data, uint32_t size)
{
    uint32_t processedSize = SubFilter(data, size) ;
    m_bufferPos += processedSize ;
    return processedSize ;
}

END_NAMESPACE_RCZIP
