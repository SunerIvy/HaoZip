/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipExtFilter_h_
#define __RCZipExtFilter_h_ 1

#include "archive/update/RCExtFilter.h"

BEGIN_NAMESPACE_RCZIP

class RCZipExtFilter:
    public RCExtFilter
{
public:

    struct
    {
        /** passes
        */
        uint32_t m_numPasses;

        /** fastbytes
        */
        uint32_t m_numFastBytes;

        /** algo
        */
        uint32_t m_algo;

    }m_deflate;

    struct
    {
        /** �ֵ��С
        */
        uint32_t m_dicSize;

        /** fastbytes
        */
        uint32_t m_numFastBytes;

        /** algo
        */
        uint32_t m_algo;

        /** ƥ������
        */
        RCStringW m_matchFinder;

    }m_lzma;

    struct
    {
        /** passes
        */
        uint32_t m_numPasses;

        /** �ֵ��С
        */
        uint32_t m_dicSize;

    }m_bzip2;
};

/** RCZipExtFilter����ָ��
*/
typedef RCSharedPtr<RCZipExtFilter> RCZipExtFilterPtr ;

END_NAMESPACE_RCZIP

#endif //__RCZipExtFilter_h_
