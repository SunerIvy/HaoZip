/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "base/RCString.h"
#include "common/RCVector.h"
#include "interface/IArchive.h"
#include "base/RCSmartPtr.h"

#ifndef __RCArchiveLink_h_
#define __RCArchiveLink_h_ 1

BEGIN_NAMESPACE_RCZIP

/** �ĵ�����
*/
class RCArchiveLink
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveLink() ;
    
    /** Ĭ����������
    */
    ~RCArchiveLink() ;

public:

    /** ����ѹ����Ƕ�׼�
    @return ����Ƿ�Ƕ�װ�, ����1,
            Ƕ�װ�,��tar.gz��, ����2
    */
    int32_t GetNumLevels() const ;

    /** ��ȡĬ�ϵ�Archive
    @return ����Ĭ������Archiveָ��
    */
    IInArchive* GetArchive() const ;
    
    /** ��ȡ��1����Archive
    @return ���ص�1������Archiveָ��
    */
    IInArchivePtr GetArchive0() const ;
    
    /** ��ȡ��2����Archive
    @return ���ص�2������Archiveָ��
    */
    IInArchivePtr GetArchive1() const ;

    /** ��ȡĬ�ϵ�ѹ���ļ���
    @return ����Ĭ��ѹ���ļ���
    */
    RCString GetDefaultItemName() const ;

    /** ��ȡ�ļ���ʽFormat Index
    @return ����ѹ���ļ���ʽ���
    */
    int32_t GetArchiverIndex() const ;
    
    /** ��ȡ��ǰѹ���ļ��ĸ�ʽ��Ϣ
    @return ���ص�ǰѹ���ļ���ʽ��Ϣ
    */
    RCString GetArchiveTypeString() const ;

    /** �رմ򿪵��ĵ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Close() ;

    /** �ͷ���Դ
    */
    void Release() ;

public:

    /** ��1��ѹ���ļ�����
    */
    IInArchivePtr m_archive0;
    
    /** Ƕ�׵ĵ�2��ѹ���ļ�����
    */
    IInArchivePtr m_archive1;

    /** ��1��ѹ���ļ�Ĭ������
    */
    RCString m_defaultItemName0;
    
    /** ��2��ѹ���ļ�Ĭ������
    */
    RCString m_defaultItemName1;

    /** ��1��ѹ���ļ���ʽFormat Index
    */
    int32_t m_formatIndex0;
    
    /** ��2��ѹ���ļ���ʽFormat Index
    */
    int32_t m_formatIndex1;

    /** ѹ���ļ�������·��
    */
    RCVector<RCString> m_volumePaths;

    /** �Ƿ��Ѿ���
    */
    bool m_isOpen ;
    
    /** ѹ���ļ����С
    */
    uint64_t m_volumesSize;
};

/** ����ָ�붨��
*/
typedef RCSharedPtr<RCArchiveLink> RCArchiveLinkPtr ;

END_NAMESPACE_RCZIP

#endif //__RCArchiveLink_h_
