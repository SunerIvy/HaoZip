/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhCRC_h_
#define __RCLzhCRC_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCLzhCRC
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzhCRC():
      m_value(0)
    {
    };

public:

    /** ��ʼ��
    */
    void Init()
    {
        m_value = 0;
    }

    /** ����
    @param [in] data ����
    @param [in] size ��С
    */
    void Update(const void* data, size_t size);

    /** ��ȡ��ֵ
    @return ������ֵ
    */
    uint16_t GetDigest() const
    {
        return m_value;
    }

public:

    /** table
    */
    static uint16_t s_table[256];

    /** ��ʼ��table
    */
    static void InitTable();

private:

    /** ��ֵ
    */
    uint16_t m_value;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhCRC_h_
