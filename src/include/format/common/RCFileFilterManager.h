/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileFilterManager_h_
#define __RCFileFilterManager_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"
#include "base/RCSmartPtr.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RCFileNameParts
{
public:

    /** �ļ���
    */
    RCString m_name;

    /** ƥ�䲿��
    */
    RCVector<RCString> m_parts;
};

/** RCFileNameParts����ָ��
*/
typedef RCSharedPtr<RCFileNameParts> RCFileNamePartsPtr ;

class RCFileFilterManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCFileFilterManager(const RCString& fileList) ;

    /** Ĭ����������
    */
    ~RCFileFilterManager() ;

public:

    /** �ļ��Ƿ����
    @param [in] absolutePath ����·��
    @param [in] relativePath ���·��
    @return �Ƿ���ture�����򷵻�false
    */
    bool IsFilter(const RCString& absolutePath, const RCString& relativePath) ;

private:

    /** ���������ļ��б�
    @return �����ɹ�����true�����򷵻�false
    */
    bool ParseList(const RCString& fileList) ;

    /** �Ƚ��ַ��������Դ���ͨ���
    @param [in] sPattern ͨ���
    @param [in] sFileName �ļ���
    @param [in] bNoCase �Ƿ����ִ�Сд
    @return ��ȷ���true�����򷵻�false
    */
    bool CompareStrings(const char_t* sPattern, 
                        const char_t* sFileName, 
                        bool bNoCase);

private:

    /** �ļ���
    */
    RCVector<RCFileNamePartsPtr> m_fileNames;
};

END_NAMESPACE_RCZIP

#endif //__RCFileFilterManager_h_
