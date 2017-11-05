/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCItemNameUtils_h_
#define __RCItemNameUtils_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCItemNameUtils:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCItemNameUtils() ;
    
    /** Ĭ����������
    */
    ~RCItemNameUtils() ;
    
public:

    /** ת�ɺϷ��ļ�����·����'/'ת��'\'
    @param [in] name �����ļ����֣����غϷ��ļ���
    @return �Ϸ��ļ���
    */
    static RCString MakeLegalName(const RCString& name);

    /** ת��ƽ̨����ļ���
    @param [in] name �����ļ����֣�����ƽ̨����ļ���
    @return ƽ̨����ļ���
    */
    static RCString GetOSName(const RCString& name);

    /** ת��ƽ̨����ļ���
    @param [in] name �����ļ����֣�����ƽ̨����ļ���
    @return ƽ̨����ļ���
    */
    static RCString GetOSName2(const RCString& name);

    /** ĩβ�Ƿ��зָ��
    @param [in] name �ļ���
    @param [in] codePage ����
    @return �Ƿ���true�����򷵻�false
    */
    static bool HasTailSlash(const RCStringA& name, uint32_t codePage);

    /** windows�ļ���ת��ƽ̨����ļ���
    @param [in] name �����ļ����֣�����ƽ̨����ļ���
    @return ƽ̨����ļ���
    */
    static RCString WinNameToOSName(const RCString& name) ;
};

END_NAMESPACE_RCZIP

#endif //__RCItemNameUtils_h_
