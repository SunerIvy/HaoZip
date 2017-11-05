/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __ICodecInfo_h_
#define __ICodecInfo_h_ 1

#include "interface/IRefCounted.h"
#include "base/RCString.h"

BEGIN_NAMESPACE_RCZIP

/** �����������ĺ���
@return ���ر������Ľӿ�ָ�룬���ݲ�ͬ���ͣ��ӿ�ָ������Ҳ��ͬ
*/
typedef void* (*PFNCreateCodec)(void) ;

/** ���������Ϣ�ӿ� 
*/
class ICodecInfo:
    public IRefCounted
{
public:

    /** ��ȡ�����������ĺ���
    @return ���ؽ�������������ָ��
    */
    virtual PFNCreateCodec GetCreateDecoderFunc(void) const = 0 ;
    
    /** ��ȡ�������Ľӿ�ID, ΪIID_ICompressCoder or IID_ICompressCoder2 or IID_ICompressFilter
    @return ���ؽ������Ľӿ�ID
    */
    virtual RC_IID GetDecoderIID(void) const = 0 ;
    
    /** ��ȡ�����������ĺ���
    @return ���ر�������������ָ��
    */
    virtual PFNCreateCodec GetCreateEncoderFunc(void) const = 0 ;
    
    /** ��ȡ�������Ľӿ�ID
    @return ���ر������Ľӿ�ID
    */
    virtual RC_IID GetEncoderIID(void) const = 0 ;
    
    /** ��ȡ����ID
    @return ���ر���ID
    */
    virtual RCMethodID GetMethodID(void) const = 0 ;
    
    /** ��ȡ��������
    @return ���ر�������
    */
    virtual RCString GetMethodName(void) const = 0 ;
    
    /** ��ȡ�������ĸ���
    @return �����������ĸ���
    */
    virtual uint32_t GetNumInStreams(void) const = 0 ;
    
    /** ��ȡ������ĸ���
    @return �����������ĸ���
    */
    virtual uint32_t GetNumOutStreams(void) const = 0 ;
    
    /** �Ƿ��������
    @return ����������������true�����򷵻�false
    */
    virtual bool IsEncoderAssigned(void) const = 0 ;
    
    /** �Ƿ��������
    @return ����������������true�����򷵻�false
    */
    virtual bool IsDecoderAssigned(void) const = 0 ;
    
    /** �Ƿ�Ϊ�򵥱�����
    @return ���ֻ����һ����������һ�����������true,���򷵻�false
    */
    virtual bool IsSimpleCodec(void) const = 0 ;
    
    /** ��ȡFilter����
    @return ����ñ������ڹ���������true�����򷵻�false
    */
    virtual bool IsFilter(void) const = 0 ;

protected:
        
    /** Ĭ����������
    */
    ~ICodecInfo() {} ;
};

/** ����ָ�붨��
*/
typedef RCComPtr<ICodecInfo> ICodecInfoPtr ;

END_NAMESPACE_RCZIP

#endif //__ICodecInfo_h_
