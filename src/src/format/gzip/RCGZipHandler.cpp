/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

//include files
#include "format/gzip/RCGZipHandler.h"
#include "interface/RCMethodDefs.h"
#include "common/RCCreateCoder.h"

/////////////////////////////////////////////////////////////////
//RCGZipHandler class implementation

BEGIN_NAMESPACE_RCZIP

RCGZipHandler::RCGZipHandler():
    m_startPosition(0),
    m_headerSize(0),
    m_packSize(0),
    m_packSizeDefined(false)
{

}

HResult RCGZipHandler::SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo)
{
    if (!compressCodecsInfo)
    {
        return RC_S_FALSE;
    }
    ICompressCoderPtr deflateDecoder;
    HResult hr = RCCreateCoder::CreateCoder(compressCodecsInfo,
                                            RCMethod::ID_COMPRESS_DEFLATE_COM,
                                            deflateDecoder,
                                            false) ;
    if (!IsSuccess(hr))
    {
        return hr ;
    }
    IGZipResumeDecoderPtr decoderSpec ;
    hr = deflateDecoder.QueryInterface(IGZipResumeDecoder::IID, (void**)decoderSpec.GetAddress()) ;
    if (!IsSuccess(hr))
    {
        return hr ;
    }
    m_decoder = deflateDecoder ;
    m_decoderSpec = decoderSpec ;
    m_compressCodecsInfo = compressCodecsInfo ;
    return RC_S_OK;
}

HResult RCGZipHandler::SetProperties(const RCPropertyNamePairArray& propertyArray) 
{
    return m_method.SetProperties(propertyArray) ;
}

END_NAMESPACE_RCZIP
