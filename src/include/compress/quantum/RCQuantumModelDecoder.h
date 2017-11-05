/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCQuantumModelDecoder_h_
#define __RCQuantumModelDecoder_h_ 1

#include "compress/quantum/RCQuantumDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Quantum Range ������
*/
class RCQuantumRangeDecoder ;

/** Quantum Model ������
*/
class RCQuantumModelDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCQuantumModelDecoder() ;
    
    /** Ĭ����������
    */
    ~RCQuantumModelDecoder() ;
    
public:

    /** ��ʼ��
    @param [in] numItems ��Ŀ��
    */
    void Init(uint32_t numItems) ;

    /** ����
    @param [in] rangeDecoder ������
    @return ���ؽ����ֽ���
    */
    uint32_t Decode(RCQuantumRangeDecoder* rangeDecoder) ;
    
private:

    /** ��Ŀ��
    */
    uint32_t m_numItems;

    /** ��¼��
    */
    uint32_t m_reorderCount;

    /** Ƶ��
    */
    uint16_t m_freqs[RCQuantumDefs::s_kNumSymbolsMax + 1];

    /** ��ֵ
    */
    byte_t m_values[RCQuantumDefs::s_kNumSymbolsMax];
};

END_NAMESPACE_RCZIP

#endif //__RCQuantumModelDecoder_h_
