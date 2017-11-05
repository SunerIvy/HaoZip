/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzmaHeader_h_
#define __RCLzmaHeader_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCLzmaHeader
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzmaHeader() ;

public:

    /** ��ȡ�ֵ��С
    @return �����ֵ��С
    */
    uint32_t GetDicSize() const ;

    /** �Ƿ��д�С
    @return �Ƿ���true�����򷵻�false
    */
    bool HasSize() const ;

    /** ����
    @param [in] buf �ڴ�����
    @param [in] isThereFilter �Ƿ��ǹ���
    @return �����ɹ�����true�����򷵻�false
    */
    bool Parse(const byte_t* buf, bool isThereFilter);

    /** ����ֵ��С
    @param [in] p �ڴ�����
    @return ͨ����鷵��true�����򷵻�false
    */
    static bool CheckDicSize(const byte_t* p) ;

public:

    /** ��С
    */
    uint64_t m_size;

    /** ����id
    */
    byte_t m_filterID;

    /** lzma����
    */
    byte_t m_lzmaProps[5];
};

END_NAMESPACE_RCZIP

#endif //__RCLzmaHeader_h_
