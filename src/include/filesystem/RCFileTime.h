/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFileTime_h_
#define __RCFileTime_h_ 1

#include "filesystem/RCFileDefs.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCFileTime
{
public:

    /** ��Dos�ļ�ʱ��ת��Ϊ�����ļ�ʱ��
    @param [in] dosTime Unix�ļ�ʱ��
    @param [out] fileTime ���ر����ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool DosTimeToFileTime(uint32_t dosTime, RC_FILE_TIME& fileTime);
    
    /** �������ļ�ʱ��ת��ΪDos�ļ�ʱ��
    @param [in] fileTime �����ļ�ʱ��
    @param [out] dosTime Dos�ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool FileTimeToDosTime(const RC_FILE_TIME& fileTime, uint32_t& dosTime);
    
    /** ��Unix�ļ�ʱ��ת��Ϊ�����ļ�ʱ��
    @param [in] unixTime Unix�ļ�ʱ��
    @param [out] fileTime ���ر����ļ�ʱ��
    */
    static void UnixTimeToFileTime(uint32_t unixTime, RC_FILE_TIME& fileTime);
    
    /** �������ļ�ʱ��ת��ΪUnix�ļ�ʱ��
    @param [in] fileTime �����ļ�ʱ��
    @param [out] unixTime Unix�ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool FileTimeToUnixTime(const RC_FILE_TIME& fileTime, uint32_t& unixTime);
    
    /** ��ȡ��1601���������
    @param [in] year ��
    @param [in] month ��
    @param [in] day ��
    @param [in] hour ʱ
    @param [in] min ��
    @param [in] sec ��
    @param [out] resSeconds ����UTC�ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool GetSecondsSince1601(uint32_t year, 
                                    uint32_t month, 
                                    uint32_t day,
                                    uint32_t hour, 
                                    uint32_t min, 
                                    uint32_t sec, 
                                    uint64_t& resSeconds);
    
    /** ��ȡ����UTC�ļ�ʱ��
    @param [out] fileTime ����UTC�ļ�ʱ��
    */
    static void GetCurUtcFileTime(RC_FILE_TIME& fileTime);
    
    /** ��RC_FILE_TIMEת����64λ�޷������ͱ�ʾ
    @param [in] fileTime �ļ�ʱ��
    @return ����ת�����
    */
    static uint64_t ConvertFromFileTime(const RC_FILE_TIME& fileTime) ;
    
    /** ��64λ�޷������ͱ�ʾת����RC_FILE_TIME
    @param [in] time 64λ�޷������ͱ�ʾ���ļ�ʱ��
    @param [out] fileTime �����ļ�ʱ��
    */
    static void ConvertToFileTime(uint64_t time, RC_FILE_TIME& fileTime) ;
    
    /**  ����ʱ��ת����UTCʱ��
    @param [in] fileTime �����ļ�ʱ��
    @param [out] utcFileTime ����UTC �ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool LocalFileTimeToFileTime(const RC_FILE_TIME& fileTime, RC_FILE_TIME& utcFileTime) ;
    
    /**  UTCʱ��ת���ɱ���ʱ��
    @param [in] utcFileTime UTC �ļ�ʱ��
    @param [out] fileTime ���ر����ļ�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    static bool FileTimeToLocalFileTime(const RC_FILE_TIME& utcFileTime, RC_FILE_TIME& fileTime) ;
    
    /** �Ƚ��ļ�ʱ��
    @param [in] time1 ��һ���ļ�ʱ��
    @param [in] time2 �ڶ����ļ�ʱ��
    @return �����ȷ���0, ��� time1 > time2 ����1�����time1 < time2 ���� -1
    */
    static int32_t CompareFileTime(const RC_FILE_TIME* time1, const RC_FILE_TIME* time2) ;
};

END_NAMESPACE_RCZIP

#endif //__RCFileTime_h_
