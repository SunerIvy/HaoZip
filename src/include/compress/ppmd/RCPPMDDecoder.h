/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDDecoder_h_
#define __RCPPMDDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCOutBuffer.h"
#include "compress/ppmd/RCPPMDRangeDecoder.h"
#include "compress/ppmd/RCPPMDDecodeInfo.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ������
*/
class RCPPMDDecoder:
    public IUnknownImpl5<ICompressCoder,
                         ICompressSetDecoderProperties2,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ISequentialInStream
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDDecoder() ;
    
    /** Ĭ����������
    */
    ~RCPPMDDecoder() ;
    
public:
    
    /** �ͷ���
    */
    void ReleaseStreams() ;
    
    /** Flush ����
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
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
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
    
    /** ����
    @param [in] size ��С
    @param [in] memStream �ڴ�������
    @return �ɹ�����RC_S_OK,���򷵻ش���� 
    */
    HResult CodeSpec(uint32_t size, byte_t* memStream) ;
    
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
    
    /** ������
    */
    RCPPMDRangeDecoder m_rangeDecoder ;
    
    /** �����
    */
    RCOutBuffer m_outStream ;
    
    /** ��Ϣ
    */
    RCPPMDDecodeInfo m_info ;
    
    /** ˳��
    */
    byte_t m_order ;
    
    /** ʹ���ڴ��С
    */
    uint32_t m_usedMemorySize ;
    
    /** ��������
    */
    int32_t m_remainLen ;
    
    /** �����С
    */
    uint64_t m_outSize ;
    
    /** �����С�Ƿ���
    */
    bool m_outSizeDefined ;
    
    /** �Ѿ������С
    */
    uint64_t m_processedSize ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDDecoder_h_
