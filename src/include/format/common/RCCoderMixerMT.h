/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCoderMixerMT_h_
#define __RCCoderMixerMT_h_ 1

#include "format/common/RCCoderMixer.h"
#include "locked/RCVirtThread.h"
#include "locked/RCStreamBinder.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

struct RCCoderMixerCoder: 
    public RCCoderMixserCoderInfo, 
    public RCVirtThread
{
    /** ���
    */
    HResult m_result;

    /** ������
    */
    RCVector<ISequentialInStreamPtr> m_inStreams;

    /** �����
    */
    RCVector<ISequentialOutStreamPtr> m_outStreams;

    /** ������ָ��
    */
    RCVector<ISequentialInStream*> m_inStreamPointers;

    /** �����ָ��
    */
    RCVector<ISequentialOutStream*> m_outStreamPointers;

    /** ���캯��
    */
    RCCoderMixerCoder(uint32_t numInStreams, uint32_t numOutStreams);

    /** ���ñ���/��������Ϣ
    @param [in] inSizes �����С
    @param [in] outSizes �����С
    */
    void SetCoderInfo(const uint64_t** inSizes, const uint64_t** outSizes);

    /** ����
    */
    virtual void Execute();

    /** ����
    @param [in] progress ѹ�����ȹ�����
    */
    void Code(ICompressProgressInfo* progress) ;
};

/** RCCoderMixerCoder����ָ��
*/
typedef RCSharedPtr<RCCoderMixerCoder> RCCoderMixerCoderPtr ;

class RCCoderMixerMT:
    public IUnknownImpl<ICompressCoder2>,
    public RCCoderMixer
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCoderMixerMT() ;
    
    /** Ĭ����������
    */
    ~RCCoderMixerMT() ;
    
public:

    /** ���û�ϱ���������Ϣ
    @param [in] bindInfo ��ϱ���������Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetBindInfo(const RCCoderMixserBindInfo& bindInfo) ;

    /** ��ӱ�����
    @param [in] coder ������
    */
    void AddCoder(ICompressCoder* coder) ;

    /** ��ӱ�������
    @param [in] coder ��������
    */
    void AddCoder2(ICompressCoder2* coder) ;

    /** ���ý��ȱ�������
    @param [in] coderIndex ��������
    */
    void SetProgressCoderIndex(int32_t coderIndex) ;

    /** ���³�ʼ��
    */
    void ReInit() ;

    /** ���ñ���/��������Ϣ
    @param [in] coderIndex ����������
    @param [in] inSizes �����С
    @param [in] outSizes �����С
    */
    void SetCoderInfo(uint32_t coderIndex, const uint64_t** inSizes, const uint64_t** outSizes) ;

    /** ��ȡд�����С
    @param [in] binderIndex ��ϱ�����������
    @return ���ش����С
    */
    uint64_t GetWriteProcessedSize(uint32_t binderIndex) const ;

    /** ѹ��/��ѹ����
    @param [in] inStreams ��������Ϣ
    @param [in] outStreams �������Ϣ
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult Code(const std::vector<in_stream_data>& inStreams,
                         const std::vector<out_stream_data>& outStreams, 
                         ICompressProgressInfo* progress) ;
                             
public:

    /** ��ϱ�����
    */
    RCVector<RCCoderMixerCoderPtr> m_coders ;
    
private:

    /** ��ӱ�����������Ϣ
    */
    void AddCoderCommon() ;

    /** ��ʼ��
    @param [in] inStreams ������
    @param [in] outStreams �����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Init(const std::vector<in_stream_data>& inStreams,
                 const std::vector<out_stream_data>& outStreams) ;

    /** ����ͷ���
    @param [in] code ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReturnIfError(HResult code) ;
    
private:

    /** RCStreamBinder����ָ��
    */
    typedef RCSharedPtr<RCStreamBinder> RCStreamBinderPtr ;

    /** ��ϱ���������Ϣ
    */
    RCCoderMixserBindInfo m_bindInfo;

    /** ���İ���Ϣ
    */
    RCVector<RCStreamBinderPtr> m_streamBinders;

    /** ���ȱ�������
    */
    int32_t m_progressCoderIndex ;
};

END_NAMESPACE_RCZIP

#endif //__RCCoderMixerMT_h_
