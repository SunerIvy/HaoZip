/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimItem_h_
#define __RCWimItem_h_ 1

#include "format/wim/RCWimResource.h"
#include "filesystem/RCFileDefs.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

const uint32_t s_kWimHashSize = 20;
const uint32_t s_kWimStreamInfoSize = 24 + 2 + 4 + s_kWimHashSize ;

/** Wim Stream Info
*/
struct RCWimStreamInfo
{
    /** Resource
    */
    RCWimResource m_resource;

    /** Part Number
    */
    uint16_t m_partNumber;

    /** Ref Count
    */
    uint32_t m_refCount;

    /** Hash
    */
    byte_t m_hash[s_kWimHashSize];
};

class RCWimItem
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimItem() ;
    
    /** Ĭ����������
    */
    ~RCWimItem() ;
    
public:

    /** �Ƿ�ΪĿ¼
    @return Ŀ¼����true,���򷵻�false
    */
    bool isDir() const ;

    /** �Ƿ�����
    @return ������������true,���򷵻�false
    */
    bool HasStream() const ;
    
public:

    /** ����
    */
    RCString m_name;

    /** ����
    */
    uint32_t m_attrib;

    /** Hash
    */
    byte_t m_hash[s_kWimHashSize];

    /** ����ʱ��
    */
    RC_FILE_TIME m_cTime;

    /** ����ʱ��
    */
    RC_FILE_TIME m_aTime;

    /** �޸�ʱ��
    */
    RC_FILE_TIME m_mTime;

    /** ���
    */
    int32_t m_streamIndex;

    /** Meta Data
    */
    bool m_hasMetadata ;
};

END_NAMESPACE_RCZIP

#endif //__RCWimItem_h_
