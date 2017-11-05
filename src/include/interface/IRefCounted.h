/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IRefCounted_h_
#define __IRefCounted_h_ 1

#include "interface/IUnknown.h"

BEGIN_NAMESPACE_RCZIP

/** ֻ�������ü��������ṩ�ӿڲ�ѯ�Ļ��� 
*/
class IRefCounted:
    public IUnknown
{
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ʼ�շ���RC_E_NOTIMPL
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        return RC_E_NOTIMPL ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void) = 0 ;
    
    /** �������ü���
    */
    virtual void Release() = 0 ;

protected:
      
    /** Ĭ����������
    */
    ~IRefCounted() {} ;
};

END_NAMESPACE_RCZIP

#endif //__IRefCounted_h_
