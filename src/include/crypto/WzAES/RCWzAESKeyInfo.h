/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWzAESKeyInfo_h_
#define __RCWzAESKeyInfo_h_ 1

#include "base/RCNonCopyable.h"
#include "crypto/WzAES/RCWzAESDefs.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** WzAES key��Ϣ
*/
class RCWzAESKeyInfo:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWzAESKeyInfo() ;
    
    /** Ĭ����������
    */
    ~RCWzAESKeyInfo() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;

    /** ����key��С
    @return ����key��С
    */
    uint32_t GetKeySize() const ;

    /** ����salt��С
    @return ����salt��С
    */
    uint32_t GetSaltSize() const ;

public:

    /** kei ��Сģʽ
    */
    byte_t m_keySizeMode; // 1 - 128-bit , 2 - 192-bit , 3 - 256-bit

    /** salt
    */
    byte_t m_salt[RCWzAESDefs::s_kSaltSizeMax];

    /** ����У��
    */ 
    byte_t m_pwdVerifComputed[RCWzAESDefs::s_kPwdVerifCodeSize];
    
    /** ����
    */
    RCByteBuffer m_password ;
};

END_NAMESPACE_RCZIP

#endif //__RCWzAESKeyInfo_h_
