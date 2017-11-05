/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCHuffmanDecoder_h_
#define __RCHuffmanDecoder_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** Huffman ����
*/
template <int32_t kNumBitsMax, uint32_t m_NumSymbols>
class RCHuffmanDecoder:
    private RCNonCopyable
{
public:
    
    /** λ�ĳ���
    */
    static const int32_t s_kNumTableBits = 9 ;
    
public:
    
    /** ����code����
    @param [in] codeLengths �������飬���鳤������Ϊm_NumSymbols
    @return �ɹ�����true�����򷵻�false
    */
    bool SetCodeLengths(const byte_t* codeLengths) ;
    
    /** ����
    @param [in] bitStream ������
    @return
    */
    template <class TBitDecoder>
    uint32_t DecodeSymbol(TBitDecoder* bitStream)
    {
        RCZIP_ASSERT(bitStream != NULL ) ;
        int32_t numBits = 0 ;
        uint32_t value = bitStream->GetValue(kNumBitsMax);
        if (value < m_limits[s_kNumTableBits])
        {
            numBits = m_lengths[value >> (kNumBitsMax - s_kNumTableBits)];
        }
        else
        {
            for (numBits = s_kNumTableBits + 1; value >= m_limits[numBits]; numBits++)
            {
            }
        }
        bitStream->MovePos(numBits);
        uint32_t index = m_positions[numBits] +
                         ((value - m_limits[numBits - 1]) >> (kNumBitsMax - numBits)) ;
        if (index >= m_NumSymbols)
        {
            return 0xFFFFFFFF;
        }
        return m_symbols[index] ;
    }
    
private:
    
    /** m_limits[i] = value limit for symbols with length = i
    */
    uint32_t m_limits[kNumBitsMax + 1];
    
    /** m_positions[i] = index in m_symbols[] of first symbol with length = i
    */
    uint32_t m_positions[kNumBitsMax + 1];
    
    /** symbol value
    */
    uint32_t m_symbols[m_NumSymbols];
    
    /** Table oh length for short codes.
    */
    byte_t m_lengths[1 << s_kNumTableBits];
};

END_NAMESPACE_RCZIP

#include "RCHuffmanDecoder.inl"

#endif //__RCHuffmanDecoder_h_
