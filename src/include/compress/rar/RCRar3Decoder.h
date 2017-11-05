/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3Decoder_h_
#define __RCRar3Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/rar/RCRar3RangeDecoder.h"
#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/rar/RCRar3Defs.h"
#include "compress/ppmd/RCPPMDDecodeInfo.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCRar3Filter ;
class RCRar3TempFilter ;
class RCRar3Vm ;
class RCRar3BlockRef ;

/** RAR3 ������
*/
class RCRar3Decoder:
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetDecoderProperties2
                        >
{
public:

    /** Huffman λ��
    */
    static const int32_t s_kNumHuffmanBits = 15;
    
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar3Decoder() ;
    
    /** Ĭ����������
    */
    ~RCRar3Decoder() ;
    
public:

    /** �ͷ���
    */
    void ReleaseStreams() ;

    /** ���ƿ�
    @param [in] distance ����
    @param [in] len ����
    */
    void CopyBlock(uint32_t distance, uint32_t len) ;

    /** �����ֽ�
    @param [in] b �������ֽ�
    */
    void PutByte(byte_t b) ;
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ;

    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
private:

    /** ����д����
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteDataToStream(const byte_t* data, uint32_t size) ;

    /** д����
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteData(const byte_t* data, uint32_t size);

    /** д����
    @param [in] startPtr ��ʼָ��
    @param [in] endPtr ����ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteArea(uint32_t startPtr, uint32_t endPtr) ;

    /** ִ�й���
    @param [in] tempFilterIndex ���
    @param [out] outBlockRef �����
    */
    void ExecuteFilter(int32_t tempFilterIndex, RCRar3BlockRef& outBlockRef);

    /** д����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult WriteBuf() ;

    /** ��ʼ��������
    */
    void InitFilters() ;

    /** AddVmCode
    @param [in] firstByte ��ʼ�ֽ�
    @param [in] codeSize ��С
    @return �ɹ�����true,���򷵻�false
    */
    bool AddVmCode(uint32_t firstByte, uint32_t codeSize) ;

    /** ReadVmCodeLZ
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadVmCodeLZ();

    /** ReadVmCodePPM
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadVmCodePPM() ;

    /** ��ȡλ
    @param [in] numBits λ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(int32_t numBits) ;

    /** ��ʼ��PPM
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult InitPPM() ;

    /** ����Ppm����
    @return ���ؽ�����
    */
    int32_t DecodePpmSymbol() ;

    /** ����PPM
    @param [in] num ����
    @param [out] keepDecompressing ���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult DecodePPM(int32_t num, bool& keepDecompressing) ;

    /** ��ȡ��
    @param [out] keepDecompressing ���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadTables(bool& keepDecompressing) ;

    /** ��ȡ���β
    @param [out] keepDecompressing ���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadEndOfBlock(bool& keepDecompressing);

    /** LZ ����
    @param [out] keepDecompressing ���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult DecodeLZ(bool& keepDecompressing) ;

    /** ����
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeReal(ICompressProgressInfo* progress);
    
private:

    /** ������
    */
    RCRar3RangeDecoder m_inBitStream;

    /** window
    */
    byte_t* m_window;

    /** winPos
    */
    uint32_t m_winPos;

    /** wrPtr
    */
    uint32_t m_wrPtr;

    /** lzSize
    */
    uint64_t m_lzSize;

    /** ��ѹ���С
    */
    uint64_t m_unpackSize;

    /** д�ļ���С
    */
    uint64_t m_writtenFileSize; // if it's > m_unpackSize, then m_unpackSize only written

    /** �����
    */
    ISequentialOutStreamPtr m_outStream;

    /** ������
    */
    RCHuffmanDecoder<s_kNumHuffmanBits, RCRar3Defs::s_kMainTableSize> m_mainDecoder;

    /** ������
    */
    RCHuffmanDecoder<s_kNumHuffmanBits, RCRar3Defs::s_kDistTableSize> m_distDecoder;

    /** ������
    */
    RCHuffmanDecoder<s_kNumHuffmanBits, RCRar3Defs::s_kAlignTableSize> m_alignDecoder;
 
    /** ������
    */
    RCHuffmanDecoder<s_kNumHuffmanBits, RCRar3Defs::s_kLenTableSize> m_lenDecoder;

    /** ������
    */
    RCHuffmanDecoder<s_kNumHuffmanBits, RCRar3Defs::s_kLevelTableSize> m_levelDecoder;

    /** reps
    */
    uint32_t m_reps[RCRar3Defs::s_kNumReps];

    /** ��󳤶�
    */
    uint32_t m_lastLength;

    /** ��󼶱�
    */
    byte_t m_lastLevels[RCRar3Defs::s_kTablesSizesSum];

    /** vmData
    */
    byte_t* m_vmData;

    /** vmCode
    */
    byte_t* m_vmCode;

    /** vm
    */
    RCRar3Vm& m_vm ;

    /** �����б�
    */
    RCVector<RCRar3Filter*> m_filters;

    /** �����б�
    */
    RCVector<RCRar3TempFilter*> m_tempFilters;

    /** �����˱��
    */
    uint32_t m_lastFilter;

    /** �Ƿ��ʵ
    */
    bool m_isSolid ;

    /** lzģʽ
    */
    bool m_lzMode ;

    /** ǰ����λ
    */
    uint32_t m_prevAlignBits ;

    /** ǰ������
    */
    uint32_t m_prevAlignCount ;

    /** �Ƿ��ȡ��
    */
    bool m_isTablesRead ;

    /** ppm
    */
    RCPPMDDecodeInfo m_ppm ;

    /** ppm Esc Char
    */
    int32_t m_ppmEscChar ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar3Decoder_h_
