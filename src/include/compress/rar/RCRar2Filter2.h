/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar2Filter2_h_
#define __RCRar2Filter2_h_ 1

#include "compress/rar/RCRar2Defs.h"
#include "compress/rar/RCRar2Filter.h"

BEGIN_NAMESPACE_RCZIP

/** RAR2 ����2
*/
class RCRar2Filter2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar2Filter2() ;
    
    /** Ĭ����������
    */
    ~RCRar2Filter2() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;

    /** ����
    @param [in] delta
    @return ���ؽ����ֽ�
    */
    byte_t Decode(byte_t delta) ;
    
public:

    /** Filters
    */
    RCRar2Filter m_filters[RCRar2Defs::s_kNumChanelsMax];

    /** Channel Delta
    */
    int32_t m_channelDelta ;

    /** Current Channel
    */
    int32_t m_currentChannel ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar2Filter2_h_
