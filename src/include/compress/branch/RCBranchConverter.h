/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchConverter_h_
#define __RCBranchConverter_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Branch ת��
*/
class RCBranchConverter:
    public IUnknownImpl<ICompressFilter>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBranchConverter() ;
    
    /** Ĭ����������
    */
    ~RCBranchConverter() ;
    
public:
    
    /** ��ʼ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Init() ;
    
    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    virtual uint32_t Filter(byte_t* data, uint32_t size) ;
    
protected:
    /** ���ݹ�����
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ���ع����ֽ���
    */
    virtual uint32_t SubFilter(byte_t* data, uint32_t size) = 0 ;
    
    /** ��ʼ��
    */
    virtual void SubInit() ;
    
protected:
    
    /** ��������λ
    */
    uint32_t m_bufferPos ;
};

END_NAMESPACE_RCZIP

#endif //__RCBranchConverter_h_
