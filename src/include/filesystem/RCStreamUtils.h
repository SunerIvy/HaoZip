/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStreamUtils_h_
#define __RCStreamUtils_h_ 1

#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

/** ��������д������
*/
class RCStreamUtils
{
public:
    
    /** ���������ж�ȡ����
    @param [in] stream �������ӿ�
    @param [out] data ���ݻ�����
    @param [in,out]  size ����������ȡ�ĳ��ȣ����ʵ�ʶ�ȡ�ĳ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    static HResult ReadStream(ISequentialInStream* stream, void* data, size_t* size);
    
    /** ���������ж�ȡ����
    @param [in] stream �������ӿ�
    @param [out] data ���ݻ�����
    @param [in]  size ����������ȡ�ĳ���
    @return �ɹ���ȡsize���ȷ���RC_S_OK, ����ȡ����size���ȷ���RC_S_FALSE, ʧ�ܷ��ش�����
    */
    static HResult ReadStream_FALSE(ISequentialInStream* stream, void* data, size_t size);
    
    /** ���������ж�ȡ����
    @param [in] stream �������ӿ�
    @param [out] data ���ݻ�����
    @param [in]  size ����������ȡ�ĳ���
    @return �ɹ���ȡsize���ȷ���RC_S_OK, ����ȡ����size���ȷ���RC_E_FAIL, ʧ�ܷ��ش�����
    */
    static HResult ReadStream_FAIL(ISequentialInStream* stream, void* data, size_t size);
    
    /** ���������д������
    @param [in] stream �������ӿ�
    @param [in] data ���ݻ�����
    @param [in]  size ����������ȡ�ĳ���
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    static HResult WriteStream(ISequentialOutStream* stream, const void* data, size_t size);
    
    /** �������ƴ�С���������ӿ�
    @param [in] inStream �������ӿ�
    @param [in] pos �������е�������ʼƫ��
    @param [in] size �������ĳ���
    @param [out] resStream ���ش��������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ʧ�ܷ��ش�����
    */
    static HResult CreateLimitedInStream(IInStream* inStream, uint64_t pos, uint64_t size, ISequentialInStream** resStream) ;

private:
    
    /** Ĭ�ϵ����ݿ��С
    */
    static const uint32_t m_kBlockSize = ((uint32_t)1 << 31) ;
};

END_NAMESPACE_RCZIP

#endif //__RCStreamUtils_h_
