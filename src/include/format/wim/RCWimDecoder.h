/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimDecoder_h_
#define __RCWimDecoder_h_ 1

#include "format/wim/RCWimBitStream.h"
#include "compress/lz/RCLZOutWindow.h"
#include "compress/huffman/RCHuffmanDecoder.h"

BEGIN_NAMESPACE_RCZIP

/** Wim ����
*/
class RCWimDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimDecoder() ;
    
    /** Ĭ����������
    */
    ~RCWimDecoder() ;

public:

    /** �ͷ���
    */
    void ReleaseStreams() ;

    /** Flush����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Flush() ;

    /** ����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] outSize �����С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Code(ISequentialInStream* inStream, ISequentialOutStream* outStream, uint32_t outSize) ;

private:

    /** ����
    @param [in] size �����С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CodeSpec(uint32_t size) ;

    /** ����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] outSize ��������С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CodeReal(ISequentialInStream* inStream, ISequentialOutStream* outStream, uint32_t outSize); 
       
private:

    /** Huffman Bits
    */
    static const int32_t s_kWimNumHuffmanBits = 16;

    /** Match Min Length
    */
    static const uint32_t s_kWimMatchMinLen = 3;

    /** Slots Length
    */
    static const uint32_t s_kWimNumLenSlots = 16;

    /** Pos Slots Number
    */
    static const uint32_t s_kWimNumPosSlots = 16;

    /** Pos Length Slots Number
    */
    static const uint32_t s_kWimNumPosLenSlots = s_kWimNumPosSlots * s_kWimNumLenSlots;

    /** Main Table Size
    */
    static const uint32_t s_kWimMainTableSize = 256 + s_kWimNumPosLenSlots;
    
    /** Dict Size
    */
    static const uint32_t s_kWimDictSize = (1 << s_kWimNumPosSlots);
    
private:

    /** ������
    */
    RCWimBitStream m_inBitStream ;

    /** �����
    */
    RCLZOutWindow  m_outWindowStream ;

    /** ������
    */
    RCHuffmanDecoder<s_kWimNumHuffmanBits, s_kWimMainTableSize> m_mainDecoder ;
};

END_NAMESPACE_RCZIP

#endif //__RCWimDecoder_h_
