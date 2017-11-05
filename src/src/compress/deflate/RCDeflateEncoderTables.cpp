/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateEncoderTables.h"

/////////////////////////////////////////////////////////////////
//RCDeflateEncoderTables class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateEncoderTables::RCDeflateEncoderTables():
    m_useSubBlocks(false),
    m_storeMode(false),
    m_staticMode(false),
    m_blockSizeRes(0),
    m_pos(0)
{
}

RCDeflateEncoderTables::~RCDeflateEncoderTables()
{
}

void RCDeflateEncoderTables::InitStructures()
{
    uint32_t i = 0 ;
    for(i = 0; i < 256; i++)
    {
        m_litLenLevels[i] = 8;
    }
    m_litLenLevels[i++] = 13;
    for(;i < RCDeflateDefs::s_kFixedMainTableSize; i++)
    {
        m_litLenLevels[i] = 5;
    }
    for(i = 0; i < RCDeflateDefs::s_kFixedDistTableSize; i++)
    {
        m_distLevels[i] = 5;
    }
}

END_NAMESPACE_RCZIP
