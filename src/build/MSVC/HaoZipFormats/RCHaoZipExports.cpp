/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/
//include files
#include "common/RCVector.h"
#include "base/RCWindowsDefs.h"
#include "algorithm/RCInitCRCTable.h"
#include "language/RCLanguage.h"

#include "format/deb/RCDebArchiveInfo.h"
#include "format/dmg/RCDmgArchiveInfo.h"
#include "format/7z/RC7zArchiveInfo.h"
#include "format/arj/RCArjArchiveInfo.h"
#include "format/bzip2/RCBZip2ArchiveInfo.h"
#include "format/cab/RCCabArchiveInfo.h"
#include "format/chm/RCChmArchiveInfo.h"
#include "format/com/RCComArchiveInfo.h"
#include "format/cpio/RCCpioArchiveInfo.h"
#include "format/gzip/RCGZipArchiveInfo.h"
#include "format/hfs/RCHfsArchiveInfo.h"
#include "format/iso/RCIsoArchiveInfo.h"
#include "format/lzh/RCLzhArchiveInfo.h"
#include "format/lzma/RCLzmaArchiveInfo.h"
#include "format/lzma/RCLzma86ArchiveInfo.h"
#include "format/nsis/RCNsisArchiveInfo.h"
#include "format/rar/RCRarArchiveInfo.h"
#include "format/rpm/RCRpmArchiveInfo.h"
#include "format/split/RCSplitArchiveInfo.h"
#include "format/tar/RCTarArchiveInfo.h"
#include "format/udf/RCUdfArchiveInfo.h"
#include "format/wim/RCWimArchiveInfo.h"
#include "format/xar/RCXarArchiveInfo.h"
#include "format/z/RCZArchiveInfo.h"
#include "format/zip/RCZipArchiveInfo.h"
#include "format/zipsplit/RCZipSplitArchiveInfo.h"

/////////////////////////////////////////////////////////////////
//RCCodecsExports class implementation

BEGIN_NAMESPACE_RCZIP

extern "C" {
    
    /** �����ĵ���Ϣ������, ���ض�������ΪIArchiveInfo�ӿ�ָ���������ʼ��ַ�����һ��Ԫ�غ���ΪNULL
    @param [out] outObject ����IArchiveInfo�ӿ�ָ�룬���ü�������1
    */
    HResult DoCreateArchiveInfoObjects(void** outObject)
    {
        if(outObject == NULL)
        {
            return RC_E_FAIL ;
        }        
        try
        {
            RCVector<IArchiveInfo*> archiveInfoArray ;
            archiveInfoArray.push_back( new RCDebArchiveInfo ) ;
            archiveInfoArray.push_back( new RCDmgArchiveInfo ) ;
            archiveInfoArray.push_back( new RC7zArchiveInfo ) ;
            archiveInfoArray.push_back( new RCArjArchiveInfo ) ;
            archiveInfoArray.push_back( new RCBZip2ArchiveInfo ) ;
            archiveInfoArray.push_back( new RCCabArchiveInfo ) ;
            archiveInfoArray.push_back( new RCChmArchiveInfo ) ;
            archiveInfoArray.push_back( new RCComArchiveInfo ) ;
            archiveInfoArray.push_back( new RCCpioArchiveInfo ) ;
            archiveInfoArray.push_back( new RCGZipArchiveInfo ) ;
            archiveInfoArray.push_back( new RCHfsArchiveInfo ) ;
            archiveInfoArray.push_back( new RCIsoArchiveInfo ) ;
            archiveInfoArray.push_back( new RCLzhArchiveInfo ) ;
            archiveInfoArray.push_back( new RCLzmaArchiveInfo ) ;
            archiveInfoArray.push_back( new RCLzma86ArchiveInfo ) ;
            archiveInfoArray.push_back( new RCNsisArchiveInfo ) ;
            archiveInfoArray.push_back( new RCRarArchiveInfo ) ;
            archiveInfoArray.push_back( new RCRpmArchiveInfo ) ;
            archiveInfoArray.push_back( new RCSplitArchiveInfo ) ;
            archiveInfoArray.push_back( new RCTarArchiveInfo ) ;
            archiveInfoArray.push_back( new RCUdfArchiveInfo ) ;
            archiveInfoArray.push_back( new RCWimArchiveInfo ) ;
            archiveInfoArray.push_back( new RCXarArchiveInfo ) ;
            archiveInfoArray.push_back( new RCZArchiveInfo ) ;
            archiveInfoArray.push_back( new RCZipArchiveInfo ) ;
            archiveInfoArray.push_back( new RCZipSplitArchiveInfo );
            
            IArchiveInfo** archiveInfo = new IArchiveInfo*[archiveInfoArray.size() + 1] ;
            for(size_t index = 0 ; index < archiveInfoArray.size(); ++index)
            {
                archiveInfo[index] = archiveInfoArray[index] ;                
            }
            archiveInfo[archiveInfoArray.size()] = NULL ;
            *outObject = archiveInfo ;
            return RC_S_OK ;
        }
        catch(...)
        {
            return RC_E_FAIL ;
        }
        return RC_E_FAIL ;
    }
}

END_NAMESPACE_RCZIP

/** DLL ��ں���
*/
BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD     ul_reason_for_call,
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
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE ;
}

extern "C"{

    RCZIP_API HResult CreateArchiveInfoObjects(void** outObject)
    {
        return RCZIP_QUALIFIER DoCreateArchiveInfoObjects(outObject) ;
    }

    /** ������Դ�ļ���
    */
    RCZIP_API void SetResFileName(const TCHAR* szFileName)
    {
        RCZIP_QUALIFIER RCLang::Instance().SetResFileName(szFileName) ;
    }
}
