/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRandomGenerator_h_
#define __RCRandomGenerator_h_ 1

#include "crypto/hash/RCSha1Defs.h"
#include "base/RCNonCopyable.h"
#include "base/RCSingleton.h"

BEGIN_NAMESPACE_RCZIP

class RCMutex ;

/** ���������
*/
class RCRandomGeneratorImpl:
    private RCNonCopyable
{
protected:

    /** Ĭ�Ϲ��캯��
    */
    RCRandomGeneratorImpl() ;
    
    /** Ĭ����������
    */
    ~RCRandomGeneratorImpl() ;

public:

    /** ���������
    @param [in] data ���ݻ���
    @param [in] size �����С
    */
    void Generate(byte_t *data, uint32_t size) ;
    
private:

    /** ��ʼ��
    */
    void Init();
    
private:

    /** ����
    */
    byte_t m_buff[RCSha1Defs::kDigestSize] ;

    /** �Ƿ��ʼ��
    */
    bool m_needInit ;

    /** ͬ��������
    */
    RCMutex* m_lock ;
};

typedef RCSingleton<RCRandomGeneratorImpl> RCRandomGenerator ;

END_NAMESPACE_RCZIP

#endif //__RCRandomGenerator_h_
