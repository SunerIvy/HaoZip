/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDI1Decoder_h_
#define __RCPPMDI1Decoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD I rev 1 ������
*/
class RCPPMDI1Decoder :
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetDecoderProperties2
                         //,
                         //ICompressSetInStream,
                         //ICompressSetOutStreamSize,
                         //ISequentialInStream
                        >
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDI1Decoder();

    /** Ĭ����������
    */
    ~RCPPMDI1Decoder();

public:

    /** ����
    @param [in] inStream ������
    @param [in] outStream �����
    @param [in] inSize �����С
    @param [in] outSize �����С
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ; 
    
    /** ���ý���������
    @param [in] data ����ָ��
    @param [in] size ��С
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
private:

    /** ˳��
    */
    uint32_t m_order;

    /** ʹ���ڴ��С
    */
    uint32_t m_memorySize;

    /** �ָ�ģʽ
    */
    uint32_t m_restoreMethod;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDI1Decoder_h_
