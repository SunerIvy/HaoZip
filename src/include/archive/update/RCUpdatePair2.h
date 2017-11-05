/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdatePair2_h_
#define __RCUpdatePair2_h_ 1

#include "base/RCTypes.h"
#include "common/RCVector.h"
#include "archive/update/RCUpdatePair.h"

BEGIN_NAMESPACE_RCZIP

/** ���ڰ�����±Ƚ�
*/
class RCUpdatePair2
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCUpdatePair2(): 
        m_isAnti(false), 
        m_dirIndex(-1), 
        m_arcIndex(-1), 
        m_newNameIndex(-1) 
    {}

public:
    
    /** �����ϴ���
    @return ����������Ϸ���true,���򷵻�false
    */
    bool ExistOnDisk() const 
    { 
        return m_dirIndex != -1; 
    }

    /** ���ڴ���
    @return ���ڴ��ڷ���true,���򷵻�false
    */
    bool ExistInArchive() const 
    { 
        return m_arcIndex != -1; 
    }
    
    /** ���´���
    @param [in] updatePairs �������б�
    @param [in] actionSet ���²���
    @param [out] operationChain ���½��
    @return �ɹ�����true,���򷵻�false
    */
    static bool UpdateProduce(const RCVector<RCUpdatePair> &updatePairs,
                              const RCActionSet &actionSet,
                              RCVector<RCUpdatePair2> &operationChain);

public:
    
    /** �����Ƿ�Ϊ������
    @return �����ݷ���true,���򷵻�false
    */
    bool GetNewData(void) const;
    
    /** �����Ƿ�Ϊ������
    @param [in] newData ������
    */
    void SetNewData(bool newData);

    /** �����Ƿ�Ϊ������
    @return �����Է���true,���򷵻�false
    */
    bool GetNewProps(void) const;
    
    /** ����������
    @param [in] newProps ������
    */
    void SetNewProps(bool newProps);

    /** �����Ƿ�Anti
    @return Anti����true,���򷵻�false
    */
    bool GetIsAnti(void) const;
    
    /** �����Ƿ�ΪAnti
    @param [in] isAnti �Ƿ�Anti
    */
    void SetIsAnti(bool isAnti);

    /** ȡ������
    @return ��������
    */
    int32_t GetDirIndex(void) const;
    
    /** ��������
    @param [in] dirIndex ����
    */
    void SetDirIndex(int32_t dirIndex);

    /** ȡ�ð��ڱ��
    @return ���ذ��ڱ��
    */
    int32_t GetArcIndex(void) const;
    
    /** ���ð��ڱ��
    @param [in] arcIndex ���ڱ��
    */
    void SetArcIndex(int32_t arcIndex);

    /** �������Ʊ��
    @return �������Ʊ��
    */
    int32_t GetNewNameIndex(void) const;
    
    /** �������Ʊ��
    @param [in] newNameIndex ���Ʊ��
    */
    void SetNewNameIndex(int32_t newNameIndex);

private:
    
    /** ������
    */
    bool m_newData;
    
    /** ������
    */
    bool m_newProps;
    
    /** �Ƿ�Anti
    */
    bool m_isAnti;
    
    /** ����
    */
    int32_t m_dirIndex;
    
    /** ���ڱ��
    */
    int32_t m_arcIndex;
    
    /** ���Ʊ��
    */
    int32_t m_newNameIndex;
};

END_NAMESPACE_RCZIP

#endif  //__RCUpdatePair2_h_
