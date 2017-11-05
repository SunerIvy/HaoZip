/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveOpen_h_
#define __RCArchiveOpen_h_ 1

#include "archive/manager/RCArchiveCodecs.h"
#include "archive/common/RCArchiveLink.h"
#include "base/RCNonCopyable.h"
#include "interface/IStream.h"
#include "interface/RCPropertyID.h"
#include <set>

BEGIN_NAMESPACE_RCZIP

/** ����򿪻ص��ӿ�
*/
class IOpenCallbackUI ;

/** ��ѹ����
*/
class RCArchiveOpen:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveOpen() ;
    
    /** Ĭ����������
    */
    ~RCArchiveOpen() ;
    
public:

    /** ��ѹ����
    @param [in] archiveCodecs �ĵ���ʽ������
    @param [in] formatIndices �ĵ���ʽ���
    @param [in] archiveName �ĵ�����
    @param [out] archiveLink �ĵ�����
    @param [in] openCallbackUI ����򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult OpenArchive(const RCArchiveCodecsPtr& archiveCodecs,
                               const RCVector<RCArchiveID>& formatIndices,
                               const RCString& archiveName,
                               RCArchiveLink& archiveLink,
                               IOpenCallbackUI* openCallbackUI) ;

public:
    
    /** �����ļ�ǩ������ƥ����ܵ��ļ���ʽ
    @param [in] fileName �ļ���
    @param [in] archiveCodecs �ĵ���ʽ������
    @param [out] matchFormatIndices ƥ��ǩ�����ļ���ʽ
    @param [in] inputFormatIndices �ĵ���ʽ��ż���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult FindFormatsBySignature(const RCString& fileName,
                                          RCArchiveCodecsPtr archiveCodecs,
                                          RCIntVector& matchFormatIndices,
                                          const std::set<RCArchiveID>* inputFormatIndices = NULL) ;

#ifndef RC_STATIC_SFX

    /** �Ƿ���RAR��ʽ�ķ־�ѹ��
    @param [in] fileName �ļ���
    @param [in] archiveCodecs ���������
    @param [in,out] result �Ƿ־�ѹ������ture�����򷵻�false
    @return ��rar��ʽ����RC_S_OK�����򷵻ش����
    */
    static HResult RCArchiveOpen::IsRarVolumeType(const RCString& fileName,
                                                  RCArchiveCodecsPtr archiveCodecs,
                                                  bool& result);
#endif
    
