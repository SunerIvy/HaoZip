/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateCOMEncoder64_h_
#define __RCDeflateCOMEncoder64_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "compress/deflate/RCDeflateEncoder.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate 64������
*/
class RCDeflateCOMEncoder64:
    public IUnknownImpl2<ICompressCoder,
                         ICompressSetCoderProperties
                        >,
    public RCDeflateEncoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateCOMEncoder64() ;
    
    /** Ĭ����������
    */
    virtual ~RCDeflateCOMEncoder64() ;
    
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
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateCOMEncoder64_h_
