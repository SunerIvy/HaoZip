/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCompressMethodMode_h_
#define __RCCompressMethodMode_h_ 1

#include "base/RCTypes.h"
#include "common/RCVector.h"
#include "archive/common/RCArchiveProperty.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ��ģʽ
*/
class RCCompressMethodMode
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCompressMethodMode() :
        m_formatIndex(-1) 
    {}
    
public:
    
    /** �����ĵ���ʽ���
    @param [in] formatIndex ��ʽ���
    */
    void SetFormatIndex(int32_t formatIndex);
    
    /** ȡ���ĵ���ʽ���
    @return �����ĵ���ʽ���
    */
    const int32_t GetFormatIndex(void) const;

    /** ȡ�������б�
    @return �����ĵ������б�����
    */
    RCVector<RCArchiveProperty>& GetProperties(void);
    
    /** ȡ�������б�
    @return �����ĵ������б�
    */
    const RCVector<RCArchiveProperty>& GetProperties(void) const;

private:
    
    /** �ĵ���ʽ���
    */
    int32_t m_formatIndex;
    
    /** �����б�
    */
    RCVector<RCArchiveProperty> m_properties;
};

END_NAMESPACE_RCZIP

#endif //__RCCompressMethodMode_h_
