/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/branch/RCBranch86.h"
#include "algorithm/Bra.h"

/////////////////////////////////////////////////////////////////
//RCBranch86 class implementation

BEGIN_NAMESPACE_RCZIP

void RCBranch86::x86Init()
{
    x86_Convert_Init(m_prevMask);
}

END_NAMESPACE_RCZIP
