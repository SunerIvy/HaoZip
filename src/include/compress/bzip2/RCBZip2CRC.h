/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2CRC_h_
#define __RCBZip2CRC_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** BZip2CRC
*/
class RCBZip2CRC
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBZip2CRC() ;
    
    /** Ĭ����������
    */
    ~RCBZip2CRC() ;
    
public:
    
    /** ��ʼ��CRC��
    */
    static void InitTable() ;
    
    /** ��ʼ��
    */
    void Init() ;
    
    /** ����У��ֵ
    @param [in] b ��������
    */
    void UpdateByte(byte_t b) ;
    
    /** ����У��ֵ
    @param [in] b ��������
    */
    void UpdateByte(uint32_t b) ;
    
    /** ����CRCУ��
    @return ����CRCУ��ֵ
    */
    uint32_t GetDigest() const ;
    
private:
    
    /** У��ֵ
    */
    uint32_t m_value;
    
    /** CRC��
    */
    static uint32_t s_table[256] ;
};

END_NAMESPACE_RCZIP

#endif //__RCBZip2CRC_h_
