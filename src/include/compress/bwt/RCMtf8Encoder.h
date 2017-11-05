/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtf8Encoder_h_
#define __RCMtf8Encoder_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** Mtf8 ������
*/
class RCMtf8Encoder:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtf8Encoder() ;
    
    /** Ĭ����������
    */
    ~RCMtf8Encoder() ;

public:
    
    /** ����ָ��λ���ݣ������ƶ�����ǰ��
    @param [in] value ��Ҫ���ҵ�����
    @return ��������ԭ����λ�ã����û���ҵ����򷵻�-1
    */
    int32_t FindAndMove(byte_t value) ;
    
    /** ������ [] 
    */
    byte_t& operator[](uint32_t index) ;
    
    /** ���������� [] 
    */
    const byte_t operator[](uint32_t index) const ;
    
public:
    
    /** ��������С
    */
    static const int32_t BUFFER_LEN = 256 ;
    
private:
    
    /** ���ݻ�����
    */
    byte_t m_buffer[BUFFER_LEN];
};

END_NAMESPACE_RCZIP

#endif //__RCMtf8Encoder_h_
