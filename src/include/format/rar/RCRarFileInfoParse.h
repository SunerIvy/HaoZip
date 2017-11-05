/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRarFileInfoParse_h_
#define __RCRarFileInfoParse_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "RCRarVolumeInStream.h"
#include "common/RCSystemUtils.h"

BEGIN_NAMESPACE_RCZIP

const unsigned int SALT_SIZE              = 8;
const unsigned int SIZEOF_MARKHEAD        = 7;
const unsigned int SIZEOF_OLDMHD          = 7;
const unsigned int SIZEOF_NEWMHD          = 13;
const unsigned int SIZEOF_OLDLHD          = 21;
const unsigned int SIZEOF_NEWLHD          = 32;
const unsigned int SIZEOF_SHORTBLOCKHEAD  = 7;
const unsigned int SIZEOF_LONGBLOCKHEAD   = 11;
const unsigned int SIZEOF_SUBBLOCKHEAD    = 14;
const unsigned int SIZEOF_COMMHEAD        = 13;
const unsigned int SIZEOF_PROTECTHEAD     = 26;
const unsigned int SIZEOF_AVHEAD          = 14;
const unsigned int SIZEOF_SIGNHEAD        = 15;
const unsigned int SIZEOF_UOHEAD          = 18;
const unsigned int SIZEOF_MACHEAD         = 22;
const unsigned int SIZEOF_EAHEAD          = 24;
const unsigned int SIZEOF_BEEAHEAD        = 24;
const unsigned int SIZEOF_STREAMHEAD      = 26;

enum 
{
    MARK_HEAD=0x72,MAIN_HEAD=0x73,FILE_HEAD=0x74,COMM_HEAD=0x75,AV_HEAD=0x76,
    SUB_HEAD=0x77,PROTECT_HEAD=0x78,SIGN_HEAD=0x79,NEWSUB_HEAD=0x7a,
    ENDARC_HEAD=0x7b
};

/** RAR�ļ���Ϣ����������������ͷ����ַ��ΪRAR�ļ���ַ�������ļ��ڲ�����RAR���ͷ��
*/
class RCRarFileInfoParse
{
public:

    /** ���캯��
    @param [in] stream ������
    */
    RCRarFileInfoParse(IInStream* stream) : m_stream(0)
    {
        if (!stream)
        {
            return;
        }

        uint64_t SFXSize = 0;
        if (stream->Seek(0, RC_STREAM_SEEK_CUR, &SFXSize) != RC_S_OK)
        {
            return;
        }

        m_sfxSize = SFXSize;

        m_stream = stream;
    }

    /** Ĭ����������
    */
    ~RCRarFileInfoParse()
    {
        if (!m_stream)
        {
            return;
        }

        uint64_t position = 0;
        if (m_stream->Seek(m_sfxSize, RC_STREAM_SEEK_SET, &position) != RC_S_OK)
        {
            return;
        }
    }

    /** ͷ����Ϣ
    */
    class RCMarkHeader
    {
    public:

        /** ͷ����Ϣ
        */
        unsigned char Data[SIZEOF_MARKHEAD];

        /** �ļ���ǩ�Ƿ���ȷ
        @return �Ƿ���true�����򷵻�false
        */
        bool IsSignature();

        /** �Ƿ��Ǿɰ汾
        @return �Ƿ���true�����򷵻�false
        */
        bool IsOldFormat();

    }m_markHeader;

    /** ��ͷ����Ϣ
    */
    struct RCBlockHeader
    {
    public:

        /** ͷ����Ϣ
        */
        unsigned char Data[SIZEOF_SHORTBLOCKHEAD];

        /** �Ƿ����ӿ�
        @return �Ƿ���true�����򷵻�false
        */
        bool IsSubBlock();

        /** ��CRC
        @return ����crc
        */
        unsigned short HeadCRC();

        /** ������
        @return ��������
        */
        unsigned char HeadType();

        /** ����
        @return ���ط��
        */
        unsigned short Flags();

        /** ���ÿ���
        @param [in] flags ���
        */
        void SetFlags(unsigned short flags);

        /** ��ͷ����С
        @return ���ش�С
        */
        unsigned short HeadSize();

        /** ����ͷ����С
        @param [in] size ��С
        */
        void SetHeadSize(unsigned short size);

        /** �Ƿ��ӿ�
        @return �Ƿ���true�����򷵻�false
        */
        bool SubBlock();
    };

    /** Main��ͷ����Ϣ
    */
    struct RCMainHeader : public RCBlockHeader
    {
    public:

        /** ͷ����Ϣ
        @param [in] data ����
        @param [in] size ��С
        @return �ɹ�����true�����򷵻�false
        */
        bool ReadFrom(unsigned char* data, uint64_t size) ;

        /** �Ƿ����
        @return �Ƿ���true�����򷵻�false
        */
        bool IsEncrypted();

        /** �Ƿ�־�
        @return �Ƿ���true�����򷵻�false
        */
        bool IsVolume();

        /** �Ƿ��ǵ�һ����
        @return �Ƿ���true�����򷵻�false
        */
        bool IsFirstVolume();

        /** �Ƿ��ʼ
        @return �Ƿ���true�����򷵻�false
        */
        bool IsSolid();

        /** �Ƿ���Main�鱣��ע��
        @return �Ƿ���true�����򷵻�false
        */
        bool IsMainComment();

        /** �Ƿ�����
        @return �Ƿ���true�����򷵻�false
        */
        bool IsLocked();

        /** �Ƿ���
        @return �Ƿ���true�����򷵻�false
        */
        bool IsSigned();

