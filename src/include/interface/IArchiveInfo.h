/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IArchiveInfo_h_
#define __IArchiveInfo_h_ 1

#include "interface/RCArchiveType.h"
#include "interface/IRefCounted.h"
#include "base/RCString.h"
#include <vector>

BEGIN_NAMESPACE_RCZIP

class IInArchive ;
class IOutArchive ;

/** ���������ĵ��ĺ�������
@return ����IInArchive�ӿ�ָ��
*/
typedef IInArchive* (*PFNCreateInArchive)(void) ;

/** ��������ĵ��ĺ�������
@return ����IOutArchive�ӿ�ָ��
*/
typedef IOutArchive* (*PFNCreateOutArchive)(void) ;

/** �ĵ���Ϣ�ӿ� 
*/
class IArchiveInfo:
    public IRefCounted
{
public:
    
    /** �ĵ�����ΨһID
    @return �ĵ�ID
    */
    virtual RCArchiveID GetArchiveID() const = 0 ;

    /** ��ȡ�ĵ�����
    @return �ĵ�����
    */
    virtual RCString GetName() const = 0 ;
    
    /** ��ȡ�ĵ���չ��
    @return �ĵ���չ��
    */
    virtual RCString GetExt() const = 0 ;
    
    /** ��ȡ�ĵ�������չ��
    @return �ĵ�������չ��
    */
    virtual RCString GetAddExt() const = 0 ;
    
    /** ��ȡ�ĵ�ǩ��
    @param [out] signature �����ļ�ǩ��
    */
    virtual void GetSignature(std::vector<byte_t>& signature) const = 0 ;
        
    /** ��ȡKeepName����
    @return ���KeepName�򷵻�true�����򷵻�false
    */
    virtual bool IsKeepName() const = 0 ;
    
    /** ��ȡ���������ĵ�����
    @return ����ָ��
    */
    virtual PFNCreateInArchive GetCreateInArchiveFunc(void) const = 0 ;
    
    /** ��ȡ��������ĵ�����
    @return ����ָ��
    */
    virtual PFNCreateOutArchive GetCreateOutArchiveFunc(void) const = 0 ;

protected:
        
    /** Ĭ����������
    */
    ~IArchiveInfo() {} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IArchiveInfo>  IArchiveInfoPtr ;

END_NAMESPACE_RCZIP

#endif //__IArchiveInfo_h_
