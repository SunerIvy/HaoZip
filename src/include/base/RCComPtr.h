/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCComPtr_h_
#define __RCComPtr_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ��COM����ָ��궨��
*/
template <class T>
class RCComPtr
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCComPtr() ;
    
    /** ָ�����ݹ��죬�����ͬʱ�Խӿ�ָ�����ü�������
    @param [in] p �ӿ�ָ��
    */
    RCComPtr(T* p) ;
    
    /** �������캯��
    @param [in] rhs �����ƵĶ���
    */
    RCComPtr(const RCComPtr<T>& rhs) ;
    
    /** Ĭ����������
    */
    ~RCComPtr() ;
    
    /** �ͷ�ָ��,���ݼ����ü���
    */
    void Release() ;
    
    /** ȡ��ָ��ĵ�ַ
    @return ���ش����Ľӿ�ָ��ĵ�ַ
    */
    T** GetAddress() ;
    
    /** ������ ->
    @return ���ؽӿ�ָ��
    */
    T* operator->() const ;
    
    /** ������ *
    @return ���ؽӿ�ָ��Ľ�����
    */
    T& operator *() const ;
    
    /** ָ�븳ֵ��������ͬʱ���ӽӿڵ����ü���
    @param [in] p �ӿ�ָ��
    @return ��������ָ����������
    */
    RCComPtr<T>& operator = (T* p) ;
    
    /** ָ�븳ֵ������
    @param [in] rhs �����ƵĶ���
    @return ��������ָ����������
    */
    RCComPtr<T>& operator = (const RCComPtr<T>& rhs) ;
    
    /** ������ !
    @return ���ָ�벻Ϊ���򷵻�false, ���򷵻�true
    */
    bool operator!() const ;
    
    /** ������ bool
    @return ���ָ�벻Ϊ���򷵻�true, ���򷵻�false
    */
    operator bool () const ;

    /** Attach���ݼ���ǰ��ָ�����ü�����������ֵΪp,������p�����ü���
    @param [in] p �ӿ�ָ��
    */
    void Attach(T* p) ;
    
    /** Detach���ͷŵ�ǰ�ӿ�ָ�룬���ı����ü���
    @return ���ص�ǰ�Ľӿ�ָ��
    */
    T* Detach() ;
    
    /** �ӿڲ�ѯ
    @param [in] iid �ӿ�ID
    @param [out] pp ���ر���ѯ�Ľӿ�ָ�룬����ӿ�ID����ʵ�֣����ı�ֵ
    @return �ɹ�����RC_S_OK��ʧ���򷵻ش����
    */  
    template <class Q>
    HResult QueryInterface(RC_IID iid, Q** pp) const
    {
        return m_ptr->QueryInterface(iid, (void**)pp) ;
    }
    
    /* ��ȡָ��
    @return ���ص�ǰ�Ľӿ�ָ��
    */
    T* Get() const ;
    
private:
    
    /** ָ���ַ
    */
    T* m_ptr ;
};

END_NAMESPACE_RCZIP

#include "RCComPtr.inl"

#endif //__RCComPtr_h_
