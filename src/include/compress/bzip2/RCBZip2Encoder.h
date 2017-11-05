/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2Encoder_h_
#define __RCBZip2Encoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/bzip2/RCBZip2ThreadInfo.h"
#include "common/RCInBuffer.h"
#include "common/RCOutBuffer.h"
#include "compress/bzip2/RCBZip2CombinedCRC.h"
#include "common/RCBitmEncoder.h"
#include "thread/RCMutex.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 ������
*/
class RCBZip2Encoder:
#ifdef COMPRESS_BZIP2_MT
    public IUnknownImpl3<ICompressCoder,
                         ICompressSetCoderProperties,
                         ICompressSetCoderMt
                        >
#else
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetCoderProperties
                        >
#endif
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2Encoder() ;
    
    /** Ĭ����������
    */
    ~RCBZip2Encoder() ;
    
public:
    
    /** д����
    @param [in] data ����
    @param [in] sizeInBits λ��
    @param [in] lastByte ����ֽ�
    */
    void WriteBytes(const byte_t* data, uint32_t sizeInBits, byte_t lastByte);
    
    /** ��ȡRle��
    @param [in] buffer ���ݻ���
    @return ���ض�ȡ�ֽ���
    */
    uint32_t ReadRleBlock(byte_t* buffer) ;
    
    /** дλ����
    @param [in] value ��ֵ
    @param [in] numBits λ��
    */
    void WriteBits(uint32_t value, uint32_t numBits) ;
    
    /** д���ֽ�
    @param [in] b д����ֽ�
    */
    void WriteByte(byte_t b) ;
    
    /** дλ
    @param [in] v
    */
    void WriteBit(bool v) ;
    
    /** дCRCУ��ֵ
    @param [in] v CRCУ��ֵ
    */
    void WriteCRC(uint32_t v) ;
    
    /** Flush����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** �ͷ���
    */
    void ReleaseStreams() ;
    
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

    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
        
public:
    
    /** ����������
    */
    RCInBuffer m_inStream;
    
    /** mt Pad
    */
    byte_t m_mtPad[1 << 8]; // It's pad for Multi-Threading. Must be >= Cache_Line_Size.
    
    /** ���������
    */
    RCBitmEncoder<RCOutBuffer> m_outStream;
    
    /** num Passes ֵ
    */
    uint32_t m_numPasses;
    
    /** CRCУ��
    */
    RCBZip2CombinedCRC m_combinedCRC;

#ifdef COMPRESS_BZIP2_MT

    /** �߳���Ϣ
    */
    RCBZip2ThreadInfo* m_threadsInfo;
    
    /** ͬ���¼�
    */
    RCManualResetEvent m_canProcessEvent;
    
    /** ͬ���ٽ���
    */
    RCMutex m_critSection;
    
    /** �߳���
    */
    uint32_t m_numThreads;
    
    /** ���߳�ģʽ
    */
    bool m_mtMode;
    
    /** ��һ����
    */
    uint32_t m_nextBlockIndex;
    
    /** �ر��߳�
    */
    bool m_closeThreads;
    
    /** ���Ƿ����
    */
    bool m_streamWasFinished;
    
    /** ͬ���¼�
    */
    RCManualResetEvent m_canStartWaitingEvent;
    
    /** �������
    */
    HResult m_result;
    
    /** ѹ������
    */
    ICompressProgressInfo* m_progress;
    
    /** ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Create();
    
    /** �ͷ�
    */
    void Free();
    
    /** �����߳���
    @param [in] numThreads �߳���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetNumberOfThreads(uint32_t numThreads) ;
    
#else

    /** �߳���Ϣ
    */
    RCBZip2ThreadInfo m_threadsInfo ;
    
#endif

private:

    /** ����ʵ��
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �����С
    @param [in] progress ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeReal(ISequentialInStream* inStream,
                     ISequentialOutStream* outStream, 
                     const uint64_t* inSize, 
                     const uint64_t* outSize,
                     ICompressProgressInfo* progress) ;
    
private:
    
    /** ���С
    */
    uint32_t m_blockSizeMult;
    
    /** �Ż�������
    */
    bool m_optimizeNumTables;
    
    /** Passes��
    */
    uint32_t m_numPassesPrev;
    
    /** �߳���
    */
    uint32_t m_numThreadsPrev;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2Encoder_h_
