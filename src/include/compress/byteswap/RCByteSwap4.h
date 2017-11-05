/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCByteSwap4_h_
#define __RCByteSwap4_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** �ֽڽ���
*/
class RCByteSwap4:
    public IUnknownImpl<ICompressFilter>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCByteSwap4() ;
    
    /** Ĭ����������
    */
    ~RCByteSwap4() ;
    
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
};

END_NAMESPACE_RCZIP

#endif //__RCByteSwap4_h_
