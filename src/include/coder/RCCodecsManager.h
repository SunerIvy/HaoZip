/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCodecsManager_h_
#define __RCCodecsManager_h_ 1

#include "interface/ICoder.h"
#include "interface/IUnknownImpl.h"
#include <vector>

BEGIN_NAMESPACE_RCZIP

/** ���������� 
*/
class RCCodecsManager:
    public IUnknownImpl<ICompressCodecsInfo>
{
public:
    
    /** �������������
    */
    typedef std::vector<ICodecInfoPtr> container_type ;

public:

    /** Ĭ�Ϲ��캯��
    */
    RCCodecsManager() ;
    
    /** Ĭ����������
    */
    virtual ~RCCodecsManager() ;
   
public:
    
    /** ��ȡѹ���������������
    @param [out] numMethods ���ر������������
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    virtual HResult GetNumberOfMethods(uint32_t& numMethods) const ;

    /** ��ȡ���������Ϣ
    @param [in] index ����������±꣬��0��ʼ
    @param [out] spCodecInfo �����������Ϣ
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult GetMethod(uint32_t index, ICodecInfoPtr& spCodecInfo) const ;

    /** ����������
    @param [in] index �������±꣬��0��ʼ
    @param [in] iid �������Ľӿ�ID
    @param [out] coder �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CreateDecoder(uint32_t index, RC_IID iid, void** coder) const ;

    /** ����������
    @param [in] index �������±꣬��0��ʼ
    @param [in] iid �������Ľӿ�ID
    @param [out] coder �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    virtual HResult CreateEncoder(uint32_t index, RC_IID iid, void** coder) const ;

public:
    
    /** ȡ����������
    @return ���ر��������������
    */
    const container_type& GetCodecArray(void) const ;
    
protected:
    
    /** ע�������
    @param [in] spCodecInfo ��Ҫע��ı������Ϣ
    */    
    bool RegisterCodec(const ICodecInfoPtr& spCodecInfo) ;
    
    /** ����������/������
    @param [in] index �������±꣬��0��ʼ
    @param [in] iid �������Ľӿ�ID
    @param [in] isEncoder �����true,���������������򴴽�������
    @param [out] coder �������Ľӿ�ָ�룬���ü�����1
    @return �ɹ�����RC_S_OK�����򷵻ش���� 
    */
    HResult DoCreateCoder(uint32_t index, RC_IID iid, bool isEncoder, void** coder) const ;
    
private:
    
    /** �����������
    */
    container_type m_codecArray ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<RCCodecsManager> RCCodecsManagerPtr ;

END_NAMESPACE_RCZIP

#endif //__RCCodecsManager_h_
