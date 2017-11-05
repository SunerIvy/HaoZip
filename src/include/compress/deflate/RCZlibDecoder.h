/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZlibDecoder_h_
#define __RCZlibDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCZlibOutStreamWithAdler ;
class RCDeflateCOMDecoder ;

/** Zlib ������
*/
class RCZlibDecoder:
    public IUnknownImpl<ICompressCoder>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZlibDecoder() ;
    
    /** Ĭ����������
    */
    ~RCZlibDecoder() ;
    
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

    /** ��ȡ���봦����ֽڴ�С
    @return ���ش�����ֽڴ�С
    */
    uint64_t GetInputProcessedSize() const ;
    
private:
    
    /** Zlib �����
    */
    RCZlibOutStreamWithAdler* m_adlerSpec;
    
    /** ���л������
    */
    ISequentialOutStreamPtr m_spAdlerStream;  
    
    /** Deflate ������
    */
    RCDeflateCOMDecoder* m_deflateDecoderSpec;
    
    /** Deflate ������
    */
    ICompressCoderPtr m_spDeflateDecoder;
};

END_NAMESPACE_RCZIP

#endif //__RCZlibDecoder_h_
