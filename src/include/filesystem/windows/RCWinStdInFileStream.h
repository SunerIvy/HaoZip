/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinStdInFileStream_h_
#define __RCWinStdInFileStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCWinStdInFileStream:
    public IUnknownImpl<ISequentialInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWinStdInFileStream() ;
    
    /** Ĭ����������
    */
    ~RCWinStdInFileStream() ;
    
public:
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinStdInFileStream_h_
