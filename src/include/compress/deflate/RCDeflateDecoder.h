/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateDecoder_h_
#define __RCDeflateDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "common/RCInBuffer.h"
#include "common/RCBitlDecoder.h"
#include "compress/huffman/RCHuffmanDecoder.h"
#include "compress/deflate/RCDeflateDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate ������
*/
class RCDeflateDecoder:
    public IUnknownImpl7<ICompressCoder,
                         ICompressGetInStreamProcessedSize,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ISequentialInStream,
                         ICompressSetCoderProperties,
                         IGZipResumeDecoder
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    explicit RCDeflateDecoder(bool deflate64Mode, bool deflateNSIS = false) ;
    
    /** Ĭ����������
    */
    virtual ~RCDeflateDecoder() ;
    
public:
    
    /** �ͷ������
    */
    void ReleaseOutStream() ;
    
    /** ˢ�»�������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
        
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

    /** ��ȡ��������ȡ�����ݳ���
    @param [out] size �������ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetInStreamProcessedSize(uint64_t& size) ;

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
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;

public:
    
    /** ��ѹ����
    @param [in] outStream  �����
    @param [in] outSize �������С
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, const uint64_t* outSize, ICompressProgressInfo* progress);
    
    /** ��ʼ��������
    @param [in] needInit �Ƿ���Ҫ��ʼ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult InitInStream(bool needInit) ;
    
    /** ���䵽�ֽ�
    */
    virtual void AlignToByte() ;
    
    /** ��ȡ�ֽ�
    @return �����ֽ�
    */
    virtual byte_t ReadByte() ;
    
    /** �Ƿ��Ѿ���ȡ��������Ľ���λ��
    @return �����Ƿ��Ѿ���ȡ��������Ľ���λ��,�Ƿ���true,���򷵻�false
    */
    virtual bool InputEofError() const ;
    
    /** ��ȡ�������Ѵ���Ĵ�С
    @return �����������Ѵ���Ĵ�С
    */
    virtual uint64_t GetInputProcessedSize() const ;
               
public:
    
    /** �Ƿ�zlibģʽ
    */
    bool m_zlibMode ;
    
    /** zlib Footer
    */
    byte_t m_zlibFooter[4] ;
    
private:
    
    /** ���ñ�����ʷ
    @param [in] keepHistory ������ʷ
    */
    void SetKeepHistory(bool keepHistory) ;
    
    /** ��ȡ����λ
    @param [in] numBits λ��
    @return ���ض�ȡλ��
    */
    uint32_t ReadBits(int32_t numBits) ;
    
    /** �����
    @param [in] values ����ָ��
    @param [in] numSymbols ������
    @return �ɹ�����true,���򷵻�false
    */
    bool DeCodeLevelTable(byte_t* values, int32_t numSymbols);
    
    /** ȡ�ý����
    @return �ɹ�����true,���򷵻�false
    */
    bool ReadTables() ;    
    
    /** ����
    @param [in] curSize ��ǰ��С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeSpec(uint32_t curSize) ;
    
    /** ����ʵ�ֺ���
    @param [in] outStream �����
    @param [in] outSize �����С
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeRealImpl(ISequentialOutStream* outStream, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ;
    
    /** ����ʵ�ֺ���
    @param [in] outStream �����
    @param [in] outSize �����С
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */                 
    HResult CodeReal(ISequentialOutStream* outStream, 
                     const uint64_t* outSize,
                     ICompressProgressInfo* progress) ;
    
private:
    
    /** ���������
    */
    RCLZOutWindow m_outWindowStream;
    
    /** ����������
    */
    RCBitlDecoder<RCInBuffer> m_inBitStream;
    
    /** Huffman ������
    */
    RCHuffmanDecoder<RCDeflateDefs::s_kNumHuffmanBits, RCDeflateDefs::s_kFixedMainTableSize> m_mainDecoder;
        
    /** Huffman ������
    */
    RCHuffmanDecoder<RCDeflateDefs::s_kNumHuffmanBits, RCDeflateDefs::s_kFixedDistTableSize> m_distDecoder;
        
    /** Huffman ������
    */
    RCHuffmanDecoder<RCDeflateDefs::s_kNumHuffmanBits, RCDeflateDefs::s_kLevelTableSize> m_levelDecoder;
    
    /** ������С
    */
    uint32_t m_storedBlockSize;
    
    /** �Ƿ����տ�
    */
    bool m_finalBlock;
    
    /** �Ƿ�洢ģʽ
    */
    bool m_storedMode;
    
    /** ����
    */
    uint32_t m_numDistLevels;
    
    /** �Ƿ�Deflate NSIS
    */
    bool m_deflateNSIS;
    
    /** �Ƿ�Deflate 64
    */
    bool m_deflate64Mode;
    
    /** �Ƿ񱣴���ʷ
    */
    bool m_keepHistory;
    
    /** �Ƿ��ʼ��������
    */
    bool m_needInitInStream ;
    
    /** ʣ�೤��
    */
    int32_t m_remainLen;
    
    /** rep0
    */
    uint32_t m_rep0;
    
    /** �Ƿ���Ҫ��ȡ��
    */
    bool m_needReadTable;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateDecoder_h_
