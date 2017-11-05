/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCHandle_h_
#define __RCHandle_h_ 1

#include "base/RCNonCopyable.h"

#ifdef RCZIP_OS_WIN
#include "base/RCWindowsDefs.h"
#endif

BEGIN_NAMESPACE_RCZIP

class RCHandle:
    private RCNonCopyable
{

    /** ������Ͷ���
    */
#ifndef RCZIP_OS_WIN
    typedef HANDLE void*
#endif

public:

    /** Ĭ�Ϲ��캯��
    */
    RCHandle();

    /** Ĭ����������
    */
    ~RCHandle();

public:

    /** �رվ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool Close();

    /** Attach �����
    @param [in] handle ���ֵ
    */
    void Attach(HANDLE handle);

    /** Detach ���
    @return �����ڲ����ֵ
    */
    HANDLE Detach();

    /** HANDLE ������
    @return ���ص�ǰ�ľ��ֵ
    */
    operator HANDLE() const ;

protected:

    /** ���ֵ
    */
    HANDLE m_handle ;
};
END_NAMESPACE_RCZIP

#endif //__RCHandle_h_
