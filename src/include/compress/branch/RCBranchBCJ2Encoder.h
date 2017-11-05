/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchBCJ2Encoder_h_
#define __RCBranchBCJ2Encoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/range/RCRangeEncoder.h"
#include "compress/range/RCRangeBitEncoder.h"
#include "compress/branch/RCBranchBCJ2Defs.h"

BEGIN_NAMESPACE_RCZIP

/** BCJ2 ������
*/
class RCBranchBCJ2Encoder:
    public IUnknownImpl<ICompressCoder2>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBranchBCJ2Encoder() ;
    
    /** Ĭ����������
    */
    ~RCBranchBCJ2Encoder() ;

public:
    
    /** ���ļ���
    */
    RCOutBuffer m_mainStream ;
    
    /** ����
    */
    RCOutBuffer m_callStream ;
    
    /** ��ת
    */
    RCOutBuffer m_jumpStream ;
    
    /** ���б�����
    */
    RCRangeEncoder m_rangeEncoder ;
    
    /** ����״̬
    */
    RCRangeBitEncoder<s_kNumMoveBits> m_statusEncoder[256 + 2] ;
    
public:
    
    /** ����
    */
    bool Create() ;
    
    /** Flush
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** �ͷ���
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
    
    /** ����
    */
    byte_t* m_buffer ;
};

END_NAMESPACE_RCZIP

#endif //__RCBranchBCJ2Encoder_h_
