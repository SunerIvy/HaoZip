/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFilterCoder_h_
#define __RCFilterCoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IPassword.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCFilterCoder:
    public IUnknownImpl11<
                          ICompressCoder,
                          ICompressSetInStream,
                          ISequentialInStream,
                          ICompressSetOutStream,
                          ISequentialOutStream,
                          IOutStreamFlush,
                          ICryptoSetPassword,
                          ICompressSetCoderProperties,
                          ICompressWriteCoderProperties,
                          ICryptoResetInitVector,
                          ICompressSetDecoderProperties2
                         >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCFilterCoder() ;
    
    /** Ĭ����������
    */
    ~RCFilterCoder() ;
    
public:
    
    /** ��ʼ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult Init() ;
    
    /** ����д������
    @param [in] outStream ������ӿ�
    @param [in] size ����д����ֽ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    HResult WriteWithLimit(ISequentialOutStream* outStream, uint32_t size) ;
    
    /** �Ƿ���Ҫд���������
    */
    bool NeedMore() const ;
    
    /** ���ñ��������
    @param [in] filter �������ӿ�
    */
    void SetFilter(ICompressFilter* filter) ;
    
    /** ѹ������
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ;

    /** ����������
    @param [in] inStream �������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult SetInStream(ISequentialInStream* inStream) ;
    
    /** �ͷ�������
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult ReleaseInStream() ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ���������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult SetOutStream(ISequentialOutStream* outStream) ;
    
    /** �ͷ������
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult ReleaseOutStream() ;
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ��ջ����������ѻ�������д����
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult Flush() ;
    
    /** ��������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetPassword(const byte_t* data, uint32_t size) ;
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) ;
    
    /** ���ü��ܳ�ʼ������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult ResetInitVector() ;
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size);
    
    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult QueryInterface(RC_IID iid, void** outObject) ;
   
protected:
    
    /** ��������ַ
    */
    byte_t* m_buffer ;
    
    /** �������ӿ�
    */
    ISequentialInStreamPtr m_spInStream ;
    
    /** ������ӿ�
    */
    ISequentialOutStreamPtr m_spOutStream ;
    
    /** ����������ƫ��
    */
    uint32_t m_bufferPos ;
    
    /** ��ת��������ʼƫ��
    */
    uint32_t m_convertedPosBegin ;
    
    /** ��ת�����ݽ���ƫ��
    */
    uint32_t m_convertedPosEnd ;
    
    /** �Ƿ���Ԥ�����С
    */
    bool m_outSizeIsDefined ;
    
    /** Ԥ�����С
    */
    uint64_t m_outSize ;
    
    /** ��ǰ����ƫ��
    */
    uint64_t m_nowPos64 ;
    
    /** �����ѯ�ӿ�
    */
    ICryptoSetPasswordPtr m_spSetPassword;
    
    /** �����������ýӿ�
    */
    ICompressSetCoderPropertiesPtr m_spSetCoderProperties;
    
    /** ��������д��ӿ�
    */
    ICompressWriteCoderPropertiesPtr m_spWriteCoderProperties;
    
    /** ����InitVector���ýӿ�
    */
    ICryptoResetInitVectorPtr m_spCryptoResetInitVector;
    
    /** �����������ýӿ�
    */
    ICompressSetDecoderProperties2Ptr m_spSetDecoderProperties;
    
    /** �����������ӿڽӿ�
    */
    ICompressFilterPtr m_spFilter ;
};

class RCInStreamReleaser
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCInStreamReleaser():
        m_filterCoder(NULL)
    {
    }
    
    /** Ĭ����������
    */
    ~RCInStreamReleaser()
    {
        if (m_filterCoder)
        {
            m_filterCoder->ReleaseInStream();
        }
    }
    
    /** ���ñ���������ӿ�
    @param [in] filterCoder ����������ӿ�
    */
    void SetFilterCoder(RCFilterCoder* filterCoder)
    {
        if (m_filterCoder && (m_filterCoder != filterCoder))
        {
            m_filterCoder->ReleaseInStream();
        }
        m_filterCoder = filterCoder ;
    }

private:
    
    /** ����������ӿ�
    */
    RCFilterCoder* m_filterCoder ;
};

class RCOutStreamReleaser
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCOutStreamReleaser():
        m_filterCoder(NULL)
    {
    }
    
    /** Ĭ����������
    */
    ~RCOutStreamReleaser()
    {
        if (m_filterCoder)
        {
            m_filterCoder->ReleaseOutStream();
        }
    }
    
    /** ���ñ���������ӿ�
    @param [in] filterCoder ����������ӿ�
    */
    void SetFilterCoder(RCFilterCoder* filterCoder)
    {
        if (m_filterCoder && (filterCoder != m_filterCoder))
        {
            m_filterCoder->ReleaseOutStream();
        }
        m_filterCoder = filterCoder ;
    }

private:
    
    /** ����������ӿ�
    */
    RCFilterCoder* m_filterCoder ;
};

END_NAMESPACE_RCZIP

#endif //__RCFilterCoder_h_
