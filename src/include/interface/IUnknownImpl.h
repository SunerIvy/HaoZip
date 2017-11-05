/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IUnknownImpl_h_
#define __IUnknownImpl_h_ 1

#include "interface/RCIIDDefs.h"
#include "base/RCRefCounted.h"
#include "base/RCComPtr.h"

BEGIN_NAMESPACE_RCZIP

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1
         >
class IUnknownImpl:
    public RCRefCounted,
    public T1
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;                    
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2
         >
class IUnknownImpl2:
    public RCRefCounted,
    public T1,
    public T2
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl2() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3
         >
class IUnknownImpl3:
    public RCRefCounted,
    public T1,
    public T2,
    public T3
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl3() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3,
            class T4
         >
class IUnknownImpl4:
    public RCRefCounted,
    public T1,
    public T2,
    public T3,
    public T4
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            case T4::IID:
                {
                    *outObject = (T4*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl4() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3,
            class T4,
            class T5
         >
class IUnknownImpl5:
    public RCRefCounted,
    public T1,
    public T2,
    public T3,
    public T4,
    public T5
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            case T4::IID:
                {
                    *outObject = (T4*)this ;
                }
                break ;
            case T5::IID:
                {
                    *outObject = (T5*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl5() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3,
            class T4,
            class T5,
            class T6
         >
class IUnknownImpl6:
    public RCRefCounted,
    public T1,
    public T2,
    public T3,
    public T4,
    public T5,
    public T6
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            case T4::IID:
                {
                    *outObject = (T4*)this ;
                }
                break ;
            case T5::IID:
                {
                    *outObject = (T5*)this ;
                }
                break ;
            case T6::IID:
                {
                    *outObject = (T6*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl6() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3,
            class T4,
            class T5,
            class T6,
            class T7
         >
class IUnknownImpl7:
    public RCRefCounted,
    public T1,
    public T2,
    public T3,
    public T4,
    public T5,
    public T6,
    public T7
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            case T4::IID:
                {
                    *outObject = (T4*)this ;
                }
                break ;
            case T5::IID:
                {
                    *outObject = (T5*)this ;
                }
                break ;
            case T6::IID:
                {
                    *outObject = (T6*)this ;
                }
                break ;
            case T7::IID:
                {
                    *outObject = (T7*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl7() {} ;
};

/** IUnknown�ӿ�ʵ����
*/
template <
            class T1,
            class T2,
            class T3,
            class T4,
            class T5,
            class T6,
            class T7,
            class T8,
            class T9,
            class T10,
            class T11
         >
class IUnknownImpl11:
    public RCRefCounted,
    public T1,
    public T2,
    public T3,
    public T4,
    public T5,
    public T6,
    public T7,
    public T8,
    public T9,
    public T10,
    public T11
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid){
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)(T1*)this ;
                }
                break ;
            case T1::IID:
                {
                    *outObject = (T1*)this ;
                }
                break ;
            case T2::IID:
                {
                    *outObject = (T2*)this ;
                }
                break ;
            case T3::IID:
                {
                    *outObject = (T3*)this ;
                }
                break ;
            case T4::IID:
                {
                    *outObject = (T4*)this ;
                }
                break ;
            case T5::IID:
                {
                    *outObject = (T5*)this ;
                }
                break ;
            case T6::IID:
                {
                    *outObject = (T6*)this ;
                }
                break ;
            case T7::IID:
                {
                    *outObject = (T7*)this ;
                }
                break ;
            case T8::IID:
                {
                    *outObject = (T8*)this ;
                }
                break ;
            case T9::IID:
                {
                    *outObject = (T9*)this ;
                }
                break ; 
            case T10::IID:
                {
                    *outObject = (T10*)this ;
                }
                break ;
            case T11::IID:
                {
                    *outObject = (T11*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }
    
protected:
      
    /** Ĭ����������
    */
    ~IUnknownImpl11() {} ;
};

END_NAMESPACE_RCZIP

#endif //__IUnknownImpl_h_
