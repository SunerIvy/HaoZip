/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCabHeader_h_
#define __RCCabHeader_h_ 1

BEGIN_NAMESPACE_RCZIP

class RCCabHeaderDefs
{
public:
    enum
    {
        kMarkerSize = 8
    };

    /** ��־
    */
    enum nFlags
    {
        kPrevCabinet = 0x0001,
        kNextCabinet = 0x0002,
        kReservePresent = 0x0004
    };

    /** ѹ��ģʽ
    */
    enum nCompressionMethodMajor
    {
        kNone = 0,
        kMSZip = 1,
        kQuantum = 2,
        kLZX = 3
    };

    /** �ļ���UTF��������
    */
    enum 
    {
        kFileNameIsUTFAttributeMask = 0x80
    };

    /** �ļ�������
    */
    enum nFolderIndex
    {
        kContinuedFromPrev    = 0xFFFD,
        kContinuedToNext      = 0xFFFE,
        kContinuedPrevAndNext = 0xFFFF
    };
};

END_NAMESPACE_RCZIP

#endif //__RCCabHeader_h_