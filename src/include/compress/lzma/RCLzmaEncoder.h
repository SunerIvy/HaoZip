/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzmaEncoder_h_
#define __RCLzmaEncoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "algorithm/LzmaEnc.h"
#include "common/RCVariant.h"
#include "interface/RCPropertyID.h"

BEGIN_NAMESPACE_RCZIP

/** Lzma ������
*/
class RCLzmaEncoder:
    public IUnknownImpl3<ICompressCoder,
                         ICompressSetCoderProperties,
                         ICompressWriteCoderProperties>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzmaEncoder() ;
    
    /** Ĭ����������
    */
    ~RCLzmaEncoder() ;
    
public:
    
    /** ѹ��/��ѹ����
    @param [in] inStream ����������
    @param [in] outStream ���������
    @param [in] inSize �������ݴ�С
    @param [in] outSize ������ݴ�С 
    @param [in] progress ���Ȼص��ӿ�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult Code(ISequentialInStream* inStream,
                         ISequentialOutStream* outStream, 
                         const uint64_t* inSize, 
                         const uint64_t* outSize,
                         ICompressProgressInfo* progress) ;
    
    /** ����ѹ����������
    @param [in] propertyArray ѹ�����������б�
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetCoderProperties(const RCPropertyIDPairArray& propertyArray) ;
    
    /** ��ѹ����������д�������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult WriteCoderProperties(ISequentialOutStream* outStream) ;

private:

    /** ����ڴ�����
    @param [in] p ָ��
    @param [in] size �����С
    @return ����������ڴ�ָ��
    */
    static void* SzBigAlloc(void* p, size_t size) ;

    /** ����ڴ��ͷ�
    @param [in] p ָ��
    @param [in] address �ڴ��ַ
    */
    static void  SzBigFree(void* p, void* address) ;

    /** �ڴ�����
    @param [in] p ָ��
    @param [in] size �����ڴ��С
    @return ����������ڴ��ַ
    */
    static void* SzAlloc(void* p, size_t size) ;

    /** �ڴ��ͷ�
    @param [in] p ָ��
    @param [in] address �ڴ��ַ
    */
    static void  SzFree(void* p, void *address) ;

    /** תΪ��д�ַ�
    @param [in] c ��ת�ַ�
    @return ���ش�д�ַ�
    */
    static RCString::value_type GetUpperChar(RCString::value_type c) ;

    /** ƥ�����
    @param [in] s �ַ���
    @param [in] btMode ģʽ
    @param [in] numHashBytes У��λ
    @return ����ƥ����
    */
    static int32_t ParseMatchFinder(const RCString::value_type* s, int32_t* btMode, int32_t* numHashBytes) ;
        
    /** ����Lzma����
    @param [in] propID ���Ա�� 
    @param [in] prop ����
    @param [in] ep ��������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    HResult SetLzmaProp(RCCoderPropIDEnumType propID, const RCVariant& prop, CLzmaEncProps& ep) ;
   
private:

    /** Lzma ������
    */
    CLzmaEncHandle m_encoder ; 
    
private:

    /** ���ڴ�����
    */
    static ISzAlloc s_bigAlloc ;

    /** �ڴ�����
    */
    static ISzAlloc s_alloc ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzmaEncoder_h_

