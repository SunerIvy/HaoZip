/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileEnumerator_h_
#define __RCFileEnumerator_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "filesystem/RCFindFile.h"

BEGIN_NAMESPACE_RCZIP

class RCFileInfo ;

/** ������ȡһ��Ŀ¼�е������ļ�����Ŀ¼��
    ����ݹ������Ŀ¼
*/
class RCFileEnumerator:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCFileEnumerator() ;
    
    /** ���캯��
    @param [in] wildcard ��ͨ�����Ŀ¼��
    */
    explicit RCFileEnumerator(const RCString& wildcard) ;
    
    /** Ĭ����������
    */
    ~RCFileEnumerator() ;
    
public:
    
    /** ��ȡһ���ļ�
    @param [out] fileInfo ����ȡ�����ļ���Ϣ
    @return �ɹ�����true, ���ʧ�ܻ����Ѿ�û�������ļ�ʱ������false
    */
    bool Next(RCFileInfo& fileInfo) ;
    
    /** ��ȡһ���ļ�
    @param [out] fileInfo ����ȡ�����ļ���Ϣ
    @param [out] found ���ȡ���ļ�����true�����򷵻�false
    @return �ɹ�����true, ���ʧ�ܷ���false
    */
    bool Next(RCFileInfo& fileInfo, bool& found);

private:
    
    /** ��ȡ��һ���ļ�
    @param [out] fileInfo ����ȡ�����ļ���Ϣ
    */
    bool NextAny(RCFileInfo& fileInfo);
    
private:
    
    /** ͨ���·����Ĭ��Ϊ*
    */
    RCString m_wildcard ;
    
    /** �ļ����ҷ���
    */
    RCFindFile m_findFile ;
};

END_NAMESPACE_RCZIP

#endif //__RCFileEnumerator_h_
