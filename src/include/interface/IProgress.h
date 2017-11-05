/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IProgress_h_
#define __IProgress_h_ 1

#include "interface/IUnknown.h"

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_IProgress = IID_IPROGRESS_BASE
};

/** ������ʾ��ؽӿ�����
*/
class IProgress:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IProgress } ;
    
public:

    /** ��������
    @param [in] total ���������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetTotal(uint64_t total) = 0 ;
    
    /** ��ǰ���
    @param [in] completed ��ǰ��ɵ�����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetCompleted(uint64_t completed) = 0 ;

protected:
        
    /** Ĭ����������
    */
    ~IProgress(){} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IProgress> IProgressPtr ;

END_NAMESPACE_RCZIP

#endif //__IProgress_h_
