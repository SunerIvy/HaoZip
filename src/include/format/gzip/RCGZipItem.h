/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCGZipItem_h_
#define __RCGZipItem_h_ 1

#include "base/RCString.h"
#include "common/RCBuffer.h"
#include "format/gzip/RCGZipHeader.h"
#include "interface/ICoder.h"
#include "interface/IStream.h"

BEGIN_NAMESPACE_RCZIP

class RCGZipItem
{
public:

    /** ����
    */
    byte_t m_method;

    /** ��־
    */
    byte_t m_flags;

    /** ʱ��
    */
    uint32_t m_time;

    /** ��ѹ��־
    */
    byte_t m_extraFlags;

    /** ϵͳƽ̨
    */
    byte_t m_hostOS;

    /** crc
    */
    uint32_t m_crc;

    /** ��С
    */
    uint32_t m_size32;

    /** ����
    */
    RCStringA m_name;

    /** ע��
    */
    RCStringA m_comment;

public:

    /** ͷ���Ƿ����crc
    @return �Ƿ���true�����򷵻�false
    */
    bool HeaderCrcIsPresent() const ;

    /** �Ƿ��ѹ
    @return �Ƿ���true�����򷵻�false
    */
    bool ExtraFieldIsPresent() const ;

    /** �Ƿ�������
    @return �з���true�����򷵻�false
    */
    bool NameIsPresent() const ;

    /** �Ƿ���ע��
    @return �з���true�����򷵻�false
    */
    bool CommentIsPresent() const ;

    /** ���
    */
    void Clear() ;

    /** ��ȡͷ��
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadHeader(IGZipResumeDecoder* stream) ;

    /** ��ȡβ��
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadFooter1(IGZipResumeDecoder* stream) ;

    /** ��ȡβ��
    @param [in] stream ������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult ReadFooter2(ISequentialInStream* stream) ;

    /** дͷ��
    @param [in] stream �����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteHeader(ISequentialOutStream* stream) ;

    /** дβ��
    @param [in] stream �����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult WriteFooter(ISequentialOutStream* stream) ;

private:

    /** ��ȡ���ֽ�
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @param [out] buf ��Ŷ�ȡ����Ļ�������ַ
    @param [in] size �������ĳ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ReadBytes(IGZipResumeDecoder* stream, byte_t* data, uint32_t size) ;

    /** �����ֽ�
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @param [in] size �����Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult SkipBytes(IGZipResumeDecoder* stream, uint32_t size) ;

    /** ��ȡ�ֽ�
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @param [in] value ���ض�ȡ���ֽ�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ReadUInt16(IGZipResumeDecoder* stream, uint16_t& value) ;

    /** ��ȡһ���ַ���
    @param [in] stream ѹ��/��ѹ���ݽӿ�
    @param [out] s ���ض�ȡ���ַ���
    @param [in] limit ����ȡ�Ĵ�С
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ReadString(IGZipResumeDecoder* stream, RCStringA& s, uint32_t limit) ;

    /** ����־
    @param [in] flag ��־
    @return ͨ����ⷵ��true�����򷵻�false
    */
    bool TestFlag(byte_t flag) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCGZipItem_h_
