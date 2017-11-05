/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBufInStream_h_
#define __RCBufInStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

struct RCReferenceBuf:
    public IUnknown,
    public RCRefCounted
{
public:
    
    /** ���ݻ�����
    */
    RCByteBuffer m_buf ;

public:
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_INVALIDARG ;
        }
        switch(iid)
        {
            case IUnknown::IID:
                {
                    *outObject = (IUnknown*)this ;
                }
                break ;
            default:
                return RC_E_NOINTERFACE ;
                break ;                
        }
        this->AddRef() ;
        return RC_S_OK ;
    }
    
    /** �������ü���
    */
    virtual void AddRef(void)
    {
        RCRefCounted::Increase() ;
    }
    
    /** �������ü���
    */
    virtual void Release(void)
    {
        RCRefCounted::Decrease() ;
    }    
};

class RCBufInStream:
    public IUnknownImpl<IInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCBufInStream() ;
    
    /** Ĭ����������
    */
    ~RCBufInStream() ;
    
    /** ��ʼ�����ݻ�����
    @param [in] data ��������ʼ��ַ
    @param [in] size ���ݳ���
    */
    void Init(const byte_t* data, uint64_t size) ;
    
    /** ��ʼ�����ݻ�����
    @param [in] ref �����ü����Ļ�����ָ��
    */
    void Init(RCReferenceBuf* ref) ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
private:
    
    /** ��������ַ
    */
    const byte_t* _data ;
    
    /** ��������С
    */
    uint64_t _size ;
    
    /** ��ǰλ��ƫ��
    */
    uint64_t _pos ;
    
    /** �����ü����Ļ������ӿ�ָ��
    */
    IUnknownPtr _ref ;
};

END_NAMESPACE_RCZIP

#endif //__RCBufInStream_h_
