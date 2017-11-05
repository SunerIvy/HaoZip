/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zAESKeyInfo_h_
#define __RC7zAESKeyInfo_h_ 1

#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** 7z AES Key
*/
class RC7zAESKeyInfo
{
public:

    /** Key Size
    */
    static const int32_t s_kKeySize = 32 ;
    
public:
    /** ���캯��
    */
    RC7zAESKeyInfo() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** �Ƿ����
    @param [in] a �Ƚ�ֵ
    @return ��ȷ���true,���򷵻�false
    */
    bool IsEqualTo(const RC7zAESKeyInfo& a) const;

    /** ����ժҪ
    */
    void CalculateDigest();
    
public:
    
    /** Cycles Power
    */
    int32_t m_numCyclesPower ;

    /** salt Size
    */
    uint32_t m_saltSize ;

    /** salt
    */
    byte_t m_salt[16] ;

    /** ����
    */
    RCByteBuffer m_password ;

    /** key
    */
    byte_t m_key[s_kKeySize] ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zAESKeyInfo_h_
