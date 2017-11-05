/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/lzh/RCLzhOutStreamWithCRC.h"

/////////////////////////////////////////////////////////////////
//RCLzhOutStreamWithCRC class implementation

BEGIN_NAMESPACE_RCZIP

HResult RCLzhOutStreamWithCRC::Write(const void* data, uint32_t size, uint32_t* processedSize)
{
    HResult hr;
    uint32_t realProcessedSize;
    if(!m_stream)
    {
        realProcessedSize = size;
        hr = RC_S_OK;
    }
    else
    {
        hr = m_stream->Write(data, size, &realProcessedSize);
    }

    m_crc.Update(data, realProcessedSize);
    if(processedSize != NULL)
    {
        *processedSize = realProcessedSize;
    }

    return hr;
}

END_NAMESPACE_RCZIP
