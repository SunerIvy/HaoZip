/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStringUtilA_h_
#define __RCStringUtilA_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ַ���ת�������֧࣬��Ansi�ַ���
*/
class RCStringUtilA:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCStringUtilA() ;
    
    /** Ĭ����������
    */
    ~RCStringUtilA() ;
    
public:
    
    /** 64λ�޷�������ת�ɶ��ֽ��ַ���
    @param [in] value ����ֵ
    @param [out] s ����ת������Ļ�����������Խ����
    @param [in] base ���ƣ�Ĭ��Ϊʮ����
    @return ����ת������ַ���ֵ
    */
    static void ConvertUInt64ToString(uint64_t value, char* s, uint32_t base = 10) ;

    /** 64λ�з�������ת�ɶ��ֽ��ַ���
    @param [in] value ����ֵ
    @param [out] s ����ת������Ļ�����������Խ����
    */
    static void ConvertInt64ToString(int64_t value, char* s) ;
    
    /** ���ֽ�ʮ�����ַ���ת��64λ�޷�������
    @param [in] s ��Ҫת�����ַ���
    @param [out] end ת����ָ��ǰ������ַ���ַ������ΪNULL
    @return ��������ֵ
    */
    static uint64_t ConvertStringToUInt64(const char* s, const char** end);
    
    /** ���ֽڰ˽����ַ���ת��64λ�޷�������
    @param [in] s ��Ҫת�����ַ���
    @param [out] end ת����ָ��ǰ������ַ���ַ������ΪNULL
    @return ��������ֵ
    */
    static uint64_t ConvertOctStringToUInt64(const char* s, const char** end);
    
    /** ���ֽ�ʮ�������ַ���ת��64λ�޷�������
    @param [in] s ��Ҫת�����ַ���
    @param [out] end ת����ָ��ǰ������ַ���ַ������ΪNULL
    @return ��������ֵ
    */
    static uint64_t ConvertHexStringToUInt64(const char* s, const char** end);

    /** ���ֽ��ַ���ת��64λ�з�������
    @param [in] s ��Ҫת�����ַ���
    @param [out] end ת����ָ��ǰ������ַ���ַ������ΪNULL
    @return ��������ֵ
    */
    static int64_t ConvertStringToInt64(const char* s, const char** end);
    
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
    static char* StringCopy(char* dest, const char* src) ;
    
    /** �ַ�ת���ɴ�д
    @param [in] ch ��Ҫת�����ַ���
    @return ת������ַ�
    */
    static char CharToUpper(char ch) ;
    
    /** �ַ�ת����Сд
    @param [in] ch ��Ҫת�����ַ���
    @return ת������ַ�
    */
    static char CharToLower(char ch) ;
    
    /** ���ַ����в����ַ�
    @param [in] data �ַ�����ʼ��ַ
    @param [in] ch ��Ҫ���ҵ��ַ�
    @return ���ҵ����ַ�����ַ���Ҳ����򷵻�NULL
    */
    static const char* StringChr(const char* data, char ch) ;

    /** ȡ����Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] count ��Ҫȡ���ַ�����
    @return �����Ӵ�
    */
    static RCStringA Left(const RCStringA& str, int32_t count) ;
    
    /** ȡ�Ҳ��Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] count ��Ҫȡ���ַ�����
    @return �����Ӵ�
    */
    static RCStringA Right(const RCStringA& str, int32_t count) ;
    
    /** ȡ�Ӵ�
    @param [in] str ��Ҫ�������ַ���
    @param [in] startIndex ��ʼ�±�ֵ
    @param [in] count �ַ����������ΪRCString::npos�����ʾ��startIndex���ַ�������
    @return �����Ӵ�
    */
    static RCStringA Mid(const RCStringA& str, int32_t startIndex, RCStringA::size_type count = RCStringA::npos) ;

    /** ���ַ������滻���ַ���
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] from ���滻���ַ���
    @param [in] to   �滻�ɵ��ַ���
    */
    static void Replace(RCStringA& str ,const RCStringA::value_type* from, const RCStringA::value_type* to) ;
    
    /** ȥ�����ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void TrimLeft(RCStringA& str, const RCStringA::value_type* value = " \r\t\n" ) ;
        
    /** ȥ���Ҳ�ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void TrimRight(RCStringA& str, const RCStringA::value_type* value = " \r\t\n" ) ;
        
    /** ȥ����������ָ���ַ�
    @param [in,out] str ��Ҫ�������ַ���
    @param [in] value ��ҪTrim���ַ��б�
    */
    static void Trim(RCStringA& str, const RCStringA::value_type* value = " \r\t\n" ) ;
        
    /** ת��Ϊ��д
    @param [in,out] str ��Ҫ�������ַ���
    */
    static void MakeUpper(RCStringA& str) ;
    
    /** ת��ΪСд
    @param [in,out] str ��Ҫ�������ַ���
    */
    static void MakeLower(RCStringA& str) ;
    
    /** �Ƚ��ַ����������ִ�Сд
    @param [in] lhs ��ֵ�ַ���
    @param [in] rhs ��ֵ�ַ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t CompareNoCase(const RCStringA& lhs, const RCStringA& rhs) ;
    
    /** �Ƚ��ַ��������ִ�Сд
    @param [in] lhs ��ֵ�ַ���
    @param [in] rhs ��ֵ�ַ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t Compare(const RCStringA& lhs, const RCStringA& rhs) ;
        
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
    static int32_t CompareNoCase(const char* cs, const char* ct, size_t count) ;
};

END_NAMESPACE_RCZIP

#endif //__RCStringUtilA_h_
