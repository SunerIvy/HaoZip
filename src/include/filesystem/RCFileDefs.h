/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileDefs_h_
#define __RCFileDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** �ļ�ʱ��
*/
class RC_FILE_TIME
{
public:
    
    /** �ļ�ʱ���λֵ
    */
    uint32_t u32LowDateTime ;
    
    /** �ļ�ʱ���λֵ
    */
    uint32_t u32HighDateTime ;

public:
    
    /** Ĭ�Ϲ��캯��
    */
    RC_FILE_TIME():
        u32LowDateTime(0),
        u32HighDateTime(0)
    {
    }
};

/** �ж��ļ�ʱ���Ƿ�Ϊ��Чֵ
@param [in] fileTime �ļ�ʱ��ֵ
@return ��Ϊ��Чֵ����true, ���򷵻�false
*/
inline bool IsValidFileTime(const RC_FILE_TIME& fileTime)
{
    return (fileTime.u32HighDateTime != 0) || (fileTime.u32LowDateTime != 0) ;
}

/** �ļ�ʱ���װ
*/
class RCFileTimeValue
{
public: 
    
    /** �ļ�ʱ��
    */
    RC_FILE_TIME m_fileTime ;
    
    /** ��ǰ�Ƿ�����Чʱ��ֵ
    */
    bool m_hasFileTime ;

public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCFileTimeValue():
        m_hasFileTime(false)
    {
    }
    
    /** �����ļ�ʱ��
    @param [in] fileTime �ļ�ʱ��ֵ
    */
    void SetFileTime(RC_FILE_TIME fileTime)
    {
        m_fileTime = fileTime ;
        m_hasFileTime = true ;
    }
};

END_NAMESPACE_RCZIP

#endif //__RCFileDefs_h_
