/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/dmg/RCDmgBlock.h"

/////////////////////////////////////////////////////////////////
//RCDmgBlock class implementation

BEGIN_NAMESPACE_RCZIP

RCDmgBlock::RCDmgBlock():
    m_type(0),
    m_unpPos(0),
    m_unpSize(0),
    m_packPos(0),
    m_packSize(0)
{
}

END_NAMESPACE_RCZIP
