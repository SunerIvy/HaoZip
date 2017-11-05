/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDelta_h_
#define __RCDelta_h_ 1

#include "base/RCDefs.h"
#include "algorithm/Delta.h"

BEGIN_NAMESPACE_RCZIP

/** Delat �㷨
*/
class RCDelta
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCDelta(): 
        m_delta(1) 
    {
    }

    /** ��ʼ��
    */
    void DeltaInit() 
    { 
        Delta_Init(m_state); 
    }

protected:
    
    /** Delta
    */
    unsigned m_delta;

    /** ״̬
    */
    byte_t m_state[DELTA_STATE_SIZE];

};

END_NAMESPACE_RCZIP

#endif //__RCDelta_h_
