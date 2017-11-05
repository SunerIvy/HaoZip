/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzmaDecoder_h_
#define __RCLzmaDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "algorithm/LzmaDec.h"

BEGIN_NAMESPACE_RCZIP

/** Lzam ������
*/
class RCLzmaDecoder:
    public IUnknownImpl7<ICompressCoder,
                         ICompressSetDecoderProperties2,
                         ICompressGetInStreamProcessedSize,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ISequentialInStream,
                         ILzmaResumeDecoder>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzmaDecoder() ;
    
    /** Ĭ����������
    */
    ~RCLzmaDecoder() ;
    
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
    
    /** ����ӿ�
    @param [in] outStream ������ӿ�
    @param [in] outSize ����������ݴ�С
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, 
                               const uint64_t* outSize, 
                               ICompressProgressInfo* progress) ;                       
    
    /** ���������ж�ȡ����
    @param [in] data ���ݻ�����
    @param [in] size �������ĳ���
    @param [out] processedSize ʵ�ʶ�ȡ�ĳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ReadFromInputStream(void* data, uint32_t size, uint32_t* processedSize) ;

private:
    
    /** �������뻺��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CreateInputBuffer();

    /** ��/����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeSpec(ISequentialInStream* inStream, ISequentialOutStream* outStream, ICompressProgressInfo* progress);

    /** ���������������С
    @param [in] outSize ��С 
    */
    void SetOutStreamSizeResume(const uint64_t* outSize);

private:

    /** �����ڴ�
    @param [in,out] p ָ��
    @param [in] size �ڴ��С
    @return ����������ڴ��ַ
    */
    static void* SzAlloc(void* p, size_t size) ;

    /** �ͷ��ڴ�
    @param [in] p ָ�� 
    @param [in] address �ڴ��ַ
    */
    static void SzFree(void* p, void* address) ;

    /** �ڴ�����
    */
    static ISzAlloc s_alloc ;

    /** ת��Res��HResult
    @param [in] res Resֵ
    @return ����HResultֵ
    */
    static HResult SResToHRESULT(result_t res) ;
    
private:

    /** ������
    */
    ISequentialInStreamPtr m_inStream ;

    /** ���뻺��
    */
    byte_t* m_inBuf ;

    /** ����λ��
    */
    uint32_t m_inPos ;

    /** �����ֽ���
    */
    uint32_t m_inSize ;

    /** ״̬
    */
    CLzmaDec m_state ;

    /** �����С�Ƿ���
    */
    bool m_outSizeDefined ;

    /** �����С
    */
    uint64_t m_outSize ;

    /** �Ѵ��������С
    */
    uint64_t m_inSizeProcessed ;

    /** �Ѿ����������С
    */
    uint64_t m_outSizeProcessed ;

    /** �Ƿ���������
    */
    bool m_propsWereSet ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzmaDecoder_h_

