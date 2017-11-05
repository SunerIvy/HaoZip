/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTypes_h_
#define __RCTypes_h_ 1

#include <tchar.h>
#include "base/RCNameSpace.h"
#include "base/RCConfig.h"

#ifndef RCZIP_HAS_STDINT
    #define BOOST__STDC_CONSTANT_MACROS_DEFINED 1
    #define __STDC_CONSTANT_MACROS 1
    #include <base/stdint.h>
#else
    #include <cstdint>
#endif

#include <vector>

/** ����ֵ����
*/
typedef long HResult ;

BEGIN_NAMESPACE_RCZIP

/** �ַ�����
*/
#if defined RCZIP_UNICODE
    typedef wchar_t char_t ;
#else 
    typedef char    char_t ;
#endif

/** �ֽ�����
*/
typedef unsigned char  byte_t ;

/** �ӿ�ID����
*/
typedef uint32_t RC_IID ;

/** ѹ����ѹ����ID����
*/
typedef uint64_t RCMethodID ;

/** ����ֵ����
*/
enum HResultCode
{
    /** ϵͳ�����
    */
    RC_S_OK                    = ((HResult)0x00000000L),
    RC_S_FALSE                 = ((HResult)0x00000001L),
    RC_E_NOTIMPL               = ((HResult)0x80004001L),
    RC_E_NOINTERFACE           = ((HResult)0x80004002L),
    RC_E_ABORT                 = ((HResult)0x80004004L),
    RC_E_FAIL                  = ((HResult)0x80004005L),
    RC_E_OUTOFMEMORY           = ((HResult)0x8007000EL),
    RC_E_INVALIDARG            = ((HResult)0x80070057L),
    RC_E_CLASSNOTAVAILABLE     = ((HResult)0x80040111L),
    
    /** �Զ�������
    */
    RC_E_CodeBegin             = ((HResult)0x00000002L) ,   //�Զ���������ʼֵ
    RC_E_Password                                       ,   //�������
    RC_E_UnexpectedEndOfArchive                         ,   //������ļ���β
    RC_E_ArchiveHeaderCRCError                          ,   //�ļ�����ͷCRC����  
    RC_E_FileHeaderCRCError                             ,   //�ļ�ͷCRC����
    RC_E_DataCRCError                                   ,   //�ļ�CRCУ�����
    RC_E_IncorrectArchive                               ,   //�ļ���ʽ����
    RC_E_MultiVolumeArchiveAreNotSupported              ,   //��֧�ַ־�
    RC_E_ReadStreamError                                ,   //��ȡ�ļ���ʧ��
    RC_E_SeekStreamError                                ,   //Seek�ļ�ʧ��
    RC_E_WriteStreamError                               ,   //д�ļ���ʧ��
    RC_E_DataError                                      ,   //���ݴ���
    RC_E_VersionNotSupported                            ,   //��֧�ָð汾
    RC_E_Skip                                           ,   //�����ò���
    RC_E_Password_Too_Long                              ,   //���볤�ȳ�������
    RC_E_NonSupport_Isz_Password                        ,   //��֧�ִ������isz�ļ�
    
    RC_E_CodeEnd                                            //�Զ������Ž���ֵ
};

/** �ж�HResult�Ƿ�Ϊ�ɹ�
@param [in] value ��Ҫ�жϵ�ֵ
@return ���Ϊ�ɹ�ֵ�򷵻�true�����򷵻�false
*/
inline bool IsSuccess(const HResult& value)
{
    return (value == RC_S_OK) ;
}

END_NAMESPACE_RCZIP

#endif //__RCTypes_h_
