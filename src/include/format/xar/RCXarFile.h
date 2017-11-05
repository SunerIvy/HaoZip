/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCXarFile_h_
#define __RCXarFile_h_ 1

#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** Xar �ļ�
*/
class RCXarFile
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCXarFile() ;
    
    /** Ĭ����������
    */
    ~RCXarFile() ;
    
public:

    /** ����
    */
    RCStringA m_name;

    /** ģʽ
    */
    RCStringA m_method;

    /** ��С
    */
    uint64_t m_size;

    /** ѹ����С
    */
    uint64_t m_packSize;

    /** ƫ����
    */
    uint64_t m_offset;

    /** ����ʱ��
    */
    uint64_t m_cTime;

    /** �޸�ʱ��
    */
    uint64_t m_mTime;

    /** ����ʱ��
    */
    uint64_t m_aTime;    

    /** �Ƿ�Ŀ¼
    */
    bool m_isDir;

    /** �Ƿ�������
    */
    bool m_hasData;    

    /** �Ƿ���sha1
    */
    bool m_sha1IsDefined;

    /** sha1
    */
    byte_t m_sha1[20];

    /** �����
    */
    int32_t m_parent;
};

END_NAMESPACE_RCZIP

#endif //__RCXarFile_h_
