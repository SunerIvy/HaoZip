/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveManager_h_
#define __RCArchiveManager_h_ 1

#include "interface/IArchiveInfo.h"
#include "interface/IArchive.h"
#include "interface/IUnknownImpl.h"
#include <vector>

BEGIN_NAMESPACE_RCZIP

/** ���������ĵ��ӿڵĺ������� 
*/
typedef IInArchive * (*CreateInArchiveP)();

/** ��������ĵ��ӿڵĺ������� 
*/
typedef IOutArchive * (*CreateOutArchiveP)();

/** �ĵ���ʽ������ 
*/
class RCArchiveManager:
    public IUnknownImpl<IArchiveCodecsInfo>
{
public:
    
    /** �ĵ���ʽ��������
    */
    typedef std::vector<IArchiveInfoPtr> container_type ;

public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveManager() ;
    
    /** Ĭ����������
    */
    virtual ~RCArchiveManager() ;
   
public:
    
    /** ��ȡ֧�ֵ��ĵ���ʽ����
    @param [out] numFormats �ĵ���ʽ��ʽ
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfFormats(uint32_t& numFormats) const ;
    
    /** ��ȡ�ĵ���Ϣ
    @param [in] index �ĵ���ʽ�±�
    @param [out] spArcInfo �ĵ���ʽ��Ϣ
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult GetFormat(uint32_t index, IArchiveInfoPtr& spArcInfo) const ;
    
    /** ���������ĵ��ӿ�
    @param [in] index �ĵ���ʽ�±�
    @param [out] spInArchive �����ĵ��ӿ�
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult CreateInArchive(uint32_t index, IInArchivePtr& spInArchive) const ;
    
    /** ��������ĵ��ӿ�
    @param [in] index �ĵ���ʽ�±�
    @param [out] spOutArchive ����ĵ��ӿ�
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult CreateOutArchive(uint32_t index, IOutArchivePtr& spOutArchive) const ;

public:
    
    /** ȡ����������
    @return �ĵ���ʽ��������
    */
    const container_type& GetArchiveArray(void) const ;

protected:
    
    /** ע���ĵ���ʽ��Ϣ
    @param [out] spArcInfo �ĵ���ʽ��Ϣ
    @return �ɹ�����true,���򷵻�false
    */    
    bool RegisterArchive(const IArchiveInfoPtr& spArcInfo) ;
    
private:
    
    /** �����������
    */
    container_type m_archiveArray ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCArchiveManager> RCArchiveManagerPtr ;

END_NAMESPACE_RCZIP

#endif //__RCArchiveManager_h_
