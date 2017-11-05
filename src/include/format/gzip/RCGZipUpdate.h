/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCGZipUpdate_h_
#define __RCGZipUpdate_h_ 1

#include "interface/IStream.h"
#include "interface/IArchive.h"

BEGIN_NAMESPACE_RCZIP

class RCGZipItem ;
class RCGZipDeflateProps ;
class ICompressCodecsInfo ;

class RCGZipUpdate
{
public:

    /** ѹ������
    @param [in] codecs ���������
    @param [in] outStream �����
    @param [in] unpackSize ��ѹ��С
    @param [in] newItem ����
    @param [in] deflateProps Ĭ������
    @param [in] updateCallback ѹ���ص�����ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult UpdateArchive(ICompressCodecsInfo* codecsInfo,
                                 ISequentialOutStream* outStream,
                                 uint64_t unpackSize,
                                 const RCGZipItem& newItem,
                                 RCGZipDeflateProps& deflateProps,
                                 IArchiveUpdateCallback* updateCallback) ;
};

END_NAMESPACE_RCZIP

#endif //__RCGZipUpdate_h_
