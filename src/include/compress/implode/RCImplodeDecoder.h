/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCImplodeDecoder_h_
#define __RCImplodeDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/implode/RCImplodeHuffmanDecoder.h"
#include "compress/lz/RCLZOutWindow.h"

BEGIN_NAMESPACE_RCZIP

/** Implode ����
*/
class RCImplodeDecoder:
    public IUnknownImpl3<ICompressCoder,
                         ICompressSetDecoderProperties2,
                         IOutStreamFlush>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCImplodeDecoder() ;
    
    /** Ĭ����������
    */
    ~RCImplodeDecoder() ;

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
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
    /** ��ջ����������ѻ�������д����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Flush() ;
    
    /** �ͷ���
    */
    void ReleaseStreams() ;
    
private:
    
    /** ReadLevelItems
    @param [in] decoder
    @param [in] levels
    @param [in] numLevelItems
    @return 
    */
    bool ReadLevelItems(RCImplodeHuffmanDecoder& decoder, byte_t* levels, int32_t numLevelItems);
    
    /** ReadTables
    @return 
    */
    bool ReadTables();
    
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
    
    /** Bit��
    */
    RCBitlDecoder<RCInBuffer> m_inBitStream ;
      
    /** ������
    */
    RCImplodeHuffmanDecoder m_literalDecoder ;
    
    /** ������
    */
    RCImplodeHuffmanDecoder m_lengthDecoder ;
    
    /** ������
    */
    RCImplodeHuffmanDecoder m_distanceDecoder ;
    
    /** ���ֵ��Ƿ�����
    */
    bool m_bigDictionaryOn ;
    
    /** �ַ��Ƿ�����
    */
    bool m_literalsOn ;
    
    /** �ֵ�λ��
    */
    int32_t m_numDistanceLowDirectBits ;
    
    /** ��Сƥ�䳤��
    */
    uint32_t m_minMatchLength ;
};

END_NAMESPACE_RCZIP

#endif //__RCImplodeDecoder_h_
