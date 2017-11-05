/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCDeflateEncoderTables_h_
#define __RCDeflateEncoderTables_h_ 1

#include "compress/deflate/RCDeflateLevels.h"

BEGIN_NAMESPACE_RCZIP

/** Deflate �����
*/
class RCDeflateEncoderTables:
    public RCDeflateLevels
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCDeflateEncoderTables() ;
    
    /** Ĭ����������
    */
    ~RCDeflateEncoderTables() ;
    
public:
    
    /** ��ʼ���ṹ
    */
    void InitStructures() ;
    
public:
    
    /** �Ƿ�ʹ���ӿ�
    */
    bool m_useSubBlocks;
    
    /** �Ƿ�洢ģʽ
    */
    bool m_storeMode;
    
    /** �Ƿ�ͳ��ģʽ
    */
    bool m_staticMode;
    
    /** ���С
    */
    uint32_t m_blockSizeRes;
    
    /** λ��
    */
    uint32_t m_pos;
};

END_NAMESPACE_RCZIP

#endif //__RCDeflateEncoderTables_h_
