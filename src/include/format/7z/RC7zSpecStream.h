/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zSpecStream_h_
#define __RC7zSpecStream_h_ 1

#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RC7zSpecStream:
    public IUnknownImpl2<ISequentialInStream,
                         ICompressGetSubStreamSize
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zSpecStream() ;
    
    /** Ĭ����������
    */
    ~RC7zSpecStream() ;
    
public:

    /** ��ʼ��
    @param [in] stream ������
    */
    void Init(ISequentialInStream* stream) ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;

    /** ��ȡ����С
    @param [in] subStream �����±�
    @param [out] size ���Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetSubStreamSize(uint64_t subStream, uint64_t& size) ;
    
private:

    /** ������
    */
    ISequentialInStreamPtr m_stream ;

    /** ��ȡ����С�Ľӿ�
    */
    ICompressGetSubStreamSizePtr m_spGetSubStreamSize ;

    /** ��С
    */
    uint64_t m_size ;
};

END_NAMESPACE_RCZIP

#endif //__RC7zSpecStream_h_
