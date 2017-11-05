/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCUdfProgressImp_h_
#define __RCUdfProgressImp_h_ 1

#include "base/RCTypes.h"
#include "interface/IArchive.h"
#include "RCUdfIn.h"

BEGIN_NAMESPACE_RCZIP

/** Udf �򿪽���ʵ��
*/
class RCUdfProgressImp: 
    public RCUdfProgressVirt
{
public:

    /** ��������
    @param [in] numBytes �ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetTotal(uint64_t numBytes);

    /** ���������
    @param [in] numFiles �ļ���
    @param [in] numBytes �ֽ���
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetCompleted(uint64_t numFiles, uint64_t numBytes);

    /** �������
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    HResult SetCompleted();

    /** ���캯��
    @param [in] callback �򿪻ص��ӿ�
    */
    RCUdfProgressImp(IArchiveOpenCallback *callback);

private:

    /** �򿪻ص��ӿ�
    */
    IArchiveOpenCallbackPtr m_callback;

    /** �ļ���
    */
    uint64_t m_numFiles;

    /** �ֽ���
    */
    uint64_t m_numBytes;
};

END_NAMESPACE_RCZIP

#endif //__RCUdfProgressImp_h_
