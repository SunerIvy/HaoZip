/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimImageInfo_h_
#define __RCWimImageInfo_h_ 1

#include "filesystem/RCFileDefs.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCXmlItem ;

/** Wim Image Info
*/
class RCWimImageInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimImageInfo() ;
    
    /** Ĭ����������
    */
    ~RCWimImageInfo() ;
    
public:  

    /** ����
    @param [in] item xml��
    */
    void Parse(const RCXmlItem& item) ;
      
public:

    /** ����ʱ���Ƿ���
    */
    bool m_cTimeDefined;

    /** �޸�ʱ���Ƿ���
    */
    bool m_mTimeDefined;

    /** �����Ƿ���
    */
    bool m_nameDefined;
    
    /** ����ʱ��
    */
    RC_FILE_TIME m_cTime;

    /** �޸�ʱ��
    */
    RC_FILE_TIME m_mTime;

    /** ����
    */
    RCString m_name ;
    
private:

    /** ����ʱ��
    @param [in] item xml��
    @param [out] defined ʱ���Ƿ���
    @param [out] ft ʱ��
    @param [in] s
    */
    static void ParseTime(const RCXmlItem& item, bool& defined, RC_FILE_TIME& ft, const RCStringA& s) ;

    /** ��������
    @param [in] s �ַ���
    @param [out] res ��������
    @return �ɹ�����true,���򷵻�false
    */
    static bool ParseNumber32(const RCStringA& s, uint32_t& res) ;

    /** ����64λ����
    @param [in] s �ַ���
    @param [out] res ���ص�����
    @return �ɹ�����true,���򷵻�false
    */
    static bool ParseNumber64(const RCStringA& s, uint64_t& res) ;
};

END_NAMESPACE_RCZIP

#endif //__RCWimImageInfo_h_
