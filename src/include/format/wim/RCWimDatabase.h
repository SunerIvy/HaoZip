/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimDatabase_h_
#define __RCWimDatabase_h_ 1

#include "format/wim/RCWimItem.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** Wim Database
*/
class RCWimDatabase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimDatabase() ;
    
    /** Ĭ����������
    */
    ~RCWimDatabase() ;
    
public:

    /** ȡ�ý�ѹ���С
    @return ���ؽ�ѹ���С
    */
    uint64_t GetUnpackSize() const ;

    /** ȡ��ѹ����С
    @return ����ѹ����С
    */
    uint64_t GetPackSize() const ;

    /** ���
    */
    void Clear() ;

public:
 
    /** �ļ���
    */
    RCVector<RCWimStreamInfo> m_streams;

    /** �ļ����б�
    */
    RCVector<RCWimItem> m_items;
};

END_NAMESPACE_RCZIP

#endif //__RCWimDatabase_h_
