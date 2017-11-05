/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipAddCommon_h_
#define __RCZipAddCommon_h_ 1

#include "base/RCDefs.h"
#include "RCZipCompressionMethodMode.h"
#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "common/RCFilterCoder.h"
#include "compress/copy/RCCopyCoder.h"
#include "crypto/Zip/RCZipEncoder.h"
#include "crypto/WzAES/RCWzAESEncoder.h"
#include "format/zip/RCZipExtFilter.h"
#include "format/zip/RCZipFileFilter.h"

BEGIN_NAMESPACE_RCZIP

struct RCZipCompressingResult
{
    /** ��ѹ��С
    */
    uint64_t m_unpackSize ;

    /** ѹ������С
    */
    uint64_t m_packSize ;
    
    /** CRCУ����
    */
    uint32_t m_crc ;

    /** ѹ��ģʽ
    */
    uint16_t m_method ;

    /** ��ѹ�汾
    */
    byte_t m_extractVersion ;
};

class RCZipAddCommon
{
public:

    /** Ĭ�Ϲ��캯��
    @param [in] options ѹ��ģʽ��Ϣ
    */
    RCZipAddCommon(const RCZipCompressionMethodMode& options);

public:

    /** ѹ��
    @param [in] codecsInfo ���������
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] progress ���ȹ�����
    @param [in] operationResult ѹ�����
    @param [in] zipExtFilter ��չ��������
    @param [in] zipFileFilter �ļ�������
    @param [in] isFileFilter �Ƿ�����ļ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Compress(ICompressCodecsInfo* codecsInfo,
                     ISequentialInStream* inStream,
                     IOutStream* outStream,
                     ICompressProgressInfo* progress,
                     RCZipCompressingResult& operationResult,
                     RCZipExtFilterPtr& zipExtFilter,
                     RCZipFileFilter& zipFileFilter,
                     bool isFileFilter);

private:

    /** ѹ��ģʽ
    */
    RCZipCompressionMethodMode m_options;

    /** COPY������
    */
    RCCopyCoder* m_copyCoderSpec;

    /** COPY������
    */
    ICompressCoderPtr m_copyCoder;

    /** LZMA������
    */
    ICompressCoderPtr m_zipLzmaEncoder;

    /** SHRINK������
    */
    ICompressCoderPtr m_shrinkEncoder;

    /** IMPLODED������
    */
    ICompressCoderPtr m_implodedEncoder;

    /** DEFLATED������
    */
    ICompressCoderPtr m_deflatedComEncoder;

    /** DEFLATED64������
    */
    ICompressCoderPtr m_deflated64Encoder;

    /** BZIP2������
    */
    ICompressCoderPtr m_bzip2Encoder;

    /** ���ܹ�����
    */
    RCFilterCoder* m_cryptoStreamSpec;

    /** ���������
    */
    ISequentialOutStreamPtr m_cryptoStream;

    /** ZIP������
    */
    RCZipEncoder* m_filterSpec;

    /** WZAES������
    */
    RCWzAESEncoder* m_filterAesSpec;

    /** ZIP������
    */
    ICompressFilterPtr m_zipCryptoFilter;

    /** WZAES������
    */
    ICompressFilterPtr m_aesFilter;
};

END_NAMESPACE_RCZIP

#endif //__RCZipAddCommon_h_
