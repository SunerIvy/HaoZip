/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCopyCoder_h_
#define __RCCopyCoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Copy ������
*/
class RCCopyCoder:
    public IUnknownImpl2<ICompressCoder,
                         ICompressGetInStreamProcessedSize>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCopyCoder() ;
    
    /** Ĭ����������
    */
    ~RCCopyCoder() ;
    
public:
    
    /** ��ȡ�Ѿ�����Ĵ�С
    @return �����Ѿ������С
    */
    uint64_t GetTotalSize(void) const ; 
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ;

    /** ��ȡ��������ȡ�����ݳ���
    @param [out] size �������ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult GetInStreamProcessedSize(uint64_t& size) ;
 
private:
    
    /** ������
    */
    byte_t* m_buffer ;
    
    /** �Ѿ�����Ĵ�С
    */
    uint64_t m_totalSize ;
};

END_NAMESPACE_RCZIP

#endif //__RCCopyCoder_h_
