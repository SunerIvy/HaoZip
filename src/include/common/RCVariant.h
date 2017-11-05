/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCVariant_h_
#define __RCVariant_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** Variant ���Ͷ���
*/
class RCVariantType
{
public:
    
    /** ����ö��ֵ
    */
    typedef enum
    {
        /** ������
        */
        RC_VT_EMPTY  = 0 ,
        
        /** �ַ�������
        */
        RC_VT_STRING = 1 ,
        
        /** �з�������
        */
        RC_VT_INT64  = 2 ,
        
        /** �޷�������
        */
        RC_VT_UINT64 = 3 ,
        
        /** Boolean ����
        */
        RC_VT_BOOL   = 4
        
    }RCVariantID ;
};

/** Variant ���Ͷ���
*/
class RCVariant
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCVariant() ;
    
    /** ���캯��
    @param [in] rhs ���ƶ���
    */
    RCVariant(const RCString& rhs) ;
    
    /** ���캯��
    */
    RCVariant(uint64_t rhs) ;
    
    /** ���캯��
    @param [in] rhs ��ʼ��ֵ
    */
    RCVariant(int64_t rhs) ;
    
    /** ���캯��
    @param [in] rhs ��ʼ��ֵ
    */
    RCVariant(bool rhs) ;
    
    /** ��������
    */
    ~RCVariant() ;
    
public:
    
    /** �������
    */
    void Clear() ;
    
    /** ȡ�Ǻ�������
    @return ���ص�ǰ������ֵ
    */
    int32_t which() const ;
    
    /** ��ȡvariant���ַ���ֵ
    @return �����ַ�������ֵ
    */
    const RCString& GetStringValue() const ;
    
    /** ��ȡvariant��64 λ�з�������ֵ
    @return ��������ֵ
    */
    int64_t GetInt64Value() const ;
    
    /** ��ȡvariant��64 λ�޷�������ֵ
    @return ��������ֵ
    */
    uint64_t GetUInt64Value() const ;
    
    /** ��ȡvariant�Ĳ���ֵ
    @return ���ز���ֵ
    */
    bool GetBooleanValue() const ;
    
public:
    
    /** ��ֵΪ�ַ�������
    @param [in] rhs �ַ���ֵ
    @return ��ǰ��������
    */
    RCVariant& operator=(const RCString& rhs) ;
    
    /** ��ֵΪ�޷���64λ����
    @param [in] rhs �޷���64λ����ֵ
    @return ��ǰ��������
    */
    RCVariant& operator=(uint64_t rhs) ;
    
    /** ��ֵΪ�з���64λ����
    @param [in] rhs �з���64λ����ֵ
    @return ��ǰ��������
    */
    RCVariant& operator=(int64_t rhs) ;
    
    /** ��ֵΪ��������
    @param [in] rhs ��������ֵ
    @return ��ǰ��������
    */
    RCVariant& operator=(bool rhs) ;

private:
    
    /** ��������
    */
    RCVariantType::RCVariantID m_type ;
    
    /** �ַ�������
    */
    RCString m_strValue ;
    
    /** ��ֵ����
    */
    uint64_t m_intValue ;
};

/** ���RCVariantֵ
@param [out] variant ��Ҫ�����Ķ���
*/
inline void ClearVariantValue(RCVariant& variant)
{
    variant.Clear() ;
}

/** �ж� RCVariant �Ƿ�Ϊ��
@param [in] variant ��Ҫ�����Ķ���
@return ���Ϊ�շ���true, ���򷵻�false
*/
inline bool IsEmptyType(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_EMPTY) ;
}

/** �ж� RCVariant �Ƿ�Ϊ �ַ�������
@param [in] variant ��Ҫ�����Ķ���
@return ���Ϊ�ַ������ͷ���true, ���򷵻�false
*/
inline bool IsStringType(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_STRING) ;
}

/** ��ȡvariant���ַ���ֵ
@param [in] variant ��Ҫ�����Ķ���
@return �����ַ���ֵ
*/
inline const RCString& GetStringValue(const RCVariant& variant)
{
    return variant.GetStringValue() ;
}

/** �ж� RCVariant �Ƿ�Ϊ 64 λ�з�������
@param [in] variant ��Ҫ�����Ķ���
@return ���Ϊ64λ�з����������ͷ���true, ���򷵻�false
*/
inline bool IsInt64Type(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_INT64) ;
}

/** ��ȡvariant��64 λ�з�������ֵ
@param [in] variant ��Ҫ�����Ķ���
@return ����64λ�з�������ֵ
*/
inline int64_t GetInt64Value(const RCVariant& variant)
{
    return variant.GetInt64Value() ;
}

/** �ж� RCVariant �Ƿ�Ϊ 64 λ�޷�������
@param [in] variant ��Ҫ�����Ķ���
@return ���Ϊ64λ�޷����������ͷ���true, ���򷵻�false
*/
inline bool IsUInt64Type(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_UINT64) ;
}

/** ��ȡvariant��64 λ�޷�������ֵ
@param [in] variant ��Ҫ�����Ķ���
@return ����64λ�޷�������ֵ
*/
inline uint64_t GetUInt64Value(const RCVariant& variant)
{
    return variant.GetUInt64Value() ;
}

/** �ж� RCVariant �Ƿ�Ϊ 64 λ��/�޷�������
@param [in] variant ��Ҫ�����Ķ���
@return �����64 λ��/�޷������ͷ���true, ���򷵻�false
*/
inline bool IsInteger64Type(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_INT64) ||
           (variant.which() == RCVariantType::RC_VT_UINT64 ) ;
}

/** ��ȡvariant��64 λ�з�������ֵ
@param [in] variant ��Ҫ�����Ķ���
@return ����64λ�з���ֵ
*/
inline int64_t GetInteger64Value(const RCVariant& variant)
{
    return variant.GetInt64Value() ;
}

/** �ж� RCVariant �Ƿ�Ϊ��������
@param [in] variant ��Ҫ�����Ķ���
@return ���Ϊ�������ͷ���true, ���򷵻�false
*/
inline bool IsBooleanType(const RCVariant& variant)
{
    return (variant.which() == RCVariantType::RC_VT_BOOL) ;
}

/** ��ȡvariant�Ĳ���ֵ
@param [in] variant ��Ҫ�����Ķ���
@return ���ض����Ӧ�Ĳ���ֵ
*/
inline bool GetBooleanValue(const RCVariant& variant)
{
   return variant.GetBooleanValue() ;
}

END_NAMESPACE_RCZIP

#endif //__RCVariant_h_
