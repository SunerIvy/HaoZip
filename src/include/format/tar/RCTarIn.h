/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCTarIn_h_
#define __RCTarIn_h_ 1

#include "interface/IStream.h"
#include "RCTarItem.h"

BEGIN_NAMESPACE_RCZIP

/** Tar ����
*/
class RCTarIn
{
public:
    
    /** ��ȡ��
    @param [in] stream ������
    @param [out] filled �Ƿ��������
    @param [out] itemInfo ���б�
    @return �ɹ�����RC_S_OK�����򷵻ش����
    */
    static HResult ReadItem(ISequentialInStream *stream, bool &filled, RCTarItemEx &itemInfo);
};

END_NAMESPACE_RCZIP

#endif //__RCTarIn_h_
