/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2ThreadInfo_h_
#define __RCBZip2ThreadInfo_h_ 1

#include "base/RCNonCopyable.h"
#include "compress/bzip2/RCBZip2Defs.h"
#include "thread/RCSynchronization.h"
#include "thread/RCThread.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 Msbf ����
*/
class RCBZip2MsbfEncoderTemp ;

/** BZip2 ������
*/
class RCBZip2Encoder;

/** BZip2�߳���Ϣ
*/
class RCBZip2ThreadInfo:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2ThreadInfo() ;
    
    /** Ĭ����������
    */
    ~RCBZip2ThreadInfo() ;
    
public:
    
    /** �����ڴ�
    @return �ɹ�����true,���򷵻�false
    */
    bool Alloc() ;
    
    /** �ͷ��ڴ�
    */
    void Free() ;
    
    /** �����3
    @param [in] blockSize ���С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult EncodeBlock3(uint32_t blockSize) ;
    
public:
    
    /** ������ָ��
    */
    byte_t* m_block ;
    
    /** �Ż������
    */
    bool m_optimizeNumTables ;
    
    /** ������ָ��
    */
    RCBZip2Encoder* m_encoder ;
    
#ifdef COMPRESS_BZIP2_MT

    /** �߳�ָ��
    */
    RCThreadPtr m_spThread ;
    
    /** ͬ���¼�
    */
    RCAutoResetEvent m_streamWasFinishedEvent ;
    
    /** ͬ���¼�
    */
    RCAutoResetEvent m_waitingWasStartedEvent ;

    /** ͬ���¼�
    */
    RCAutoResetEvent m_canWriteEvent ;
    
    /** ѹ�����С
    */
    uint64_t m_packSize ;
    
    /** mt Pad
    */
    byte_t m_mtPad[1 << 8] ; // It's pad for Multi-Threading. Must be >= Cache_Line_Size.
    
    /** ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Create() ;
    
    /** �ͷ���
    @param [in] needLeave �Ƿ��뿪
    */
    void FinishStream(bool needLeave) ;
    
    /** �̺߳���
    */
    void ThreadFunc() ;
    
#endif

private:
    
    /** д����λ
    @param [in] value ��ֵ
    @param [in] numBits λ��
    */
    void WriteBits2(uint32_t value, uint32_t numBits) ;
    
    /** д�ֽ�2
    @param [in] b д���ֽ�
    */
    void WriteByte2(byte_t b);
    
    /** дλ����2
    @param [in] v
    */
    void WriteBit2(bool v) ;
    
    /** дCRCУ��
    @param [in] v У��ֵ
    */
    void WriteCRC2(uint32_t v) ;
    
    /** �����
    @param [in] block ������
    @param [in] blockSize ���С
    */
    void EncodeBlock(const byte_t* block, uint32_t blockSize) ;
    
    /** ��ͷ�����
    @param [in] block ������
    @param [in] blockSize ���С
    @return ���ر�����ֽ���
    */
    uint32_t EncodeBlockWithHeaders(const byte_t* block, uint32_t blockSize) ;
    
    /** �����2
    @param [in] block ������
    @param [in] blockSize ���С
    @param [in] numPasses ���Դ�С
    */
    void EncodeBlock2(const byte_t* block, uint32_t blockSize, uint32_t numPasses) ;
    
private:
    
    /** mt ����
    */
    byte_t* m_mtfArray;
    
    /** ��ʱ����
    */
    byte_t* m_tempArray;
    
    /** ���������
    */
    uint32_t* m_blockSorterIndex;
    
    /** ��ǰ�����
    */
    RCBZip2MsbfEncoderTemp* m_outStreamCurrent;
    
    /** ����
    */
    byte_t m_lens[RCBZip2Defs::s_kNumTablesMax][RCBZip2Defs::s_kMaxAlphaSize];
        
    /** Ƶ��
    */
    uint32_t m_freqs[RCBZip2Defs::s_kNumTablesMax][RCBZip2Defs::s_kMaxAlphaSize];
        
    /** ����
    */
    uint32_t m_codes[RCBZip2Defs::s_kNumTablesMax][RCBZip2Defs::s_kMaxAlphaSize];
        
    /** ѡ����
    */
    byte_t m_selectors[RCBZip2Defs::s_kNumSelectorsMax];
        
    /** CRCУ��
    */
    uint32_t m_crcs[1 << RCBZip2Defs::s_kNumPassesMax];
    
    /** CRC����
    */
    uint32_t m_numCrcs;
    
    /** ����
    */
    uint32_t m_blockIndex;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2ThreadInfo_h_
