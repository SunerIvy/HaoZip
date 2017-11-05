/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtf8Decoder_h_
#define __RCMtf8Decoder_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** Mtf8 ������
*/
class RCMtf8Decoder:
    private RCNonCopyable
{
public:
    
    /** �������Ͷ���
    */
#ifdef RCZIP_BIT_64
    typedef uint64_t RCMtfVar ;
    static const int32_t RC_MTF_MOVS = 3 ;
#else
    typedef uint32_t RCMtfVar ;
    static const int32_t RC_MTF_MOVS = 2 ;
#endif

    /** ������λ�õ����ֵ
    */
    static const int32_t POS_LEN = 256 ;

public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtf8Decoder() ;
    
    /** Ĭ����������
    */
    ~RCMtf8Decoder() ;
    
public:
    
    /** ��������������
    */
    void StartInit() ;
    
    /** ���ݸ�ֵ
    @param [in] pos ��ֵ�±�
    @param [in] value λ����ֵ
    */
    void Add(uint32_t pos, byte_t value) ;
    
    /** ��ȡ��������һ������
    @return ����λ����ֵ
    */
    byte_t GetHead() const ;
    
    /** ��ȡ���������ƶ�����һ��λ��
    @param [in] pos �����±�
    @return ���ص�һ������ֵ
    */
    byte_t GetAndMove(uint32_t pos) ;
    
private:
    
    /** ���ݻ�����
    */
    RCMtfVar Buffer[POS_LEN >> RC_MTF_MOVS] ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtf8Decoder_h_
