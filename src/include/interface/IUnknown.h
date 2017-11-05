/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IUnknown_h_
#define __IUnknown_h_ 1

#include "interface/RCIIDDefs.h"
#include "base/RCComPtr.h"

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_INVALID  = IID_IUNKNOWN_BASE -1,
    IID_IUnknown = IID_IUNKNOWN_BASE
};

/** �ӿڻ��࣬���нӿھ����ڸ�������� 
*/
class IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IUnknown } ;
    
public:
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject) = 0 ;
    
    /** �������ü���
    */
    virtual void AddRef(void) = 0 ;
    
    /** �������ü���
    */
    virtual void Release(void) = 0 ;

protected:
      
    /** Ĭ����������
    */
    virtual ~IUnknown() {} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IUnknown> IUnknownPtr ;


END_NAMESPACE_RCZIP

#endif //__IUnknown_h_
