/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar2Decoder_h_
#define __RCRar2Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBitmDecoder.h"
#include "common/RCInBuffer.h"
#include "compress/lz/RCLZOutWindow.h"
#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/rar/RCRar2Filter2.h"

BEGIN_NAMESPACE_RCZIP

/** RAR2 ������
*/
class RCRar2Decoder:
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetDecoderProperties2
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar2Decoder() ;
    
    /** Ĭ����������
    */
    ~RCRar2Decoder() ;
    
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

    /** ��ʼ��
    */
    void InitStructures() ; 

    /** λ��ȡ
    @param [in] numBits λ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(int32_t numBits) ;

    /** ��ȡ��
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadTables();

    /** ��ȡ��
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadLastTables() ;

    /** ����
    @param [in] pos λ��
    @return �ɹ�����true,���򷵻�false
    */
    bool DecodeMm(uint32_t pos) ;

    /** lz ����
    @param [in] pos λ��
    @return �ɹ�����true,���򷵻�false
    */
    bool DecodeLz(int32_t pos) ;
    
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

    /** �����
    */
    RCLZOutWindow m_outWindowStream ;

    /** ������
    */
    RCBitmDecoder<RCInBuffer> m_inBitStream ;

    /** ������
    */
    RCHuffmanDecoder<RCRar2Defs::s_kNumHuffmanBits, RCRar2Defs::s_kMainTableSize> m_mainDecoder;

    /** ������
    */
    RCHuffmanDecoder<RCRar2Defs::s_kNumHuffmanBits, RCRar2Defs::s_kDistTableSize> m_distDecoder;

    /** ������
    */
    RCHuffmanDecoder<RCRar2Defs::s_kNumHuffmanBits, RCRar2Defs::s_kLenTableSize> m_lenDecoder;

    /** ������
    */
    RCHuffmanDecoder<RCRar2Defs::s_kNumHuffmanBits, RCRar2Defs::s_kMMTableSize> m_mmDecoders[RCRar2Defs::s_kNumChanelsMax];

    /** ������
    */
    RCHuffmanDecoder<RCRar2Defs::s_kNumHuffmanBits, RCRar2Defs::s_kLevelTableSize> m_levelDecoder;

    /** mm ������
    */
    RCRar2Filter2 m_mmFilter;

    /** �Ƿ�audioģʽ
    */
    bool m_audioMode ;    

    /** ͨ����
    */
    int32_t m_numChannels;

    /** rep Dists
    */
    uint32_t m_repDists[RCRar2Defs::s_kNumRepDists] ;

    /** repDistPtr
    */
    uint32_t m_repDistPtr;

    /** ��󳤶�
    */
    uint32_t m_lastLength;  

    /** ��󼶱�
    */
    byte_t m_lastLevels[RCRar2Defs::s_kMaxTableSize] ;

    /** ѹ�����С
    */
    uint64_t m_packSize ;

    /** �Ƿ��ʵ
    */
    bool m_isSolid ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar2Decoder_h_
