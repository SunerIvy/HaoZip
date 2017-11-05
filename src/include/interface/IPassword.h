/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IPassword_h
#define __IPassword_h 1

#include "interface/IUnknown.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_ICryptoGetTextPassword     = IID_IPASSWORD_BASE,
    IID_ICryptoGetTextPassword2
};

/** ��ȡ����ӿ�
*/
class ICryptoGetTextPassword:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoGetTextPassword } ;
    
public:
    
    /** ��ȡ����
    @param [out] password ��ȡ������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CryptoGetTextPassword(RCString& password) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoGetTextPassword(){} ;
};

/** ��ȡ����ӿ�
*/
class ICryptoGetTextPassword2:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoGetTextPassword2 } ;
    
public:
    
    /** ��ȡ����
    @param [out] passwordIsDefined �����Ƿ��� ����0��ʾû�ж������룬����1��ʾ������ ����0��ʾû�ж������룬����1��ʾ������
    @param [out] password ��ȡ������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CryptoGetTextPassword2(int32_t* passwordIsDefined, RCString& password) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoGetTextPassword2(){} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<ICryptoGetTextPassword>    ICryptoGetTextPasswordPtr ;
typedef RCComPtr<ICryptoGetTextPassword2>   ICryptoGetTextPassword2Ptr ;

END_NAMESPACE_RCZIP

#endif //__IPassword_h
