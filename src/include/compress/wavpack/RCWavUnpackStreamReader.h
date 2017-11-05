/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWavUnpackStreamReader_h_
#define __RCWavUnpackStreamReader_h_ 1

#include "base/RCTypes.h"
#include "common/RCBuffer.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "wavpack/wavpack.h"

BEGIN_NAMESPACE_RCZIP

/** ����������
@param [in] inStream ������
@param [in] error ������Ϣ
@param [in] flags ��־
@param [in] norm_offset ƫ����
@return ���ؽ�ѹ������ָ��
*/
WavpackContext* RcWavpackOpenInputStream(void* inStream, char* error, int flags, int norm_offset);

/** WavPack�ļ�������
*/
class RCWavPackBufferStream
{
public:

    /** ���캯��
    @param [in] inStream ������
    */
    RCWavPackBufferStream(ISequentialInStream* inStream);

public:

    /** ��ȡ�ֽ�
    @param [in] data ���ݻ���
    @param [in] bcount �����С
    */
    int32_t ReadByte(void* data, int32_t bcount);

    /** ����λ��
    @return ���ص�ǰλ��
    */
    uint32_t GetPos(void);

    /** �����ֽ�
    @param [in] c �����ֽ���
    @return ���ػ����ֽ���
    */
    int PushBackByte(int c);

private:
    
    enum 
    {
        /** ���建���С
        */
        ENUM_BUFFER_SIZE = 0x2000,
    };

    /** ������
    */
    ISequentialInStream* m_inStream;

    /** ����
    */
    RCByteBuffer m_buffer;

    /** ����λ��
    */
    uint32_t m_dataPos;

    /** �����ܴ�С
    */
    uint32_t m_totalReadSize;
};

END_NAMESPACE_RCZIP

#endif //__RCWavUnpackStreamReader_h_
