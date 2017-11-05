/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWzAESDefs_h_
#define __RCWzAESDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** WzAES ��������
*/
class RCWzAESDefs
{
public:
    static const uint32_t s_kSaltSizeMax = 16;
    static const uint32_t s_kMacSize = 10;
    static const uint32_t s_kPasswordSizeMax = 99 ; // 128;

    /** Password Verification Code Size
    */
    static const uint32_t s_kPwdVerifCodeSize = 2 ;
    static const uint32_t s_kAesKeySizeMax = 32;
    static const uint32_t s_kNumKeyGenIterations = 1000;
};

/** �Ż�ѡ���
*/
//#define _NO_WZAES_OPTIMIZATIONS 1

END_NAMESPACE_RCZIP

#endif //__RCWzAESDefs_h_
