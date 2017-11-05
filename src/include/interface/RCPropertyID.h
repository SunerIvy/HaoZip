/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPropertyID_h_
#define __RCPropertyID_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Archive ����
*/
class RCPropID
{
public:
    
    /** ����ID����
    */
    enum EnumType
    {
        kpidNoProperty = 0,
        kpidMainSubfile = 1,
        kpidHandlerItemIndex = 2,
        kpidPath,
        kpidName,
        kpidExtension,
        kpidIsDir,
        kpidSize,
        kpidPackSize,
        kpidAttrib,
        kpidCTime,
        kpidATime,
        kpidMTime,
        kpidSolid,
        kpidCommented,
        kpidEncrypted,
        kpidSplitBefore,
        kpidSplitAfter,
        kpidDictionarySize,
        kpidCRC,
        kpidType,
        kpidIsAnti,
        kpidMethod,
        kpidHostOS,
        kpidFileSystem,
        kpidUser,
        kpidGroup,
        kpidBlock,
        kpidComment,
        kpidPosition,
        kpidPrefix,
        kpidNumSubDirs,
        kpidNumSubFiles,
        kpidUnpackVer,
        kpidVolume,
        kpidIsVolume,
        kpidOffset,
        kpidLinks,
        kpidNumBlocks,
        kpidNumVolumes,
        kpidTimeType,
        kpidBit64,
        kpidBigEndian,
        kpidCpu,
        kpidPhySize,
        kpidHeadersSize,
        kpidChecksum,
        kpidCharacts,
        kpidVa,
        kpidId,
        kpidShortName,
        kpidCreatorApp,
        kpidSectorSize,
        kpidPosixAttrib,
        kpidLink,
        
        kpidTotalSize = 0x1100,
        kpidFreeSpace,
        kpidClusterSize,
        kpidVolumeName,
        
        kpidLocalName = 0x1200,
        kpidProvider,
        
        kpidUserDefined = 0x10000,
        kpidCommentSizePosition,
        
        /** ѹ���ļ����ͣ�����Ϊ64λ�޷�������
        */
        kpidArchiveType = 0x20000,

        /** �ļ��ľ���·�������ļ���������ѯʹ��
        */
        kpidAbsolutePath = 0x30000,

        /** �ļ������·�������ļ���������ѯʹ��
        */
        kpidRelativePath
    } ;
};

typedef RCPropID::EnumType RCPropIDEnumType ;

/** ѹ����ѹ��������
*/
class RCCoderPropID
{
public:
    
    enum EnumType
    {
        kDefaultProp = 0,
        kDictionarySize,
        kUsedMemorySize,
        kOrder,
        kBlockSize,
        kPosStateBits,
        kLitContextBits,
        kLitPosBits,
        kNumFastBytes,
        kMatchFinder,
        kMatchFinderCycles,
        kNumPasses,
        kAlgorithm,
        kNumThreads,
        kEndMarker
    };
};

typedef RCCoderPropID::EnumType RCCoderPropIDEnumType ;

/** ����ID����
*/
typedef uint32_t RCPropertyID ;

END_NAMESPACE_RCZIP

#endif //__RCPropertyID_h_
