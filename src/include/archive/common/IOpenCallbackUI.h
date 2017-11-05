/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __IOpenCallbackUI_h_
#define __IOpenCallbackUI_h_ 1

#include "base/RCString.h"
#include "interface/IArchive.h"

BEGIN_NAMESPACE_RCZIP

/** ����򿪻ص��ӿ�
*/
class IOpenCallbackUI
{
public:

    /** ����Ƿ���ֹ
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenCheckBreak() = 0 ;
    
    /** �����������
    @param [in] files �ļ�����
    @param [in] bytes �ֽ�����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenSetTotal(const uint64_t* files, const uint64_t* bytes) = 0 ;
    
    /** ������ɽ���
    @param [in] files ����ļ���
    @param [in] bytes ����ֽ���
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenSetCompleted(const uint64_t *files, const uint64_t *bytes) = 0 ;
    
    /** ��ȡ����
    @param [out] password ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenCryptoGetTextPassword(RCString& password) = 0 ;
    
    /** ��ȡ����
    @param [out] password ����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenGetPasswordIfAny(RCString& password) = 0 ;
    
    /** �Ƿ��Ѿ�ѯ�ʹ�����
    @return �Ѿ�ѯ�����뷵�� true,���򷵻� false
    */
    virtual bool OpenWasPasswordAsked() = 0 ;
    
    /** ���ѯ��������
    */
    virtual void OpenClearPasswordWasAskedFlag() = 0 ;

    /** �޸��־�
    @param [in] items �޸�ǰ�ķ־�����
    @param [out] volumeFirst ��һ���־�
    @param [out] outputFilenames �޸���ķ־�����
    @return ����δʵ��,����RC_S_FALSE
    */
    virtual HResult VolumeRepair(const RCVector<RCArchiveVolumeItem>& items, RCString& volumeFirst, RCVector<RCString>& outputFilenames)
    {
        return RC_S_FALSE;
    };

    /** ���ô���
    @param [in] errorCode �����
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult OpenSetError(int32_t errorCode) = 0 ;
    
protected:
       
    /** Ĭ����������
    */
    ~IOpenCallbackUI() {} ;
};

END_NAMESPACE_RCZIP

#endif //__IOpenCallbackUI_h_
