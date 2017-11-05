/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/udf/RCUdfProgressImp.h"

BEGIN_NAMESPACE_RCZIP

RCUdfProgressImp::RCUdfProgressImp(IArchiveOpenCallback *callback):
    m_callback(callback), 
    m_numFiles(0), 
    m_numBytes(0) 
{
}

HResult RCUdfProgressImp::SetTotal(uint64_t numBytes)
{
    if (m_callback)
    {
        return m_callback->SetTotal(NULL, numBytes);
    }
    return RC_S_OK;
}

HResult RCUdfProgressImp::SetCompleted(uint64_t numFiles, uint64_t numBytes)
{
    m_numFiles = numFiles;
    m_numBytes = numBytes;
    return SetCompleted();
}

HResult RCUdfProgressImp::SetCompleted()
{
    if (m_callback)
    {
        return m_callback->SetCompleted(m_numFiles, m_numBytes);
    }
    return RC_S_OK;
}

END_NAMESPACE_RCZIP
