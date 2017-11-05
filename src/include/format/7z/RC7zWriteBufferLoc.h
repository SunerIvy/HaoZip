/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zWriteBufferLoc_h_
#define __RC7zWriteBufferLoc_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RC7zWriteBufferLoc:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zWriteBufferLoc() ;
    
    /** Ĭ����������
    */
    ~RC7zWriteBufferLoc() ;
    
public:

    /** ��ʼ��
    @param [in] data ����
    @param [in] size ��С
    */
    void Init(byte_t* data, size_t size) ;

    /** д�ֽ�
    @param [in] data ����
    @param [in] size ��С
    */
    void WriteBytes(const void* data, size_t size) ;

    /** дһ���ֽ�
    */
    void WriteByte(byte_t b) ;

    /** ��ȡλ��
    */
    size_t GetPos() const ;
    
private:

    /** ����
    */
    byte_t* m_data ;

    /** ��С
    */
    size_t m_size ;

    /** λ��
    */
    size_t m_pos ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zWriteBufferLoc_h_
