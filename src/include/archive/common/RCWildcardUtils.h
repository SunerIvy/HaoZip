/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWildcardUtils_h_
#define __RCWildcardUtils_h_ 1

#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ͨ�丨����
*/
class RCWildcardUtils
{
public:
    
    /** �Ƚ��ļ�������Сд�Ƿ�������s_isCaseSensitive�����ж�
    @param [in] s1 ��һ���ļ���
    @param [in] s2 �ڶ����ļ���
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t CompareFileNames(const RCString& s1, const RCString& s2);
    
    /** �ֽ�·���ַ���Ϊ�ַ������飬�ָ���Ϊ�ļ�·���ָ���
    @param [in] path �ļ�·��
    @param [out] pathParts ���طָ����
    */
    static void SplitPathToParts(const RCString& path, RCVector<RCString>& pathParts);
    
    /** �ֽ��ļ���Ϊ�ļ�·�����ļ�����������
    @param [in] path �ļ���
    @param [out] dirPrefix ·�����������ļ���
    @param [out] name �ļ���������·��
    */
    static void SplitPathToParts(const RCString& path, RCString& dirPrefix, RCString& name);
    
    /** ���ļ����зֽ���ļ�·��
    @param [in] path �ļ�������·��
    @return �����ļ�·��
    */
    static RCString ExtractDirPrefixFromPath(const RCString& path);
    
    /** ���ļ����зֽ���ļ���
    @param [in] path �ļ�������·��
    @return �����ļ���������·��
    */
    static RCString ExtractFileNameFromPath(const RCString& path);
    
    /** �ļ������Ƿ���ͨ���
    @param [in] path �ļ���
    @return �������ͨ�������true�����򷵻�false
    */
    static bool DoesNameContainWildCard(const RCString& path);
    
    /** �ж��ļ����Ƿ�ƥ��ͨ���
    @param [in] mask ͨ����ļ���
    @param [in] name �ļ���
    @return ���ƥ�䷵��true�����򷵻�false
    */
    static bool CompareWildCardWithName(const RCString& mask, const RCString& name);
    
    /** �ж��ַ��Ƿ�Ϊ·���ָ���
    @param [in] ch ��Ҫ�жϵ��ַ�
    @return ����Ƿָ�������true�����򷵻�false
    */
    static bool IsCharDirLimiter(char_t ch) ;
    
    /** ��ȡ·���ָ���
    @return ����·���ָ���
    */
    static char_t GetDirLimiter(void) ;
    
    /** ��ȡ�Ƿ����ִ�Сд
    @return ���ִ�Сд����true,���򷵻�false
    */
    static bool IsCaseSensitive(void) ;
    
    /** �����Ƿ����ִ�Сд
    @param [in] isCaseSensitive �Ƿ����ִ�Сд
    */
    static void SetCaseSensitive(bool isCaseSensitive) ;

private:
    
    /** �Ƚ��ļ���ʱ���Ƿ����ִ�Сд
    */
    static bool s_isCaseSensitive ;

private:
    
    /** �ж��ļ����Ƿ�ƥ��ͨ���
    @param [in] mask ͨ����ļ���
    @param [in] name �ļ���
    @return ���ƥ�䷵��true�����򷵻�false
    */
    static bool EnhancedMaskTest(const char_t* mask, const char_t* name) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWildcardUtils_h_
