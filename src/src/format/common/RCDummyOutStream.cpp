/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/common/RCDummyOutStream.h"

/////////////////////////////////////////////////////////////////
//RCDummyOutStream class implementation

BEGIN_NAMESPACE_RCZIP

RCDummyOutStream::RCDummyOutStream():
    m_size(0)
{
}

RCDummyOutStream::~RCDummyOutStream()
{
}

void RCDummyOutStream::SetStream(ISequentialOutStream *outStream)
{
    m_stream = outStream ; 
}

void RCDummyOutStream::ReleaseStream()
{
    m_stream.Release() ;
}

void RCDummyOutStream::Init()
{
    m_size = 0 ;
}

uint64_t RCDummyOutStream::GetSize() const
{
    return m_size ;
}

HResult RCDummyOutStream::Write(const void* data, uint32_t size, uint32_t* processedSize)
{
    uint32_t realProcessedSize = 0 ;
    HResult result = RC_S_OK ;
    if (!m_stream)
    {
        realProcessedSize = size ;
        result = RC_S_OK ;
    }
    else
    {
        result = m_stream->Write(data, size, &realProcessedSize) ;
    }

    m_size += realProcessedSize;
    if (processedSize != NULL)
    {
        *processedSize = realProcessedSize ;
    }
    return result ;
}

END_NAMESPACE_RCZIP
