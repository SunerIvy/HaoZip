/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCompressCodecsLoader_h_
#define __RCCompressCodecsLoader_h_ 1

#include "coder/RCCodecsManager.h"

BEGIN_NAMESPACE_RCZIP

/** ѹ����������Ϣ�ӿ�
*/
class ICompressCodecsInfo ;

/** �ӽӿ����������� 
*/
class RCCompressCodecsLoader:
    public RCCodecsManager
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCCompressCodecsLoader() ;
    
    /** Ĭ����������
    */
    virtual ~RCCompressCodecsLoader() ;

public:
    
    /** ��ICompressCodecsInfo��������������
    @param [in] codecsInfo ����������Ľӿ�ָ��
    @return ���سɹ����صı������������
    */
    int32_t LoadCodecs(ICompressCodecsInfo* codecsInfo) ;
};

END_NAMESPACE_RCZIP

#endif //__RCCompressCodecsLoader_h_
