/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/
#ifndef __RCUpdateAction_h
#define __RCUpdateAction_h 1

#include "base/RCSingleton.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ�����³���ö�ٶ���
*/
class RCUpdateDefs
{
public:
    
    enum 
    {
        KNUMVALUES = 7,
    };

    /** �ȽϽ��
    */
    enum enum_pairstate
    {
        KNOTMASKED = 0,
        KONLYINARCHIVE,
        KONLYONDISK,
        KNEWINARCHIVE,
        KOLDINARCHIVE,
        KSAMEFILES,
        KUNKNOWNEWERFILES
    };

    /** ���²���
    */
    enum enum_pairaction
    {
        KIGNORE = 0,
        KCOPY,
        KCOMPRESS,
        KCOMPRESSASANTI
    };
};

typedef RCUpdateDefs::enum_pairstate    RCUpdatePairState;
typedef RCUpdateDefs::enum_pairaction   RCUpdatePairAction;

/** ���²�������
*/
class RCActionSet
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCActionSet(): 
        m_StateActions(RCUpdateDefs::KNUMVALUES) 
    {}
    
public:
    
    /** =����������
    */
    RCActionSet& operator=(const RCActionSet& val);
    
public:
    
    /** �Ƿ���ɨ�����
    @return �Ƿ���true,���򷵻�false
    */
    bool NeedScanning() const;
    
    /** ���ظ��²����б�
    @return ���ظ��²����б�
    */
    RCVector<RCUpdatePairAction> & GetStateActions(void);
    
    /** ���ظ��²����б�
    @return ���ظ��²����б�
    */
    const RCVector<RCUpdatePairAction>& GetStateActions(void) const;
    
private:
    
    /** ���²����б�
    */
    RCVector<RCUpdatePairAction> m_StateActions;
};

/** ȫ�ָ��²�������
*/
struct RCGlobalActionSet
{
    /** �½�����
    */
    RCActionSet m_AddActionSet;
    
    /** ���²���
    */
    RCActionSet m_UpdateActionSet;
    
    /** ˢ�²���
    */
    RCActionSet m_FreshActionSet;
    
    /** ͬ������
    */
    RCActionSet m_SynchronizeActionSet;
    
    /** ɾ������
    */
    RCActionSet m_DeleteActionSet;
    
    /** Ĭ�Ϲ��캯��
    */
    RCGlobalActionSet();
};

/** ���嵥����Ϊȫ�ַ��ʵ�
*/
typedef RCSingleton<RCGlobalActionSet> Singleton_GlobalActionSet;

END_NAMESPACE_RCZIP

#endif //__RCUpdateAction_h
