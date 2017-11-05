/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar2Filter_h_
#define __RCRar2Filter_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** RAR2 ����
*/
class RCRar2Filter
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar2Filter() ;
    
    /** Ĭ����������
    */
    ~RCRar2Filter() ;
    
    /** ��ʼ������
    */
    void Init() ;
    
    /** ��������
    @param [in] channelDelta
    @param [in] deltaByte
    @return 
    */
    byte_t Decode(int32_t& channelDelta, byte_t deltaByte) ;
    
public:

    int32_t m_k1;
    int32_t m_k2; 
    int32_t m_k3;
    int32_t m_k4;
    int32_t m_k5;
    int32_t m_d1;
    int32_t m_d2;
    int32_t m_d3;
    int32_t m_d4;
    int32_t m_lastDelta;
    uint32_t m_dif[11];
    uint32_t m_byteCount;
    int32_t m_lastChar;
};

END_NAMESPACE_RCZIP

#endif //__RCRar2Filter_h_
