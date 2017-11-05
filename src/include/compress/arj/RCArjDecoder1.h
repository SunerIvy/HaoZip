/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArjDecoder1_h_
#define __RCArjDecoder1_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/lz/RCLZOutWindow.h"
#include "common/RCBitmDecoder.h"
#include "common/RCInBuffer.h"

BEGIN_NAMESPACE_RCZIP

#define CODE_BIT    16

#define THRESHOLD   3
#define DDICSIZ     26624
#define MAXDICBIT   16
#define MATCHBIT    8
#define MAXMATCH    256
#define NC          (0xFF + MAXMATCH + 2 - THRESHOLD)
#define NP          (MAXDICBIT + 1)
#define CBIT        9
#define NT          (CODE_BIT + 3)
#define PBIT        5
#define TBIT        5

#if NT > NP
#define NPT NT
#else
#define NPT NP
#endif

#define CTABLESIZE  4096
#define PTABLESIZE  256

/** Arj ��ʽ����1
*/
class RCArjDecoder1:
    public IUnknownImpl<ICompressCoder>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArjDecoder1() ;
    
    /** Ĭ����������
    */
    ~RCArjDecoder1() ;

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
    
    /** �ͷ��ļ���
    */
    void ReleaseStreams() ;
    
    /** ���ɱ�
    @param [in] nchar 
    @param [in] bitLen
    @param [in] tableBits
    @param [in] table
    @param [in] tableSize
    */
    void MakeTable( int32_t nchar, 
                    byte_t* bitLen, 
                    int32_t tableBits, 
                    uint32_t* table, 
                    int32_t tableSize);
  
    /** ��ȡC_Len
    */
    void ReadCLen();
    
    /** ��ȡPt_Len
    @param [in] nn
    @param [in] nbit
    @param [in] iSpecial
    */
    void ReadPtLen(int32_t nn, int32_t nbit, int32_t iSpecial) ;
    
    /** ����
    @return
    */
    uint32_t DecodeC() ;
    
    /** ����
    @return
    */
    uint32_t DecodeP() ;
    
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
    
    /** �������
    */
    class CCoderReleaser
    {
    public:
        
        /** �Ƿ���Ҫflush
        */
        bool m_needFlush ;
        
        /** ���캯��
        @param [in] coder ������ָ��
        */
        CCoderReleaser(RCArjDecoder1* coder) ;
        
        /** Ĭ����������
        */
        ~CCoderReleaser() ;
        
    private:
        
        /** ������ָ��
        */
        RCArjDecoder1* m_coder;
    }; 
    
    /** ��Ԫ����
    */
    friend class CCoderReleaser ;
    
private:
    
    /** �����
    */
    RCLZOutWindow m_outWindowStream ;
    
    /** ����������
    */
    RCBitmDecoder<RCInBuffer> m_inBitStream;

    /** left����
    */
    uint32_t m_left[2 * NC - 1];
    
    /** right����
    */
    uint32_t m_right[2 * NC - 1];
    
    /** C_Len����
    */
    byte_t m_cLen[NC];
    
    /** Pt_Len����
    */
    byte_t m_ptLen[NPT];

    /** C_Table
    */
    uint32_t m_cTable[CTABLESIZE];
    
    /** Pt_Table
    */
    uint32_t m_ptTable[PTABLESIZE];
};

END_NAMESPACE_RCZIP

#endif //__RCArjDecoder1_h_
