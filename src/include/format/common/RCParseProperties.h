/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCParseProperties_h_
#define __RCParseProperties_h_ 1

#include "base/RCString.h"
#include "common/RCVariant.h"

BEGIN_NAMESPACE_RCZIP

class RCParseProperties
{
public:

    /** ת��string��uint32
    @param [in] srcString �ַ���
    @param [out] number ������ֵ
    @return ���ؽ���string�еļ����ֽ�
    */
    static int32_t ParseStringToUInt32(const RCString& srcString, uint32_t& number) ;

    /** ��������ֵ
    @param [in] name ������
    @param [in] prop ����
    @param [out] resValue ��������ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ParsePropValue(const RCString& name, const RCVariant& prop, uint32_t& resValue);

    /** ���������ֵ��С
    @param [in] srcStringSpec ������
    @param [out] dicSize �����ֵ��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ParsePropDictionaryValue(const RCString& srcStringSpec, uint32_t& dicSize) ;

    /** ���������ֵ��С
    @param [in] name ������
    @param [in] prop ����
    @param [out] resValue �����ֵ��С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ParsePropDictionaryValue(const RCString& name, const RCVariant& prop, uint32_t& resValue);

    /** ת��string��bool
    @param [in] s �ַ���
    @param [out] res bool��ֵ
    @return �ɹ�ת������true�����򷵻�false
    */
    static bool StringToBool(const RCString& s, bool& res) ;

    /** ����bool����
    @param [out] dest ����bool����
    @param [in] value ֵ
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult SetBoolProperty(bool& dest, const RCVariant& value) ;

    /** �������߳�����
    @param [in] name ������
    @param [in] prop ����
    @param [in] defaultNumThreads Ĭ���߳���
    @param [out] numThreads �߳���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ParseMtProp(const RCString& name, const RCVariant& prop, uint32_t defaultNumThreads, uint32_t& numThreads) ;
};

END_NAMESPACE_RCZIP

#endif //__RCParseProperties_h_
