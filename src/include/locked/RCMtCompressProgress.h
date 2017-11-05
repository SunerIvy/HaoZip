/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtCompressProgress_h_
#define __RCMtCompressProgress_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCMtCompressProgressMixer ;

class RCMtCompressProgress:
    public IUnknownImpl<ICompressProgressInfo>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtCompressProgress() ;
    
    /** Ĭ����������
    */
    ~RCMtCompressProgress() ;
    
public:
    
    /** ��ʼ��
    @param [in] progress ѹ�����Ƚӿ�
    @param [in] index �߳����
    */
    void Init(RCMtCompressProgressMixer* progress, uint32_t index) ;
    
    /** ʹ�õ�ǰֵ���³�ʼ��
    */
    void Reinit() ;
    
    /** ��������ѹ�����ļ����
    @param [in] itemIndex ����ѹ�����ļ����
    */
    void SetItemIndex(uint32_t itemIndex) ;
    
    /** ����ѹ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) ;
    
private:
    
    /** ѹ�����Ƚӿ�
    */
    RCMtCompressProgressMixer* m_progress ;
    
    /** �̺߳�
    */
    uint32_t m_index ;
    
    /** ����ѹ�����ļ����
    */
    uint32_t m_itemIndex ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtCompressProgress_h_
