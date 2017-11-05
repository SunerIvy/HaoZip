/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtExtractProgressMixer_h_
#define __RCMtExtractProgressMixer_h_ 1

#include "base/RCNonCopyable.h"
#include "interface/ICoder.h"
#include "thread/RCMutex.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCMtLocalProgress ;

class RCMtExtractProgressMixer:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtExtractProgressMixer() ;
    
    /** Ĭ����������
    */
    ~RCMtExtractProgressMixer() ;

public:
    
    /** ��ʼ��
    @param [in] numItems ������Ŀ����
    @param [in] progress ���Ƚӿ�
    */
    void Init(uint32_t numItems, RCMtLocalProgress* progress);
    
    /** �Խ��������³�ʼ��
    @param [in] index ���������
    */
    void Reinit(uint32_t index);
    
    /** ���ý���
    @param [in] index ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SetRatioInfo(uint32_t index, uint64_t inSize, uint64_t outSize);
    
    /** �����������ݴ�С
    @param [in] value �������ݴ�Сֵ
    */
    void SetInSize(uint64_t value) ;
    
    /** ����������ݴ�С
    @param [in] value ������ݴ�Сֵ
    */
    void SetOutSize(uint64_t value) ;
    
    /** �Ե�ǰ���ݻص�����
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SetCur() ;
    
private:
    
    /** ��ѹ���ȹ���ӿ�
    */
    RCMtLocalProgress* m_progressSpec ;
    
    /** ��ѹ���Ƚӿ�
    */
    ICompressProgressInfoPtr m_progress ;
    
    /** �������ݴ�С�б�
    */
    RCVector<uint64_t> m_inSizes ;
    
    /** ������ݴ�С�б�
    */
    RCVector<uint64_t> m_outSizes ;
    
    /** ���������ܴ�С
    */
    uint64_t m_totalInSize ;
    
    /** ��������ܴ�С
    */
    uint64_t m_totalOutSize ;
    
    /** ���߳�ͬ����
    */
    RCMutex m_lock ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtExtractProgressMixer_h_
