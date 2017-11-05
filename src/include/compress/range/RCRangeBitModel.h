/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRangeBitModel_h_
#define __RCRangeBitModel_h_ 1

#include "compress/range/RCRangeCoderDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Range Bit ģ��
*/
template <int32_t numMoveBits>
class RCRangeBitModel
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRangeBitModel() ;
    
    /** ����Prob
    @return ����Prob
    */
    uint32_t GetProb() const ;

    /** ����Prob
    @param [in] prob ֵ
    */
    void SetProb(uint32_t prob) ;

    /** ��ʼ��
    */
    void Init() ;

    /** ����ģ�� 
    @param [in] symbol ����
    */
    void UpdateModel(uint32_t symbol) ;

protected:

    /** prob
    */
    uint32_t m_prob ;
};

END_NAMESPACE_RCZIP

#include "RCRangeBitModel.inl"

#endif //__RCRangeBitModel_h_
