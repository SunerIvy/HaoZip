/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMemBlockManagerMt_h_
#define __RCMemBlockManagerMt_h_ 1

#include "locked/RCMemBlockManager.h"
#include "thread/RCMutex.h"
#include "thread/RCSynchronization.h"

BEGIN_NAMESPACE_RCZIP

class RCMemBlockManagerMt:
    private RCMemBlockManager
{
public:

    /** Ĭ�Ϲ��캯��
    @param [in] blockSize ���ݿ��С
    */
    explicit RCMemBlockManagerMt(size_t blockSize = (1 << 20)) ;
    
    /** Ĭ����������
    */
    ~RCMemBlockManagerMt() ;

public:
    
    /** �����ڴ�ռ�
    @param [in] numBlocks ��������ݿ����
    @param [in] numNoLockBlocks ��������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult AllocateSpace(size_t numBlocks, size_t numNoLockBlocks = 0) ;
    
    /** �����ڴ�ռ�
    @param [in] desiredNumberOfBlocks ��������ݿ����
    @param [in] numNoLockBlocks ��������
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult AllocateSpaceAlways(size_t desiredNumberOfBlocks, size_t numNoLockBlocks = 0);
    
    /** �ͷ��ڴ�ռ�
    */
    void FreeSpace();
    
    /** ����һ�����ݿ�
    @return �������ݿ��ַ, ʧ�ܷ���NULL
    */
    void* AllocateBlock() ;
    
    /** �ͷ����ݿ��ڴ�ռ�
    @param [in] p ���ݿ��ڴ��ַ
    @param [in] lockMode �Ƿ�Ϊ����ģʽ
    */
    void FreeBlock(void* p, bool lockMode = true);
    
    /** �ͷż������������
    @param [in] number �ͷŵļ���
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult ReleaseLockedBlocks(int32_t number) ;
    
    /** ��ȡ��ǰ���ݿ��С
    */
    size_t GetBlockSize() const ;
    
public:
    
    /** ͬ���ź���
    */
    RCSemaphore m_semaphore ;

private:
    
    /** ͬ����
    */
    RCMutex m_lock ;
};

END_NAMESPACE_RCZIP

#endif //__RCMemBlockManagerMt_h_
