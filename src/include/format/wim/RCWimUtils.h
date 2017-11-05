/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimUtils_h_
#define __RCWimUtils_h_ 1

#include "format/wim/RCWimHeader.h"
#include "format/wim/RCWimDatabase.h"
#include "format/wim/RCWimResource.h"
#include "format/wim/RCWimItem.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "common/RCBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** Wim Utils
*/
class RCWimUtils
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCWimUtils(ICompressCodecsInfo* compressCodecsInfo) ;

    /** ��ͷ���
    @param [in] inStream ������
    @param [out] header ͷ�ṹ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadHeader(IInStream* inStream, RCWimHeader& header) ;

    /** ���ĵ�
    @param [in] inStream ������
    @param [in] header ͷ�ṹ
    @param [in] xml
    @param [out] database
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult OpenArchive(IInStream* inStream,
                               const RCWimHeader& header, 
                               RCByteBuffer& xml,
                               RCWimDatabase& database);

    /** ����
    @param [in,out] database
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SortDatabase(RCWimDatabase& database) ;

private:

    /** ��ȡ��
    @param [in] inStream ������
    @param [in] h ͷ�ṹ
    @param [out] db 
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadStreams(IInStream* inStream, const RCWimHeader& h, RCWimDatabase& db) ;

    /** ��ѹ����
    @param [in] inStream ������
    @param [in] resource
    @param [in] lzxMode lzxģʽ
    @param [out] buf ���
    @param [out] digest ժҪ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult UnpackData(IInStream* inStream, const RCWimResource& resource, bool lzxMode, RCByteBuffer& buf, byte_t* digest) ;

    /** ȡ����
    @param [in] p ����
    @param [in] s ���ṹ
    */
    void GetStream(const byte_t* p, RCWimStreamInfo& s) ;

    /** ȡ���ļ�ʱ��
    @param [in] p ����
    @param [out] ft �ļ�ʱ��
    */
    void GetFileTimeFromMem(const byte_t* p, RC_FILE_TIME* ft) ;

    /** ����Ŀ¼
    @param [in] base
    @param [in] pos λ��
    @param [in] size ��С
    @param [in] prefix ǰ׺
    @param [out] items ���б�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ParseDirItem(const byte_t* base, 
                         size_t pos, 
                         size_t size,
                         const RCString& prefix, 
                         RCVector<RCWimItem>& items) ;

    /** ����Ŀ¼
    @param [in] base
    @param [in] size ��С
    @param [in] prefix ǰ׺
    @param [in] items ���б�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ParseDir(const byte_t* base, 
                     size_t size,
                     const RCString& prefix, 
                     RCVector<RCWimItem>& items) ;

    /** ����hash
    @param [in] streams ���б�
    @param [in] sortedByHash ����hash
    @param [in] hash hashֵ
    @return ���ؽ�����
    */
    int32_t FindHash(const RCVector<RCWimStreamInfo>& streams,
                     const RCVector<int32_t>& sortedByHash, 
                     const byte_t* hash) ;

    /** ������������
    */
    ICompressCodecsInfoPtr m_compressCodecsInfo ;
};

END_NAMESPACE_RCZIP

#endif //__RCWimUtils_h_
