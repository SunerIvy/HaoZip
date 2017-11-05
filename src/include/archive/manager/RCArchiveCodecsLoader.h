/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveCodecsLoader_h_
#define __RCArchiveCodecsLoader_h_ 1

#include "archive/manager/RCArchiveManager.h"
#include "archive/manager/RCArchiveCodecs.h"

BEGIN_NAMESPACE_RCZIP

/** �������������
*/
class RCArchiveCodecsLoader:
    public RCArchiveCodecs
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveCodecsLoader() ;
    
    /** Ĭ����������
    */
    ~RCArchiveCodecsLoader() ;
    
public:
    
    /** �Ӷ�̬���ӿ��м���ѹ���㷨���ܽ�����
    @param [in] codecFilePath ��Ҫ���صĶ�̬���ӿ��ļ��б�
    @param [out] errMsg ������ش��󣬷��ش�����Ϣ�������±����ļ���Ӧ�������ϢΪ�ձ�ʾ���سɹ�
    @return ���سɹ����ص��ļ���
    */
    uint32_t LoadCompressCodecs(const RCVector<RCString>& codecFilePath,
                                RCVector<RCString>* errMsg) ;
    
    /** �Ӷ�̬���ӿ��м����ĵ���ʽ��Ϣ
    @param [in] formatFilePath ��Ҫ���صĶ�̬���ӿ��ļ��б�
    @param [out] errMsg ������ش��󣬷��ش�����Ϣ�������±����ļ���Ӧ�������ϢΪ�ձ�ʾ���سɹ�
    @return ���سɹ����ص��ļ���
    */  
    uint32_t LoadArchiveFormats(const RCVector<RCString>& formatFilePath,
                                RCVector<RCString>* errMsg) ;
   
private:
       
    /** �ĵ���ʽ������
    */
    RCArchiveManagerPtr m_spArchive ;
    
    /** ��̬���ӿ�������ݽṹ
    */
    class RCShareLibData ;
    RCShareLibData* m_shareLibData ;
};

/** ����ָ�붨��
*/
typedef RCIntrusivePtr<RCArchiveCodecsLoader> RCArchiveCodecsLoaderPtr ;

END_NAMESPACE_RCZIP

#endif //__RCArchiveCodecsLoader_h_
