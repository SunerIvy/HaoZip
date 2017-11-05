/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCInStreamWithCRC_h_
#define __RCInStreamWithCRC_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCInStreamWithCRC:
    public IUnknownImpl<IInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCInStreamWithCRC() ;
    
    /** Ĭ����������
    */
    ~RCInStreamWithCRC() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;

    /** ����������
    */
    void SetStream(IInStream *stream) ;

    /** �ͷ���
    */
    void ReleaseStream() ;

    /** ��ȡcrc
    @return ����crc
    */
    uint32_t GetCRC() const ;

    /** ��ȡ��С
    @return ���ش�С
    */
    uint64_t GetSize() const ;

    /** �Ƿ����
    @return �Ƿ���true�����򷵻�false
    */
    bool WasFinished() const ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    @param [out] newPosition ��������ļ�ƫ��
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;

    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject) ;

private:

    /** ������
    */
    IInStreamPtr m_stream ;

    /** ��С
    */
    uint64_t m_size ;

    /** crc
    */
    uint32_t m_crc ;

    /** �Ƿ����
    */
    bool m_wasFinished ;
};

END_NAMESPACE_RCZIP

#endif //__RCInStreamWithCRC_h_
