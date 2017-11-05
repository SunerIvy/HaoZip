/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zInArchiveInfo_h_
#define __RC7zInArchiveInfo_h_ 1

#include "format/7z/RC7zHeader.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

class RC7zInArchiveInfo
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zInArchiveInfo() ;
    
    /** Ĭ����������
    */
    ~RC7zInArchiveInfo() ;

public:

    /** ���
    */
    void Clear() ;

public:

    /** �汾
    */
    RC7zArchiveVersion m_version;

    /** ��ʼλ��
    */
    uint64_t m_startPosition;

    /** ͷ�ļ������ʼλ��
    */
    uint64_t m_startPositionAfterHeader;

    /** ������ʼλ��
    */
    uint64_t m_dataStartPosition;

    /** ������ʼλ��2
    */
    uint64_t m_dataStartPosition2;

    /** �ļ�������Ϣ
    */
    RCVector<uint64_t> m_fileInfoPopIDs;
};

END_NAMESPACE_RCZIP

#endif //__RC7zInArchiveInfo_h_
