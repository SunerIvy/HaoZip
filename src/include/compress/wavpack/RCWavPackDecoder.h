/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWavPackDecoder_h
#define __RCWavPackDecoder_h 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** WavPack ������
*/
class RCWavPackDecoder :
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetDecoderProperties2>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWavPackDecoder();

    /** Ĭ����������
    */
    ~RCWavPackDecoder();

public:

    /** ����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �����С
    @param [in] progress ��ѹ�ص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ; 

    /** ���ý���������
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;   
};

END_NAMESPACE_RCZIP

#endif //__RCWavPackDecoder_h
