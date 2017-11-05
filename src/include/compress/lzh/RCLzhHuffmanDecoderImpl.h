/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhHuffmanDecoderImpl_h_
#define __RCLzhHuffmanDecoderImpl_h_ 1

#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/lzh/RCLzhDecoderDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Lzh Huffman ������ʵ��
*/
template <uint32_t m_NumSymbols>
class RCLzhHuffmanDecoderImpl:
    public RCHuffmanDecoder<RCLzhDecoderDefs::s_kMaxHuffmanLen, m_NumSymbols>
{
public:

    /** ��������
    @param [in] bitStream λ������ 
    */
    template <class TBitDecoder>
    uint32_t Decode(TBitDecoder *bitStream)
    {
        if (m_symbol >= 0)
        {
            return (uint32_t)m_symbol;
        }
        return DecodeSymbol(bitStream);
    }
    
public:

    /** ���� symbol
    @param [in] symbol ���� 
    */
    void SetSymbol(int32_t symbol)
    {
        m_symbol = symbol ;
    }
    
    /** ��ȡ symbol
    @return ���ط���
    */
    int32_t GetSymbol() const
    {
        return m_symbol ;
    }

private:

    /** symbol
    */
    int32_t m_symbol ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhHuffmanDecoderImpl_h_

