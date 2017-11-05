/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArchiveUpdateFilter_h_
#define __RCArchiveUpdateFilter_h_ 1

#include "base/RCString.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ���ļ�������
*/
class RCArchiveUpdateFilter
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCArchiveUpdateFilter() {} ;
    
public:
    
    /** ѹ��Դ�ļ������˺���
    @param [in] index ��ǰ�ļ��ڰ��ڵ�����ֵ
    @param [in] filePath ��ǰ�ļ�������·��
    @param [in] newFilePath ���˺���ļ���
    @return �������RC_S_OK, ���Ѿ����й��ˣ� ����δ���й���
    */
    virtual HResult OnGetFilePath(uint32_t index, 
                                  const RCString& filePath,
                                  RCString& newFilePath) = 0 ;

    /** ��ȡ������
    @param [in] index ��ǰ�ļ��ڰ��ڵ�����ֵ
    @param [in] newFilePath ���˺���ļ���
    @return �������RC_S_OK, ���Ѿ����й��ˣ� ����δ���й���
    */
    virtual HResult OnGetStream(uint32_t index, RCString& newFilePath) = 0;
    
    /** �ж��������Ƿ��Ѿ���ת��
    @param [in] index �ļ����
    @return �Ѿ�ת������true,���򷵻�false
    */
    virtual bool IsFileConverted(uint32_t index) = 0 ;
    
    /** �ж��Ƿ���Ҫת��
    @param [in] index �ļ����
    @return ��Ҫת������true,���򷵻�false
    */
    virtual bool NeedConvert(uint32_t index) = 0 ;
    
protected:    
    
    /** Ĭ����������
    */
    ~RCArchiveUpdateFilter() {} ;
};

/** ����ָ�붨��
*/
typedef RCSharedPtr<RCArchiveUpdateFilter> RCArchiveUpdateFilterPtr ;

END_NAMESPACE_RCZIP

#endif //__RCArchiveUpdateFilter_h_
