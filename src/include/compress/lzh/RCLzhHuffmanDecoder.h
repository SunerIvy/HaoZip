/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhHuffmanDecoder_h_
#define __RCLzhHuffmanDecoder_h_ 1

#include "compress/lzh/RCLzhHuffmanDecoderImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBitmDecoder.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Lzh Huffman ������
*/
class RCLzhHuffmanDecoder:
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetCoderProperties>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzhHuffmanDecoder() ;
    
    /** Ĭ����������
    */
    ~RCLzhHuffmanDecoder() ;
    
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
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
private:

    /** �ͷ���
    */
    void ReleaseStreams() ;

    /** ��ȡλ����
    @param [in] numBits λ��
    @return ���ض�ȡλ��
    */
    uint32_t ReadBits(int32_t numBits) ;

    /** ��ȡ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadLevelTable() ;

    /** ��ȡP��
    @param [in] numBits λ�� 
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadPTable(int32_t numBits) ;

    /** ��ȡC��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult ReadCTable() ;
    
    /** �����ֵ��С
    @param [in] numDictBits �ֵ�λ�� 
    */
    void SetDictionary(int32_t numDictBits) ;

private:
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @throws ʧ�����쳣
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeReal(ISequentialInStream* inStream,
                             ISequentialOutStream* outStream, 
                             const uint64_t* inSize, 
                             const uint64_t* outSize,
                             ICompressProgressInfo* progress) ;

private:

    /** �������ͷ�
    */
    class CCoderReleaser
    {
    public:

        /** �Ƿ���ҪFlush
        */
        bool m_needFlush ;

        /** ���캯��
        @param [in] coder ������ָ�� 
        */
        CCoderReleaser(RCLzhHuffmanDecoder* coder) ;

        /** ��������
        */
        ~CCoderReleaser() ;

    private:

        /** ������ָ��
        */
        RCLzhHuffmanDecoder* m_coder;
    }; 

    friend class CCoderReleaser ;
    
private:

    /** �ֵ��С
    */
    int32_t m_numDictBits ;

    /** �����
    */
    RCLZOutWindow m_outWindowStream ;

    /** λ������
    */
    RCBitmDecoder<RCInBuffer> m_inBitStream ;    

    /** ������ʵ��
    */
    RCLzhHuffmanDecoderImpl<RCLzhDecoderDefs::s_kNumLevelSymbols> m_levelHuffman ;

    /** ������ʵ��
    */
    RCLzhHuffmanDecoderImpl<RCLzhDecoderDefs::s_kNumDistanceSymbols> m_pHuffmanDecoder ;

    /** ������ʵ��
    */
    RCLzhHuffmanDecoderImpl<RCLzhDecoderDefs::s_kNumCSymbols> m_cHuffmanDecoder ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhHuffmanDecoder_h_

