/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInArchiveUtils_h_
#define __RCInArchiveUtils_h_ 1

#include "base/RCString.h"
#include "filesystem/RCFileDefs.h"
#include "interface/RCPropertyID.h"

BEGIN_NAMESPACE_RCZIP

/** �����ĵ��ӿ�
*/
class IInArchive ;

/** �����ĵ�������
*/
class RCInArchiveUtils
{
public:

    /** ȡ�����ļ�·��
    @param [in] archive �����ĵ�
    @param [in] index ���
    @param [out] result ���ذ����ļ�·��
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemPath(IInArchive* archive, 
                                      uint32_t index, 
                                      RCString& result);
                                      
    /** ȡ�����ļ�·��
    @param [in] archive �����ĵ�
    @param [in] index �����ļ����
    @param [in] defaultName ȱʡ����
    @param [out] result �����ļ�·��
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemPath(IInArchive* archive, 
                                      uint32_t index,
                                      const RCString& defaultName, 
                                      RCString& result);
    
    /** ȡ�����ļ�ʱ��
    @param [in] archive �����ĵ�
    @param [in] index �ļ����
    @param [in] defaultFileTime ȱʡʱ��
    @param [out] fileTime �����ļ�ʱ��
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemFileTime(IInArchive* archive, 
                                          uint32_t index,
                                          const RC_FILE_TIME& defaultFileTime,
                                          RC_FILE_TIME& fileTime);
    
    /** �����ļ��Ƿ���ĳ����
    @param [in] archive �����ĵ�
    @param [in] index ���
    @param [in] propID ���Ա��
    @param [out] result �и�����Ϊtrue,����Ϊfalse
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemProp(IInArchive* archive, 
                                     uint32_t index, 
                                     RCPropertyID propID, 
                                     bool& result);
    
    /** �������Ƿ�ΪĿ¼
    @param [in] archive �����ĵ�
    @param [in] index �����ļ����
    @param [out] result ��Ŀ¼Ϊtrue,����Ϊfalse
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemFolder(IInArchive* archive, 
                                       uint32_t index, 
                                       bool& result);
    
    /** �����ļ��Ƿ���
    @param [in] archive �����ĵ�
    @param [in] index �ļ����
    @param [out] result ��Ϊtrue,����Ϊfalse
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemAnti(IInArchive* archive, 
                                     uint32_t index, 
                                     bool& result);
    
    /** ȡѹ�������ļ�����
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] fileCount �ļ�����
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveFileCount(IInArchive* inArchive, 
                                         uint32_t& fileCount ) ;
                                      
    /** ȡѹ���ļ��ܴ�С
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] unPackSize ѹ���ļ���ѹ���ܴ�С
    @param [out] packSize ѹ���ļ�ѹ�����ܴ�С
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveFileSize(IInArchive* inArchive, 
                                        uint64_t& unPackSize,
                                        uint64_t& packSize ) ;

    /** ȡѹ���ļ�ѹ��ƽ̨
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] hostOS ѹ��ƽ̨
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveHostOS(IInArchive* inArchive, 
                                      RCString& hostOS) ;
    
    /** ȡѹ���ļ�����ע������
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] isCommented ����true��ʾ����ע�ͣ�����û����ע��
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveIsCommented(IInArchive* inArchive, 
                                           bool& isCommented) ;

    /** ȡѹ���ļ�����ע��
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] comment ������ע��
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveComment(IInArchive* inArchive, 
                                       RCString& comment) ;
   
    /** �Ƿ���Ը���ע��
    @param [in] inArchive �����ĵ�
    @return ע�Ϳɸ��·���true,���򷵻�false
    */ 
    static bool GetInArchiveCanUpdateComment(IInArchive* inArchive) ;
    
    /** ȡѹ���ļ�����������
    @param [in] inArchive �����ĵ��ӿ�
    @param [out] isEncrypted ����true��ʾ�����룬����û������
    @return ����ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetInArchiveIsEncrypted(IInArchive* inArchive, 
                                           bool& isEncrypted) ;

    /** �ж��Ƿ����ĵ�����
    @param [in] inArchive �����ĵ��ӿ�
    @param [in] propID ����ID
    @return ���ĵ����Է���true,���򷵻�false
    */
    static bool HasArchiveProperty(IInArchive* inArchive, RCPropertyID propID) ;
};

END_NAMESPACE_RCZIP

#endif //__RCInArchiveUtils_h_
