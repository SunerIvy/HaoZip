/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCShrinkDecoder_h_
#define __RCShrinkDecoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

/** Shrink ������
*/
class RCShrinkDecoder:
    public IUnknownImpl<ICompressCoder>
{
public:
    /** �������ݶ���
    */
    static const int32_t s_kNumMaxBits = 13 ;
    static const uint32_t s_kNumItems = 1 << s_kNumMaxBits ;
    
public:

    /** Ĭ�Ϲ��캯��
    */
    RCShrinkDecoder() ;
    
    /** Ĭ����������
    */
    ~RCShrinkDecoder() ;

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

    /** parents
    */
    uint16_t m_parents[s_kNumItems] ;

    /** ��׺
    */
    byte_t m_suffixes[s_kNumItems] ;

    /** stack
    */
    byte_t m_stack[s_kNumItems] ;

    /** �Ƿ����
    */
    bool m_isFree[s_kNumItems] ;

    /** �Ƿ�Parent
    */
    bool m_isParent[s_kNumItems] ;
    
private:

    /** �����С
    */
    static const uint32_t s_kBufferSize = (1 << 20);

    /** ��С����λ
    */
    static const int s_kNumMinBits = 9;
};

END_NAMESPACE_RCZIP

#endif //__RCShrinkDecoder_h_
