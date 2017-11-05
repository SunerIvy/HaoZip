/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCreateCoder_h_
#define __RCCreateCoder_h_ 1

#include "interface/ICodecInfo.h"
#include "interface/ICoder.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCCreateCoder
{
public:
    
    /** ����ID���ұ��뷽����Ϣ
    @param [in] codecInfo ��������ѯ�ӿ�
    @param [in] methodID ����ID
    @param [out] spCodecInfo ���ظ÷����ӿ�ָ��
    @param [out] codecIndex ���ظñ��������±�ֵ
    @return �ɹ�����true����������ڸ÷����򷵻�false
    */
    static bool FindMethodByID(ICompressCodecsInfo* codecInfo, 
                               RCMethodID methodID, 
                               ICodecInfoPtr& spCodecInfo,
                               uint32_t* codecIndex = NULL) ;
                               
    /** ����Name���ұ��뷽����Ϣ
    @param [in] codecInfo ��������ѯ�ӿ�
    @param [in] methodName �������ƣ������ִ�Сд
    @param [out] spCodecInfo ���ظ÷����ӿ�ָ��
    @param [out] codecIndex ���ظñ��������±�ֵ
    @return �ɹ�����true����������ڸ÷����򷵻�false
    */
    static bool FindMethodByName(ICompressCodecsInfo* codecInfo, 
                                 const RCString& methodName, 
                                 ICodecInfoPtr& spCodecInfo,
                                 uint32_t* codecIndex = NULL) ;

    /** ����Name���ұ���ID
    @param [in] codecInfo ��������ѯ�ӿ�
    @param [in] methodName �������ƣ������ִ�Сд
    @param [out] methodID ���ر������ƶ�Ӧ�ı���ID
    @param [out] codecIndex ���ظñ��������±�ֵ
    @return �ɹ�����true����������ڸ÷����򷵻�false
    */
    static bool FindMethodID(ICompressCodecsInfo* codecInfo, 
                             const RCString& methodName, 
                             RCMethodID& methodID,
                             uint32_t* codecIndex = NULL) ;

    /** ��������/������
    @param [in] codecInfo ��������ѯ�ӿ�
    @param [in] methodID ����ID
    @param [out] coder  ����ICompressCoder�ӿ�ָ��
    @param [in] isEncoder ���Ϊtrue�������������ӿ�ָ�룬���Ϊfalse���򴴽��������ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult CreateCoder(ICompressCodecsInfo* codecInfo,
                               RCMethodID methodID,
                               ICompressCoderPtr& coder,
                               bool isEncoder);
                    
    /** ��������/������
    @param [in] codecsInfo ��������ѯ�ӿ�
    @param [in] methodID ����ID
    @param [out] coder  ����ICompressCoder�ӿ�ָ��
    @param [out] coder2 ����ICompressCoder2�ӿ�ָ��
    @param [in] isEncoder ���Ϊtrue�������������ӿ�ָ�룬���Ϊfalse���򴴽��������ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult CreateCoder(ICompressCodecsInfo* codecsInfo, 
                               RCMethodID methodID,
                               ICompressCoderPtr& coder,
                               ICompressCoder2Ptr& coder2,
                               bool isEncoder);
    
    /** ��������/�������Ĺ�����
    @param [in] codecsInfo ��������ѯ�ӿ�
    @param [in] methodID ����ID
    @param [out] filter ����ICompressFilter�ӿ�ָ��
    @param [in] isEncoder ���Ϊtrue�������������ӿ�ָ�룬���Ϊfalse���򴴽��������ӿ�ָ��
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult CreateFilter(ICompressCodecsInfo* codecsInfo, 
                                RCMethodID methodID,
                                ICompressFilterPtr& filter,
                                bool isEncoder);
private:
    
    /** ��������/������
    @param [in] codecsInfo ��������ѯ�ӿ�
    @param [in] methodID ����ID
    @param [out] filter ����ICompressFilter�ӿ�ָ��
    @param [out] coder  ����ICompressCoder�ӿ�ָ��
    @param [out] coder2 ����ICompressCoder2�ӿ�ָ��
    @param [in] isEncoder ���Ϊtrue�������������ӿ�ָ�룬���Ϊfalse���򴴽��������ӿ�ָ��
    @param [in] isOnlyCoder ���Ϊtrue������RCFilterCoder��Ϊcoder�ӿ�ָ�룬
                            ���Ϊfalse,�����������Filter���򲻴���coder�ӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult CreateCoder(ICompressCodecsInfo* codecsInfo, 
                               RCMethodID methodID,
                               ICompressFilterPtr& filter,
                               ICompressCoderPtr& coder,
                               ICompressCoder2Ptr& coder2,
                               bool isEncoder,
                               bool isOnlyCoder) ;
};

END_NAMESPACE_RCZIP

#endif //__RCCreateCoder_h_
