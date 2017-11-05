/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzxDecoder_h_
#define __RCLzxDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "interface/IStream.h"
#include "compress/lz/RCLZOutWindow.h"
#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/lzx/RCLzxBitStreamDecoder.h"
#include "compress/lzx/RCLzxX86ConvertOutStream.h"
#include "compress/lzx/RCLzxDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Lzx ������
*/
class RCLzxDecoder:
    public IUnknownImpl5<ICompressCoder,
                         IOutStreamFlush,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ICompressSetCoderProperties>
{
public:

    /** ���캯��
    @param [in] wimMode wimģʽ
    */
    explicit RCLzxDecoder(bool wimMode = false) ;
    
    /** Ĭ����������
    */
    ~RCLzxDecoder() ;

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
    
    /** ��ջ����������ѻ�������д����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Flush() ;
    
    /** ����������
    @param [in] inStream �������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetInStream(ISequentialInStream* inStream) ;
    
    /** �ͷ�������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ReleaseInStream() ;
    
    /** �����������С
    @param [in] outSize �������С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOutStreamSize(const uint64_t* outSize) ;
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
private:
    
    /** ���ò���
    @param [in] numDictBits �ֵ�λ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetParams(int32_t numDictBits) ;
    
    /** �����Ƿ�����ʷ
    @param [in] keepHistory  �Ƿ�����ʷ
    */
    void SetKeepHistory(bool keepHistory) ;
    
    /** ��ȡ����
    @param [in] numBits ����λ��
    @return ���ض�ȡ���
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** ��ȡ��
    @param [in] lastLevels ��󼶱�
    @param [in] newLevels �¼���
    @param [in] numSymbols ������
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadTable(byte_t* lastLevels, byte_t* newLevels, uint32_t numSymbols);
    
    /** ��ȡ��
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadTables();
    
    /** �����ǰ����
    */
    void ClearPrevLevels();
    
    /** ����
    @param [in] size ��С
    @return �ɹ�����true,���򷵻�false
    */
    HResult CodeSpec(uint32_t size) ;
    
    /** ���뺯��
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �������Ŷ��
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����true,���򷵻�false
    */
    HResult CodeReal(ISequentialInStream* inStream,
                     ISequentialOutStream* outStream, 
                     const uint64_t* inSize, 
                     const uint64_t* outSize,
                     ICompressProgressInfo* progress) ;
    
private:
    
    /** ������
    */
    RCLzxBitStreamDecoder m_inBitStream;
    
    /** �����
    */
    RCLZOutWindow m_outWindowStream;

    /** �ظ�����
    */
    uint32_t m_repDistances[RCLzxDefs::s_kNumRepDistances];
        
    /** λ�ó���
    */
    uint32_t m_numPosLenSlots;

    /** �Ƿ��ǽ�ѹ��
    */
    bool m_isUncompressedBlock;
    
    /** �Ƿ����
    */
    bool m_alignIsUsed;

    /** ������
    */
    RCHuffmanDecoder<RCLzxDefs::s_kNumHuffmanBits, RCLzxDefs::s_kMainTableSize> m_mainDecoder;
        
    /** ������
    */
    RCHuffmanDecoder<RCLzxDefs::s_kNumHuffmanBits, RCLzxDefs::s_kNumLenSymbols> m_lenDecoder;
        
    /** ������
    */
    RCHuffmanDecoder<RCLzxDefs::s_kNumHuffmanBits, RCLzxDefs::s_kAlignTableSize> m_alignDecoder;
    
    /** ������
    */
    RCHuffmanDecoder<RCLzxDefs::s_kNumHuffmanBits, RCLzxDefs::s_kLevelTableSize> m_levelDecoder;

    /** ������
    */
    byte_t m_lastMainLevels[RCLzxDefs::s_kMainTableSize];
        
    /** ����
    */
    byte_t m_lastLenLevels[RCLzxDefs::s_kNumLenSymbols];

    /** �����
    */
    RCLzxX86ConvertOutStream* m_x86ConvertOutStreamSpec;
    
    /** �����
    */
    ISequentialOutStreamPtr m_x86ConvertOutStream;

    /** ��ѹ���С
    */
    uint32_t m_unCompressedBlockSize;

    /** �Ƿ񱣴���ʷ
    */
    bool m_keepHistory;
    
    /** ��������
    */
    int32_t m_remainLen;
    
    /** �Ƿ������ֽ�
    */
    bool m_skipByte;
    
    /** wimģʽ
    */
    bool m_wimMode;
};

END_NAMESPACE_RCZIP

#endif //__RCLzxDecoder_h_
