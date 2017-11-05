/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUpdatePair_h_
#define __RCUpdatePair_h_ 1

#include "base/RCTypes.h"
#include "common/RCVector.h"
#include "interface/IArchive.h"
#include "filesystem/RCFileInfo.h"
#include "archive/update/RCUpdateAction.h"
#include "archive/common/RCDirItems.h"
#include "archive/common/RCArcItem.h"

BEGIN_NAMESPACE_RCZIP

/** ���ڰ����ļ����±Ƚ�
*/
class RCUpdatePair
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCUpdatePair() : 
        m_arcIndex(-1), 
        m_dirIndex(-1) 
    {}
    
public:

    /** �Ƚ��ַ���
    @param [in] s1 �ַ���1
    @param [in] s2 �ַ���2
    @return = 0, ����ƥ��
            < 0, s1 < s2
            > 0, s1 > s2
    */
    static bool CompareStrings(const RCString &s1, const RCString& s2);
    
    /** �Ƚ��ļ�ʱ��
    @param [in] ft1 �ļ�ʱ��1
    @param [in] ft2 �ļ�ʱ��2
    @return = 0, ���
            < 0, ft1 < ft2
            > 0, ft1 > ft2
    */
    static int32_t CompareFileTime(const RC_FILE_TIME* ft1, const RC_FILE_TIME* ft2);

    /** �Ƚ��ļ���
    @param [in] s1 �ļ���1
    @param [in] s2 �ļ���2
    @return = 0, �ļ������
            < 0, s1 < s2
            > 0, s1 > s2
    */
    static int32_t CompareFileNames(const RCString &s1, const RCString &s2);

    /** �������ͱȽ��ļ�ʱ��
    @param [in] fileTimeType �ļ�ʱ������
    @param [in] time1 �ļ�ʱ��1
    @param [in] time2 �ļ�ʱ��2
    @return = 0, ���
            < 0, time1 < time2
            > 0, time1 > time2
    */
    static int32_t MyCompareTime(RCArchiveFileTimeType fileTimeType, const RC_FILE_TIME& time1, const RC_FILE_TIME& time2);
    
    /** �ļ�������
    @param [in] strings �ļ����б�
    @param [in] indices ����б�
    */
    static void SortFileNames(RCVector<RCString> &strings, RCIntVector &indices);
    
    /** ����ļ����Ƿ��ظ�
    @param [in] strings �ļ����б�
    @param [in] indices ����б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult TestDuplicateString(const RCVector<RCString> &strings, const RCIntVector &indices);
    
    /** ������Ҫ���µ��ĵ��б�
    @param [in] dirItems �������б�
    @param [in] arcItems �������б�
    @param [in] fileTimeType �ĵ�ʱ������
    @param [out] updatePairs �������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    static HResult GetUpdatePairInfoList(const RCDirItems &dirItems, 
                                         const RCVector<RCArcItem> &arcItems, 
                                         RCArchiveFileTimeType fileTimeType, 
                                         RCVector<RCUpdatePair> &updatePairs);

public:
    
    /** �ԱȽ��
    */
    RCUpdateDefs::enum_pairstate m_state;
        
    /** ��������
    */
    int32_t m_arcIndex;
    
    /** ��������
    */
    int32_t m_dirIndex;
};

END_NAMESPACE_RCZIP

#endif //__RCUpdatePair_h_
