/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStringUtil_h_
#define __RCStringUtil_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include <stdarg.h>

BEGIN_NAMESPACE_RCZIP

/** �ַ���ת��������
*/
class RCStringUtil:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCStringUtil() ;
    
    /** Ĭ����������
    */
    ~RCStringUtil() ;
    
public:
    
    /** 32λ�з�������ת���ַ���
    @param [in] value ����ֵ
    @return ����ת������ַ���ֵ
    */
    static RCString ConvertInt32ToString(int32_t value ) ;
    
    /** 32λ�޷�������ת���ַ���
    @param [in] value ����ֵ
    @return ����ת������ַ���ֵ
    */
    static RCString ConvertUInt32ToString(uint32_t value ) ;
    
    /** 32λ�޷�������ת��ʮ�������ַ���
    @param [in] value ����ֵ
    @return ����ת������ַ���ֵ
    */
    static RCString ConvertUInt32ToHex(uint32_t value ) ;
    
    /** 64λ�޷�������ת�ɿ��ֽ��ַ���
    @param [in] value ����ֵ
    @param [out] s ����ת������ַ�������������С�ڲ������
    */
    static void ConvertUInt64ToString(uint64_t value, wchar_t* s) ;
    
    /** 64λ�з�������ת�ɿ��ֽ��ַ���
    @param [in] value ����ֵ
    @param [out] s ����ת������ַ�������������С�ڲ������
    */
    static void ConvertInt64ToString(int64_t value, wchar_t *s) ;
    
    /** 64λ�з�������ת���ַ���
    @param [in] value ����ֵ
    @return ����ת������ַ���ֵ
    */
    static RCString ConvertInt64ToString(int64_t value ) ;
    
    /** 64λ�޷�������ת���ַ���
    @param [in] value ����ֵ
    @return ����ת������ַ���ֵ
    */
    static RCString ConvertUInt64ToString(uint64_t value ) ;
    
    /** ���ֽ��ַ���ת��64λ�޷�������
    @param [in] s �ַ�����ʼ��ַ
    @param [out] end ת����ֹ���ַ�����ַ����ѡ����
    @return ����ת��������ֵ
    */
    static uint64_t ConvertStringToUInt64(const wchar_t* s, const wchar_t** end);
    
    /** ��ȡ�ַ�������
    @param [in] s �ַ�����ʼ��ַ
    @return �����ַ�������
    */
    static size_t StringLen(const wchar_t* s) ;
    
    /** ��ȡ�ַ�������
    @param [in] s �ַ�����ʼ��ַ
    @return �����ַ�������
    */
    static size_t StringLen(const char* s) ;
    
    /** �ַ�������, �������������ȼ��
    @param [in] src Դ�ַ�����ַ
    @param [out] dest Ŀ�껺������ַ
    @return ����dest
    */
    static wchar_t* StringCopy(wchar_t* dest, const wchar_t* src) ;
       
    /** �Ƚ��ַ����������ִ�Сд
    @param [in] lhs ��ֵ�ַ���
    @param [in] rhs ��ֵ�ַ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t CompareNoCase(const RCString& lhs, const RCString& rhs) ;
    
    /** �Ƚ��ַ��������ִ�Сд
    @param [in] lhs ��ֵ�ַ���
    @param [in] rhs ��ֵ�ַ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t Compare(const RCString& lhs, const RCString& rhs) ;
    
    /** �ַ�ת���ɴ�д
    @param [in] ch ��Ҫת�����ַ���
    @return ת������ַ�
    */
    static wchar_t CharToUpper(wchar_t ch) ;
    
    /** �ַ�ת����Сд
    @param [in] ch ��Ҫת�����ַ���
    @return ת������ַ�
    */
    static wchar_t CharToLower(wchar_t ch) ;
    
    /** ���ַ����в����ַ�
    @param [in] data �ַ�����ʼ��ַ
    @param [in] ch ��Ҫ���ҵ��ַ�
    @return ���ҵ����ַ�����ַ���Ҳ����򷵻�NULL
    */
    static const wchar_t* StringChr(const wchar_t* data, wchar_t ch) ;
    
    /** ���ַ������滻���ַ���
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] from ���滻���ַ���
    @param [in] to   �滻�ɵ��ַ���
    */
    static void Replace(RCString& str ,const RCString::value_type* from, const RCString::value_type* to) ;
        
    /** ���ַ������滻���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] from ���滻���ַ���
    @param [in] to   �滻�ɵ��ַ���
    */
    static void Replace(RCString& str ,const RCString::value_type from, const RCString::value_type to) ;
    
    /** ȥ�����ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void TrimLeft(RCString& str, const RCString::value_type* value = _T(" \r\t\n")) ;
        
    /** ȥ���Ҳ�ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void TrimRight(RCString& str, const RCString::value_type* value = _T(" \r\t\n")) ;
        
    /** ȥ����������ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void Trim(RCString& str, const RCString::value_type* value = _T(" \r\t\n")) ;
        
    /** ת��Ϊ��д
    @param [in,out] str ��Ҫ�������ַ���
    */
    static void MakeUpper(RCString& str) ;
    
    /** ת��ΪСд
    @param [in,out] str ��Ҫ�������ַ���
    */
    static void MakeLower(RCString& str) ;
    
    /** ȡ����Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] count ��Ҫȡ���ַ�����
    @return �����Ӵ�
    */
    static RCString Left(const RCString& str, int32_t count) ;
    
    /** ȡ�Ҳ��Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] count ��Ҫȡ���ַ�����
    @return �����Ӵ�
    */
    static RCString Right(const RCString& str, int32_t count) ;
    
    /** ȡ�Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] startIndex ��ʼ�±�ֵ
    @param [in] count �ַ����������ΪRCString::npos�����ʾ��startIndex���ַ�������
    @return �����Ӵ�
    */
    static RCString Mid(const RCString& str, int32_t startIndex, RCString::size_type count = RCString::npos) ;

    /** ��ʽ���ַ���
    @param [in,out] str ����ַ���
    @param [in] fmt ��ʽ���ַ�
    @param [in] ... �ɱ�����б�
    */
    static void Format(RCString& str, const RCString::value_type* fmt , ...) ;
        
    /** �ַ�����ͨ����Ƚ�, ͨ���Ϊ * �� ?
    @param [in] sPattern ����ͨ������ַ���
    @param [in] sFileName ��Ҫ����ƥ��Ƚϵ��ַ���
    @param [in] bNoCase �Ƿ����ִ�Сд��true ��ʾ�����ִ�Сд, false��ʾ���ִ�Сд
    @return ����true��ʾƥ��ɹ�������ƥ��ʧ��
    */
    static bool WildcardCompare(const char_t* sPattern, 
                                const char_t* sFileName, 
                                bool bNoCase) ;    
       
private:

    /** �Ƚ��ַ����������ִ�Сд
    @param [in] cs ��ֵ�ַ���
    @param [in] ct ��ֵ�ַ���
    @param [in] count ���Ƚϵ��ַ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t CompareNoCase(const wchar_t* cs, const wchar_t* ct, size_t count) ;

    /** ��ʽ���ַ���
    @param [out] buf ���������
    @param [in] size ��������С
    @param [in] format ��ʽ���ַ�
    @param [in] args �ɱ�����б�
    @return ת������� 0 ��ʾ�ɹ�, -1 ��ʾʧ�ܣ�1 ��ʾ����������
    */
    static int32_t FormatToBuffer(RCString::value_type* buf, int32_t size ,const RCString::value_type* format, va_list args) ;
};

END_NAMESPACE_RCZIP

#endif //__RCStringUtil_h_
