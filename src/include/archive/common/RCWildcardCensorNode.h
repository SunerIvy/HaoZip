/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWildcardCensorNode_h_
#define __RCWildcardCensorNode_h_ 1

#include "archive/common/RCWildcardItem.h"

BEGIN_NAMESPACE_RCZIP

/** ƥ��ڵ�
*/
class RCWildcardCensorNode
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWildcardCensorNode() ;
    
    /** ���캯��
    @param [in] name ����
    @param [in] parent ���ڵ�
    */
    RCWildcardCensorNode(const RCString& name, RCWildcardCensorNode* parent) ;
    
    /** Ĭ����������
    */
    ~RCWildcardCensorNode() ;
    
public:
    
    /** �����ӽڵ�
    @param [in] name ·����
    @return �����ӽڵ���±�, ������Ҳ�������-1
    */
    int32_t FindSubNode(const RCString& name) const ;
    
    /** ���ӽڵ�
    @param [in] include �Ƿ����
    @param [in] item ������
    */
    void AddItem(bool include, RCWildcardItem& item) ;
    
    /** ���ӽڵ�
    @param [in] include �Ƿ����
    @param [in] path ·��
    @param [in] recursive �Ƿ�ݹ�
    @param [in] forFile �����ļ�
    @param [in] forDir ����Ŀ¼
    */
    void AddItem(bool include, const RCString& path, bool recursive, bool forFile, bool forDir);
    
    /** ���ӽڵ�
    @param [in] include �Ƿ����
    @param [in] path ·��
    @param [in] recursive �Ƿ�ݹ�
    */
    void AddItem2(bool include, const RCString& path, bool recursive) ;
    
    /** �Ƿ���Ҫ�����Ŀ¼
    @return ��Ҫ��鷵��true,���򷵻�false
    */
    bool NeedCheckSubDirs() const ;

    /** �Ƿ��������
    @return ���������true,���򷵻�false
    */
    bool AreThereIncludeItems() const ;
    
    /** ���·��
    @param [in] path ·��
    @param [in] isFile �Ƿ�Ϊ�ļ�
    @param [out] include �Ƿ����
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPath(const RCString& path, bool isFile, bool& include) const ;
    
    /** ���·��
    @param [in] path ·��
    @param [in] isFile �Ƿ�Ϊ�ļ�
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPath(const RCString& path, bool isFile) const ;
    
    /** ���·��һֻ����·��
    @param [in] include �Ƿ����
    @param [in,out] pathParts ����·���б�
    @param [in] isFile �Ƿ�Ϊ�ļ�
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPathToRoot(bool include, RCVector<RCString>& pathParts, bool isFile) const ;
    
    /** �ų�
    @param [in] fromNodes ���ų��Ľڵ�
    */
    void ExtendExclude(const RCWildcardCensorNode& fromNodes) ;
    
    /** ���ø��ڵ�
    @param [in] parent ���ڵ�
    */
    void SetParent(RCWildcardCensorNode* parent) ;
    
    /** ���ظ��ڵ�
    @return ���ظ��ڵ�ָ��
    */
    RCWildcardCensorNode* GetParent(void) const ;
    
    /** ��������
    @return ���������ַ���
    */
    const RCString& GetName() const ;
    
    /** ��������
    @param [in] name ����
    */
    void SetName(const RCString& name ) ;
    
    /** �����ӽڵ��б�
    @return �����ӽڵ��б�����
    */
    RCVector<RCWildcardCensorNode>& GetSubNodes() ;
    
    /** �����ӽڵ��б�
    @return �����ӽڵ��б�
    */
    const RCVector<RCWildcardCensorNode>& GetSubNodes() const ;
    
    /** ���ذ�������
    @return ���ذ��������б�����
    */
    RCVector<RCWildcardItem>& GetIncludeItems() ;
    
    /** ���ذ�������
    @return ���ذ��������б�
    */
    const RCVector<RCWildcardItem>& GetIncludeItems() const ;
    
    /** �����ų������б�
    @return �����ų������б�����
    */
    RCVector<RCWildcardItem>& GetExcludeItems() ;
    
    /** �����ų���
    @return �����ų����б�
    */
    const RCVector<RCWildcardItem>& GetExcludeItems() const ;
    
private:
    
    /** ��鵱ǰ·��
    @param [in] include �Ƿ����
    @param [in] pathParts ����·���б�
    @param [in] isFile �Ƿ����ļ�
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPathCurrent(bool include, const RCVector<RCString>& pathParts, bool isFile) const ;
    
    /** ����ƥ����
    @param [in] include �Ƿ����
    @param [out] item �������ӵ���
    */
    void AddItemSimple(bool include, RCWildcardItem& item) ;
    
    /** ���·��
    @param [in,out] pathParts ����·���б�
    @param [in] isFile �Ƿ����ļ�
    @param [out] include �Ƿ����
    @return ƥ�䷵��true,���򷵻�false
    */
    bool CheckPath(RCVector<RCString>& pathParts, bool isFile, bool& include) const ;
    
private:
    
    /** ���ڵ�
    */
    RCWildcardCensorNode* m_parent ;
    
    /** ����
    */
    RCString m_name;
    
    /** �ӽڵ��б�
    */
    RCVector<RCWildcardCensorNode> m_subNodes;
    
    /** ���������б�
    */
    RCVector<RCWildcardItem> m_includeItems;
    
    /** �ų������б�
    */
    RCVector<RCWildcardItem> m_excludeItems;
};

END_NAMESPACE_RCZIP

#endif //__RCWildcardCensorNode_h_
