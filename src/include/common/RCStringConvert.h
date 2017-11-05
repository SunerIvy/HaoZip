/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCStringConvert_h_
#define __RCStringConvert_h_ 1

#include "base/RCString.h"
#include "base/RCNonCopyable.h"
#include "common/RCDynamicBuffer.h"

BEGIN_NAMESPACE_RCZIP

typedef enum
{
    RC_ENCODING_LOCAL,
    RC_CN_GB2312,
    RC_CN_GBK,
    RC_CN_GB18030,
    RC_CN_BIG5,
    RC_UNICODE_UTF7,
    RC_UNICODE_UTF8,
    RC_UNICODE_UTF16,
    RC_UNICODE_UTF16_BE,
    RC_UNICODE_UTF16_LE,
    RC_UNICODE_UTF32,
    RC_UNICODE_UTF32_BE,
    RC_UNICODE_UTF32_LE,
    RC_UNICODE_UCS2,
    RC_UNICODE_UCS2_BE,
    RC_UNICODE_UCS2_LE,
    RC_UNICODE_UCS4,
    RC_UNICODE_UCS4_BE,
    RC_UNICODE_UCS4_LE,
    
    RC_ENCODING_UNKNOWN
}RCEncodingType ;

/** �ַ��������ҳ
*/
typedef enum
{
    RC_CP_ACP   = 0 ,
    RC_CP_OEMCP = 1 ,
    RC_CP_UTF8  = 65001
}RCCodePage ;

class RCStringConvert:
    private RCNonCopyable
{   
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCStringConvert() ;
    
    /** Ĭ����������
    */
    ~RCStringConvert() ;
    
    /** �򿪱���ת����
    @param [in] toCode Ŀ�����
    @param [in] fromCode Դ����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Open(RCEncodingType toCode, RCEncodingType fromCode) ;
    
    /** ת������
    @param [in] inBuf �������ݻ�����
    @param [in] inBufLen �������ݳ���
    @param [out] result ת�����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Convert(const char* inBuf, size_t inBufLen, RCDynamicCharBuffer& result) ;
   
   /** ת������
    @param [in] inBuf �������ݻ�����
    @param [in] inBufLen �������ݳ���
    @param [out] result ת�����, �Զ��ֽڷ�ʽ�洢
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Convert(const char* inBuf, size_t inBufLen, RCStringA& result) ;
   
   /** ת������
    @param [in] inBuf �������ݻ�����
    @param [in] inBufLen �������ݳ���
    @param [out] result ת�����, �Կ��ֽڷ�ʽ�洢
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Convert(const char* inBuf, size_t inBufLen, RCStringW& result) ;
    
    /** �ر�ת����
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Close(void) ;

    /** UTF8����ת��Unicode����
    @param [in] inBuf �������ݻ�����
    @param [in] inBufLen �������ݳ���
    @param [out] result ת�����
    @return �ɹ�����true,ʧ�ܷ���false
    */
    static bool ConvertUTF8ToUnicode(const char* inBuf, size_t inBufLen, RCStringW& result) ;
    
    /** Unicode����ת��UTF8����
    @param [in] inBuf �������ݻ�����
    @param [in] inBufLen �������ݳ���
    @param [out] result ת�����
    @return �ɹ�����true,ʧ�ܷ���false
    */
    static bool ConvertUnicodeToUTF8(const wchar_t* inBuf, size_t inBufLen, RCStringA& result) ;
    
    /** ���ֽ�ת���ɿ��ֽ�
    @param [in] src Դ�ַ�������
    @param [in] codePage �ַ�������Ĵ���ҳ
    @return ת����Ŀ��ֽڱ����ַ���
    */
    static RCStringW MultiByteToUnicodeString(const RCStringA& src, uint32_t codePage = RC_CP_ACP) ;
    
    /** ���ֽ�ת���ɿ��ֽ�
    @param [in] src Դ�ַ�������
    @param [in] len �ַ����ĳ��ȣ����Ϊ-1����Ϊsrc����0��β���ַ���
    @param [in] codePage �ַ�������Ĵ���ҳ
    @return ת����Ŀ��ֽڱ����ַ���
    */
    static RCStringW MultiByteToUnicodeString(const char* src, int32_t len = -1, uint32_t codePage = RC_CP_ACP) ;
    
    /** ���ֽ�ת���ɶ��ֽ�
    @param [in] src Դ�ַ�������
    @param [in] codePage �ַ�������Ĵ���ҳ
    @param [in] defaultChar ���޷�ת��ʱ���滻��Ĭ���ַ�
    @param [out] defaultCharWasUsed Ĭ���ַ��Ƿ�ʹ��
    @return ת����Ķ��ֽڱ����ַ���
    */
    static RCStringA UnicodeStringToMultiByte(const RCStringW& src,
                                              uint32_t codePage, 
                                              char defaultChar, 
                                              bool& defaultCharWasUsed) ;
    
    /** ���ֽ�ת���ɶ��ֽ�
    @param [in] src Դ�ַ�������
    @param [in] codePage �ַ�������Ĵ���ҳ
    @return ת����Ķ��ֽڱ����ַ���
    */                                 
    static RCStringA UnicodeStringToMultiByte(const RCStringW& src, uint32_t codePage = RC_CP_ACP);
    
    /** ��ȡ�����ַ���
    @param [in] type �ַ�������
    @return ���ر����ַ���
    */
    static RCStringA GetEncodingString(RCEncodingType type) ;
    
public:
    
    /** �ж��ֽ����Ƿ�ΪLITTLE ENDIAN
    */
    static bool IsLittleEndian(void) ;
    
    /** ����BOMֵ��ȡ��������
    @param [in] inBuf ��������ַ
    @param [in] inBufLen ���������ݳ���
    @param [out] type ���ر�������
    @param [out] bomLen ����ΪNULL������BOM��ǵĳ���
    @return ����ɹ�����true��ʧ�ܷ���false
    */
    static bool GetEncodingType(const char* inBuf, 
                                size_t inBufLen,
                                RCEncodingType& type,
                                uint32_t* bomLen) ;

private:
    
    /** �򿪱���ת����
    @param [in] toCode Ŀ����룬�μ�libiconv�ĵ�
    @param [in] fromCode Դ���룬�μ�libiconv�ĵ�
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool Open(const char* toCode, const char* fromCode) ;
    
private:
    
    /** ʵ������
    */
    struct TImpl ;
    TImpl* m_impl ;
};

END_NAMESPACE_RCZIP

#endif //__RCStringConvert_h_
