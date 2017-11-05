/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCHfsIn_h_
#define __RCHfsIn_h_ 1

#include "base/RCString.h"
#include "common/RCVector.h"
#include "interface/IStream.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

struct RCHfsExtent
{
    /** ƫ��λ��
    */
    uint32_t m_pos ;

    /** ��ĸ���
    */
    uint32_t m_numBlocks ;
};

struct RCHfsFork
{
    /** ��С
    */
    uint64_t m_size;

    /** ��ĸ���
    */
    uint32_t m_numBlocks;

    /** ��չ��Ϣ
    */
    RCHfsExtent m_extents[8];

    /** ����
    @param [in] p �ڴ�����
    */
    void Parse(const byte_t* p) ;
};

struct RCHfsVolHeader
{
    /** ͷ��
    */
    byte_t m_header[2];

    /** �汾
    */
    uint16_t m_version;

    /** ����ʱ��
    */
    uint32_t m_cTime;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** �����־��С
    */
    int32_t m_blockSizeLog;

    /** ��ĸ���
    */
    uint32_t m_numBlocks;

    /** ���п�ĸ���
    */
    uint32_t m_numFreeBlocks;

    /** �Ƿ�����չ�ļ�
    */
    RCHfsFork m_extentsFile;

    /** �Ƿ�����־�ļ�
    */
    RCHfsFork m_catalogFile;

    /** �Ƿ���hfsx
    @return �Ƿ���true�����򷵻�false
    */
    bool IsHfsX() const ;
};

enum ERecordType
{
    RECORD_TYPE_FOLDER = 1,
    RECORD_TYPE_FILE   = 2,
    RECORD_TYPE_FOLDER_THREAD = 3,
    RECORD_TYPE_FILE_THREAD = 4
};

struct RCHfsItem
{
    /** ����
    */
    RCString m_name;

    /** ��ID
    */
    uint32_t m_parentID;

    /** ����
    */
    uint16_t m_type;

    /** ID
    */
    uint32_t m_id;

    /** ����ʱ��
    */
    uint32_t m_cTime;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** ����ʱ��
    */
    uint32_t m_aTime;

    /** ��С
    */
    uint64_t m_size;

    /** ��ĸ���
    */
    uint32_t m_numBlocks;

    /** ��չ��Ϣ
    */
    RCVector<RCHfsExtent> m_extents ;

    /** Ĭ�Ϲ��캯��
    */
    RCHfsItem() ;

    /** �Ƿ���Ŀ¼
    @return ��Ŀ¼����true�����򷵻�false
    */
    bool IsDir() const ;
};

struct RCHfsIdIndexPair
{
    /** ID
    */
    uint32_t m_id ;

    /** ����
    */
    int32_t m_index ;
};

struct RCHfsProgressVirt
{
    /** ������
    @param [in] numFiles �ܵ��ļ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetTotal(uint64_t numFiles) = 0 ;

    /** �������
    @param [in] numFiles �Ѿ���ɵ��ļ�����
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetCompleted(uint64_t numFiles) = 0 ;
};

class RCHfsDatabase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCHfsDatabase() ;

    /** Ĭ����������
    */
    ~RCHfsDatabase() ;

public:

    /** ���
    */
    void Clear() ;

    /** ��ȡ·��
    @param [in] index item����
    @return ����·��
    */
    RCString GetItemPath(int32_t index) const ;

    /** ���ĵ�
    @param [in] inStream ������
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Open(IInStream* inStream, RCHfsProgressVirt* progress) ; 
    
public:

    /** ͷ����Ϣ
    */
    RCHfsVolHeader m_header ;

    /** hfs����Ϣ
    */
    RCVector<RCHfsItem> m_items ;

private:

    /** ��ȡ��չ�ļ���Ϣ
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult LoadExtentFile(IInStream* inStream) ;

    /** ��ȡ��־��Ϣ
    @param [in] inStream ������
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult LoadCatalog(IInStream* inStream, RCHfsProgressVirt* progress) ; 

    /** ��ȡ�ļ�
    @param [in] fork fork��Ϣ
    @param [out] buf ���ض�ȡ������
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadFile(const RCHfsFork& fork, RCByteBuffer& buf, IInStream* inStream) ;
       
private:

    /** ID��������MAP 
    */
    RCVector<RCHfsIdIndexPair> m_idToIndexMap ;
};

END_NAMESPACE_RCZIP

#endif //__RCHfsIn_h_
