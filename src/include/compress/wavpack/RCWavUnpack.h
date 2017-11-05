/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCWavUnpack_h_
#define __RCWavUnpack_h_ 1

#if defined(WIN32)
#include <windows.h>
#include <io.h>
#endif

#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "base/RCTypes.h"
#include "interface/IStream.h"
#include "interface/ICoder.h"
#include "wavpack/wavpack.h"

#define NO_ERROR 0L
#define SOFT_ERROR 1
#define HARD_ERROR 2
#define USER_ABORT 3

BEGIN_NAMESPACE_RCZIP

/** WavPack ��ѹ
@param [in] inFileStream ������
@param [in] outFileStream �����
@param [in] progressCallback ���Ȼص��ӿ�
@return ���ؽ�ѹ���
*/
int RcWavUnpackFile(void* inFileStream, void* outFileStream, ICompressProgressInfo* progressCallback);

END_NAMESPACE_RCZIP

#endif //__RCWavUnpack_h_
