/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfCDString_h_
#define __RCUdfCDString_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Udf CD String
*/
struct RCUdfCDString128
{
    /** ����
    */
    byte_t m_data[128];

    /** ����
    @param [in] buf ���ݻ���
    */
    void Parse(const byte_t *buf);

    /** �����ַ���
    @return �����ַ���
    */
    RCString GetString() const;
};

/** Udf CD String
*/
struct RCUdfCDString
{
    /** ���ݻ���
    */
    RCByteBuffer m_data;

    /** ����
    @param [in] p ����
    @param [in] size ���ݴ�С
    */
    void Parse(const byte_t *p, uint32_t size);

    /** �����ַ���
    @return �����ַ���
    */
    RCString GetString() const;
};

END_NAMESPACE_RCZIP

#endif //__RCUdfCDString_h_
