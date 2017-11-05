/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateEncoder_h_
#define __RCDeflateEncoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCBitlEncoder.h"
#include "compress/deflate/RCDeflateEncoderValue.h"
#include "compress/deflate/RCDeflateDefs.h"
#include "compress/deflate/RCDeflateLevels.h"
#include "compress/deflate/RCDeflateEncoderTables.h"
#include "compress/deflate/RCDeflateEncoderOptimal.h"
#include "interface/ICoder.h"

#include "algorithm/LzFind.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate ������
*/
class RCDeflateEncoder:
    private RCNonCopyable
{
protected:

    typedef struct _CSeqInStream
    {
        ISeqInStream SeqInStream ;
        ISequentialInStreamPtr RealStream ;
    }CSeqInStream;

public:

    /** Ĭ�Ϲ��캯��
    */
    explicit RCDeflateEncoder(bool deflate64Mode = false) ;
    
    /** Ĭ����������
    */
    virtual ~RCDeflateEncoder() ;
    
public:

    /** ����ƥ��
    */
    void GetMatches() ;

    /** �ƶ�λ��
    @param [in] num λ��
    */
    void MovePos(uint32_t num) ;

    /** ����
    @param [in] backRes ����λ��
    @param [in] cur ��ʼλ��
    @return �����ƶ����ֽ���
    */
    uint32_t Backward(uint32_t& backRes, uint32_t cur) ;

    /** ȡ���Ż�
    @param [out] backRes ���˽��
    @return �����ƶ��ֽ���
    */
    uint32_t GetOptimal(uint32_t& backRes);

    /** ȡ�ÿ����Ż�
    @param [out] backRes ���˽��
    @return �����ƶ��ֽ���
    */
    uint32_t GetOptimalFast(uint32_t& backRes) ;

    /** �����
    @param [in] levels ���� 
    @param [in] numLevels ����
    @param [in] freqs Ƶ��
    */
    void LevelTableDummy(const byte_t* levels, int32_t numLevels, uint32_t* freqs) ;

    /** д������λ
    @param [in] value ����
    @param [in] numBits λ����
    */
    void WriteBits(uint32_t value, int32_t numBits);

    /** �������
    @param [in] levels ����
    @param [in] numLevels ����
    @param [in] lens ����
    @param [in] codes ��������
    */
    void LevelTableCode(const byte_t* levels, int32_t numLevels, const byte_t* lens, const uint32_t* codes);

    /** ���ɱ�
    @param [in] maxHuffLen ��󳤶� 
    */
    void MakeTables(uint32_t maxHuffLen);

    /** ���ؿ�Ȩ��
    @return ���ؿ�Ȩ��
    */
    uint32_t GetLzBlockPrice() const ;

    /** ���Կ�
    */
    void TryBlock() ;

    /** ���Կ�
    @param [in] tableIndex ����
    @param [in] numPasses ����ֵ
    @return ���سɹ��ֽ���
    */
    uint32_t TryDynBlock(int32_t tableIndex, uint32_t numPasses) ;

    /** �����޸���
    @param [in] tableIndex ����
    @return ���سɹ��ֽ���
    */
    uint32_t TryFixedBlock(int32_t tableIndex) ;

    /** ����Ȩ��
    @param [in] levels ����
    */
    void SetPrices(const RCDeflateLevels& levels);

    /** д���
    */
    void WriteBlock() ;

    /** ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Create() ;

    /** �ͷ�
    */
    void Free() ;

    /** д��洢��
    @param [in] blockSize ���С
    @param [in] additionalOffset ����ƫ����
    @param [in] finalBlock �Ƿ����һ��
    */
    void WriteStoreBlock(uint32_t blockSize, uint32_t additionalOffset, bool finalBlock) ;

    /** �ͷ���
    */
    void ReleaseStreams() ;

    /** ���ؿ�Ȩ��
    @param [in] tableIndex ����
    @param [in] numDivPasses
    @return ����Ȩ��
    */
    uint32_t GetBlockPrice(int32_t tableIndex, int32_t numDivPasses) ;

    /** �����
    @param [in] tableIndex ����
    @param [in] finalBlock �ͷ�����
    */
    void CodeBlock(int32_t tableIndex, bool finalBlock) ;

public:
    
    /** ���뺯��
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

    /** ��������
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �����С
    @param [in] progress ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult BaseCode(ISequentialInStream* inStream,
                     ISequentialOutStream* outStream, 
                     const uint64_t* inSize, 
                     const uint64_t* outSize,
                     ICompressProgressInfo *progress) ;
    
    /** ���ñ�������
    @param [in] propertyArray �����б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult BaseSetEncoderProperties2(const RCPropertyIDPairArray& propertyArray) ;
            
private:
    
    /** ����ֵ
    */
    RCDeflateEncoderValue* m_values;
    
    /** ƥ��
    */
    uint16_t* m_matchDistances;
    
    /** �����ֽ�
    */
    uint32_t m_numFastBytes;
    
    /** ����ģʽ
    */
    bool m_fastMode;
    
    /** btģʽ
    */
    bool m_btMode;
    
    /** ����
    */
    uint16_t* m_onePosMatchesMemory;
    
    /** ����
    */
    uint16_t* m_distanceMemory;
    
    /** λ��
    */
    uint32_t m_pos;
    
    /** �����ֽ���
    */
    int32_t m_numPasses;
    
    /** �����ֽ���
    */
    int32_t m_numDivPasses;
    
    /** ���ͳ��
    */
    bool m_checkStatic;
    
    /** Multi Pass
    */
    bool m_isMultiPass;
    
    /** ���С
    */
    uint32_t m_valueBlockSize;
    
    /** ��ϳ���
    */
    uint32_t m_numLenCombinations;
    
    /** ���ƥ�䳤��
    */
    uint32_t m_matchMaxLen;
    
    /** ��ʼλ��
    */
    const byte_t* m_lenStart;
    
    /** Direct Bit
    */
    const byte_t* m_lenDirectBits;
    
    /** �Ƿ񴴽�
    */
    bool m_created;
    
    /** Deflate 64ģʽ
    */
    bool m_deflate64Mode;
    
    /** ����
    */
    byte_t m_levelLevels[RCDeflateDefs::s_kLevelTableSize];
        
    /** ������
    */
    int32_t m_numLitLenLevels;
    
    /** ������
    */
    int32_t m_numDistLevels;
    
    /** �������
    */
    uint32_t m_numLevelCodes;
    
    /** ֵ���
    */
    uint32_t m_valueIndex;
    
    /** Second Pass
    */
    bool m_secondPass;
    
    /** ����ƫ��
    */
    uint32_t m_additionalOffset;
    
    /** �Ż����
    */
    uint32_t m_optimumEndIndex;
    
    /** �Ż���ǰ���
    */
    uint32_t m_optimumCurrentIndex;
    
    /** �ַ�Ȩ��
    */
    byte_t  m_literalPrices[256];
    
    /** ����Ȩ��
    */
    byte_t  m_lenPrices[RCDeflateDefs::s_kNumLenSymbolsMax];
        
    /** λȨ��
    */
    byte_t  m_posPrices[RCDeflateDefs::s_kDistTableSize64];
    
    /** ����
    */
    RCDeflateLevels m_newLevels;
    
    /** Ƶ��
    */
    uint32_t m_mainFreqs[RCDeflateDefs::s_kFixedMainTableSize];
        
    /** Ƶ��
    */
    uint32_t m_distFreqs[RCDeflateDefs::s_kDistTableSize64];
        
    /** ������
    */
    uint32_t m_mainCodes[RCDeflateDefs::s_kFixedMainTableSize];
    
    /** ժҪ����
    */
    uint32_t m_distCodes[RCDeflateDefs::s_kDistTableSize64];
    
    /** Level ����
    */
    uint32_t m_levelCodes[RCDeflateDefs::s_kLevelTableSize];
    
    /** Level ����
    */
    byte_t m_levelLens[RCDeflateDefs::s_kLevelTableSize];
    
    /** ���С
    */
    uint32_t m_blockSizeRes;
    
    /** �����
    */
    RCDeflateEncoderTables* m_tables;
    
    /** �Ż���
    */
    RCDeflateEncoderOptimal m_optimum[RCDeflateDefs::s_kNumOpts];
    
    /** ƥ��ѭ��
    */
    uint32_t m_matchFinderCycles;
    
private:
    
    /** ��ȡ
    @param [in] object ����
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return ���ض�ȡ�ֽ���
    */
    static result_t Read(void* object, void* data, size_t* size) ;
    
    /** ȡ��λ��Slot
    @param [in] pos λ��
    @return ����Slot
    */
    static uint32_t GetPosSlot(uint32_t pos) ;
    
    /** �ڴ�����
    @param [out] p ָ��
    @param [in] size �ڴ��С
    @return ����������ڴ��ַ
    */
    static void* SzAlloc(void* p, size_t size) ;
    
    /** �ͷ��ڴ�
    @param [in] p ָ��
    @param [in] address ָ��
    */
    static void SzFree(void* p, void* address) ;
    
    /** 
    @param [in] freqs
    @param [in] lens
    @param [in] num
    @return ����Ȩ��
    */
    static uint32_t HuffmanGetPrice(const uint32_t* freqs, const byte_t* lens, uint32_t num) ;
    
    /**
    @param [in] freqs
    @param [in] lens
    @param [in] num
    @param [in] extraBits
    @param [in] extraBase
    @return ����Ȩ��
    */
    static uint32_t HuffmanGetPriceSpec(const uint32_t* freqs, 
                                          const byte_t* lens, 
                                          uint32_t num, 
                                          const byte_t* extraBits, 
                                          uint32_t extraBase) ;
    
    /**
    @param [in] codes
    @param [in] lens
    @param [in] num
    */
    static void HuffmanReverseBits(uint32_t* codes, const byte_t* lens, uint32_t num) ;
    
    /**
    @param [in] blockSize
    @param [in] bitPosition
    @return 
    */
    static uint32_t GetStorePrice(uint32_t blockSize, int32_t bitPosition) ;
    
private:
    
    /** �ڴ����
    */
    static ISzAlloc s_alloc ;
        
private:
    
    /** ƥ�����
    */
    CMatchFinder m_lzInWindow ;
    
    /** λ����
    */
    RCBitlEncoder m_outStream ;
    
    /** ����������
    */
    CSeqInStream m_seqInStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateEncoder_h_
