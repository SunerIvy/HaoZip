/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2DecoderState_h_
#define __RCBZip2DecoderState_h_ 1

#include "thread/RCSynchronization.h"
#include "thread/RCThread.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2 ������
*/
class RCBZip2Decoder ;

/** BZip2����״̬
*/
class RCBZip2DecoderState
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2DecoderState() ;
    
    /** Ĭ����������
    */
    ~RCBZip2DecoderState() ;
    
public:
    
    /** �ڴ�����
    @return �ɹ�����true,���򷵻�false
    */
    bool Alloc() ;
    
    /** �ڴ��Ƿ�
    */
    void Free() ;

public:
    
    /** ����
    */
    uint32_t* m_counters ;
        
public:

#ifdef COMPRESS_BZIP2_MT

    /** ������ָ��
    */
    RCBZip2Decoder* m_decoder ;
    
    /** �߳�ָ��
    */
    RCThreadPtr m_spThread ;
    
    /** �Ƿ���Ż�
    */
    bool m_optimizeNumTables ;

    /** ͬ���¼�
    */
    RCAutoResetEvent m_streamWasFinishedEvent ;
    
    /** ͬ���¼�
    */
    RCAutoResetEvent m_waitingWasStartedEvent ;

    /** ͬ���¼�
    */
    RCAutoResetEvent m_canWriteEvent ;

    /** mt Pad
    */
    byte_t m_mtPad[1 << 8]; // It's pad for Multi-Threading. Must be >= Cache_Line_Size.

    /** ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Create() ;
    
    /** ���
    */
    void FinishStream() ;
    
    /** �̺߳���
    */
    void ThreadFunc();

#endif //COMPRESS_BZIP2_MT
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2DecoderState_h_
