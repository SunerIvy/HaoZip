/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZDecoder_h_
#define __RCZDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Z ������
*/
class RCZDecoder:
    public IUnknownImpl2<ICompressCoder,ICompressSetDecoderProperties2>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCZDecoder() ;
    
    /** Ĭ����������
    */
    ~RCZDecoder() ;

public:

    /** �ͷſռ�
    */
    void Free() ;
    
public:
    
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

    /** ���ý�ѹ����
    @param [in] data ��������
    @param [in] size ���ݳ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetDecoderProperties2(const byte_t* data, uint32_t size) ;
    
private:
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @throws ʧ�����쳣
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult CodeReal(ISequentialInStream* inStream,
                             ISequentialOutStream* outStream, 
                             const uint64_t* inSize, 
                             const uint64_t* outSize,
                             ICompressProgressInfo* progress) ;

private:

    /** ����
    */
    byte_t m_properties;

    /** ���λ��
    */
    int32_t m_numMaxBits;

    /** parents
    */
    uint16_t* m_parents;

    /** ��׺
    */
    byte_t* m_suffixes;

    /** stack
    */
    byte_t* m_stack;
};

END_NAMESPACE_RCZIP

#endif //__RCZDecoder_h_
