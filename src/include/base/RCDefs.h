/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDefs_h_
#define __RCDefs_h_ 1

#include "base/RCTypes.h"

#ifdef _DEBUG
    #include <assert.h>
#endif

BEGIN_NAMESPACE_RCZIP

/** Unicode�汾���ַ����궨��
*/
#if !defined(_T)
    #if defined (RCZIP_UNICODE)
        #define _T(x)   L##x 
    #else 
        #define _T(x)   x
    #endif
#endif

/** �����׳��쳣
*/
#define _ThrowAgain()       throw

/** �׳������
*/
#define _ThrowCode(ex)      throw ( static_cast<HResult>(ex) )

/** �׳��쳣
*/
#define _Throw(ex)          throw ( ex )

/** �ڲ�ʹ�õ�Assert�궨��
*/
#ifdef _DEBUG
    #define RCZIP_ASSERT(x) { assert(x); }
#else
    #define RCZIP_ASSERT(x)
#endif

/** ����/���� ����
*/
#if !defined (RCZIP_NO_WINDOWS_API)
    #define RCZIP_API_EXPORT __declspec(dllexport)
    #define RCZIP_API_IMPORT __declspec(dllimport)
#else
    #define RCZIP_API_EXPORT
    #define RCZIP_API_IMPORT
#endif

/** RCZIP API
*/
#ifdef _RCZIP_API_EXPORTS
    #define RCZIP_API    RCZIP_API_EXPORT
#else
    #define RCZIP_API    RCZIP_API_IMPORT
#endif

/** ȡ��Сֵ, ���ִ�������Զ�����
@param [in] a ��һ��ֵ
@param [in] b �ڶ���ֵ
@return ���� a �� b �бȽ�С��һ��
*/
template <class T> 
inline T MyMin(const T& a, const T& b)
{
    return a < b ? a : b;
}

/** ȡ���ֵ, ���ִ�������Զ�����
@param [in] a ��һ��ֵ
@param [in] b �ڶ���ֵ
@return ���� a �� b �бȽϴ��һ��
*/
template <class T> 
inline T MyMax(const T& a, const T& b)
{
    return a > b ? a : b;
}

/** �ȽϺ���
@param [in] a ��һ��ֵ
@param [in] b �ڶ���ֵ
@return �� a == b ���� 0; ��a > b ���� 1; �� a < b ���� -1
*/
template <class T> 
inline int MyCompare(const T& a, const T& b)
{
    return a < b ? -1 : (a == b ? 0 : 1);
}

/** ��boolֵת��Ϊintֵ
@param [in] value ��Ҫת����boolֵ
@return ����ת�����intֵ���� 1 ��ʾtrue, 0 ��ʾfalse
*/
inline int BoolToInt(const bool& value)
{
    return (value ? 1: 0);
}

/** ��intֵת��Ϊboolֵ
@param [in] value ��Ҫת����intֵ
@return ����ת�����boolֵ
*/
inline bool IntToBool(const int& value)
{
    return (value != 0) ;
}

END_NAMESPACE_RCZIP

#endif //__RCDefs_h_
