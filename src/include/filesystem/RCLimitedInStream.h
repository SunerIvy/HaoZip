/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLimitedInStream_h_
#define __RCLimitedInStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCLimitedInStream:
    public IUnknownImpl<IInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLimitedInStream() ;
    
    /** Ĭ����������
    */
    ~RCLimitedInStream() ;
    
public:
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
    /** ����ָ��λ��
    @param [in] offset ��Ҫ������ƫ����
    @param [in] seekOrigin �����Ļ�׼λ��
    @param [out] newPosition ��������ļ�ƫ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;

public:
    
    /** �����������ӿ�
    @param [in] stream �������ӿ�ָ��
    */
    void SetStream(IInStream* stream) ;
    
    /** ��ʼ�����ƶ���ָ��ƫ��
    @param [in] startOffset ��ʼƫ��
    @param [in] size �����ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult InitAndSeek(uint64_t startOffset, uint64_t size) ;
    
    /** �ƶ�����ʼλ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SeekToStart() ;
    
private:
    
    /** �ƶ�����ǰλ�ö�Ӧ������ƫ��λ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SeekToPhys() ;
        
private:
    
    /** ������ӿ�
    */
    IInStreamPtr m_spStream ;
    
    /** �߼�λ��
    */
    uint64_t m_virtPos;
    
    /** ����λ��
    */
    uint64_t m_physPos;
    
    /** ���ݳ���
    */
    uint64_t m_size;
    
    /** ��ʼƫ��
    */
    uint64_t m_startOffset;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCLimitedInStream>   RCLimitedInStreamPtr ;

END_NAMESPACE_RCZIP

#endif //__RCLimitedInStream_h_
