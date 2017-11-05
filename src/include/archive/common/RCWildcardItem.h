/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWildcardItem_h_
#define __RCWildcardItem_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ͨ���ƥ����
*/
class RCWildcardItem
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWildcardItem() ;
    
    /** Ĭ����������
    */
    ~RCWildcardItem() ;
    
    /** �������캯��
    @param [in] rhs ��������
    */
    RCWildcardItem(const RCWildcardItem& rhs) ;
    
    /** ��ֵ������
    @param [in] rhs ���Ʋ���
    */
    RCWildcardItem& operator= (const RCWildcardItem& rhs) ;

public:
    
    /** ���·��
    @param [in] pathParts ����·���б�
    @param [in] isFile �Ƿ�Ϊ�ļ�
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPath(const RCVector<RCString>& pathParts, bool isFile) const ;
    
    /** ���ظ���·���б�
    @return ���ظ���·���б�
    */
    const RCVector<RCString>& GetPathParts(void) const ;
    
    /** ���ظ���·���б�
    @return ���ظ���·���б�����
    */
    RCVector<RCString>& GetPathParts(void) ;
    
    /** �����Ƿ�ݹ�
    @return �ݹ鷵��true,���򷵻�false
    */
    bool IsRecursive(void) const ;
    
    /** �����Ƿ�for�ļ�
    @return for�ļ�����true,���򷵻�false
    */
    bool IsForFile(void) const ;
    
    /** �����Ƿ�forĿ¼
    @return forĿ¼����true,���򷵻�false
    */
    bool IsForDir(void) const ;
    
    /** �����Ƿ�ݹ�
    @param [in] isRecursive �Ƿ�ݹ�
    */
    void SetIsRecursive(bool isRecursive) ;
    
    /** �����Ƿ�for�ļ�
    @param [in] isForFile for�ļ�
    */
    void SetIsForFile(bool isForFile) ;
    
    /** �����Ƿ�forĿ¼
    @param [in] isForDir forĿ¼
    */
    void SetIsForDir(bool isForDir) ;
    
private:
      
    /** �ļ�·���б�
    */ 
    RCVector<RCString> m_pathParts ;
    
    /** �Ƿ�ݹ�
    */
    bool m_isRecursive ;
    
    /** �Ƿ�for�ļ�
    */
    bool m_isForFile ;
    
    /** �Ƿ�forĿ¼
    */
    bool m_isForDir ;
};

END_NAMESPACE_RCZIP

#endif //__RCWildcardItem_h_
