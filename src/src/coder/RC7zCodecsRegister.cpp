/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "coder/RC7zCodecsRegister.h"
#include "crypto/7zAES/RC7zAESInfo.h"
#include "crypto/Rar20/RCRar20DecoderInfo.h"
#include "crypto/RarAES/RCRarAESDecoderInfo.h"
#include "crypto/WzAES/RCWzAESInfo.h"
#include "crypto/Zip/RCZipCryptoInfo.h"
#include "compress/copy/RCCopyCoderInfo.h"
#include "compress/byteswap/RCByteSwap2Info.h"
#include "compress/byteswap/RCByteSwap4Info.h"
#include "compress/shrink/RCShrinkDecoderInfo.h"
#include "compress/lzh/RCLzhHuffmanDecoderInfo.h"
#include "compress/z/RCZDecoderInfo.h"
#include "compress/arj/RCArjDecoder1Info.h"
#include "compress/arj/RCArjDecoder2Info.h"
#include "compress/lzx/RCLzxDecoderInfo.h"
#include "compress/lzma/RCLzmaCoderInfo.h"
#include "compress/implode/RCImplodeDecoderInfo.h"
#include "compress/branch/RCBranchARMInfo.h"
#include "compress/branch/RCBranchARMTInfo.h"
#include "compress/branch/RCBranchBCJ2Info.h"
#include "compress/branch/RCBranchBCJInfo.h"
#include "compress/branch/RCBranchIA64Info.h"
#include "compress/branch/RCBranchPPCInfo.h"
#include "compress/branch/RCBranchSPARCInfo.h"
#include "compress/ppmd/RCPPMDCoderInfo.h"
#include "compress/quantum/RCQuantumDecoderInfo.h"
#include "compress/deflate/RCDeflateCOMCoderInfo.h"
#include "compress/deflate/RCDeflateCOMCoder64Info.h"
#include "compress/deflate/RCDeflateNSISCoderInfo.h"
#include "compress/deflate/RCZlibCoderInfo.h"
#include "compress/bzip2/RCBZip2CoderInfo.h"
#include "compress/lzma2/RCLzma2CoderInfo.h"
#include "compress/delta/RCDeltaCoderInfo.h"

BEGIN_NAMESPACE_RCZIP

#ifdef RC_STATIC_SFX

RC7zCodecsRegister::RC7zCodecsRegister()
{
}

RC7zCodecsRegister::~RC7zCodecsRegister()
{
}

HResult RC7zCodecsRegister::LoadCodecs(void)
{
    //������ע����ֽ�����
    ICodecInfoPtr spCodecInfo ;
    spCodecInfo = new RC7zAESInfo ;
    RegisterCodec(spCodecInfo) ;
    
    spCodecInfo = new RCCopyCoderInfo ;
    RegisterCodec(spCodecInfo) ;
      
    spCodecInfo = new RCLzmaCoderInfo ;
    RegisterCodec(spCodecInfo) ;
    
    spCodecInfo = new RCBranchBCJ2Info ;
    RegisterCodec(spCodecInfo) ;
    
    spCodecInfo = new RCBranchBCJInfo ;
    RegisterCodec(spCodecInfo) ;
    
    spCodecInfo = new RCPPMDCoderInfo ;
    RegisterCodec(spCodecInfo) ;

    //���ӽ�ѹ7z��Ҫ�������㷨
    spCodecInfo = new RCBZip2CoderInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCLzma2CoderInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCBranchARMInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCBranchARMTInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCBranchIA64Info;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCBranchPPCInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCBranchSPARCInfo;
    RegisterCodec(spCodecInfo);

    //����deflate,deflate64,delta�㷨
    spCodecInfo = new RCDeflateCOMCoderInfo;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCDeflateCOMCoder64Info;
    RegisterCodec(spCodecInfo);

    spCodecInfo = new RCDeltaCoderInfo;
    RegisterCodec(spCodecInfo);
    
    return RC_S_OK ;
}

#endif //RC_STATIC_SFX

END_NAMESPACE_RCZIP
