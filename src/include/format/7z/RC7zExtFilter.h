/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zExtFilter_h_
#define __RC7zExtFilter_h_ 1

#include "archive/update/RCExtFilter.h"

BEGIN_NAMESPACE_RCZIP

class RC7zExtFilter:
    public RCExtFilter
{
public:

    struct
    {
        /** �ֵ��С
        */
        uint32_t m_dicSize;

        /** algo
        */
        uint32_t m_algo;

        /** fastbytes
        */
        uint32_t m_fastBytes;

        /** ƥ���ַ�
        */
        const RCString::value_type* m_matchFinder;

    }m_lzma;

    struct
    {
        /** fastbytes
        */
        uint32_t m_fastBytes;

        /** passes
        */
        uint32_t m_numPasses;

        /** algo
        */
        uint32_t m_algo;

    }m_deflate;

    struct
    {
        /** passes
        */
        uint32_t m_numPasses;

        /** �ֵ��С
        */
        uint32_t m_dicSize;

    }m_bzip2;

    struct
    {
        /** �ڴ��С
        */
        uint32_t m_useMemSize;

        /** ˳��
        */
        uint32_t m_order;

    }m_ppmd;
};

/** RC7zExtFilter����ָ��
*/
typedef RCSharedPtr<RC7zExtFilter> RC7zExtFilterPtr ;

END_NAMESPACE_RCZIP

#endif //__RC7zExtFilter_h_