public:
    
    /** ���ذ���������
    @param [in] archive �����ĵ�ָ��
    @param [in] index ���������
    @param [in] defaultName ȱʡ����
    @param [out] result ���ذ���������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemPath(IInArchive* archive,
                                      uint32_t index,
                                      const RCString& defaultName,
                                      RCString& result) ;

    /** ���ذ������Ƿ�ΪĿ¼
    @param [in] archive �����ĵ�ָ��
    @param [in] index ���������
    @param [out] result ��Ŀ¼����true,���򷵻�false
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemFolder(IInArchive* archive,
                                       uint32_t index,
                                       bool& result) ;

    /** ���ذ������Ƿ�Ϊ����
    @param [in] archive �����ĵ�ָ��
    @param [in] index ���������
    @param [out] result �Ƿ���true,���򷵻�false
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemAnti(IInArchive* archive,
                                     uint32_t index,
                                     bool& result) ;

    /** ���ذ�����·��
    @param [in] archive �����ĵ�ָ��
    @param [in] index ���������
    @param [out] result ���ذ�����·��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemPathNoDefault(IInArchive* archive,
                                               uint32_t index,
                                               RCString& result) ;

    /** ���ذ�����Ŀ��չ��
    @param [in] archive �����ĵ�ָ��
    @param [in] index ������Ŀ���
    @param [out] result ������չ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetArchiveItemPathExtension(IInArchive* archive,
                                               uint32_t index,
                                               RCString& result) ;

    /** ���ذ�����Ŀ�Ƿ���ĳ����
    @param [in] archive �����ĵ�ָ��
    @param [in] index ���������
    @param [in] propID �������
    @param [out] result ��ĳ���Է���true,���򷵻�false
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult IsArchiveItemProp(IInArchive* archive,
                                     uint32_t index,
                                     RCPropertyID propID,
                                     bool& result) ;
    
private:

    /** ���ĵ�
    @param [in] archiveCodecs �ĵ���ʽ���������
    @param [in] formatIndices �ĵ���ʽ�б�
    @param [in] archiveName �ĵ���
    @param [out] archive0 �����ĵ�1
    @param [out] archive1 �����ĵ�2
    @param [out] defaultItemName0 ȱʡ����1
    @param [out] defaultItemName1 ȱʡ����2
    @param [out] volumePaths ���־�·��
    @param [out] volumesSize �־��С
    @param [in] openCallbackUI ����򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult OpenArchive(const RCArchiveCodecsPtr& archiveCodecs,
                               const RCVector<RCArchiveID>& formatIndices,
                               const RCString& archiveName,
                               IInArchivePtr& archive0,
                               IInArchivePtr& archive1,
                               RCString& defaultItemName0,
                               RCString& defaultItemName1,
                               RCVector<RCString>& volumePaths,
                               uint64_t& volumesSize,
                               IOpenCallbackUI* openCallbackUI) ;

    /** ���ĵ�
    @param [in] archiveCodecs �ĵ���ʽ���������
    @param [in] formatIndices �ĵ���ʽ�б�
    @param [in] fileName �ļ���
    @param [out] archive0 �����ĵ�1
    @param [out] archive1 �����ĵ�2
    @param [out] formatIndex0 �ĵ�1��ʽ���
    @param [out] formatIndex1 �ĵ�2��ʽ���
    @param [out] defaultItemName0 ȱʡ����1
    @param [out] defaultItemName1 ȱʡ����2
    @param [in] archiveOpenCallback �򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult OpenArchive(const RCArchiveCodecsPtr& archiveCodecs,
                               const RCVector<RCArchiveID>& formatIndices,
                               const RCString& fileName,
                               IInArchivePtr& archive0,
                               IInArchivePtr& archive1,
                               int32_t& formatIndex0,
                               int32_t& formatIndex1,
                               RCString& defaultItemName0,
                               RCString& defaultItemName1,
                               IArchiveOpenCallbackPtr archiveOpenCallback) ;

    /** ���ĵ�
    @param [in] archiveCodecs �ĵ���ʽ���������
    @param [in] arcTypeIndex �ĵ���ʽ���
    @param [in] fileName �ļ���
    @param [out] archiveResult �򿪵��ļ�
    @param [out] formatIndex �ĵ���ʽ���
    @param [out] defaultItemName ��ȱʡ����
    @param [in] archiveOpenCallback �򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult OpenArchive(const RCArchiveCodecsPtr& archiveCodecs,
                               int32_t arcTypeIndex,
                               const RCString& fileName,
                               IInArchivePtr& archiveResult,
                               int32_t& formatIndex,
                               RCString& defaultItemName,
                               IArchiveOpenCallbackPtr archiveOpenCallback) ;

    /** ���ĵ�
    @param [in] archiveCodecs �ĵ���ʽ���������
    @param [in] arcTypeIndex ��ʽ���
    @param [in] inStream �����ļ���ָ��
    @param [in] fileName �ļ���
    @param [out] archiveResult �򿪵��ļ�
    @param [out] formatIndex �ĵ���ʽ���
    @param [out] defaultItemName ȱʡ��Ŀ����
    @param [in] archiveOpenCallback �򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult OpenArchive(const RCArchiveCodecsPtr& archiveCodecs,
                               int32_t arcTypeIndex,
                               IInStreamPtr inStream,
                               const RCString& fileName,
                               IInArchivePtr& archiveResult,
                               int32_t& formatIndex,
                               RCString& defaultItemName,
                               IArchiveOpenCallbackPtr archiveOpenCallback) ;

    /** ���ûص�
    @param [in] fileName �ļ�����
    @param [in] openCallbackUI ����򿪻ص��ӿ�ָ��
    @param [in] reArchiveOpenCallback �򿪻ص��ӿ�ָ��
    @param [in] archiveOpenCallback �򿪻ص��ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult SetCallback( const RCString& fileName,
                                IOpenCallbackUI* openCallbackUI,
                                IArchiveOpenCallbackPtr reArchiveOpenCallback,
                                IArchiveOpenCallbackPtr& archiveOpenCallback) ;
        
#ifndef RC_STATIC_SFX

    /** �����ĵ���ʽǩ��
    @param [in] p1 ��ƥ�䴮1
    @param [in] p2 ��ƥ�䴮2
    @param [in] size ��ƥ��ĳ���
    @return p1 p2ƥ��ɹ����� true,���򷵻� false
    */
    static bool TestSignature(const byte_t* p1, const byte_t* p2, size_t size) ;
    
#endif

    /** ����ȱʡ����
    @param [in] name ������
    */
    static void MakeDefaultName(RCString& name) ;
    
    /** �����ļ�ǰ������ƥ����ܵ��ļ���ʽ
    @param [in] inStream ������
    @param [in] archiveCodecs �ĵ���ʽ������
    @param [in] fileExt �ļ���չ��
    @param [out] formatIndices ����ȫ��������չ�����ҵ��ĸ�ʽ������ǩ���ķ���ǰ��
    @param [out] matchFormatIndices ƥ��ǩ�����ļ���ʽ
    @param [in] inputFormatIndices �ĵ���ʽ�б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult FindFormatsBySignature(IInStreamPtr inStream,
                                          RCArchiveCodecsPtr archiveCodecs,
                                          const RCString& fileExt,
                                          RCIntVector& formatIndices,
                                          RCIntVector* matchFormatIndices = NULL,
                                          const std::set<RCArchiveID>* inputFormatIndices = NULL) ;

    /** ��ȡ�ļ�����չ��, ����'.'
    @param [in] fileName �ļ���
    @return �����ļ���չ��,����'.'
    */
    static RCString GetFileExtension(const RCString& fileName) ;
    
private:
    
    /** ǩ��������ƫ����
    */
    static const uint64_t s_maxCheckStartPosition ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveOpen_h_
