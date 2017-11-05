/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveInfoEx_h_
#define __RCArchiveInfoEx_h_ 1

#include "archive/manager/RCArchiveExtInfo.h"
#include "interface/IArchiveInfo.h"
#include "common/RCVector.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ĵ�����Ϣ����
*/
class RCArchiveInfoEx
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveInfoEx() ;
    
    /** Ĭ����������
    */
    ~RCArchiveInfoEx() ;
    
    /** �������캯��
    */
    RCArchiveInfoEx(const RCArchiveInfoEx& rhs) ;
    
    /** ��ֵ������
    */
    RCArchiveInfoEx& operator= (const RCArchiveInfoEx& rhs) ;
    
public:
    
    /** ��ʼ��
    @param [in] spArcInfo �ĵ���ʽ��Ϣ
    */
    void initialize(const IArchiveInfoPtr& spArcInfo) ;
    
    /** �ĵ�����ΨһID
    @return �ĵ�ID
    */
    RCArchiveID GetArchiveID() const ;

    /** ��ȡ�ĵ�����
    @return �ĵ�����
    */
    RCString GetName() const ;
    
    /** ��ȡ�ĵ�ǩ��
    @param [out] signature �����ļ�ǩ��
    */
    void GetSignature(std::vector<byte_t>& signature) const ;
        
    /** ��ȡKeepName����
    @return ���KeepName�򷵻�true�����򷵻�false
    */
    bool IsKeepName() const ;
    
    /** �Ƿ���������ĵ�
    @return ���Ը��·���true,���򷵻�false
    */
    bool IsEnableUpdate(void) const ;
    
    /** ��ȡ����չ��
    @return ���ظ�ʽ��չ��
    */
    RCString GetMainExt(void) const ;
    
    /** ������չ��
    @param [in] ext ��չ��
    @return ���ƥ�䵽��չ��������ֵ >=0 �����û��ƥ�䣬�򷵻�-1
    */
    int32_t FindExtension(const RCString& ext) const ;
    
    /** ��ȡ������չ�����Կո���Ϊ�ָ���
    @return ����������չ��
    */
    RCString GetAllExtensions(void) const ;
    
    /** ��ȡ��չ������
    @return ������չ������
    */
    uint32_t GetExtCount(void) const ;
    
    /** ��ȡָ����չ��
    @param [in] index ��չ����Ӧ���±�ֵ
    @return ������չ��������±겻���ڣ��򷵻ؿ�
    */
    RCString GetExt(uint32_t index) const ; 
    
    /** ��ȡָ��������չ��
    @param [in] index ��չ����Ӧ���±�ֵ
    @return ������չ��������±겻���ڣ��򷵻ؿ�
    */
    RCString GetAddExt(uint32_t index) const ; 
    
    /** ��ȡIArchiveInfo�ӿ�
    @return �����ĵ���Ϣ�ӿ�ָ��
    */
    const IArchiveInfoPtr& GetArchiveInfo(void) const ;
    
private:
    
    /** ������չ��Ϊ����
    @param [in] src ��չ��
    @param [out] dest ����������
    */
    void SplitExt(const RCString& src, RCVector<RCString>& dest) ;
    
private:
    
    /** �ĵ���ʽ��Ϣ
    */
    IArchiveInfoPtr m_spArcInfo ;
    
    /** ��չ������
    */
    RCVector<RCArchiveExtInfo> m_arcExts ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveInfoEx_h_
