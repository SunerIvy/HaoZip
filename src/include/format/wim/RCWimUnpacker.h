/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimUnpacker_h_
#define __RCWimUnpacker_h_ 1

#include "common/RCBuffer.h"
#include "format/wim/RCWimDecoder.h"
#include "format/wim/RCWimResource.h"
#include "interface/ICoder.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

/** Wim Unpacker
*/
class RCWimUnpacker
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimUnpacker(ICompressCodecsInfo* compressCodecsInfo) ;
    
    /** Ĭ����������
    */
    ~RCWimUnpacker() ;
    
public:

    /** ��ѹ
    @param [in] inStream ������
    @param [in] resource WIM��Դ����
    @param [in] lzxMode lzxģʽ
    @param [in] outStream �����
    @param [in] progress ���Ȼص��ӿ�
    @param [out] digest ��ѹ���ݵ�ַ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Unpack( IInStream* inStream, 
                    const RCWimResource& resource,
                    bool lzxMode,
                    ISequentialOutStream* outStream, 
                    ICompressProgressInfo* progress,
                    byte_t* digest);
    
    /** ���ñ������������ӿ�ָ��
    @param [in] compressCodecsInfo ���������ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult SetCompressCodecsInfo(ICompressCodecsInfo* compressCodecsInfo) ;
    
private:

    /** ��ѹ
    @param [in] inStream ������
    @param [in] resource 
    @param [in] lzxMode lzxģʽ
    @param [in] outStream �����
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Unpack(IInStream* inStream, 
                   const RCWimResource& resource, 
                   bool lzxMode,
                   ISequentialOutStream* outStream, 
                   ICompressProgressInfo* progress);
    
private:

    /** copy coder
    */
    ICompressCoderPtr m_copyCoder;

    /** lzx decoder
    */
    ICompressCoderPtr m_lzxDecoder;

    /** xpress decoder
    */
    RCWimDecoder m_xpressDecoder;

    /** ����
    */
    RCByteBuffer m_sizesBuf;
    
    /** ������������
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo ;
};

END_NAMESPACE_RCZIP

#endif //__RCWimUnpacker_h_
