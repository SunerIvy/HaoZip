/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDmgBlock_h_
#define __RCDmgBlock_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

class RCDmgBlock:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDmgBlock() ;

public:

    /** ��ȡ��һ������ƫ��
    @return ������һ������ƫ��
    */
    uint64_t GetNextPackOffset() const
    {
        return m_packPos + m_packSize ;
    }
    
public:
    
    /** ����
    */
    uint32_t m_type;

    /** ��ѹƫ��
    */
    uint64_t m_unpPos;

    /** ��ѹ��Ĵ�С
    */
    uint64_t m_unpSize;

    /** ��ѹǰ�Ĵ�С
    */
    uint64_t m_packPos;

    /** ��ѹǰ�Ĵ�С
    */
    uint64_t m_packSize;
};

/** RCDmgBlock����ָ��
*/
typedef RCSharedPtr<RCDmgBlock> RCDmgBlockPtr ;

END_NAMESPACE_RCZIP

#endif //__RCDmgBlock_h_
