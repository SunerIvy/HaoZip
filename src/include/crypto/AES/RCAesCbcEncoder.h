/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCAesCbcEncoder_h_
#define __RCAesCbcEncoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Aes Cbs ������
*/
class RCAesCbcEncoder:
    public IUnknownImpl2<ICompressFilter,
                         ICryptoProperties
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCAesCbcEncoder() ;
    
    /** Ĭ����������
    */
    ~RCAesCbcEncoder() ;

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
    
    /** ���ü��ܵļ�����
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetKey(const byte_t* data, uint32_t size) ;
    
    /** ���ü��ܳ�ʼ������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetInitVector(const byte_t *data, uint32_t size) ;

private:

    /** �ṹ TAesCbcImpl
    */
    struct TAesCbcImpl ;

    /** ʵ��
    */
    TAesCbcImpl* m_impl ;
};

END_NAMESPACE_RCZIP

#endif //__RCAesCbcEncoder_h_
