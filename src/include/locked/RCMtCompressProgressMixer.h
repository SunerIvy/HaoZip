/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtCompressProgressMixer_h_
#define __RCMtCompressProgressMixer_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/ICoder.h"
#include "thread/RCMutex.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCMtCompressProgressMixer:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtCompressProgressMixer() ;
    
    /** Ĭ����������
    */
    ~RCMtCompressProgressMixer() ;

public:
    
    /** ��ʼ��
    @param [in] numItems ������Ŀ����
    @param [in] progress ���Ƚӿ�
    @param [in] mtProgress �̰߳�ȫ���Ƚӿ�
    */
    void Init(uint32_t numItems, ICompressProgressInfo* progress, IMtCompressProgressInfo* mtProgress);
    
    /** �Խ��������³�ʼ��
    @param [in] index ���������
    */
    void Reinit(uint32_t index);
    
    /** ���ý���
    @param [in] index ���������
    @param [in] itemIndex ��ǰ�����ļ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SetRatioInfo(uint32_t index, uint32_t itemIndex, uint64_t inSize, uint64_t outSize);
    
private:
    
    /** ���Ƚӿ�
    */
    ICompressProgressInfoPtr m_progress;
    
    /** �̰߳�ȫ�Ľ��Ƚӿ�
    */
    IMtCompressProgressInfoPtr m_mtProgress;
    
    /** ���������ܴ�С�б�
    */
    RCVector<uint64_t> m_inSizes ;
        
    /** ��������ܴ�С�б�
    */
    RCVector<uint64_t> m_outSizes ;
        
    /** ���������ܴ�С
    */
    uint64_t m_totalInSize ;
    
    /** ��������ܴ�С
    */
    uint64_t m_totalOutSize ;
    
    /** �̰߳�ȫͬ����
    */
    RCMutex m_lock ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtCompressProgressMixer_h_
