/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCMemBlocks_h_
#define __RCMemBlocks_h_ 1

#include "base/RCNonCopyable.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCMemBlockManagerMt ;
class ISequentialOutStream ;

class RCMemBlocks
{
    /** �ڴ���б�
    */
    typedef RCVector<void*> block_type ;

public:

    /** Ĭ�Ϲ��캯��
    */
    RCMemBlocks() ;
    
    /** Ĭ����������
    */
    ~RCMemBlocks() ;
    
public:
    
    /** �ͷ��ڴ��ռ�
    @param [in] manager �ڴ������
    */
    void FreeOpt(RCMemBlockManagerMt* manager) ;
    
    /** ������д�������
    @param [in] blockSize �ڴ���С
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK, ʧ���򷵻ش�����
    */
    HResult WriteToStream(size_t blockSize, ISequentialOutStream* outStream) const ;
    
    /** �����ܴ�С
    @param [in] totalSize �����ܴ�С
    */
    void SetTotalSize(uint64_t totalSize) ;
    
    /** ��ȡ�ܴ�С
    @return ���������ܴ�С
    */
    uint64_t GetTotalSize(void) const ;
    
    /** ��ȡ���ݿ��С
    @return �������ݿ��С�ֽ���
    */
    size_t GetBlockSize() const ;
    
    /** ��ȡ���ݿ��б�
    */
    const block_type& GetBlock() const ;
    
    /** ����һ���ڴ��
    @param [in] item �ڴ����ʼ��ַ
    */
    void Add(void* item);
    
private:
    
    /** �ͷ��ڴ��ռ�
    @param [in] manager �ڴ������
    */
    void Free(RCMemBlockManagerMt* manager);
    
protected:

    /** ���ݿ��б�
    */
    block_type m_blocks ;
    
    /** �ܴ�С
    */
    uint64_t m_totalSize ;
};

END_NAMESPACE_RCZIP

#endif //__RCMemBlocks_h_
