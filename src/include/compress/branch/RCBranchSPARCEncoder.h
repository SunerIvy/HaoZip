/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCBranchSPARCEncoder_h_
#define __RCBranchSPARCEncoder_h_ 1

#include "compress/branch/RCBranchConverter.h"

BEGIN_NAMESPACE_RCZIP

/** SPARC ������
*/
class RCBranchSPARCEncoder:
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

#endif //__RCBranchSPARCEncoder_h_

