/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFindFile_h_
#define __RCFindFile_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCFileInfo ;
class RCFindFile:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCFindFile() ;
    
    /** Ĭ����������
    */
    ~RCFindFile() ;

public:
    
    /** ����Ƿ��Ѿ�����
    @return ����Ѿ����䷵��true, ���򷵻�false
    */
    bool IsHandleAllocated() const ;
    
    /** �����ļ�
    @param [in] wildcard ��ͨ�����·��
    @param [out] fileInfo ȡ�����ļ���Ϣ
    @return �ɹ�����true, ���򷵻�false
    */
    bool FindFirst(const RCString& wildcard, RCFileInfo& fileInfo) ;
    
    /** ������һ���ļ�
    @param [out] fileInfo ȡ�����ļ���Ϣ
    @return �ɹ�����true, ���򷵻�false
    */
    bool FindNext(RCFileInfo& fileInfo) ;
    
    /** �رղ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool Close(void) ;
    
    /** �����ļ�
    @param [in] wildcard ��ͨ�����·��
    @param [out] fileInfo ȡ�����ļ���Ϣ
    @return �ɹ�����true, ���򷵻�false
    */
    static bool FindFile(const RCString& wildcard, RCFileInfo& fileInfo);
    
private:
    
    /** ʵ����
    */
    class TImpl ;
    
    /** ʵ�ֶ���
    */
    TImpl* m_impl ;
};

END_NAMESPACE_RCZIP

#endif //__RCFindFile_h_
