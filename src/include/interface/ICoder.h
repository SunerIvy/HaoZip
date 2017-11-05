/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __ICoder_h
#define __ICoder_h 1

#include "interface/IUnknown.h"
#include "interface/ICodecInfo.h"
#include "common/RCProperty.h"
#include <vector>
#include <utility>

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_ICompressProgressInfo     = IID_ICODER_BASE,
    IID_ICompressCoder,
    IID_ICompressCoder2,
    IID_ICompressSetCoderProperties,
    IID_ICompressSetDecoderProperties2,
    IID_ICompressWriteCoderProperties,
    IID_ICompressGetInStreamProcessedSize,
    IID_ICompressSetCoderMt,
    IID_ICompressGetSubStreamSize,
    IID_ICompressSetInStream,
    IID_ICompressSetOutStream,
    IID_ICompressSetInStreamSize,
    IID_ICompressSetOutStreamSize,
    IID_ICompressFilter,
    IID_ICompressCodecsInfo,
    IID_ISetCompressCodecsInfo,
    IID_ICryptoProperties,
    IID_ICryptoResetInitVector,
    IID_ICryptoSetPassword,
    IID_ICryptoSetCRC,
    IID_IMtCompressProgressInfo,
    IID_ISetMultiThreadMode,
    
    IID_IBZip2ResumeDecoder,
    IID_ILzmaResumeDecoder,
    IID_IGZipResumeDecoder 
};

/** ǰ������
*/
class ISequentialInStream ;
class ISequentialOutStream ;

/** ѹ�����Ƚӿ� 
*/
class ICompressProgressInfo:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressProgressInfo } ;
    
public:
    
    /** ����ѹ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressProgressInfo(){} ;
};

/** ���߳�ѹ����ѹ���Ƚӿ� 
*/
class IMtCompressProgressInfo:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IMtCompressProgressInfo } ;
    
public:
    
    /** ����ѹ������
    @param [in] index ��ǰ�����±�
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint32_t index, uint64_t inSize, uint64_t outSize) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IMtCompressProgressInfo(){} ;
};

/** ���߳��������ýӿ�
*/
class ISetMultiThreadMode:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ISetMultiThreadMode } ;
    
public:
    
    /** ����ѹ����ѹ���߳�ģʽ
    @param [in] isMultThread �Ƿ�Ϊ���߳�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetMultiThread(bool isMultThread) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ISetMultiThreadMode(){} ;
};

/** ѹ�����ݽӿ� 
*/
class ICompressCoder:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressCoder } ;
    
public:
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) = 0 ;

protected:
    
    /** Ĭ����������
    */
    ~ICompressCoder(){} ;
};

/** �߼�ѹ�����ݽӿ� 
*/
class ICompressCoder2:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressCoder2 } ;
    
public:
    
    /** ��������Ϣ 
    */
    typedef std::pair<ISequentialInStream*,uint64_t> in_stream_data ;

    /** �������Ϣ 
    */
    typedef std::pair<ISequentialOutStream*,uint64_t> out_stream_data ;

public:
    
    /** ѹ��/��ѹ����
    @param [in] inStreams ��������Ϣ
    @param [in] outStreams �������Ϣ
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Code(const std::vector<in_stream_data>& inStreams,
                         const std::vector<out_stream_data>& outStreams, 
                         ICompressProgressInfo* progress) = 0 ;
protected:
    
    /** Ĭ����������
    */
    ~ICompressCoder2(){} ;
};

/** ����ѹ���������� 
*/
class ICompressSetCoderProperties:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetCoderProperties } ;
    
public:
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetCoderProperties(){} ;
};

/** ���ý�ѹ�������� 
*/
class ICompressSetDecoderProperties2:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetDecoderProperties2 } ;
    
public:
    
    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetDecoderProperties2(){} ;
};

/** ���ѹ���������� 
*/
class ICompressWriteCoderProperties:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressWriteCoderProperties } ;
    
public:
    
    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressWriteCoderProperties(){} ;
};

/** ��ȡ��������ȡ������ 
*/
class ICompressGetInStreamProcessedSize:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressGetInStreamProcessedSize } ;
    
public:
    
    /** ��ȡ��������ȡ�����ݳ���
    @param [out] size �������ݳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetInStreamProcessedSize(uint64_t& size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressGetInStreamProcessedSize(){} ;
};

/** ���߳����� 
*/
class ICompressSetCoderMt:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetCoderMt } ;
    
public:
    
    /** ���ö��̸߳���
    @param [in] numThreads �̸߳���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetNumberOfThreads(uint32_t numThreads) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetCoderMt(){} ;
};

/** ��ȡ�����Ĵ�С
*/
class ICompressGetSubStreamSize:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressGetSubStreamSize } ;
    
public:
    
    /** ��ȡ����С
    @param [in] subStream �����±�
    @param [out] size ���Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetSubStreamSize(uint64_t subStream, uint64_t& size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressGetSubStreamSize(){} ;
};

/** ����������
*/
class ICompressSetInStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetInStream } ;
    
public:
    
    /** ����������
    @param [in] inStream �������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetInStream(ISequentialInStream* inStream) = 0 ;
    
    /** �ͷ�������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult ReleaseInStream() = 0;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetInStream(){} ;
};

/** ���������
*/
class ICompressSetOutStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetOutStream } ;
    
public:
    
    /** ���������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetOutStream(ISequentialOutStream* outStream) = 0 ;
    
    /** �ͷ������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult ReleaseOutStream() = 0 ;
    
protected:
    
    /** Ĭ�Ϲ��캯��
    */
    ~ICompressSetOutStream(){} ;
};

/** �����������Ĵ�С 
*/
class ICompressSetInStreamSize:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetInStreamSize } ;
    
public:
    
    /** ������������С
    @param [in] inSize ��������С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetInStreamSize(uint64_t inSize) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetInStreamSize(){} ;
};

/** ����������Ĵ�С 
*/
class ICompressSetOutStreamSize:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressSetOutStreamSize } ;
    
public:
    
    /** �����������С
    @param [in] outSize �������С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetOutStreamSize(const uint64_t* outSize) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressSetOutStreamSize(){} ;
};

/** ѹ�����ݹ������ӿ� 
*/
class ICompressFilter:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressFilter } ;
    
public:
    
    /** ��ʼ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Init() = 0 ;
    
    /** ��������
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ʵ�ʴ������ݵĳ���
    */
    virtual uint32_t Filter(byte_t* data, uint32_t size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressFilter(){} ;
};

/** �����������Ϣ 
*/
class ICompressCodecsInfo:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICompressCodecsInfo } ;
    
public:
    /** ��ȡѹ���������������
    @param [out] numMethods ���ر������������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetNumberOfMethods(uint32_t& numMethods) const = 0 ;
    
    /** ��ȡ���������Ϣ
    @param [in] index ����������±꣬��0��ʼ
    @param [out] spCodecInfo �����������Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult GetMethod(uint32_t index, ICodecInfoPtr& spCodecInfo) const = 0 ;
    
    /** ����������
    @param [in] index �������±꣬��0��ʼ
    @param [in] iid �������Ľӿ�ID
    @param [out] coder �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CreateDecoder(uint32_t index, RC_IID iid, void** coder) const = 0 ;
    
    /** ����������
    @param [in] index �������±꣬��0��ʼ
    @param [in] iid �������Ľӿ�ID
    @param [out] coder �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CreateEncoder(uint32_t index, RC_IID iid, void** coder) const = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICompressCodecsInfo(){} ;
};

/** ���ñ���������ӿ� 
*/
class ISetCompressCodecsInfo:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ISetCompressCodecsInfo } ;
    
public:
    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ISetCompressCodecsInfo(){} ;
};

/** ��������
*/
class ICryptoProperties:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoProperties } ;
    
public:
    
    /** ���ü��ܵļ�����
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetKey(const byte_t* data, uint32_t size) = 0 ;
    
    /** ���ü��ܳ�ʼ������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetInitVector(const byte_t *data, uint32_t size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoProperties(){} ;
};

/** ���ü��ܳ�ʼ������ 
*/
class ICryptoResetInitVector:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoResetInitVector } ;
    
public:
    
    /** ���ü��ܳ�ʼ������
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult ResetInitVector() = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoResetInitVector(){} ;
};

/** ��������ӿ� 
*/
class ICryptoSetPassword:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoSetPassword } ;
    
public:
    
    /** ��������
    @param [in] data ���ݻ�����
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetPassword(const byte_t* data, uint32_t size) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoSetPassword(){} ;
};

/** ����CRC����У��ӿ� 
*/
class ICryptoSetCRC:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICryptoSetCRC } ;
    
public:
    
    /** ����CRCֵ
    @param [in] crc CRC��ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CryptoSetCRC(uint32_t crc) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ICryptoSetCRC(){} ;
};

/** ѹ�����ݽӿ� 
*/
class IBZip2ResumeDecoder:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IBZip2ResumeDecoder } ;
    
public:
    
    /** ����������
    @param [in] inStream ����������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetInStream(ISequentialInStream* inStream) = 0 ;
    
    /** �ͷ�������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult ReleaseInStream() = 0 ;
    
    /** ����
    @param [in] outStream ���������
    @param [out] isBZ �Ƿ�ΪBZip2����
    @param [in]  progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, bool& isBZ, ICompressProgressInfo* progress) = 0 ;
    
    /** ��ȡ�����������Ѵ�����
    @return ����������������ֽ���
    */
    virtual uint64_t GetInputProcessedSize() = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IBZip2ResumeDecoder(){} ;
};

/** ѹ�����ݽӿ� 
*/
class ILzmaResumeDecoder:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ILzmaResumeDecoder } ;
    
public:
    
    /** ����ӿ�
    @param [in] outStream ������ӿ�
    @param [in] outSize ����������ݴ�С
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, 
                               const uint64_t* outSize, 
                               ICompressProgressInfo* progress) = 0 ;
                       
    
    /** ���������ж�ȡ����
    @param [in] data ���ݻ�����
    @param [in] size �������ĳ���
    @param [out] processedSize ʵ�ʶ�ȡ�ĳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult ReadFromInputStream(void* data, uint32_t size, uint32_t* processedSize) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~ILzmaResumeDecoder(){} ;
};

/** ѹ�����ݽӿ� 
*/
class IGZipResumeDecoder:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IGZipResumeDecoder } ;
    
public:
    
    /** ��ѹ����
    @param [in] outStream  �����
    @param [in] outSize �������С
    @param [in] progress ���Ƚӿ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CodeResume(ISequentialOutStream* outStream, const uint64_t* outSize, ICompressProgressInfo* progress) = 0 ;
    
    /** ��ʼ��������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult InitInStream(bool needInit) = 0 ;
    
    /** ���䵽�ֽ�
    */
    virtual void AlignToByte() = 0 ;
    
    /** ��ȡ�ֽ�
    @return ���ض�ȡ�����ֽ�ֵ
    */
    virtual byte_t ReadByte() = 0 ;
    
    /** �Ƿ��Ѿ���ȡ��������Ľ���λ��
    @return ����������Ľ�������true�����򷵻�false
    */
    virtual bool InputEofError() const = 0 ;
    
    /** ��ȡ�������Ѵ���Ĵ�С
    @return ��������������������ֽ���
    */
    virtual uint64_t GetInputProcessedSize() const = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IGZipResumeDecoder(){} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<ICompressProgressInfo>             ICompressProgressInfoPtr ;
typedef RCComPtr<ICompressCoder>                    ICompressCoderPtr ;
typedef RCComPtr<ICompressCoder2>                   ICompressCoder2Ptr ;
typedef RCComPtr<ICompressSetCoderProperties>       ICompressSetCoderPropertiesPtr ;
typedef RCComPtr<ICompressSetDecoderProperties2>    ICompressSetDecoderProperties2Ptr ;
typedef RCComPtr<ICompressWriteCoderProperties>     ICompressWriteCoderPropertiesPtr ;
typedef RCComPtr<ICompressGetInStreamProcessedSize> ICompressGetInStreamProcessedSizePtr ;
typedef RCComPtr<ICompressSetCoderMt>               ICompressSetCoderMtPtr ;
typedef RCComPtr<ICompressGetSubStreamSize>         ICompressGetSubStreamSizePtr ;
typedef RCComPtr<ICompressSetInStream>              ICompressSetInStreamPtr ;
typedef RCComPtr<ICompressSetOutStream>             ICompressSetOutStreamPtr ;
typedef RCComPtr<ICompressSetInStreamSize>          ICompressSetInStreamSizePtr ;
typedef RCComPtr<ICompressSetOutStreamSize>         ICompressSetOutStreamSizePtr ;
typedef RCComPtr<ICompressFilter>                   ICompressFilterPtr ;
typedef RCComPtr<ICompressCodecsInfo>               ICompressCodecsInfoPtr ;
typedef RCComPtr<ISetCompressCodecsInfo>            ISetCompressCodecsInfoPtr ;
typedef RCComPtr<ICryptoProperties>                 ICryptoPropertiesPtr ;
typedef RCComPtr<ICryptoResetInitVector>            ICryptoResetInitVectorPtr ;
typedef RCComPtr<ICryptoSetPassword>                ICryptoSetPasswordPtr ;
typedef RCComPtr<ICryptoSetCRC>                     ICryptoSetCRCPtr ;
typedef RCComPtr<IMtCompressProgressInfo>           IMtCompressProgressInfoPtr ;
typedef RCComPtr<ISetMultiThreadMode>               ISetMultiThreadModePtr ;

typedef RCComPtr<IBZip2ResumeDecoder>               IBZip2ResumeDecoderPtr ;
typedef RCComPtr<ILzmaResumeDecoder>                ILzmaResumeDecoderPtr ;
typedef RCComPtr<IGZipResumeDecoder>                IGZipResumeDecoderPtr ;

END_NAMESPACE_RCZIP

#endif //__ICoder_h
