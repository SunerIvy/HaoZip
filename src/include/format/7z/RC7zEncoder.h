/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zEncoder_h_
#define __RC7zEncoder_h_ 1

#include "format/common/RCCoderMixerMT.h"
#include "format/7z/RC7zItem.h"
#include "format/7z/RC7zCompressionMode.h"

BEGIN_NAMESPACE_RCZIP

class RC7zEncoder
{
public:

    /** ���캯��
    */
    RC7zEncoder(const RC7zCompressionMethodMode &options) ;

    /** Ĭ����������
    */
    ~RC7zEncoder() ;
    
public:

    /** �������
    */
    HResult EncoderConstr() ;

    /** ����
    @param [in] codecsInfo ���������
    @param [in] inStream ������
    @param [in] inStreamSize ��������С
    @param [in] inSizeForReduce �����С
    @param [in] folderItem �ļ�����
    @param [in] outStream �����
    @param [in] packSizes ���Ĵ�С
    @param [in] compressProgress ѹ�����ȹ�����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Encode( ICompressCodecsInfo* codecsInfo,
                    ISequentialInStream* inStream,
                    const uint64_t* inStreamSize, 
                    const uint64_t* inSizeForReduce,
                    RC7zFolder& folderItem,
                    ISequentialOutStream* outStream,
                    RCVector<uint64_t>& packSizes,
                    ICompressProgressInfo* compressProgress) ;
    
private:

    /** ������ϱ���
    @param [in] codecsInfo ���������
    @param [in] inSizeForReduce �����С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult CreateMixerCoder(ICompressCodecsInfo* codecsInfo,
                             const uint64_t* inSizeForReduce) ;

private:

    /** �ӻ�ϱ������Ϣ�õ��ļ�����Ϣ
    @param [in] bindInfo ��ϱ������Ϣ
    @param [in] decompressionMethods ����id
    @param [out] folder ����ļ����ļ�
    */
    static void ConvertBindInfoToFolderItemInfo(RCCoderMixserBindInfo& bindInfo,
                                                const RCVector<RCMethodID>& decompressionMethods,
                                                RC7zFolder& folder) ;
private:

    /** ���̵߳Ļ�ϱ���
    */
    RCCoderMixerMT* m_mixerCoderSpec ;

    /** ��ϱ�����
    */
    ICompressCoder2Ptr m_mixerCoder ;

    /** ������Ϣ
    */
    RCVector<RC7zCoderInfo> m_codersInfo;  

    /** ѹ��ģʽ
    */
    RC7zCompressionMethodMode m_options;

    /** ��ϱ������Ϣ
    */
    RCCoderMixserBindInfo m_bindInfo;

    /** ����Ļ�ϱ������Ϣ
    */
    RCCoderMixserBindInfo m_decompressBindInfo;

    /** ����Ļ�ϱ������Ϣת����
    */
    RCCoderMixserBindReverseConverter* m_bindReverseConverter;

    /** ����ģʽ
    */
    RCVector<RCMethodID> m_decompressionMethods;

    /** �Ƿ��ѹ���
    */
    bool m_constructed;
};

END_NAMESPACE_RCZIP

#endif //__RC7zEncoder_h_
