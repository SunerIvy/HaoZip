/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCPPMDSubAlloc_h_
#define __RCPPMDSubAlloc_h_ 1

#include "base/RCNonCopyable.h"

BEGIN_NAMESPACE_RCZIP

/** PPMD �ӷ�����
*/
class RCPPMDSubAlloc:
    private RCNonCopyable
{
public:

    /** Mem block
    */
    struct RCPPMDMemBlock
    {
        /** ���
        */
        uint16_t m_stamp ;

        /** NU
        */
        uint16_t m_NU ;

        /** ��һ��
        */
        uint32_t m_next ;

        /** ǰһ��
        */
        uint32_t m_prev ;

        /** Ĭ�Ϲ��캯��
        */
        RCPPMDMemBlock() ;

        /** �����б�
        @param [in] Base ����
        @param [in] p ����λ��
        */
        void InsertAt(byte_t* Base, uint32_t p) ;

        /** �Ƴ�
        @param [in] Base �Ƴ�����
        */
        void Remove(byte_t* Base) ;
    };   

public:

    /** Ĭ�Ϲ��캯��
    */
    RCPPMDSubAlloc() ;
    
    /** Ĭ����������
    */
    ~RCPPMDSubAlloc() ;
    
public:
    
    /** ����ָ��
    @param [in] offset ƫ��
    @return ����ָ��
    */
    void* GetPtr(uint32_t offset) const ;

    /** ����ǰһ��
    @param [in] offset ƫ��
    @return ���ض���ǰһ��
    */
    void* GetPtrNoCheck(uint32_t offset) const ;

    /** ����ƫ��
    @param [in] ptr ָ��
    @return ����ƫ��
    */
    uint32_t GetOffset(void* ptr) const ;

    /** ����ƫ��(�޼��)
    @param [in] ptr ָ��
    @return ����ƫ��
    */
    uint32_t GetOffsetNoCheck(void* ptr) const ;
 
    /** ����Blk
    @param [in] offset ƫ��
    @return ����Blk
    */
    RCPPMDMemBlock* GetBlk(uint32_t offset) const ;

    /** ���ؽڵ�
    @param [in] offset ƫ��
    @return ����ָ��
    */
    uint32_t* GetNode(uint32_t offset) const ;

    /** ����ڵ�
    @param [in] p ����
    @param [in] index ����λ��
    */
    void InsertNode(void* p, int32_t index) ;

    /** �Ƴ��ڵ�
    @param [in] index ���
    @return ��������ָ��
    */
    void* RemoveNode(int32_t index) ;

    /** U2B
    @return 
    */
    uint32_t U2B(int32_t NU) const ;

    /** �ָ��
    @param [in] pv ����ָ��
    @param [in] oldIndex �ɱ��
    @param [in] newIndex �±��
    */
    void SplitBlock(void* pv, int32_t oldIndex, int32_t newIndex) ;

    /** ����ʹ�õ��ڴ���
    @return ����ʹ�õ��ڴ���
    */
    uint32_t GetUsedMemory() const ;

    /** ����������ڴ���
    @return ����������ڴ���
    */
    uint32_t GetSubAllocatorSize() const ;

    /** ֹͣ����
    */
    void StopSubAllocator() ;

    /** ��ʼ����
    @param [in] size �����С
    @return �ɹ�����true,���򷵻�false
    */
    bool StartSubAllocator(uint32_t size) ;

    /** ��ʼ��
    */
    void InitSubAllocator() ;

    /** �ϲ����п�
    */
    void GlueFreeBlocks() ;

    /** ���ɵ�Ԫ
    @param [in] index ���
    @return ���ط����ָ��
    */
    void* AllocUnitsRare(int32_t index) ;

    /** ���ɵ�Ԫ
    @return ���ط����ָ��
    */
    void* AllocUnits(int32_t NU) ;

    /** ����������
    @return ���ط���������
    */
    void* AllocContext() ;

    /** ��չ��Ԫ
    @param [in] oldPtr ��ָ��
    @param [in] oldNU
    @return ������չ��ָ��
    */
    void* ExpandUnits(void* oldPtr, int32_t oldNU) ;

    /** ������Ԫ
    @param [in] oldPtr ��ָ��
    @param [in] oldNU
    @param [in] newNU
    @return ����������ָ��
    */
    void* ShrinkUnits(void* oldPtr, int32_t oldNU, int32_t newNU) ;

    /** �ͷŵ�Ԫ
    @param [in] ptr �ͷ�ָ��
    @param [in] oldNU
    */
    void FreeUnits(void* ptr, int oldNU) ;
        
public:

    /** ����ָ��
    */
    byte_t* m_pText ;

    /** ��ʼָ��
    */
    byte_t* m_unitsStart ;
        
private:

    static const uint32_t N1 = 4 ;
    static const uint32_t N2 = 4 ;
    static const uint32_t N3 = 4 ;
    static const uint32_t N4 = (128+3-1*N1-2*N2-3*N3)/4 ;
    static const uint32_t UNIT_SIZE = 12 ;
    static const uint32_t N_INDEXES = N1 + N2 + N3 + N4 ;

public:

    /** Extra 1 * UNIT_SIZE for NULL support
        Extra 2 * UNIT_SIZE for s0 in GlueFreeBlocks()
    */
    static const uint32_t s_kExtraSize = (UNIT_SIZE * 3) ;

    /**
    */
    static const uint32_t s_kMaxMemBlockSize = 0xFFFFFFFF - s_kExtraSize ;
   
private:

    /** �����С
    */
    uint32_t m_subAllocatorSize ;

    /** ��Ŷ���
    */
    byte_t m_indx2Units[N_INDEXES] ;

    /** ��Ŷ���
    */
    byte_t m_units2Indx[128] ;

    /** glue����
    */
    byte_t m_glueCount ;

    /** ���ж���
    */
    uint32_t m_freeList[N_INDEXES] ;

    /** ������ַ
    */
    byte_t* m_base ;

    /** �ѿ�ʼλ��
    */
    byte_t* m_heapStart ;

    /** ��λ
    */
    byte_t* m_loUnit ;

    /** ��λ
    */
    byte_t* m_hiUnit ;
};

END_NAMESPACE_RCZIP

#endif //__RCPPMDSubAlloc_h_
