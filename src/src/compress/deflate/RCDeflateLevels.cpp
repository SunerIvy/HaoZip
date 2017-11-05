/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/deflate/RCDeflateLevels.h"

/////////////////////////////////////////////////////////////////
//RCDeflateLevels class implementation

BEGIN_NAMESPACE_RCZIP

RCDeflateLevels::RCDeflateLevels()
{
}

RCDeflateLevels::~RCDeflateLevels()
{
}

void RCDeflateLevels::SubClear()
{
    uint32_t i = 0 ;
    for(i = RCDeflateDefs::s_kNumLitLenCodesMin; i < RCDeflateDefs::s_kFixedMainTableSize; i++)
    {
        m_litLenLevels[i] = 0;
    }
    for(i = 0; i < RCDeflateDefs::s_kFixedDistTableSize; i++)
    {
        m_distLevels[i] = 0;
    }
}

void RCDeflateLevels::SetFixedLevels()
{
    int32_t i = 0 ;    
    for (i = 0; i < 144; i++)
    {
        m_litLenLevels[i] = 8;
    }
    for (; i < 256; i++)
    {
        m_litLenLevels[i] = 9;
    }
    for (; i < 280; i++)
    {
        m_litLenLevels[i] = 7;
    }
    for (; i < 288; i++)
    {
        m_litLenLevels[i] = 8;
    }
    for (i = 0; i < RCDeflateDefs::s_kFixedDistTableSize; i++)  // test it: InfoZip only uses kDistTableSize
    {
        m_distLevels[i] = 5;
    }
}
  
END_NAMESPACE_RCZIP
