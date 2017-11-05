/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCAdcDecoderInfo_h_
#define __RCAdcDecoderInfo_h_ 1

#include "common/RCCodecInfoBase.h"

BEGIN_NAMESPACE_RCZIP

/** Adc ��������Ϣ
*/
class RCAdcDecoderInfo:
    public RCCodecInfoBase
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCAdcDecoderInfo() ;
    
    /** Ĭ����������
    */
    ~RCAdcDecoderInfo() ;
    
public:
    
    /** ��ȡ�����������ĺ���
    @return ���ؽ�������������
    */
    virtual PFNCreateCodec GetCreateDecoderFunc(void) const ;
    
    /** ��ȡ�������Ľӿ�ID, ΪIID_ICompressCoder or IID_ICompressCoder2 or IID_ICompressFilter
    @return ���ؽ�����ID
    */
    virtual RC_IID GetDecoderIID(void) const ;
    
    /** ��ȡ�����������ĺ���
    @return ���ر�������������
    */
    virtual PFNCreateCodec GetCreateEncoderFunc(void) const ;
    
    /** ��ȡ�������Ľӿ�ID
    @return ���ر�����ID
    */
    virtual RC_IID GetEncoderIID(void) const ;
    
    /** ��ȡ����ID
    @return ���ر���ID
    */
    virtual RCMethodID GetMethodID(void) const ;
    
    /** ��ȡ��������
    @return ���ر�������
    */
    virtual RCString GetMethodName(void) const ;
    
    /** ��ȡInStream�ĸ���
    @return ��������������
    */
    virtual uint32_t GetNumInStreams(void) const ;
    
    /** ��ȡ������ĸ���
    @return ����������ĸ���
    */
    virtual uint32_t GetNumOutStreams(void) const ;
    
    /** �Ƿ��������
    @return ����������������true�����򷵻�false
    */
    virtual bool IsEncoderAssigned(void) const ;
    
    /** �Ƿ��������
    @return ����������������true�����򷵻�false
    */
    virtual bool IsDecoderAssigned(void) const ;
    
    /** �Ƿ�Ϊ�򵥱�����
    @return ���ֻ����һ����������һ�����������true,���򷵻�false
    */
    virtual bool IsSimpleCodec(void) const ;
    
    /** ��ȡFilter����
    @return ����ǹ��˱���������true,���򷵻�false
    */
    virtual bool IsFilter(void) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCAdcDecoderInfo_h_
