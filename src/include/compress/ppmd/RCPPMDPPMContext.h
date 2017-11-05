/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDPPMContext_h_
#define __RCPPMDPPMContext_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** �ڴ����
*/
class RCPPMDSubAlloc ;

/** PPMD ����������
*/
class RCPPMDPPMContext
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDPPMContext() ;
    
    /** Ĭ����������
    */
    ~RCPPMDPPMContext() ;
    
public:

    /** ״̬��
    */
    uint16_t m_numStats ; // sizeof(uint16_t) > sizeof(byte_t)

    /** Ƶ��
    */
    uint16_t m_summFreq ;

    /** ״̬
    */
    uint32_t m_stats;

    /** ��׺
    */
    uint32_t m_suffix;

public:

    /** ״̬
    */
    class TState
    {
    public:

        /** ����
        */
        byte_t m_symbol ;

        /** Ƶ��
        */
        byte_t m_freq ;

        /** ��̵���
        */
        uint16_t m_successorLow ;

        /** ��̸���
        */
        uint16_t m_successorHigh ;

    public:

        /** ���캯��
        */
        TState() ;

        /** ���غ��
        @return ���غ��
        */
        uint32_t GetSuccessor() const ;

        /** ���ú��
        @param [in] v �����ֵ
        */
        void SetSuccessor(uint32_t v) ;
    };

public:

    /** ��������
    @param [in] subAllocator ������
    @param [in] pStats ��״̬
    @param [out] FirstState ��һ��״̬
    @return ���ش�����������
    */
    RCPPMDPPMContext* CreateChild(RCPPMDSubAlloc& subAllocator, TState* pStats, TState& FirstState) ;

    /** ״̬����
    @return ����״̬
    */
    TState& OneState() const ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDPPMContext_h_
