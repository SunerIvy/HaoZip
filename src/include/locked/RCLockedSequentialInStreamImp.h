/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLockedSequentialInStreamImp_h_
#define __RCLockedSequentialInStreamImp_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCLockedInStream ;

class RCLockedSequentialInStreamImp:
    public IUnknownImpl<ISequentialInStream>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLockedSequentialInStreamImp() ;
    
    /** Ĭ����������
    */
    ~RCLockedSequentialInStreamImp() ;
    
public:
    
    /** ��ʼ��
    @param [in] lockedInStream �̰߳�ȫ���������ӿ�
    @param [in] startPos ������ʼƫ��
    */
    void Init(RCLockedInStream* lockedInStream, uint64_t startPos) ;
    
    /** ��ȡ���� 
    @param [out] data ������ݵĻ�����
    @param [in] size ��������С
    @param [out] processedSize ʵ�ʶ�ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    virtual HResult Read(void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** �̰߳�ȫ�������������ӿ�ָ��
    */
    RCLockedInStream* m_lockedInStream ;
    
    /** ��ǰ����λ��ƫ��
    */
    uint64_t m_pos ;
};

END_NAMESPACE_RCZIP

#endif //__RCLockedSequentialInStreamImp_h_
