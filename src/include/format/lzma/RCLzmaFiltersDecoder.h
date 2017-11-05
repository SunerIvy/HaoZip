/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzmaFiltersDecoder_h_
#define __RCLzmaFiltersDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "format/lzma/RCLzmaHeader.h"

BEGIN_NAMESPACE_RCZIP

class RCLzmaFiltersDecoder
{
public:
    
    /** �������������
    @param [in] compressCodecsInfo ���������ָ��
    @param [in] filteredMode �Ƿ��ǹ���ģʽ
    @param [in] inStream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Create(ICompressCodecsInfo* compressCodecsInfo, 
                   bool filteredMode , 
                   ISequentialInStream* inStream) ;
    

    /** ����
    @param [in] header ͷ������
    @param [in] outStream �����
    @param [in] progress ѹ��������Ϣָ��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Code(const RCLzmaHeader& header,
                 ISequentialOutStream* outStream, 
                 ICompressProgressInfo* progress) ;

    
    /** ��ȡ��������������ݴ�С
    @return ������������������ݴ�С
    */
    uint64_t GetInputProcessedSize() const ;
    
    /** �ͷ�������
    */
    void ReleaseInStream() ;
    
    /** ��ȡ����
    @param [in] data ��Ŷ�ȡ����Ļ�������ַ
    @param [in] size �������Ĵ�С
    @param [in] processedSize ����ʵ�ʶ����Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadInput(byte_t* data, uint32_t size, uint32_t* processedSize) ;
    
private:

    /** lzma������
    */
    ILzmaResumeDecoderPtr m_lzmaDecoderSpec ;

    /** lzma������
    */
    ICompressCoderPtr m_lzmaDecoder ;

    /** �����
    */
    ISequentialOutStreamPtr m_bcjStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzmaFiltersDecoder_h_
