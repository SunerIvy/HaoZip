/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLocalProgress_h_
#define __RCLocalProgress_h_ 1

#include "interface/ICoder.h"
#include "interface/IProgress.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCLocalProgress:
    public IUnknownImpl<ICompressProgressInfo>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLocalProgress() ;
    
    /** Ĭ����������
    */
    ~RCLocalProgress() ;
    
    /** ��ʼ��
    @param [in] progress ���Ƚӿ�
    @param [in] inSizeIsMain �Ƿ��������С�������
    */
    void Init(IProgress* progress, bool inSizeIsMain) ;
    
    /** ���µ�ǰ����������������»ص�����
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    HResult SetCur() ;
    
    /** ���õ�ǰ������±�ֵ
    @param [in] index ��ǰ�±�ֵ
    */
    void SetIndex(uint32_t index) ;
    
    /** ��ȡ����ƫ��
    @return ���ؽ���ƫ��ֵ
    */
    uint64_t GetProgressOffset() const ;
    
    /** ��ȡ�����С
    @return ���������С
    */
    uint64_t GetInSize() const ;
    
    /** ��ȡ�����С
    @return ���������С
    */
    uint64_t GetOutSize() const ;
    
    /** �Ƿ��Զ��������Ȼص�
    @return ����Զ��������Ȼص�����true, ���򷵻�false
    */
    bool IsSendRatio() const ;
    
    /** �Ƿ��Զ���������ɻص�
    @return ����Զ���������ɻص�����true, ���򷵻�false
    */
    bool IsSendProgress() const ;
    
    /** ���õ�ǰ����ƫ��
    @param [in] value ��ǰ����ƫ��ֵ
    */
    void SetProgressOffset(uint64_t value) ;
    
    /** ���������С
    @param [in] value �����Сֵ
    */
    void SetInSize(uint64_t value) ;
    
    /** ���������С
    @param [in] value �����Сֵ
    */
    void SetOutSize(uint64_t value) ;
    
    /** �Ƿ��Զ��������Ȼص�
    @param [in] value �Ƿ��Զ��������Ȼص�����ֵ
    */
    void SetSendRatio(bool value) ;
    
    /** �Ƿ��Զ���������ɻص�
    @param [in] value �Ƿ��Զ���������ɻص�����ֵ
    */
    void SetSendProgress(bool value) ;
    
    /** ����ѹ������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult SetRatioInfo(uint64_t inSize, uint64_t outSize) ;
    
private:
    
    /** ѹ�����������Ϣ
    */
    IProgressPtr m_spProgress;
    
    /** ѹ����ѹ����������Ϣ
    */
    ICompressProgressInfoPtr m_spRatioProgress ;
    
    /** ���߳�ѹ����ѹ����������Ϣ
    */
    IMtCompressProgressInfoPtr m_spMtRatioProgress ;
    
    /** �Ƿ�ʹ��inSize��Ϊ���Ȼص�
    */
    bool m_inSizeIsMain ;
    
    /** ����ƫ��
    */
    uint64_t m_progressOffset ;
    
    /** �����С
    */
    uint64_t m_inSize ;
    
    /** �����С
    */
    uint64_t m_outSize ;
    
    /** �Ƿ�����ɱ�����Ϣ
    */
    bool m_sendRatio ;
    
    /** �Ƿ������������Ϣ
    */
    bool m_sendProgress ;
    
    /** ��ǰ�����������
    */
    uint32_t m_curIndex ;
};

END_NAMESPACE_RCZIP

#endif //__RCLocalProgress_h_
