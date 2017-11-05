/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCOutStreamWithCRC_h_
#define __RCOutStreamWithCRC_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCOutStreamWithCRC:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCOutStreamWithCRC() ;
    
    /** Ĭ����������
    */
    ~RCOutStreamWithCRC() ;
    
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

    /** ��ʼ��crc
    */
    void InitCRC() ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;

    /** ��ȡcrc
    @return ����crc
    */
    uint32_t GetCRC() const ;
    
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
    ISequentialOutStreamPtr m_stream;

    /** ��С
    */
    uint64_t m_size;

    /** crc
    */
    uint32_t m_crc;

    /** �Ƿ����crc
    */
    bool m_calculate;
};

END_NAMESPACE_RCZIP

#endif //__RCOutStreamWithCRC_h_
