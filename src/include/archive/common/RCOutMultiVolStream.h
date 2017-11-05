/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef RCOutMultiVolStream_h_
#define RCOutMultiVolStream_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"
#include "archive/common/RCTempFiles.h"
#include "filesystem/RCOutFileStream.h"

BEGIN_NAMESPACE_RCZIP

/** �־�������¼��ӿ�
*/
class IOutStreamEvent ;

/** �־������ʵ��
*/
class RCOutMultiVolStream
    : public IUnknownImpl3<IOutStream, IMultiVolStream, IZipMultiVolStream>
{
public:
    
    /** ���캯��
    @param [in] outStreamEvent �־�������¼��ӿ�ָ��
    */
    RCOutMultiVolStream(IOutStreamEvent* outStreamEvent) ;
    
public:
    
    /** ���־��ļ���С
    */
    RCVector<uint64_t> m_sizes;
    
    /** �־��ļ���ǰ׺
    */
    RCString m_prefix;
    
    /** ��ʱ�ļ�
    */
    RCTempFiles* m_tempFiles;

    /** ��ʼ��
    */
    void Init() ; 

    /** �ر�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Close();
    
    /** д����
    @param [in] data ��д����
    @param [in] size ���ݴ�С
    @param [out] processedSize ����д���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Write(const void *data, uint32_t size, uint32_t *processedSize);
    
    /** �ƶ�����
    @param [in] offset ƫ����
    @param [in] seekOrigin ��ʼλ��
    @param [out] newPosition �µ��ļ�λ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t *newPosition);
    
    /** �����ļ���С
    @param [in] newSize �ļ���С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetSize(uint64_t newSize);

    /** ȡ�õ�ǰ��������ľ���
    @param [out] volIndex ���ص�ǰ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetCurVolIndex(uint32_t& volIndex);

    /** ȡ�õ�ǰ���д�ֽ���
    @param [out] freeByte ���ص�ǰ���д�ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetCurVolFreeByte(uint64_t& freeByte);

    /** ȡ�õ�ǰ��ƫ����
    @param [out] position ���ص�ǰ����ļ�ƫ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetCurVolPosition(uint64_t& position);

    /** ��ʹ���¾�ʼд�ļ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ForceStartNextVol();

    /** ����ĳλ�ÿ�ʼ��һ�������Ƿ���
    @param [in] beginPos ��ʼλ��
    @param [in] dataLen ���ݳ���
    @param [out] result �����true,���򷵻�false
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CheckDataAcrossVol(uint64_t beginPos, uint64_t dataLen, bool& result);

    /** ȡ�÷־�����
    @param [out] volCount �־�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetVolumeCount(uint32_t& volCount);

    /** �����Ƿ�����zip �־�
    @param [in] toZip  true����zip�־� false������zip�־�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetToZipMultiVolFormat(bool toZip);

public:

    /** ��ֻ��һ����ʱ���Ƿ��Զ�ȥ��.001��׺
    @param [in] isAutoRename �Ƿ��Զ�������Ψһ�־�
    */
    void SetAutoRename(bool isAutoRename) ;

private:

    /** д7z���ݷ־���ʵ��
    @param [in] data ��д������
    @param [in] size ���ݳ���
    @param [out] processedSize ʵ��д���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult  Write7zMultiVolImpl(const void *data, uint32_t size, uint32_t *processedSize);

    /** дwin zip���ݷ־���ʵ��
    @param [in] data ��д������
    @param [in] size ���ݳ���
    @param [out] processedSize ʵ��д���ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult  WriteZipMultiVolImpl(const void *data, uint32_t size, uint32_t *processedSize);

    /** ���ֻ��һ���־�,�Զ�ȥ��.001��׺
    *   �����ѹ���������ļ�����,��ȡ������
    @return �������ɹ�����true,���򷵻�false
    */
    bool RenameSingleVolumn(void);

    /** ������zip��ʽ���һ���־���
    @return �������ɹ�����true,���򷵻�false
    */
    bool RenameLastZipVolume(void);

private:
    
    /** �����
    */
    int32_t m_streamIndex;
    
    /** ƫ����
    */
    uint64_t m_offsetPos;
    
    /** ����λ��
    */
    uint64_t m_absPos;
    
    /** �ļ�������
    */
    uint64_t m_length;
    
    /** �־���Ϣ�ṹ
    */
    struct RCSubStreamInfo
    {
        /** ����ļ���
        */
        RCOutFileStream * m_streamSpec;
        
        /** ����ļ���ָ��
        */
        IOutStreamPtr m_stream;
        
        /** �־��ļ���
        */
        RCString m_name;
        
        /** �־��ļ�ƫ��
        */
        uint64_t m_pos;
        
        /** �־��ļ�ʵ�ʴ�С
        */
        uint64_t m_RealSize;
        
        /** �־��Ƿ�̶���С
        */
        bool     m_fixed;
    };
    
    /** �־���Ϣ�б�
    */
    RCVector<RCSubStreamInfo> m_streams;
    
private:
    
    /** д���¼�����
    */
    IOutStreamEvent* m_outStreamEvent ;

    /** ��ֻ��һ����ʱ���Ƿ��Զ�ȥ��.001��׺
    */
    bool m_isAutoRename ;

    /** �Ƿ�����zip�־�
    */
    bool m_isZipSplit;

};

END_NAMESPACE_RCZIP

#endif //RCOutMultiVolStream_h_
