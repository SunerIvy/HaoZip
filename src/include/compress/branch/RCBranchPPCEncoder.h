/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchPPCEncoder_h_
#define __RCBranchPPCEncoder_h_ 1

#include "compress/branch/RCBranchConverter.h"

BEGIN_NAMESPACE_RCZIP

/** PPC ������
*/
class RCBranchPPCEncoder:
    public RCBranchConverter
{
public:
    /** ���ݹ�����
    @param [in,out] data ���ݻ�����
    @param [in] size ���ݳ���
    @return ���ع����ֽ���
    */
    virtual uint32_t SubFilter(byte_t* data, uint32_t size) ;
};

END_NAMESPACE_RCZIP

#endif //__RCBranchPPCEncoder_h_

