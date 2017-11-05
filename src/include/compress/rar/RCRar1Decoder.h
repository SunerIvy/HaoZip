/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar1Decoder_h_
#define __RCRar1Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBitmDecoder.h"
#include "common/RCInBuffer.h"
#include "compress/lz/RCLZOutWindow.h"
#include "compress/huffman/RCHuffmanDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Rar1 ������
*/
class RCRar1Decoder:
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetDecoderProperties2
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar1Decoder() ;
    
    /** Ĭ����������
    */
    ~RCRar1Decoder() ;

public:

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

    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
        
private:

    /** ��ȡλ
    @param [in] numBits λ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(int32_t numBits) ;

    /** ���ƿ�
    @param [in] distance ����
    @param [in] len ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CopyBlock(uint32_t distance, uint32_t len) ;

    /** ����
    @param [in] posTab 
    @return ���ؽ�����
    */
    uint32_t DecodeNum(const uint32_t* posTab) ;

    /** LZ ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ShortLZ() ;

    /** LZ ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult LongLZ() ;

    /** Huffman ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult HuffDecode();

    /** ȡ�ñ�־����
    */
    void GetFlagsBuf() ;

    /** ��ʼ������
    */
    void InitData() ;

    /** ��ʼ��Huffman
    */
    void InitHuff() ;

    /** CorrHuff
    @param [in] CharSet 
    @param [in] NumToPlace
    */
    void CorrHuff(uint32_t* CharSet, uint32_t* NumToPlace) ;

    /** ��ʼ��
    */
    void InitStructures();
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeReal(ISequentialInStream* inStream,
                             ISequentialOutStream* outStream, 
                             const uint64_t* inSize, 
                             const uint64_t* outSize,
                             ICompressProgressInfo* progress) ;
    
private:

    /** s_kNumRepDists
    */
    static const uint32_t s_kNumRepDists = 4 ;
    
private:

    /** �����
    */
    RCLZOutWindow m_outWindowStream;

    /** ������
    */
    RCBitmDecoder<RCInBuffer> m_inBitStream;

    /** ժҪ
    */
    uint32_t m_repDists[s_kNumRepDists];

    /** repָ��
    */
    uint32_t m_repDistPtr;

    /** lastDist
    */
    uint32_t m_lastDist;

    /** lastLength
    */
    uint32_t m_lastLength;

    /** ��ѹ���С
    */
    int64_t m_unpackSize;

    /** �Ƿ��ʵ
    */
    bool m_isSolid;

    /** chSet
    */
    uint32_t m_chSet[256] ;

    /** chSetA
    */
    uint32_t m_chSetA[256] ;

    /** chSetB
    */
    uint32_t m_chSetB[256] ;

    /** chSetC
    */
    uint32_t m_chSetC[256] ;

    /** place
    */
    uint32_t m_place[256] ;

    /** placeA
    */
    uint32_t m_placeA[256] ;

    /** placeB
    */
    uint32_t m_placeB[256] ;

    /** placeC
    */
    uint32_t m_placeC[256] ;

    /** NToPl
    */
    uint32_t m_NToPl[256] ;

    /** NToPlB
    */
    uint32_t m_NToPlB[256] ;

    /** NToPlC
    */
    uint32_t m_NToPlC[256] ;

    /** ��־����
    */
    uint32_t m_flagBuf ;

    /** avrPlc
    */
    uint32_t m_avrPlc ;

    /** avrPlcB
    */
    uint32_t m_avrPlcB ;

    /** avrLn1
    */
    uint32_t m_avrLn1 ;

    /** avrLn2
    */
    uint32_t m_avrLn2 ;

    /** avrLn3
    */
    uint32_t m_avrLn3 ;

    /** buf60
    */
    int32_t m_buf60 ;

    /** numHuf
    */
    int32_t m_numHuf ;

    /** stMode
    */
    int32_t m_stMode ;

    /** lCount
    */
    int32_t m_lCount ;

    /** flagsCnt
    */
    int32_t m_flagsCnt;

    /** nhfb
    */
    uint32_t m_nhfb ;

    /** nlzb
    */
    uint32_t m_nlzb ;

    /** maxDist3
    */
    uint32_t m_maxDist3 ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar1Decoder_h_
