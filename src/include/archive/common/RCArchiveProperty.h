/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveProperty_h_
#define __RCArchiveProperty_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ĵ�����
*/
class RCArchiveProperty
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveProperty() ;
    
    /** ���캯��
    @param [in] name ��������
    @param [in] value ����ֵ
    */
    RCArchiveProperty(const RCString& name, const RCString& value) ;
    
    /** Ĭ����������
    */
    ~RCArchiveProperty() ;
    
    /** �������캯��
    @param [in] rhs ����ֵ
    */
    RCArchiveProperty(const RCArchiveProperty& rhs) ;
    
    /** ��ֵ������
    @param [in] rhs ����ԭ��
    */
    RCArchiveProperty& operator= (const RCArchiveProperty& rhs) ;

public:    
    
    /** ������������
    @param [in] name ��������
    */
    void SetName(const RCString& name) ;
    
    /** ��������ֵ
    @param [in] value ����ֵ
    */
    void SetValue(const RCString& value) ;
    
    /** ��ȡ��������
    @return ������������
    */
    const RCString& GetName(void) const ;
    
    /** ��ȡ����ֵ
    @return ��������ֵ
    */
    const RCString& GetValue(void) const ;
    
private:
    
    /** ��������
    */
    RCString m_name;
    
    /** ����ֵ
    */
    RCString m_value;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveProperty_h_
