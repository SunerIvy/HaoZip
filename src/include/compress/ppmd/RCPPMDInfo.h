/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDInfo_h_
#define __RCPPMDInfo_h_ 1

#include "compress/ppmd/RCPPMDSubAlloc.h"
#include "compress/ppmd/RCPPMDSEE2Context.h"
#include "compress/ppmd/RCPPMDPPMContext.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD ��Ϣ
*/
class RCPPMDInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDInfo() ;
    
    /** Ĭ����������
    */
    ~RCPPMDInfo() ;
    
public:

    /** ȡ��λ�ܼ�
    @param [in] rs ״̬
    @param [in] numStates ״̬����
    */
    uint16_t& GetBinSumm(const RCPPMDPPMContext::TState& rs, int32_t numStates) ;

    /** ����������
    @param [in] offset ƫ����
    @return ����������
    */
    RCPPMDPPMContext* GetContext(uint32_t offset) const ;

    /** ����������
    @param [in] offset ƫ����
    @return ����������
    */
    RCPPMDPPMContext* GetContextNoCheck(uint32_t offset) const ;

    /** ����״̬
    @param [in] offset ƫ����
    @return ����״̬
    */
    RCPPMDPPMContext::TState* GetState(uint32_t offset) const ;

    /** ����״̬
    @param [in] offset ƫ����
    @return ����״̬
    */
    RCPPMDPPMContext::TState* GetStateNoCheck(uint32_t offset) const ;

    /** �ع�ģ��
    */
    void RestartModelRare() ;

    /** ��ʼ����ģ��
    @param [in] maxOrder ���˳��
    */
    void StartModelRare(int32_t maxOrder) ;

    /** ����������
    @param [in] skip �Ƿ�����
    @param [in] p1 ����
    @return ����������
    */
    RCPPMDPPMContext* CreateSuccessors(bool skip, RCPPMDPPMContext::TState* p1) ;

    /** ����ģ��
    */
    void UpdateModel() ;

    /** �������
    */
    void ClearMask() ;

    /** ����1
    @param [in] p ״̬
    */
    void update1(RCPPMDPPMContext::TState* p) ;

    /** ����2
    @param [in] p ״̬
    */
    void update2(RCPPMDPPMContext::TState* p) ;

    /** ����������
    @param [in] Diff ����
    @param [in] scale �߶�
    @return ����������
    */
    RCPPMDSEE2Context* makeEscFreq2(int32_t Diff, uint32_t &scale) ;

    /** ���¼���
    */
    void rescale() ;

    /** ��һ������
    */
    void NextContext() ;
       
public:

    /** �ڴ����
    */
    RCPPMDSubAlloc m_subAllocator ;

    /** ������
    */
    RCPPMDSEE2Context m_SEE2Cont[25][16] ;

    /** α������
    */
    RCPPMDSEE2Context m_dummySEE2Cont ;

    /** ��С������
    */
    RCPPMDPPMContext* m_minContext ;

    /** ���������
    */
    RCPPMDPPMContext* m_maxContext ;

    /** found next state transition
    */
    RCPPMDPPMContext::TState* m_foundState ; 

    /** ������
    */
    int32_t m_numMasked ;

    /** ��ʼ��
    */
    int32_t m_initEsc ;

    /** ˳��
    */
    int32_t m_orderFall ;

    /** ����
    */
    int32_t m_runLength ;

    /** ��ʼ��
    */
    int32_t m_initRL ;

    /** ���˳��
    */
    int32_t m_maxOrder ;

    /** ����
    */
    byte_t m_charMask[256] ;

    /** ����
    */
    byte_t m_NS2Indx[256] ;

    /** ����
    */
    byte_t m_NS2BSIndx[256] ;

    /** ���
    */
    byte_t m_HB2Flag[256] ;

    /** ����
    */
    byte_t m_escCount ;

    /** ����
    */
    byte_t m_printCount ;

    /** �ɹ���
    */
    byte_t m_prevSuccess ;

    /** ��־
    */
    byte_t m_hiBitsFlag ;


    /** binary SEE-contexts
    */
    uint16_t m_binSumm[128][64] ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDInfo_h_