        /** �Ƿ񱣻�
        @return �Ƿ���true�����򷵻�false
        */
        bool IsProtected();

        /** ���ܰ汾
        @return �Ƿ���true�����򷵻�false
        */
        unsigned short m_encryptVer;

        /** posAV�ĸ�λ
        */
        unsigned short m_highPosAV;

        /** posAV
        */
        unsigned short m_posAV;

    }m_mainHeader;

    /** End��ͷ����Ϣ
    */
    struct RCEndHeader : public RCBlockHeader
    {
    public:

        /** ͷ����Ϣ
        @param [in] data ����
        @param [in] size ��С
        @return �ɹ�����true�����򷵻�false
        */
        bool ReadFrom(unsigned char* data, uint64_t size) ;

        /** �Ƿ�����һ���־�
        @return �Ƿ���true�����򷵻�false
        */
        bool IsLastVolume();

        /** ѹ����CRC32У��
        */
        uint32_t m_arcDataCRC;

        /** ��ǰ�־����
        */
        unsigned short m_volNumber;

    }m_endHeader;

    /** Protect��ͷ����Ϣ
    */
    struct RCProtectHeader
    {
    public:

        /** ͷ����Ϣ
        @param [in] data ����
        @param [in] size ��С
        @return �ɹ�����true�����򷵻�false
        */
        bool ReadFrom(unsigned char* data, uint64_t size) ;

        /** ���ݴ�С
        */
        uint32_t m_dataSize;

        /** ����
        unsigned char m_version;
        unsigned short m_recSectors;
        uint32_t m_totalBlocks;
        unsigned char m_mark[8];
        */
    };


    /** Sub��ͷ����Ϣ
    */
    struct RCSubHeader
    {
    public:

        /** ͷ����Ϣ
        @param [in] data ����
        @param [in] size ��С
        @return �ɹ�����true�����򷵻�false
        */
        bool ReadFrom(unsigned char* data, uint64_t size) ;

        /** ���ݴ�С
        */
        uint32_t m_dataSize;

        /** ����
        unsigned short m_subType;
        unsigned char m_level;
        */
    };

    /** File��ͷ����Ϣ
    */
    struct RCFileHeader : public RCBlockHeader
    {
    public:

        /** ͷ����Ϣ
        @param [in] data ����
        @param [in] size ��С
        @return �ɹ�����true�����򷵻�false
        */
        bool ReadFrom(unsigned char* data, uint64_t size) ;

        /** ����С(��λ)
        */
        uint32_t m_packSize;

        /** ��ѹ���С(��λ)
        */
        uint32_t m_unpSize;

        /** ƽ̨����
        */
        unsigned char HostOS;

        /** crc
        */
        uint32_t m_fileCRC;

        /** �ļ�ʱ��
        */
        uint32_t m_fileTime;

        /** ��ѹ�汾
        */
        unsigned char m_unpVer;

        /** ����
        */
        unsigned char m_method;

        /** ���ִ�С
        */
        unsigned short m_nameSize;

        union 
        {
            /** �ļ�����
            */
            uint32_t m_fileAttr;

            /** �ӷ��
            */
            uint32_t m_subFlags;
        };

        /** ����С(��λ)
        */
        uint32_t m_highPackSize;

        /** ��ѹ���С(��λ)
        */
        uint32_t m_highUnpSize;
    
        /** ����
        char m_fileName[NM];
        wchar m_fileNameW[NM];
        Array<byte> m_subData;
        byte m_salt[SALT_SIZE];
        RarTime m_mTime;
        RarTime m_cTime;
        RarTime m_aTime;
        RarTime m_arcTime;
        */
    };

    /** ���ļ�����ȡ�ļ���Ϣ
    @return �ɹ�����true�����򷵻�false
    */
    bool ReadInfoFromStream();

private:

    /** ������
    */
    IInStream* m_stream;

    /** ����������ʼ��ַ
    */
    uint64_t m_sfxSize;

    /** ��ȡ��ͷ��
    @param [out] BlockType ������
    @param [out] CurBlockPos ��ǰ��ͷ����λ��
    @param [out] NextBlockPos ��һ����ͷ����λ��
    @return ���ؿ�ͷ����С
    */
    uint64_t ReadHeader(unsigned char& BlockType, uint64_t &CurBlockPos, uint64_t& NextBlockPos);

    /** ��ȡ�ϵ�ͷ��
    @param [out] BlockType ������
    @param [out] CurBlockPos ��ǰ��ͷ����λ��
    @param [out] NextBlockPos ��һ����ͷ����λ��
    @return ���ؿ�ͷ����С
    */
    uint64_t ReadOldHeader(unsigned char& BlockType, uint64_t CurBlockPos, uint64_t& NextBlockPos);

    /** ��ȡ�µ�ͷ��
    @param [out] BlockType ������
    @param [out] CurBlockPos ��ǰ��ͷ����λ��
    @param [out] NextBlockPos ��һ����ͷ����λ��
    @return ���ؿ�ͷ����С
    */
    uint64_t ReadNewHeader(unsigned char& BlockType, uint64_t CurBlockPos, uint64_t& NextBlockPos);

    /** ������
    @param [in] BlockType ������
    @return ����λ��
    */
    uint64_t SearchBlock(unsigned char BlockType);

    /** ��ȡ��ǰλ��
    @return ���ص�ǰλ��
    */
    uint64_t Tell();

    /** ��ȡ����
    @param [in] data ��ַ
    @param [in] size ��С
    @return �ɹ�����true�����򷵻�false
    */
    bool Read(void* data, size_t size);
};

END_NAMESPACE_RCZIP

#endif //RCRarFileInfoParse_h_
