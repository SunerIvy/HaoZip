/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTarOut_h_
#define __RCTarOut_h_ 1

#include "interface/IStream.h"
#include "RCTarItem.h"

BEGIN_NAMESPACE_RCZIP

/** Tar ���
*/
class RCTarOut
{
public: 

    /** ����
    @param [in] outStream �����
    */
    void Create(ISequentialOutStream *outStream);

    /** д���ļ���
    @param [in] item �ļ�����Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteHeaderReal(const RCTarItem &item);

    /** д���ļ���
    @param [in] item �ļ�����Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteHeader(const RCTarItem &item);

    /** ��д�ļ�����
    @param [in] dataSize ���ݴ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult FillDataResidual(uint64_t dataSize);

    /** д���ͷ�ṹ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteFinishHeader();

private:

    /** д���ֽ����� 
    @param [in] buffer ����
    @param [in] size ��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteBytes(const void *buffer, uint32_t size);

private:

    /** �����
    */
    RCComPtr<ISequentialOutStream> m_stream;
};

END_NAMESPACE_RCZIP

#endif //__RCTarOut_h_
