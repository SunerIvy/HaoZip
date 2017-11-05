/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArjDecoder2_h_
#define __RCArjDecoder2_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "common/RCBitmDecoder.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Arj ��ʽ����2
*/
class RCArjDecoder2:
    public IUnknownImpl<ICompressCoder>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArjDecoder2() ;
    
    /** Ĭ����������
    */
    ~RCArjDecoder2() ;

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

private:
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @throws ʧ�����쳣
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeReal(ISequentialInStream* inStream,
                             ISequentialOutStream* outStream, 
                             const uint64_t* inSize, 
                             const uint64_t* outSize,
                             ICompressProgressInfo* progress) ;
                             
private:
    
    /** �ͷ���
    */
    void ReleaseStreams() ;

private:
    
    /** �������
    */
    class CCoderReleaser
    {
    public:
        
        /** �Ƿ���Ҫflush
        */
        bool m_needFlush ;
        
        /** ���캯��
        @param [in] coder Arj ������ָ��
        */
        CCoderReleaser(RCArjDecoder2* coder) ;
        
        /** Ĭ����������
        */
        ~CCoderReleaser() ;
        
    private:
        
        /** Arj ������2ָ��
        */
        RCArjDecoder2* m_coder;
    }; 
    
    friend class CCoderReleaser ;
       
private:
    
    /** �����
    */
    RCLZOutWindow m_outWindowStream;
    
    /** ������
    */
    RCBitmDecoder<RCInBuffer> m_inBitStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCArjDecoder2_h_
