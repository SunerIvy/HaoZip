/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCpioArchiveInfo_h_
#define __RCCpioArchiveInfo_h_ 1

#include "common/RCArchiveInfoBase.h"

BEGIN_NAMESPACE_RCZIP

class RCCpioArchiveInfo:
    public RCArchiveInfoBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCpioArchiveInfo() ;
    
    /** Ĭ����������
    */
    ~RCCpioArchiveInfo() ;
 
public:

    /** �ĵ�����ΨһID
    @return �ĵ�ID
    */
    virtual RCArchiveID GetArchiveID() const ;
    
    /** ��ȡArchive����
    @return ����Archive����
    */
    virtual RCString GetName() const ;
    
    /** ��ȡArchive��չ��
    @return ����Archive��չ��
    */
    virtual RCString GetExt() const ;
    
    /** ��ȡArchive��չ��
    @return ����Archive��չ��
    */
    virtual RCString GetAddExt() const ;
    
    /** ��ȡArchiveǩ��
    @param [out] signature ����Archiveǩ��
    */
    virtual void GetSignature(std::vector<byte_t>& signature) const ;
        
    /** ��ȡKeepName����
    @return ����KeepName����
    */
    virtual bool IsKeepName() const ;
    
    /** ��ȡ����InArchive����
    @return ����InArchive����ָ��
    */
    virtual PFNCreateInArchive GetCreateInArchiveFunc(void) const ;
    
    /** ��ȡ����OutArchive����
    @return ����OutArchive����ָ��
    */
    virtual PFNCreateOutArchive GetCreateOutArchiveFunc(void) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCCpioArchiveInfo_h_
