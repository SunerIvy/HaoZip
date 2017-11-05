/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zCompressionMode_h_
#define __RC7zCompressionMode_h_ 1

#include "base/RCDefs.h"
#include "format/common/RCMethodProps.h"

BEGIN_NAMESPACE_RCZIP

struct RC7zArchiveMethodFull: 
    public RCArchiveMethod
{
    /** �������ĸ���
    */
    uint32_t m_numInStreams;

    /** ������ĸ���
    */
    uint32_t m_numOutStreams;

    /** �Ƿ��Ǽ򵥱���
    */
    bool IsSimpleCoder() const
    {
        return (m_numInStreams == 1) && (m_numOutStreams == 1);
    }
};

struct RC7zBind
{
    /** �������
    */
    uint32_t m_inCoder;

    /** ������
    */
    uint32_t m_inStream;

    /** �������
    */
    uint32_t m_outCoder;

    /** �����
    */
    uint32_t m_outStream;
};

class RC7zCompressionMethodMode
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zCompressionMethodMode():
      m_passwordIsDefined(false),
      m_numThreads(1)
    {
    }

public:

    /** �Ƿ��ǿ�
    */
    bool IsEmpty() const
    {
        return (m_methods.empty() && !m_passwordIsDefined);
    }

public:

    /** ѹ��ģʽ
    */
    RCVector<RC7zArchiveMethodFull> m_methods;

    /** ����Ϣ
    */
    RCVector<RC7zBind> m_binds;

    /** �̸߳���
    */
    uint32_t m_numThreads;

    /** �Ƿ�������
    */
    bool m_passwordIsDefined;

    /** ����
    */
    RCString m_password;
};

END_NAMESPACE_RCZIP

#endif //__RC7zCompressionMode_h_
