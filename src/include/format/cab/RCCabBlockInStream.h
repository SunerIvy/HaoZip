/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabBlockInStream_h_
#define __RCCabBlockInStream_h_ 1

#include "base/RCTypes.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCCabBlockInStream : 
    public IUnknownImpl<ISequentialInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCabBlockInStream();

    /** Ĭ����������
    */
    ~RCCabBlockInStream();

public:

    /** ����
    */
    bool Create() ;

    /** ������
    @param [in] stream ������
    */
    void SetStream(ISequentialInStream* stream) ;

    /** Ϊ�µ��ļ��г�ʼ��
    */
    void InitForNewFolder() ;

    /** Ϊ�µĿ��ʼ��
    */
    void InitForNewBlock() ;

    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize);

    /** ��֮ǰ�Ĳ���
    @param [in] packSize ��ѹǰ��С
    @param [in] unpackSize ��ѹ���С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult PreRead(uint32_t& packSize, uint32_t& unpackSize);

public:
    
    /** ��ѹǰ�ܴ�С
    */
    uint32_t m_totalPackSize;

    /** ������С
    */
    uint32_t m_reservedSize;

    /** �Ƿ����ݴ���
    */
    bool m_dataError;

    /** �Ƿ���mszip
    */
    bool m_msZip;

private:

    /** ������
    */
    ISequentialInStreamPtr m_stream;

    /** �����ڴ�
    */
    byte_t* m_buffer;

    /** λ��
    */
    uint32_t m_pos;

    /** ��С
    */
    uint32_t m_size;

    /** ���С
    */
    static const uint32_t s_blockSize = (1 << 16);
};

END_NAMESPACE_RCZIP

#endif //__RCCabBlockInStream_h_