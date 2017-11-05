/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveExtInfo_h_
#define __RCArchiveExtInfo_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ĵ���ʽ��չ��Ϣ
*/
class RCArchiveExtInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveExtInfo() ;
    
    /** ���캯��
    @param [in] ext ��չ��
    @param [in] addExt ������չ��
    */
    RCArchiveExtInfo(const RCString& ext, const RCString& addExt) ;
    
    /** Ĭ����������
    */
    ~RCArchiveExtInfo() ;
    
    /** �������캯��
    @param [in] rhs ����ԭ��
    */
    RCArchiveExtInfo(const RCArchiveExtInfo& rhs) ;
    
    /** ��ֵ������
    @param [in] rhs ����ԭ��
    */
    RCArchiveExtInfo& operator= (const RCArchiveExtInfo& rhs) ;

public:
    
    /** ��ȡ�ļ���չ��
    @return ������չ��
    */
    const RCString& GetExt(void) const ;
    
    /** ��ȡ������չ��
    @return ���ظ�����չ��
    */
    const RCString& GetAddExt(void) const ;
    
    /** ������չ��
    @param [in] ext ��չ��
    */
    void SetExt(const RCString& ext) ;
    
    /** ���ø�����չ��
    @param [in] addExt ������չ��
    */
    void SetAddExt(const RCString& addExt) ;
    
private:
    
    /** �ļ���չ��
    */
    RCString m_ext ;
    
    /** ������չ��
    */
    RCString m_addExt ;
};

END_NAMESPACE_RCZIP

#endif //__RCArchiveExtInfo_h_
