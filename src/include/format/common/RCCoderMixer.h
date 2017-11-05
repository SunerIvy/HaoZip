/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCoderMixer_h_
#define __RCCoderMixer_h_ 1

#include "common/RCVector.h"
#include "interface/ICoder.h"

BEGIN_NAMESPACE_RCZIP

struct RCCoderMixerBindPair
{
    /** ��������
    */
    uint32_t m_inIndex;

    /** �������
    */
    uint32_t m_outIndex;
};

struct RCCoderMixserCoderStreamsInfo
{
    /** ����������
    */
    uint32_t m_numInStreams;

    /** ���������
    */
    uint32_t m_numOutStreams;
};

struct RCCoderMixserBindInfo
{
    /** ��ϱ���������Ϣ
    */
    RCVector<RCCoderMixserCoderStreamsInfo> m_coders;

    /** ��ϱ���������Ϣ
    */
    RCVector<RCCoderMixerBindPair> m_bindPairs;

    /** ����������
    */ 
    RCVector<uint32_t> m_inStreams;

    /** ���������
    */
    RCVector<uint32_t> m_outStreams;

    /** ���
    */
    void Clear() ;

    /** ��ȡ���ĸ���
    @param [out] numInStreams �����������ĸ���
    @param [out] numOutStreams ����������ĸ���
    */
    void GetNumStreams(uint32_t& numInStreams, uint32_t& numOutStreams) const ;

    /** ���������в��Ұ���Ϣ
    @param [in] inStream ������������
    @return ���� ����Ϣ������
    */
    int32_t FindBinderForInStream(uint32_t inStream) const ;    

    /** ��������в��Ұ���Ϣ
    @param [in] outStream ������������
    @return ���ذ���Ϣ������
    */
    int32_t FindBinderForOutStream(uint32_t outStream) const ;

    /** ��ȡ�������еı���������
    @param [in] coderIndex ����������
    @return �����������еı���������
    */
    uint32_t GetCoderInStreamIndex(uint32_t coderIndex) const ;

    /** ��ȡ������еı���������
    @param [in] coderIndex ����������
    @return ����������еı���������
    */
    uint32_t GetCoderOutStreamIndex(uint32_t coderIndex) const ;

    /** ���������в���
    @param [in] streamIndex ������
    @param [in] coderIndex ����������
    @param [out] coderStreamIndex ������������
    @return �ɹ�����RC_S_OK�����򷵻�RC_E_FAIL
    */
    HResult FindInStream(uint32_t streamIndex, 
                         uint32_t& coderIndex,
                         uint32_t& coderStreamIndex) const ;
    /** ��������в���
    @param [in] streamIndex ������
    @param [in] coderIndex ����������
    @param [out] coderStreamIndex ������������
    @return �ɹ�����RC_S_OK�����򷵻�RC_E_FAIL
    */
    HResult FindOutStream(uint32_t streamIndex, 
                          uint32_t& coderIndex,
                          uint32_t& coderStreamIndex) const ;
};

class RCCoderMixserBindReverseConverter
{
public:

    /** ���캯��
    */
    RCCoderMixserBindReverseConverter(const RCCoderMixserBindInfo& srcBindInfo);

    /** ���������ϱ���������Ϣ
    @param [out] destBindInfo ���ػ�ϱ���������Ϣ
    */
    void CreateReverseBindInfo(RCCoderMixserBindInfo& destBindInfo);

public:

    /** ����������
    */
    uint32_t m_numSrcInStreams;

    /** Ŀ�����Դ����map
    */
    RCVector<uint32_t> m_destOutToSrcInMap;

private:

    /** ���������
    */
    uint32_t m_numSrcOutStreams;

    /** Դ��ϱ���������Ϣ
    */
    RCCoderMixserBindInfo m_srcBindInfo;

    /** Դ����Ŀ�����map
    */
    RCVector<uint32_t> m_srcInToDestOutMap;

    /** Դ���Ŀ������map
    */
    RCVector<uint32_t> m_srcOutToDestInMap;

    /** Ŀ������Դ���map
    */
    RCVector<uint32_t> m_destInToSrcOutMap;
};

struct RCCoderMixserCoderInfo
{
    /** ѹ��������
    */
    ICompressCoderPtr m_coder;

    /** ѹ��������
    */
    ICompressCoder2Ptr m_coder2;

    /** ����������
    */
    uint32_t m_numInStreams;

    /** ���������
    */
    uint32_t m_numOutStreams;

    /** �����С
    */
    RCVector<uint64_t> m_inSizes;

    /** �����С
    */
    RCVector<uint64_t> m_outSizes;

    /** �����Сָ��
    */
    RCVector<const uint64_t*> m_inSizePointers;

    /** �����Сָ��
    */
    RCVector<const uint64_t*> m_outSizePointers;

    /** ���캯��
    */
    RCCoderMixserCoderInfo(uint32_t numInStreams, uint32_t numOutStreams);

    /** ���ñ���/��������Ϣ
    @param [in] inSizes �����С
    @param [in] outSizes �����С
    */
    void SetCoderInfo(const uint64_t** inSizes, const uint64_t** outSizes);

    /** ����ID��ѯ�ӿ�
    @param [in] iid ����ѯ�Ľӿ�ID
    @param [out] outObject �����ѯ�ɹ����򱣴����ӿ�ָ�룬���������ü���
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    HResult QueryInterface(RC_IID iid, void** outObject) const ;
};

class RCCoderMixer
{
public:

    /** ���û�ϱ���������Ϣ
    @param [in] bindInfo ��ϱ���������Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    virtual HResult SetBindInfo(const RCCoderMixserBindInfo& bindInfo) = 0 ;

    /** ���³�ʼ��
    */
    virtual void ReInit() = 0;

    /** ���ñ���/��������Ϣ
    @param [in] coderIndex ����������
    @param [in] inSizes �����С
    @param [in] outSizes �����С
    */
    virtual void SetCoderInfo(uint32_t coderIndex, const uint64_t** inSizes, const uint64_t** outSizes) = 0 ;

protected:

    /** Ĭ����������
    */
    ~RCCoderMixer() {} ;
};

END_NAMESPACE_RCZIP

#endif //__RCCoderMixer_h_
