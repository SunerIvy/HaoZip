/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLzma2Encoder_h_
#define __RCLzma2Encoder_h_ 1

#include "interface/ICoder.h"
#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"
#include "algorithm/Lzma2Enc.h"

BEGIN_NAMESPACE_RCZIP

/** Lzma2 ������
*/
class RCLzma2Encoder:
    public IUnknownImpl4<ICompressCoder,
                         ICompressSetOutStream,
                         ICompressSetCoderProperties,
                         ICompressWriteCoderProperties>
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLzma2Encoder() ;

    /** Ĭ����������
    */
    ~RCLzma2Encoder() ;

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

    /** ���������
    @param [in] outStream ������ӿ�ָ��
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult SetOutStream(ISequentialOutStream* outStream) ;

    /** �ͷ������
    @return �ɹ�����RC_S_OK,���򷵻ش����
    */
    virtual HResult ReleaseOutStream() ;

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
    
    /** ��ȡ����
    @param [in] object Դ��ַ
    @param [in] data Ŀ���ַ
    @param [in] size ��ȡ��С
    @return ���ض�ȡ�ֽ���
    */
    static int32_t ReadData(void* object, void* data, size_t* size) ;
    
    /** д����
    @param [in] object Ŀ���ַ
    @param [in] data Դ��ַ
    @param [in] size д���С
    @return ����д���ֽ���
    */
    static size_t  WriteData(void* object, const void* data, size_t size) ;
    
    /** ���ڴ�����
    @param [in] p ָ��
    @param [in] size �����С
    @return ���������ڴ��ַ
    */
    static void* SzBigAlloc(void* p, size_t size) ;
    
    /** ���ڴ��ͷ�
    @param [in] p ָ��
    @param [in] address �ڴ��ַ
    */
    static void SzBigFree(void* p, void *address) ;
    
    /** �ڴ�����
    @param [in] p ָ��
    @param [in] size �����С
    @return ���������ڴ��ַ
    */
    static void* SzAlloc(void* p, size_t size) ;
    
    /** �ڴ��ͷ�
    @param [in] p ָ��
    @param [in] address �ڴ��ַ
    */
    static void SzFree(void* p, void *address) ;
    
    /** ResתHResult
    @param [in] res Resֵ
    @return ����HResult
    */
    static HResult SResToHRESULT(result_t res) ;
    
    /** ѹ������
    @param [in] pp ����ָ��
    @param [in] inSize �����С
    @param [in] outSize �����С
    @return ����result_t
    */
    static result_t CompressProgress(void* pp, uint64_t inSize, uint64_t outSize) ;
    
    /** תΪ��д�ַ�
    @param [in] c ��ת�ַ�
    @return ���ش�д�ַ�
    */
    static RCString::value_type GetUpperChar(RCString::value_type c) ;
        
    /** ƥ�����
    @param [in] s �ַ���
    @param [in] btMode ģʽ
    @param [in] numHashBytes ��ϣ�ֽ���
    @return ����ƥ����
    */
    static int32_t ParseMatchFinder(const RCString::value_type* s, int32_t* btMode, int32_t* numHashBytes) ;

private:
    
    /** ���л�������
    */
    struct CSeqInStream
    {
        /** �������ӿ�
        */
        ISeqInStream m_seqInStream;
        
        /** ������ָ�� 
        */ 
        ISequentialInStream* m_realStream;
    };

    /** ���л������
    */
    struct CSeqOutStream
    {
        /** ������ӿ�
        */
        ISeqOutStream m_seqOutStream ;
        
        /** �����ָ��
        */
        ISequentialOutStreamPtr m_realStream ;
        
        /** ���
        */
        HResult m_result ;
    };

private:
    
    /** ���ڴ�����
    */
    static ISzAlloc s_bigAlloc ;
    
    /** �ڴ�����
    */
    static ISzAlloc s_alloc ;

private:
    
    /** ������
    */
    CLzma2EncHandle m_encoder ;
    
    /** ������
    */
    CSeqInStream m_seqInStream ;
    
    /** �����
    */
    CSeqOutStream m_seqOutStream ;
};

END_NAMESPACE_RCZIP

#endif //__RCLzma2Encoder_h_
