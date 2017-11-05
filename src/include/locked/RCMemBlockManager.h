/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMemBlockManager_h_
#define __RCMemBlockManager_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

class RCMemBlockManager:
    private RCNonCopyable
{
public:

    /** ���캯��
    @param [in] blockSize ���ݿ��С
    */
    explicit RCMemBlockManager(size_t blockSize = (1 << 20) ) ;
    
    /** Ĭ����������
    */
    ~RCMemBlockManager() ;

public:
    
    /** �����ڴ�ռ�
    @param [in] numBlocks ��������ݿ����
    @return �ɹ�����true, ʧ���򷵻�false
    */
    bool AllocateSpace(size_t numBlocks) ;
    
    /** �ͷ��ڴ�ռ�
    */
    void FreeSpace();
    
    /** ��ȡ��ǰ���ݿ��С
    */
    size_t GetBlockSize() const ;
    
    /** ����һ�����ݿ�
    @return �������ݿ��ַ, ʧ�ܷ���NULL
    */
    void* AllocateBlock() ;
    
    /** �ͷ����ݿ��ڴ�ռ�
    @param [in] p ���ݿ��ڴ��ַ
    */
    void FreeBlock(void* p) ;
    
private:
    
    /** ������ʼ��ַ
    */
    void* m_data;
    
    /** ���ݿ��С
    */
    size_t m_blockSize;
    
    /** ��һ�������ڴ��ַ
    */
    void* m_headFree;
};

END_NAMESPACE_RCZIP

#endif //__RCMemBlockManager_h_
