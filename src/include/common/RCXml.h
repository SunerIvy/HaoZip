/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCXml_h_
#define __RCXml_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** XML �ڵ�����
*/
struct RCXmlProp
{
    /** ��������
    */
    RCStringA m_name ;
    
    /** ����ֵ
    */
    RCStringA m_value ;
};

/** XML�ڵ���
*/
class RCXmlItem
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCXmlItem() ;
    
    /** Ĭ����������
    */
    ~RCXmlItem() ;
    
public:

    /** ����XML�ļ�����
    @param [in] text XML�ı�����
    @param [in,out] pos  �ı�������ʼƫ����
    @param [in] numAllowedLevels ������XML�ļ��ڵ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool ParseItem(const RCStringA& text, int32_t& pos, int32_t numAllowedLevels) ;
  
    /** �ж��Ƿ�Ϊָ���ڵ�
    @param [in] tag �ڵ�����
    @return ���Ϊ��Ч�ڵ����ƣ�����true, ���򷵻�false
    */
    bool IsTagged(const RCStringA& tag) const ;
    
    /** ��������
    @param [in] propName ��������
    @return �������Ե��±�ֵ�����ʧ�ܷ��� -1
    */
    int32_t FindProperty(const RCStringA& propName) const ;
    
    /** ��ȡ����ֵ
    @param [in] propName ��������
    @return �������Ե�ֵ�����ʧ�ܷ��ؿմ�
    */
    RCStringA GetPropertyValue(const RCStringA& propName) const ;
    
    /** ��ȡ�Ӵ�
    @return �����ִ����ƣ�����ж���ӽڵ㣬���ؿմ�
    */
    RCStringA GetSubString() const ;
    
    /** �����ӽڵ�
    @param [in] tag �ӽڵ������
    @return �����ӽڵ���±�ֵ
    */
    int32_t FindSubTag(const RCStringA& tag) const;
    
    /** ���ݽڵ��������ִ�
    @param [in] tag �ӽڵ������
    @return �����ִ����ƣ�ʧ���򷵻ؿմ�
    */
    RCStringA GetSubStringForTag(const RCStringA& tag) const ;
    
    /** ��ȡ����
    @return ���ؽڵ�����
    */
    const RCStringA& GetName() const ;
    
    /** �ж��Ƿ�ΪTag
    @return ���ΪTag����true, ���򷵻�false
    */
    bool IsTag() const ;
    
    /** ��ȡ����
    @return ����ֵ�б�
    */
    const RCVector<RCXmlProp>& GetProps() const ;
    
    /** ��ȡ�ӽڵ�
    @return �ӽڵ�ֵ�б�
    */
    const RCVector<RCXmlItem>& GetSubItems() const ;
        
    /** �Ƿ�Ϊ�ո��ַ�
    @param [in] c ��Ҫ�жϵ��ַ�
    @return ���Ϊ�ո��ַ�����true, ���򷵻�false
    */
    static bool IsSpaceChar(char c) ;
  
private:
    
    /** ����
    @param [in] s XML�ı�����
    @param [in,out] pos  �ı�������ʼƫ����
    @param [in] numAllowedLevels ������XML�ļ��ڵ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool ParseItems(const RCStringA& s, int32_t& pos, int32_t numAllowedLevels) ;
    
    /** �Ƿ�Ϊ��Ч�ַ�
    @param [in] c ��Ҫ�жϵ��ַ�
    @return ���Ϊ��Ч�ַ�����true, ���򷵻�false
    */
    static bool IsValidChar(char c) ;  
    
    /** ��������ȡ����ֵ
    @param [in] s XML�ı�����
    @param [in,out] pos  �ı�������ʼƫ����
    @param [out] prop ��������ֵ
    @return �ɹ�����true, ���򷵻�false
    */
    static bool ReadProperty(const RCStringA& s, int32_t& pos, RCXmlProp& prop) ;
    
private:
    
    /** ����
    */
    RCStringA m_name ;
    
    /** Tag���
    */
    bool m_isTag ;
    
    /** ����
    */
    RCVector<RCXmlProp> m_props ;
    
    /** �ӽڵ�
    */
    RCVector<RCXmlItem> m_subItems ;
};

/** XML�ļ����ݽ�����
*/
class RCXml:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCXml() ;
    
    /** Ĭ����������
    */
    ~RCXml() ;
    
    /** �����ļ��ı�����
    @param [in] text XML��ʽ���ı�����
    @return �ɹ�����true, ʧ�ܷ���false
    */
    bool Parse(const RCStringA& text) ;
    
    /** ��ȡ���ڵ�
    @return ���ظ��ڵ�
    */
    const RCXmlItem& GetRoot() const ;
    
private:
    
    /** ����XML�ļ�ͷ
    @param [in] s XML�ı�
    @param [in,out] pos �ı�������ʼƫ����
    @param [in] startString ��ʼ�ַ���
    @param [in] endString �����ַ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool SkipHeader(const RCStringA& s, 
                    int32_t& pos,
                    const RCStringA& startString, 
                    const RCStringA& endString) ;
    
private:
    
    /** ���ڵ�
    */
    RCXmlItem m_root ;
};

END_NAMESPACE_RCZIP

#endif //__RCXml_h_
