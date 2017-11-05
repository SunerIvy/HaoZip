/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMemLockBlocks_h_
#define __RCMemLockBlocks_h_ 1

#include "locked/RCMemBlocks.h"

BEGIN_NAMESPACE_RCZIP

class RCMemLockBlocks:
    public RCMemBlocks
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCMemLockBlocks() ;
    
    /** Ĭ����������
    */
    ~RCMemLockBlocks() ;
    
public:
    
    /** �ͷ��ڴ��ռ�
    @param [in] memManager �ڴ������
    */
    void Free(RCMemBlockManagerMt* memManager);  
    
    /** �л�������ģʽ
    @param [in] memManager �ڴ������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult SwitchToNoLockMode(RCMemBlockManagerMt* memManager);
    
    /** �ͷ��ڴ����
    @param [in] blocks �ڴ�������
    @param [in] memManager �ڴ������
    */
    void Detach(RCMemLockBlocks& blocks, RCMemBlockManagerMt* memManager);
    
    /** ����������
    @param [in] isLockMode �Ƿ�Ϊ����ģʽ
    */
    void SetLockMode(bool isLockMode) ;
    
    /** ��ȡ��������
    @return ����ģʽ����true, ���򷵻�false
    */
    bool GetLockMode() const;

private:
    
    /** �ͷ��ڴ��
    @param [in] index �ڴ���±�ֵ
    @param [in] memManager �ڴ������
    */
    void FreeBlock(uint32_t index, RCMemBlockManagerMt* memManager);
    
private:
    
    /** �Ƿ�Ϊ����ģʽ
    */
    bool m_lockMode ;
};

END_NAMESPACE_RCZIP

#endif //__RCMemLockBlocks_h_
