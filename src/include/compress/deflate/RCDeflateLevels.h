/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateLevels_h_
#define __RCDeflateLevels_h_ 1

#include "base/RCDefs.h"
#include "compress/deflate/RCDeflateDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate ����
*/
class RCDeflateLevels
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateLevels() ;
    
    /** Ĭ����������
    */
    ~RCDeflateLevels() ;
    
public:
    
    /** ���
    */
    void SubClear() ;
    
    /** ���ù̶�����
    */
    void SetFixedLevels() ;
    
public:
    
    /** ���𳤶�
    */
    byte_t m_litLenLevels[RCDeflateDefs::s_kFixedMainTableSize];
        
    /** ����
    */
    byte_t m_distLevels[RCDeflateDefs::s_kFixedDistTableSize];
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateLevels_h_
