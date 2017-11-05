/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/7z/RC7zWriteBufferLoc.h"

/////////////////////////////////////////////////////////////////
//RC7zWriteBufferLoc class implementation

BEGIN_NAMESPACE_RCZIP

RC7zWriteBufferLoc::RC7zWriteBufferLoc():
    m_data(NULL),
    m_size(0),
    m_pos(0)
{
}

RC7zWriteBufferLoc::~RC7zWriteBufferLoc()
{
}

void RC7zWriteBufferLoc::Init(byte_t* data, size_t size)
{
    m_data = data ;
    m_size = size ;
    m_pos = 0 ;
}

void RC7zWriteBufferLoc::WriteBytes(const void* data, size_t size)
{
    if (size > m_size - m_pos)
    {
        _ThrowCode(RC_E_WriteStreamError) ;
    }
    memcpy(m_data + m_pos, data, size);
    m_pos += size ;
}

void RC7zWriteBufferLoc::WriteByte(byte_t b)
{
    if (m_size == m_pos)
    {
        _ThrowCode(RC_E_WriteStreamError) ;
    }
    m_data[m_pos++] = b;
}

size_t RC7zWriteBufferLoc::GetPos() const
{
    return m_pos;
}
  
END_NAMESPACE_RCZIP
