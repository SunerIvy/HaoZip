/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMultiStream_h_
#define __RCMultiStream_h_ 1

#include "interface/IStream.h"
#include "interface/IArchive.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCMultiStream:
    public IUnknownImpl3<IInStream,
                         ICloneStream,
                         IMultiStream>
{
public:

    struct CSubStreamInfo
    {
        /** ������
        */
        IInStreamPtr m_spStream ;

        /** λ��
        */
        uint64_t m_pos ;

        /** ��С
        */
        uint64_t m_size ;
    } ;

public:

    /** Ĭ�Ϲ��캯��
    */
    RCMultiStream() ;
    
    /** Ĭ����������
    */
    ~RCMultiStream() ;
    
public:

    /** ��ʼ��
    */
    void Init() ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;
    
    /** Clone������ 
    @return Clone �������������ʧ�ܷ���NULL
    */
    virtual IUnknown* Clone(void) ;

    /** ȡ��ĳ�־��С
    @param [in] index ����
    @param [in] volumeSize �־��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetVolumeSize(uint32_t index, uint64_t& volumeSize);

    /** ȡ�ôӿ�ʼ��ĳ�־�����з־���ܴ�С���������� [0, index)
    @param [in] index ����
    @param [out] volumeTotalSize �ܴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult GetVolumeTotalSize(uint32_t index, uint64_t& volumeTotalSize);
    
public:

    /** ��������
    */
    RCVector<CSubStreamInfo> m_streams ;
    
private:

    /** ������
    */
    int32_t  m_streamIndex ;

    /** λ��
    */
    uint64_t m_pos ;

    /** ��λλ��
    */
    uint64_t m_seekPos ;

    /** �ܳ���
    */
    uint64_t m_totalLength ;
};

END_NAMESPACE_RCZIP

#endif //__RCMultiStream_h_
