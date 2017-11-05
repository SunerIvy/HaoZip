/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/
//include files
#include "coder/RCCodecsRegister.h"
#include "algorithm/RCInitCRCTable.h"
#include "common/RCAlloc.h"
#include "common/RCBitlDecoderData.h"
#include "compress/bzip2/RCBZip2CRCTableInit.h"
#include "compress/range/RCRangeCoderDefs.h"
#include "crypto/AES/RCAesTableInit.h"
#include "crypto/hash/RCRandomGenerator.h"
#include "language/RCLanguage.h"

#ifdef RCZIP_OS_WIN
    #include "base/RCWindowsDefs.h"
#endif

/////////////////////////////////////////////////////////////////
//RCCodecsExports class implementation


#if !defined (RC_STATIC_SFX) && !defined (RC_BUILD_STATIC)

BEGIN_NAMESPACE_RCZIP

/** �����������������, ���ض�������ΪICompressCodecsInfo�ӿ�ָ��
*/
extern "C" {
    HResult DoCreateCodecs(void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_FAIL ;
        }
        RCCodecsManager* codecsManager = NULL ;
        try
        {
            RCCodecsRegister* codecsRegister = new RCCodecsRegister() ;
            codecsManager = codecsRegister ;
            HResult hr = codecsRegister->LoadCodecs() ;
            if(IsSuccess(hr))
            {
                ICompressCodecsInfo* codecsInfo = (ICompressCodecsInfo*)codecsManager ;
                codecsInfo->AddRef() ;
                *outObject = codecsInfo ;
            }
            return hr ;
        }
        catch(...)
        {
            if(codecsManager)
            {
                delete codecsManager ;
                codecsManager = NULL ;
            }
            return RC_E_FAIL ;
        }
        return RC_E_FAIL ;
    }
}

END_NAMESPACE_RCZIP

#ifdef RCZIP_OS_WIN

/** DLL ��ں���
*/
BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD   ul_reason_for_call,
                       LPVOID  /*lpReserved*/
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        {
            //��ʼ��
            (void)RCZIP_QUALIFIER RCLang::Instance() ;
            (void)RCZIP_QUALIFIER RCInitCRCTable::Instance() ;
            (void)RCZIP_QUALIFIER RCAlloc::Instance() ;
            (void)RCZIP_QUALIFIER RCBitlDefs::Instance() ;
            (void)RCZIP_QUALIFIER RCBZip2CRCInit::Instance() ;
            (void)RCZIP_QUALIFIER RCRangeCoderInit::Instance() ;
            (void)RCZIP_QUALIFIER RCAesTableInit::Instance() ;
            (void)RCZIP_QUALIFIER RCRandomGenerator::Instance() ;
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE ;
}

extern "C"{
    /** �����������������, ���ض�������ΪICompressCodecsInfo�ӿ�ָ��
    @param [out] outObject ����ICompressCodecsInfo�ӿ�ָ�룬�������ü�����1
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    RCZIP_API HResult CreateCodecs(void** outObject)
    {
        return RCZIP_QUALIFIER DoCreateCodecs(outObject) ;
    }

    /** ������Դ�ļ���
    */
    RCZIP_API void SetResFileName(const TCHAR* szFileName)
    {
        RCZIP_QUALIFIER RCLang::Instance().SetResFileName(szFileName) ;
    }
}

#else
    #error "Can't support other OS now!"
#endif

#endif // RC_STATIC_SFX
