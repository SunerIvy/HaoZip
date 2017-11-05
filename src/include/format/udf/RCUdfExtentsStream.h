/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfExtentsStream_h_
#define __RCUdfExtentsStream_h_ 1

#include "base/RCTypes.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "format/udf/RCUdfIn.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** Udf Seek
*/
struct RCUdfSeekExtent
{
    /** ����
    */
    uint64_t m_phy ;

    /** ����
    */
    uint64_t m_virt ;
};

/** Udf Extents Stream
*/
class RCUdfExtentsStream:
    public IUnknownImpl<IInStream>
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCUdfExtentsStream() ;
    
    /** ��ʼ��
    */
    void Init();
    
    /** �ͷ���
    */
    void ReleaseStream() ;

public:
    
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

public:
    
    /** ��Ӧ�ļ���������
    */
    IInStreamPtr m_stream;
    
    /** ����λ�����ļ�����ʵλ�õ�ӳ���
    */
    RCVector<RCUdfSeekExtent> m_extents ;
    
private:

    /** ��λ������ƫ��λ��
    */
    HResult SeekToPhys() ;
       
private:

    /** ����λ��
    */
    uint64_t m_phyPos ;

    /** ����λ��
    */
    uint64_t m_virtPos ;

    /** �Ƿ�Seek
    */
    bool m_needStartSeek ;
};

END_NAMESPACE_RCZIP

#endif //__RCUdfExtentsStream_h_
