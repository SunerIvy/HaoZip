/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2CombinedCRC_h_
#define __RCBZip2CombinedCRC_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ��CRCУ��BZIP2
*/
class RCBZip2CombinedCRC
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2CombinedCRC() ;
    
    /** Ĭ����������
    */
    ~RCBZip2CombinedCRC() ;
    
public:
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ����
    @param [in] v 
    */
    void Update(uint32_t v) ;
    
    /** ����CRCУ��
    @return ����CRCУ��
    */
    uint32_t GetDigest() const ;
    
private:
    
    /** У��ֵ
    */
    uint32_t m_value ;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2CombinedCRC_h_
