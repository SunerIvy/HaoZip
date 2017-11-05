/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCExtractStatus_h_
#define __RCExtractStatus_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** ��ѹ״̬
*/
class RCExtractStatus
{
public:
    
    /** �ĵ�����
    */
    uint64_t m_numArchives ;
    
    /** ��ѹ������ݴ�С
    */
    uint64_t m_unpackSize ;
    
    /** ��ѹѹ�����ݴ�С
    */
    uint64_t m_packSize ;
    
    /** �Ѿ���ѹ���ļ��и���
    */
    uint64_t m_numFolders ;
    
    /** �Ѿ���ѹ���ļ�����
    */
    uint64_t m_numFiles ;

public:
    
    /** ��ճ�Ա����
    */
    void Clear()
    {
        m_numArchives = 0;
        m_unpackSize  = 0;
        m_packSize    = 0;
        m_numFolders  = 0;
        m_numFiles    = 0;
    }
};

END_NAMESPACE_RCZIP

#endif //__RCExtractStatus_h_
