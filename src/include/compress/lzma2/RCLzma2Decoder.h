/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzma2Decoder_h_
#define __RCLzma2Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "algorithm/Lzma2Dec.h"

BEGIN_NAMESPACE_RCZIP

/** Lzma2 ������
*/
class RCLzma2Decoder:
    public IUnknownImpl6<ICompressCoder,
                         ICompressSetDecoderProperties2,
                         ICompressGetInStreamProcessedSize,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ISequentialInStream>
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCLzma2Decoder();

    /** Ĭ����������
    */
    virtual ~RCLzma2Decoder();

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

private:
    
    /** �����ڴ�
    @param [in] p ָ��
    @param [in] size ��С
    @return ���������ڴ�ָ��
    */
    static void* SzAlloc(void* p, size_t size) ;
    
    /** �ͷ��ڴ�
    @param [in] p ָ��
    @param [in] address �ڴ��ַ
    */
    static void SzFree(void* p, void* address) ;
    
    /** Res ת HResult
    @param [in] res Resֵ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult SResToHRESULT(result_t res) ;

private:
    
    /** �ڴ�����
    */
    static ISzAlloc s_alloc ;

private:
    
    /** ������
    */
    ISequentialInStreamPtr m_inStream;
    
    /** ���뻺��
    */
    byte_t* m_inBuf;
    
    /** ����λ��
    */
    uint32_t m_inPos;
    
    /** �����С
    */
    uint32_t m_inSize;
    
    /** ״̬
    */
    CLzma2Dec m_state;
    
    /** �Ƿ��������С
    */
    bool m_outSizeDefined;
    
    /** �����С
    */
    uint64_t m_outSize;
    
    /** �Ѵ��������С
    */
    uint64_t m_inSizeProcessed;
    
    /** �Ѵ��������С
    */
    uint64_t m_outSizeProcessed;

};

END_NAMESPACE_RCZIP

#endif //__RCLzma2Decoder_h_
