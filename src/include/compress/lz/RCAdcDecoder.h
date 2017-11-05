/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCAdcDecoder_h_
#define __RCAdcDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Adc ����
*/
class RCAdcDecoder:
    public IUnknownImpl<ICompressCoder>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCAdcDecoder() ;
    
    /** Ĭ����������
    */
    ~RCAdcDecoder() ;
    
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


public:
    
    /** Flush���е�����
    */
    void Flush() ;
    
    /** �ͷ���
    */
    void ReleaseStreams() ;
    
private:
    
    /** ����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �����С
    @param [in] progress ������ʾ�ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeReal(ISequentialInStream* inStream,
                     ISequentialOutStream* outStream, 
                     const uint64_t* inSize, 
                     const uint64_t* outSize,
                     ICompressProgressInfo* progress) ;
    
private:
    
    /** �����
    */
    RCLZOutWindow m_outWindowStream ;
    
    /** ������
    */
    RCInBuffer m_inStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCAdcDecoder_h_
