/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDmgMethods_h_
#define __RCDmgMethods_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCVector.h"
#include "format/dmg/RCDmgMethodStat.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCDmgFile ;

class RCDmgMethods:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDmgMethods() ;
    
public:

    /** ����
    @param [in] file dmg�ļ�
    */
    void Update(const RCDmgFile& file);

    /** ��ȡ�ַ���
    @return �����ַ���
    */
    RCString GetString() const ;
    
public:

    /** ͳ��
    */
    RCVector<RCDmgMethodStatPtr> m_stats ;

    /** ����
    */
    RCVector<uint32_t> m_types ;
    
private:

    /** ��ȡ��С�ַ���
    @param [in] value ��ֵ
    @return �����ַ���
    */
    RCString GetSizeString(uint64_t value) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCDmgMethods_h_
