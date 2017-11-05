/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWildcardCensor_h_
#define __RCWildcardCensor_h_ 1

#include "archive/common/RCWildcardPair.h"

BEGIN_NAMESPACE_RCZIP

/** ͨ���ƥ��
*/
class RCWildcardCensor
{
public:

    /** ��ȡPair����
    @return ����Pair��������
    */
    RCVector<RCWildcardPair>& GetPairs(void) ;
    
    /** ��ȡPair����
    @return ����Pair����
    */
    const RCVector<RCWildcardPair>& GetPairs(void) const ;
    
    /** �Ƿ�Ϊ���·��
    @return �Ƿ���true,���򷵻�false
    */
    bool AllAreRelative() const ;
    
    /** ����ƥ��Ŀ¼
    @param [in] include �Ƿ����
    @param [in] path ·������
    @param [in] recursive �Ƿ�ݹ�
    */
    void AddItem(bool include, const RCString& path, bool recursive) ;
    
    /** ���·���Ƿ�ƥ��
    @param [in] path ·������
    @param [in] isFile �Ƿ�Ϊ�ļ�
    @return �Ƿ���true,���򷵻�false
    */
    bool CheckPath(const RCString& path, bool isFile) const ;
    
    /** �ų�
    */
    void ExtendExclude() ;

private:
    
    /** ����ǰ׺
    @param [in] prefix ǰ׺
    @return ���ض�Ӧ�����
    */
    int32_t FindPrefix(const RCString& prefix) const ;
     
private:
    
    /** ƥ�������
    */
    RCVector<RCWildcardPair> m_pairs ;
};

END_NAMESPACE_RCZIP

#endif //__RCWildcardCensor_h_
