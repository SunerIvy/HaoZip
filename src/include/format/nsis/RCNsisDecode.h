/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCNsisDecode_h_
#define __RCNsisDecode_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

namespace RCNsisMethodType
{
    enum EEnum
    {
        kCopy,
        kDeflate,
        kBZip2,
        kLZMA
    };
}

class RCNsisDecode
{
public:

    /** ��ʼ��
    @param [in] codecsInfo ���������ָ��
    @param [in] inStream ����
    @param [in] method ѹ������
    @param [in] thereIsFilterFlag ���˱�־
    @param [out] useFilter �����Ƿ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Init(ICompressCodecsInfo* codecsInfo,
                 IInStream* inStream,
                 RCNsisMethodType::EEnum method,
                 bool thereIsFilterFlag,
                 bool& useFilter) ;

    /** ��ȡ����
    @param [out] data ��Ŷ�ȡ����Ļ�������ַ
    @param [in] processedSize ����ʵ�ʶ����Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Read(void* data, size_t* processedSize) ;

    /** �ͷ�
    */
    void Release()
    {
        m_filterInStream.Release() ;
        m_codecInStream.Release() ;
        m_decoderInStream.Release() ;
    }
    
private:

    /** ѹ������
    */
    RCNsisMethodType::EEnum m_method ;

    /** ����������
    */
    ISequentialInStreamPtr m_filterInStream ;

    /** ����������
    */
    ISequentialInStreamPtr m_codecInStream ;

    /** ����������
    */
    ISequentialInStreamPtr m_decoderInStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCNsisDecode_h_
