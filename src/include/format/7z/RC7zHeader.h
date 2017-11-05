/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zHeader_h_
#define __RC7zHeader_h_ 1

#include "base/RCDefs.h"

//#define _7Z_VOL

BEGIN_NAMESPACE_RCZIP

class RC7zHeader
{
public:

    static const int32_t s_k7zSignatureSize = 6;
    static byte_t s_k7zSignature[s_k7zSignatureSize];

    // #define _7Z_VOL
    // 7z-MultiVolume is not finished yet.
    // It can work already, but I still do not like some
    // things of that new multivolume format.
    // So please keep it commented.
    
    static const byte_t s_k7zMajorVersion = 0;
    static const uint32_t s_k7zStartHeaderSize = 20;

#ifdef _7Z_VOL
    static byte_t s_k7zFinishSignature[s_k7zSignatureSize];
    static const uint32_t s_k7zFinishHeaderSize = s_k7zStartHeaderSize + 16;
#endif
    
};

struct RC7zArchiveVersion
{
    /** ���汾��
    */
    byte_t m_major ;

    /** �Ӱ汾��
    */
    byte_t m_minor ;
};

struct RC7zStartHeader
{
    /** ��һ��ͷ��ƫ��
    */
    uint64_t m_nextHeaderOffset;

    /** ��һ��ͷ�Ĵ�С
    */
    uint64_t m_nextHeaderSize;

    /** ��һ��ͷ��crc
    */
    uint32_t m_nextHeaderCRC;
};

#ifdef _7Z_VOL

struct RC7zFinishHeader: 
    public RC7zStartHeader
{
    uint64_t m_archiveStartOffset;       // data offset from end if that struct

    uint64_t m_additionalStartBlockSize; // start  signature & start header size
};

#endif

class RC7zID
{
public:
    enum Enum
    {
        kEnd,
        kHeader,
        kArchiveProperties,    
        kAdditionalStreamsInfo,
        kMainStreamsInfo,
        kFilesInfo,    
        kPackInfo,
        kUnpackInfo,
        kSubStreamsInfo,
        kSize,
        kCRC,
        kFolder,
        kCodersUnpackSize,
        kNumUnpackStream,
        kEmptyStream,
        kEmptyFile,
        kAnti,
        kName,
        kCTime,
        kATime,
        kMTime,
        kWinAttributes,
        kComment,
        kEncodedHeader,
        kStartPos,
        kDummy
    };
} ;

END_NAMESPACE_RCZIP

#endif //__RC7zHeader_h_
