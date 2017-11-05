/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSharedLibWin32_h_
#define __RCSharedLibWin32_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"

#include "base/RCWindowsDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCSharedLibWin32:
    private RCNonCopyable
{
public:
    
    /** ���Ͷ���
    */
    typedef HINSTANCE   shared_lib_module ;
    typedef FARPROC     shared_lib_proc ;
    
public:

    /** Ĭ�Ϲ��캯��
    */
    RCSharedLibWin32() ;
    
    /** Ĭ����������
    */
    ~RCSharedLibWin32() ;
    
    /** ���붯̬���ӿ�
    @param [in] fileName ��̬���ӿ���ļ�������������·��
    @return ���سɹ�����true�����򷵻�false
    */
    bool LoadSharedLib(const RCString& fileName) ;
    
    /** ���붯̬���ӿ�
    @param [in] fileName ��̬���ӿ���ļ�������������·��
    @param [in] flags ����ı��
    @return ���سɹ�����true�����򷵻�false
    */
    bool LoadSharedLibEx(const RCString& fileName, DWORD flags) ;
    
    /** ж�ض�̬���ӿ�
    @return  ж�سɹ�����true�����򷵻�false
    */
    bool UnloadSharedLib(void) ;
    
    /** ��̬���ӿ��Ƿ��Ѿ�����
    @return ����Ѿ����ط���true�����򷵻�false
    */
    bool IsLoaded(void) const ;
    
    /** ��ȡ��̬���ӿ��еĺ�����ַ
    @param [in] procName ��������
    @return ���ػ�ȡ�ĺ�����ַָ�룬���ʧ�ܷ���NULL
    */
    shared_lib_proc GetSharedLibProc(const char* procName) const ;

    /** ��ȡģ����
    @return ���ص�ǰ�Ѽ���ģ��ľ��
    */
    shared_lib_module GetHandle() const ;
    
    /** ��ȡģ���Ӧ·��
    @param [in] module ��ģ��ľ��
    @return �������ļ���������·�������ʧ�ܷ��ؿմ�
    */
    static RCString GetModuleFullName(shared_lib_module module) ;
    
private:
    
    /** module ���
    */
    shared_lib_module m_module ;
};

END_NAMESPACE_RCZIP

#endif //__RCSharedLibWin32_h_
