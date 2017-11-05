/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "compress/lz/RCLZOutWindow.h"

/////////////////////////////////////////////////////////////////
//RCLZOutWindow class implementation

BEGIN_NAMESPACE_RCZIP

RCLZOutWindow::RCLZOutWindow()
{
}

RCLZOutWindow::~RCLZOutWindow()
{
}

void RCLZOutWindow::Init(bool solid)
{
    if(!solid)
    {
        RCOutBuffer::Init();
    }
}

bool RCLZOutWindow::CopyBlock(uint32_t distance, uint32_t len)
{
    uint32_t pos = m_pos - distance - 1;
    if (distance >= m_pos)
    {
        if (!m_overDict || distance >= m_bufferSize)
        {
            return false;
        }
        pos += m_bufferSize;
    }
    if (m_limitPos - m_pos > len && m_bufferSize - pos > len)
    {
        const byte_t *src = m_buffer + pos;
        byte_t *dest = m_buffer + m_pos;
        m_pos += len;
        do
        {
            *dest++ = *src++;
        }
        while(--len != 0);
    }
    else
    {
        do
        {
            if (pos == m_bufferSize)
            {
                pos = 0;
            }
            m_buffer[m_pos++] = m_buffer[pos++];
            if (m_pos == m_limitPos)
            {
                FlushWithCheck();
            }
        }
        while(--len != 0);
    }
    return true;
}

void RCLZOutWindow::PutByte(byte_t byte)
{
    m_buffer[m_pos++] = byte;
    if (m_pos == m_limitPos)
    {
        FlushWithCheck();
    }
}

byte_t RCLZOutWindow::GetByte(uint32_t distance) const
{
    uint32_t pos = m_pos - distance - 1;
    if (pos >= m_bufferSize)
    {
        pos += m_bufferSize;
    }
    return m_buffer[pos];
}

END_NAMESPACE_RCZIP
