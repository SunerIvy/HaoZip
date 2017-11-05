/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialInStreamWithCRC_h_
#define __RCSequentialInStreamWithCRC_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCSequentialInStreamWithCRC:
    public IUnknownImpl<ISequentialInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSequentialInStreamWithCRC() ;
    
    /** Ĭ����������
    */
    ~RCSequentialInStreamWithCRC() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;

    /** ������
    @param [in] stream ������
    */
    void SetStream(ISequentialInStream* stream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ��ȡcrc
    @return ����crc
    */
    uint32_t GetCRC() const ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;

    /** �Ƿ����
    @return �Ƿ���true�����򷵻�false
    */
    bool WasFinished() const ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
private:

    /** ������
    */
    ISequentialInStreamPtr m_stream ;

    /** ��С
    */
    uint64_t m_size ;

    /** crc
    */
    uint32_t m_crc ;

    /** �Ƿ����
    */
    bool m_wasFinished ;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialInStreamWithCRC_h_
