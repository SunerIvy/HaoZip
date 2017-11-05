/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zItem_h_
#define __RC7zItem_h_ 1

#include "format/7z/RC7zDefs.h"
#include "common/RCVector.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

struct RC7zCoderInfo
{
    /** ģʽID
    */
    RCMethodID m_methodID;

    /** ����
    */
    RCByteBuffer m_properties;

    /** ����������
    */
    RC7zNum m_numInStreams;

    /** ���������
    */
    RC7zNum m_numOutStreams;

    /** �Ƿ��Ǽ򵥱���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSimpleCoder() const ;    
};

struct RC7zBindPair
{
    /** ��������
    */
    RC7zNum m_inIndex ;

    /** �������
    */
    RC7zNum m_outIndex ;
};

struct RC7zFolder
{
    /** ������
    */
    RCVector<RC7zCoderInfo> m_coders;

    /** ����Ϣ
    */
    RCVector<RC7zBindPair> m_bindPairs;

    /** ������
    */
    RCVector<RC7zNum> m_packStreams;

    /** ��ѹ���С
    */
    RCVector<uint64_t> m_unpackSizes;

    /** ��ѹCRC
    */
    uint32_t m_unpackCRC;

    /** �Ƿ��н�ѹCRC
    */
    bool m_unpackCRCDefined;

    /** Ĭ�Ϲ��캯��
    */
    RC7zFolder() ;

    /** ��ȡ��ѹ��Ĵ�С
    @throws ʧ�����쳣
    @return ��ѹ���С
    */
    uint64_t GetUnpackSize() const  ;

    /** ��ȡ�����
    @return �����
    */
    RC7zNum GetNumOutStreams() const ;

    /** ���������в��Ұ���Ϣ
    @param [in] inStreamIndex ������������
    @return �ɹ�������BindPair���������򷵻�-1
    */
    int32_t FindBindPairForInStream(RC7zNum inStreamIndex) const ; 

    /** ��������в��Ұ���Ϣ
    @param [in] outStreamIndex �����������
    @return �ɹ�������BindPair���������򷵻�-1
    */
    int32_t FindBindPairForOutStream(RC7zNum outStreamIndex) const ;

    /** �����б��в��Ұ���Ϣ
    @param [in] inStreamIndex ��������
    @return �ɹ�������BindPair���������򷵻�-1
    */
    int32_t FindPackStreamArrayIndex(RC7zNum inStreamIndex) const ;

    /** ���ṹ
    @return ͨ����鷵��true�����򷵻�false
    */
    bool CheckStructure() const;
};

struct RC7zUInt64DefVector
{
    /** ֵ
    */
    RCVector<uint64_t> m_values;

    /** �Ƿ���
    */
    RCVector<bool> m_defined;

    /** ���
    */
    void Clear() ;

    /** ����
    */
    void ReserveDown() ;

    /** ��ȡ�� 
    @param [in] index ����
    @param [out] value ��
    @return �ɹ�����true�����򷵻�false
    */
    bool GetItem(int32_t index, uint64_t& value) const ;

    /** ������
    @param [in] index ����
    @param [in] defined �Ƿ���
    @param [in] value ��ֵ
    */
    void SetItem(int32_t index, bool defined, uint64_t value) ;

    /** ����С
    @param [in] size ��С
    @return ͨ����鷵��true�����򷵻�false
    */
    bool CheckSize(int32_t size) const ;
};

struct RC7zFileItem
{
    /** ��С
    */
    uint64_t m_size;

    /** ����
    */
    uint32_t m_attrib;

    /** crc
    */
    uint32_t m_crc;

    /** ����
    */
    RCString m_name;

    /** �Ƿ�����(Test it !!! it means that there is)
    */
    bool m_hasStream; 

    /** �Ƿ���·��(stream in some folder. It can be empty stream)
    */
    bool m_isDir;

    /** �Ƿ�����CRC
    */
    bool m_crcDefined;

    /** �Ƿ�������
    */
    bool m_attribDefined;

