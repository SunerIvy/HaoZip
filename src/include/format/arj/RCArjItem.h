/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCArjItem_h_
#define __RCArjItem_h_ 1

#include "base/RCTypes.h"
#include "base/RCString.h"
#include "RCArjHeader.h"

BEGIN_NAMESPACE_RCZIP

struct RCArjItem
{
    /** ����
    */
    RCStringA m_name;

    /** ע��
    */
    RCStringA m_comment;

    /** �޸�ʱ��
    */
    uint32_t m_mTime;

    /** ���Ĵ�С
    */
    uint32_t m_packSize;

    /** ��С
    */
    uint32_t m_size;

    /** crc
    */
    uint32_t m_fileCRC;

    /** �־�λ��
    */
    uint32_t m_splitPos;

    /** �汾
    */
    byte_t m_version;

    /** ��ѹ�汾
    */
    byte_t m_extractVersion;

    /** ϵͳƽ̨
    */
    byte_t m_hostOS;

    /** ��־
    */
    byte_t m_flags;

    /** ����
    */
    byte_t m_method;

    /** �ļ�����
    */
    byte_t m_fileType;

    /** �ļ�����ģʽ
    */
    uint16_t m_fileAccessMode;

    /** ����ƫ��
    */
    uint64_t m_dataPosition;

    /** �Ƿ��Ǽ���
    @return �Ƿ���true�����򷵻�false
    */
    bool IsEncrypted() const;

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const;

    /** �����Ƿ��Ƿ־�
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSplitAfter() const ;

    /** ǰ���Ƿ��Ƿ־�
    @return �Ƿ���true�����򷵻�false
    */
    bool IsSplitBefore() const ;

    /** ��ȡwindowsƽ̨�µ�����
    @return ��������
    */
    uint32_t GetWinAttributes() const;

    /** ����
    @param [in] p �ڴ�����
    @param [in] size �ڴ��С
    */
    HResult Parse(const byte_t* p, unsigned size);
};

END_NAMESPACE_RCZIP

#endif //__RCArjItem_h_