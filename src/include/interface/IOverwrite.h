/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IOverwrite_h
#define __IOverwrite_h 1

#include "interface/IUnknown.h"
#include "base/RCString.h"
#include "filesystem/RCFileDefs.h"
#include "archive/extract/RCExtractDefs.h"

BEGIN_NAMESPACE_RCZIP

/** �ӿ�ID����
*/
enum
{
    IID_IAskOverwrite = IID_IOVERWRITE_BASE
};

/** ��ȡ����ӿ�
*/
class IAskOverwrite:
    public IUnknown
{
public:
    
    /** �ӿ�ID
    */
    enum { IID = IID_IAskOverwrite } ;
    
public:
    
    /** �ļ�����ȷ�Ͻӿ�
    @param [in] existName �Ѿ����ڵ��ļ�·��
    @param [in] existTime �Ѿ����ڵ��ļ�ʱ��
    @param [in] existSize �Ѿ����ڵ��ļ���С
    @param [in] newName ���ļ���
    @param [in] newTime ���ļ�ʱ��
    @param [in] newSize ���ļ���С
    @param [in] isEnableRename �Ƿ�֧������������
    @param [out] answer ȷ�Ͻ��
    @param [out] newFileName ����������������ļ�ʱ�������û�ָ������
    @return �ɹ�����RC_S_OK, ���򷵻ش�����
    */
    virtual HResult AskOverwrite(const RCString& existName,
                                 const RC_FILE_TIME* existTime, 
                                 const uint64_t* existSize,
                                 const RCString& newName,
                                 const RC_FILE_TIME* newTime, 
                                 const uint64_t* newSize,
                                 bool isEnableRename,
                                 RCExractOverwriteAnswer& answer,
                                 RCString& newFileName) = 0 ;
    
protected:
    
    /** Ĭ����������
    */
    ~IAskOverwrite(){} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<IAskOverwrite> IAskOverwritePtr ;

END_NAMESPACE_RCZIP

#endif //__IPassword_h
