/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipCompressionMethodMode_h_
#define __RCZipCompressionMethodMode_h_ 1

#include "base/RCDefs.h"
#include "base/RCString.h"
#include "common/RCVector.h"

BEGIN_NAMESPACE_RCZIP

struct RCZipCompressionMethodMode
{
    /** ѹ��ģʽ��˳��
    */
    RCByteVector m_methodSequence ;

    /** ƥ������
    */
    RCStringW m_matchFinder;

    /** algo
    */
    uint32_t m_algo ;

    /** passes
    */
    uint32_t m_numPasses ;

    /** fastbytes
    */
    uint32_t m_numFastBytes ;

    /** �Ƿ�ƥ����������
    */
    bool m_numMatchFinderCyclesDefined ;

    /** ƥ����������
    */
    uint32_t m_numMatchFinderCycles ;

    /** �ֵ��С
    */
    uint32_t m_dicSize ;

#ifdef COMPRESS_MT
    /** �߳���
    */
    uint32_t m_numThreads ;
#endif

    /** �Ƿ�������
    */
    bool m_passwordIsDefined ;

    /** ����
    */
    RCStringA m_password ;

    /** �Ƿ���AESģʽ
    */
    bool m_isAesMode ;

    /** AESģʽ�ܳ�
    */
    byte_t m_aesKeyMode ;

    /** Ĭ�Ϲ��캯��
    */ 
    RCZipCompressionMethodMode():
        m_numMatchFinderCyclesDefined(false),
        m_passwordIsDefined(false),
        m_isAesMode(false),
        m_aesKeyMode(3)
    {}
} ;

END_NAMESPACE_RCZIP

#endif //__RCZipCompressionMethodMode_h_
