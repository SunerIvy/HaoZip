/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTempFiles_h_
#define __RCTempFiles_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

/** ��ʱ�ļ�
*/
class RCTempFiles:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCTempFiles() ;
    
    /** Ĭ����������
    */
    ~RCTempFiles() ;
    
public:
    
    /** ��ȡ��ʱ�ļ��б�
    @return ������ʱ�ļ��б�
    */
    const RCVector<RCString>& GetPaths() const ;
    
    /** ��ȡ��ʱ�ļ��б�
    @return ������ʱ�ļ��б�����
    */
    RCVector<RCString>& GetPaths() ;
    
private:
    
    /** ɾ��������ʱ�ļ���,����б�
    */
    void Clear() ;
    
private:
    
    /** ��ʱ�ļ��б�
    */
    RCVector<RCString> m_paths ;
};

END_NAMESPACE_RCZIP

#endif //__RCTempFiles_h_
