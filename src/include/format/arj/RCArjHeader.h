/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArjHeader_h_
#define __RCArjHeader_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCVariant.h"
#include "interface/IStream.h"
#include "filesystem/RCFileDefs.h"
#ifdef RCZIP_OS_WIN
#include "base/RCWindowsDefs.h"
#endif

BEGIN_NAMESPACE_RCZIP

class RCArjDefs
{
public:

    static const int32_t kBlockSizeMin = 30;
    static const int32_t kBlockSizeMax = 2600;
   
    static const byte_t kSig0 = 0x60;
    static const byte_t kSig1 = 0xEA;

    /** ѹ������
    */
    enum NCompressionMethod
    {
        kStored = 0,
        kCompressed1a = 1,
        kCompressed1b = 2,
        kCompressed1c = 3,
        kCompressed2 = 4,
        kNoDataNoCRC = 8,
        kNoData = 9
    };

    /** �ļ�����
    */
    enum NFileType
    {
        kBinary = 0,
        k7BitText = 1,
        kArchiveHeader = 2,
        kDirectory = 3,
        kVolumeLablel = 4,
        kChapterLabel = 5
    };

    static const byte_t kGarbled = 1;
    static const byte_t kVolume = 4;
    static const byte_t kExtFile = 8;
    static const byte_t kPathSym = 0x10;
    static const byte_t kBackup = 0x20;

    /** ϵͳƽ̨����
    */
    enum NHostOS
    {
        kMSDOS = 0,
        kPRIMOS,
        kUnix,
        kAMIGA,
        kMac,
        kOS_2,
        kAPPLE_GS,
        kAtari_ST,
        kNext,
        kVAX_VMS,
        kWIN95
    };

    /** ���ַ���
    @param [in] p �ڴ�����
    @param [in] size ���ݴ�С
    @param [out] res �����ַ���
    @return �ɹ�����RC_S_OK�����򷵻�RC_S_FALSE
    */
    static HResult ReadString(const byte_t* p, unsigned& size, RCStringA& res);

    /** �����
    @param [in] p �ڴ�����
    @param [in] maxSize ����ǵ����ƫ��λ��
    @return ͨ����鷵��true�����򷵻�false
    */
    static inline bool TestMarkerCandidate(const byte_t* p, unsigned maxSize);

    /** ���Ҳ���ȡ���
    @param [in] stream ������
    @param [in] searchHeaderSizeLimit ����ͷ�������ƫ��λ��
    @param [out] position ���ƫ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    static HResult FindAndReadMarker(ISequentialInStream* stream, 
                                     const uint64_t* searchHeaderSizeLimit, 
                                     uint64_t& position);
    /** ����ʱ��
    @param [in] dosTime dosʱ��
    @param [out] prop ʱ������
    */
    static void SetTime(uint32_t dosTime, RCVariant& prop);

    /** ����ϵͳƽ̨
    @param [in] hostOS ϵͳƽ̨
    @param [in] prop ƽ̨����
    */
    static void SetHostOS(byte_t hostOS, RCVariant& prop);

    /** ����unicode�ַ���
    @param [in] s ascii�ַ���
    @param [out] prop unicode�ַ�������
    */
    static void SetUnicodeString(const RCStringA& s, RCVariant& prop);
};

struct RCArjArchiveHeader
{
    /** ϵͳ����
    */
    byte_t m_hostOS;

    /** ����ʱ��
    */
    uint32_t m_cTime;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** �ĵ���С
    */
    uint32_t m_archiveSize;

    /** �ļ���
    */
    RCStringA m_name;

    /** ע��
    */
    RCStringA m_comment;

    /** ����
    @param [in] p �ڴ�����
    @param [in] size ���ݴ�С
    */
    HResult Parse(const byte_t* p, unsigned size);
};

END_NAMESPACE_RCZIP

#endif //__RCArjHeader_h_