    /** Ĭ�Ϲ��캯��
    */
    RC7zFileItem() ;

    /** ��������
    @param [in] attrib ����
    */
    void SetAttrib(uint32_t attrib) ;
};

struct RC7zFileItem2
{
    /** ����ʱ��
    */
    uint64_t m_cTime;

    /** ����ʱ��
    */
    uint64_t m_aTime;

    /** �޸�ʱ��
    */
    uint64_t m_mTime;

    /** ��ʼƫ��
    */
    uint64_t m_startPos;

    /** �Ƿ��д���ʱ��
    */
    bool m_cTimeDefined;

    /** �Ƿ��з���ʱ��
    */
    bool m_aTimeDefined;

    /** �Ƿ����޸�ʱ��
    */
    bool m_mTimeDefined;

    /** �Ƿ�����ʼƫ��
    */
    bool m_startPosDefined;

    /** �Ƿ���anti
    */
    bool m_isAnti;
};

/** RC7zFileItem����ָ��
*/
typedef RCSharedPtr<RC7zFileItem>  RC7zFileItemPtr ;

/** RC7zFileItem2����ָ��
*/
typedef RCSharedPtr<RC7zFileItem2>  RC7zFileItem2Ptr ;

struct RC7zArchiveDatabase
{
    /** ���Ĵ�С
    */
    RCVector<uint64_t> m_packSizes;

    /** �Ƿ�����crc
    */
    RCVector<bool> m_packCRCsDefined;

    /** crc
    */
    RCVector<uint32_t> m_packCRCs;

    /** �ļ���
    */
    RCVector<RC7zFolder> m_folders;

    /** ��ѹ���ĸ���
    */
    RCVector<RC7zNum> m_numUnpackStreamsVector;

    /** �ļ�
    */
    RCVector<RC7zFileItemPtr> m_files;

    /** ����ʱ��
    */
    RC7zUInt64DefVector m_cTime;

    /** ����ʱ��
    */
    RC7zUInt64DefVector m_aTime;

    /** ����ʱ��
    */
    RC7zUInt64DefVector m_mTime;

    /** �Ƿ�ƫ��
    */
    RC7zUInt64DefVector m_startPos;

    /** �Ƿ���anti
    */
    RCVector<bool> m_isAnti;

    /** ע����ʼλ��
    */
    uint64_t m_commentStartPos;

    /** �Ƿ���ע��
    */
    bool m_isCommented;

    /** ע����Ϣ
    */
    RCString m_comment;

    /** Ĭ�Ϲ��캯��
    */
    RC7zArchiveDatabase() :
        m_commentStartPos(0),
        m_isCommented(false)
    {}

    /** ���
    */
    void Clear() ;

    /** ����
    */
    void ReserveDown() ;

    /** �Ƿ��ǿ�
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEmpty() const ;

    /** ����ļ�����
    @return ͨ����鷵��true�����򷵻�false
    */
    bool CheckNumFiles() const ;

    /** �Ƿ��ǹ�ʵѹ��
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSolid() const ;    

    /** �Ƿ���anti
    @param [in] index ����
    @return �Ƿ���true�����򷵻�false
    */
    bool IsItemAnti(int32_t index) const ;

    /** �������anti
    @param [in] index ����
    @param [in] isAnti �Ƿ�anti
    */
    void SetItemAnti(int32_t index, bool isAnti) ;

    /** ��ȡ�ļ���Ϣ
    @param [in] index ����
    @param [out] file �ļ���Ϣ
    @param [out] file2 �ļ���Ϣ
    */
    void GetFile(int32_t index, RC7zFileItemPtr& file, RC7zFileItem2Ptr& file2) const;

    /** ����ļ�
    @param [in] file �ļ���Ϣ
    @param [in] file2 �ļ���Ϣ
    */
    void AddFile(const RC7zFileItemPtr& file, const RC7zFileItem2Ptr& file2);
};

END_NAMESPACE_RCZIP

#endif //__RC7zItem_h_
