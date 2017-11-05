/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchBCJ2Decoder_h_
#define __RCBranchBCJ2Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/range/RCRangeDecoder.h"
#include "compress/range/RCRangeBitDecoder.h"
#include "compress/branch/RCBranchBCJ2Defs.h"
#include "common/RCOutBuffer.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** BCJ2 ������
*/
class RCBranchBCJ2Decoder:
    public IUnknownImpl<ICompressCoder2>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBranchBCJ2Decoder() ;
    
    /** Ĭ����������
    */
    ~RCBranchBCJ2Decoder() ;
   
public:
    
    /** Flush
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** �ͷ����ӿ�
    */
    void ReleaseStreams() ;
    
    /** ѹ��/��ѹ����
    @param [in] inStreams ��������Ϣ
    @param [in] outStreams �������Ϣ
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(const std::vector<in_stream_data>& inStreams,
                         const std::vector<out_stream_data>& outStreams, 
                         ICompressProgressInfo* progress) ;

private:
    
    /** ѹ��/��ѹ����
    @param [in] inStreams ��������Ϣ
    @param [in] outStreams �������Ϣ
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeReal(const std::vector<in_stream_data>& inStreams,
                             const std::vector<out_stream_data>& outStreams, 
                             ICompressProgressInfo* progress) ;

private:

    /** ��������
    */
    RCInBuffer m_mainInStream;
    
    /** ����
    */
    RCInBuffer m_callStream;
    
    /** ��ת
    */
    RCInBuffer m_jumpStream;
    
    /** ���н�����
    */
    RCRangeDecoder m_rangeDecoder;
    
    /** ����״̬
    */
    RCRangeBitDecoder<s_kNumMoveBits> m_statusDecoder[256 + 2];

    /** �����
    */
    RCOutBuffer m_outStream;
};

END_NAMESPACE_RCZIP

#endif //__RCBranchBCJ2Decoder_h_
