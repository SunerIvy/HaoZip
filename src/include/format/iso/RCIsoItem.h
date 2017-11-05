/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIsoItem_h_
#define __RCIsoItem_h_ 1

#include "base/RCTypes.h"
#include "filesystem/RCFileDefs.h"
#include "filesystem/RCFileTime.h"
#include "common/RCBuffer.h"
#include "format/iso/RCIsoHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RCIsoRecordingDateTime
{
    /** ��
    */
    byte_t m_year;

    /** ��
    */
    byte_t m_month;

    /** ��
    */
    byte_t m_day;

    /** Сʱ
    */
    byte_t m_hour;

    /** ����
    */
    byte_t m_minute;

    /** ��
    */
    byte_t m_second;

    /** gmtƫ��
    */
    signed char m_gmtOffset;

    /** ��ȡ�ļ�ʱ��
    @param [out] ft �����ļ�ʱ��
    @return ��ȡ�ɹ�����true�����򷵻�false
    */
    bool GetFileTime(RC_FILE_TIME& ft) const;
};

struct RCIsoDirRecord
{
    /** ��չ���Լ�¼����
    */
    byte_t m_extendedAttributeRecordLen;

    /** ��չλ��
    */
    uint32_t m_extentLocation;

    /** ���ݳ���
    */
    uint32_t m_dataLength;

    /** ����ʱ��
    */
    RCIsoRecordingDateTime m_dateTime;

    /** �ļ��Ǳ�־
    */
    byte_t m_fileFlags;

    /** �ļ�����
    */
    byte_t m_fileUnitSize;

    /** ����ȱ�ڵĴ�С
    */
    byte_t m_interleaveGapSize;

    /** �����к�
    */
    uint16_t m_volSequenceNumber;

    /** �ļ�id
    */
    RCByteBuffer m_fileId;

    /** ϵͳ�õĻ�����
    */
    RCByteBuffer m_systemUse;

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const;

    /** �Ƿ���ϵͳ��
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSystemItem() const;

    /** ��ȡsusp����
    @param [in] skipSize �����Ĵ�С
    @param [out] lenRes ���ֳ���
    @return �ɹ�����susp���֣����򷵻�0
    */
    const byte_t* FindSuspName(int32_t skipSize, int32_t& lenRes) const;

    /** ��ȡ��ǰ����
    @param [in] checkSusp �Ƿ�Ҫ����susp
    @param [in] skipSize �����Ĵ�С
    @return ���ص�ǰ����
    */
    int32_t GetLengthCur(bool checkSusp, int32_t skipSize) const;

    /** ��ȡ��ǰ����
    @param [in] checkSusp �Ƿ�Ҫ����susp
    @param [in] skipSize �����Ĵ�С
    @return ���ص�ǰ����
    */
    const byte_t* GetNameCur(bool checkSusp, int32_t skipSize) const;

    /** ����susp
    @param [in] p �ڴ�����
    @param [in] startPos ��ʼƫ��
    @return ͨ�����鷵��true�����򷵻�false
    */
    bool CheckSusp(const byte_t* p, int32_t& startPos) const;

    /** ����susp
    @param [in] startPos ��ʼƫ��
    @return ͨ�����鷵��true�����򷵻�false
    */
    bool CheckSusp(int32_t& startPos) const;
};

END_NAMESPACE_RCZIP

#endif //__RCIsoItem_h_
