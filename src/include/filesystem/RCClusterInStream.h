/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCClusterInStream_h_
#define __RCClusterInStream_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCClusterInStream:
    public IUnknownImpl<IInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCClusterInStream() ;
    
    /** Ĭ����������
    */
    ~RCClusterInStream() ;
    
public:
    
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
    @param [out] newPosition ��������ļ�ƫ��
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult Seek(int64_t offset, RC_STREAM_SEEK seekOrigin, uint64_t* newPosition) ;

public:
    
    /** �ƶ���ָ������λ��
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    HResult SeekToPhys() ;
    
    /** ��ʼ������λ�ļ�ƫ��
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    HResult InitAndSeek() ;
    
public:
    
    /** �������ӿ�
    */
    IInStreamPtr m_stream ;
    
    /** ��ʼƫ��λ��
    */
    uint64_t m_startOffset ;
    
    /** ��С
    */
    uint64_t m_size ;
    
    /** �߼����ַ
    */
    int32_t m_blockSizeLog ;
    
    /** λ������
    */
    RCVector<uint32_t> m_vector ;
    
private:
    
    /** ����λ��
    */
    uint64_t m_virtPos;
    
    /** ����λ��
    */
    uint64_t m_physPos;
    
    /** ��ǰλ��
    */
    uint32_t m_curRem;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCClusterInStream>   RCClusterInStreamPtr ;

END_NAMESPACE_RCZIP

#endif //__RCClusterInStream_h_
