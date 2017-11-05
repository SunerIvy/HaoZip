/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzhOutStreamWithCRC_h_
#define __RCLzhOutStreamWithCRC_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "RCLzhCRC.h"

BEGIN_NAMESPACE_RCZIP

class RCLzhOutStreamWithCRC:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ��д��Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;

public:

    /** ��ʼ��
    @param [in] stream ������
    */
    void Init(ISequentialOutStream *stream)
    {
        m_stream = stream;
        m_crc.Init();
    }

    /** �ͷ���
    */
    void ReleaseStream()
    {
        m_stream.Release();
    }

    /** ��ȡcrc
    @return ����crc
    */
    uint32_t GetCRC() const
    {
        return m_crc.GetDigest();
    }

    /** ��ʼ��crc
    */
    void InitCRC()
    {
        m_crc.Init();
    }

private:

    /** crc
    */
    RCLzhCRC m_crc;

    /** �����
    */
    ISequentialOutStreamPtr m_stream;
};

END_NAMESPACE_RCZIP

#endif //__RCLzhOutStreamWithCRC_h_
