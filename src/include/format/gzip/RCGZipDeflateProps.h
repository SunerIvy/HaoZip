/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCGZipDeflateProps_h_
#define __RCGZipDeflateProps_h_ 1

#include "interface/ICoder.h"
#include "common/RCProperty.h"

BEGIN_NAMESPACE_RCZIP

class RCGZipDeflateProps
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCGZipDeflateProps() ;
    
    /** �Ƿ�Ϊ���ѹ��ģʽ
    @return �Ƿ������ѹ��ģʽ
    */
    bool IsMaximum() const ;

    /** ����������Ӧ�õ�����ӿ�
    @param [in] setCoderProperties ��ҪӦ�����Եı���ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetCoderProperties(ICompressSetCoderProperties* setCoderProperties) ;
    
    /** ���ñ�������
    @param [in] propertyArray ������������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetProperties(const RCPropertyNamePairArray& propertyArray);

private:

    /** ��ʼ������
    */ 
    void Init() ;
    
    /** ��ʼ������ΪĬ��ֵ
    */
    void Normalize() ;
    
private:

    /** �ȼ�
    */
    uint32_t m_level ;

    /** passes
    */
    uint32_t m_numPasses ;

    /** fb
    */
    uint32_t m_fb ;

    /** algo
    */
    uint32_t m_algo ;

    /** mc
    */
    uint32_t m_mc ;

    /** �Ƿ�����mc
    */
    bool m_mcDefined ;
};

END_NAMESPACE_RCZIP

#endif //__RCGZipDeflateProps_h_
