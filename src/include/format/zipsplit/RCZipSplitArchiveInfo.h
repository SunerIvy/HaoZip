/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipSplitArchiveInfo_h_
#define __RCZipSplitArchiveInfo_h_ 1

#include "common/RCArchiveInfoBase.h"

BEGIN_NAMESPACE_RCZIP

/** zip �־���
*/
class RCZipSplitArchiveInfo:
    public RCArchiveInfoBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZipSplitArchiveInfo() ;
    
    /** Ĭ����������
    */
    ~RCZipSplitArchiveInfo() ;
    
public:

    /** �ĵ�����ΨһID
    @return �ĵ�ID
    */
    virtual RCArchiveID GetArchiveID() const ;
    
    /** ��ȡArchive����
    */
    virtual RCString GetName() const ;
    
    /** ��ȡArchive��չ��
    */
    virtual RCString GetExt() const ;
    
    /** ��ȡArchive��չ��
    */
    virtual RCString GetAddExt() const ;
    
    /** ��ȡArchiveǩ��
    */
    virtual void GetSignature(std::vector<byte_t>& signature) const ;
        
    /** ��ȡKeepName����
    */
    virtual bool IsKeepName() const ;
    
    /** ��ȡ����InArchive����
    */
    virtual PFNCreateInArchive GetCreateInArchiveFunc(void) const ;
    
    /** ��ȡ����InArchive����
    */
    virtual PFNCreateOutArchive GetCreateOutArchiveFunc(void) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCZipSplitArchiveInfo_h_
