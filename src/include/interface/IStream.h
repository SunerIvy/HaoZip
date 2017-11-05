/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IStream_h_
#define __IStream_h_ 1

#include "interface/IUnknown.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_ISequentialInStream     = IID_ISTREAM_BASE,
    IID_ISequentialOutStream,
    IID_IInStream,
    IID_IOutStream,
    IID_IStreamGetSize,
    IID_IOutStreamFlush,
    IID_ICloneStream,
    IID_IStreamGetFileName,
    IID_IMultiStream,
    IID_IMultiVolStream,
    IID_IZipMultiVolStream
};

/** ��ȡ���ݽӿ�
*/
class ISequentialInStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ISequentialInStream } ;
    
public:
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~ISequentialInStream() {} ;
};

/** д�����ݽӿ�
*/
class ISequentialOutStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ISequentialOutStream } ;
    
public:
    
    /** д����  
    @param [in] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~ISequentialOutStream() {} ;
};

/** �ļ�ƫ�Ƶ��������λ�ö��� 
*/
typedef enum
{
    /** ���ļ���ʼ 
    */
    RC_STREAM_SEEK_SET = 0,

    /** �ӵ�ǰ�ļ�ƫ�ƴ���ʼ 
    */
    RC_STREAM_SEEK_CUR = 1,

    /** ���ļ�����
    */
    RC_STREAM_SEEK_END = 2
    
} RC_STREAM_SEEK ;

/** �������ݽӿ�
*/
class IInStream:
    public ISequentialInStream
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IInStream } ;
    
public:
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~IInStream() {} ;
};

/** ������ݽӿ�
*/
class IOutStream:
    public ISequentialOutStream
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IOutStream } ;
    
public:
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) = 0 ;
    
    /** ������С
    @param [in] newSize �µĴ�С 
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetSize(uint64_t newSize) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~IOutStream() {} ;
};

/** ��ȡ���Ĵ�С 
*/
class IStreamGetSize:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IStreamGetSize } ;
    
public:
    
    /** ��ȡ����
    @param [out] size �������ĳ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetSize(uint64_t* size) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~IStreamGetSize() {} ;
};

/** ��ջ����������ѻ�������д����
*/
class IOutStreamFlush:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IOutStreamFlush } ;
    
public:
    
    /** ��ջ����������ѻ�������д����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult Flush() = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~IOutStreamFlush() {} ;
};

/** Clone�������ӿ�
*/
class ICloneStream:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_ICloneStream } ;
    
public:
    
    /**  Clone ������ 
    @return Clone �������������ʧ�ܷ���NULL
    */
    virtual IUnknown* Clone(void) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~ICloneStream() {} ;
};

/** ��ȡ����Ӧ���ļ���
*/
class IStreamGetFileName:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IStreamGetFileName } ;
    
public:
    
    /** ��ȡ����Ӧ���ļ�����������·��
    @param [out] fileName �����ļ�����������·��
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetFileName(RCString& fileName) = 0 ;

protected:
       
    /** Ĭ����������
    */
    ~IStreamGetFileName() {} ;
};

/** �־����ӿ�,ȡ��ĳ�־��С
*/
class IMultiStream :
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IMultiStream };
    
public:

    /** ȡ��ĳ�־��С
    @param [in] index �־����
    @param [out] volumeSize ���С�ֽ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetVolumeSize(uint32_t index, uint64_t& volumeSize) = 0 ;

    /** ȡ�ôӿ�ʼ��ĳ�־�����з־���ܴ�С
        �������� [0, index)
    @param [in] index �־����
    @param [out] volumeTotalSize �ܷ־��С�ֽ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetVolumeTotalSize(uint32_t index, uint64_t& volumeTotalSize) = 0;
    
protected:
    
    /** Ĭ����������
    */
    ~IMultiStream() {} ;
};

/** �־�������ӿ�
*/
class IMultiVolStream :
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IMultiVolStream };
    
public:
    
    /** ȡ�õ�ǰ��������ľ���
    @param [out] volIndex ������������ľ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetCurVolIndex(uint32_t& volIndex) = 0;

    /** ȡ�õ�ǰ���д�ֽ���
    @param [out] freeByte ���ص�ǰ��Ŀ�д�ֽ���
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetCurVolFreeByte(uint64_t& freeByte) = 0;

    /** ȡ�õ�ǰ��ƫ����
    @param [out] position ���ص�ǰ��ƫ����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetCurVolPosition(uint64_t& position) = 0;

    /** ����ĳλ�ÿ�ʼ��һ�������Ƿ���
    @param [in] beginPos ��ǰλ��ƫ��
    @param [in] dataLen ���ݳ���
    @param [out] result ��������true, ���򷵻�false
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult CheckDataAcrossVol(uint64_t beginPos, uint64_t dataLen, bool& result) = 0;

    /** ��ʹ���¾�ʼд�ļ�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult ForceStartNextVol() = 0;

    /** ȡ�÷־�����
    @param [out] volCount ���ط־�����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult GetVolumeCount(uint32_t& volCount) = 0;

protected:
    
    /** Ĭ����������
    */
    ~IMultiVolStream() {};
};

/** ��������zip �־�ӿ�
*/
class IZipMultiVolStream :
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IZipMultiVolStream };
    
public:
    
    /** �����Ƿ�����zip �־�
    @param [in] toZip  true����zip�־� false������zip�־�
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetToZipMultiVolFormat(bool toZip) = 0;
    
protected:
    
    /** Ĭ����������
    */
    ~IZipMultiVolStream() {};
};

/** ����ָ�붨��
*/

typedef RCComPtr<ISequentialInStream>   ISequentialInStreamPtr ;
typedef RCComPtr<ISequentialOutStream>  ISequentialOutStreamPtr ;
typedef RCComPtr<IInStream>             IInStreamPtr ;
typedef RCComPtr<IOutStream>            IOutStreamPtr ;
typedef RCComPtr<IStreamGetSize>        IStreamGetSizePtr ;
typedef RCComPtr<IOutStreamFlush>       IOutStreamFlushPtr ;
typedef RCComPtr<ICloneStream>          ICloneStreamPtr ;
typedef RCComPtr<IStreamGetFileName>    IStreamGetFileNamePtr ;
typedef RCComPtr<IMultiStream>          IMultiStreamPtr;
typedef RCComPtr<IMultiVolStream>       IMultiVolStreamPtr;
typedef RCComPtr<IZipMultiVolStream>    IZipMultiVolStreamPtr;

END_NAMESPACE_RCZIP

#endif //__IStream_h_
