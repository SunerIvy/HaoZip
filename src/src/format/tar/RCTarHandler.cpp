/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#include "format/tar/RCTarHandler.h"
#include "common/RCCreateCoder.h"
#include "interface/RCMethodDefs.h"

BEGIN_NAMESPACE_RCZIP

HResult RCTarHandler::SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo)
{
    if (!compressCodecsInfo)
    {
        return RC_S_FALSE;
    }

    m_compressCodecsInfo = compressCodecsInfo ;
    HResult hr = RCCreateCoder::CreateCoder(m_compressCodecsInfo.Get(), RCMethod::ID_COMPRESS_COPY, m_spCopyCoder, false);
    if ( !IsSuccess(hr) || (m_spCopyCoder == NULL) )
    {
        return hr ;
    }
    return RC_S_OK;
}

END_NAMESPACE_RCZIP