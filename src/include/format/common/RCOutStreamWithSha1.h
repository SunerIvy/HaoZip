/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutStreamWithSha1_h_
#define __RCOutStreamWithSha1_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCSha1Context ;

class RCOutStreamWithSha1:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCOutStreamWithSha1() ;
    
    /** Ĭ����������
    */
    ~RCOutStreamWithSha1() ;
    
public:

    /** ����������
    @param [in] stream ������
    */
    void SetStream(ISequentialOutStream* stream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ��ʼ��
    @param [in] calculate �Ƿ����crc
    */
    void Init(bool calculate = true) ;

    /** ��ʼ��sha1
    */
    void InitSha1() ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;

    /** ���
    */
    void Final(byte_t* digest) ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:

    /** �����
    */
    ISequentialOutStreamPtr m_spStream ;

    /** ��С
    */
    uint64_t m_size ;

    /** sha
    */
    RCSha1Context& m_sha ;

    /** �Ƿ����crc
    */
    bool m_calculate ;
};

END_NAMESPACE_RCZIP

#endif //__RCOutStreamWithSha1_h_
