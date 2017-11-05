/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinStdOutFileStream_h_
#define __RCWinStdOutFileStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCWinStdOutFileStream:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWinStdOutFileStream() ;
    
    /** Ĭ����������
    */
    ~RCWinStdOutFileStream() ;
    
public:
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinStdOutFileStream_h_
