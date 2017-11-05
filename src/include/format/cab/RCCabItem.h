/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabItem_h_
#define __RCCabItem_h_ 1

#include "base/RCTypes.h"
#include "base/RCDefs.h"
#include "base/RCString.h"
#include "format/cab/RCCabHeader.h"
#ifdef RCZIP_OS_WIN
    #include "base/RCWindowsDefs.h"
#endif

BEGIN_NAMESPACE_RCZIP

struct RCCabFolder
{
    /** ������ʼλ��
    */
    uint32_t m_dataStart; 

    /** ���ݿ������
    */
    uint16_t m_numDataBlocks;

    /** ѹ�����͵����汾
    */
    byte_t m_compressionTypeMajor;

    /** ѹ�����͵Ĵΰ汾
    */
    byte_t m_compressionTypeMinor;

    /** ��ȡѹ������
    @return [out] ����ѹ������
    */
    byte_t GetCompressionMethod() const ;
};

struct RCCabItem
{
    /** ����
    */
    RCStringA m_name;

    /** ƫ��
    */
    uint32_t m_offset;

    /** ��С
    */
    uint32_t m_size;

    /** ʱ��
    */
    uint32_t m_time;

    /** �ļ�������
    */
    uint16_t m_folderIndex;

    /** ��־
    */
    uint16_t m_flags;

    /** ����
    */
    uint16_t m_attributes;

    /** ��ȡ����ƫ��
    @return ���ؽ���ƫ��
    */
    uint64_t GetEndOffset() const ;

    /** ��ȡwindows������
    @return ����windows������
    */
    uint32_t GetWinAttributes() const ;

    /** �����Ƿ���UTF
    @return �Ƿ���true�����򷵻�false
    */
    bool IsNameUTF() const ;

    /** �Ƿ���Ŀ¼
    @return �Ƿ���true�����򷵻�false
    */
    bool IsDir() const ;

    /** �Ƿ��ǰһ������
    @return �Ƿ���true�����򷵻�false
    */
    bool ContinuedFromPrev() const ;

    /** �Ƿ����һ������
    @return �Ƿ���true�����򷵻�false
    */
    bool ContinuedToNext() const ;

    /** ��ȡ�ļ�������
    @param [in] numFolders �ļ�����
    @return �����ļ�������
    */
    int32_t GetFolderIndex(int32_t numFolders) const;
};

END_NAMESPACE_RCZIP

#endif //__RCCabItem_h_