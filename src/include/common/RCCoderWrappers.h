/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCoderWrappers_h_
#define __RCCoderWrappers_h_ 1

#include "algorithm/Types.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ�����ȷ�װ
*/
struct RCCompressProgressWrap
{
    /** ѹ�����ȵײ�ص��ӿ�
    */
    ICompressProgress m_progress ;
    
    /** ѹ�����Ƚ���ص��ӿ�
    */
    ICompressProgressInfo* m_progressInfo ;
    
    /** �������
    */
    HResult m_hr ;
    
    /** ���캯��
    @param [in] progress ���Ȼص��ӿ�
    */
    RCCompressProgressWrap(ICompressProgressInfo* progress);
};

/** �������ӿڷ�װ
*/
struct RCSeqInStreamWrap
{
    /** �ײ�ص��ӿ�
    */
    ISeqInStream m_seqIn ;
    
    /** ����ȡ���ݽӿ�
    */
    ISequentialInStream* m_inStream ;
    
    /** �������
    */
    HResult m_hr ;
    
    /** ���캯��
    @param [in] stream ��ȡ���ݽӿ�ָ��
    */
    RCSeqInStreamWrap(ISequentialInStream* stream) ;
};

/** ����λ���ض�λ�ӿڷ�װ
*/
struct RCSeekInStreamWrap
{
    /** �ײ��ض�λ�ӿ�
    */
    ISeekInStream m_seekIn ;
    
    /** �������ӿ�
    */
    IInStream* m_inStream ;
    
    /** �������
    */
    HResult m_hr ;
    
    /** ���캯��
    @param [in] stream �������ӿ�ָ��
    */
    RCSeekInStreamWrap(IInStream* stream) ;
};

/** ������ӿڷ�װ
*/
struct RCSeqOutStreamWrap
{
    /** �ײ�������ӿ�
    */
    ISeqOutStream m_seqOut ;
    
    /** ������ӿ�
    */
    ISequentialOutStream* m_outStream ;
    
    /** �������
    */
    HResult m_hr ;
    
    /** �Ѵ����С
    */
    uint64_t m_processed ;
    
    /** ���캯��
    @param [in] stream ������ӿ�ָ��
    */
    RCSeqOutStreamWrap(ISequentialOutStream* stream) ;
};

/** �������ת��
@param [in] res ������
@return ת�����HResult���͵Ľ��
*/
HResult SResToHResult(result_t res) ;

END_NAMESPACE_RCZIP

#endif //__RCCoderWrappers_h_
