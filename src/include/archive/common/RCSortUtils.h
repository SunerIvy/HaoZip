/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSortUtils_h_
#define __RCSortUtils_h_ 1

#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ��������
*/
class RCSortUtils
{
public:

    /** �ļ���������, �����ļ����ıȽϣ�����RCWildcardUtils::CompareFileNames����ʵ��
    @param [in] fileNames ��Ҫ������ַ�������
    @param [out] indices ��������������Ԫ��Ϊstrings�е��±�ֵ
    @param [in] useSysSort �Ƿ�ʹ��Windowsϵͳ�ṩ�����򷽷�
    */
    static void SortFileNames(const RCVector<RCString>& fileNames, RCIntVector& indices, bool useSysSort = false) ;

    /** �ļ����Ƚ�
    @param [in] lhs
    @param [in] rhs
    @param [in] useSysSort �Ƿ�ʹ��Windowsϵͳ�ṩ�����򷽷�
    @return ����ֵ�������£�
            0  - ���
            1  - lhs > rhs
            -1 - lhs < rhs
    */
    static int32_t Compare(const RCString& lhs, const RCString& rhs, bool useSysSort = false);
};

END_NAMESPACE_RCZIP

#endif //__RCSortUtils_h_
