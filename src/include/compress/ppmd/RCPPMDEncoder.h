/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDEncoder_h_
#define __RCPPMDEncoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "common/RCInBuffer.h"
#include "compress/range/RCRangeEncoder.h"
#include "compress/ppmd/RCPPMDEncodeInfo.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ������
*/
class RCPPMDEncoder:
    public IUnknownImpl3<ICompressCoder,
                         ICompressSetCoderProperties,
                         ICompressWriteCoderProperties
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDEncoder() ;
    
    /** Ĭ����������
    */
    ~RCPPMDEncoder() ;
    
public:
    
    /** Flush ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Flush() ;
    
    /** �Ƿ�������
    */
    void ReleaseStreams() ;
    
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

    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) ;
            
private:
    
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
    RCInBuffer m_inStream ;
    
    /** ������
    */
    RCRangeEncoder m_rangeEncoder ;
    
    /** ��Ϣ
    */
    RCPPMDEncodeInfo m_info ;
    
    /** �ڴ��С
    */
    uint32_t m_usedMemorySize ;
    
    /** ˳��
    */
    byte_t m_order ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDEncoder_h_
