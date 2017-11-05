/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSystemUtils_h_
#define __RCSystemUtils_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCSystemUtils
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSystemUtils() ;
    
    /** Ĭ����������
    */
    ~RCSystemUtils() ;
    
public:
    
    /** ��ȡCPU����
    @return ���ص�ǰ������CPU��
    */
    static uint32_t GetNumberOfProcessors() ;
    
    /** ��ȡRAM��С
    @return ���ص�ǰ������RAM��С����λΪ�ֽ�
    */
    static uint64_t GetRamSize() ;
};

END_NAMESPACE_RCZIP

#endif //__RCSystemUtils_h_
