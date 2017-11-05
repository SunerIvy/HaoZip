/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCImplodeHuffmanDecoder_h_
#define __RCImplodeHuffmanDecoder_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCBitlDecoder.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Implode Huffman ����
*/
class RCImplodeHuffmanDecoder:
    private RCNonCopyable
{
public:

    /** ���캯��
    @param [in] numSymbols ������
    */
    explicit RCImplodeHuffmanDecoder(uint32_t numSymbols) ;
    
    /** Ĭ����������
    */
    ~RCImplodeHuffmanDecoder() ;

public:
    
    /** �λ��
    */
    static const int32_t s_kNumBitsInLongestCode = 16 ;
    
    /** RCInBit
    */
    typedef RCBitlDecoder<RCInBuffer> RCInBit ;
    
public:
    
    /** ���ñ��볤��
    @param [in] codeLengths ���볤��
    @return �ɹ�����true,���򷵻�false
    */
    bool SetCodeLengths(const byte_t* codeLengths);
    
    /** ����
    @param [in] inStream ����������
    @return �����ֽ���
    */
    uint32_t DecodeSymbol(RCInBit* inStream);
    
private:
    
    /** m_limitits[i] = value limit for symbols with length = i
    */
    uint32_t m_limitits[s_kNumBitsInLongestCode + 2];
    
    /** m_positions[i] = index in m_symbols[] of first symbol with length = i
    */
    uint32_t m_positions[s_kNumBitsInLongestCode + 2]; 
    
    /** number of symbols in m_symbols
    */
    uint32_t m_numSymbols;
    
    /** symbols: at first with len=1 then 2, ... 15.
    */
    uint32_t* m_symbols;
};

END_NAMESPACE_RCZIP

#endif //__RCImplodeHuffmanDecoder_h_
