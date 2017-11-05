/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimHeader_h_
#define __RCWimHeader_h_ 1

#include "format/wim/RCWimResource.h"

BEGIN_NAMESPACE_RCZIP

/** Wim ��������
*/
namespace NWimHeaderFlags
{
    const uint32_t s_compression     = 2;
    const uint32_t s_spanned         = 8;
    const uint32_t s_rpFix           = 0x80;
    const uint32_t s_xpress          = 0x20000;
    const uint32_t s_lzx             = 0x40000;
}

/** Wim ͷ�ṹ
*/
class RCWimHeader
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimHeader() ;
    
    /** Ĭ����������
    */
    ~RCWimHeader() ;

public:

    /** ����
    @param [in] p ����
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult Parse(const byte_t* p);

    /** �Ƿ�ѹ��
    @return ѹ������true,���򷵻�false
    */
    bool IsCompressed() const ;

    /** �Ƿ�֧��
    @return ֧�ַ���true,���򷵻�false
    */
    bool IsSupported() const ;

    /** �Ƿ�lzxģʽ
    @return lzx����true,���򷵻�false
    */
    bool IsLzxMode() const ;

    /** �Ƿ�Span
    @return Span����true,���򷵻�false
    */
    bool IsSpanned() const ;

    /** �Ƿ��°汾
    @return �°淵��true,���򷵻�false
    */
    bool IsNewVersion() const ;

    /** �Ƿ�From Archive
    @return From Archive����true,���򷵻�false
    */
    bool AreFromOnArchive(const RCWimHeader& h) ;
        
public:

    /** ���
    */
    uint32_t m_flags;

    /** �汾
    */
    uint32_t m_version;

    /** ���
    */
    uint16_t m_partNumber;

    /** �ֿ���
    */
    uint16_t m_numParts;

    /** Image ��
    */
    uint32_t m_numImages;

    /** Guid
    */
    byte_t m_guid[16];
    
    /** Offset Resource
    */
    RCWimResource m_offsetResource;

    /** Xml
    */
    RCWimResource m_xmlResource;

    /** Meta Data
    */
    RCWimResource m_metadataResource;
};

END_NAMESPACE_RCZIP

#endif //__RCWimHeader_h_
