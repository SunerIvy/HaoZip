/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zDefs_h_
#define __RC7zDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

typedef uint32_t RC7zNum ;

class RC7zDefs
{
public:

    /** ������
    */
    static const RC7zNum  s_7zNumMax     = 0x7FFFFFFF;

    /** �������
    */
    static const RC7zNum  s_7zNumNoIndex = 0xFFFFFFFF;

    /** ͷ��С
    */
    static const uint32_t s_headerSize   = 32 ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zDefs_h_
