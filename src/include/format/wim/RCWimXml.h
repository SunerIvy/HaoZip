/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWimXml_h_
#define __RCWimXml_h_ 1

#include "base/RCDefs.h"
#include "common/RCVector.h"
#include "common/RCBuffer.h"
#include "format/wim/RCWimImageInfo.h"

BEGIN_NAMESPACE_RCZIP

/** Win xml
*/
class RCWimXml
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCWimXml() ;
    
    /** Ĭ����������
    */
    ~RCWimXml() ;
    
public:

    /** ����
    */
    void Parse() ;
    
public:

    /** ����
    */
    RCByteBuffer m_data;

    /** ���
    */
    uint16_t m_volIndex;

    /** Image �б�
    */
    RCVector<RCWimImageInfo> m_images;
};

END_NAMESPACE_RCZIP

#endif //__RCWimXml_h_
