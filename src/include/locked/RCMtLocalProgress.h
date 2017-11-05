/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMtLocalProgress_h_
#define __RCMtLocalProgress_h_ 1

#include "interface/ICoder.h"
#include "interface/IProgress.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCMtLocalProgress:
    public IUnknownImpl<ICompressProgressInfo>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMtLocalProgress() ;
    
    /** Ĭ����������
    */
    ~RCMtLocalProgress() ;
    
    /** ��ʼ��
    @param [in] progress ���Ȼص��ӿ�
    @param [in] inSizeIsMain true��ʾ���������ݻص����ȣ�����������ݻص�����
    */
    void Init(IProgress* progress, bool inSizeIsMain) ;
    
    /** ����ǰ�������ݻص����Ƚӿ�
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SetCur() ;
    
    /** ���õ�ǰ������±�ֵ
    @param [in] index ��ǰ������±�ֵ
    */
    void SetIndex(uint32_t index) ;
    
    /** ��ȡ��������ƫ��
    @return ���ؽ�������ƫ��
    */
    uint64_t GetProgressOffset() const ;
    
    /** ��ȡ�������ݴ�С
    @return �����������ݴ�С
    */
    uint64_t GetInSize() const ;
    
     /** ��ȡ������ݴ�С
    @return ����������ݴ�С
    */
    uint64_t GetOutSize() const ;
    
    /** ��ȡ�Ƿ��Զ����ͽ���
    @return ����Զ����ͽ��ȷ���true, ���򷵻�false
    */
    bool IsSendRatio() const ;
    
    /** ��ȡ�����ý���ʱ�Զ��ص�����ɽӿ�
    @return ��������ý���ʱ�Զ��ص�����ɽӿڷ���true, ���򷵻�false
    */
    bool IsSendProgress() const ;
    
    /** ���ý�������ƫ��
    @param [in] value ��������ƫ��
    */
    void SetProgressOffset(uint64_t value) ;
    
    /** �����������ݴ�С
    @param [in] value �������ݴ�С
    */
    void SetInSize(uint64_t value) ;
    
    /** ����������ݴ�С
    @param [in] value ������ݴ�С
    */
    void SetOutSize(uint64_t value) ;
    
    /** �����Ƿ��Զ����ͽ���
    @param [in] value true��ʾ�Ƿ��Զ����ͽ���
    */
    void SetSendRatio(bool value) ;
    
    /** �����Ƿ��Զ����Ͷ��߳̽���
    @param [in] value true��ʾ�Ƿ��Զ����ͽ���
    */
    void SetSendMtRatio(bool value) ;
    
    /** �����Ƿ������ý���ʱ�Զ��ص�����ɽӿ�
    @param [in] value true�����ý���ʱ�Զ��ص�����ɽӿ�
    */
    void SetSendProgress(bool value) ;
    
    /** ����ѹ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) ;
    
private:
    
    /** ���Ƚӿ�
    */
    IProgressPtr m_progress;
    
    /** ѹ�����Ƚӿ�
    */
    ICompressProgressInfoPtr m_ratioProgress;
    
    /** ���߳�ѹ����ѹ����������Ϣ
    */
    IMtCompressProgressInfoPtr m_spMtRatioProgress ;
    
    /** true��ʾ���������ݻص����ȣ�����������ݻص�����
    */
    bool m_inSizeIsMain ;
    
    /** ��������ƫ��
    */
    uint64_t m_progressOffset ;
    
    /** �������ݴ�С
    */
    uint64_t m_inSize ;
    
    /** ������ݴ�С
    */
    uint64_t m_outSize ;
    
    /** �Ƿ��Զ����ͽ���
    */
    bool m_sendRatio ;
    
    /** �Ƿ��Զ����Ͷ��߳̽���
    */
    bool m_sendMtRatio ;
    
    /** �Ƿ������ý���ʱ�Զ��ص�����ɽӿ�
    */
    bool m_sendProgress ;
    
    /** ��ǰ�����������
    */
    uint32_t m_curIndex ;
};

END_NAMESPACE_RCZIP

#endif //__RCMtLocalProgress_h_
