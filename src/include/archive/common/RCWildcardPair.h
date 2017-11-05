/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWildcardPair_h_
#define __RCWildcardPair_h_ 1

#include "archive/common/RCWildcardCensorNode.h"

BEGIN_NAMESPACE_RCZIP

/** ͨ���ƥ���
*/
class RCWildcardPair
{
public:

    /** ���캯��
    @param [in] prefix ǰ׺
    */
    explicit RCWildcardPair(const RCString& prefix) ;

    /** ��ȡprefix
    @return ����ǰ׺����
    */
    RCString& GetPrefix(void) ;
    
    /** ��ȡprefix
    @return ����ǰ׺
    */
    const RCString& GetPrefix(void) const ;
    
    /** ��ȡhead
    @return ���ؽڵ�����
    */
    RCWildcardCensorNode& GetHead(void) ;
    
    /** ��ȡhead
    @return ����ͨ��ڵ�
    */
    const RCWildcardCensorNode& GetHead(void) const ;
    
private:
    
    /** ǰ׺
    */
    RCString m_prefix ;
    
    /** ͨ��ڵ�
    */
    RCWildcardCensorNode m_head ;
};

END_NAMESPACE_RCZIP

#endif //__RCWildcardPair_h_
