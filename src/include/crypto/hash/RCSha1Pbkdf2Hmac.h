/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSha1Pbkdf2Hmac_h_
#define __RCSha1Pbkdf2Hmac_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Sha1 Pbkdf2 Hmac
*/
class RCSha1Pbkdf2Hmac
{
public:

    /**
    @param [in] pwd ����
    @param [in] pwdSize �����С
    @param [in] salt 
    @param [in] saltSize
    @param [in] numIterations ��������
    @param [in] key ����key
    @param [in] keySize key��С
    */
    static void Pbkdf2Hmac( const byte_t* pwd, 
                            size_t pwdSize, 
                            const byte_t* salt, 
                            size_t saltSize,
                            uint32_t numIterations, 
                            byte_t* key, 
                            size_t keySize
                           );
    
    /**
    @param [in] pwd ����
    @param [in] pwdSize �����С
    @param [in] salt 
    @param [in] saltSize
    @param [in] numIterations ��������
    @param [in] key ����key
    @param [in] keySize key��С
    */
    static void Pbkdf2Hmac32( const byte_t* pwd, 
                              size_t pwdSize, 
                              const uint32_t* salt,
                              size_t saltSize,
                              uint32_t numIterations, 
                              uint32_t* key,
                              size_t keySize
                            );
};

END_NAMESPACE_RCZIP

#endif //__RCSha1Pbkdf2Hmac_h_
