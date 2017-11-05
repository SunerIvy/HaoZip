/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCZipDefs_h_
#define __RCZipDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

namespace RCZipDefs
{
    /** lz algo x1
    */
    static const uint32_t s_lzAlgoX1 = 0;

    /** lz algo x5
    */
    static const uint32_t s_lzAlgoX5 = 1;

    /** deflate passes x1
    */
    static const uint32_t s_deflateNumPassesX1  = 1;

    /** deflate passes x7
    */
    static const uint32_t s_deflateNumPassesX7  = 3;

    /** deflate passes x9
    */
    static const uint32_t s_deflateNumPassesX9  = 10;

    /** deflate fastbytes x1
    */
    static const uint32_t s_deflateNumFastBytesX1 = 32;

    /** deflate fastbytes x7
    */
    static const uint32_t s_deflateNumFastBytesX7 = 64;

    /** deflate fastbytes x9
    */
    static const uint32_t s_deflateNumFastBytesX9 = 128;

    /** ƥ������ x1
    */
    static const char_t* s_lzmaMatchFinderX1 = _T("HC4");

    /** ƥ������ x5
    */
    static const char_t* s_lzmaMatchFinderX5 = _T("BT4");

    /** lzma fastbytes x1
    */
    static const uint32_t s_lzmaNumFastBytesX1 = 32;

    /** deflate fastbytes x7
    */
    static const uint32_t s_lzmaNumFastBytesX7 = 64;

    /** lzma �ֵ��С x1
    */
    static const uint32_t s_lzmaDicSizeX1 = 1 << 16;

    /** lzma �ֵ��С x3
    */
    static const uint32_t s_lzmaDicSizeX3 = 1 << 20;

    /** lzma �ֵ��С x5
    */
    static const uint32_t s_lzmaDicSizeX5 = 1 << 24;

    /** lzma �ֵ��С x7
    */
    static const uint32_t s_lzmaDicSizeX7 = 1 << 25;

    /** lzma �ֵ��С x9
    */
    static const uint32_t s_lzmaDicSizeX9 = 1 << 26;

    /** bzip2 passes x1
    */
    static const uint32_t s_bzip2NumPassesX1 = 1;

    /** bzip2 passes x7
    */
    static const uint32_t s_bzip2NumPassesX7 = 2;

    /** bzip2 passes x9
    */
    static const uint32_t s_bzip2NumPassesX9 = 7;

    /** bzip2 �ֵ��С x1
    */
    static const uint32_t s_bzip2DicSizeX1 = 100000;

    /** bzip2 �ֵ��С x3
    */
    static const uint32_t s_bzip2DicSizeX3 = 500000;

    /** bzip2 �ֵ��С x5
    */
    static const uint32_t s_bzip2DicSizeX5 = 900000;

    /** ����߳���
    */
    static const uint32_t s_maxThreadNums = 10;
};

END_NAMESPACE_RCZIP

#endif //__RCZipDefs_h_
