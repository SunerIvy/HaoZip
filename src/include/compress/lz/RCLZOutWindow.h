/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCLZOutWindow_h_
#define __RCLZOutWindow_h_ 1

#include "common/RCOutBuffer.h"

BEGIN_NAMESPACE_RCZIP

/** RCLZOutWindow
*/
class RCLZOutWindow:
    public RCOutBuffer
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RCLZOutWindow() ;
    
    /** Ĭ����������
    */
    ~RCLZOutWindow() ;
    
public:
    
    /** ��ʼ��
    @param [in] solid �Ƿ��ʵ
    */
    void Init(bool solid = false) ;
    
    /** ��������
    @param [in] distance distance >= 0
    @param [in] len len > 0
    @return �ɹ�����true��ʧ�ܷ���false
    */
    bool CopyBlock(uint32_t distance, uint32_t len) ;
    
    /** �����ֽ�
    @param [in] byte �ֽ�ֵ
    */
    void PutByte(byte_t byte) ;
    
    /** ��ȡ�ֽ�
    @param [in] distance �൱ǰλ�õľ��루��ǰ��
    @return ���ػ�ȡ���ֽ�ֵ
    */
    byte_t GetByte(uint32_t distance) const ;
};

END_NAMESPACE_RCZIP

#endif //__RCLZOutWindow_h_
