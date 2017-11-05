/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBZip2Update_h_
#define __RCBZip2Update_h_ 1

#include "interface/IArchive.h"
#include "interface/ICoder.h"

BEGIN_NAMESPACE_RCZIP

class RCBZip2Update
{
public:

    /** ѹ������
    @param [in] codecsInfo ���������
    @param [in] unpackSize ��ѹ���С
    @param [in] outStream �����
    @param [in] indexInClient client�е�����
    @param [in] dictionary �ֵ��С
    @param [in] numPasses passes
    @param [in] numThreads �߳���
    @param [in] updateCallback ���¹������ص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult UpdateArchive(ICompressCodecsInfo* codecsInfo,
                                 uint64_t unpackSize,
                                 ISequentialOutStream* outStream,
                                 int32_t indexInClient,
                                 uint32_t dictionary,
                                 uint32_t numPasses,
                                 uint32_t numThreads,
                                 IArchiveUpdateCallback* updateCallback) ;

};

END_NAMESPACE_RCZIP

#endif //__RCBZip2Update_h_
