/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInOutStream_h_
#define __RCInOutStream_h_ 1

#include "base/RCTypes.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"

BEGIN_NAMESPACE_RCZIP

class RCInOutStream
{
public:
    RCInOutStream(ISequentialInStream* inStream, 
                  ISequentialOutStream* outStream,
                  ICompressProgressInfo* progress) :
      m_InStream(inStream),
      m_OutStream(outStream),
      m_Progress(progress),
      m_InCount(0),
      m_OutCount(0),
      m_IsCanceled(false)
    {}
public:
    uint64_t m_InCount;
    uint64_t m_OutCount;
    ISequentialInStream*    m_InStream;
    ISequentialOutStream*   m_OutStream;
    ICompressProgressInfo*  m_Progress;
    bool m_IsCanceled;
};

int32_t stream_getc(RCInOutStream*);
int32_t stream_putc(int32_t ,RCInOutStream*);


END_NAMESPACE_RCZIP

#endif //__RCInOutStream_h_