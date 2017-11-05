/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSplitArchiveInfo_h_
#define __RCSplitArchiveInfo_h_ 1

#include "common/RCArchiveInfoBase.h"

BEGIN_NAMESPACE_RCZIP

/** �־��ʽ��Ϣ
*/
class RCSplitArchiveInfo:
    public RCArchiveInfoBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSplitArchiveInfo() ;
    
    /** Ĭ����������
    */
    ~RCSplitArchiveInfo() ;
    
public:

    /** �ĵ�����ΨһID
    @return �ĵ�ID
    */
    virtual RCArchiveID GetArchiveID() const ;
    
    /** ��ȡArchive����
    @return �����ĵ���ʽ����
    */
    virtual RCString GetName() const ;
    
    /** ��ȡArchive��չ��
    @return ���ظ�ʽ��չ��
    */
    virtual RCString GetExt() const ;
    
    /** ��ȡArchive��չ��
    @return ���ظ�����չ��
    */
    virtual RCString GetAddExt() const ;
    
    /** ��ȡArchiveǩ��
    @param [out] signature ��ʽǩ��
    */
    virtual void GetSignature(std::vector<byte_t>& signature) const ;
        
    /** ��ȡKeepName����
    @return ����KeepName����
    */
    virtual bool IsKeepName() const ;
    
    /** ��ȡ����InArchive����
    @return ����InArchive��������
    */
    virtual PFNCreateInArchive GetCreateInArchiveFunc(void) const ;
    
    /** ��ȡ����OutArchive����
    @return ����OutArchive��������
    */
    virtual PFNCreateOutArchive GetCreateOutArchiveFunc(void) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCSplitArchiveInfo_h_
