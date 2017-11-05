/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveCodecs_h_
#define __RCArchiveCodecs_h_ 1

#include "coder/RCCodecsManager.h"
#include "archive/manager/RCArchiveInfoEx.h"
#include "interface/IArchive.h"
#include "common/RCVector.h"
#include "base/RCIntrusivePtr.h"
#include <map>

BEGIN_NAMESPACE_RCZIP

/** �����ĵ���ʽ�ͱ������Ϣ
*/
class RCArchiveCodecs:
    public RCRefCounted
{
public:
    
    /** �ĵ���ʽ����
    */
    typedef std::map<RCArchiveID,RCArchiveInfoEx> TArchiveInfoExMap ;
    
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveCodecs() ;
    
    /** Ĭ����������
    */
    virtual ~RCArchiveCodecs() ;
    
public:
    
    /** �����ļ������Ҷ�Ӧ�Ŀ��Ը��µ��ĵ���Ϣ������·���е���չ��ƥ���ļ���ʽ�е�����չ��
    @param [in] arcPath �ļ���
    @return �����ĵ���ʽID�����ʧ�ܷ��� RC_ARCHIVE_UNKNOWN
    */
    RCArchiveID FindFormatForArchiveName(const RCString& arcPath) const ;
    
    /** �����ļ���չ�����Ҷ�Ӧ���ĵ���Ϣ
    @param [in] ext �ļ���չ��,������"."
    @return �����ĵ���ʽID�����ʧ�ܷ��� RC_ARCHIVE_UNKNOWN
    */
    RCArchiveID FindFormatForExtension(const RCString& ext) const ;
    
    /** �����ĵ��������Ʋ��Ҷ�Ӧ���ĵ���Ϣ
    @param [in] arcType �ĵ���������, ��"7z"�ȣ������ִ�Сд
    @return �����ĵ���ʽID�����ʧ�ܷ��� RC_ARCHIVE_UNKNOWN
    */
    RCArchiveID FindFormatForArchiveType(const RCString& arcType) const ;
    
    /** �����ĵ��������Ʋ��Ҷ�Ӧ���ĵ���Ϣ
    @param [in] arcType �ĵ���������,���Ժ��ж����"."�ָ�, ��"tar.gz"�ȣ������ִ�Сд
    @param [out] formatIndices �����ĵ���ʽID���飬���ʧ�ܷ��� RC_ARCHIVE_UNKNOWN
    @return ����κ�һ���ĵ�����û��ƥ�䣬����false��ȫ��ƥ�䷵��true
    */
    bool FindFormatForArchiveType(const RCString& arcType, RCVector<RCArchiveID>& formatIndices) const;
    
    /** ��ȡ�����������Ϣ
    @return ���ر����������Ϣ�ӿ�ָ��
    */
    ICompressCodecsInfo* GetCompressCodecs(void) const ;
    
    /** ���������ĵ��ӿ�
    @param [in] formatIndex �ĵ���ʽID
    @param [out] archive �����ĵ��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش�����
    */
    HResult CreateInArchive(RCArchiveID formatIndex, IInArchivePtr& archive) const ;
    
    /** ��������ĵ��ӿ�
    @param [in] formatIndex �ĵ���ʽID
    @param [out] archive ����ĵ��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش�����
    */
    HResult CreateOutArchive(RCArchiveID formatIndex, IOutArchivePtr& archive) const ;
    
    /** �����ĵ���ʽ���Ʋ���֧��������ļ���ʽ
    @param [in] name �ĵ���ʽ����,�����ִ�Сд
    @return �ĵ���ʽID
    */
    RCArchiveID FindOutFormatFromName(const RCString& name) const ;
    
    /** ��ȡ�ĵ���Ϣ����
    @param [in] formatIndex �ĵ���ʽID
    @return �����ĵ���Ϣ����, ���ID�����ڣ����ؿյ��ĵ���Ϣ����
    */
    const RCArchiveInfoEx& GetArchiveInfoEx(RCArchiveID formatIndex) const ;
    
    /** �����ĵ���Ϣ��������
    @return ������������
    */
    const TArchiveInfoExMap& GetArchiveInfoExMap(void) const ;
    
protected:
    
    /** �������
    */
    void Clear(void) ;
    
    /** �����µ��ĵ���ʽ
    @return �ɹ�����true,���򷵻�false
    */
    bool AddArchiveInfo(IArchiveInfoPtr spArchiveInfo) ;
       
protected:
    
    /** ѹ������������
    */
    RCCodecsManagerPtr m_spCodecs ;

private:       
    
    /** �ĵ���ʽ��������
    */
    TArchiveInfoExMap m_archiveInfoMap ;
};

/** ����ָ�붨��
*/
typedef RCIntrusivePtr<RCArchiveCodecs> RCArchiveCodecsPtr ;

END_NAMESPACE_RCZIP

#endif //__RCArchiveCodecs_h_
