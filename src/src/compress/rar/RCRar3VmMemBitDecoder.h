/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3VmMemBitDecoder_h_
#define __RCRar3VmMemBitDecoder_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCRar3VmMemBitDecoder 
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCRar3VmMemBitDecoder() ;
    
    /** Ĭ����������
    */
    ~RCRar3VmMemBitDecoder() ;
    
public:
    void Init(const byte_t *data, uint32_t byteSize) ;
    uint32_t ReadBits(int32_t numBits) ;
    uint32_t ReadBit() ;
    bool Avail() const ;
    
private:
    const byte_t* _data ;
    uint32_t _bitSize ;
    uint32_t _bitPos ;
};

END_NAMESPACE_RCZIP

#endif //__RCRar3VmMemBitDecoder_h_
