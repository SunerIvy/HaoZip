/********************************************************************************
 *  版权所有(C)2008,2009,2010，好压软件工作室，保留所有权利。                   *
 ********************************************************************************
 *  作者    : HaoZip                                                            *
 *  版本    : 1.7                                                               *
 *  联系方式: haozip@gmail.com                                                  *
 *  官方网站: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranchIA64Decoder.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranchIA64Decoder class implementation

BEGIN_NAMESPACE_RCZIP

uint32_t RCBranchIA64Decoder::SubFilter(byte_t* data, uint32_t size)
{
    return (uint32_t)::IA64_Convert(data, size, m_bufferPos, 0);
}

END_NAMESPACE_RCZIP
