/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchBCJx86Encoder_h_
#define __RCBranchBCJx86Encoder_h_ 1

#include "compress/branch/RCBranchConverter.h"
#include "compress/branch/RCBranch86.h"

BEGIN_NAMESPACE_RCZIP

/** BCJ x86 ������
*/
class RCBranchBCJx86Encoder:
    public RCBranchConverter,
    public RCBranch86
{
public:
    
    /** ���ݹ�����
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ���ع����ֽ���
    */
    virtual uint32_t SubFilter(byte_t* data, uint32_t size) ;
    
    /** ��ʼ��
    */
    virtual void SubInit() ;
};

END_NAMESPACE_RCZIP

#endif //__RCBranchBCJx86Encoder_h_
