/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWinFileBase_h_
#define __RCWinFileBase_h_ 1

#include "base/RCWindowsDefs.h"
#include "base/RCNonCopyable.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

class RCWinFileBase:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWinFileBase() ;
    
    /** Ĭ����������
    */
    ~RCWinFileBase() ;
    
public:
    
    /** �ر��ļ�
    @return �رճɹ�����true, ���򷵻�false
    */
    bool Close() ;
    
    /** ��ȡ��ǰ�ļ�λ��ƫ��
    @param [out] position ���ص�ǰ�ļ�λ��ƫ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool GetPosition(uint64_t& position) const;
    
    /** ��ȡ��ǰ�ļ�����
    @param [out] length ���ص�ǰ�ļ�����
    @return �ɹ�����true, ���򷵻�false
    */
    bool GetLength(uint64_t& length) const;
    
    /** ��λ�ļ�λ��
    @param [in] distanceToMove �ƶ�ƫ����
    @param [in] moveMethod �ƶ�����
    @param [out] newPosition �ƶ����µ��ļ�λ��ƫ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool Seek(int64_t distanceToMove, DWORD moveMethod, uint64_t& newPosition) const ;
    
    /** ��λ�ļ�λ��
    @param [in] position �ƶ�ƫ����
    @param [out] newPosition �ƶ����µ��ļ�λ��ƫ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool Seek(uint64_t position, uint64_t& newPosition);
    
    /** ��λ�ļ�ƫ�Ƶ��ļ���
    @return �ɹ�����true, ���򷵻�false
    */
    bool SeekToBegin();
    
    /** ��λ�ļ�ƫ�Ƶ��ļ�β
    @param [out] newPosition �ƶ����µ��ļ�λ��ƫ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool SeekToEnd(uint64_t& newPosition);
    
    /** ȡ��ǰ�ļ���
    @return ���ص�ǰ�ļ�����������·��
    */
    const RCString& GetFileName() const ;
  
protected:
    
    /** �����ļ�
    @param [in] fileName �ļ���
    @param [in] desiredAccess ��������
    @param [in] shareMode ��������
    @param [in] creationDisposition ��������
    @param [in] flagsAndAttributes ���λ
    @return �ɹ�����true, ���򷵻�false
    */
    bool Create(const RCString& fileName,
                DWORD desiredAccess,
                DWORD shareMode, 
                DWORD creationDisposition,  
                DWORD flagsAndAttributes) ;
    
protected:
    
    /** �ļ����
    */
    HANDLE m_handle ;
    
    /** �ļ���
    */
    RCString m_fileName ;
};

END_NAMESPACE_RCZIP

#endif //__RCWinFileBase_h_
