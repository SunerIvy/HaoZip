/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimResource_h_
#define __RCWimResource_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace NWimResourceFlags
{
    const byte_t s_compressed = 4;
    const byte_t s_metadata = 2;
}

class RCWimResource
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimResource() ;
    
    /** Ĭ����������
    */
    ~RCWimResource() ;
    
public:

    /** ����
    @param [in] p ����
    */
    void Parse(const byte_t* p) ; 

    /** �Ƿ�ѹ��
    @return ѹ������true,���򷵻�false
    */
    bool IsCompressed() const ;

    /** �Ƿ�meta����
    @return meta���ݷ���true,���򷵻�false
    */
    bool IsMetadata() const ;

    /** �Ƿ��
    @return �շ���true,���򷵻�false
    */
    bool IsEmpty() const ;
    
public:

    /** ѹ����С
    */
    uint64_t m_packSize;

    /** ƫ��
    */
    uint64_t m_offset;

    /** ��ѹ���С
    */
    uint64_t m_unpackSize;

    /** ��־
    */
    byte_t   m_flags;
};

END_NAMESPACE_RCZIP

#endif //__RCWimResource_h_
