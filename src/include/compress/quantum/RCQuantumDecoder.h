/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCQuantumDecoder_h_
#define __RCQuantumDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "compress/quantum/RCQuantumRangeDecoder.h"
#include "compress/quantum/RCQuantumModelDecoder.h"
#include "compress/quantum/RCQuantumDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Quantum ������
*/
class RCQuantumDecoder:
    public IUnknownImpl4<ICompressCoder,
                         ICompressSetInStream,
                         ICompressSetOutStreamSize,
                         ICompressSetCoderProperties
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCQuantumDecoder() ;
    
    /** Ĭ����������
    */
    ~RCQuantumDecoder() ;
    
public:

    /**
    */
    void Init() ;

    /**
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult CodeSpec(uint32_t size) ;

    /**
    */
    void ReleaseStreams() ;

    /**
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
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
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

    /** ���ò���
    @param [in] numDictBits �ֵ�λ��
    */
    void SetParams(int32_t numDictBits) ;

    /** �����Ƿ�����ʷ
    @param [in] keepHistory �Ƿ�����ʷ
    */
    void SetKeepHistory(bool keepHistory) ;
        
private:

    /** �����
    */
    RCLZOutWindow m_outWindowStream;

    /** Range������
    */
    RCQuantumRangeDecoder m_rangeDecoder;

    /** �����С
    */
    uint64_t m_outSize;

    /** ��������
    */
    int32_t m_remainLen; // -1 means end of stream. // -2 means need Init

    /** �ظ�0
    */
    uint32_t m_rep0;

    /** �ֵ�λ��
    */
    int32_t m_numDictBits;

    /** �ֵ��С
    */
    uint32_t m_dictionarySize;

    /** ������
    */
    RCQuantumModelDecoder m_selector ;

    /** ������
    */
    RCQuantumModelDecoder m_literals[RCQuantumDefs::s_kNumLitSelectors] ;

    /** ������
    */
    RCQuantumModelDecoder m_posSlot[RCQuantumDefs::s_kNumMatchSelectors] ;

    /** ������
    */
    RCQuantumModelDecoder m_lenSlot ;

    /** �Ƿ�����ʷ
    */
    bool m_keepHistory ;
};

END_NAMESPACE_RCZIP

#endif //__RCQuantumDecoder_h_
