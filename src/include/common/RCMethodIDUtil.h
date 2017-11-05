/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMethodIDUtil_h_
#define __RCMethodIDUtil_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCMethodIDUtil:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMethodIDUtil() ;
    
    /** Ĭ����������
    */
    ~RCMethodIDUtil() ;
    
    /** ��MethodIDת�����ַ���
    @param [in] id MethodID ֵ
    @return ת������ַ���
    */
    static RCStringW ConvertMethodIdToString(RCMethodID id) ;
    
private:
    
    /** ���ֽ�ֵת����ʮ���ַ�
    @param [in] value �ֽ�ֵ
    @return ����ʮ�������ַ�ֵ
    */
    static wchar_t GetHex(byte_t value) ;
};

END_NAMESPACE_RCZIP

#endif //__RCMethodIDUtil_h_
