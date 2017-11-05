/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDmgFile_h_
#define __RCDmgFile_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCVector.h"
#include "common/RCBuffer.h"
#include "format/dmg/RCDmgBlock.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCDmgFile:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDmgFile() ;
    
public:

    /** ��ȡ��ѹ���С
    @return ���ؽ�ѹ���С
    */
    uint64_t GetUnpackSize() const ;

    /** ��ȡ����С
    @return ���ذ���С
    */
    uint64_t GetPackSize() const ;
    
public:

    /** ԭʼ����
    */
    RCByteBuffer m_raw ;

    /** ��ʼƫ��
    */
    uint64_t m_startPos ;

    /** dmg��
    */
    RCVector<RCDmgBlockPtr> m_blocks ;

    /** ����
    */
    RCStringA m_name ;
};

/** RCDmgFile����ָ��
*/
typedef RCSharedPtr<RCDmgFile> RCDmgFilePtr ;

END_NAMESPACE_RCZIP

#endif //__RCDmgFile_h_
