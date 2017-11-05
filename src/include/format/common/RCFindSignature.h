/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFindSignature_h_
#define __RCFindSignature_h_ 1

#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

class RCFindSignature
{
public:
    
    /** ���������в����ļ���ʽǩ��
    @param [in] stream ������
    @param [in] signature ǩ�����ݵĿ�ʼ��ַ
    @param [in] signatureSize ǩ�����ݳ���
    @param [in] limit ���ƴ�������ƥ�����ݵ���󳤶�����
    @param [out] resPos ���ǩ�����ҳɹ�������ǩ�����������е�ƫ��
    @return �ɹ�����RC_S_OK��ʧ�ܷ��ش�����
    */
    static HResult FindSignatureInStream(ISequentialInStream* stream,
                                         const byte_t* signature, 
                                         uint32_t signatureSize,
                                         const uint64_t* limit, 
                                         uint64_t& resPos) ;
};

END_NAMESPACE_RCZIP

#endif //__RCFindSignature_h_
