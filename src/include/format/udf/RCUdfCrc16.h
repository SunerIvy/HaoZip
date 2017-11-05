/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfCrc16_h_
#define __RCUdfCrc16_h_ 1

#include "base/RCTypes.h"
#include "algorithm/Types.h"

BEGIN_NAMESPACE_RCZIP

/** Udf Crc 16
*/
class RCUdfCrc16
{
public:

    /** ����Crc��
    */
    static void MY_FAST_CALL Crc16GenerateTable(void);

    /** Crc ����
    @param [in] v 
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return ����Crc
    */
    static uint16_t MY_FAST_CALL Crc16_Update(uint16_t v, const void *data, size_t size);

    /** Crc ����
    @param [in] data ����
    @param [in] size ���ݴ�С
    @return ����Crc
    */
    static uint16_t MY_FAST_CALL Crc16Calc(const void *data, size_t size);

private:

    /** Crc ���ݱ�
    */
    static uint16_t s_crc16Table[256];
};

/** Udf Crc 16 ���ʼ��
*/
struct RCUdfCrc16TableInit 
{ 
    /** ���캯��
    */
    RCUdfCrc16TableInit() 
    { 
        RCUdfCrc16::Crc16GenerateTable(); 
    } 
};

END_NAMESPACE_RCZIP

#endif //__RCUdfCrc16_h_
