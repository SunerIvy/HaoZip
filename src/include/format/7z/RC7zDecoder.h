/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zDecoder_h_
#define __RC7zDecoder_h_ 1

#include "format/common/RCCoderMixerMT.h"
#include "format/7z/RC7zItem.h"
#include "interface/IPassword.h"
#include "interface/ICoder.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

struct RC7zBindInfoEx: 
    public RCCoderMixserBindInfo
{
    /** ������id
    */
    RCVector<RCMethodID> m_coderMethodIDs;

    /** ���
    */
    void Clear()
    {
        RCCoderMixserBindInfo::Clear() ;
        m_coderMethodIDs.clear() ;
    }
};

class RC7zDecoder
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zDecoder() ;
    
    /** Ĭ����������
    */
    ~RC7zDecoder() ;
    
public:

    /** ����
    @param [in] codecsInfo ���������
    @param [in] inStream ������
    @param [in] startPos ��ʼλ��
    @param [in] packSizes ����С
    @param [in] folderInfo �ļ�����Ϣ
    @param [in] outStream �����
    @param [in] compressProgress ѹ�����ȹ�����
    @param [in] getTextPassword ���������
    @param [in] passwordIsDefined �Ƿ�������
    @param [in] numThreads �߳���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Decode(ICompressCodecsInfo* codecsInfo,
                   IInStream* inStream,
                   uint64_t startPos,
                   const uint64_t* packSizes,
                   const RC7zFolder& folderInfo,
                   ISequentialOutStream* outStream,
                   ICompressProgressInfo* compressProgress,
                   ICryptoGetTextPassword* getTextPassword, 
                   bool& passwordIsDefined,
                   uint32_t numThreads) ;

private:

    /** ���ļ�����Ϣ�õ�����Ϣ
    @param [in] folder �ļ�����Ϣ
    @param [out] bindInfo ���ذ���Ϣ
    */
    static void ConvertFolderItemInfoToBindInfo(const RC7zFolder& folder,
                                                RC7zBindInfoEx& bindInfo) ;

    /** �����Ƿ����
    @param [in] a1 ����1
    @param [in] a2 ����2
    @return ��ȷ���true�����򷵻�false
    */
    static bool AreCodersEqual(const RCCoderMixserCoderStreamsInfo& a1,
                               const RCCoderMixserCoderStreamsInfo& a2) ;

    /** ��ϱ������Ϣ�еİ������Ƿ����
    @param [in] a1 ��ϱ������Ϣ1
    @param [in] a2 ��ϱ������Ϣ2
    @return ��ȷ���true�����򷵻�false
    */
    static bool AreBindPairsEqual(const RCCoderMixerBindPair& a1, 
                                  const RCCoderMixerBindPair& a2) ;

    /** ����չ��Ϣ�Ƿ����
    @param [in] a1 ����չ��Ϣ1
    @param [in] a2 ����չ��Ϣ2
    @return ��ȷ���true�����򷵻�false
    */
    static bool AreBindInfoExEqual(const RC7zBindInfoEx& a1, 
                                   const RC7zBindInfoEx& a2) ;
                                                                     
private:

    /** �Ƿ��а���Ϣ
    */
    bool m_bindInfoExPrevIsDefined ;

    /** ����Ϣ
    */ 
    RC7zBindInfoEx m_bindInfoExPrev ;

    /** ���̵߳Ļ�ϱ���
    */
    RCCoderMixerMT* m_mixerCoderMTSpec ;

    /** ��ϱ��빫����Ϣ
    */
    RCCoderMixer* m_mixerCoderCommon ;
  
    /** ��ϱ�����
    */
    ICompressCoder2Ptr m_mixerCoder;

    /** ������
    */
    RCVector<IUnknownPtr> m_decoders;
};

END_NAMESPACE_RCZIP

#endif //__RC7zDecoder_h_
