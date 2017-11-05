/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabCheckSum2_h_
#define __RCCabCheckSum2_h_ 1

#include "base/RCTypes.h"

BEGIN_NAMESPACE_RCZIP

class RCCabCheckSum2
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCabCheckSum2();

public:

    /** ��ʼ��
    */
    void Init() ;

    /** ����
    @param [in] data �ڴ�����
    @param [in] size �ڴ��С
    */
    void Update(const void *data, uint32_t size);

    /** ������ݸ���
    */
    void FinishDataUpdate();

    /** ����UInt32
    @param [in] v ��ֵ
    */
    void UpdateUInt32(uint32_t v) ;

    /** ��ȡ���
    @return ���ؽ��
    */
    uint32_t GetResult() const ;

private:

    /** ��ֵ
    */
    uint32_t m_value;

    /** λ��
    */
    int32_t m_pos;

    /** ��ʷ����
    */
    byte_t m_hist[4];
};

END_NAMESPACE_RCZIP

#endif //__RCCabCheckSum2_h_