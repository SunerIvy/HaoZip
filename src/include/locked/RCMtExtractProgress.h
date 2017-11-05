/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtExtractProgress_h_
#define __RCMtExtractProgress_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCMtExtractProgressMixer ;

class RCMtExtractProgress:
    public IUnknownImpl<ICompressProgressInfo>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtExtractProgress() ;
    
    /** Ĭ����������
    */
    ~RCMtExtractProgress() ;
    
public:
    
    /** ��ʼ��
    @param [in] progress �̰߳�ȫ�Ľ�ѹ���Ƚӿ�
    @param [in] index ��ǰ�ļ����
    */
    void Init(RCMtExtractProgressMixer* progress, uint32_t index) ;
    
    /** ���³�ʼ��
    */
    void Reinit() ;
    
    /** ����ѹ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) ;
    
private:
    
    /** ��ѹ���Ƚӿ�
    */
    RCMtExtractProgressMixer* m_progress ;
    
    /** ������ļ����
    */
    uint32_t m_index ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtExtractProgress_h_
