/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDmgMethodStat_h_
#define __RCDmgMethodStat_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

class RCDmgMethodStat:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDmgMethodStat() ;

public:

    /** �������
    */
    uint32_t m_numBlocks ;

    /** ��ѹ���Ĵ�С
    */
    uint64_t m_packSize ;

    /** ��ѹ��Ĵ�С
    */
    uint64_t m_unpSize ;
};

/** RCDmgMethodStat����ָ��
*/
typedef RCSharedPtr<RCDmgMethodStat> RCDmgMethodStatPtr ;

END_NAMESPACE_RCZIP

#endif //__RCDmgMethodStat_h_
