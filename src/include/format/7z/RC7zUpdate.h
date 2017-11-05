/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zUpdate_h_
#define __RC7zUpdate_h_ 1

#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "format/7z/RC7zCompressionMode.h"
#include "format/7z/RC7zOutArchive.h"
#include "format/7z/RC7zArchiveDatabaseEx.h"
#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "common/RCBuffer.h"
#include "format/7z/RC7zItem.h"

BEGIN_NAMESPACE_RCZIP

struct RC7zUpdateItem
{
    /** ���ĵ��е�����
    */
    int32_t m_indexInArchive;

    /** ��clinet�е�����
    */
    int32_t m_indexInClient;

    /** ����ʱ��
    */
    uint64_t m_cTime;

    /** ����ʱ�䰴
    */
    uint64_t m_aTime;

    /** �޸�ʱ��
    */
    uint64_t m_mTime;

    /** ��С
    */
    uint64_t m_size;

    /** ����
    */
    RCString m_name;

    /** ����
    */
    uint32_t m_attrib;

    /** �Ƿ���������
    */
    bool m_newData;

    /** �Ƿ���������
    */
    bool m_newProperties;

    /** �Ƿ���anti
    */
    bool m_isAnti;

    /** �Ƿ���Ŀ¼
    */
    bool m_isDir;

    /** �Ƿ�������
    */
    bool m_attribDefined;

    /** �Ƿ��д���ʱ��
    */
    bool m_cTimeDefined;

    /** �Ƿ��з���ʱ��
    */
    bool m_aTimeDefined;

    /** �Ƿ����޸�ʱ��
    */
    bool m_mTimeDefined;

public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zUpdateItem() ;

public:

    /** �Ƿ�����
    */
    bool HasStream() const ;

    /** ������������·��״̬
    */
    void SetDirStatusFromAttrib() ;

    /** ��ȡ��չƫ��
    */
    int32_t GetExtensionPos() const;

    /** ��ȡ��չ��Ϣ
    */
    RCString GetExtension() const;
};

/** RC7zUpdateItem����ָ��
*/
typedef RCSharedPtr<RC7zUpdateItem> RC7zUpdateItemPtr ;

struct RC7zUpdateOptions
{
    /** ģʽ
    */
    const RC7zCompressionMethodMode* m_method;

    /** ������ 
    */
    const RC7zCompressionMethodMode* m_headerMethod;

    /** �Ƿ��ù���
    */
    bool m_useFilters;

    /** �Ƿ�������
    */
    bool m_maxFilter;

    /** ͷ����
    */
    RC7zHeaderOptions m_headerOptions;

    /** ��ʵ�ļ���
    */
    uint64_t m_numSolidFiles;

    /** ��ʵ�ֽ���
    */
    uint64_t m_numSolidBytes;

    /** �Ƿ��й�ʵ��չ
    */
    bool m_solidExtension;

    /** �Ƿ��Ƴ��Խ�ѹģ��
    */
    bool m_removeSfxBlock;

    /** �Ƿ��Ƿ־�ģʽ
    */
    bool m_volumeMode;
};

struct RC7zFolderRepack
{
    /** �ļ���������
    */
    int32_t m_folderIndex;

    /** ��������
    */
    int32_t m_group;

    /** �������ļ�
    */
    RC7zNum m_numCopyFiles;
};

class RC7zUpdate
{
public:

