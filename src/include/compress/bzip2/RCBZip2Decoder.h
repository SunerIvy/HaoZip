/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2Decoder_h_
#define __RCBZip2Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCInBuffer.h"
#include "common/RCOutBuffer.h"
#include "common/RCBitmDecoder.h"
#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/bzip2/RCBZip2Defs.h"
#include "compress/bzip2/RCBZip2CombinedCRC.h"
#include "compress/bzip2/RCBZip2DecoderState.h"
#include "thread/RCMutex.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 ������
*/
class RCBZip2Decoder:
#ifdef COMPRESS_BZIP2_MT
    public IUnknownImpl5<ICompressCoder,
                         ICompressGetInStreamProcessedSize,
                         ICompressSetCoderMt,
                         IBZip2ResumeDecoder,
                         ICompressSetCoderProperties
                        >
#else
    public IUnknownImpl4<ICompressCoder,
                         ICompressGetInStreamProcessedSize,
                         IBZip2ResumeDecoder,
                         ICompressSetCoderProperties
                        >
#endif
{
public:
    
    typedef RCHuffmanDecoder<RCBZip2Defs::s_kMaxHuffmanLen, RCBZip2Defs::s_kMaxAlphaSize> RCBZip2HuffmanDecoder ;
        
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2Decoder() ;
    
    /** Ĭ����������
    */
    ~RCBZip2Decoder() ;
    
public:
    
    /** ���ý���
    @param [in] packSize ���ݴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetRatioProgress(uint64_t packSize);
    
    /** ��ȡǩ��
    @param [out] wasFinished �Ƿ����
    @param [out] crc CRCУ��ֵ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadSignatures(bool& wasFinished, uint32_t& crc) ;
    
    /** Flush����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** �ͷ��ļ���
    @param [in] releaseInStream �Ƿ��ͷ�������
    */
    void ReleaseStreams(bool releaseInStream) ;

public:
    
    /** ����������
    @param [in] inStream ����������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetInStream(ISequentialInStream* inStream) ;
    
    /** �ͷ�������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ReleaseInStream() ;
    
    /** ����
    @param [in] outStream ���������
    @param [out] isBZ �Ƿ�ΪBZip2����
    @param [in]  progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, bool& isBZ, ICompressProgressInfo* progress) ;
    
    /** ��ȡ�����������Ѵ�����
    @return �����������Ѵ����ֽ���
    */
    virtual uint64_t GetInputProcessedSize() ;

public:
    
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

    /** ��ȡ��������ȡ�����ݳ���
    @param [out] size �������ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetInStreamProcessedSize(uint64_t& size) ;
        
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ; 

public:
    
    /** �������
    */
    RCOutBuffer m_outStream;
    
    /** mt Pad
    */
    byte_t m_mtPad[1 << 8] ; // It's pad for Multi-Threading. Must be >= Cache_Line_Size.
    
    /** ���뻺��
    */
    RCBitmDecoder<RCInBuffer> m_inStream;
    
    /** ѡ��
    */
    byte_t m_selectors[RCBZip2Defs::s_kNumSelectorsMax];
        
    /** Huffman����
    */
    RCBZip2HuffmanDecoder m_huffmanDecoders[RCBZip2Defs::s_kNumTablesMax];
        
    /** inStart
    */
    uint64_t m_inStart ;
    
    /** CRCУ��
    */
    RCBZip2CombinedCRC m_combinedCRC ;
    
#ifdef COMPRESS_BZIP2_MT
    
    /** ���Ƚӿ�ָ��
    */
    ICompressProgressInfo* m_progress ;
    
    /** ״̬
    */
    RCBZip2DecoderState* m_states ;
    
    /** �߳���
    */
    uint32_t m_numThreadsPrev ;
    
    /** ͬ���¼�
    */
    RCManualResetEvent m_canProcessEvent;
    
    /** ͬ���ٽ���
    */
    RCMutex m_critSection;
    
    /** �߳���
    */
    uint32_t m_numThreads;
    
    /** �Ƿ���߳�ģʽ
    */
    bool m_isMtMode ;
    
    /** ��һ����
    */
    uint32_t m_nextBlockIndex ;
    
    /** �Ƿ�ر��߳�
    */
    bool m_isCloseThreads;
    
    /** ���Ƿ����1
    */
    bool m_streamWasFinished1;
    
    /** ���Ƿ����2
    */
    bool m_streamWasFinished2;
    
    /** ͬ���¼�
    */
    RCManualResetEvent m_canStartWaitingEvent;
    
    /** ������1
    */
    HResult m_result1;
    
    /** ������2
    */
    HResult m_result2;
    
    /** �����С
    */
    uint32_t m_blockSizeMax;

    /** ����������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Create();
    
    /** �Ƿ�
    */
    void Free();

    /** �����߳���
    @param [in] numThreads �߳�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetNumberOfThreads(uint32_t numThreads) ;
    
#else

    /** ״̬
    */
    RCBZip2DecoderState m_states[1];
    
#endif

private:
    
    /** �Ƿ���������ʼ��
    */
    bool m_needInStreamInit ;

    /** �Ƿ�IszBzip2�㷨
    */
    bool m_isIszBZip2 ;

private:
    
    /** ��ȡ����λ
    @param [in] numBits ����λ��
    @return ���ض�ȡ������λ��
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** ��ȡ�ֽ�
    @return ���ض�ȡ���ֽ�
    */
    byte_t ReadByte() ;
    
    /** ��ȡλ
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadBit() ;
    
    /** ȡ��CRCУ��
    @return ����CRCУ��
    */
    uint32_t ReadCRC() ;
    
    /** �ļ�����
    @param [out] isBZ �Ƿ���BZ
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult DecodeFile(bool& isBZ, ICompressProgressInfo* progress) ;
    
    /** �������
    @param [in] inStream ������
    @param [in] outStream �����
    @param [out] isBZ �Ƿ�BZip2
    @param [in] progress �������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeReal(ISequentialInStream* inStream,
                     ISequentialOutStream* outStream, 
                     bool& isBZ,
                     ICompressProgressInfo* progress) ;

public:
    
    /** ��ȡ����λ
    @param [in] inStream ����������
    @param [in] num ����λ��
    @return ���ض�ȡλ��
    */
    static uint32_t ReadBits(RCBitmDecoder<RCInBuffer>* inStream, int32_t num) ;
    
    /** ��ȡλ
    @param [in] inStream ����������
    @return ���ض�ȡλ��
    */
    static uint32_t ReadBit(RCBitmDecoder<RCInBuffer>* inStream) ;
    
    /** ��ȡ���ݿ�
    @param [in] inStream ������
    @param [out] charCounters �ַ���
    @param [out] blockSizeMax ������ֽ���
    @param [out] selectors
    @param [out] huffmanDecoders
    @param [out] blockSizeRes
    @param [out] origPtrRes
    @param [out] randRes
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult ReadBlock(RCBitmDecoder<RCInBuffer>* inStream,
                             uint32_t* charCounters, 
                             uint32_t blockSizeMax, 
                             byte_t* selectors, 
                             RCBZip2HuffmanDecoder* huffmanDecoders,
                             uint32_t* blockSizeRes, 
                             uint32_t* origPtrRes, 
                             bool* randRes) ;
                             
    /** �����1
    @param [in] charCounters �ֽ���
    @param [in] blockSize ���С
    */
    static void DecodeBlock1(uint32_t* charCounters, uint32_t blockSize) ;
    
    /** �����2
    @param [in] tt ��������
    @param [in] blockSize ���С
    @param [in] origPtr 
    @param [in] outStream �����
    @return ���ؽ�������ֽ���
    */
    static uint32_t DecodeBlock2(const uint32_t* tt, 
                                 uint32_t blockSize, 
                                 uint32_t origPtr, 
                                 RCOutBuffer& outStream) ;
    
    /** �����2
    @param [in] tt  ��������
    @param [in] blockSize ���С
    @param [in] origPtr 
    @param [in] outStream ���������
    @return ���ؽ�������ֽ���
    */
    static uint32_t DecodeBlock2Rand(const uint32_t* tt, 
                                     uint32_t blockSize, 
                                     uint32_t origPtr, 
                                     RCOutBuffer& outStream) ;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2Decoder_h_