    /** ����
    @param [in] codecsInfo ���������
    @param [in] inStream ������
    @param [in] db ��������
    @param [in] updateItems ������
    @param [in] archive ����ĵ�
    @param [in] newDatabase �»�������
    @param [in] seqOutStream �����
    @param [in] updateCallback �ĵ����¹������ص��ӿ�
    @param [in] options ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult Update(ICompressCodecsInfo* codecsInfo,
                          IInStream* inStream,
                          const RC7zArchiveDatabaseEx* db,
                          const RCVector<RC7zUpdateItemPtr>& updateItems,
                          RC7zOutArchive& archive,
                          RC7zArchiveDatabase& newDatabase,
                          ISequentialOutStream* seqOutStream,
                          IArchiveUpdateCallback* updateCallback,
                          const RC7zUpdateOptions& options) ;

private:

    /** д��Χ
    @param [in] codecsInfo ���������
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] position ƫ��λ��
    @param [in] size ��С
    @param [in] progress ѹ�����ȹ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult WriteRange(ICompressCodecsInfo* codecsInfo,
                              IInStream* inStream, 
                              ISequentialOutStream* outStream,
                              uint64_t position, 
                              uint64_t size, 
                              ICompressProgressInfo* progress) ;

    /** �Ƚ��ڴ�
    @param [in] a1 �ڴ�һ
    @param [in] a2 �ڴ��
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareBuffers(const RCByteBuffer& a1, const RCByteBuffer& a2) ;

    /** �Ƚϱ���
    @param [in] c1 ����һ
    @param [in] c2 �����
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareCoders(const RC7zCoderInfo& c1, const RC7zCoderInfo& c2) ;

    /** �Ƚϰ������Ϣ
    @param [in] b1 �������Ϣһ
    @param [in] b2 �������Ϣ��
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareBindPairs(const RC7zBindPair& b1, const RC7zBindPair& b2) ;

    /** �Ƚ��ļ���
    @param [in] f1 �ļ���һ
    @param [in] f2 �ļ��ж�
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareFolders(const RC7zFolder& f1, const RC7zFolder& f2) ;

    /** �ȽϿ���
    @param [in] p1 ��ֵһ
    @param [in] p2 ��ֵ��
    @param [in] param ����
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareEmptyItems(const int32_t* p1, const int32_t* p2, void* param) ;
 
    /** �Ƚ��ļ���
    @param [in] p1 �ļ���һ
    @param [in] p2 �ļ��ж�
    @param [in] param ����
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t CompareFolderRepacks(const RC7zFolderRepack* p1, const RC7zFolderRepack* p2, void* param) ;

    /** �Ӹ�����ļ���
    @param [in] ui ������
    @param [in] file �ļ���
    @param [in] file2 �ļ���
    */
    static void FromUpdateItemToFileItem(const RC7zUpdateItemPtr& ui, 
                                         RC7zFileItemPtr& file, 
                                         RC7zFileItem2Ptr& file2) ;

    /** ��ȡ��չ����
    @param [in] ext ��չ
    @return ��������
    */
    static int32_t GetExtIndex(const char* ext) ;

    /** �Ƚ��ַ���
    @param [in] s1 �ַ���һ
    @param [in] s2 �ַ�����
    @return ��ȷ���0�����򷵻�����
    */
    static int32_t MyStringCompareNoCase(const RCString::value_type* s1, const RCString::value_type* s2) ;

    struct RC7zRefItem ;

    class RC7zSolidGroup ;

    /** �Ƚϸ�����
    @param [in] p1 �������
    @param [in] p2 �������
    @param [in] param ����
    */
    static int32_t CompareUpdateItems(const RC7zRefItem* p1, const RC7zRefItem* p2, void* param) ;

    /** �Ƿ���exe�ļ�
    */
    static bool IsExeFile(const RCString& ext) ;

    /** ��ȡģʽ����
    @param [in] methodID ģʽid
    @param [in] numInStreams �������ĸ���
    @param [out] methodResult ���ģʽ����
    @return ����true
    */
    static bool GetMethodFull(uint64_t methodID,
                              uint32_t numInStreams, 
                              RC7zArchiveMethodFull& methodResult) ; 

    /** ����exe��ģʽ����
    @param [in] method ģʽ����
    @param [in] bcj2Filter �Ƿ���bcj filter
    @param [out] exeMethod ���ģʽ����
    @return �ɹ�����true�����򷵻�false
    */
    static bool MakeExeMethod(const RC7zCompressionMethodMode& method,
                              bool bcj2Filter, 
                              RC7zCompressionMethodMode& exeMethod) ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zUpdate_h_
